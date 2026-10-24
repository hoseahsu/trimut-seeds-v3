#include <bits/stdc++.h>
using namespace std;
void solve() {
  int x, y, n;
  cin >> x >> y >> n;
  int z = n / x;
  if (z * x + y <= n) {
    cout << z * x + y << '\n';
  } else {
    cout << (z - 1) * x + y << '\n';
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
