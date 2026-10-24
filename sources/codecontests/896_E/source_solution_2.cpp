#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
int n, m, nn, mm;
int a[200005];
int c[200005], d[200005];
int w[200005];
int ff = 0, gg = 0;
struct kuai {
  int a[505];
  int r, c, n;
  int lp, rp;
  int f[505], s[505];
  unsigned char d[200005];
  int find(int x) {
    if (f[x] == x) return x;
    return f[x] = find(f[x]);
  }
  inline void he(int x, int y) {
    register int fx = find(x), fy = find(y);
    if (fx == fy) return;
    s[fx] += s[fy];
    f[fy] = fx;
  }
  inline void jian(int x) {
    if (x >= r) return;
    int y = x;
    x += c;
    if ((y << 1) >= r) {
      int rc = r + c, qc = rc - c;
      for (register int i = y + 1; i <= qc; i++) {
        ff++;
        if (ff > 30000000) cout << 1 / 0;
        if (d[i + c] != 0) {
          register int cr = i + c;
          if (d[cr - y] != 0)
            he(d[cr - y], d[cr]);
          else {
            a[d[cr]] -= y;
            d[cr - y] = d[cr];
          }
          d[cr] = 0;
        }
      }
      r = x;
      while (d[r + c] == 0) r--;
    } else {
      r -= y;
      for (register int i = x; i >= c; i--) {
        register int o = i + y;
        if (d[i] != 0) {
          if (d[o] != 0)
            he(d[o], d[i]);
          else {
            a[d[i]] += y;
            d[o] = d[i];
          }
          d[i] = 0;
        }
      }
      c = x;
    }
  }
  inline int qiu(int x) { return s[find(d[x + c])]; }
  void yanghua() {
    c = 0;
    for (register int i = 1; i <= n; i++) {
      f[i] = i;
      s[i] = 1;
    }
    for (register int i = 1; i <= n; i++) {
      if (a[i] > r) r = a[i];
      if (d[a[i]] != 0) {
        he(d[a[i]], i);
      } else {
        d[a[i]] = i;
      }
    }
  }
  int fa[505];
  void huanyuan() {
    for (int i = 1; i <= n; i++) d[a[i]] = 0;
    for (int i = 1; i <= n; i++) fa[i] = a[i];
    for (int i = 1; i <= n; i++) a[i] = fa[find(i)] - c;
    c = 0;
  }
} b[505];
inline int read() {
  register int x = 0, f = 1;
  register char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
  return x * f;
}
void rd() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) a[i] = read();
  int nn;
  nn = 254;
  for (int i = 1; i <= n; i++) {
    if (i % nn == 1) {
      c[i] = c[i - 1] + 1;
      d[i] = 1;
      b[c[i]].a[d[i]] = a[i];
      b[c[i]].lp = i;
    } else {
      c[i] = c[i - 1];
      d[i] = d[i - 1] + 1;
      b[c[i]].a[d[i]] = a[i];
    }
    b[c[i]].rp = i;
    if (!b[c[i]].d[a[i]]) b[c[i]].d[a[i]] = d[a[i]];
  }
  mm = c[n];
  for (int i = 1; i <= mm; i++) {
    b[i].n = b[i].rp - b[i].lp + 1;
    memset(b[i].d, 0, sizeof(b[i].d));
  }
  for (int i = 1; i <= mm; i++) {
    b[i].yanghua();
  }
}
int main() {
  rd();
  for (int i = 1; i <= m; i++) {
    int l, r, x, opt;
    opt = read();
    l = read();
    r = read();
    x = read();
    if (opt == 1) {
      if (c[l] == c[r]) {
        b[c[l]].huanyuan();
        for (int j = l; j <= r; j++)
          if (b[c[j]].a[d[j]] > x) b[c[j]].a[d[j]] -= x;
        b[c[l]].yanghua();
      } else {
        b[c[l]].huanyuan();
        for (int j = l; c[j] == c[l]; j++)
          if (b[c[j]].a[d[j]] > x) b[c[j]].a[d[j]] -= x;
        b[c[l]].yanghua();
        b[c[r]].huanyuan();
        for (int j = r; c[j] == c[r]; j--)
          if (b[c[j]].a[d[j]] > x) b[c[j]].a[d[j]] -= x;
        b[c[r]].yanghua();
        for (int j = c[l] + 1; j <= c[r] - 1; j++) {
          if (x < b[j].r) b[j].jian(x);
        }
      }
    } else {
      int ans = 0;
      if (c[l] == c[r]) {
        b[c[l]].huanyuan();
        for (int j = l; j <= r; j++)
          if (b[c[j]].a[d[j]] == x) ans++;
        b[c[l]].yanghua();
      } else {
        b[c[l]].huanyuan();
        for (register int j = l; c[j] == c[l] && j <= n; j++)
          ans += (b[c[j]].a[d[j]] == x);
        b[c[l]].yanghua();
        b[c[r]].huanyuan();
        for (register int j = r; c[j] == c[r] && j > 0; j--)
          ans += (b[c[j]].a[d[j]] == x);
        b[c[r]].yanghua();
        for (register int j = c[l] + 1; j <= c[r] - 1; j++) {
          ans += b[j].qiu(x);
        }
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
