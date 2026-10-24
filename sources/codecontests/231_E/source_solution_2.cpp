#include <bits/stdc++.h>
using namespace std;
inline long long in() {
  int32_t x;
  scanf("%d", &x);
  return x;
}
inline long long lin() {
  long long x;
  scanf("%lld", &x);
  return x;
}
inline string get() {
  char ch[2000010];
  scanf("%s", ch);
  return ch;
}
inline void read(long long *a, long long n) {
  for (long long i = 0; i < n; i++) a[i] = in();
}
template <class blank>
inline void out(blank x) {
  cout << x << "\n";
  exit(0);
}
const long long maxn = 1e5 + 10;
const long long maxm = 1e6 + 10;
const long long maxlg = 20;
const long long base = 29;
const long long base2 = 31;
const long long mod2 = 1e9 + 9;
const long long mod = 1e9 + 7;
const long long INF = 1e18 + 10;
const long long SQ = 317 + 5;
vector<pair<long long, long long> > g[maxn];
bool mark[maxn];
long long where[maxn];
long long cur = 1;
long long n, m;
vector<long long> adj[maxn];
vector<long long> vertices[maxn];
long long cnt[maxn], has[maxn];
long long root[maxn][maxlg];
bool cut[maxn];
long long h[maxn], l[maxn];
long long pre[maxn];
inline void tarjan(long long node, long long fa = 0) {
  h[node] = l[node] = (fa ? h[fa] + 1 : 0);
  pre[node] = fa;
  mark[node] = true;
  for (auto u : g[node]) {
    if (!mark[u.first]) {
      tarjan(u.first, node);
      l[node] = min(l[node], l[u.first]);
      if (l[u.first] > h[node]) cut[u.second] = true;
    } else if (u.first != fa && h[u.first] < h[node]) {
      for (long long V = node; V != pre[u.first]; V = pre[V]) {
        vertices[cur].push_back(V);
        where[V] = cur + n;
      }
      cur++;
    }
    if (u.first != fa) {
      l[node] = min(l[node], h[u.first]);
      if (l[u.first] > h[node]) cut[u.second] = true;
    }
  }
}
inline void dfs(long long node, long long fa = 0) {
  cnt[node] += cnt[fa];
  root[node][0] = fa;
  for (long long i = 1; i < maxlg; i++)
    root[node][i] = root[root[node][i - 1]][i - 1];
  for (auto u : adj[node]) {
    if (u - fa) {
      h[u] = h[node] + 1;
      dfs(u, node);
    }
  }
}
long long pr[maxn];
inline long long Root(long long v) {
  return pr[v] == v ? v : pr[v] = Root(pr[v]);
}
inline void merge(long long v, long long u) {
  v = Root(v), u = Root(u);
  pr[v] = u;
}
inline long long lca(long long p, long long q) {
  if (h[p] < h[q]) swap(p, q);
  for (long long i = maxlg - 1; i >= 0; i--)
    if (h[p] - (1 << i) >= h[q]) p = root[p][i];
  if (p == q) return p;
  for (long long i = maxlg - 1; i >= 0; i--)
    if (root[p][i] != root[q][i]) p = root[p][i], q = root[q][i];
  return root[p][0];
}
inline long long CNT(long long v, long long u) {
  long long LCA = lca(v, u);
  return cnt[v] + cnt[u] - 2 * cnt[LCA] + has[LCA];
}
long long pw[maxn];
pair<long long, long long> e[maxn];
int32_t main() {
  pw[0] = 1;
  for (long long i = 1; i < maxn; i++) pw[i] = pw[i - 1] * 2 % mod;
  n = in(), m = in();
  for (long long i = 1; i <= n; i++) pr[i] = where[i] = i;
  for (long long i = 0; i < m; i++) {
    long long v = in(), u = in();
    g[v].push_back({u, i});
    g[u].push_back({v, i});
    merge(v, u);
    e[i] = {v, u};
  }
  tarjan(1);
  memset(h, 0, sizeof h);
  for (long long i = 0; i < m; i++)
    if (cut[i]) {
      adj[where[e[i].first]].push_back(where[e[i].second]),
          adj[where[e[i].second]].push_back(where[e[i].first]);
    }
  for (long long i = 1; i < cur; i++) {
    for (auto v : vertices[i]) adj[v].push_back(i + n), adj[i + n].push_back(v);
  }
  for (long long i = 1; i < cur; i++) cnt[i + n] = 1, has[i + n] = true;
  dfs(1);
  long long q = in();
  while (q--) {
    long long v = in(), u = in();
    cout << pw[CNT(v, u)] << "\n";
  }
}
