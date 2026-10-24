#include <bits/stdc++.h>
using namespace std;
long long cal(long long x, long long y, long long m) {
  long long ret = 1;
  for (; y; y >>= 1) {
    if (y & 1) ret = ret * x % m;
    x = x * x % m;
  }
  return ret;
}
long long cal2(long long x, long long y, long long m) {
  long long p = cal(2ll, y, m - 1);
  if (x % m == 0) return 0;
  return cal(x, p, m);
}
long long k, l, r, p;
long long CASE;
int main() {
  cin >> CASE;
  for (int TCASE = 1; TCASE <= CASE; ++TCASE) {
    long long k, l, r, p;
    scanf("%I64d%I64d%I64d%I64d", &k, &l, &r, &p);
    if (p == 2) {
      cout << (1 - (k & 1)) << endl;
      continue;
    }
    long long A = (cal2(k, r + 1, p) + p - 1) % p,
              B = (cal2(k, l, p) + p - 1) % p;
    A = A * cal(B, p - 2, p) % p;
    if (cal2(k, l, p) == 1) A = cal(2ll, r - l + 1, p);
    if (k % 2) {
      long long dv = cal(2ll, r - l, p);
      A = A * cal(dv, p - 2, p) % p;
    }
    cout << A << endl;
  }
  return 0;
}
