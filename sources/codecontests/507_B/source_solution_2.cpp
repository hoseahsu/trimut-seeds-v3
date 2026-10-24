#include <bits/stdc++.h>
using namespace std;
void boost() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
int main() {
  boost();
  long long r, x, y, k, l, ans = 0;
  cin >> r >> x >> y >> k >> l;
  double d = sqrt((x - k) * (x - k) + (y - l) * (y - l));
  if (d == 0) {
    cout << 0;
    return 0;
  }
  if (d <= 2 * r) {
    cout << 1;
    return 0;
  }
  long long a = (long long)((d - 2 * r) / (2 * r));
  d = d - a * 2 * r;
  d = d - 2 * r;
  if (d <= 0) {
    cout << a + 1;
    return 0;
  }
  cout << a + 2;
  return 0;
}
