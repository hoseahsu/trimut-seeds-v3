#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 5;
const int N = 105;
int a[N], b[N], n, sum;
int dp[2][N * N][N];
int main() {
  scanf("%d", &n);
  sum = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    sum += a[i];
  }
  for (int i = 1; i <= n; i++) scanf("%d", b + i);
  for (int j = 0; j <= sum; j++)
    for (int k = 0; k <= n; k++) dp[0][j][k] = -INF;
  dp[0][0][0] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= sum; j++)
      for (int k = 0; k <= n; k++) {
        dp[i & 1][j][k] = dp[i & 1 ^ 1][j][k];
        if (k)
          dp[i & 1][j][k] = max(dp[i & 1][j][k],
                                dp[i & 1 ^ 1][max(j - b[i], 0)][k - 1] + a[i]);
      }
  for (int k = 0; k <= n; k++) {
    if (dp[n & 1][sum][k] >= 0) {
      printf("%d %d\n", k, sum - dp[n & 1][sum][k]);
      break;
    }
  }
  return 0;
}
