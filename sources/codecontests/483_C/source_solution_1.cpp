#include <bits/stdc++.h>
int n, k;
int bef;
int tmp;
int main() {
  int i;
  scanf("%d %d", &n, &k);
  if (1 + k < n)
    for (i = n; i > 1 + k; i--) printf("%d ", i);
  for (i = 0; i < 1 + k; i++)
    if (i % 2 == 0)
      printf("%d ", 1 + k - i / 2);
    else
      printf("%d ", 1 + i / 2);
  printf("\n");
  return 0;
}
