#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, L, v, l, r, a, b;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> L >> v >> l >> r;
    a = L / v;
    if (l % v == 0) {
      b = r / v - l / v + 1;
    } else {
      b = r / v - l / v;
    }
    cout << a - b << endl;
  }
}
