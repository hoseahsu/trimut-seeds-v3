#include <bits/stdc++.h>
using namespace std;
int tm[3][3], n;
long long dp[40][3][3];
long long mseek(int n, int s, int t) {
  if (dp[n][s][t]) return dp[n][s][t];
  if (n == 1)
    return dp[n][s][t] = min(tm[s][t], tm[s][3 - s - t] + tm[3 - s - t][t]);
  long long ansa =
      mseek(n - 1, s, 3 - s - t) + tm[s][t] + mseek(n - 1, 3 - s - t, t);
  long long ansb = mseek(n - 1, s, t) + tm[s][3 - s - t] + mseek(n - 1, t, s) +
                   tm[3 - s - t][t] + mseek(n - 1, s, t);
  return dp[n][s][t] = min(ansa, ansb);
}
void ir() {
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) scanf("%d", &tm[i][j]);
  scanf("%d", &n);
}
int main() {
  ir();
  cout << mseek(n, 0, 2) << '\n';
  return 0;
}
