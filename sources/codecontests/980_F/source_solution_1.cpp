#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, m, dfn[500005], low[500005], tim, stk[500005], top, scnt, scc[500005];
vector<int> G[500005], cir[500005];
void tarjan(int u, int ff) {
  dfn[u] = low[u] = ++tim, stk[++top] = u;
  for (int v : G[u])
    if (v != ff) {
      if (!dfn[v])
        tarjan(v, u), low[u] = min(low[u], low[v]);
      else
        low[u] = min(low[u], dfn[v]);
    }
  if (dfn[u] == low[u]) {
    ++scnt;
    for (int x = -1; x != u;)
      scc[x = stk[top--]] = scnt, cir[scnt].push_back(x);
  }
}
int d[500005], mxd[500005];
void BFS() {
  queue<int> q;
  memset(d, -1, sizeof d), d[1] = 0, q.push(1);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : G[u])
      if (d[v] == -1) d[v] = d[u] + 1, q.push(v);
  }
}
bool vis[500005];
void DFS(int u) {
  vis[u] = 1, mxd[u] = d[u];
  for (int v : G[u])
    if (!vis[v]) DFS(v), mxd[u] = max(mxd[u], mxd[v]);
}
int L[500005], CL[500005], f[500005];
void dfs(int u, int ff, int fL) {
  int o = scc[u];
  for (int u : cir[o])
    for (int v : G[u])
      if (scc[v] != o) {
        int now = scc[u] > scc[v] ? mxd[v] - d[u] : fL;
        if (now > L[u])
          CL[u] = L[u], L[u] = now;
        else
          CL[u] = max(CL[u], now);
      }
  static pair<int, int> q[500005 << 1];
  int len = cir[o].size(), lim = len / 2, l, r;
  q[l = r = 1] = make_pair(L[cir[o][0]], 0);
  for (int i = (1), LIM = (len - 1 + lim); i <= LIM; i++) {
    while (i - q[l].second > lim) l++;
    int u = cir[o][i % len];
    f[u] = max(f[u], i + q[l].first);
    while (l <= r && q[r].first <= L[u] - i) r--;
    q[++r] = make_pair(L[u] - i, i);
  }
  reverse(cir[o].begin(), cir[o].end());
  q[l = r = 1] = make_pair(L[cir[o][0]], 0);
  for (int i = (1), LIM = (len - 1 + lim); i <= LIM; i++) {
    while (i - q[l].second > lim) l++;
    int u = cir[o][i % len];
    f[u] = max(f[u], i + q[l].first);
    while (l <= r && q[r].first <= L[u] - i) r--;
    q[++r] = make_pair(L[u] - i, i);
  }
  for (int u : cir[o])
    for (int v : G[u])
      if (scc[v] != o && v != ff)
        dfs(v, u, max(f[u], mxd[v] - d[u] == L[u] ? CL[u] : L[u]) + 1);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1, x, y; i <= m; i++)
    scanf("%d%d", &x, &y), G[x].push_back(y), G[y].push_back(x);
  tarjan(1, 0);
  BFS(), DFS(1);
  dfs(1, 0, 0);
  for (int i = (1), LIM = (n); i <= LIM; i++)
    printf("%d%c", max(f[i], L[i]), i == n ? 10 : 32);
}
