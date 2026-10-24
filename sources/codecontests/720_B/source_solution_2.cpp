#include <bits/stdc++.h>
using namespace std;
const int INF = (int)2e9;
const long long INFL = (long long)9e18;
const int MAXINT = ((~0) ^ (1 << 31));
const long long MAXLL = ((~0) ^ ((long long)1 << 63));
template <class T>
inline T pow2(T a) {
  return a * a;
}
template <class T>
inline bool mineq(T& a, T b) {
  return (a > b) ? (a = b, true) : false;
}
template <class T>
inline bool maxeq(T& a, T b) {
  return (a < b) ? (a = b, true) : false;
}
const int maxn = 1e5 + 100;
int n, m;
int pr[maxn], cl[maxn];
int visited[maxn];
vector<pair<int, int> > adj[maxn];
vector<vector<int> > cmp;
struct E {
  int k, c;
  E() {}
  E(int _k, int _c) : k(_k), c(_c) {}
} es[4200010];
struct Flow {
  int n, m, dis[500010];
  int qq[500010], qr, ql;
  vector<int> e[500010];
  void init(int _n) {
    n = _n;
    m = 0;
    for (int i = 0; i < n; i++) e[i] = vector<int>();
  }
  void add_edge(int a, int b, int c) {
    e[a].push_back(m);
    es[m] = E(b, c);
    m++;
    e[b].push_back(m);
    es[m] = E(a, 0);
    m++;
  }
  bool BFS(int src, int sink) {
    memset(dis, -1, n * sizeof(int));
    ql = qr = 0;
    qq[qr++] = src;
    dis[src] = 0;
    while (ql != qr && dis[sink] == -1) {
      int p = qq[ql++];
      for (auto it = (e[p]).begin(); it != (e[p]).end(); it++) {
        E ee = es[*it];
        if (ee.c == 0 || dis[ee.k] != -1) continue;
        dis[ee.k] = dis[p] + 1;
        qq[qr++] = ee.k;
      }
    }
    return dis[sink] != -1;
  }
  long long go(int p, int sink, long long c) {
    if (p == sink) return c;
    long long ret = 0, tmp;
    for (auto it = (e[p]).begin(); it != (e[p]).end(); it++) {
      E& ee = es[*it];
      if (ee.c == 0 || dis[p] + 1 != dis[ee.k]) continue;
      tmp = go(ee.k, sink, min(c - ret, (long long)ee.c));
      ret += tmp;
      ee.c -= tmp;
      es[(*it) ^ 1].c += tmp;
      if (ret == c) break;
    }
    if (ret == 0) dis[p] = -1;
    return ret;
  }
  long long max_flow(int src, int sink) {
    long long ret = 0;
    while (BFS(src, sink)) ret += go(src, sink, 1LL << 60);
    return ret;
  }
} mf;
void dfs(int v, int par, int col) {
  visited[v] = 1;
  pr[v] = par;
  cl[v] = col;
  for (auto id : adj[v]) {
    int u = id.first;
    int c = id.second;
    if (u == par) continue;
    if (visited[u] == 1) {
      cmp.push_back(vector<int>());
      vector<int>& now = cmp.back();
      int id = v;
      now.push_back(c);
      do {
        now.push_back(cl[id]);
        id = pr[id];
      } while (id != u);
    } else if (!visited[u])
      dfs(u, v, c);
  }
  visited[v] = 2;
}
set<int> colors;
int cycle_id[maxn], color_id[maxn];
int deg[maxn];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  mf.init((int)1e5);
  cin >> n >> m;
  for (int i = 0; i < (int)(m); i++) {
    int a, b, c;
    cin >> a >> b >> c;
    colors.insert(c);
    deg[c]++;
    adj[a].push_back(make_pair(b, c));
    adj[b].push_back(make_pair(a, c));
  }
  dfs(1, -1, -1);
  assert(n - 1 + (int)cmp.size() == m);
  int src = 0, sink = 1, newid = 2;
  for (int i = 0; i < (int)(cmp.size()); i++) {
    cycle_id[i] = newid++;
    mf.add_edge(cycle_id[i], sink, 1);
  }
  for (auto it : colors) {
    color_id[it] = newid++;
    mf.add_edge(src, color_id[it], deg[it] - 1);
  }
  for (int i = 0; i < (int)(cmp.size()); i++) {
    for (int j = 0; j < (int)(cmp[i].size()); j++) {
      mf.add_edge(color_id[cmp[i][j]], cycle_id[i], 1);
    }
  }
  cout << colors.size() - (cmp.size() - mf.max_flow(src, sink)) << endl;
}
