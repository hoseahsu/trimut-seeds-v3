#include <bits/stdc++.h>
int main() {
  long long int n, s;
  scanf("%I64d", &n);
  if (n < 3)
    printf("%I64d", n);
  else {
    if (n % 2 == 0) {
      if (n % 3 != 0)
        printf("%I64d", n * (n - 1) * (n - 3));
      else
        printf("%I64d", (n - 1) * (n - 2) * (n - 3));
    } else
      printf("%I64d", n * (n - 1) * (n - 2));
  }
  return 0;
}
