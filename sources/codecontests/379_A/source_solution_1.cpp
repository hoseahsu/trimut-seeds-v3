#include <bits/stdc++.h>
int main() {
  int a, b, n = 0, i;
  scanf("%d%d", &a, &b);
  n = a;
  for (i = 0; a / b != 0; i++) {
    n += a / b;
    a = a / b + a % b;
  }
  printf("%d\n", n);
  return 0;
}
