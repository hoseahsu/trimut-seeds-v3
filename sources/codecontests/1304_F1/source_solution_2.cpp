#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, neg = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') neg = -1;
    c = getchar();
  }
  while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
  return x * neg;
}
inline void print(long long x) {
  if (x < 0) {
    putchar('-');
    print(abs(x));
    return;
  }
  if (x <= 9)
    putchar(x + '0');
  else {
    print(x / 10);
    putchar(x % 10 + '0');
  }
}
inline long long qpow(long long x, long long e, long long _MOD) {
  long long ans = 1;
  while (e) {
    if (e & 1) ans = ans * x % _MOD;
    x = x * x % _MOD;
    e >>= 1;
  }
  return ans;
}
long long n = read(), m = read(), k = read(), a[55][20005], sum[55][20005],
          dp[55][20005], mxp[55][20005], mxs[55][20005];
signed main() {
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= m; j++)
      a[i][j] = read(), sum[i][j] = sum[i][j - 1] + a[i][j];
  for (long long i = 1; i <= m; i++)
    dp[1][i] = sum[1][min(i + k - 1, m)] - sum[1][i - 1];
  for (long long i = 1; i <= m; i++)
    mxp[1][i] = max(mxp[1][i - 1],
                    dp[1][i] + sum[2][min(i + k - 1, m)] - sum[2][i - 1]);
  for (long long i = m; i >= 1; i--)
    mxs[1][i] = max(mxs[1][i + 1],
                    dp[1][i] + sum[2][min(i + k - 1, m)] - sum[2][i - 1]);
  for (long long i = 2; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      if (j + k <= m)
        dp[i][j] = max(dp[i][j],
                       mxs[i - 1][j + k] + sum[i][j + k - 1] - sum[i][j - 1]);
      if (j - k >= 1)
        dp[i][j] = max(dp[i][j],
                       mxp[i - 1][j - k] + sum[i][j + k - 1] - sum[i][j - 1]);
      for (long long l = max(j - k + 1, 1ll); l <= min(j + k - 1, m); l++) {
        dp[i][j] = max(dp[i][j], dp[i - 1][l] +
                                     sum[i][min(max(j + k - 1, l + k - 1), m)] -
                                     sum[i][min(j, l) - 1]);
      }
    }
    for (long long j = 1; j <= m; j++)
      mxp[i][j] = max(mxp[i][j - 1], dp[i][j] + sum[i + 1][min(j + k - 1, m)] -
                                         sum[i + 1][j - 1]);
    for (long long j = m; j >= 1; j--)
      mxs[i][j] = max(mxs[i][j + 1], dp[i][j] + sum[i + 1][min(j + k - 1, m)] -
                                         sum[i + 1][j - 1]);
  }
  long long ans = 0;
  for (long long i = 1; i <= m; i++) ans = max(ans, dp[n][i]);
  cout << ans << endl;
  return 0;
}
