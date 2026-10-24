#include <bits/stdc++.h>
const int N = 200005;
int n, k, q, mod, cnt[2];
int sH[N], ans;
void up(int &x, int y) { x += y - mod, x += x >> 31 & mod; }
void up(int &x, int y, int z) { x = (x + (long long)y * z) % mod; }
int c(int n) { return (long long)n * (n - 1) / 2 % mod; }
void solve(int n, int m) {
  if (m == 1 || n == 1) return void(++cnt[n - q]);
  solve(n >> 1, m - 1), solve(n + 1 >> 1, m - 1);
}
int f(int a, int b) {
  return ((long long)a * b % mod * (mod + 1 >> 1) + mod + sH[a] + sH[b] -
          sH[a + b]) %
         mod;
}
int main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  std::cin >> n >> k >> mod;
  q = n >> std::min(k - 1, 20), solve(n, k);
  sH[1] = 1;
  for (int i = 2; i <= n; ++i)
    sH[i] = (long long)(mod - mod / i) * sH[mod % i] % mod;
  for (int i = 2; i <= n; ++i) up(sH[i], sH[i - 1]);
  for (int i = 2; i <= n; ++i) up(sH[i], sH[i - 1]);
  up(ans, (long long)c(q) * (mod + 1 >> 1) % mod, cnt[0]);
  up(ans, (long long)c(q + 1) * (mod + 1 >> 1) % mod, cnt[1]);
  up(ans, f(q, q), c(cnt[0]));
  up(ans, f(q + 1, q + 1), c(cnt[1]));
  up(ans, f(q, q + 1), (long long)cnt[0] * cnt[1] % mod);
  std::cout << ans << '\n';
  return 0;
}
