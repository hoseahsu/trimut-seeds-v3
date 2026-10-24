#include <bits/stdc++.h>
const long long M = 998244353;
using namespace std;
int mod(string t, int N) {
  int r = 0;
  for (int i = 0; i < t.length(); i++) {
    r = r * 10 + (t[i] - '0');
    r %= N;
  }
  return r;
}
long long modularExponentiation(long long x, long long n, long long M) {
  if (n == 0)
    return 1;
  else if (n % 2 == 0)
    return modularExponentiation((x * x) % M, n / 2, M);
  return (x * modularExponentiation((x * x) % M, (n - 1) / 2, M)) % M;
}
long long binaryExponentiation(long long x, long long n) {
  if (n == 0)
    return 1;
  else if (n % 2 == 0)
    return binaryExponentiation(x * x, n / 2);
  else
    return x * binaryExponentiation(x * x, (n - 1) / 2);
}
long long GCD(long long A, long long B) {
  if (B == 0)
    return A;
  else
    return GCD(B, A % B);
}
long long extended_GCD(long long a, long long b, long long &x, long long &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  long long x1, y1;
  long long gcd = extended_GCD(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return gcd;
}
long long modinv(long long a, long long mod) {
  long long x, y;
  extended_GCD(a, mod, x, y);
  if (x < 0) x += mod;
  return x;
}
long long modPrimeInverse(long long A, long long M) {
  return modularExponentiation(A, M - 2, M);
}
long long power(long long x, int y, int p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long modInverse(long long n, int p) { return power(n, p - 2, p); }
long long solve(long long n, int r, int p) {
  if (n < r) return 0;
  if (r == 0) return 1;
  long long fac[n + 1];
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % p;
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  long long a[2 * n];
  for (int i = 0; i < 2 * n; i++) cin >> a[i];
  sort(a, a + 2 * n);
  long long sum1 = 0, sum2 = 0;
  for (int i = 0; i < n; i++) sum1 += a[i];
  for (int i = n; i < 2 * n; i++) sum2 += a[i];
  long long val = sum2 - sum1;
  long long num = solve(2 * n, n, M);
  cout << ((num % M) * (val % M)) % M << "\n";
  return 0;
}
