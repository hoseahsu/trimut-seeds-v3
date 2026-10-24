#include <bits/stdc++.h>
using namespace std;
long long a[1000001], fr[1000001], sum[1000001];
int main() {
  long long n, i, x, nr1, nr2, p, ans = 0, lg, v1, v2;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    x = a[i];
    lg = 0;
    while (x != 0) {
      lg++;
      x /= 10;
    }
    fr[lg]++;
  }
  for (i = 20; i >= 1; i--) sum[i] = sum[i + 1] + fr[i];
  for (i = 1; i <= n; i++) {
    x = a[i];
    nr1 = 0;
    nr2 = 0;
    p = 1;
    lg = 0;
    while (x != 0) {
      nr1 += (x % 10) * p;
      nr2 = nr1 * 10;
      lg++;
      x /= 10;
      p *= 100;
      p %= 998244353;
      nr1 %= 998244353;
      nr2 %= 998244353;
      v2 = (nr2 + x * p) % 998244353;
      if (x != 0)
        v2 = (v2 * fr[lg]) % 998244353;
      else
        v2 = (v2 * sum[lg]) % 998244353;
      v1 = (nr1 + x * p) % 998244353;
      if (x != 0)
        v1 = (v1 * fr[lg]) % 998244353;
      else
        v1 = (v1 * sum[lg]) % 998244353;
      ans = (ans + v1 + v2) % 998244353;
    }
  }
  cout << ans << '\n';
  return 0;
}
