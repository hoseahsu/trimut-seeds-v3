#include <bits/stdc++.h>
using namespace std;
int n;
int d[12][12];
int ans = 0;
int r(int c) { return (c == n * n ? -1 : (cin >> d[c / n][c % n], r(c + 1))); }
int f(int c) {
  int k = c / (n * n);
  int i = (c % (n * n)) / n;
  int j = (c % (n * n)) % n;
  return (c == n * n * n
              ? 1
              : (d[i][j] = min(d[i][j], d[i][k] + d[k][j]), f(c + 1)));
}
int g(int c) {
  return (c == n * n ? -1 : (ans = max(ans, d[c / n][c % n]), g(c + 1)));
}
int main() {
  cin >> n;
  r(0);
  f(0);
  g(0);
  cout << ans << endl;
  return 0;
}
