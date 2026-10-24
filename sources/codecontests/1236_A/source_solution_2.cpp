#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  while (q--) {
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    if (c >= 2) {
      ans += 2 * min(b, (c / 2)) + min(b, c / 2);
      b = b - c / 2;
    }
    if (b >= 2) ans += 2 * min(a, (b / 2)) + min(a, b / 2);
    cout << ans << endl;
  }
  return 0;
}
