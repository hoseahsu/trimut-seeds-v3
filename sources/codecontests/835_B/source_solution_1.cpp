#include <bits/stdc++.h>
using namespace std;
void test_case() {
  long long k;
  cin >> k;
  string n;
  cin >> n;
  long long sz = n.size();
  long long s = 0;
  for (long long i = (0); i < (sz); ++i) {
    s += (n[i] - '0');
  }
  if (s >= k) {
    cout << 0 << "\n";
    return;
  }
  sort(n.begin(), n.end());
  long long ans = 0;
  for (long long i = (0); i < (sz); ++i) {
    s -= (n[i] - '0');
    s += 9;
    ans++;
    if (s >= k) {
      cout << ans << "\n";
      return;
    }
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    test_case();
  }
  return 0;
}
