#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000007;
const long long linf = 1ll * inf * inf;
const int N = 1000 + 7;
const int M = 30;
const int multipleTest = 0;
int n;
int a[N][N];
long long L[N][N];
long long dp[N][N];
void solve() {
  cin >> n;
  for (int i = (0), _b = (n); i < _b; ++i)
    for (int j = (0), _b = (n); j < _b; ++j) scanf("%d", &a[i][j]);
  for (int i = (0), _b = (n); i < _b; ++i) L[i][i] = dp[i][i] = 1;
  for (int len = (1), _b = (n); len < _b; ++len) {
    for (int i = (0), _b = (n - len); i < _b; ++i) {
      int j = i + len;
      for (int k = (i), _b = (j); k < _b; ++k) {
        if (a[i][j]) L[i][j] = (L[i][j] + dp[i][k] * dp[k + 1][j]) % inf;
        dp[i][j] = (dp[i][j] + L[i][k + 1] * dp[k + 1][j]) % inf;
      }
    }
  }
  cout << dp[0][n - 1] << '\n';
}
int main() {
  int Test = 1;
  if (multipleTest) {
    cin >> Test;
  }
  for (int i = 0; i < Test; ++i) {
    solve();
  }
}
