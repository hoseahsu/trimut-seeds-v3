#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, INF = 1e9, ans = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < (n); i++) cin >> a[i];
  for (int i = 30; i > 0; i--) {
    vector<int> b(n);
    for (int j = 0; j < (n); j++) {
      if (a[j] <= i)
        b[j] = a[j];
      else
        b[j] = -INF;
    }
    int mx = 0, cur = 0;
    for (int j = 0; j < (n); j++) {
      if (cur + b[j] > b[j])
        cur += b[j];
      else
        cur = b[j];
      mx = max(mx, cur);
    }
    ans = max(ans, mx - i);
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  cout.precision(12);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
