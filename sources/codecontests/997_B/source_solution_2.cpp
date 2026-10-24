#include <bits/stdc++.h>
using namespace std;
long long n, dp[50][9], ans;
int main() {
  cin >> n;
  for (int i = 0; i < 49; i++)
    for (int j = 0; j < 9; j++)
      for (int k = 0; k < 49; k++)
        for (int t = 0; t < 9; t++)
          if (k + t < n && i * 9 + j * 4 > 4 * t + k * 9 &&
              (j * 4 + i * 9 - 4 * t - k * 9) % 49 == 0) {
            dp[i][j] = 1;
          }
  for (int i = 0; i < 49 && i <= n; i++)
    for (int j = 0; j < 9 && i + j <= n; j++)
      if (!dp[i][j]) ans += (n - i - j + 1);
  cout << ans;
}
