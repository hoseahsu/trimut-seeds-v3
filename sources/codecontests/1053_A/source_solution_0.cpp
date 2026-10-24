#include <bits/stdc++.h>
inline int read() {
  char ch = getchar();
  int ret = 0, f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  for (; ch >= '0' && ch <= '9'; ch = getchar()) ret = ret * 10 + ch - '0';
  return ret * f;
}
using namespace std;
const int INF = 1 << 30;
int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  if (n * m * 2 % k) {
    puts("NO");
    return 0;
  }
  k = n * m * 2 / k;
  long long t = sqrt(k);
  for (long long i = max(k / max(n, m), 1ll); i <= t; ++i)
    if (k % i == 0) {
      long long tmp = k / i;
      if (i <= n && tmp <= m) {
        printf("YES\n%d %d\n%I64d %d\n%d %I64d\n", 0, 0, i, 0, 0, tmp);
        return 0;
      }
      if (i <= m && tmp <= n) {
        printf("YES\n%d %d\n%I64d %d\n%d %I64d\n", 0, 0, tmp, 0, 0, i);
        return 0;
      }
    }
  puts("NO");
  return 0;
}
