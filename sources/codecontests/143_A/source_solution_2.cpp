#include <bits/stdc++.h>
using namespace std;
int main() {
  int r1, r2, c1, c2, d1, d2, x, y, z, w;
  cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
  for (x = 1; x < 10; ++x) {
    y = r1 - x;
    z = c1 - x;
    w = d1 - x;
    if (x != y && x != z && x != w && y != z && y != w && z != w && y < 10 &&
        y > 0 && z > 0 && z < 10 && w > 0 && w < 10 && z + w == r2 &&
        z + y == d2 && y + w == c2) {
      cout << x << " " << y << "\n" << z << " " << w;
      return 0;
    }
  }
  cout << -1;
  return 0;
}
