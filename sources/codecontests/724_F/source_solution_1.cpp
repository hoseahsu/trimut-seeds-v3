#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const int M = 12;
long long MOD;
long long dp[N][M][N];
long long curCom[M];
long long inv2[M];
inline long long mypow(long long a, long long b) {
  int res = 1;
  while (b) {
    if (b & 1) {
      res = ((long long)res * a) % MOD;
    }
    a = ((long long)a * a) % MOD;
    b >>= 1;
  }
  return res;
}
inline long long cmb(long long a, long long b) {
  long long d1, d2;
  if (a < b) {
    return 0;
  }
  d1 = 1;
  d2 = inv2[b];
  while (b) {
    d1 = (long long)d1 * a % MOD;
    b--;
    a--;
  }
  return (long long)d1 * d2 % MOD;
}
bool calCurCom(long long n, int m) {
  if (n == 0) {
    return false;
  }
  int i;
  long long mul = 1;
  long long tmp = n;
  for (i = 1; i <= m; i++, tmp++) {
    mul = mul * tmp % MOD;
    curCom[i] = mul * inv2[i] % MOD;
  }
  return true;
}
int main() {
  int n, d, i, j, k, l, m;
  scanf("%d%d%lld", &n, &d, &MOD);
  if (n <= 2) {
    printf("1\n");
    return 0;
  }
  long long tmp = 1;
  inv2[1] = 1;
  for (i = 2; i <= d; i++) {
    tmp = tmp * i;
    inv2[i] = mypow(tmp, MOD - 2);
  }
  for (k = 0; k <= n; k++) {
    dp[1][0][k] = 1;
  }
  for (i = 2; i <= d + 1; i++) {
    for (k = 1; k <= n; k++) {
      dp[i][i - 1][k] = 1;
    }
  }
  for (i = 3; i <= n; i++) {
    for (j = 1; j <= d && j < i - 1; j++) {
      for (k = 2; k <= n - 1; k++) {
        dp[i][j][k] = dp[i][j][k - 1];
        if (calCurCom(dp[k][d - 1][k - 1], j)) {
          for (l = 1; l <= j && l * k < i; l++) {
            tmp = (long long)dp[i - k * l][j - l][k - 1] * curCom[l] % MOD;
            dp[i][j][k] = ((long long)dp[i][j][k] + tmp) % MOD;
          }
        }
      }
    }
  }
  long long ans = 0;
  ans = dp[n][d][(n + 1) / 2 - 1];
  if ((n & 1) == 0) {
    ans = ((long long)ans + cmb(dp[n / 2][d - 1][n / 2 - 1] + 1, 2)) % MOD;
  }
  printf("%lld\n", ans);
  return 0;
}
