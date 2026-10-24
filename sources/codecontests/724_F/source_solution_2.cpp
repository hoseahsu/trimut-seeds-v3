#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1000 + 3, MAX_D = 10 + 3;
int n, d, modu, dp[MAX_N][MAX_D][MAX_N];
int inv[MAX_N];
inline long long mod_pow(long long a, int b) {
  long long res = 1;
  while (b) {
    if (b & 1) (res *= a) %= modu;
    (a *= a) %= modu;
    b >>= 1;
  }
  return res;
}
int main() {
  scanf("%d%d%d", &n, &d, &modu);
  if (n <= 2) return puts("1"), 0;
  for (int i = 1; i < n; ++i) inv[i] = mod_pow(i, modu - 2);
  dp[1][0][0] = dp[1][d - 1][0] = 1;
  for (int i = 2; i <= n; ++i)
    for (int j = 1; j <= d; ++j)
      for (int k = 1; k < i; ++k) {
        dp[i][j][k] = dp[i][j][k - 1];
        int r = dp[k][d - 1][k - 1] - 1, c = 1;
        for (int t = 1; t * k < i && t <= j; ++t) {
          c = (long long)c * (++r) % modu * inv[t] % modu;
          (dp[i][j][k] +=
           (long long)dp[i - t * k][j - t][min(k - 1, i - t * k - 1)] * c %
           modu) %= modu;
        }
      }
  long long ans = dp[n][d][(n + 1) / 2 - 1];
  if (n % 2 == 0)
    ans += (long long)(dp[n / 2][d - 1][n / 2 - 1]) *
           (dp[n / 2][d - 1][n / 2 - 1] + 1) / 2;
  ans %= modu;
  cout << ans << endl;
  return 0;
}
