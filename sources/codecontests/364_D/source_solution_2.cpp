#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  for (; ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') f = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar())
    x = (x << 1) + (x << 3) + ch - 48;
  return x * f;
}
inline long long gcd(long long x, long long y) {
  return (!y) ? x : gcd(y, x % y);
}
long long n, a[1000005], g[1000005], p[10000005], cnt[10000005], ans = 1;
bool vis[1000005];
inline void solve(long long x) {
  p[0] = 0;
  for (long long i = 1; i * i <= a[x]; i++)
    if (a[x] % i == 0) {
      p[++p[0]] = i;
      if (i * i != a[x]) p[++p[0]] = a[x] / i;
    }
  for (long long i = 1; i <= p[0]; i++) cnt[i] = 0;
  sort(p + 1, p + p[0] + 1);
  for (long long i = 1; i <= n; i++)
    ++cnt[lower_bound(p + 1, p + p[0] + 1, gcd(a[i], a[x])) - p];
  for (long long i = 1; i <= p[0] - 1; i++)
    for (long long j = i + 1; j <= p[0]; j++)
      if (p[j] % p[i] == 0) cnt[i] += cnt[j];
  for (long long i = 1; i <= p[0]; i++)
    if (cnt[i] * 2 >= n) ans = max(ans, p[i]);
}
signed main() {
  srand(time(NULL));
  n = read();
  for (long long i = 1; i <= n; i++) a[i] = read();
  for (long long i = 1; i <= min(n, 10ll); i++) {
    long long m = ((rand() << 15) + rand()) % n + 1;
    while (vis[m]) m = ((rand() << 15) + rand()) % n + 1;
    vis[m] = 1;
    solve(m);
  }
  printf("%I64d", ans);
  return 0;
}
