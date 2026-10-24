#include <bits/stdc++.h>
using namespace std;
long long dp[505], n, ans;
struct node {
  long long a, b, k;
  bool operator<(const node x) const { return b > x.b; }
} mp[505];
int main() {
  scanf("%lld", &n);
  for (long long i = 1; i <= n; i++)
    scanf("%lld%lld%lld", &mp[i].a, &mp[i].b, &mp[i].k);
  sort(mp + 1, mp + n + 1);
  for (long long i = 1; i <= n; i++) {
    for (long long j = i; j >= 0; j--) {
      ans = max(ans, dp[j] = max(dp[j], dp[j] + mp[i].a - mp[i].b * mp[i].k));
      if (j)
        ans = max(ans,
                  dp[j] = max(dp[j], dp[j - 1] + mp[i].a - (j - 1) * mp[i].b));
    }
  }
  printf("%lld", ans);
  return 0;
}
