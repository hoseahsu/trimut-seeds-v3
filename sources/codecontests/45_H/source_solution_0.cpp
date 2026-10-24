#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const long double eps = 1e-7;
const int inf = 1000000010;
const long long INF = 10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 100010, LOG = 20;
struct DSU {
  int par[901];
  vector<int> vec[901];
  DSU() {
    for (int i = 1; i <= 900; i++) par[i] = i, vec[i].push_back(i);
  }
  int get(int x) {
    if (par[x] == x) return x;
    return par[x] = get(par[x]);
  }
  void join(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) return;
    if (vec[x].size() < vec[y].size()) swap(x, y);
    for (int v : vec[y]) vec[x].push_back(v);
    par[y] = x;
    vec[y].clear();
  }
} dsu;
int n, m, k, u, v, x, y, t, a, b, ans;
int h[901];
bool connected[901][901];
pair<int, int> E[MAXN];
vector<int> G1[MAXN];
vector<int> G2[MAXN];
vector<pair<int, int> > cutedge;
vector<int> leaf;
int bridge(int node, int par) {
  int res = h[node] = h[node] = h[par] + 1;
  for (int v : G1[node])
    if (v != par) {
      if (h[v])
        res = min(res, h[v]);
      else
        res = min(res, bridge(v, node));
    }
  if (node != 1 && res >= h[node])
    cutedge.push_back({par, node});
  else
    dsu.join(par, node);
  return res;
}
void dfs(int node, int par) {
  if (G2[node].size() == 1) {
    leaf.push_back(node);
    return;
  }
  for (int v : G2[node])
    if (v != par) dfs(v, node);
}
void connect(int u, int v) {
  for (int x : dsu.vec[u])
    for (int y : dsu.vec[v])
      if (!connected[x][y]) {
        cout << x << ' ' << y << '\n';
        connected[x][y] = 1;
        return;
      }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  if (n == 2) return cout << -1 << '\n', 0;
  for (int i = 1; i <= m; i++) {
    cin >> u >> v;
    G1[u].push_back(v);
    G1[v].push_back(u);
    E[i] = {u, v};
    connected[u][v] = 1;
  }
  bridge(1, 1);
  for (pair<int, int> p : cutedge) {
    int u = dsu.get(p.first), v = dsu.get(p.second);
    G2[v].push_back(u);
    G2[u].push_back(v);
  }
  int root = 0;
  for (int i = 1; i <= n; i++)
    if (G2[i].size()) {
      if (G2[i].size() == 1)
        leaf.push_back(i);
      else
        root = i;
    }
  if (!leaf.size()) return cout << 0 << '\n', 0;
  cout << (leaf.size() + 1) / 2 << '\n';
  if (!root) {
    connect(leaf[0], leaf[1]);
    return 0;
  }
  leaf.clear();
  dfs(root, root);
  if (leaf.size() & 1) {
    int v = leaf.back();
    leaf.pop_back();
    connect(v, leaf.back());
  }
  for (int i = 0; 2 * i < leaf.size(); i++)
    connect(leaf[i], leaf[i + leaf.size() / 2]);
  for (int i = 1; i <= n; i++) {
    cerr << "(dsu.vec[i])"
         << " : ";
    for (auto SHIT : (dsu.vec[i])) cerr << SHIT << ' ';
    cerr << endl;
    ;
  }
  return 0;
}
