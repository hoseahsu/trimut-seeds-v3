#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k, m;
  cin >> n >> m >> k;
  long long a[n + 1];
  for (int i = 1; i < n + 1; i++) {
    cin >> a[i];
  }
  k = min(k, m - 1);
  long long ans = 1e9;
  long long fans = -1;
  for (int i = 0; i <= k; i++) {
    long long ans = 1e9;
    for (int j = 0; j <= m - 1 - k; j++) {
      long long caseans = max(a[1 + i + j], a[1 + i + j + n - m]);
      ans = min(ans, caseans);
    }
    fans = max(fans, ans);
  }
  cout << fans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t, n;
  cin >> t;
  while (t--) {
    solve();
  }
}
