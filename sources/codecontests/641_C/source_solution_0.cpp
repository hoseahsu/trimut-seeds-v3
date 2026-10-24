#include <bits/stdc++.h>
using namespace std;
int b[1100000];
int main() {
  int n, q, odd, even, p1, p2;
  while (scanf("%d %d", &n, &q) != EOF) {
    memset(b, 0, sizeof(b));
    odd = 0, even = 1;
    while (q--) {
      int x, y;
      scanf("%d", &x);
      if (x == 1) {
        scanf("%d", &y);
        odd = (odd + y + n) % n;
        even = (even + y + n) % n;
      } else {
        if (odd % 2) {
          odd = (odd - 1 + n) % n;
          even = (even + 1 + n) % n;
        } else {
          odd = (odd + 1 + n) % n;
          even = (even - 1 + n) % n;
        }
      }
    }
    int cnt = 1;
    while (cnt <= n) {
      b[odd] = cnt++;
      b[even] = cnt++;
      odd = (odd + 2 + n) % n;
      even = (even + 2 + n) % n;
    }
    for (int i = 0; i < n - 1; i++) printf("%d ", b[i]);
    printf("%d\n", b[n - 1]);
  }
  return 0;
}
