#include <bits/stdc++.h>
using namespace std;
long long k, d, t;
int main() {
  scanf("%lld%lld%lld", &k, &d, &t);
  t *= 2;
  long long round = ceil((double)k / d) * d;
  long long num = k * 2 + (round - k);
  long long cnt = t / num;
  long long left = t - cnt * num;
  double ans = 0.0;
  if (left <= k * 2) {
    ans = cnt * round + left / 2;
    if (left % 2) ans += 0.5;
  } else
    ans = cnt * round + k + (left - k * 2);
  printf("%.1lf\n", ans);
  return 0;
}
