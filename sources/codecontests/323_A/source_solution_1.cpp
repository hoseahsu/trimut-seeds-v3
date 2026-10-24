#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e18;
const long double PI = 4 * atan((long double)1);
const int INFTY = 1e7;
int main() {
  long long n;
  scanf("%I64d", &n);
  if (n & 1) {
    cout << -1 << endl;
    return 0;
  }
  string row1, row2;
  int groups = n / 2;
  string r1 = "bb", r2 = "ww";
  for (int i = 0; i < groups; ++i) {
    row1 += r1, row2 += r2;
    swap(r1, r2);
  }
  string ans;
  for (int z = 0; z < n; ++z) {
    for (int row = 0; row < n / 2; row++) {
      if ((row + z) & 1) {
        cout << row2 << endl;
        cout << row2 << endl;
      } else {
        cout << row1 << endl;
        cout << row1 << endl;
      }
    }
    if (z != n - 1) cout << endl;
  }
}
