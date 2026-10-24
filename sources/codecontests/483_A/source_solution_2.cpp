#include <bits/stdc++.h>
int main() {
  long long int l, r, i;
  scanf("%I64d %I64d", &l, &r);
  long long int a = l % 2;
  if (l + 2 + a <= r) {
    printf("%I64d %I64d %I64d", l + a, l + a + 1, l + a + 2);
  } else
    printf("-1");
  return 0;
}
