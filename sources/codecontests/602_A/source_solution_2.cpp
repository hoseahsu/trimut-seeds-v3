#include <bits/stdc++.h>
long long pow(long long x, long long y) {
  long long n = 1;
  while (y--) n *= x;
  return n;
}
int main() {
  long long ans = 0, n, b, a;
  scanf("%lld%lld", &n, &b);
  for (long long i = 0; i < n; i++) {
    scanf("%lld", &a);
    ans += a * pow(b, n - i - 1);
  }
  scanf("%lld%lld", &n, &b);
  for (long long i = 0; i < n; i++) {
    scanf("%lld", &a);
    ans -= a * pow(b, n - i - 1);
  }
  if (!ans)
    printf("=\n");
  else if (ans < 0)
    printf("<\n");
  else
    printf(">\n");
  return 0;
}
