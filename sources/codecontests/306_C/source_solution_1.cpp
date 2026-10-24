#include <bits/stdc++.h>
using namespace std;
const int maxn = 4010;
const int mod = 1e9 + 9;
int n, w, b;
int num[maxn * 2], inv[maxn * 2];
int pp(int a, int b) {
  if (!b) return 1;
  int cnt = pp(a, b / 2);
  cnt = 1ll * cnt * cnt % mod;
  if (b & 1) cnt = 1ll * cnt * a % mod;
  return cnt;
}
int calc(int n, int m) {
  if (n < m) return 0;
  return 1ll * num[n] * num[n - 1] % mod * inv[m - 1] % mod * inv[n - m] % mod;
}
int main() {
  cin >> n >> w >> b;
  num[0] = 1;
  for (int i = 1; i <= w + b; ++i) num[i] = 1ll * num[i - 1] * i % mod;
  inv[w + b] = pp(num[w + b], mod - 2);
  for (int i = w + b - 1; i >= 0; --i)
    inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
  int ans = 0;
  for (int i = 1; i < n - 1; ++i) {
    int cur = n - i - 1;
    cur = 1ll * cur * calc(w, n - i) % mod * calc(b, i) % mod;
    (ans += cur) %= mod;
  }
  cout << ans << endl;
  return 0;
}
