#include <bits/stdc++.h>
using namespace std;
const int maxn = 52;
int n, a[maxn + 5], b[maxn + 5], pos[maxn + 5], lft[maxn + 5], rht[maxn + 5];
vector<int> res[maxn + 5];
void go(vector<int> vec) {
  int m = vec.size();
  int x = 1, p = n;
  for (int i = (0); i <= int(m - 1); i++) {
    int y = x;
    x += vec[i];
    for (int j = (x - 1); j >= int(y); j--) {
      b[p--] = a[j];
    }
  }
  memcpy(a, b, sizeof(a));
}
int main() {
  scanf("%d", &n);
  for (int i = (1); i <= int(n); i++) {
    scanf("%d", &a[i]);
  }
  int m = 0;
  while (true) {
    bool F = true;
    for (int i = (1); i <= int(n); i++)
      if (a[i] != i) {
        F = false;
        break;
      }
    if (F) break;
    memset(lft, 0x3f, sizeof(lft));
    memset(rht, 0xc0, sizeof(rht));
    for (int i = 1, l = 1; i <= n; i += l, l = 1) {
      while (i + l <= n && a[i + l] == a[i] + l) {
        l++;
      }
      lft[a[i]] = i;
      rht[a[i] + l] = i + l;
    }
    int x = 0;
    for (int i = (1); i <= int(n); i++)
      if (lft[i] <= rht[i]) {
        x = i;
        break;
      }
    int y = 0;
    for (int i = 1, l = 1; i <= n; i += l, l = 1) {
      while (i + l <= n && a[i + l] == a[i] + l) {
        l++;
      }
      if (a[i] + l == x) {
        y = i;
      }
    }
    ++m;
    if (lft[x] != 1) {
      res[m].emplace_back(lft[x] - 1);
    }
    res[m].emplace_back(y - lft[x]);
    res[m].emplace_back(rht[x] - y);
    if (rht[x] != n + 1) {
      res[m].emplace_back(n + 1 - rht[x]);
    }
    go(res[m]);
  }
  printf("%d\n", m);
  for (int i = (1); i <= int(m); i++) {
    printf("%d", int(res[i].size()));
    for (int j = (0); j <= int(res[i].size() - 1); j++) {
      printf(" %d", res[i][j]);
    }
    puts("");
  }
  return 0;
}
