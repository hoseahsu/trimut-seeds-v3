#include <bits/stdc++.h>
using namespace std;
map<long long, bool> m;
int n, l;
long long x, y;
int s = -1;
int main() {
  ios::sync_with_stdio(false);
  bool f1 = false, f2 = false;
  cin >> n >> l >> x >> y;
  for (int i = 1; i <= n; i++) {
    long long t;
    cin >> t;
    m[t] = true;
    if (t - x >= 0)
      if (m[t - x]) f1 = true;
    if (t - y >= 0)
      if (m[t - y]) f2 = true;
    if (t >= y && t - y + x >= 0 && m[t - y + x]) {
      s = t - y;
    }
    if (t < y && t - y + x >= 0 && m[t - y + x]) {
      if (t + x <= l) s = t + x;
    }
    if (t >= x + y && m[t - x - y]) s = t - x;
    if (m[x]) f1 = true;
    if (m[y]) f2 = true;
  }
  int res = (!f1) + (!f2);
  if (res == 2) {
    if (s != -1) {
      cout << 1 << endl;
      cout << s << " ";
      return 0;
    }
  }
  cout << res << endl;
  if (!f1) cout << x << " ";
  if (!f2) cout << y << " ";
  return 0;
}
