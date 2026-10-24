#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
const int maxm = 55;
const int inf = 2147483647;
const long long p = 998244353;
const double eps = 1e-9;
const long long INF = 9223372036854775807ll;
long long fac[maxn], rev[maxn];
long long qpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1ll) ans = ans * a % p;
    a = a * a % p;
    b >>= 1ll;
  }
  return ans;
}
long long C(long long a, long long b) {
  return fac[a] * rev[b] % p * rev[a - b] % p;
}
int main() {
  long long n, k;
  scanf("%lld%lld", &n, &k);
  if (k >= n) {
    printf("0\n");
    return 0;
  }
  fac[0] = rev[0] = 1;
  for (register int i = (1); i < (n + 1); ++i) {
    fac[i] = fac[i - 1] * i % p;
    rev[i] = rev[i - 1] * qpow(i, p - 2) % p;
  }
  long long t = n - k;
  long long ans = 0, fg = 1;
  for (register int i = (0); i < (t + 1); ++i) {
    ans = (ans + fg * C(t, i) * qpow(t - i, n) % p) % p;
    fg *= -1;
  }
  ans = ans * C(n, t) % p;
  if (k) ans = ans * 2 % p;
  ans = (ans + p) % p;
  printf("%lld\n", ans);
}
