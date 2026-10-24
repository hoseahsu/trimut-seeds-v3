#include <bits/stdc++.h>
#pragma GCC optimize(3)
template <typename _Tp>
inline void read(_Tp& x) {
  char ch;
  bool flag = 0;
  x = 0;
  while (ch = getchar(), !isdigit(ch))
    if (ch == '-') flag = 1;
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  if (flag) x = -x;
}
using namespace std;
long long n, m, a[150010], b[150010];
long long slove(long long mid) {
  long long sum = 0;
  for (long long i = 1; i <= n; i++) {
    if (b[i] - a[i] * mid < 0) {
      sum += b[i] - a[i] * mid;
    }
    if (-1 * sum > m) {
      return 0;
    }
  }
  if (sum >= 0) {
    return 1;
  }
  if (sum < 0 && -1 * sum <= m) {
    return 1;
  }
  return 0;
}
int main() {
  long long ans = 0, lo = 0, hi = 2000000000, mid;
  read(n);
  read(m);
  for (long long i = 1; i <= n; i++) read(a[i]);
  for (long long i = 1; i <= n; i++) read(b[i]);
  while (hi - lo >= 0) {
    mid = (lo + hi) / 2;
    if (slove(mid) == 1) {
      lo = mid + 1, ans = mid;
    } else {
      hi = mid - 1;
    }
  }
  cout << ans;
  return 0;
}
