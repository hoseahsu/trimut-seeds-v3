#include <bits/stdc++.h>
inline int read() {
  int data = 0, w = 1;
  char ch = getchar();
  while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
  if (ch == '-') w = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') data = data * 10 + (ch ^ 48), ch = getchar();
  return data * w;
}
using ll = long long;
template <typename T>
inline void chkmin(T &x, const T &y) {
  if (y < x) x = y;
}
const ll INF(0x3f3f3f3f3f3f3f3fll);
const int N(205);
int n, t, K;
ll a[N], b[N], c[N], sa[N], sb[N], f[N][N][2], g[N][N][2];
int main() {
  n = read(), t = read(), K = read();
  for (int i = 1; i <= n; i++) a[i] = read(), b[i] = read(), c[i] = read();
  ++n, a[n] = b[n] = 2e9, c[n] = INF;
  for (int i = 1; i <= n; i++)
    sa[i] = sa[i - 1] + a[i], sb[i] = sb[i - 1] + b[i];
  std::memset(f, 0x3f, sizeof f), std::memset(g, 0x3f, sizeof g);
  std::memset(*f, 0, sizeof *f), std::memset(*g, 0, sizeof *g);
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= t; j++)
      for (int k = 0; k < 2; k++) {
        if (k * a[i] + j * b[i] <= c[i] && f[i - 1][j][k] != INF) {
          chkmin(f[i][j][k], f[i - 1][j][k]);
          ll c = (k * sa[i - 1] + j * sb[i - 1] + K - 1) / K;
          if (c * K <= k * sa[i] + j * sb[i]) chkmin(g[i][j][k], c);
        }
        for (int l = 0; l < j; l++)
          if (g[i][l][k] != INF) {
            ll res = k * sa[i] + l * sb[i] - K * g[i][l][k],
               cnt = (std::max(res + (j - l) * b[i] - c[i], 0ll) + K - 1) / K;
            if (cnt * K <= res && f[i - 1][j - l][0] != INF) {
              chkmin(f[i][j][k], g[i][l][k] + cnt + f[i - 1][j - l][0]);
              ll c = ((j - l) * sb[i - 1] + K - 1) / K;
              if (c * K <= (j - l) * sb[i] + res - cnt * K)
                chkmin(g[i][j][k], g[i][l][k] + cnt + c);
            }
          }
      }
  printf("%lld\n", f[n][t][1]);
  return 0;
}
