#include <bits/stdc++.h>
using namespace std;
const int MAX = (int)1e5 + 5;
int a[MAX], n;
int main() {
  long long ans = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int k = 1; k < n; k++) {
    int j;
    for (j = 0; (1 << j) + k <= n; j++)
      ;
    j--;
    ans += a[k];
    a[(1 << j) + k] += a[k];
    printf("%I64d\n", ans);
  }
  return 0;
}
