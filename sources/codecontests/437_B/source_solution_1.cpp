#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long sum = 0, ff = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') ff = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') sum = sum * 10 + ch - 48, ch = getchar();
  return sum * ff;
}
void write(long long x) {
  if (x < 0) x = ~(x - 1), putchar('-');
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
void writesp(long long x) { write(x), putchar(' '); }
void writeln(long long x) { write(x), puts(""); }
const int N = 1e5 + 7;
int s, l, ans[N], cnt;
inline int lowbit(int x) { return x & (-x); }
int main() {
  s = read(), l = read();
  while (l) {
    if (s - lowbit(l) >= 0) ans[++cnt] = l, s -= lowbit(l);
    --l;
  }
  if (s) return puts("-1"), 0;
  writeln(cnt);
  for (register int i = 1; i <= cnt; ++i) writesp(ans[i]);
  return 0;
}
