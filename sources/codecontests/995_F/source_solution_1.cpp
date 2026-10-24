#include <bits/stdc++.h>
const int N = 3005;
int n, D, h[N], nxt[N], adj[N], fa[N], t, f[N][N], inv[N], ifac[N], C[N][N],
    g[N], s[N][N];
inline void dfs(const int x) {
  for (register int i = 1; i <= n; ++i) f[x][i] = 1;
  for (register int i = h[x], j, v; i; i = nxt[i])
    for (dfs(v = adj[i]), j = 1; j <= n; ++j)
      f[x][j] = (0ll + f[x][j]) * s[v][j] % 1000000007;
  for (register int i = 1; i <= n; ++i)
    s[x][i] = s[x][i - 1] + f[x][i],
    s[x][i] >= 1000000007 ? s[x][i] -= 1000000007 : 0;
}
int main() {
  scanf("%d%d", &n, &D);
  register int i, j;
  auto add = [&](const int u, const int v) {
    nxt[++t] = h[u], h[u] = t, adj[t] = v;
  };
  for (i = 2; i <= n; ++i) scanf("%d", &fa[i]), add(fa[i], i);
  for (i = 2, inv[0] = inv[1] = ifac[0] = ifac[1] = 1; i <= n; ++i)
    inv[i] = (0ll + inv[1000000007 % i]) * (1000000007 - 1000000007 / i) %
             1000000007,
    ifac[i] = (0ll + ifac[i - 1]) * inv[i] % 1000000007;
  for (i = C[0][0] = 1; i <= n; ++i)
    for (j = C[i][0] = C[i][i] = 1; j < i; ++j)
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1],
      C[i][j] >= 1000000007 ? C[i][j] -= 1000000007 : 0;
  dfs(1);
  register int ans = 0, o;
  for (i = 1; i <= n; ++i)
    for (j = 1, g[i] = f[1][i]; j < i; ++j)
      g[i] = (g[i] - (0ll + C[i - 1][j - 1]) * g[j]) % 1000000007,
      g[i] < 0 ? g[i] += 1000000007 : 0;
  for (i = 1; i <= n; ans = (ans + (0ll + o) * g[i]) % 1000000007, ++i)
    for (j = D - i + 1, o = ifac[i]; j <= D; ++j)
      o = (0ll + o) * j % 1000000007;
  printf("%d", ans);
  return 0;
}
