#include <bits/stdc++.h>
long long mo, ans[1000], res[1000];
long long mul(long long a, long long b) {
  return b == 0 ? 0 : ((mul(a, b >> 16) << 16) + a * (b & (1 << 16) - 1)) % mo;
}
void mul(long long f[2][2], long long g[2][2]) {
  long long a[2][2];
  a[0][0] = (mul(f[0][0], g[0][0]) + mul(f[0][1], g[1][0])) % mo;
  a[0][1] = (mul(f[0][0], g[0][1]) + mul(f[0][1], g[1][1])) % mo;
  a[1][0] = (mul(f[1][0], g[0][0]) + mul(f[1][1], g[1][0])) % mo;
  a[1][1] = (mul(f[1][0], g[0][1]) + mul(f[1][1], g[1][1])) % mo;
  memcpy(f, a, sizeof a);
}
void prezro(long long g[2][2]) { g[0][0] = g[1][1] = 1, g[0][1] = g[1][0] = 0; }
void quick(long long f[2][2], long long n) {
  long long g[2][2];
  for (prezro(g); n; n >>= 1) {
    if (n & 1) mul(g, f);
    mul(f, f);
  }
  memcpy(f, g, sizeof g);
}
void preget(long long f[2][2]) { f[0][0] = 0, f[0][1] = f[1][0] = f[1][1] = 1; }
bool dw(long long g[2][2]) {
  return g[0][0] == 1 && g[1][1] == 1 && !g[0][1] && !g[1][0];
}
int main() {
  long long n, tm;
  long long f[2][2], g[2][2], h[2][2];
  int i, j, k, cnt, pp;
  scanf("%I64d", &n);
  for (mo = tm = 1, cnt = 1, ans[0] = 0, i = 0; i < 13; i++) {
    mo = mo * 10;
    preget(f);
    quick(f, tm);
    prezro(g), pp = 0, j = 0;
    do {
      for (k = 0; k < cnt; k++) {
        preget(h);
        quick(h, ans[k] + tm * j);
        if (h[1][0] == n % mo) res[pp++] = ans[k] + tm * j;
      }
      mul(g, f);
      j++;
    } while (!dw(g));
    memcpy(ans, res, sizeof res);
    cnt = pp;
    tm *= j;
  }
  printf("%I64d\n", cnt == 0 ? -1 : ans[0]);
  return 0;
}
