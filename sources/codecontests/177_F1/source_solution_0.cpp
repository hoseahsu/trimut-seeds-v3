#include <bits/stdc++.h>
const int maxi = 2000000000;
const int maxq = 1000000000;
const double eps = 1e-10;
const double pi = 3.1415926535897932;
const double inf = 1e+18;
const int mo = 1000000007;
using namespace std;
int stn, ms[1111][1111], n, k, t, st[1111111], x, y, z, sum;
bool f[11111];
void rec(int x, int y) {
  sum += ms[x][y];
  if (x == n) {
    stn++;
    st[stn] = sum;
  }
  if (y) f[y] = true;
  if (x < n)
    for (int i = 0; i <= n; i++)
      if (f[i] == false && (ms[x + 1][i] || i == 0)) rec(x + 1, i);
  sum -= ms[x][y];
  f[y] = false;
}
int main() {
  cin >> n >> k >> t;
  for (int i = 0; i < k; i++) {
    cin >> x >> y >> z;
    ms[x][y] = z;
  }
  for (int i = 0; i <= n; i++)
    if (ms[1][i] || i == 0) rec(1, i);
  sort(st + 1, st + stn + 1);
  cout << st[t] << endl;
  return 0;
}
