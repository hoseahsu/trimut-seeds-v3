#include <bits/stdc++.h>
using namespace std;
int gcd(int xx, int yy) {
  while (yy != 0) {
    xx = xx % yy;
    swap(xx, yy);
  }
  return xx;
}
int lcm(int xx, int yy) { return (xx / gcd(xx, yy)) * yy; }
int c, v0, v1, a, l;
int main() {
  cin >> c >> v0 >> v1 >> a >> l;
  int res = 0;
  int idx = 0;
  c -= v0;
  res += 1;
  while (c > 0) {
    idx += 1;
    int tmp = min(v1, v0 + a * idx) - l;
    res += 1;
    c -= tmp;
  }
  cout << res << endl;
}
