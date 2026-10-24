#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
map<int, int> s;
int main() {
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    s[x]++;
  }
  while (q--) {
    int x;
    cin >> x;
    int ans = 0;
    for (int i = 1 << 30; i >= 1; i /= 2) {
      int k = min(s[i], x / i);
      ans += k;
      x -= k * i;
    }
    if (x) {
      cout << -1 << endl;
    } else {
      cout << ans << endl;
    }
  }
  return 0;
}
