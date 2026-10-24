#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e2 + 5;
const int mod = 998244353;
int n, k;
int dp[2][maxn][maxn];
int main() {
  scanf("%d%d", &n, &k);
  int now = 1, pre = 0;
  dp[0][0][0] = 1;
  for (int i = 0; i < n; i++) {
    pre = i & 1;
    now = pre ^ 1;
    memset(dp[now], 0, sizeof(dp[now]));
    for (int j = 0; j <= n; j++)
      for (int k = 0; k <= n; k++) {
        dp[now][j + 1][max(j + 1, k)] =
            (dp[now][j + 1][max(j + 1, k)] + dp[pre][j][k]) % mod;
        dp[now][1][max(1, k)] = (dp[now][1][max(1, k)] + dp[pre][j][k]) % mod;
      }
  }
  int cnt[maxn];
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++) cnt[i] = (cnt[i] + dp[n & 1][j][i]) % mod;
  long long ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (i * j < k) ans = (ans + (long long)cnt[i] * cnt[j]) % mod;
  ans = (ans * (long long)((mod + 1) / 2)) % mod;
  printf("%lld\n", ans);
  return 0;
}
