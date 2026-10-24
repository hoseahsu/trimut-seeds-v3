#include <bits/stdc++.h>
using namespace std;
const double PI = 3.14159265358979323846264338327950288419716939937510;
const double E = 2.7182818284590452353602874713526624977572470936999596;
const double eps = 0.000000001;
const int MOD = 1000000007;
inline int max(int x, int y) { return x > y ? x : y; }
inline int min(int x, int y) { return x < y ? x : y; }
inline int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
template <typename T>
inline void read(T& x) {
  char ch;
  x = 0;
  bool flag = 0;
  ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') flag = 1;
    ch = getchar();
  }
  while ((ch <= '9' && ch >= '0')) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  if (flag) x *= -1;
}
template <typename T>
inline void read(T& x, T& y) {
  read(x);
  read(y);
}
template <typename T>
inline void read(T& x, T& y, T& z) {
  read(x);
  read(y);
  read(z);
}
int main() {
  long long n;
  read(n);
  long long l, r, len;
  read(l, r);
  if (r >= l)
    len = r - l + 1;
  else
    len = r + n - l + 1;
  long long k;
  read(k);
  long long ans = -1, lx, ly, rx, ry;
  for (long long y = (0); (y) <= (2000000); (y)++) {
    if (y > n) break;
    if (k - y + n - len * 2 < 0) continue;
    rx = (k - y + n - len * 2) / (y + n);
    if (k < len) continue;
    rx = min(rx, (k - len) / (y + n));
    long long tmp = max(0ll, k - len * 2);
    if (tmp % (y + n) == 0)
      lx = tmp / (y + n);
    else
      lx = tmp / (y + n) + 1;
    if (lx <= rx) ans = max(ans, y);
  }
  if (len * 2 >= k && len <= k) ans = max(ans, min(n, k + n - len * 2));
  for (long long x = (1); (x) <= (2000000); (x)++) {
    long long tmp = k - x * n + n - len * 2;
    if (tmp < 0) continue;
    ry = tmp / (x + 1);
    if (k < len) continue;
    ry = min(ry, (k - len) / x - n);
    if (ry < 0) continue;
    tmp = max(0ll, k - len * 2 - x * n);
    if (tmp % x == 0)
      ly = tmp / x;
    else
      ly = tmp / x + 1;
    ry = min(ry, n);
    if (ly <= ry) ans = max(ans, ry);
  }
  k++;
  for (long long y = (0); (y) <= (2000000); (y)++) {
    if (y > n) break;
    if (k - y + n - len * 2 < 0) continue;
    rx = (k - y + n - len * 2) / (y + n);
    if (k <= len) continue;
    rx = min(rx, (k - (len + 1)) / (y + n));
    long long tmp = max(0ll, k - len - len);
    if (tmp % (y + n) == 0)
      lx = tmp / (y + n);
    else
      lx = tmp / (y + n) + 1;
    if (lx <= rx && y > 0) ans = max(ans, y);
  }
  if (len * 2 >= k && len <= k && min(n, k + n - len * 2) > 0)
    ans = max(ans, min(n, k + n - len * 2));
  for (long long x = (1); (x) <= (2000000); (x)++) {
    long long tmp = k - x * n + n - len * 2;
    if (tmp < 0) continue;
    ry = tmp / (x + 1);
    if (k < len + 1) continue;
    ry = min(ry, (k - (len + 1)) / x - n);
    if (ry < 0) continue;
    tmp = max(0ll, k - len * 2 - x * n);
    if (tmp % x == 0)
      ly = tmp / x;
    else
      ly = tmp / x + 1;
    ry = min(ry, n);
    if (ly <= ry && ry > 0) ans = max(ans, ry);
  }
  cout << ans << endl;
  return 0;
}
