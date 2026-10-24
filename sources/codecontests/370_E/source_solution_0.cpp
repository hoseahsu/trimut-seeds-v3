#include <bits/stdc++.h>
using namespace std;
class p {
 public:
  int l, r, c;
  p(int l, int r, int c) : l(l), r(r), c(c) {}
};
bool cmp(const p &i, const p &j) { return i.l < j.l; }
int a[200002], n;
vector<p> v;
int l[100001], r[100001];
int d[6][100001];
int f(int h, int k) {
  if (k < 0) return 1;
  if (d[h][k] >= 0) return d[h][k];
  if (v[k + 1].l - h <= v[k].r) return d[h][k] = 0;
  for (int i = v[k].l - 4; i <= v[k].l; i++) {
    for (int j = v[k].r; j <= v[k].r + 4; j++) {
      int cl = i, cr = j, nl = v[k + 1].l - h;
      if (cl < 1 || cr > n || cr >= nl) continue;
      if (cr - cl + 1 > 5 || cr - cl + 1 < 2) continue;
      int c1 = (nl - cr + 3) / 5, c2 = (nl - cr - 1) / 2;
      if (v[k].c + c1 + 1 > v[k + 1].c || v[k].c + c2 + 1 < v[k + 1].c)
        continue;
      if (f(v[k].l - i, k - 1)) return d[h][k] = 1;
    }
  }
  return d[h][k] = 0;
}
void trace(int h, int k) {
  if (k < 0) return;
  for (int i = v[k].l - 4; i <= v[k].l; i++) {
    for (int j = v[k].r; j <= v[k].r + 4; j++) {
      int cl = i, cr = j, nl = v[k + 1].l - h;
      if (cl < 1 || cr > n || cr >= nl) continue;
      if (cr - cl + 1 > 5 || cr - cl + 1 < 2) continue;
      int c1 = (nl - cr + 3) / 5, c2 = (nl - cr - 1) / 2;
      if (v[k].c + c1 + 1 > v[k + 1].c || v[k].c + c2 + 1 < v[k + 1].c)
        continue;
      if (f(v[k].l - i, k - 1)) {
        for (int p = i; p <= j; p++) a[p] = v[k].c;
        int need = (v[k + 1].c - v[k].c - 1), len = nl - cr - 1;
        if (need) {
          int p = len / need, q = len % need, sum = 0;
          int cur = v[k].c + 1;
          for (int i = cr + 1; i < nl; i++) {
            a[i] = cur;
            sum++;
            if (sum == p) {
              if (q)
                q--;
              else {
                sum = 0;
                cur++;
              }
            } else if (sum > p) {
              sum = 0;
              cur++;
            }
          }
        }
        trace(v[k].l - i, k - 1);
        return;
      }
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (i == 1) {
      if (a[i] > 1) {
        puts("-1");
        return 0;
      }
      a[i] = 1;
    }
    if (a[i]) {
      if (!l[a[i]]) l[a[i]] = i;
      r[a[i]] = i;
    }
  }
  for (int i = 1; i <= 100000; i++)
    if (l[i]) {
      v.push_back(p(l[i], r[i], i));
    }
  if (v.size() == 1) {
    if (v[0].r - v[0].l + 1 > 5) {
      puts("-1");
      return 0;
    }
    if (v[0].r == 1) {
      a[2] = 1;
      v[0].r++;
    }
    for (int i = v[0].l; i <= v[0].r; i++) a[i] = 1;
    int rem = (n - v[0].r) / 2;
    int cur = 2;
    for (int i = v[0].r + 1; i < n; i += 2) {
      a[i] = a[i + 1] = cur;
      cur++;
    }
    if (a[n] == 0) a[n] = a[n - 1];
    printf("%d\n", a[n]);
    for (int i = 1; i <= n; i++) printf("%d ", a[i]);
    puts("");
    return 0;
  }
  sort(v.begin(), v.end(), cmp);
  for (int i = 0; i < v.size(); i++) {
    if (v[i].r - v[i].l + 1 > 5) {
      puts("-1");
      return 0;
    }
    if (i && v[i].l <= v[i - 1].r) {
      puts("-1");
      return 0;
    }
    if (i && v[i].c < v[i - 1].c) {
      puts("-1");
      return 0;
    }
    if (i > 0 && i < v.size() - 1 && v[i].l == v[i].r &&
        v[i - 1].r == v[i].l - 1 && v[i + 1].l == v[i].r + 1) {
      puts("-1");
      return 0;
    }
  }
  for (int i = 0; i < v.size(); i++) {
    for (int j = v[i].l; j <= v[i].r; j++) a[j] = v[i].c;
  }
  memset(d, -1, sizeof(d));
  for (int l = v.back().l - 4; l <= v.back().l; l++) {
    for (int r = v.back().r; r <= v.back().r + 4; r++) {
      if (r - l + 1 > 5 || r - l + 1 < 2) continue;
      if (l < 1 || r > n) continue;
      if (f(v.back().l - l, v.size() - 2)) {
        if (r == n - 1 && r - l + 1 == 5) continue;
        trace(v.back().l - l, v.size() - 2);
        for (int j = l; j <= r; j++) a[j] = v.back().c;
        int cur = v.back().c + 1;
        for (int j = r + 1; j < n; j += 2) {
          a[j] = a[j + 1] = cur;
          cur++;
        }
        if (a[n] == 0) a[n] = a[n - 1];
        printf("%d\n", a[n]);
        for (int j = 1; j <= n; j++) printf("%d ", a[j]);
        puts("");
        return 0;
      }
    }
  }
  puts("-1");
  return 0;
}
