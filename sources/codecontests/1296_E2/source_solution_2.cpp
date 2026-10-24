#include <bits/stdc++.h>
using namespace std;
namespace yspm {
inline long long read() {
  long long res = 0, f = 1;
  char k;
  while (!isdigit(k = getchar()))
    if (k == '-') f = -1;
  while (isdigit(k)) res = res * 10 + k - '0', k = getchar();
  return res * f;
}
const long long N = 2e5 + 10;
long long dp[N], maxx[30], n, ans;
char s[N];
signed main() {
  n = read();
  scanf("%s", s + 1);
  for (long long i = n; i >= 1; --i) {
    dp[i] = maxx[s[i] - 'a'] + 1;
    for (long long j = s[i] - 'a' + 1; j < 26; ++j)
      maxx[j] = max(maxx[j], dp[i]);
    ans = max(ans, dp[i]);
  }
  printf("%lld\n", ans);
  for (long long i = 1; i <= n; ++i) printf("%lld ", dp[i]);
  return puts(""), 0;
}
}  // namespace yspm
signed main() { return yspm::main(); }
