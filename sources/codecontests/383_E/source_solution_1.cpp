#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
inline int read() {
  char c = getchar();
  int x = 0;
  bool f = 0;
  for (; !isdigit(c); c = getchar()) f ^= !(c ^ 45);
  for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
  if (f) x = -x;
  return x;
}
int n, f[1 << 24 | 1];
inline int getc(int x) {
  int res = 0;
  for (; x; x ^= x & -x) res++;
  return res;
}
signed main() {
  n = read();
  for (register int i = (1); i <= (n); ++i) {
    char s[3];
    cin >> s;
    int S = 0;
    for (register int i = (0); i <= (2); ++i) S |= 1 << (s[i] - 'a');
    for (int T = S; T; T = (T - 1) & S) f[T] += (getc(T) & 1) ? 1 : -1;
  }
  int maxst = (1 << 24) - 1;
  for (register int i = (0); i <= (23); ++i)
    for (register int s = (0); s <= (maxst); ++s)
      if (s >> i & 1) f[s] += f[s ^ (1 << i)];
  int res = 0;
  for (register int s = (0); s <= (maxst); ++s) res ^= f[s] * f[s];
  cout << res;
  return 0;
}
