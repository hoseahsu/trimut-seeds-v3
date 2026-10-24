#include <bits/stdc++.h>
using namespace std;
const int N = 5010, M = 10100;
int la[N][M], dp[2][M], n, m, a[N], ans[N], sz, b[N], T;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  memset(dp, 0x3f, sizeof dp);
  dp[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    b[i] = b[i - 1] + a[i];
    T ^= 1;
    memset(dp[T], 0x3f, sizeof dp[T]);
    for (int j = 0; j <= sz; ++j)
      if (dp[!T][j] <= b[i - 1]) {
        int tmp = m + dp[!T][j] + j - b[i - 1];
        for (int k = 0; k <= a[i] / 2 && k <= tmp; ++k) {
          int nj = j + (a[i] - k) / 10;
          if (dp[!T][j] + a[i] - k < dp[T][nj])
            la[i][nj] = k, dp[T][nj] = dp[!T][j] + a[i] - k;
        }
      }
    sz += a[i] / 10;
  }
  int tmp = min_element(dp[T], dp[T] + sz + 1) - dp[T];
  cout << dp[T][tmp] << '\n';
  for (int i = n; i; --i) ans[i] = la[i][tmp], tmp -= (a[i] - ans[i]) / 10;
  for (int i = 1; i <= n; ++i) cout << ans[i] << " \n"[i == n];
  return 0;
}
