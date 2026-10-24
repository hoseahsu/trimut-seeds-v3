#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const int inf = 0x3f3f3f3f;
inline long long read() {
  register long long x = 0, f = 1;
  register char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
  return x * f;
}
void write(long long x) {
  if (x < 0) x = -x, putchar('-');
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
void writeln(long long x) {
  write(x);
  puts("");
}
const int mod = 1e9 + 7;
const int maxn = 55;
int n, p, pow2[maxn], f[maxn][3][3];
void add(int &x, int v) {
  x += v;
  if (x >= mod) x -= mod;
}
int main() {
  n = read(), p = read();
  pow2[0] = 1;
  for (register int i = (1); i <= int(n); ++i) pow2[i] = pow2[i - 1] * 2 % mod;
  f[0][0][0] = 1;
  for (register int i = (0); i < int(n); ++i) {
    int x = read();
    for (register int j = (0); j <= int(2); ++j) {
      for (register int k = (0); k <= int(2); ++k) {
        if (!f[i][j][k]) continue;
        if (x != 1) {
          if (k == 0) {
            add(f[i + 1][j ? 3 - j : 1][k], 1ll * f[i][j][k] * pow2[i] % mod);
          } else {
            add(f[i + 1][j ? 3 - j : 1][k],
                1ll * f[i][j][k] * pow2[i - 1] % mod);
            add(f[i + 1][j ? j + 0 : 0][k],
                1ll * f[i][j][k] * pow2[i - 1] % mod);
          }
        }
        if (x != 0) {
          if (j == 0) {
            add(f[i + 1][j][k ? 3 - k : 1], 1ll * f[i][j][k] * pow2[i] % mod);
          } else {
            add(f[i + 1][j][k ? 3 - k : 1],
                1ll * f[i][j][k] * pow2[i - 1] % mod);
            add(f[i + 1][j][k ? k + 0 : 0],
                1ll * f[i][j][k] * pow2[i - 1] % mod);
          }
        }
      }
    }
  }
  int ans = 0;
  for (register int i = (0); i <= int(2); ++i)
    for (register int j = (0); j <= int(2); ++j)
      if (((i + j) & 1) == p) add(ans, f[n][i][j]);
  writeln(ans);
  return 0;
}
