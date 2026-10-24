#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long int;
using dd = double;
using ldd = long double;
using si = short int;
using ui = unsigned int;
vector<bool> was(10e7 + 1);
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ui n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  ui ans = 0;
  int i = 2;
  while (i <= n) {
    ans += (a * 8 + b * 4 + c * 2 + d) * (n / i);
    i *= 2;
  }
  i = 3;
  while (i <= n) {
    ans += (a * 27 + b * 9 + c * 3 + d) * (n / i);
    i *= 3;
  }
  int x = 2;
  for (int i = 5; i <= n; i += x, x = 6 - x) {
    if (was[i / 3]) continue;
    int cnt = 0;
    int z = i;
    while (z <= n) {
      cnt += n / z;
      if (n / i < z) break;
      z *= i;
    }
    z = x;
    ans += cnt * (a * i * i * i + b * i * i + c * i + d);
    if (n / i < i) continue;
    for (int ii = i * i; ii <= n; ii += i * z, z = 6 - z) {
      was[(ii) / 3] = 1;
    }
  }
  cout << ans;
  return 0;
}
