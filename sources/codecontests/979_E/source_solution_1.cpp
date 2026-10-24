#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long n, m, x, ans, g[52][52][2], f[52][52][52][52][2], pw[52];
void upd(long long &x, long long y) {
  x += y;
  if (x >= mod) x %= mod;
}
int main() {
  scanf("%lld%lld", &n, &m);
  pw[0] = 1;
  for (int i = 1; i <= n; ++i) pw[i] = pw[i - 1] * 2 % mod;
  g[0][0][0] = 1;
  for (long long i = 1; i <= n; ++i) g[0][i][0] = g[0][i - 1][0] * 2 % mod;
  for (long long i = 1; i <= n; ++i) {
    g[i][0][0] = g[i][0][1] = (g[i - 1][0][0] + g[i - 1][0][1]) % mod;
    for (long long j = 1; j <= n; ++j) {
      g[i][j][0] = g[i][j - 1][0] * 2 % mod;
      g[i][j][1] = g[i][j - 1][1] * 2 % mod;
    }
  }
  f[0][0][0][0][0] = 1;
  for (long long i = 1; i <= n; ++i) {
    scanf("%lld", &x);
    for (long long j1 = 0; j1 < i; ++j1)
      for (long long j2 = 0; j1 + j2 < i; ++j2)
        for (long long j3 = 0; j1 + j2 + j3 < i; ++j3) {
          long long j4 = i - 1 - j1 - j2 - j3;
          for (long long k = 0; k < 2; ++k) {
            if (x == 0 || x == -1) {
              upd(f[i][j1 + 1][j2][j3][k ^ 1],
                  f[i - 1][j1][j2][j3][k] * g[j2][j4][0] % mod * pw[j1 + j3]);
              upd(f[i][j1][j2][j3 + 1][k],
                  f[i - 1][j1][j2][j3][k] * g[j2][j4][1] % mod * pw[j1 + j3]);
            }
            if (x == 1 || x == -1) {
              upd(f[i][j1][j2 + 1][j3][k ^ 1],
                  f[i - 1][j1][j2][j3][k] * g[j1][j3][0] % mod * pw[j2 + j4]);
              upd(f[i][j1][j2][j3][k],
                  f[i - 1][j1][j2][j3][k] * g[j1][j3][1] % mod * pw[j2 + j4]);
            }
          }
        }
  }
  for (long long j1 = 0; j1 <= n; ++j1)
    for (long long j2 = 0; j1 + j2 <= n; ++j2)
      for (long long j3 = 0; j1 + j2 + j3 <= n; ++j3)
        upd(ans, f[n][j1][j2][j3][m]);
  printf("%lld\n", ans);
  return 0;
}
