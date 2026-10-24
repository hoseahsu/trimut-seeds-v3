#include <bits/stdc++.h>
using namespace std;
int Pow(int x, int y) {
  int s = 1;
  for (; y; y >>= 1, x = (long long)x * x % 1000000007)
    if (y & 1) s = (long long)s * x % 1000000007;
  return s;
}
int n, x, y, i, j, k, l, b[105][105], a[105][105], d[105], f[105], g[105],
    h[105], ans[105];
int main() {
  scanf("%d", &n);
  for (i = 1; i < n; i++) {
    scanf("%d%d", &j, &k);
    b[j][k] = b[k][j] = 1;
  }
  for (x = f[0] = 1; x <= n; x++) {
    for (i = 1; i <= n; i++)
      for (j = 1; j <= n; j++)
        if (b[i][j])
          a[i][j] = 1000000007 - x;
        else
          a[i][j] = 1000000007 - 1;
    for (i = 1; i <= n; i++)
      for (a[i][i] = 0, j = 1; j <= n; j++)
        if (i != j)
          if (b[i][j])
            a[i][i] += x;
          else
            a[i][i]++;
    for (i = y = 1; i + 1 < n; i++) {
      for (j = i; j < n; j++)
        if (a[j][i]) break;
      if (j != i)
        for (y = 1000000007 - y, k = i; k < n; k++) swap(a[i][k], a[j][k]);
      for (j = i + 1, l = Pow(a[i][i], 1000000007 - 2); j < n; j++)
        for (k = n - 1; k >= i; k--)
          a[j][k] =
              (a[j][k] -
               (long long)a[i][k] * a[j][i] % 1000000007 * l % 1000000007 +
               1000000007) %
              1000000007;
    }
    for (i = 1; i < n; i++) y = (long long)y * a[i][i] % 1000000007;
    d[x] = y;
    for (i = x; i; i--)
      f[i] = (f[i - 1] + (long long)(1000000007 - x) * f[i]) % 1000000007;
    f[0] = (long long)(1000000007 - x) * f[0] % 1000000007;
  }
  for (x = 1; x <= n; x++) {
    for (i = 0; i <= n; i++) g[i] = f[i];
    for (i = n - 1; ~i; i--) {
      h[i] = g[i + 1];
      g[i] = (g[i] + (long long)x * g[i + 1]) % 1000000007;
    }
    for (i = j = 1; i <= n; i++)
      if (i != x) j = (long long)j * (x - i + 1000000007) % 1000000007;
    j = (long long)d[x] * Pow(j, 1000000007 - 2) % 1000000007;
    for (i = 0; i < n; i++)
      ans[i] = (ans[i] + (long long)h[i] * j) % 1000000007;
  }
  for (i = 0; i < n; i++) cout << ans[i] << ' ';
  return 0;
}
