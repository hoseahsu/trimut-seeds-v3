#include <bits/stdc++.h>
void printmatrix(int mat[26][26]) {
  int i, j;
  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++) printf("%d ", mat[i][j]);
    printf("\n");
  }
}
int maxx(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}
int main() {
  char king[11];
  int mat[26][26], n, f, l, i, j, len, temp, flag = 0;
  int max = -999;
  scanf("%d", &n);
  for (i = 0; i < 26; i++)
    for (j = 0; j < 26; j++) mat[i][j] = 0;
  for (i = 0; i < n; i++) {
    scanf("%s", king);
    len = strlen(king);
    f = king[0] - 'a';
    l = king[len - 1] - 'a';
    for (j = 0; j < 26; j++) {
      if (mat[j][f] > 0) {
        mat[j][l] = maxx(mat[j][l], mat[j][f] + len);
      }
    }
    if (mat[f][l] <= len) {
      mat[f][l] = len;
    }
  }
  for (i = 0; i < 26; i++) {
  }
  for (i = 0; i < 26; i++)
    if (mat[i][i] > max) max = mat[i][i];
  printf("%d\n", max);
  return 0;
}
