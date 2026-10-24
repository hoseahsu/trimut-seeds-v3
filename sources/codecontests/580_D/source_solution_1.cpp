#include <bits/stdc++.h>
using namespace std;
long long dp[262500][18];
long long a[18], g[18][18];
long long bit_count(long long x) {
  long long ret = 0;
  while (x) {
    x -= (x & -x);
    ret++;
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < k; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    g[u][v] = w;
  }
  long long ans = 0;
  for (long long bitmask = 1; bitmask < (1LL << n); bitmask++) {
    long long cnt = bit_count(bitmask);
    if (cnt > m) continue;
    for (long long last = 0; last < n; last++) {
      if (bitmask & (1LL << last)) {
        if (cnt == 1) {
          dp[bitmask][last] = a[last];
          if (m == 1) ans = max(ans, dp[bitmask][last]);
        }
        for (long long bit = 0; bit < n; bit++) {
          if (!(bitmask & (1LL << bit))) {
            dp[bitmask | (1LL << bit)][bit] =
                max(dp[bitmask | (1LL << bit)][bit],
                    dp[bitmask][last] + a[bit] + g[last][bit]);
            if (cnt == m - 1) ans = max(ans, dp[bitmask | (1LL << bit)][bit]);
          }
        }
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
