#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
long long la[maxn], lb[maxn];
long long x, mod;
long long mul(long long a, long long b) {
  long long ans = 0;
  for (; b; b >>= 1, a = (a + a) % mod)
    if (b & 1) ans = (ans + a) % mod;
  return ans;
}
long long fib(long long n) {
  if (n == 0) return 0;
  --n;
  long long a = 1, b = 1, ta = 1, tb = 0, xa, xb;
  for (; n; n >>= 1) {
    if (n & 1) {
      xa = (mul(a, ta) + mul(b, tb)) % mod;
      xb = (mul(a, tb) + mul(ta, b)) % mod;
      xb = (xb + mod - mul(b, tb)) % mod;
      ta = xa;
      tb = xb;
    }
    xa = (mul(a, a) + mul(b, b)) % mod;
    xb = mul(b, (a + a + mod - b) % mod);
    a = xa;
    b = xb;
  }
  return ta;
}
int main() {
  int i, j, k, t1 = 0, t2 = 0;
  long long len = 60;
  mod = 10;
  long long *a = la, *b = lb;
  scanf("%I64d", &x);
  for (i = 0; i < len; ++i)
    if (fib(i) == x % mod) a[t1++] = i;
  for (k = 1; k <= 12; ++k) {
    swap(a, b);
    swap(t1, t2);
    t1 = 0;
    mod *= 10;
    for (j = 0; j < 10; ++j)
      for (i = 0; i < t2; ++i)
        if (fib(b[i] + j * len) == x % mod) a[t1++] = b[i] + j * len;
    len *= 10;
  }
  printf("%I64d\n", t1 > 0 ? a[0] : -1);
  return 0;
}
