#include <bits/stdc++.h>
using namespace std;
const int me = 100025;
string s[5];
int good(int x, int y) { return x > 0 && y > 0 && x < 5 && y < 5; }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 1; i <= 4; i++) {
    cin >> s[i];
    s[i] = "$" + s[i];
  }
  for (int i = 1; i <= 4; i++)
    for (int j = 1; j <= 4; j++) {
      if (s[i][j] == 'x' || s[i][j] == 'o') continue;
      s[i][j] = 'x';
      for (int k = 1; k <= 4; k++)
        for (int q = 1; q <= 4; q++) {
          if (s[k][q] != 'x') continue;
          for (int dx = -1; dx <= 1; dx++)
            for (int dy = -1; dy <= 1; dy++) {
              if (dx * dx + dy * dy == 0) continue;
              if (!good(k + dx, q + dy) || s[k + dx][q + dy] != 'x') continue;
              if (!good(k + dx + dx, q + dy + dy) ||
                  s[k + dx + dx][q + dy + dy] != 'x')
                continue;
              cout << "YES" << endl;
              return 0;
            }
        }
      s[i][j] = '.';
    }
  cout << "NO" << endl;
  return 0;
}
