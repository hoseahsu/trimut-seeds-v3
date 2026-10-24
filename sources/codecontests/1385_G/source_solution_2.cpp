#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const int inf = 1e9 + 10;
const long long INF = 1e18;
const long double EPS = 1e-10;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
struct UnionFind {
  vector<long long> par;
  vector<long long> siz;
  UnionFind(long long sz_) : par(sz_), siz(sz_, 1) {
    for (long long i = 0; i < sz_; ++i) par[i] = i;
  }
  void init(long long sz_) {
    par.clear();
    par.resize(sz_);
    siz.clear();
    siz.resize(sz_, 1);
    for (long long i = 0; i < sz_; ++i) par[i] = i;
  }
  long long root(long long x) {
    while (par[x] != x) {
      x = par[x] = par[par[x]];
    }
    return x;
  }
  bool merge(long long x, long long y) {
    x = root(x);
    y = root(y);
    if (x == y) return false;
    if (siz[x] < siz[y]) swap(x, y);
    siz[x] += siz[y];
    par[y] = x;
    return true;
  }
  bool issame(long long x, long long y) { return root(x) == root(y); }
  long long size(long long x) { return siz[root(x)]; }
};
class SCC {
  void dfs(int v) {
    if (used[v]) return;
    used[v] = 1;
    for (auto &u : g[v]) dfs(u);
    ord.push_back(v);
  }
  void rdfs(int v, int idx) {
    if (~cmp[v]) return;
    cmp[v] = idx;
    for (auto &u : rg[v]) rdfs(u, idx);
  }

 public:
  vector<vector<int>> g, rg, dag, sc;
  vector<int> cmp, ord, used;
  SCC(int n) : g(n), rg(n), cmp(n, -1), used(n, 0) {}
  SCC(vector<vector<int>> &g)
      : g(g), rg(g.size()), cmp(g.size(), -1), used(g.size(), 0) {
    for (int v = 0; v < (int)g.size(); ++v)
      for (int u : g[v]) rg[u].push_back(v);
    build();
  }
  void add_edge(int s, int t) {
    g[s].push_back(t);
    rg[t].push_back(s);
  }
  void build() {
    for (int i = 0; i < (int)g.size(); ++i) dfs(i);
    reverse(ord.begin(), ord.end());
    int sz = 0;
    for (int i : ord)
      if (!~cmp[i]) rdfs(i, sz++);
    dag.resize(sz);
    sc.resize(sz);
    for (int i = 0; i < (int)g.size(); ++i) {
      for (int j : g[i]) {
        int x = cmp[i], y = cmp[j];
        if (x != y) dag[x].emplace_back(y);
      }
      sc[cmp[i]].push_back(i);
    }
  }
  int size() { return dag.size(); }
  int operator[](int x) { return cmp[x]; }
  bool same(int x, int y) { return cmp[x] == cmp[y]; }
};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(25);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int>> a(2, vector<int>(n));
    for (int i = 0; i < (2); ++i) {
      for (int j = 0; j < (n); ++j) {
        cin >> a[i][j];
        a[i][j]--;
      }
    }
    vector<vector<int>> idx(n);
    for (int i = 0; i < (2); ++i)
      for (int j = 0; j < (n); ++j) idx[a[i][j]].push_back(n * i + j);
    bool ng = false;
    for (int i = 0; i < (n); ++i) {
      if (idx[i].size() != 2) {
        ng = true;
        break;
      }
    }
    if (ng) {
      cout << -1 << '\n';
      continue;
    }
    SCC scc(n * 2);
    UnionFind uf(n);
    for (int i = 0; i < (n); ++i) {
      int v = idx[i][0], u = idx[i][1];
      if (v % n == u % n) continue;
      if (v / n == u / n) {
        v %= n, u %= n;
        scc.add_edge(v, u + n);
        scc.add_edge(u, v + n);
        scc.add_edge(u + n, v);
        scc.add_edge(v + n, u);
      } else {
        v %= n, u %= n;
        scc.add_edge(v, u);
        scc.add_edge(u, v);
        scc.add_edge(v + n, u + n);
        scc.add_edge(u + n, v + n);
      }
      uf.merge(v, u);
    }
    scc.build();
    for (int i = 0; i < (n); ++i) {
      if (scc.same(i, i + n)) {
        ng = true;
        break;
      }
    }
    if (ng) {
      cout << -1 << '\n';
      continue;
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < (n); ++i) g[uf.root(i)].push_back(i);
    vector<int> ans;
    for (int i = 0; i < (n); ++i) {
      if (g[i].empty()) continue;
      set<int> res;
      for (int x : g[i])
        if (scc[x] < scc[n + x]) res.insert(x);
      if (res.size() > g[i].size() - res.size()) {
        for (int x : g[i]) {
          if (scc[x] < scc[n + x])
            res.erase(x);
          else
            res.insert(x);
        }
      }
      for (auto x : res) ans.push_back(x);
    }
    cout << ans.size() << '\n';
    for (auto x : ans) cout << x + 1 << ' ';
    cout << '\n';
  }
  return 0;
}
