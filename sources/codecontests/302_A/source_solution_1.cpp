#include <bits/stdc++.h>
int main() {
  int i, neg = 0, pos = 0, n, m, x, l, r, h;
  scanf("%d %d", &n, &m);
  for (x = 0; x < n; x++) {
    scanf("%d", &i);
    if (i == -1) {
      neg = neg + 1;
    } else {
      pos = pos + 1;
    }
  }
  for (x = 1; x <= m; x++) {
    scanf("%d %d", &l, &r);
    h = (r - l + 1);
    if (h % 2 == 0 && ((h / 2) <= neg && (h / 2) <= pos)) {
      printf("1\n");
    } else {
      printf("0\n");
    }
  }
}
