#include <bits/stdc++.h>
using namespace std;
inline char gc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline long long read() {
  char c = getchar();
  long long tot = 1;
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') {
    tot = -1;
    c = getchar();
  }
  long long sum = 0;
  while (c >= '0' && c <= '9') {
    sum = sum * 10 + c - '0';
    c = getchar();
  }
  return sum * tot;
}
inline void wr(long long x) {
  if (x < 0) {
    putchar('-');
    wr(-x);
    return;
  }
  if (x >= 10) wr(x / 10);
  putchar(x % 10 + '0');
}
inline void wrn(long long x) {
  wr(x);
  putchar('\n');
}
inline void wri(long long x) {
  wr(x);
  putchar(' ');
}
inline void wrn(long long x, long long y) {
  wri(x);
  wrn(y);
}
inline void wrn(long long a, long long b, long long c) {
  wri(a);
  wrn(b, c);
}
long long n, m, ans[500055];
struct xx {
  long long x, y, w, id;
} z[500055], t;
bool cmp(xx a, xx b) { return (a.y == b.y) ? a.x < b.x : a.y < b.y; }
bool cmp1(xx a, xx b) {
  return (a.x - t.x) * (b.y - t.y) - (a.y - t.y) * (b.x - t.x) < 0;
}
void solve(long long l, long long r) {
  if (l > r) return;
  long long c = min_element(z + l, z + r + 1, cmp) - z;
  swap(z[c], z[l]);
  t = z[l];
  sort(z + l + 1, z + r + 1, cmp1);
  long long t1 = 0, t2 = 0;
  long long k, k2 = 0, tt = 100000;
  for (k = r; k > l; k--) {
    if (t.w != z[k].w && t1 == t2) {
      if (abs(t1 * 4 - (r - l)) < abs(tt * 4 - (r - l))) {
        tt = t1;
        k2 = k;
      }
    }
    if (z[k].w == t.w)
      t1++;
    else
      t2++;
  }
  if (t.w)
    ans[z[k2].id] = t.id;
  else
    ans[t.id] = z[k2].id;
  solve(l + 1, k2 - 1);
  solve(k2 + 1, r);
}
signed main() {
  n = read();
  for (long long i = (1); i <= (n); i++)
    z[i].x = read(), z[i].y = read(), z[i].w = 0, z[i].id = i;
  for (long long i = (1); i <= (n); i++)
    z[i + n].x = read(), z[i + n].y = read(), z[i + n].w = 1, z[i + n].id = i;
  solve(1, n * 2);
  for (long long i = (1); i <= (n); i++) wrn(ans[i]);
  return 0;
}
