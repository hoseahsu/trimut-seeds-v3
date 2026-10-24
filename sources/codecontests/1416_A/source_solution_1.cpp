#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e16;
const long long N = 1e5 + 1;
const long long mod = 1e9 + 7;
void solve() {
  long long n;
  cin >> n;
  vector<long long> last_ind(n + 1, -1);
  vector<long long> m(n + 1, 0);
  for (long long i = 0; i < n; i++) {
    long long a;
    cin >> a;
    m[a] = max(m[a], i - last_ind[a]);
    last_ind[a] = i;
  }
  for (long long i = 1; i <= n; i++) {
    m[i] = max(m[i], n - last_ind[i]);
  }
  vector<long long> ans(n + 1, -1);
  for (long long i = 1; i <= n; i++) {
    for (long long j = m[i]; j <= n and ans[j] == -1; j++) {
      ans[j] = i;
    }
  }
  for (long long i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
