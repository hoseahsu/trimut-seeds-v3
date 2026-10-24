#include <bits/stdc++.h>
using namespace std;
long long n, k, d, ans = -1;
int main() {
  cin >> n >> k;
  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }
  long long l = 0, r = k + 1, m;
  while (r - l >= 2) {
    m = (l + r) / 2;
    d = 1 + ((k * (k + 1)) / 2) - (((k - m) * (k - m + 1)) / 2) - m;
    if (d >= n) {
      ans = m;
      r = m;
    } else
      l = m;
  }
  cout << ans << endl;
  return 0;
}
