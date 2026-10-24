#include <bits/stdc++.h>
using namespace std;
const int inf = ~0U >> 1;
const long long INF = ~0ULL >> 1;
;
int n, x, y, cnt[4000], vis[4000], circle[4000], Cnt, top;
double ans;
vector<int> E[4000];
void check(int S, int u, int dis) {
  vis[u] = 1;
  for (int i = (0); i < (E[u].size()); ++i)
    if (!vis[E[u][i]])
      check(S, E[u][i], dis + 1);
    else if (E[u][i] == S && dis > 1) {
      circle[S] = 1;
      ++Cnt;
      return;
    }
  vis[u] = 0;
}
void dfs(int S, int u, int c) {
  if (circle[u]) ++top;
  vis[u] = 1;
  if (top > 1) {
    int L1 = top;
    int L2 = Cnt - L1 + min(2, top);
    ans += 0.5 * (1. / c + 1. / (c - L1 + L2) - 1. / (c + L2 - 2));
  } else
    ans += 1. / c;
  for (int i = (0); i < (E[u].size()); ++i)
    if (!vis[E[u][i]]) dfs(S, E[u][i], c + 1);
  vis[u] = 0;
  if (circle[u]) --top;
}
int main() {
  scanf("%d", &n);
  for (int i = (1); i <= (n); ++i)
    scanf("%d%d", &x, &y), E[x].push_back(y), E[y].push_back(x);
  for (int i = (0); i < (n); ++i) {
    memset(vis, 0, sizeof(vis));
    check(i, i, 0);
  }
  for (int i = (0); i < (n); ++i) {
    memset(vis, 0, sizeof(vis));
    dfs(i, i, 1);
  }
  printf("%.10lf\n", ans);
  return 0;
}
