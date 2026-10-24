#include <bits/stdc++.h>
char a[1003][1000], a2[1003][1000];
int h[1002][1000], n, m, k, s, i, j;
void f(int i, int j) {
  a2[i][j] = '#';
  {
    if (i + 1 >= 0 && j >= 0 && i + 1 < n && j < m && a2[i + 1][j] != '#' &&
        a2[i + 1][j] != 'X')
      f(i + 1, j);
  };
  {
    if (i >= 0 && j + 1 >= 0 && i < n && j + 1 < m && a2[i][j + 1] != '#' &&
        a2[i][j + 1] != 'X')
      f(i, j + 1);
  };
  {
    if (i - 1 >= 0 && j >= 0 && i - 1 < n && j < m && a2[i - 1][j] != '#' &&
        a2[i - 1][j] != 'X')
      f(i - 1, j);
  };
  {
    if (i >= 0 && j - 1 >= 0 && i < n && j - 1 < m && a2[i][j - 1] != '#' &&
        a2[i][j - 1] != 'X')
      f(i, j - 1);
  };
  if (s >= k) return;
  s++;
  a[i][j] = 'X';
}
int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) {
      scanf(" %c", &a[i][j]);
      a2[i][j] = a[i][j];
    }
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) {
      if (a[i][j] == '.') f(i, j);
    }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) printf("%c", a[i][j]);
    puts("");
  }
  return 0;
}
