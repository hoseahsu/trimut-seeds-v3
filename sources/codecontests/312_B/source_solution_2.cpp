#include <bits/stdc++.h>
using namespace std;
int main() {
  double a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << fixed << setprecision(10)
       << a / b / (1 - ((b - a) / b) * ((d - c) / d)) << endl;
  return 0;
}
