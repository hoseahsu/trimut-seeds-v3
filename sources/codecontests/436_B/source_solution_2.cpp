#include <bits/stdc++.h>
char a[2005][2005];
int main() {
  int n, m, k;
  int i, j;
  int b[2005] = {0};
  scanf("%d%d%d", &n, &m, &k);
  for (i = 0; i < n; i++) scanf("%s", a[i]);
  for (i = 1; i < n; i++)
    for (j = 0; j < m; j++) {
      if (a[i][j] == 'R' && i + j < m) b[i + j]++;
      if (a[i][j] == 'L' && j - i >= 0) b[j - i]++;
      if (a[i][j] == 'U') {
        if (i % 2 == 0) b[j]++;
      }
    }
  for (i = 0; i < m; i++) printf("%d ", b[i]);
  printf("\n");
  return 0;
}
