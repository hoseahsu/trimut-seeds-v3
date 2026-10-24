#include <bits/stdc++.h>
inline int read() {
  register int s = 0, f = 1;
  char c;
  for (c = getchar(); c < '0' || c > '9'; c = getchar())
    if (c == '-') f = -1;
  while (c >= '0' && c <= '9') s = (s * 10 + (c ^ '0')), c = getchar();
  return s * f;
}
inline void print(register int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) print(x / 10);
  putchar(x % 10 ^ '0');
}
using namespace std;
int ans, prim[20000005], l, r, tot;
bitset<300000005> vis;
inline void Get_Prime(register int l, register int r) {
  vis[0] = vis[1] = 1;
  for (register int i = 2; i <= r; ++i) {
    if (!vis[i]) prim[++tot] = i;
    for (register int j = 1; j <= tot && i * prim[j] <= r; ++j) {
      vis[i * prim[j]] = 1;
      if (i % prim[j] == 0) break;
    }
  }
}
int main() {
  l = read(), r = read(), Get_Prime(l, r);
  for (register int i = 5; i <= r; i += 4)
    if (i >= l && !vis[i]) ++ans;
  if (l <= 2 && r >= 2) ++ans;
  print(ans);
  return 0;
}
