#include <bits/stdc++.h>
using namespace std;
bool qiuyuakioi;
int read() {
  int x = 0, l = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == EOF) {
      qiuyuakioi = 1;
      return 0;
    }
    ch = getchar();
  }
  while (isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar();
  return x * l;
}
const int N = 2.5e5 + 5, sec = 86400;
int ti[N], a, b[N], c[N], d[N], e[N], f[N];
int l, da[14][32], nd[14][32],
    y[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
void o(int x) {
  if (x < 10) putchar(48);
  printf("%d", x);
}
int main() {
  int n = read(), m = read();
  for (int i = 1; i <= 12; ++i) {
    for (int j = 2; j <= y[i]; ++j) da[i][j] = da[i][j - 1] + sec;
    da[i + 1][1] = da[i][y[i]] + sec;
  }
  y[2] = 29;
  for (int i = 1; i <= 12; ++i) {
    for (int j = 2; j <= y[i]; ++j) nd[i][j] = nd[i][j - 1] + sec;
    nd[i + 1][1] = nd[i][y[i]] + sec;
  }
  while (1) {
    ++l;
    a = read();
    if (qiuyuakioi) break;
    b[l] = read(), c[l] = read(), d[l] = read(), e[l] = read(), f[l] = read();
    ti[l] = nd[b[l]][c[l]] + d[l] * 3600 + e[l] * 60 + f[l];
  }
  --l;
  for (int i = m; i <= l; ++i)
    if (ti[i] - ti[i - m + 1] <= n - 1) {
      printf("2012-"), o(b[i]), printf("-"), o(c[i]), printf(" ");
      o(d[i]), printf(":"), o(e[i]), printf(":"), o(f[i]);
      exit(0);
    }
  printf("-1");
  return 0;
}
