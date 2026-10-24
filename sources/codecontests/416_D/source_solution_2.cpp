#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  char ch = getchar();
  long long x = 0, r = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') r = 0;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + ch - '0', ch = getchar();
  return r ? x : -x;
}
long long n, a[1001000], ans, l, x, y, slope;
int main() {
  n = read();
  for (int i = 1; i <= n; ++i) a[i] = read();
  l = 1;
  while (l <= n) {
    ans++;
    x = y = -1;
    for (int i = l; i <= n; ++i) {
      if (a[i] != -1) {
        if (x == -1)
          x = i;
        else {
          y = i;
          break;
        }
      }
    }
    if (y == -1) break;
    slope = (a[y] - a[x]) / (y - x);
    if (slope * (y - x) != a[y] - a[x]) {
      l = y;
      continue;
    }
    a[l] = a[x] - slope * (x - l);
    if (a[l] <= 0) {
      l = y;
      continue;
    }
    for (int i = l + 1; i <= n + 1; ++i) {
      if (i == n + 1) {
        cout << ans;
        return 0;
      }
      if (a[i] == -1) {
        a[i] = a[i - 1] + slope;
        if (a[i] <= 0) {
          a[i] = -1;
          l = i;
          break;
        }
      }
      if (a[i] != a[i - 1] + slope) {
        l = i;
        break;
      }
    }
  }
  cout << ans;
  return 0;
}
