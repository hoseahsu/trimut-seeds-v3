#include <bits/stdc++.h>
using namespace std;
const long long M = 3e5 + 10, M2 = 1e6 + 10, oo = 1e9 + 7;
int mit[M], dmit[M], pr[M], reg[M];
vector<int> adj[M];
int find(int u) {
  if (pr[u] == u) return u;
  return pr[u] = find(pr[u]);
}
void jnt(int u, int v) {
  int a = find(u), b = find(v);
  if (a == b) return;
  pr[a] = b;
}
void dfs(int u, int p) {
  int mx = 0, smx = 0;
  for (auto v : adj[u]) {
    if (v == p) continue;
    dfs(v, u);
    if (mit[v] >= mx) {
      smx = mx;
      mx = mit[v];
    } else
      smx = max(smx, mit[v]);
    dmit[u] = max(dmit[u], dmit[v]);
  }
  mit[u] = mx + 1;
  dmit[u] = max(dmit[u], mx + smx + 1);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) pr[i] = i;
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    jnt(u, v);
  }
  for (int i = 1; i <= n; i++) {
    int p = find(i);
    if (reg[p] == 0) {
      dfs(p, 0);
      reg[p] = dmit[p];
    }
  }
  for (int i = 1; i <= n; i++) {
    int p = find(i);
  }
  while (q--) {
    int tp, x, y, p, p1, p2;
    cin >> tp;
    if (tp == 1) {
      cin >> x;
      p = find(x);
      cout << reg[p] - 1 << endl;
    }
    if (tp == 2) {
      cin >> x >> y;
      p1 = find(x);
      p2 = find(y);
      if (p1 == p2) continue;
      jnt(x, y);
      p = find(x);
      reg[p] = max(max(reg[p1], reg[p2]), reg[p1] / 2 + 2 + reg[p2] / 2);
    }
  }
  return 0;
}
