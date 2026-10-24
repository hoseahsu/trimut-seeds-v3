#include <bits/stdc++.h>
using namespace std;
long long int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void solve() {
  long long int k, b, n, t;
  cin >> k >> b >> n >> t;
  long long int ans = 0, bacteria = k + b;
  while (bacteria <= t) {
    bacteria = (bacteria * k) + b;
    ans++;
  }
  cout << max(0LL, n - ans);
}
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
  ;
  long long int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
