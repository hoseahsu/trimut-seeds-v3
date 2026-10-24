#include <bits/stdc++.h>
int main() {
  char A[100];
  int n, i, j, k = 0, m, l;
  scanf("%d", &n);
  scanf("%s", A);
  for (i = n; i >= 0; i--) {
    l = 0;
    if (i % 2 == 0) {
      j = i / 2;
      m = j;
      for (k = 0; k < j; k++) {
        if (A[k] == A[m]) l++, m++;
      }
      if (j == 0) {
        printf("%d", n);
        return 0;
      } else if (j == l) {
        printf("%d", (n - l) + 1);
        return 0;
      }
    }
  }
}
