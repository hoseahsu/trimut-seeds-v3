#include <bits/stdc++.h>
using namespace std;
vector<long long> v;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long a = 0, b = 0, c, d, e, f = 0, l, g, m, n, k, i, j, t, p, q;
  cin >> m >> n;
  for (i = 1; i <= n / 2; i++) {
    for (j = 1; j <= m; j++) {
      cout << j << ' ' << i << '\n';
      cout << m - j + 1 << ' ' << n - i + 1 << '\n';
    }
  }
  if (n % 2) {
    d = n / 2 + 1;
    for (i = 1; i <= m / 2; i++) {
      cout << i << ' ' << d << '\n';
      cout << m - i + 1 << ' ' << d << '\n';
    }
    if (m % 2) {
      cout << m / 2 + 1 << ' ' << d << '\n';
    }
  }
  return 0;
}
