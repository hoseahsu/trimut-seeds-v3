#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > G;
vector<int> a, nod, vis;
int edge;
int dfs(int v, int u) {
  int i, j, k, l, z;
  for (i = 0, z = 0; i < G[v].size(); i++) {
    k = G[v][i];
    if (k == u) continue;
    l = dfs(k, v);
    if (l == 0) nod[k] = 2;
    if (l == 1) z = 1;
  }
  if (z == 1 || nod[v] == 1) return 1;
  return 0;
}
void dfs2(int v, int u, int cnt) {
  int i, j, k, l, z;
  vis[v] = cnt;
  for (i = 0, z = 0; i < G[v].size(); i++) {
    k = G[v][i];
    if (k == u || nod[k] == 2) continue;
    dfs2(k, v, cnt + 1);
  }
}
void dfs_back(int v, int u, int cnt) {
  int i, j, k, l, z;
  vis[v] = cnt;
  for (i = 0, z = 0; i < G[v].size(); i++) {
    k = G[v][i];
    if (k == u || nod[k] == 2) continue;
    dfs_back(k, v, cnt + 1);
  }
}
void dfs_len(int v, int u) {
  int i, j, k, l, z;
  for (i = 0, z = 0; i < G[v].size(); i++) {
    k = G[v][i];
    if (k == u || nod[k] == 2) continue;
    dfs_len(k, v);
    edge++;
  }
}
int main() {
  int i, j, k, l;
  int n, m;
  cin >> n >> m;
  G.resize(n + 10);
  nod.resize(n + 10, 0);
  for (i = 0; i < n - 1; i++) {
    cin >> k >> l;
    G[k].push_back(l);
    G[l].push_back(k);
  }
  for (i = 0; i < m; i++) {
    cin >> k;
    a.push_back(k);
    nod[k] = 1;
  }
  dfs(a[0], -1);
  vis.assign(n + 10, 0);
  dfs2(a[0], -1, 0);
  k = -1;
  for (i = 1; i <= n; i++) {
    if (k <= vis[i] && nod[i] != 2) {
      if (k == vis[i] && nod[i] != 2)
        l = min(l, i);
      else
        l = i;
      k = vis[i];
    }
  }
  vis.assign(n + 10, 0);
  dfs_back(l, -1, 0);
  int l2, k2 = -1;
  for (i = 1; i <= n; i++) {
    if (k2 <= vis[i] && nod[i] != 2) {
      if (k2 == vis[i] && nod[i] != 2)
        l2 = min(l2, i);
      else
        l2 = i;
      k2 = vis[i];
    }
  }
  k = k2;
  l = min(l, l2);
  dfs_len(a[0], -1);
  cout << l << '\n' << 2 * edge - k;
}
