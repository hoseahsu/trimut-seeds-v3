#include <bits/stdc++.h>
int n, k;
long long int a[100010], inv[100010], presum[100010], jc[100010], jcv[100010],
    e[100010];
char str[100010];
void init() {
  int i;
  inv[1] = 1;
  jc[0] = 1;
  jcv[0] = 1;
  jc[1] = 1;
  jcv[1] = 1;
  e[0] = 1;
  e[1] = 10;
  for (i = 2; i < 100010; i++) {
    inv[i] = inv[1000000007LL % i] * (1000000007LL - 1000000007LL / i) %
             1000000007LL;
    jc[i] = (jc[i - 1] * i) % 1000000007LL;
    jcv[i] = (jcv[i - 1] * inv[i]) % 1000000007LL;
    e[i] = (e[i - 1] * 10LL) % 1000000007LL;
  }
}
long long int COMB(long long int n, long long int m) {
  if (m < 0 || m > n) return 0LL;
  if (m == 0 || m == n) return 1LL;
  long long int ret =
      ((jc[n] * jcv[n - m]) % 1000000007LL * jcv[m]) % 1000000007LL;
  return ret;
}
void solve(int n, int k) {
  int i, l;
  long long int ans = 0;
  if (k == 0) {
    for (i = n - 1; i >= 0; i--)
      ans = (ans + (e[n - 1 - i] * a[i]) % 1000000007LL) % 1000000007LL;
    printf("%I64d\n", ans % 1000000007LL);
    return;
  }
  for (l = 0; l <= n - 2; l++)
    ans = (ans +
           (e[l] * COMB(n - l - 2, k - 1) % 1000000007LL * presum[n - l - 2]) %
               1000000007LL) %
          1000000007LL;
  for (i = 0; i <= n - 1; i++)
    ans = (ans +
           ((a[i] * e[n - 1 - i]) % 1000000007LL * COMB(i, k)) % 1000000007LL) %
          1000000007LL;
  printf("%I64d\n", ans % 1000000007LL);
}
int main() {
  int i;
  init();
  while (scanf("%d%d", &n, &k) == 2) {
    scanf("%s", str);
    for (i = 0; i < n; i++) {
      a[i] = str[i] - '0';
      if (i == 0)
        presum[i] = a[i];
      else
        presum[i] = (presum[i - 1] + a[i]) % 1000000007LL;
    }
    solve(n, k);
  }
  return 0;
}
