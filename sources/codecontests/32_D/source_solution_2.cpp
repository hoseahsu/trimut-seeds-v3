#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  char map[301][301];
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> map[i][j];
    }
  if (k >= 3610000) {
    cout << "-1" << endl;
    return 0;
  }
  int c = 0, r = 1;
  bool flag = false;
  int xcen, ycen, xup, yup, xdown, ydown, xleft, yleft, xright, yright;
  while (c < k) {
    for (int i = r + 1; i <= n - r && !flag; i++)
      for (int j = r + 1; j <= m - r && !flag; j++) {
        if (map[i][j] == '*' && map[i - r][j] == '*' && map[i + r][j] == '*' &&
            map[i][j - r] == '*' && map[i][j + r] == '*') {
          ++c;
          if (c == k) {
            xcen = i, ycen = j;
            xup = i - r, yup = j;
            xdown = i + r, ydown = j;
            xleft = i, yleft = j - r;
            xright = i, yright = j + r;
            flag = true;
            break;
          }
        }
      }
    r++;
    if (r > max(n, m) / 2 + 2) break;
    if (flag) break;
  }
  if (!flag) {
    cout << "-1" << endl;
    return 0;
  }
  cout << xcen << " " << ycen << endl;
  cout << xup << " " << yup << endl;
  cout << xdown << " " << ydown << endl;
  cout << xleft << " " << yleft << endl;
  cout << xright << " " << yright << endl;
  return 0;
}
