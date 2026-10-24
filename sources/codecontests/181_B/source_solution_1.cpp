#include <bits/stdc++.h>
using namespace std;
int point[2009][2009];
int main() {
  int t, i, x, y, a, j, b, cnt = 0, ar[3009][5];
  cin >> t;
  for (i = 0; i < t; ++i) {
    cin >> a >> b;
    ar[i][0] = a;
    ar[i][1] = b;
    a += 1000;
    b += 1000;
    point[a][b] = 1;
  }
  for (i = 0; i < t; ++i) {
    for (j = i + 1; j < t; ++j) {
      x = ar[i][0] + ar[j][0];
      y = ar[i][1] + ar[j][1];
      if (x % 2 == 0 && y % 2 == 0) {
        x /= 2;
        y /= 2;
        x += 1000;
        y += 1000;
        if (point[x][y] == 1) {
          cnt++;
        }
      }
    }
  }
  cout << cnt << endl;
  return 0;
}
