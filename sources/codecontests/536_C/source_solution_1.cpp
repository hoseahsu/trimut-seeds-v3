#include <bits/stdc++.h>
using namespace std;
namespace IO {
char ibuf[(1 << 21) + 1], obuf[(1 << 21) + 1], st[15], *iS, *iT,
    *oS = obuf, *oT = obuf + (1 << 21);
inline char Get() {
  return (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, (1 << 21) + 1, stdin),
                      (iS == iT ? EOF : *iS++))
                   : *iS++);
}
inline void Flush() {
  fwrite(obuf, 1, oS - obuf, stdout);
  oS = obuf;
}
inline void Put(register char x) {
  *oS++ = x;
  if (oS == oT) Flush();
}
inline int read() {
  register int x = 0;
  register char ch = Get();
  while (ch > '9' || ch < '0') ch = Get();
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + (ch ^ 48), ch = Get();
  return x;
}
inline void write(register int x) {
  register int top = 0;
  while (x) st[++top] = (x % 10) + 48, x /= 10;
  while (top) Put(st[top--]);
  Put(' ');
}
}  // namespace IO
using namespace IO;
const int N = 3e5 + 1;
struct node {
  int x, y, id;
  inline bool operator<(node a) const {
    return x > a.x || (x == a.x && y > a.y);
  }
} a[N];
inline double Slope(node a, node b) {
  return (double)a.x * b.x * (b.y - a.y) / ((double)a.y * b.y * (b.x - a.x));
}
int q[N], Next[N], v[N];
double k[N];
int main() {
  register int n = read(), px, py = 0, tl;
  for (register int i = 1; i <= n; ++i) {
    a[i].x = read(), a[i].y = read(), a[i].id = i;
    if (py < a[i].y || (py == a[i].y && px < a[i].x)) py = a[i].y, px = a[i].x;
  }
  sort(a + 1, a + n + 1);
  q[tl = 1] = 1;
  for (register int i = 2; i <= n && px <= a[i].x; ++i) {
    if (a[q[tl]].x == a[i].x) {
      if (a[q[tl]].y == a[i].y)
        Next[a[i].id] = Next[a[q[tl]].id], Next[a[q[tl]].id] = a[i].id;
      continue;
    }
    while (tl > 1 && k[tl] > Slope(a[q[tl]], a[i])) --tl;
    q[++tl] = i, k[tl] = Slope(a[q[tl - 1]], a[i]);
  }
  for (; tl; --tl)
    for (register int i = a[q[tl]].id; i; i = Next[i]) v[i] = 1;
  for (register int i = 1; i <= n; ++i)
    if (v[i]) write(i);
  return Flush(), 0;
}
