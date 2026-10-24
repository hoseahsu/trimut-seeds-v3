#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
const int mod = 998244353;
int n, k, ans, sum;
int f[maxn], g[maxn];
int main() {
  scanf("%d%d", &n, &k);
  for (int l = 1; l < k && l <= n; ++l) {
    int s = (k - 1) / l;
    memset(f, 0, sizeof(f));
    memset(g, 0, sizeof(g));
    f[1] = 2;
    for (int i = 2; i <= n; ++i) {
      for (int j = max(0, i - l); j < i; ++j) {
        if (j)
          f[i] = (f[i] + f[j]) % mod;
        else
          f[i] = (f[i] + 2) % mod;
      }
    }
    f[n] = (f[n] - sum + mod) % mod;
    sum = (sum + f[n]) % mod;
    g[1] = f[n];
    for (int i = 2; i <= n; ++i) {
      for (int j = max(0, i - s); j < i; ++j) {
        if (j)
          g[i] = (g[i] + g[j]) % mod;
        else
          g[i] = (g[i] + f[n]) % mod;
      }
    }
    ans = (ans + g[n]) % mod;
  }
  printf("%d\n", ans);
  return 0;
}
