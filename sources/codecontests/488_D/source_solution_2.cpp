#include <bits/stdc++.h>
using namespace std;
set<pair<int, int> > sa, sb;
int dp[100010], a[100010];
int n, x, s, l;
int main() {
  cin >> n >> s >> l;
  for (int i = 1; i <= (n); i++) cin >> a[i];
  dp[0] = 0;
  for (int i = 1; i <= (n); i++) {
    sa.insert(make_pair(a[i], i));
    while (sa.rbegin()->first - sa.begin()->first > s) {
      sb.erase(make_pair(dp[x], x));
      x++;
      sa.erase(make_pair(a[x], x));
    }
    if (i >= l && sa.size() >= l && dp[i - l] >= 0)
      sb.insert(make_pair(dp[i - l], i - l));
    if (sb.empty())
      dp[i] = -1;
    else
      dp[i] = sb.begin()->first + 1;
  }
  cout << dp[n] << endl;
  return 0;
}
