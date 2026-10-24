#include <bits/stdc++.h>
using namespace std;
int main() {
  double a, b, c, d;
  cin >> a >> b >> c >> d;
  double res = 0.0, per = 1.0;
  for (int i = 1; i < (int)1e6; i++) {
    res += (a / b * per);
    per *= (1.0 - a / b) * (1 - c / d);
  }
  cout << fixed << setprecision(10) << res << endl;
}
