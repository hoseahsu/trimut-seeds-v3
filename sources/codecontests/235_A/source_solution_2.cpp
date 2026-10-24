#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (!b) return a;
  return gcd(b, a % b);
}
int main() {
  int n;
  scanf("%d", &n);
  if (n == 1)
    printf("1\n");
  else if (n == 2)
    printf("2\n");
  else if (n % 2)
    printf("%I64d\n", 1LL * n * (n - 1) * (n - 2));
  else {
    long long int x = 1LL * n * (n - 1);
    long long int ans = 1LL * (n - 1) * (n - 2) * (n - 3);
    for (int i = n - 1; i >= 1; i--) ans = max(ans, x / gcd(x, i) * i);
    printf("%I64d\n", ans);
  }
}
