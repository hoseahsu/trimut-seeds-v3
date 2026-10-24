#include <bits/stdc++.h>
using namespace std;
long long h[1001000], dp[1001000][2];
int n;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%I64d", &h[i]), h[i]--;
  for (int i = 1; i <= n; i++) {
    dp[i][0] =
        (dp[i - 1][0] + dp[i - 1][1] * min(h[i], h[i - 1]) + h[i]) % 1000000007;
    dp[i][1] = (min(h[i + 1], h[i]) +
                min(min(h[i], h[i - 1]), h[i + 1]) * dp[i - 1][1]) %
               1000000007;
  }
  printf("%I64d\n", dp[n][0]);
  return 0;
}
