#include <bits/stdc++.h>
using namespace std;
double p, dp[2000 + 1][2000 + 1];
int main() {
  int n, t;
  cin >> n >> p >> t;
  for (int i = 0; i <= t; i++) dp[0][i] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= t; j++)
      dp[i][j] = p * dp[i - 1][j - 1] + (1 - p) * dp[i][j - 1];
  double res = 0;
  for (int i = 1; i <= n; i++) res += dp[i][t];
  cout << fixed << setprecision(6) << res << endl;
  return 0;
}
