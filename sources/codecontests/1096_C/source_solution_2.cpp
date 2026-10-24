#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    int d;
    scanf("%d", &d);
    if (d == 179) {
      printf("360\n");
    } else {
      for (int i = 3; i <= 180; i++) {
        if (i * d % 180 == 0) {
          int k = i * d / 180;
          if (k >= 1 && k <= i - 2) {
            printf("%d\n", i);
            break;
          }
        }
      }
    }
  }
  return 0;
}
