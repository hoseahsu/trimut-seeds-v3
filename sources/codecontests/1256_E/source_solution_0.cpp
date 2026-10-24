#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i].first;
    v[i].second = i;
  }
  vector<long long> dp(n + 1);
  vector<int> p(n + 1, -1);
  sort(v.begin(), v.end());
  fill(dp.begin(), dp.end(), 2e15);
  dp[0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 2; j < i + 5 && j < n; ++j) {
      int diff = v[j].first - v[i].first;
      if (dp[i] + diff < dp[j + 1]) {
        dp[j + 1] = dp[i] + diff;
        p[j + 1] = i;
      }
    }
  }
  int tail = n, teamId = 0;
  vector<int> ans(n);
  while (tail > 0) {
    for (int i = tail - 1; i >= p[tail]; --i) ans[v[i].second] = teamId + 1;
    tail = p[tail];
    teamId++;
  }
  cout << dp[n] << " " << teamId << endl;
  for (auto e : ans) cout << e << " ";
  cout << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
