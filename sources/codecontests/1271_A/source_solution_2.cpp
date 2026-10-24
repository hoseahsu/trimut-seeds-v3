#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d, e, f, g;
long long s1, s2;
inline void work() {
  if (e < f) {
    g = min(d, min(b, c));
    cout << g * f + e * min(d - g, a);
  } else {
    g = min(d, a);
    cout << g * e + f * min(d - g, min(b, c));
  }
}
signed main() {
  cin >> a >> b >> c >> d >> e >> f;
  work();
  return 0;
}
