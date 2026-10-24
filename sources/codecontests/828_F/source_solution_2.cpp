#include <bits/stdc++.h>
using namespace std;
const int maxn = 200009;
struct edge {
  int u, v, w, flag, id;
  bool operator<(const edge &e) const { return w < e.w; }
} e[maxn];
vector<int> g[maxn];
int head[maxn], fa[maxn][20], dep[maxn], pa[maxn];
int mx[maxn][20], mn[maxn][20], ans[maxn];
int n, m, u, v, w;
int getpa(int x) { return pa[x] == x ? x : pa[x] = getpa(pa[x]); }
void dfs(int u, int f, int d) {
  fa[u][0] = f;
  dep[u] = d;
  for (int i = 0; i < g[u].size(); i++)
    if (g[u][i] != f) dfs(g[u][i], u, d + 1);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
    e[i].id = i;
  }
  sort(e + 1, e + m + 1);
  for (int i = 1; i <= n; i++) pa[i] = i;
  for (int i = 1; i <= m; i++) {
    u = getpa(e[i].u);
    v = getpa(e[i].v);
    if (u == v) continue;
    pa[u] = v;
    e[i].flag = 1;
    g[e[i].u].push_back(e[i].v);
    g[e[i].v].push_back(e[i].u);
  }
  dfs(1, 0, 1);
  for (int i = 1; i <= m; i++)
    if (e[i].flag)
      if (fa[e[i].u][0] == e[i].v)
        mx[e[i].u][0] = e[i].w;
      else
        mx[e[i].v][0] = e[i].w;
  for (int j = 1; j <= 17; j++)
    for (int i = 1; i <= n; i++) {
      fa[i][j] = fa[fa[i][j - 1]][j - 1];
      mx[i][j] = max(mx[i][j - 1], mx[fa[i][j - 1]][j - 1]);
    }
  memset(mn, 0x3f, sizeof mn);
  for (int i = 1; i <= m; i++)
    if (!e[i].flag) {
      u = e[i].u;
      v = e[i].v;
      if (dep[u] < dep[v]) swap(u, v);
      for (int j = 17; j >= 0; j--)
        if (dep[fa[u][j]] >= dep[v]) {
          mn[u][j] = min(mn[u][j], e[i].w);
          u = fa[u][j];
        }
      if (u == v) continue;
      for (int j = 17; j >= 0; j--)
        if (fa[u][j] != fa[v][j]) {
          mn[u][j] = min(mn[u][j], e[i].w);
          mn[v][j] = min(mn[v][j], e[i].w);
          u = fa[u][j];
          v = fa[v][j];
        }
      mn[u][0] = min(mn[u][0], e[i].w);
      mn[v][0] = min(mn[v][0], e[i].w);
    }
  for (int j = 17; j >= 1; j--)
    for (int i = 1; i <= n; i++) {
      mn[i][j - 1] = min(mn[i][j - 1], mn[i][j]);
      mn[fa[i][j - 1]][j - 1] = min(mn[fa[i][j - 1]][j - 1], mn[i][j]);
    }
  for (int i = 1; i <= m; i++)
    if (e[i].flag) {
      if (fa[e[i].u][0] == e[i].v)
        ans[e[i].id] = mn[e[i].u][0];
      else
        ans[e[i].id] = mn[e[i].v][0];
    } else {
      u = e[i].u;
      v = e[i].v;
      if (dep[u] < dep[v]) swap(u, v);
      for (int j = 17; j >= 0; j--)
        if (dep[fa[u][j]] >= dep[v]) {
          ans[e[i].id] = max(ans[e[i].id], mx[u][j]);
          u = fa[u][j];
        }
      if (u == v) continue;
      for (int j = 17; j >= 0; j--)
        if (fa[u][j] != fa[v][j]) {
          ans[e[i].id] = max(ans[e[i].id], mx[u][j]);
          ans[e[i].id] = max(ans[e[i].id], mx[v][j]);
          u = fa[u][j];
          v = fa[v][j];
        }
      ans[e[i].id] = max(ans[e[i].id], mx[u][0]);
      ans[e[i].id] = max(ans[e[i].id], mx[v][0]);
    }
  for (int i = 1; i <= m; i++) {
    if (ans[i] > 1e9) ans[i] = 0;
    printf("%d ", ans[i] - 1);
  }
  return 0;
}
