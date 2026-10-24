#include <bits/stdc++.h>
long long f[40][40];
int main() {
  int n, h;
  scanf("%d%d", &n, &h);
  for (register int i = 0; i <= n; i += 1) f[0][i] = 1;
  for (register int i = 1; i <= n; i += 1)
    for (register int j = 1; j <= n; j += 1)
      for (register int k = 0; k < j; k += 1)
        f[j][i] += f[k][i - 1] * f[j - k - 1][i - 1];
  printf("%lld", f[n][n] - f[n][h - 1]);
  return 0;
}
