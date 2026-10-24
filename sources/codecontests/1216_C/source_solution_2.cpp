#include <bits/stdc++.h>
using namespace std;
map<long long, long long> M;
vector<long long> V, VV[100002];
long long a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w,
    x, y, z, x1, x2, x3, x4, x5, x6, y11, y2, y3, y4, y5, y6, s1, s2;
long long A[5][5];
string st;
long long check(long long X1, long long Y1, long long X2, long long Y2,
                long long X3, long long Y3, long long r, long long p) {
  if (X3 >= X1 && X3 <= X2 && Y3 >= Y1 && Y3 <= Y2) {
    A[r][p] = 1;
    return 1;
  } else {
    return 0;
  }
}
int main() {
  cin >> x1;
  cin >> y11;
  cin >> x2;
  cin >> y2;
  cin >> x3 >> y3 >> x4 >> y4;
  cin >> x5 >> y5 >> x6 >> y6;
  s1 = s1 + check(x3, y3, x4, y4, x1, y11, 1, 1);
  s1 = s1 + check(x3, y3, x4, y4, x1, y2, 1, 2);
  s1 = s1 + check(x3, y3, x4, y4, x2, y11, 1, 3);
  s1 = s1 + check(x3, y3, x4, y4, x2, y2, 1, 4);
  s2 = s2 + check(x5, y5, x6, y6, x1, y11, 2, 1);
  s2 = s2 + check(x5, y5, x6, y6, x1, y2, 2, 2);
  s2 = s2 + check(x5, y5, x6, y6, x2, y11, 2, 3);
  s2 = s2 + check(x5, y5, x6, y6, x2, y2, 2, 4);
  if (s1 == 4 || s2 == 4)
    cout << "NO";
  else if (s1 == 2 && s2 == 2 && (A[1][1] | A[2][1]) && (A[1][2] | A[2][2]) &&
           (A[1][3] | A[2][3]) && (A[1][4] | A[2][4])) {
    if (A[1][1] ^ A[1][2]) {
      if (A[1][1]) {
        if (y4 >= y5)
          cout << "NO";
        else
          cout << "YES";
      } else {
        if (y6 >= y3)
          cout << "NO";
        else
          cout << "YES";
      }
    } else {
      if (A[1][1]) {
        if (x4 >= x5)
          cout << "NO";
        else
          cout << "YES";
      } else {
        if (x6 >= x3)
          cout << "NO";
        else
          cout << "YES";
      }
    }
  } else
    cout << "YES";
  return 0;
}
