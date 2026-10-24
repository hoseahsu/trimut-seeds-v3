#include <bits/stdc++.h>
using namespace std;
void solve() {
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    double a, b;
    cin >> a >> b;
    double ans = 0.0;
    double lim = min(a, 4 * b);
    ans += lim * lim / 8.0 + b * lim;
    if (a > 4 * b) ans += 2 * b * (a - 4 * b);
    if (b == 0)
      ans = 1.0;
    else if (a == 0)
      ans = 0.5;
    else
      ans /= 2 * a * b;
    cout << fixed << setprecision(10) << ans << endl;
  }
}
int main() { solve(); }
