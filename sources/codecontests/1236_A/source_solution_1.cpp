#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const int N = 1e6 + 5, mod = 1e9 + 9;
int main() {
  int t;
  cin >> t;
  int a, b, c;
  while (t--) {
    cin >> a >> b >> c;
    int ans = 0;
    int x;
    x = min(c / 2, b);
    ans += x * 3;
    b -= x;
    ans += min(a, b / 2) * 3;
    cout << ans << endl;
  }
}
