#include <bits/stdc++.h>
long long R = 7 + 1e9, NUMTESTCASE;
const int NN = 10 + 1e5;
const double pi = acos(-1.0);
int di[4] = {1, 0, -1, 0}, dj[4] = {0, 1, 0, -1},
    DI[8] = {1, 1, 0, -1, -1, -1, 0, 1}, DJ[8] = {0, 1, 1, 1, 0, -1, -1, -1};
using namespace std;
long long x, pref[100][NN], n, m, k, memo[100][NN], ans;
set<pair<long long, long long>, greater<pair<long long, long long> > >
    flag[100];
long long solve(int i, int j) {
  if (i == n + 1) return 0;
  if (memo[i][j] != -1) return memo[i][j];
  long long res = pref[i][min(m, j + k)] + pref[i + 1][min(m, j + k)] -
                  pref[i][j - 1] - pref[i + 1][j - 1];
  long long draft, mx = 0;
  for (auto it : flag[i + 1]) {
    int p = it.second;
    draft = it.first;
    if (abs(j - p) <= k)
      draft -= pref[i + 1][min(min(p + k, j + k), m)] -
               pref[i + 1][max(p - 1, j - 1)];
    mx = max(mx, draft);
    if (abs(p - j) > k) break;
  }
  flag[i].insert({mx + res, j});
  ans = max(ans, mx + res);
  return memo[i][j] = mx + res;
}
int main() {
  memset(memo, -1, sizeof(memo));
  cin >> n >> m >> k;
  k--;
  for (int i = (1); i <= (n); ++i)
    for (int j = (1); j <= (m); ++j) {
      scanf("%lld", &x);
      pref[i][j] = pref[i][j - 1] + x;
    }
  for (int i = n; i >= 1; i--)
    for (int j = (1); j <= (m); ++j) solve(i, j);
  cout << ans;
  return 0;
}
