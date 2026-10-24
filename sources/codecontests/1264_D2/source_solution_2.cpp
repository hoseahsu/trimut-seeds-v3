#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long fac[2000500];
long long quickpow(long long a, long long b) {
  if (b == 0)
    return 1LL;
  else if (b == 1)
    return a;
  else if (b % 2 == 0)
    return quickpow(a * a % mod, b / 2);
  else
    return (quickpow(a * a % mod, b / 2) * a) % mod;
}
long long Cnm(long long n, long long m) {
  if (n < 0 || m < 0 || n < m) return 0LL;
  if (n != 0 && m == 0) return 1LL;
  if (n == m) return 1LL;
  long long sex = (fac[n - m] * fac[m]) % mod;
  long long sex1 = quickpow(sex, mod - 2);
  return (sex1 * fac[n]) % mod;
}
long long l, r, x, ans;
char s[1000500];
long long sum1[2000500];
long long sum2[2000500];
int n;
int main() {
  fac[1] = 1;
  for (long long i = 2; i <= 2000000; i++) fac[i] = (fac[i - 1] * i) % mod;
  scanf("%s", s);
  n = strlen(s);
  for (int i = 0; i < n; i++) {
    if (s[i] == '?')
      x++;
    else if (s[i] == '(')
      l++;
  }
  sum1[0] = sum2[0] = 1;
  long long t = x;
  for (long long i = 1; i <= 2000000; i++) {
    sum1[i] = (sum1[i - 1] + Cnm(x, i));
  }
  for (long long i = 1; i <= 2000000; i++) {
    sum2[i] = (sum2[i - 1] + Cnm(x - 1, i));
  }
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == '?') {
      t--;
      if (l - r + t - 1 >= 0) ans = (ans + sum2[l - r + t - 1]) % mod;
    } else if (s[i] == '(')
      l--;
    else if (s[i] == ')') {
      if (l - r + t - 1 >= 0) ans = (ans + sum1[l - r + t - 1]) % mod;
      r++;
    }
  }
  printf("%lld", ans);
  return 0;
}
