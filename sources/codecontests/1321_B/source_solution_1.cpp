#include <bits/stdc++.h>
using namespace std;
constexpr long long INF = 2e18;
constexpr long long MOD = 1e9 + 7;
constexpr long long MAXN = 2e5 + 3;
void solve() {
  long long n;
  cin >> n;
  map<long long, long long> m;
  long long ans = 0;
  for (long long i = 1; i <= n; ++i) {
    long long x;
    cin >> x;
    m[x - i] += x;
    ans = max(ans, m[x - i]);
  }
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  while (t--) solve();
}
