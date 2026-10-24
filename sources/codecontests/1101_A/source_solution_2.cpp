#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5, N2 = 2e5, N1 = 1e6, M = 1e2;
long long binpow(long long a, long long n) {
  long long ans = 1;
  while (n) {
    if (n & 1) ans *= a;
    a *= a;
    n >>= 1;
  }
  return ans;
}
string s, s1, s2;
long long n, m, t, x, y, z;
long long k, k1, k2, g, g1, g2, ans, kol, kol1;
char c;
long long mxx = 0, mxy = 0;
int main() {
  cin.tie(0);
  cin >> t;
  while (t--) {
    long long l, r, d;
    cin >> l >> r >> d;
    long long d1 = d;
    if (d < l)
      cout << d << endl;
    else if (r % d == 0)
      cout << r + d << endl;
    else {
      cout << d * (r / d + 1) << endl;
    }
  }
  return 0;
}
