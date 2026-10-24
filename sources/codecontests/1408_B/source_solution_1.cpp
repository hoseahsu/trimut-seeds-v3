#include <bits/stdc++.h>
const int MAX_N = 100;
int n, k;
int a[MAX_N + 10];
int upper_div(int a, int b) { return (a - 1) / b + 1; }
int main() {
  int tn;
  scanf("%d", &tn);
  while (tn--) {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    int cnt = 0;
    for (int i = 2; i <= n; ++i)
      if (a[i] != a[i - 1]) ++cnt;
    --k;
    if (cnt == 0)
      printf("%d\n", 1);
    else if (k == 0)
      printf("%d\n", -1);
    else
      printf("%d\n", upper_div(cnt, k));
  }
  return 0;
}
