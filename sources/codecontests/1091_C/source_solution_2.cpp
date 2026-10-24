#include <bits/stdc++.h>
using namespace std;
long long i, i0, n, m;
set<long long> s;
void cal(long long n, long long x) {
  n = n / x * x - 1;
  long long tmp = n / x + 1;
  s.insert(tmp + (n / x * x) * tmp / 2);
}
int main() {
  while (scanf("%lld", &n) != EOF) {
    s.clear();
    for (i = 1; i * i <= n; i++) {
      if (n % i == 0) {
        cal(n, i);
        if (i * i != n) {
          cal(n, n / i);
        }
      }
    }
    for (auto i : s) {
      printf("%lld ", i);
    }
    printf("\n");
  }
  return 0;
}
