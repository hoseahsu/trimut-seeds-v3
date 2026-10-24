#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
long long int ne;
long long int go(long long int idx, long long int pre) {
  if (idx == ne) return 0;
  long long int ans = 1e15;
  if (idx == 0)
    ans = min(ans, 1 + go(idx + 1, 0));
  else {
    if (idx == 3) {
      if (pre != 1) ans = min(ans, go(idx + 1, 1));
      if (pre != 2) ans = min(ans, go(idx + 1, 2));
    } else if (idx == 1) {
      if (pre != 1) ans = min(ans, go(idx + 1, 1));
    } else {
      if (pre != 2) ans = min(ans, go(idx + 1, 2));
    }
    ans = min(ans, 1 + go(idx + 1, 0));
  }
}
long double k, d, t;
long double kk, dl, dd, tt, tc;
long double kectotal, tnow, ans;
long double prnow, kebnow;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> k >> d >> t;
  kk = ceil(k / d);
  dd = kk * d;
  dl = dd - k;
  tt = 1 / (2 * t);
  tt = dl * tt;
  tc = k / t;
  kectotal = tt + tc;
  tnow = floor(1.0 / kectotal);
  ans = (tnow * dd);
  prnow = tnow * kectotal;
  kebnow = 1.0 - prnow;
  if (kebnow <= 0.000000000) {
  } else if (kebnow <= tc) {
    ans += ((kebnow / tc) * k);
    kebnow -= kebnow;
  } else if (kebnow > tc) {
    ans += k;
    kebnow -= tc;
  }
  if (kebnow <= 0.000000000) {
  } else if (kebnow <= tt) {
    ans += ((kebnow / tt) * dl);
    kebnow -= kebnow;
  }
  cout << fixed << setprecision(11) << ans << endl;
  return 0;
}
