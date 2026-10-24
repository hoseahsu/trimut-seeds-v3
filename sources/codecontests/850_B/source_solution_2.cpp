#include <bits/stdc++.h>
using namespace std;
long long a;
long long s1[2000005];
long long s2[2000005];
int main() {
  long long n, x, y;
  scanf("%lld %lld %lld", &n, &x, &y);
  long long p = (long long)(x * 1.0 / y) + 1;
  for (long long i = 1; i <= n; i++) {
    scanf("%lld", &a);
    s1[a]++;
    s2[a] += a;
  }
  for (long long i = 1; i < 2000005; i++) {
    s1[i] += s1[i - 1];
    s2[i] += s2[i - 1];
  }
  long long ans = 2000005 * n * y;
  for (long long i = 2; i < 2000005; i++) {
    long long tot = 0;
    for (long long j = i; j < 2000005 && tot < ans; j += i) {
      long long k = max(j - i, j - p);
      tot +=
          ((s1[j] - s1[k]) * j - (s2[j] - s2[k])) * y + (s1[k] - s1[j - i]) * x;
    }
    ans = min(tot, ans);
  }
  printf("%lld\n", ans);
}
