#include <bits/stdc++.h>
using namespace std;
long long ara[100005];
long long aa[100005], bb[100005];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", ara + i);
  if (n == 1) {
    printf("1 1\n%lld\n", -ara[1]);
    printf("1 1\n0\n");
    printf("1 1\n0\n");
    return 0;
  }
  for (int i = 1; i < n; i++) {
    long long x = ara[i];
    long long rem = (-x) % n;
    rem += n, rem %= n;
    rem = (n - rem) % n;
    long long b = rem;
    long long a = (b - x) / n - b;
    aa[i] = a * n, bb[i] = b * (n - 1);
  }
  printf("%d %d\n", 1, n);
  for (int i = 1; i <= n; i++) printf("%lld ", aa[i]);
  printf("\n");
  printf("%d %d\n", 1, n - 1);
  for (int i = 1; i < n; i++) printf("%lld ", bb[i]);
  printf("\n");
  printf("%d %d\n", n, n);
  printf("%lld\n", -ara[n]);
  return 0;
}
