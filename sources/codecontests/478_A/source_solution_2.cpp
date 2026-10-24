#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long a, b, c, d, e;
  cin >> a >> b >> c >> d >> e;
  long long sum = a + b + c + d + e;
  if (sum == 0)
    cout << -1 << '\n';
  else if (sum % 5 == 0)
    cout << sum / 5 << '\n';
  else
    cout << -1 << '\n';
  return 0;
}
