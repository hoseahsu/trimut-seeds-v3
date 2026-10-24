#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, r;
  cin >> n >> r;
  long double i = (4 * atan(1)) / n;
  cout << fixed << setprecision(7) << (r * sin(i) / (1 - sin(i))) << endl;
  return 0;
}
