#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long double pi = acos(-1);
const int MOD = 1e9 + 7;
string s;
const int MAXN = 1000010;
long long int dp[MAXN][5][2];
int main() {
  ios::sync_with_stdio(false);
  ;
  cin >> s;
  int n = s.size();
  if (s[0] == '?') {
    dp[0][0][1] = 1;
    dp[0][1][0] = 1;
    dp[0][3][1] = 1;
  } else if (s[0] == '0') {
    dp[0][0][1] = 1;
  } else if (s[0] == '1') {
    dp[0][1][0] = 1;
  } else if (s[0] == '*') {
    dp[0][3][1] = 1;
  }
  for (int i = 1; i < n; i++) {
    if (s[i] == '?') {
      dp[i][3][1] = (dp[i - 1][1][0] + dp[i - 1][2][0] + dp[i - 1][3][1]) % MOD;
      dp[i][0][1] = (dp[i - 1][0][1] + dp[i - 1][1][1]) % MOD;
      dp[i][1][1] = dp[i - 1][3][1];
      dp[i][1][0] = (dp[i - 1][0][1] + dp[i - 1][1][1]) % MOD;
      dp[i][2][0] = dp[i - 1][3][1];
    } else if (s[i] == '*') {
      dp[i][3][1] = (dp[i - 1][1][0] + dp[i - 1][2][0] + dp[i - 1][3][1]) % MOD;
    } else if (s[i] == '0') {
      dp[i][0][1] = (dp[i - 1][0][1] + dp[i - 1][1][1]) % MOD;
    } else if (s[i] == '1') {
      dp[i][1][1] = dp[i - 1][3][1];
      dp[i][1][0] = (dp[i - 1][0][1] + dp[i - 1][1][1]) % MOD;
    } else if (s[i] == '2') {
      dp[i][2][0] = dp[i - 1][3][1];
    }
  }
  long long int resp = 0;
  for (int i = 0; i < 4; i++) {
    resp += dp[n - 1][i][1];
  }
  resp = resp % MOD;
  cout << resp << "\n";
}
