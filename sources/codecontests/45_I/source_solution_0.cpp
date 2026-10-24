#include <bits/stdc++.h>
int cmp(const void *n1, const void *n2) {
  return (*((int *)n1)) - (*((int *)n2));
}
int main() {
  int ar[100], n, neg = 0, qna = 0;
  scanf("%d", &n);
  for (long long i = 0; i < n; i++) {
    scanf("%d", ar + i);
  }
  qsort(ar, n, sizeof(int), cmp);
  if (ar[0] > 0) {
    for (long long i = 0; i < n; i++) {
      printf("%d ", ar[i]);
    }
    return 0;
  }
  for (int i = 0; ar[i] < 0; i++) neg++;
  if ((neg % 2) == 1) neg--;
  for (long long i = 0; i < neg; i++) {
    printf("%d ", ar[i]);
    qna = 1;
  }
  for (long long i = 0; i < n; i++) {
    if (ar[i] > 0) {
      printf("%d ", ar[i]);
      qna = 1;
    }
  }
  if (!qna) printf("%d", ar[n - 1]);
  return 0;
}
