#include <bits/stdc++.h>
using namespace std;
long long mod(long long x, long long y) { return y == 0 ? x : mod(y, x % y); }
long long x, y, cnt1, cnt2;
long long work(long long n) {
  long long t1 = n / x;
  long long t2 = n / y;
  long long t3 = n / ((x * y) / mod(x, y));
  if (n - t1 >= cnt1 && n - t2 >= cnt2 && n - t3 >= cnt1 + cnt2) return true;
  return false;
}
int main() {
  while (~scanf("%I64d%I64d%I64d%I64d", &cnt1, &cnt2, &x, &y)) {
    long long l = 1, r = 2e9;
    while (l <= r) {
      long long mid = (l + r) >> 1;
      if (work(mid)) {
        r = mid - 1;
      } else
        l = mid + 1;
    }
    printf("%I64d\n", l);
  }
  return 0;
}
