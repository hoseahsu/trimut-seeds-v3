#include <bits/stdc++.h>
using namespace std;
int dp[100 + 1][2];
int main() {
  int n;
  scanf("%d", &n);
  int ans = 0, temp;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &temp);
    if (temp) {
      dp[i][1] = max(dp[i - 1][1] + 1, dp[i - 1][0] + 1);
      dp[i][0] = dp[i - 1][0];
    } else {
      dp[i][1] = dp[i - 1][1];
      dp[i][0] = dp[i - 1][0] + 1;
    }
    ans = max(max(ans, dp[i][0]), dp[i][1]);
  }
  printf("%d", ans);
  return 0;
}
