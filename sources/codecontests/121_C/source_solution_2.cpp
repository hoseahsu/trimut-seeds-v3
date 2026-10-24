#include <bits/stdc++.h>
using namespace std;
const int maxn = 15;
int n, base = 0, K, ans, tmp, fac[maxn], used[maxn], res[maxn];
int calc(int n) {
  int res = 0;
  for (int t = 1; t <= 9; t++)
    for (int i = 0; i < (1 << t); i++) {
      int tmp = 0;
      for (int j = 0; j < t; j++)
        if (i >> j & 1)
          tmp = tmp * 10 + 4;
        else
          tmp = tmp * 10 + 7;
      res += tmp <= n;
    }
  return res;
}
bool check(int x) {
  while (x) {
    if (x % 10 != 4 && x % 10 != 7) return false;
    x /= 10;
  }
  return true;
}
int main() {
  fac[0] = 1;
  for (int i = 1; i <= 13; i++) fac[i] = fac[i - 1] * i;
  scanf("%d%d", &n, &K);
  if (n <= 13 && K > fac[n]) {
    puts("-1");
    return 0;
  }
  if (n >= 14) ans += calc(base = (n - 13));
  n -= base;
  for (int i = n; i >= 1; i--) {
    tmp = (K - 1) / fac[i - 1];
    K -= tmp * fac[i - 1];
    for (int j = 1; j <= n; j++)
      if (!used[j] && !tmp) {
        used[j] = 1;
        res[n + 1 - i] = j;
        break;
      } else if (!used[j])
        tmp--;
  }
  for (int i = 1; i <= n; i++) ans += check(base + i) && check(base + res[i]);
  printf("%d\n", ans);
  return 0;
}
