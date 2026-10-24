#include <bits/stdc++.h>
void sort(int *a, int n) {
  int isSorted = 0;
  int i;
  int tmp;
  while (isSorted == 0) {
    isSorted = 1;
    for (i = 0; i < n - 1; i++) {
      if (a[i] > a[i + 1]) {
        tmp = a[i];
        a[i] = a[i + 1];
        a[i + 1] = tmp;
        isSorted = 0;
      }
    }
  }
}
int main() {
  int n, m;
  int p[101];
  int i;
  int numeven, numodd;
  scanf("%d", &n);
  m = n / 2;
  for (i = 0; i < m; i++) scanf("%d", p + i);
  sort(p, m);
  numeven = 0;
  numodd = 0;
  for (i = 0; i < m; i++) {
    numeven += ((n - i * 2) - p[m - 1 - i]) > 0 ? ((n - i * 2) - p[m - 1 - i])
                                                : -((n - i * 2) - p[m - 1 - i]);
  }
  for (i = 0; i < m; i++) {
    numodd += (((i * 2 + 1) - p[i])) > 0 ? (((i * 2 + 1) - p[i]))
                                         : -(((i * 2 + 1) - p[i]));
  }
  if (numeven > numodd)
    printf("%d\n", numodd);
  else
    printf("%d\n", numeven);
  return 0;
}
