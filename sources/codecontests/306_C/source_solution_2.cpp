#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 9;
const int N = 4040;
int n, w, b;
long long fac[N], f[N][N], inv[N];
long long qpow(long long x, long long p) {
  long long res = 1ll;
  while (p) {
    if (p & 1) {
      res = (res * x) % mod;
    }
    x = (x * x) % mod;
    p >>= 1;
  }
  return res;
}
long long INV(long long k) { return qpow(k, mod - 2); }
long long calc(int x, int y) {
  return fac[x] * inv[y] % mod * inv[x - y] % mod;
}
void init() {
  fac[0] = 1ll;
  inv[0] = 1ll;
  for (int i = 1; i < N; i++) {
    fac[i] = (fac[i - 1] * 1ll * i) % mod;
    inv[i] = INV(fac[i]);
  }
}
int main() {
  scanf("%d%d%d", &n, &w, &b);
  init();
  for (int i = 1; i <= n; i++) {
    for (int j = i; j < N; j++) {
      f[i][j] = (fac[j] * calc(j - 1, i - 1)) % mod;
    }
  }
  long long ans = 0;
  for (int i = 1; i < n - 1; i++) {
    ans =
        (ans + f[n - i][w] * f[i][b] % mod * (1ll * n - 1ll * i - 1ll) % mod) %
        mod;
  }
  cout << ans << endl;
  return 0;
}
