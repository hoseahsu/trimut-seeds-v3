#include <bits/stdc++.h>
using namespace std;
namespace star {
const int maxn = 1e6 + 10, mod = 998244353;
char s[maxn];
int n, l[maxn], r[maxn], w[maxn], inv[maxn], mul[maxn];
inline int fpow(int a, int b) {
  int ans = 1;
  for (; b; b >>= 1, a = 1ll * a * a % mod)
    if (b & 1) ans = 1ll * ans * a % mod;
  return ans;
}
inline int C(int n, int m) {
  return n < 0 or m < 0 or n < m
             ? 0
             : 1ll * mul[n] * inv[m] % mod * inv[n - m] % mod;
}
inline void work() {
  scanf("%s", s + 1), n = strlen(s + 1);
  for (int i = 1; i <= n; i++)
    l[i] = l[i - 1] + (s[i] == '('), w[i] = w[i - 1] + (s[i] == '?');
  for (int i = n; i; i--) r[i] = r[i + 1] + (s[i] == ')');
  mul[0] = inv[0] = 1;
  for (int i = 1; i <= n; i++) mul[i] = 1ll * mul[i - 1] * i % mod;
  inv[n] = fpow(mul[n], mod - 2);
  for (int i = n - 1; i; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
  int ans = 0;
  for (int i = 1; i < n; i++) {
    int s1 = l[i], s2 = w[i], s3 = r[i + 1], s4 = w[n] - w[i];
    ans = (ans + 1ll * s1 * C(s2 + s4, s3 + s4 - s1) +
           1ll * s2 * C(s2 + s4 - 1, s3 + s4 - s1 - 1)) %
          mod;
  }
  printf("%d\n", ans);
}
}  // namespace star
signed main() {
  star::work();
  return 0;
}
