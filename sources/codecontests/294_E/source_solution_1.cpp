#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 5;
vector<pair<int, int> > adj[maxn];
long long d[maxn], size[maxn], val[maxn], sz[maxn], n;
void dfs1(int v, int p) {
  size[v]++;
  for (int i = 0; i < adj[v].size(); i++) {
    int u = adj[v][i].first;
    if (u == p) continue;
    d[u] = d[v] + 1;
    dfs1(u, v);
    size[v] += size[u];
  }
}
int best;
void dfs_size(int v, int p, int ban) {
  sz[v] = 1;
  for (int i = 0; i < adj[v].size(); i++) {
    int u = adj[v][i].first;
    if (u == p || u == ban) continue;
    dfs_size(u, v, ban);
    sz[v] += sz[u];
  }
}
void dfs(int v, int p, int ban, long long tot) {
  if (p == -1) {
    dfs_size(v, p, ban);
    val[v] = 0;
    best = v;
  }
  for (int i = 0; i < adj[v].size(); i++) {
    long long u = adj[v][i].first, w = adj[v][i].second;
    if (u == ban || u == p) continue;
    val[u] = val[v] - w * (sz[u] - (tot - sz[u]));
    if (val[u] < val[best]) best = u;
    dfs(u, v, ban, tot);
  }
}
long long ans, tot;
void cal(int v, int p, int ban) {
  if (p == -1) ans = 0;
  sz[v] = 1;
  for (int i = 0; i < adj[v].size(); i++) {
    long long u = adj[v][i].first, w = adj[v][i].second;
    if (u == ban || u == p) continue;
    cal(u, v, ban);
    sz[v] += sz[u];
    ans += w * (sz[u] * (tot - sz[u]) + sz[u] * (n - tot));
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
  }
  dfs1(0, -1);
  long long jav = 3e18;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < adj[i].size(); j++) {
      long long v = i, u = adj[i][j].first, w = adj[i][j].second;
      if (d[v] < d[u]) continue;
      long long Ans = w * size[v] * (n - size[v]);
      dfs(u, -1, v, n - size[v]);
      tot = size[u] - size[v];
      cal(best, -1, v);
      long long ans1 = ans;
      dfs(v, -1, u, size[v]);
      tot = size[v];
      cal(best, -1, u);
      jav = min(jav, Ans + ans1 + ans);
    }
  }
  cout << jav << "\n";
  return 0;
}
