#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
const int Mod = 1000000007;
const int INF = 0x3f3f3f3f;
const long long LL_INF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);
const double ERR = 1e-10;
int x[10], y[10];
int main() {
  int t = 1;
  while (t--) {
    int a;
    int b, c;
    cin >> a;
    b = a / 1000;
    c = a % 1000;
    int x1, x2, x3;
    x[1] = b / 100;
    x[2] = (b / 10) % 10;
    x[3] = b % 10;
    y[1] = c / 100;
    y[2] = (c / 10) % 10;
    y[3] = c % 10;
    int sum1 = b / 100 + (b / 10) % 10 + b % 10;
    int sum2 = c / 100 + (c / 10) % 10 + c % 10;
    if (sum1 == sum2) {
      cout << 0 << endl;
      continue;
    }
    if (sum1 > sum2) {
      swap(sum1, sum2);
      for (int i = 1; i <= 3; i++) {
        swap(x[i], y[i]);
      }
    }
    int cnt = 0;
    while (sum1 < sum2) {
      int minx = 9;
      int maxy = 0;
      int flagx, flagy;
      for (int i = 1; i <= 3; i++) {
        if (x[i] < minx) {
          minx = x[i];
          flagx = i;
        }
      }
      for (int i = 1; i <= 3; i++) {
        if (y[i] > maxy) {
          maxy = y[i];
          flagy = i;
        }
      }
      if (9 - minx > maxy) {
        sum1 += 9 - x[flagx];
        x[flagx] = 9;
      } else {
        sum2 -= y[flagy];
        y[flagy] = 0;
      }
      cnt++;
    }
    cout << cnt << endl;
  }
  return 0;
}
