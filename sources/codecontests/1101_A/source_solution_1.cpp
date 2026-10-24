#include <bits/stdc++.h>
using namespace std;
int l, r, d, n;
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  while (n--) {
    cin >> l >> r >> d;
    if (d > r || d < l) {
      cout << d << endl;
      continue;
    }
    cout << d * (r / d + 1) << endl;
  }
  return 0;
}
