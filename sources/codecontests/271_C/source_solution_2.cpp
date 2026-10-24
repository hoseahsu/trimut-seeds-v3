#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, n;
  scanf("%d %d", &n, &k);
  if (n < (3 * k)) {
    printf("%d", -1);
    return 0;
  }
  for (int i = 0; i < 2 * k; i++) {
    printf("%d ", i % k + 1);
  }
  printf("%d ", k);
  for (int i = 1; i < k; i++) {
    printf("%d ", i);
  }
  for (int i = 3 * k + 1; i <= n; i++) {
    printf("%d ", 1);
  }
  return 0;
}
