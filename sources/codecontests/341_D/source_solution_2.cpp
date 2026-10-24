#include <bits/stdc++.h>
using namespace std;
int n, q, x, y, xx, yy;
long long read() {
  long long x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + ch - '0';
    ch = getchar();
  }
  return x;
}
struct BIT {
  long long c[1005][1005];
  long long ask(int x, int y) {
    long long ans = 0;
    for (; x; x -= x & -x)
      for (int i = y; i; i -= i & -i) ans ^= c[x][i];
    return ans;
  }
  void modify(int x, int y, long long v) {
    for (; x <= (n + 1); x += x & -x)
      for (int i = y; i <= (n + 1); i += i & -i) c[x][i] ^= v;
  }
} t[2][2];
long long v;
int main() {
  n = read();
  q = read();
  while (q--) {
    int op = read();
    x = read();
    y = read();
    xx = read();
    yy = read();
    if (op == 2) {
      v = read();
      t[x & 1][y & 1].modify((x + 1) >> 1, (y + 1) >> 1, v);
      t[x & 1][(yy + 1) & 1].modify((x + 1) >> 1, (yy + 2) >> 1, v);
      t[(xx + 1) & 1][y & 1].modify((xx + 2) >> 1, (y + 1) >> 1, v);
      t[(xx + 1) & 1][(yy + 1) & 1].modify((xx + 2) >> 1, (yy + 2) >> 1, v);
    } else {
      long long v1 = t[(x - 1) & 1][(y - 1) & 1].ask(x >> 1, y >> 1);
      long long v2 = t[(x - 1) & 1][yy & 1].ask(x >> 1, (yy + 1) >> 1);
      long long v3 = t[xx & 1][(y - 1) & 1].ask((xx + 1) >> 1, y >> 1);
      long long v4 = t[xx & 1][yy & 1].ask((xx + 1) >> 1, (yy + 1) >> 1);
      printf("%lld\n", v1 ^ v2 ^ v3 ^ v4);
    }
  }
  return 0;
}
