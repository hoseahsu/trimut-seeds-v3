// http://rippro.org/event/ritscamp2015/F.pdf
// http://tubo28.me/blog/post/2015/10/28/aoj2667/
#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define DEBUG(x) cerr << #x << " = " << x << endl
#define int long long
struct LCA {
  int N, logN;
  vector<vector<int>> G;
  vector<int> depth;
  vector<vector<int>> parent;
  LCA(int size) : N(size), G(size), depth(size) {
    logN = 0;
    for(int x = 1; x < N; x *= 2) logN++;
    parent.assign(max<int>(logN, 1), vector<int>(N));
  }
  void add_edge(int u, int v) {
    G[u].push_back(v);
    G[v].push_back(u);
  }
  void build(int root) {
    deque<pair<int, int>> Q;
    Q.emplace_back(root, -1);
    while(!Q.empty()) {
      pair<int, int> p = Q.back(); Q.pop_back();
      int cur = p.first, prev = p.second;
      parent[0][cur] = prev;
      if(prev == -1) depth[cur] = 0;
      else depth[cur] = depth[prev] + 1;
      for(int next : G[cur]) {
        if(next != prev) Q.emplace_back(next, cur);
      }
    }
    for(int k = 1; k < logN; k++) {
      for(int v = 0; v < N; v++) {
        if(parent[k - 1][v] == -1) parent[k][v] = -1;
        else parent[k][v] = parent[k - 1][parent[k - 1][v]];
      }
    }
  }
  int lca(int u, int v) {
    if(depth[u] > depth[v]) swap(u, v);
    for(int k = 0; k < logN; k++) {
      if(((depth[v] - depth[u]) >> k) & 1) {
        v = parent[k][v];
      }
    }
    if(u == v) return u;
    for(int k = logN - 1; k >= 0; k--) {
      if(parent[k][u] != parent[k][v]) {
        u = parent[k][u];
        v = parent[k][v];
      }
    }
    return parent[0][u];
  }
};
struct Compact {
  const vector<vector<int>> &G;
  const vector<bool> &V;
  vector<int> parent;
  Compact(const vector<vector<int>> &g, const vector<bool> &v) : G(g), V(v) { }
  void build(int root) {
    parent.assign(G.size(), -1);
    deque<tuple<int, int, int>> Q;
    Q.emplace_back(root, -1, -1);
    while(!Q.empty()) {
      int cur, prev, p;
      tie(cur, prev, p) = Q.back(); Q.pop_back();
      if(V[cur]) {
        parent[cur] = p;
        p = cur;
      }
      for(int next : G[cur]) {
        if(next != prev) Q.emplace_back(next, cur, p);
      }
    }
  }
  int getWeight(const int v, const vector<int> &addNow, const vector<int> &addLazy, const vector<int> &depth) {
    int w = addNow[v];
    for(int cur = v; cur != -1; cur = parent[cur]) {
      w += addLazy[cur] * (depth[v] - depth[cur]);
    }
    return w;
  }
  void propagate(const int root, vector<int> &addNow, const vector<int> &addLazy) {
    deque<tuple<int, int, int, int>> Q;
    Q.emplace_back(root, -1, 0, 0);
    while(!Q.empty()) {
      int cur, prev, add, addDiff;
      tie(cur, prev, add, addDiff) = Q.back(); Q.pop_back();
      addNow[cur] += add;
      for(int next : G[cur]) {
        if(next != prev) Q.emplace_back(next, cur, add + addDiff + addLazy[cur], addDiff + addLazy[cur]);
      }
    }
  }
};
const int MAX_N = 150000;
const int SQRT_Q = 1600;
int T[SQRT_Q], A[SQRT_Q], B[SQRT_Q];
signed main() {
  ios::sync_with_stdio(false);
  int N, Q; cin >> N >> Q;
  vector<vector<int>> G(N);
  LCA lca(N);
  REP(i,N-1) {
    int a, b; cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
    lca.add_edge(a, b);
  }
  lca.build(0);
  vector<int> addNow(N, 0);
  vector<int> addLazy(N);
  vector<bool> V(N);
  for(int qb = 0; qb < Q; qb += SQRT_Q) {
    V.assign(N, false);
    for(int i = 0; qb + i < Q && i < SQRT_Q; ++i) {
      cin >> T[i] >> A[i] >> B[i];
      if(T[i] == 0) {
        V[A[i]] = true;
        V[B[i]] = true;
        V[lca.lca(A[i], B[i])] = true;
      }
      else {
        V[A[i]] = true;
      }
    }
    Compact c(G, V);
    c.build(0);
    fill(addLazy.begin(), addLazy.end(), 0);
    for(int i = 0; qb + i < Q && i < SQRT_Q; ++i) {
      if(T[i] == 0) {
        int d = 0;
        d += c.getWeight(A[i], addNow, addLazy, lca.depth);
        d += c.getWeight(B[i], addNow, addLazy, lca.depth);
        d -= 2 * c.getWeight(lca.lca(A[i], B[i]), addNow, addLazy, lca.depth);
        cout << d << '\n';
      }
      else {
        addLazy[A[i]] += B[i];
      }
    }
    c.propagate(0, addNow, addLazy);
  }
}