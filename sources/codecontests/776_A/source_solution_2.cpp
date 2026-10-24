#include <bits/stdc++.h>
using namespace std;
const int N = 1050, mod = 1e9 + 7;
int main() {
  string a, b, x, y;
  cin >> a >> b;
  cout << a << " " << b << endl;
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> x >> y;
    if (x == a) {
      a = y;
    } else if (x == b) {
      b = y;
    } else if (y == a) {
      a = x;
    } else
      b = x;
    cout << a << " " << b << endl;
  }
  return 0;
}
