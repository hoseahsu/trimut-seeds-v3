#include <bits/stdc++.h>
using namespace std;
long long a[400005], k, n;
map<long long, long long> m;
int main() {
  long long i, j = 0, ans = 0;
  scanf("%d", &n);
  scanf("%d", &k);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  if (k == 1) {
    return printf("%lld\n", (n * (n + 1)) / 2), 0;
  }
  j = 1;
  m[a[1]]++;
  for (i = 1; i <= n;) {
    while (++j <= n) {
      m[a[j]]++;
      if (m[a[j]] == k) break;
    }
    if (j > n) break;
    while (i <= j && m[a[j]] == k) {
      ans += (n - j + 1);
      m[a[i]]--;
      i++;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
