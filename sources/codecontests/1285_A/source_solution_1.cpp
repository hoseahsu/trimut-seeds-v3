#include <bits/stdc++.h>
const long long inf = 1e18 + 7;
const long long N = 1e6 + 1;
const long long md = 1e9 + 7;
using namespace std;
void sol() {
  long long n;
  cin >> n;
  string x;
  cin >> x;
  long long lc = count(x.begin(), x.end(), 'L');
  long long rc = count(x.begin(), x.end(), 'R');
  long long ans = rc - (-lc) + 1;
  cout << ans << "\n";
}
int32_t main() {
  long long T = 1;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  while (T--) sol();
  return 0;
}
