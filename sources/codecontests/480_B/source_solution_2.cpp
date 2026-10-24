#include <bits/stdc++.h>
int aa[100000], n;
int find(int x) {
  int i, j;
  for (i = 0, j = 0; i < n; i++) {
    while (j < n && aa[j] - aa[i] < x) j++;
    if (j < n && aa[j] - aa[i] == x) return i;
  }
  return -1;
}
int main() {
  int l, x, y, i, ix, iy, j, tmp;
  scanf("%d%d%d%d", &n, &l, &x, &y);
  for (i = 0; i < n; i++) scanf("%d", &aa[i]);
  ix = find(x);
  iy = find(y);
  if (ix != -1 && iy != -1) {
    printf("0\n");
    return 0;
  }
  if (ix != -1) {
    printf("1\n");
    printf("%d\n", y);
    return 0;
  }
  if (iy != -1) {
    printf("1\n");
    printf("%d\n", x);
    return 0;
  }
  i = find(x + y);
  if (i != -1) {
    printf("1\n");
    printf("%d\n", aa[i] + x);
    return 0;
  }
  i = find(y - x);
  if (i != -1 && aa[i] + y <= l) {
    printf("1\n");
    printf("%d\n", aa[i] + y);
    return 0;
  }
  for (i = 0, j = n - 1; i < j; i++, j--)
    tmp = aa[i], aa[i] = aa[j], aa[j] = tmp;
  for (i = 0; i < n; i++) aa[i] = l - aa[i];
  i = find(y - x);
  if (i != -1 && aa[i] + y <= l) {
    printf("1\n");
    printf("%d\n", l - (aa[i] + y));
    return 0;
  }
  printf("2\n");
  printf("%d %d\n", x, y);
  return 0;
}
