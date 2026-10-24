#include <bits/stdc++.h>
using namespace std;
namespace gao {
inline int read() {
  char c = getchar();
  int x = 0, f = 1;
  while (c > '9' || c < '0') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
struct node {
  int t, nt;
} e[1000005 << 1];
int f[1000005], c[1000005], head[1000005], sz[1000005], n, tot, a, b, m, n2;
long long ans;
inline void add2(int u, int v) {
  e[++tot].t = v;
  e[tot].nt = head[u];
  head[u] = tot;
}
inline void add(int u, int v) { add2(u, v), add2(v, u); }
inline void dfs(int u, int fa) {
  f[u] = fa;
  sz[u] = c[u];
  for (int i = head[u]; i; i = e[i].nt) {
    int v = e[i].t;
    if (v == fa) continue;
    dfs(v, u);
    sz[u] += sz[v];
  }
}
inline void calc() {
  dfs(a, 0);
  int u = b;
  while (f[u] != a) u = f[u];
  ans = 1ll * (n2 - sz[u] - 1) * (sz[b] - 1);
  printf("%lld\n", ans);
}
inline void clear() {
  for (int i = 1; i <= n; i++) head[i] = sz[i] = c[i] = f[i] = 0;
  n = tot = 0;
}
}  // namespace gao
namespace gao2 {
struct node {
  int t, nt;
} e[1000005 << 1];
int n, f[1000005], head[1000005], tot, dfn[1000005], low[1000005], st[1000005],
    tp, cnt;
inline void add(int u, int v) {
  e[++tot].t = v;
  e[tot].nt = head[u];
  head[u] = tot;
}
inline void tarjan(int u, int fa) {
  dfn[u] = low[u] = ++cnt;
  st[++tp] = u;
  for (int i = head[u]; i; i = e[i].nt) {
    int v = e[i].t;
    if (v == fa) continue;
    if (!dfn[v]) {
      tarjan(v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] >= dfn[u]) {
        gao::n++;
        gao::add(u, gao::n);
        while (tp > 0) {
          gao::add(gao::n, st[tp]);
          tp--;
          if (st[tp + 1] == v) break;
        }
      }
    } else
      low[u] = min(low[u], dfn[v]);
  }
}
inline void solve() {
  gao::n = n;
  for (int i = 1; i <= n; i++) gao::c[i] = 1;
  for (int i = 1; i <= n; i++) {
    if (!dfn[i]) tarjan(i, 0);
  }
}
inline void clear() {
  for (int i = 1; i <= n; i++) head[i] = dfn[i] = low[i] = st[i] = 0;
  n = tot = cnt = tp = 0;
}
}  // namespace gao2
int T, n, a, b, m;
inline int read() {
  char c = getchar();
  int x = 0, f = 1;
  while (c > '9' || c < '0') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
signed main() {
  T = read();
  while (T--) {
    gao::clear();
    gao2::clear();
    n = read(), m = read(), gao::a = read(), gao::b = read();
    for (int i = 1; i <= m; i++) {
      int u = read(), v = read();
      gao2::add(u, v), gao2::add(v, u);
    }
    gao2::n = n;
    gao::n2 = n;
    gao2::solve();
    gao::calc();
  }
}
