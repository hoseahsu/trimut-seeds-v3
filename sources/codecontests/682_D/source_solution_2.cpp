#include <bits/stdc++.h>
using namespace std;
const long long int M = 1e9 + 7;
const long long int N = 1e5 + 5;
long long int n, m, k;
long long int dp[1001][1001][11][2];
string s, t;
long long int solve(long long int l, long long int r, long long int tot,
                    long long int cont) {
  if (l == n || r == m || tot > k) {
    if (tot == k)
      return 0;
    else
      return -1000000000000000000;
  }
  long long int &ans = dp[l][r][tot][cont];
  if (ans != -1) return ans;
  if (s[l] != t[r])
    ans = max(solve(l + 1, r, tot, 0), solve(l, r + 1, tot, 0));
  else {
    if (cont == 1) {
      ans = max(
          max(solve(l + 1, r, tot, 0), solve(l, r + 1, tot, 0)),
          1 + max(solve(l + 1, r + 1, tot, 1), solve(l + 1, r + 1, tot, 0)));
    } else {
      ans = max(max(solve(l + 1, r, tot, 0), solve(l, r + 1, tot, 0)),
                1 + max(solve(l + 1, r + 1, tot + 1, 0),
                        solve(l + 1, r + 1, tot + 1, 1)));
    }
  }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k;
  cin >> s >> t;
  memset(dp, -1, sizeof(dp));
  long long int x = solve(0, 0, 0, 0);
  cout << x;
}
