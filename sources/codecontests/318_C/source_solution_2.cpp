#include <bits/stdc++.h>
using namespace std;
long long mrest(long long x, long long y, long long m);
int main() {
  long long x, y, m;
  cin >> x >> y >> m;
  if (x >= m || y >= m) {
    cout << 0 << endl;
    return 0;
  }
  if (x <= 0 && y <= 0) {
    cout << -1 << endl;
    return 0;
  }
  long long cnt;
  if (x < 0 && abs(x) > y) {
    cnt = abs(x) / y;
    cnt = cnt + mrest(-1 * (abs(x) % y), y, m);
  } else if (y < 0 && abs(y) > x) {
    cnt = abs(y) / x;
    cnt = cnt + mrest(-1 * (abs(y) % x), x, m);
  } else
    cnt = mrest(x, y, m);
  cout << cnt << endl;
}
long long mrest(long long x, long long y, long long m) {
  long long cnt = 0;
  while (x < m && y < m) {
    if (x < y) {
      long long tmp = y;
      y = x + y;
      x = tmp;
    } else {
      long long tmp = x;
      x = x + y;
      y = tmp;
    }
    cnt++;
  }
  return cnt;
}
