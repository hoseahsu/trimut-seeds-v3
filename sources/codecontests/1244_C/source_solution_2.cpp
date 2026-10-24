#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int i, t, q, n, p, w, d, x, y, z, a, b, c;
  cin >> n >> p >> w >> d;
  a = p / w;
  x = a;
  y = (p - (a * w)) / d;
  if ((a * w + y * d) == p) {
    z = n - a - y;
    if (x >= 0 && y >= 0 && z >= 0)
      cout << x << " " << y << " " << z;
    else
      cout << "-1";
  } else {
    for (i = 0; i < 10e6 + 1; i++) {
      if ((p - (d * i)) % w == 0) {
        x = (p - (d * i)) / w;
        y = i;
        z = n - x - y;
        break;
      }
    }
    if (i == 10e6 + 1) {
      cout << "-1";
    } else {
      if (x >= 0 && y >= 0 && z >= 0)
        cout << x << " " << y << " " << z;
      else
        cout << "-1";
    }
  }
  return 0;
}
