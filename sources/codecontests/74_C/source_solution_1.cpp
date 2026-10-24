#include <bits/stdc++.h>
using namespace std;
int n, m;
bool vis[2000020];
int main() {
  int i, j, k, st;
  int ans = 0;
  scanf("%d %d", &n, &m);
  if (n > m) swap(n, m);
  if (n == 1) {
    printf("%d\n", m);
    return 0;
  }
  memset(vis, 0, sizeof(vis));
  st = (2 * (m - 1)) % (2 * (n - 1));
  for (i = 0; i < n; i++) {
    if (vis[i] == 0) {
      ans++;
      j = i;
      while (vis[j] == 0) {
        vis[j] = 1;
        if (j >= n) vis[2 * (n - 1) - j] = 1;
        j = (j + st) % (2 * (n - 1));
      }
      if (j > 0) {
        j = 2 * (n - 1) - i;
        while (vis[j] == 0) {
          vis[j] = 1;
          if (j >= n) vis[2 * (n - 1) - j] = 1;
          j = (j + st) % (2 * (n - 1));
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
