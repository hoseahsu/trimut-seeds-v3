#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, e, f, ans = INT_MAX;
string s;
int main() {
  cin >> s;
  for (int i = 0; i <= 9; i++)
    for (int j = 0; j <= 9; j++)
      for (int k = 0; k <= 9; k++)
        for (int p = 0; p <= 9; p++)
          for (int y = 0; y <= 9; y++)
            for (int h = 0; h <= 9; h++)
              if (i + j + k == p + y + h)
                ans = min(ans, 6 - (i == (s[0] - 48)) - (j == (s[1] - 48)) -
                                   (k == (s[2] - 48)) - (p == (s[3] - 48)) -
                                   (y == (s[4] - 48)) - (h == (s[5] - 48)));
  cout << ans;
  return 0;
}
