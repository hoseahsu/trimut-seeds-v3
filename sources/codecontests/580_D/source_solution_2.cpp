#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
long long val[22];
long long has[22][22];
long long dp[22][1 << 20];
int CountsetBits(long long num) { return __builtin_popcount(num); }
long long solve(int mask, int last) {
  if (dp[last][mask] != -1)
    return dp[last][mask];
  else if (CountsetBits(mask) >= m)
    return 0;
  else {
    long long ret = -1;
    for (int i = 0; i < n; i++) {
      if (!(mask & (1 << i))) {
        ret = max(ret, solve(mask | (1 << i), i) + val[i] + has[last][i]);
      }
    }
    return dp[last][mask] = ret;
  }
}
int main() {
  memset(dp, -1, sizeof(dp));
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) cin >> val[i];
  for (int i = 0; i < k; i++) {
    long long x, y, c;
    cin >> x >> y >> c;
    has[x - 1][y - 1] = c;
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, solve(0 | (1 << i), i) + val[i]);
  }
  cout << ans << endl;
  return 0;
}
