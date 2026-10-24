#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int q, n, a[505];
int main() {
  cin >> q;
  while (q--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    bool pd = 1;
    for (int i = 1; i < n; i++) {
      int xx = a[i] + 1;
      if (xx > n) xx = 1;
      if (xx != a[i + 1]) {
        pd = 0;
        break;
      }
    }
    if (pd) {
      cout << "YES" << endl;
      continue;
    }
    pd = 1;
    for (int i = 1; i < n; i++) {
      int xx = a[i] - 1;
      if (xx == 0) xx = n;
      if (xx != a[i + 1]) {
        pd = 0;
        break;
      }
    }
    if (pd)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
