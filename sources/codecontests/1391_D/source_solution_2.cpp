#include <bits/stdc++.h>
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
mt19937 myrand(time(0));
long long n, m;
string tmp[1000002], str[1000002];
long long dp[1000002][10];
long long call(long long pos, long long mask) {
  if (pos >= n) return 0;
  long long& ret = dp[pos][mask];
  if (ret != -1) return ret;
  ret = 1e18;
  long long tot = 1 << m, up = ((mask & 1) > 0) + ((mask & 2) > 0),
            down = ((mask & 2) > 0) + ((mask & 4) > 0);
  for (int nmask = 0; nmask < tot; nmask++) {
    long long cost = 0, addup = ((nmask & 1) > 0) + ((nmask & 2) > 0),
              adddown = ((nmask & 2) > 0) + ((nmask & 4) > 0);
    for (int i = 0; i < m; i++) {
      if ((str[i][pos] == '1') && !(nmask & (1 << i)))
        cost++;
      else if ((str[i][pos] == '0') && (nmask & (1 << i)))
        cost++;
    }
    if (pos == 0)
      ret = min(ret, cost + call(pos + 1, nmask));
    else if (m == 2 && (up + addup) & 1)
      ret = min(ret, cost + call(pos + 1, nmask));
    else if (m == 3 && (up + addup) & 1 && (down + adddown) & 1)
      ret = min(ret, cost + call(pos + 1, nmask));
  }
  return ret;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(), cout.tie();
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> tmp[i];
  if (n > 3 && m > 3) {
    cout << -1 << endl;
    return 0;
  }
  if (n == 1 || m == 1) {
    cout << 0 << endl;
    return 0;
  }
  swap(n, m);
  if (n >= m) {
    for (int i = 0; i < m; i++) str[i] = tmp[i];
  } else {
    for (int i = 0; i < n; i++) str[i].resize(m);
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) str[j][i] = tmp[i][j];
    }
    swap(n, m);
  }
  memset(dp, -1, sizeof dp);
  long long ans = call(0, 0);
  cout << ans << endl;
  return 0;
}
