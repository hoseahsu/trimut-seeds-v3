#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, i, sx, sy, c1 = 0, c2 = 0, c3 = 0, c4 = 0, cnt = 0, x, y;
  cin >> n >> sx >> sy;
  for (i = 0; i < n; i++) {
    cin >> x >> y;
    x -= sx;
    y -= sy;
    if (x >= 1) c1++;
    if (y >= 1) c2++;
    if (x <= -1) c3++;
    if (y <= -1) c4++;
  }
  cnt = max(c1, max(c2, max(c3, c4)));
  if (cnt == c1) {
    cout << cnt << endl;
    cout << sx + 1 << " " << sy << endl;
  } else if (cnt == c2) {
    cout << cnt << endl;
    cout << sx << " " << sy + 1 << endl;
  } else if (cnt == c3) {
    cout << cnt << endl;
    cout << sx - 1 << " " << sy << endl;
  } else {
    cout << cnt << endl;
    cout << sx << " " << sy - 1 << endl;
  }
}
