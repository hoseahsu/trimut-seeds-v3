#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, d, e, f, cnt;
  cin >> a >> b >> c;
  e = min(a, min(b, c));
  d = max(a, max(b, c));
  f = a + b + c - d - e;
  if (d >= 2 * (a + b + c - d))
    cout << a + b + c - d << endl;
  else {
    d = d - e;
    f = f - e;
    cout << (d + f) / 3 + e << endl;
  }
  return 0;
}
