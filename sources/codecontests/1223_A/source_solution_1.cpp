#include <bits/stdc++.h>
int main(void) {
  int p;
  scanf("%d", &p);
  long long int a[p];
  for (int i = 0; i < p; i++) {
    scanf("%lld", &a[i]);
  }
  for (int i = 0; i < p; i++) {
    if (a[i] == 2) {
      printf("2");
    } else if (a[i] % 2 != 0) {
      printf("1");
    } else {
      printf("0");
    }
    printf("\n");
  }
  return 0;
}
