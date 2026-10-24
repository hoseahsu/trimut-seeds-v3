#include <bits/stdc++.h>
using namespace std;
long long m;
long long solve(long long x, long long y) {
  if (max(x, y) >= m) return 0;
  long long mn = min(x, y);
  long long mx = max(x, y);
  x = mn;
  y = mx;
  if (x < 0) {
    long long T = (abs(x) + y) / y;
    x += T * y;
    return T + solve(x, y);
  }
  return 1 + solve(mn + mx, mx);
}
int main() {
  long long x, y;
  cin >> x >> y >> m;
  if (max(x, y) >= m) {
    cout << 0 << endl;
    return 0;
  } else if (max(x, y) <= 0) {
    cout << -1 << endl;
    return 0;
  } else {
    cout << solve(x, y) << endl;
  }
}
