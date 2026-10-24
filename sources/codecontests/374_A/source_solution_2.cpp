#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, a, b, ans;
int dist(int xx, int yy) {
  if (xx % a != x % a || yy % b != y % b) return 1000000000;
  int res = abs(xx - x) / a + abs(yy - y) / b;
  return res % 2 ? 1000000000 : max(abs(xx - x) / a, abs(yy - y) / b);
}
int main() {
  cin >> n >> m >> x >> y >> a >> b;
  if (x == 1 && y == 1 || x == 1 && y == m || x == n && y == 1 ||
      x == n && y == m) {
    cout << "0\n";
    return 0;
  }
  if (x + a > n && x - a < 1 || y + b > m && y - b < 1) {
    cout << "Poor Inna and pony!\n";
    return 0;
  }
  int ans = min(min(dist(1, 1), dist(1, m)), min(dist(n, 1), dist(n, m)));
  if (ans == 1000000000)
    cout << "Poor Inna and pony!\n";
  else
    cout << ans << "\n";
  return 0;
}
