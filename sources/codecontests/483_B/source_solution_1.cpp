#include <bits/stdc++.h>
using namespace std;
int c1, c2, x, y;
long long le, ri, mi;
long long nx, ny, nxy;
long long n1, n2, n_all;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> c1 >> c2 >> x >> y;
  le = 1ll;
  ri = (long long)(1e10);
  while (ri - le > 1ll) {
    mi = (ri + le) / 2;
    nx = mi / x;
    ny = mi / y;
    nxy = nx / y;
    n1 = ny - nxy;
    n2 = nx - nxy;
    n_all = mi - nx - ny + nxy;
    if (max(0ll, c1 - n1) + max(0ll, c2 - n2) <= n_all)
      ri = mi;
    else
      le = mi;
  }
  cout << ri << endl;
  return 0;
}
