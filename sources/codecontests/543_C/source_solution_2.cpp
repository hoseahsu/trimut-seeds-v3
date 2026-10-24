#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
long long co[25][25], n, m, p[25][25], dp[1 << 20], ms[25][25];
char c[25][25];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= m; j++) {
      cin >> c[i][j];
    }
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= m; j++) cin >> co[i][j];
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      long long maxi = 0;
      for (long long k = 1; k <= n; k++) {
        if (c[i][j] == c[k][j]) {
          p[i][j] += co[k][j];
          ms[i][j] |= 1 << (k - 1);
          maxi = max(maxi, co[k][j]);
        }
      }
      p[i][j] -= maxi;
    }
  }
  long long maxi = 1e18;
  for (long long j = 0; j < 1 << n; j++) dp[j] = maxi;
  dp[0] = 0;
  for (long long mk = 0; mk < 1 << n; mk++) {
    if (dp[mk] == maxi) continue;
    for (long long i = 1; i <= n; i++)
      if (!(mk & (1 << (i - 1)))) {
        for (long long j = 1; j <= m; j++) {
          dp[mk | ms[i][j]] = min(dp[mk | ms[i][j]], dp[mk] + p[i][j]);
          dp[mk | (1 << (i - 1))] =
              min(dp[mk | (1 << (i - 1))], dp[mk] + co[i][j]);
        }
      }
  }
  cout << dp[(1 << n) - 1];
  return 0;
}
