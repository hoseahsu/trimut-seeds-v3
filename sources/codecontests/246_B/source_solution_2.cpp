#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  getchar();
  int sum = 0, i, temp;
  for (i = 0; i < n; i++) {
    scanf("%d", &temp);
    getchar();
    sum += temp;
  }
  if (sum < 0) {
    sum *= -1;
  }
  if (sum % n == 0) {
    printf("%d\n", n);
  } else {
    printf("%d\n", n - 1);
  }
  return 0;
}
