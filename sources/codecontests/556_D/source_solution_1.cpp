#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 5;
struct node {
  long long mx, mn;
  int id;
  bool operator<(const node &t) const { return mx > t.mx; }
} w[N];
bool cmp(node a, node b) { return a.mn < b.mn; }
struct num {
  long long v;
  int id;
  bool operator<(const num &t) const { return v < t.v; }
} a[N];
long long ans[N];
int n, m;
int main() {
  cin >> n >> m;
  long long pl = -1, pr = -1;
  for (int i = 0; i < n; i++) {
    long long l, r;
    scanf("%I64d%I64d", &l, &r);
    if (pl != -1) {
      w[i].mx = r - pl;
      w[i].mn = l - pr;
      w[i].id = i;
    }
    pl = l, pr = r;
  }
  for (int i = 1; i <= m; i++) {
    scanf("%I64d", &a[i].v);
    a[i].id = i;
  }
  sort(a + 1, a + 1 + m);
  sort(w + 1, w + n, cmp);
  priority_queue<node> Q;
  int cnt = 0;
  for (int i = 1, j = 1; i <= m; i++) {
    while (w[j].mn <= a[i].v && a[i].v <= w[j].mx && j < n) {
      Q.push(w[j]);
      j++;
    }
    if (Q.empty()) continue;
    node now = Q.top();
    Q.pop();
    if (a[i].v > now.mx) {
      puts("No");
      return 0;
    }
    ans[now.id] = a[i].id;
    cnt++;
  }
  if (cnt < n - 1) {
    puts("No");
    return 0;
  }
  puts("Yes");
  for (int i = 1; i < n; i++)
    printf("%I64d%c", ans[i], i == n - 1 ? '\n' : ' ');
  return 0;
}
