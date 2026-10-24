#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
int solve() {
  int n, k;
  cin >> n >> k;
  vector<pair<pair<int, int>, int>> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i].first.second >> arr[i].first.first, arr[i].second = i + 1;
  sort(arr.begin(), arr.end());
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++)
    a[i] = arr[i].first.second, b[i] = arr[i].first.first;
  vector<vector<int>> dp(n + 1, vector<int>(k + 1, -INF));
  vector<vector<bool>> op(n + 1, vector<bool>(k + 1, 0));
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    dp[i + 1][0] = dp[i][0] + (k - 1) * b[i];
    for (int j = 1; j < k + 1; j++) {
      int v1 = dp[i][j] + (k - 1) * b[i],
          v2 = dp[i][j - 1] + (j - 1) * b[i] + a[i];
      if (v2 > v1) op[i + 1][j] = 1;
      dp[i + 1][j] = max(v1, v2);
    }
  }
  int curj = k;
  vector<int> maj, bon;
  for (int i = n; i; i--) {
    int oo = op[i][curj];
    if (oo) {
      maj.push_back(i - 1);
      curj--;
    } else {
      bon.push_back(i - 1);
    }
  }
  cout << n + n - k << endl;
  for (int i = k - 1; i >= 1; i--) cout << arr[maj[i]].second << " ";
  for (auto i : bon) cout << arr[i].second << " " << -arr[i].second << " ";
  cout << arr[maj[0]].second << endl;
  return 0;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) solve();
  return 0;
}
