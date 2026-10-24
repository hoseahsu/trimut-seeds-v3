#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int i, j, n, m, k, z = 0;
  string s;
  cin >> n;
  int a[n + 7];
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 1; i <= n; i++) {
    for (k = 3; k <= 360; k++) {
      for (j = 1; j <= k - 2; j++)
        if ((180 * j) % k == 0 && 180 * j / k == a[i]) {
          cout << k << endl;
          goto endloop;
        }
    }
  endloop:;
  }
  return 0;
}
