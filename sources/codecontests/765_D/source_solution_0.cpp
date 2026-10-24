#include <bits/stdc++.h>
#pragma warning(disable : 4996)
const int kMaxn = 100010;
int n, m, a[kMaxn], g[kMaxn], h[kMaxn];
int main() {
  static int i, j, k, x, now, ans;
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) scanf("%d", a + i);
  m = 0;
  memset(g, 0, sizeof(g));
  memset(h, 0, sizeof(h));
  for (i = 1; i <= n; ++i) {
    if (!g[i]) {
      if (g[a[i]]) {
        g[i] = g[a[i]];
      } else {
        g[i] = g[a[i]] = ++m;
        h[m] = a[i];
      }
    }
  }
  ans = 0;
  for (i = 1; i <= n; ++i)
    if (h[g[i]] != a[i]) ans = -1;
  for (i = 1; i <= m; ++i)
    if (g[h[i]] != i) ans = -1;
  if (ans == -1) {
    puts("-1");
    return 0;
  }
  printf("%d\n", m);
  for (i = 1; i <= n; ++i) printf("%d ", g[i]);
  puts("");
  for (i = 1; i <= m; ++i) printf("%d ", h[i]);
  return 0;
}
