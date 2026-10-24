#include <bits/stdc++.h>
int main() {
  long long n, sum;
  int i;
  scanf("%lld", &n);
  sum = 0;
  for (i = 1; sum < n; i++) sum += i;
  printf("%lld\n", i - 1 + n - sum);
}
