#include <bits/stdc++.h>
const int maxn = 1000100;
long long result, n, m;
long long deg[maxn + 1];
int main() {
  long long i, j, k, x, y;
  scanf("%I64d%I64d", &n, &m);
  for (i = 1; i <= n; ++i) deg[i] = 0;
  for (i = 1; i <= m; ++i) {
    scanf("%I64d%I64d", &x, &y);
    ++deg[x];
    ++deg[y];
  }
  result = 0;
  for (i = 1; i <= n; ++i) {
    result += deg[i] * (n - 1 - deg[i]);
  }
  result = n * (n - 1) * (n - 2) / 6 - result / 2;
  printf("%I64d\n", result);
  return 0;
}
