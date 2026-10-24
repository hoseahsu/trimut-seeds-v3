#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long INF = 1e18;
const int M = 1e6 + 6;
int main() {
  int t;
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  int ans1 = a;
  int ans = 0;
  int ans2 = min(b, c);
  if (e > f) {
    int ok = min(a, d);
    ans = ok * e + min((d - ok), ans2) * f;
  } else {
    int ok = min(ans2, d);
    ans = ok * f + min((d - ok), a) * e;
  }
  cout << ans << endl;
  return 0;
}
