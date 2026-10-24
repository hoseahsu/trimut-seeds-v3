#include <bits/stdc++.h>
using namespace std;
const long double pi = 3.1415926535897932384626433;
const int mod = 1000000007;
const long long inf = 3e18;
long long n, m, k;
long long dp[5001][5001];
vector<long long> v;
long long mkc(long long i, long long j) {
  if (j == 0 or i >= v.size()) {
    return 0;
  }
  if (dp[i][j] != -1) return dp[i][j];
  long long ans = 0;
  ans = max(mkc(i + 1, j), v[i] + mkc(i + m, j - 1));
  return dp[i][j] = ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  memset(dp, -1, sizeof(dp));
  cin >> n >> m >> k;
  vector<long long> a(n), pre(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  pre[0] = a[0];
  for (long long i = 1; i < n; i++) {
    pre[i] = pre[i - 1] + a[i];
  }
  for (long long i = n - 1; i >= m; i--) {
    pre[i] = pre[i] - pre[i - m];
  }
  for (long long i = m - 1; i < n; i++) {
    v.push_back(pre[i]);
  }
  cout << mkc(0, k);
}
