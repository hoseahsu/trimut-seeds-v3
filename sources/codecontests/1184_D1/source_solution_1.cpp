#include <bits/stdc++.h>
int main() {
  int n, d, m, q;
  int t, i;
  scanf("%d %d %d %d", &n, &d, &m, &q);
  for (int a = 0; a < q; a++) {
    scanf("%d %d", &t, &i);
    if (t == 1) {
      if (i <= d) d++;
      n++;
    } else {
      if (i < d) {
        d -= i;
        n -= i;
      } else {
        n = i;
      }
    }
    printf("%d %d\n", n, d);
  }
}
