#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y);
bool isPrime(long long n);
long long modInv(long long a, long long b);
long long gcdExtended(long long a, long long b, long long *x, long long *y);
long long mpower(long long a, long long b, long long p);
const long long inf = (long long)1e17;
const long long N = (long long)3e5 + 5;
long long n, m;
string s, t;
long long dp[5001][5001];
long long rec(long long i, long long j) {
  if (i == n || j == m) {
    return 0;
  }
  if (dp[i][j] != -1) return dp[i][j];
  long long ans = rec(i, j + 1);
  if (s[i] == t[j]) {
    ans += 1 + rec(i + 1, j + 1);
    ans %= 1000000007;
  }
  dp[i][j] = ans;
  return ans;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  cin >> s >> t;
  n = s.length();
  m = t.length();
  memset(dp, -1, sizeof(dp));
  ;
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    ans += rec(i, 0);
    ans %= 1000000007;
  }
  cout << ans << "\n";
  return 0;
}
long long modInv(long long a, long long m) {
  long long x, y;
  long long g = gcdExtended(a, m, &x, &y);
  long long res = (x % m + m) % m;
  return res;
}
long long gcdExtended(long long a, long long b, long long *x, long long *y) {
  if (a == 0) {
    *x = 0, *y = 1;
    return b;
  }
  long long x1, y1;
  long long gcd = gcdExtended(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}
long long mpower(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long power(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = res * x;
    y = y >> 1;
    x = x * x;
  }
  return res;
}
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  long long p = sqrt(n);
  for (long long i = 5; i <= p; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
