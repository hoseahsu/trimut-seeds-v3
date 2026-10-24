#include <bits/stdc++.h>
using namespace std;
int main() {
  long long k, b, t, n, z, ans;
  cin >> k >> b >> t >> n;
  z = 1;
  int i = 0;
  while (z <= n) {
    z = k * z + b;
    i++;
  }
  ans = t - i + 1;
  if (ans < 0) ans = 0;
  cout << ans << endl;
  return 0;
}
