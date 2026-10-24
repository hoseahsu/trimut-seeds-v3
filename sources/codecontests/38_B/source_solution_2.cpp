#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, x1, x2, y1, y2;
  string str1, str2;
  char b[10][10];
  cin >> str1;
  cin >> str2;
  for (i = 1; i <= 8; i++)
    for (j = 1; j <= 8; j++) {
      b[i][j] = '.';
    }
  x1 = str1[0] - 'a' + 1;
  y1 = str1[1] - '0';
  x2 = str2[0] - 'a' + 1;
  y2 = str2[1] - '0';
  b[x1][y1] = 'r';
  b[x2][y2] = 'k';
  int ans = 0;
  for (i = 1; i <= 8; i++)
    for (j = 1; j <= 8; j++) {
      if (b[i][j] == '.') {
        if (abs(i - x1) == 2 && abs(j - y1) == 1) continue;
        if (abs(i - x1) == 1 && abs(j - y1) == 2) continue;
        if (abs(i - x2) == 2 && abs(j - y2) == 1) continue;
        if (abs(i - x2) == 1 && abs(j - y2) == 2) continue;
        if (i == x1 || j == y1) continue;
        ans++;
      }
    }
  cout << ans << endl;
  return 0;
}
