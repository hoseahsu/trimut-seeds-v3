#include <bits/stdc++.h>
using namespace std;
int n, k;
int main() {
  scanf("%d %d", &n, &k);
  if (k > n / 3) return puts("-1"), 0;
  int m = 3 * k, st;
  if (k & 1) {
    printf("1 1 2 1 2 3 3 2 3 ");
    st = 4;
  } else
    printf("1 1 2 1 2 2 "), st = 3;
  while (st < k) {
    printf("%d %d %d %d %d %d ", st, st, st + 1, st, st + 1, st + 1);
    st += 2;
  }
  for (int i = m; i < n; i++) printf("1 ");
  puts("");
}
