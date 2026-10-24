#include <bits/stdc++.h>
long long t, k, d, ans;
int main(void) {
  scanf("%lld%lld%lld", &k, &d, &t);
  long long x = k / d * d + (k % d != 0) * d;
  t *= 2ll;
  long long y = t / (2ll * k + (x - k));
  ans += y * x;
  t -= y * (2ll * k + (x - k));
  if (t >= 2ll * k) {
    ans += k + (t - 2ll * k);
    printf("%lld.0\n", ans);
  } else {
    ans += t / 2;
    if (t % 2)
      printf("%lld.5\n", ans);
    else
      printf("%lld.0\n", ans);
  }
  return 0;
}
