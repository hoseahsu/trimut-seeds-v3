#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
inline char gc() {
  static const int L = 1000;
  static char sxd[L], *sss = sxd, *ttt = sxd;
  if (sss == ttt) {
    ttt = (sss = sxd) + fread(sxd, 1, L, stdin);
    if (sss == ttt) return EOF;
  }
  return *sss++;
}
inline int read(int& x) {
  x = 0;
  char c = getchar();
  bool f = false;
  for (; !isdigit(c); c = getchar()) {
    if (c == EOF) return -1;
    if (c == '-') f = true;
  }
  for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
  if (f) x = -x;
  return 1;
}
int i, j, z, n, a;
int main() {
  read(n);
  for (i = 1; i <= n; i++) {
    read(a);
    if (a > z) {
      cout << i;
      return 0;
    }
    if (a >= z) z = a + 1;
  }
  puts("-1");
  return 0;
}
