#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  register long long s = 0, f = 0;
  register char ch = getchar();
  while (!isdigit(ch)) f |= (ch == '-'), ch = getchar();
  while (isdigit(ch)) s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
  return f ? -s : s;
}
long long n, m, p, check;
const long long MAX = 26;
long long a[MAX], b[MAX], pos[MAX];
inline long long pw(long long x) { return x < 10 ? 10 : 100; }
inline void dfs(long long k, long long x, long long y, long long num) {
  if (x == 0 and y == 0 and num) {
    puts("Yes");
    printf("%lld\n", num);
    for (register long long i = 1; i <= num; ++i) {
      printf("%lld ", b[i]);
    }
    exit(0);
  }
  if (k > m) return;
  dfs(k + 1, x, y, num);
  b[num + 1] = pos[a[k]];
  dfs(k + 1, x ^ a[k], (y * pw(a[k]) + a[k]) % p, num + 1);
}
signed main() {
  n = read(), p = read();
  for (register long long i = 1; i <= n; ++i) {
    long long x = read();
    if (x < MAX) a[++m] = x, pos[x] = i;
  }
  dfs(1, 0, 0, 0);
  puts("No");
  return 0;
}
