#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;
const long long N = 1e5 + 5;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while ((ch > '9' || ch < '0')) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') x = x * 10 + (ch ^ 48), ch = getchar();
  return x * f;
}
inline long long ksm(long long x, long long y = mod - 2, long long z = mod) {
  long long ret = 1;
  while (y) {
    if (y & 1LL) ret = ret * x % mod;
    x = x * x % mod;
    y >>= 1LL;
  }
  return ret;
}
long long inv[N], sum[N];
void init(long long n) {
  inv[1] = 1;
  for (register signed i = 2; i <= n; i++)
    inv[i] = inv[mod % i] * (mod - mod / i) % mod;
  for (register signed i = 1; i <= n; i++) sum[i] = (sum[i - 1] + inv[i]) % mod;
}
long long k, n, ans;
map<long long, long long> S;
void MS(long long l, long long r, long long h) {
  if (h == k || l == r) {
    S[r - l + 1]++;
    return;
  }
  long long mid = (l + r) >> 1;
  MS(l, mid, h + 1);
  MS(mid + 1, r, h + 1);
}
long long calc(long long x, long long y) {
  long long res = x * y % mod;
  for (register signed i = 1; i <= x; ++i)
    res -= (sum[i + y] - sum[i]) * 2, res %= mod;
  return (res % mod + mod) % mod;
}
signed main() {
  n = read();
  k = read();
  mod = read();
  init(n);
  MS(1, n, 1);
  for (map<long long, long long>::iterator X = S.begin(); X != S.end(); X++) {
    long long x = X->first, y = X->second;
    ans += x * (x - 1) % mod * inv[2] % mod * y % mod;
    ans %= mod;
    ans += y * (y - 1) % mod * inv[2] % mod * calc(x, x) % mod;
    ans %= mod;
  }
  for (map<long long, long long>::iterator X = S.begin(); X != S.end(); X++)
    for (map<long long, long long>::iterator Y = S.begin(); Y != S.end(); Y++) {
      long long x = X->first, y = Y->first, a = X->second, b = Y->second;
      if (x >= y) continue;
      ans += calc(x, y) * a % mod * b % mod;
      ans %= mod;
    }
  ans = ans * inv[2] % mod;
  ans += mod;
  ans %= mod;
  cout << ans << '\n';
}
