#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
void solve() {
  long long n, q;
  cin >> n >> q;
  long long a[n];
  vector<long long> cnt(31);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    ++cnt[__builtin_ctz(a[i])];
  }
  while (q--) {
    long long x;
    cin >> x;
    long long ans = 0;
    for (long long i = 30; i >= 0 && x > 0; i--) {
      long long req = min(x >> i, cnt[i]);
      ans += req;
      x -= (1 << i) * req;
    }
    if (x > 0) ans = -1;
    cout << ans << '\n';
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  solve();
  return 0;
}
