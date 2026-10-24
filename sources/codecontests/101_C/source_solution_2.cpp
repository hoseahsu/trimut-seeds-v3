#include <bits/stdc++.h>
using namespace std;
bool f(long long x, long long y, long long xc, long long yc) {
  if (!x && !y) return true;
  if (!xc && !yc) return false;
  if (!xc)
    if (x % yc || y % yc)
      return false;
    else
      return true;
  else if (!yc)
    if (x % xc || y % xc)
      return false;
    else
      return true;
  else {
    if ((y * yc + x * xc) % (yc * yc + xc * xc)) return false;
    long long a = (y * yc + x * xc) / (yc * yc + xc * xc);
    if ((x - a * xc) % yc)
      return false;
    else
      return true;
  }
}
int main() {
  long long xa, ya, xb, yb, xc, yc;
  cin >> xa >> ya >> xb >> yb >> xc >> yc;
  if (f(xb - xa, yb - ya, xc, yc) || f(xb + xa, yb + ya, xc, yc) ||
      f(xb - ya, yb + xa, xc, yc) || f(xb + ya, yb - xa, xc, yc))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
