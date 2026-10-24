#include <bits/stdc++.h>
using namespace std;
int n, k, a[100003], b[100003];
int main(void) {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  int lo, mid, hi;
  lo = 1;
  hi = 10000;
  while (hi >= lo) {
    mid = (lo + hi) / 2;
    int need = 0;
    for (int i = 1; i <= n; i++) need += max(0, mid * a[i] - b[i]);
    if (need <= k)
      lo = mid + 1;
    else
      hi = mid - 1;
  }
  printf("%d\n", hi);
}
