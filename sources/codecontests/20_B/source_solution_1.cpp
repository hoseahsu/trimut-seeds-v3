#include <bits/stdc++.h>
using namespace std;
int main() {
  double A, B, C;
  cin >> A >> B >> C;
  if (A == 0 && B == 0 && C == 0) {
    cout << "-1";
    return 0;
  }
  if (A == 0 && B == 0 && C != 0) {
    cout << "0";
    return 0;
  }
  if (A == 0) {
    double z = (-C) / B;
    printf("1\n%.10lf", z);
    return 0;
  } else {
    double der = (B * B - 4 * A * C);
    if (der < 0) {
      cout << 0;
      return 0;
    }
    if (der == 0) {
      printf("1\n%.10lf", (-B) / (2 * A));
    }
    if (der > 0) {
      double x1 = (-B + sqrt(der)) / (2 * A), x2 = (-B - sqrt(der)) / (2 * A);
      double q = min(x1, x2), p = max(x1, x2);
      printf("2\n%.10lf\n%.10lf", q, p);
    }
  }
  return 0;
}
