#include <bits/stdc++.h>
using namespace std;
const int mx = 1e6 + 5;
const int MOD = 1e9 + 7;
long long bigmod(long long x, long long n) {
  long long res = 1;
  while (n > 0) {
    if (n % 2 == 1) res = (res * x) % MOD;
    x = (x * x) % MOD;
    n /= 2;
  }
  return res;
}
long long fact[mx], inv[mx];
void prep(int k) {
  fact[0] = 1;
  for (int i = 1; i <= k; i++) fact[i] = (fact[i - 1] * i) % MOD;
  for (int i = 1; i < 2005 && i <= k; i++) {
    inv[i] = bigmod(fact[i], MOD - 2);
    int x = k - i;
    inv[x] = bigmod(fact[x], MOD - 2);
  }
}
long long nCr(int n, int r) {
  if (r > n) return 0;
  if (r == 0 || r == n) return 1;
  r = min(r, n - r);
  long long res = fact[n];
  res = (res * inv[r]) % MOD;
  return (res * inv[n - r]) % MOD;
}
long long DP[1005][1005];
long long solve(int n, int x) {
  if (x == 1) return 1;
  if (n == 1) return 0;
  if (DP[n][x] != -1) return DP[n][x];
  long long res = (solve(n - 1, x) * x) % MOD + (solve(n - 1, x - 1) * x) % MOD;
  return DP[n][x] = res % MOD;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int m, n, k;
  cin >> n >> m >> k;
  long long ans;
  if (m == 1)
    ans = bigmod(k, n);
  else {
    memset(DP, -1, sizeof(DP));
    prep(k);
    ans = 0;
    for (int i = 1; i <= n && i <= k; i++) {
      for (int j = 0; j <= i; j++) {
        long long cnt = 1;
        cnt = (cnt * nCr(k, 2 * i - j)) % MOD;
        cnt = (cnt * nCr(2 * i - j, i - j)) % MOD;
        cnt = (cnt * nCr(i, i - j)) % MOD;
        cnt = (cnt * solve(n, i)) % MOD;
        cnt = (cnt * solve(n, i)) % MOD;
        cnt = (cnt * bigmod(j, n * m - 2 * n)) % MOD;
        ans = (ans + cnt) % MOD;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
