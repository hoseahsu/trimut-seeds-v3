#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e18;
int vis[1000010];
int pre[1000010];
long long cost[1000010];
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  memset(vis, 0, sizeof(vis));
  int x;
  for (int i = 1; i <= m; i++) {
    scanf("%d", &x);
    vis[x] = 1;
  }
  for (int i = 1; i <= k; i++) scanf("%lld", &cost[i]);
  if (vis[0]) return 0 * printf("-1\n");
  pre[0] = 0;
  for (int i = 1; i <= n; i++)
    if (vis[i])
      pre[i] = pre[i - 1];
    else
      pre[i] = i;
  long long ans = MAXN;
  for (int i = 1; i <= k; i++) {
    long long res = 0;
    int cur = 0;
    while (1) {
      if (cur + i >= n) {
        res += cost[i];
        break;
      }
      if (pre[cur + i] == cur) {
        res = MAXN;
        break;
      }
      res += cost[i];
      cur = pre[cur + i];
    }
    ans = min(ans, res);
  }
  if (ans == MAXN)
    printf("-1\n");
  else
    printf("%lld\n", ans);
}
