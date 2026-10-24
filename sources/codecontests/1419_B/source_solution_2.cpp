#include <bits/stdc++.h>
using namespace std;
unsigned long long t, x, sum, d = 1, c = 1;
int main() {
  ios::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    sum = 0, d = 1, c = 1;
    cin >> x;
    while (x >= c) {
      sum++;
      x -= c;
      d = d * 2 + 1;
      c = (d + 1) * d / 2;
    }
    cout << sum << "\n";
  }
  return 0;
}
