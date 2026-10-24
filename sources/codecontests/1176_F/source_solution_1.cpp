#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int MAX = 2e5 + 5;
const long long MAX2 = 11;
const long long MOD = 998244353;
const long long INF = 2e18;
const int dr[] = {1, 0, -1, 0, 1, 1, -1, -1, 0};
const int dc[] = {0, 1, 0, -1, 1, -1, 1, -1, 0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;
int n, k, c, x, id;
long long dp[MAX][10], z[MAX][7], cnt[MAX][4];
priority_queue<int> pq[4];
long long f(int nw, int st) {
  if (nw > n) return 0;
  if (dp[nw][st] != -1) return dp[nw][st];
  long long ret = f(nw + 1, st), tmp;
  tmp = max(z[nw][1], max(z[nw][4], z[nw][6]));
  ret = max(ret, f(nw + 1, (st + 1) % 10) + tmp + (st == 9 ? tmp : 0));
  if (cnt[nw][1] >= 2) {
    ret = max(ret, f(nw + 1, (st + 2) % 10) + z[nw][1] + z[nw][2] +
                       (st >= 8 ? z[nw][1] : 0));
  }
  if (cnt[nw][1] && cnt[nw][2]) {
    ret = max(ret, f(nw + 1, (st + 2) % 10) + z[nw][1] + z[nw][4] +
                       (st >= 8 ? max(z[nw][4], z[nw][1]) : 0));
  }
  if (cnt[nw][1] == 3) {
    ret = max(ret, f(nw + 1, (st + 3) % 10) + z[nw][1] + z[nw][2] + z[nw][3] +
                       (st >= 7 ? z[nw][1] : 0));
  }
  return dp[nw][st] = ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (long long i = 1; i <= n; ++i) {
    cin >> k;
    for (long long j = 1; j <= 3; ++j)
      while (!pq[j].empty()) pq[j].pop();
    for (long long j = 1; j <= k; ++j) {
      cin >> c >> x;
      pq[c].push(x);
    }
    id = 0;
    for (long long j = 1; j <= 3; ++j) {
      if (pq[1].empty()) break;
      z[i][++id] = pq[1].top();
      cnt[i][1]++;
      pq[1].pop();
    }
    id = 3;
    for (long long j = 1; j <= 2; ++j) {
      if (pq[2].empty()) break;
      z[i][++id] = pq[2].top();
      cnt[i][2]++;
      pq[2].pop();
    }
    id = 5;
    for (long long j = 1; j <= 1; ++j) {
      if (pq[3].empty()) break;
      z[i][++id] = pq[3].top();
      cnt[i][3]++;
      pq[3].pop();
    }
  }
  memset(dp, -1, sizeof dp);
  cout << f(1, 0) << "\n";
  return 0;
}
