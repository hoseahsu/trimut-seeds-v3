#include <bits/stdc++.h>
using namespace std;
const int N = 3010;
const int mod = 998244353;
int n, c, a[N];
long long qpow(int a, int b) {
  long long ret = 1, base = a;
  while (b) {
    if (b & 1) ret = ret * base % mod;
    base = base * base % mod, b >>= 1;
  }
  return ret;
}
void up(long long &a, long long b) { a = (a + b) % mod; }
long long ans[N], w[N], iw[N];
long long f0[N][N], f1[N][N];
int cnt[N];
void solve1() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= c; j++) cnt[j] = 0;
    int tmp = c;
    long long s = 1;
    for (int j = i; j <= n; j++) {
      if (tmp == -1) {
        s = s * iw[cnt[a[j]]] % mod;
        cnt[a[j]]++;
        s = s * w[cnt[a[j]]] % mod;
      } else
        cnt[a[j]]++;
      if (cnt[a[j]] == 1) tmp--;
      if (!tmp) {
        for (int k = 1; k <= c; k++) s = s * w[cnt[k]] % mod;
        tmp = -1;
      }
      if (tmp == -1) f0[i][j] = s * iw[cnt[a[j]]] % mod;
    }
  }
  f1[0][0] = 1;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= i / c; j++)
      if (f1[i][j])
        for (int k = i + 1; k <= n; k++)
          up(f1[k][j + 1], f1[i][j] * f0[i + 1][k]);
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= i / c; j++) up(ans[j], f1[i][j] * (w[n - i] + 1));
}
long long f2[2][N][2100];
void solve2() {
  int ss = (1 << c) - 1;
  f2[0][0][0] = 1, a[n + 1] = 1;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= i / c; j++)
      for (int k = 0; k <= ss; k++)
        if (f2[i & 1][j][k]) {
          int no = i & 1, ne = no ^ 1, ts = k | (1 << (a[i + 1] - 1));
          if (ts == ss) {
            up(f2[ne][j + 1][0], f2[no][j][k]);
            if (i < n) up(ans[j + 1], f2[no][j][k] * (w[n - i - 1] + 1));
          } else
            up(f2[ne][j][ts], f2[no][j][k]);
          up(f2[ne][j][k], f2[no][j][k]);
          f2[no][j][k] = 0;
        }
  ans[0] = (w[n] + 1) % mod;
}
int main() {
  scanf("%d%d", &n, &c);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  long long tmp = 1;
  for (int i = 1; i <= n; i++)
    tmp = tmp * 2 % mod, w[i] = (tmp - 1 + mod) % mod,
    iw[i] = qpow(w[i], mod - 2);
  if (c > 9)
    solve1();
  else
    solve2();
  for (int i = 0; i <= n; i++) ans[i] = (ans[i] - ans[i + 1] + mod) % mod;
  ans[0] = (ans[0] - 1 + mod) % mod;
  for (int i = 0; i <= n; i++) printf("%lld ", ans[i]);
  printf("\n");
  return 0;
}
