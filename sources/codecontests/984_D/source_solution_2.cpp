#include <bits/stdc++.h>
int a[5010][5010];
int d[5010][5010] = {0};
int max(int x, int y) { return x > y ? x : y; }
int main() {
  int n, q, l, r;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[1][i]);
    d[i][i] = a[1][i];
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= n - i; j++) {
      a[i + 1][j] = a[i][j] ^ a[i][j + 1];
    }
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= n - i + 1; j++) {
      d[j][i + j - 1] = max(a[i][j], max(d[j][i + j - 2], d[j + 1][i + j - 1]));
    }
  }
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    scanf("%d %d", &l, &r);
    printf("%d\n", d[l][r]);
  }
}
