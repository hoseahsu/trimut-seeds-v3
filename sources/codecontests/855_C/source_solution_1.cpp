#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
int n, m, k, mx;
vector<int> v[N];
long long dp[N][3][13], dp2[3][13];
void dfs(int p, int x) {
  for (auto u : v[x])
    if (u != p) dfs(x, u);
  if (p and v[x].size() == 1) {
    dp[x][0][0] = k - 1;
    dp[x][1][1] = 1;
    dp[x][2][0] = m - k;
  } else {
    dp[x][0][0] = k - 1;
    dp[x][1][1] = 1;
    dp[x][2][0] = m - k;
    for (auto u : v[x]) {
      if (u != p) {
        for (int t = 0; t <= mx; t++) dp2[0][t] = dp2[1][t] = dp2[2][t] = 0;
        for (int t = 0; t <= mx; t++) {
          for (int t2 = 0; t + t2 <= mx; t2++) {
            (dp2[0][t + t2] += (dp[u][0][t2] + dp[u][1][t2] + dp[u][2][t2]) %
                               mod * dp[x][0][t] % mod) %= mod;
            (dp2[1][t + t2] += dp[u][0][t2] * dp[x][1][t] % mod) %= mod;
            (dp2[2][t + t2] +=
             (dp[u][0][t2] + dp[u][2][t2]) % mod * dp[x][2][t] % mod) %= mod;
          }
        }
        for (int t = 0; t <= mx; t++)
          dp[x][0][t] = dp2[0][t], dp[x][1][t] = dp2[1][t],
          dp[x][2][t] = dp2[2][t];
      }
    }
    dp[x][1][0] = 0;
  }
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);
  }
  scanf("%d %d", &k, &mx);
  dfs(0, 1);
  long long res = 0;
  for (int i = 0; i <= mx; i++) {
    res += dp[1][0][i] + dp[1][1][i] + dp[1][2][i];
    res %= mod;
  }
  printf("%lld\n", res);
  return 0;
}
