#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
template <typename T1, typename T2>
inline void chkmin(T1 &x, const T2 &y) {
  if (x > y) x = y;
}
template <typename T1, typename T2>
inline void chkmax(T1 &x, const T2 &y) {
  if (x < y) x = y;
}
void solve() {
  ll n, m, x;
  cin >> n >> x >> m;
  ll L = x, R = x;
  for (ll i = 0; i < m; i++) {
    ll l, r;
    cin >> l >> r;
    if (l > R || r < L) continue;
    chkmax(R, r);
    chkmin(L, l);
  }
  cout << R - L + 1 << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
