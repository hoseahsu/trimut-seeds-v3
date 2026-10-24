#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    double a, b;
    cin >> a >> b;
    b *= 4;
    if (b == 0) {
      printf("1\n");
      continue;
    }
    if (a == 0) {
      printf("0.5\n");
      continue;
    }
    double sum = a * 2 * b;
    double s = 0;
    if (a > b) s = (a - b) * 2 * b;
    s += ((min(a, b) + b) + b) * min(a, b) / 2;
    printf("%lf\n", s / sum);
  }
  return 0;
}
