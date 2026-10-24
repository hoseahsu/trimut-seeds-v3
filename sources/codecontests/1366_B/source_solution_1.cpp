#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, x, m, a, b;
  cin >> t;
  while (t--) {
    cin >> n >> x >> m;
    int r = x, l = x;
    for (int I = 1; I <= m; I++) {
      cin >> a >> b;
      if (l < a || b < r)
        l = l;
      else {
        r = min(a, r);
        l = max(b, l);
      }
    }
    cout << l - r + 1 << endl;
  }
}
