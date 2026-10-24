#include <bits/stdc++.h>
using namespace std;
long long powmod(long long a, long long b, long long mod) {
  if (b == 0 || a == 1) {
    if (mod == 1)
      return 0;
    else
      return 1;
  }
  if (b % 2 == 0) {
    long long k = powmod(a, b / 2, mod);
    return (k * k) % mod;
  } else {
    long long k = powmod(a, b / 2, mod);
    return ((k * k) % mod * a) % mod;
  }
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  if (b == 0) return a;
  if (a > b)
    return gcd(a % b, b);
  else
    return gcd(b % a, a);
}
long long prime(long long p) {
  for (long long i = 2; i * i <= p; i++) {
    if (p % i == 0 && i < p) return i;
  }
  return 1;
}
long long sqr(long long i) { return i * i; }
long long check(long long n, bool c) {
  long long x = 0, y = 1;
  while (n - y + 1 >= 0) {
    if (c == true)
      x += ((n - y + 1) * (n - y + 2)) / 2;
    else
      x += (n - y + 1);
    if (x > 1000000000000000000) return x;
    y *= 10;
  }
  return x;
}
void solve(long long ppppppppp = 1) {
  long long k, c = 2;
  cin >> k;
  k--;
  char a[10000];
  while (c--) {
    long long l = 0, r = 1000000000;
    while (r > l) {
      long long mid = (l + r) / 2;
      if (mid == l) mid++;
      if (check(mid, c) > k)
        r = mid - 1;
      else
        l = mid;
    }
    {
      k -= check(l, c);
      sprintf(a, "%d", l + 1);
    }
  }
  cout << a[k] << "\n";
  return;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tututu;
  tututu = 1;
  cin >> tututu;
  for (long long qwerty = 0; qwerty < tututu; qwerty++) solve();
  return 0;
}
