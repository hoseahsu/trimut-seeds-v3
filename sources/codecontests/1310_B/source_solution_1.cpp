#include <bits/stdc++.h>
using namespace std;
inline bool setmin(int &x, int y) { return (y < x) ? x = y, 1 : 0; }
inline bool setmax(int &x, int y) { return (y > x) ? x = y, 1 : 0; }
inline bool setmin(long long &x, long long y) { return (y < x) ? x = y, 1 : 0; }
inline bool setmax(long long &x, long long y) { return (y > x) ? x = y, 1 : 0; }
const int N = 200000;
const int inf = (int)1e9 + 1;
const long long big = (long long)1e18 + 1;
const int P = 239;
const int P1 = 31;
const int P2 = 57;
const int MOD = (int)1e9 + 7;
const int MOD1 = (int)1e9 + 9;
const int MOD2 = 998244353;
const long double eps = 1e-9;
const double pi = atan2(0, -1);
const int ABC = 26;
int cnt[N];
map<pair<pair<int, int>, bool>, int> dp;
int solve(int l, int r, bool need) {
  auto it = dp.find(make_pair(make_pair(l, r), need));
  if (it != dp.end()) {
    return it->second;
  }
  int ans = -inf;
  if (need && (cnt[r] - cnt[l]) == 0) {
    ans = -inf;
  } else if (r - l == 1) {
    ans = 0;
  } else {
    int m = (l + r) / 2;
    int a0 = solve(l, m, false);
    int a1 = solve(l, m, true);
    int b0 = solve(m, r, false);
    int b1 = solve(m, r, true);
    int cntL = cnt[m] - cnt[l];
    int cntR = cnt[r] - cnt[m];
    if (!need && cntL >= 0 && cntR >= 0) {
      int val = a0 + b0;
      if (cntL >= 1 || cntR >= 1) {
        val += 2;
      }
      setmax(ans, val);
    }
    if (cntL >= 1 && cntR >= 0) {
      int val = a1 + b0;
      if (need) {
        if (cntL + cntR > 1) {
          setmax(ans, val + 1 + 2);
        } else {
          setmax(ans, val + 1);
        }
      } else {
        if (cntL + cntR > 1) {
          setmax(ans, val + 1 + 2);
        } else {
          setmax(ans, val + 2);
        }
      }
    }
    if (cntL >= 0 && cntR >= 1) {
      int val = a0 + b1;
      if (need) {
        if (cntL + cntR > 1) {
          setmax(ans, val + 1 + 2);
        } else {
          setmax(ans, val + 1);
        }
      } else {
        if (cntL + cntR > 1) {
          setmax(ans, val + 1 + 2);
        } else {
          setmax(ans, val + 2);
        }
      }
    }
    if (cntL >= 1 && cntR >= 1) {
      int val = a1 + b1;
      setmax(ans, val + 1 + 2);
    }
  }
  return dp[make_pair(make_pair(l, r), need)] = ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.precision(20);
  cout << fixed;
  int n, k;
  cin >> n >> k;
  if (k == 0) {
    cout << 0 << "\n";
    return 0;
  }
  for (int i = (0); i < (k); i++) {
    int x;
    cin >> x;
    cnt[x - 1]++;
  }
  int ans = 1;
  for (int i = (0); i < ((1 << (n - 1))); i++) {
    if (cnt[i * 2] || cnt[i * 2 + 1]) {
      ans++;
    }
  }
  for (int i = (1); i < ((1 << n)); i++) {
    cnt[i / 2] += cnt[i];
    cnt[i] = 0;
  }
  n--;
  for (int i = ((1 << n) - 1); i > (-1); i--) {
    cnt[i + 1] = cnt[i];
    cnt[i] = 0;
  }
  for (int i = (1); i < ((1 << n) + 1); i++) {
    cnt[i] += cnt[i - 1];
  }
  cout << ans + max(solve(0, (1 << n), false), solve(0, (1 << n), true))
       << "\n";
  return 0;
}
