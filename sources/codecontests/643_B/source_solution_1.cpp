#include <bits/stdc++.h>
using namespace std;
long long int n, k, a, b, c, d, p;
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  cin >> a >> b >> c >> d;
  p = (n * (n - 1)) / 2;
  p -= 2;
  if (n == 4) {
    cout << -1;
    return 0;
  }
  if (k < n + 1) {
    cout << -1;
    return 0;
  }
  if (k > p) {
    cout << -1;
    return 0;
  }
  cout << a << " " << c << " ";
  for (int i = 1; i <= n; i++) {
    if (i != a && i != b && i != c && i != d) cout << i << " ";
  }
  cout << d << " " << b << endl;
  cout << c << " " << a << " ";
  for (int i = 1; i <= n; i++) {
    if (i != a && i != b && i != c && i != d) cout << i << " ";
  }
  cout << b << " " << d << endl;
  return 0;
}
