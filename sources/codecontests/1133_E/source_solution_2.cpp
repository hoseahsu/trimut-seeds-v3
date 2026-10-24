#include <bits/stdc++.h>
using namespace std;
void optimise() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
long long int mod = 1e9 + 7;
void normalize(long long int &a) { a = (a + mod) % mod; }
long long int modmul(long long int a, long long int b) {
  a = a % mod;
  b = b % mod;
  normalize(a);
  normalize(b);
  return (a * b) % mod;
}
long long int modadd(long long int a, long long int b) {
  a = a % mod;
  b = b % mod;
  normalize(a);
  normalize(b);
  return (a + b) % mod;
}
long long int modsub(long long int a, long long int b) {
  a = a % mod;
  b = b % mod;
  normalize(a);
  normalize(b);
  return (a - b + mod) % mod;
}
long long int me(long long int x, long long int n) {
  x %= mod;
  if (n == 0) return 1;
  long long int u = me(x, n / 2) % mod;
  u = (u * u) % mod;
  if (n % 2) u = (u * x) % mod;
  return u;
}
long long int me1(long long int x, long long int n) {
  if (n == 0) return 1;
  long long int u = me1(x, n / 2);
  u = u * u;
  if (n % 2) u = u * x;
  return u;
}
inline long long int modInv(long long int a) { return me(a, mod - 2); }
inline long long int modDiv(long long int a, long long int b) {
  return modmul(a, modInv(b));
}
long long int __gcd(long long int a, long long int b) {
  if (b == 0)
    return a;
  else
    return __gcd(b, a % b);
}
long long int inf = 1e18;
void solve() {
  long long int n, k;
  cin >> n >> k;
  long long int dp[n][k + 1];
  memset(dp, 0, sizeof(dp));
  long long int a[n];
  for (long long int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (long long int i = 0; i < n; i++) {
    long long int j = i;
    for (; j >= 0; j--) {
      if (a[i] - a[j] > 5) break;
    }
    long long int diff = (i - j);
    for (long long int j1 = 1; j1 <= k; j1++) {
      if (j >= 0) {
        dp[i][j1] = max(dp[j][j1 - 1] + diff, dp[i - 1][j1]);
      } else
        dp[i][j1] = diff;
    }
  }
  cout << dp[n - 1][k];
}
signed main() {
  optimise();
  long long int t;
  t = 1;
  cout << fixed << setprecision(10);
  while (t--) {
    solve();
    cout << "\n";
  }
}
