#include <bits/stdc++.h>
using namespace std;
long long dp[2005][2005], ans[2005];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s, p;
  cin >> s >> p;
  long long ls = s.size(), lp = p.size();
  s = '.' + s;
  p = '.' + p;
  for (long long i = 1; i <= ls; i++) {
    for (long long j = 0; j <= i; j++) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
    long long x = i, j = 1, id = -1, k = 0;
    while (x <= ls) {
      if (s[x] == p[j]) {
        x++;
        j++;
        if (j > lp) {
          id = x - 1;
          break;
        }
      } else
        x++, k++;
    }
    if (id == -1) continue;
    for (long long j = 0; j <= i; j++) {
      if (j + k <= ls) dp[id][j + k] = max(dp[id][j + k], dp[i - 1][j] + 1);
    }
  }
  for (long long i = 0; i <= ls; i++) {
    for (long long j = i + 1; j - i >= lp && j <= ls; j++)
      dp[ls][j] = max(dp[ls][i] - 1, dp[ls][j]);
  }
  for (long long i = 0; i <= ls; i++) {
    for (long long j = 0; j <= i; j++) {
      long long low = 1, high = dp[ls][j];
      while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (ls - mid * lp >= i) {
          ans[i] = max(ans[i], mid);
          low = mid + 1;
        } else
          high = mid - 1;
      }
    }
    cout << ans[i] << " ";
  }
}
