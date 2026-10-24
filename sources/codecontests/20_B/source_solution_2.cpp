#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a == 0) {
    if (b == 0 && c != 0) cout << 0 << endl;
    if (b == 0 && c == 0) cout << -1 << endl;
    if (b != 0 && c == 0) cout << 1 << endl << "0,0000000000" << endl;
    if (b != 0 && c != 0) {
      cout << 1 << endl;
      double x = (double)-c / b;
      printf("%3.10lf\n", x);
    }
  } else {
    double x, y;
    if (b * b - 4 * a * c < 0) cout << 0 << endl;
    if (b * b == 4 * a * c) {
      cout << 1 << endl;
      x = (double)-b / (2 * a);
      printf("%3.10lf\n", x);
    }
    if (b * b - 4 * a * c > 0) {
      cout << 2 << endl;
      long double disc = sqrt(pow(b, 2) - (4 * a * c));
      x = (double)(-b + disc) / (2 * a);
      y = (double)(-b - disc) / (2 * a);
      if (x < y) {
        printf("%3.10lf\n", x);
        printf("%3.10lf \n", y);
      }
      if (y < x) {
        printf("%3.10lf\n", y);
        printf("%3.10lf\n", x);
      }
    }
  }
  return 0;
}
