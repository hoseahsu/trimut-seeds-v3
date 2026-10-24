#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
const int MOD = 1000000007;
signed main() {
  cin.tie(0), cout.tie(0);
  ios::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (k < n + 1 || n <= 4)
    cout << -1 << '\n', exit(0);
  else {
    cout << a << ' ' << c << ' ';
    for (int i = 1; i <= n; i++)
      if (i != a && i != b && i != c && i != d) cout << i << ' ';
    cout << d << ' ' << b << '\n';
    cout << c << ' ' << a << ' ';
    for (int i = 1; i <= n; i++)
      if (i != a && i != b && i != c && i != d) cout << i << ' ';
    cout << b << ' ' << d << '\n';
  }
  return 0;
}
