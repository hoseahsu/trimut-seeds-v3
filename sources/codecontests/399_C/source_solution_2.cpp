#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b;
  while (~scanf("%I64d%I64d", &a, &b)) {
    long long s = 0;
    if (!a) {
      s = -b * b;
      printf("%I64d\n", s);
      while (b--) printf("x");
      printf("\n");
    } else if (!b) {
      s = a * a;
      printf("%I64d\n", s);
      while (a--) printf("o");
      printf("\n");
    } else {
      long long temp = a * a - b * b, c, ans = 1;
      int j;
      for (int i = 1; i <= a; i++) {
        if (b >= i + 1)
          j = i + 1;
        else
          break;
        c = ((a - i + 1) * (a - i + 1) + (i - 1)) -
            ((b / j + 1) * (b / j + 1) * (b % j) +
             (b / j) * (b / j) * (j - b % j));
        if (c > temp) {
          temp = c;
          ans = i;
        }
      }
      printf("%I64d\n", temp);
      int tb = b % (ans + 1);
      int ta = ans - 1;
      for (int i = 1; i <= ans * 2 + 1; i++) {
        if (i & 1) {
          if (tb) {
            j = b / (ans + 1) + 1;
            tb--;
          } else
            j = b / (ans + 1);
          while (j--) printf("x");
        } else {
          if (ta) {
            j = 1;
            ta--;
          } else
            j = a - ans + 1;
          while (j--) printf("o");
        }
      }
      printf("\n");
    }
  }
  return 0;
}
