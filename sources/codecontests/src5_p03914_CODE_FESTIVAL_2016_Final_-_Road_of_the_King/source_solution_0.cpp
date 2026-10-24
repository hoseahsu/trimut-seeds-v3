#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr ll kMod = 1e9 + 7;

ll dp[301][301][301];

int main()
{
  int n, m;
  cin >> n >> m;
  dp[0][n - 1][1] = 1;
  for (int i = 0; i < m; ++i)
  {
    for (int j = n; j >= 0; --j)
    {
      for (int k = 1; k <= n; ++k)
      {
        dp[i][j][k] %= kMod;
        dp[i + 1][j][k] += dp[i][j][k] * (n - j - k);
        if (j > 0)
          dp[i + 1][j - 1][k] += dp[i][j][k] * j;
        dp[i + 1][j][n - j] += dp[i][j][k] * k;
      }
    }
  }
  cout << dp[m][0][n] % kMod << endl;
}