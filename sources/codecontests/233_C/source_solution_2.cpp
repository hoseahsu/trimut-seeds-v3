#include <bits/stdc++.h>
using namespace std;
const int inf = (1 << 30);
const int N = 100005;
int n, k;
int g[105][105];
int main() {
  int i, j, t, cas = 0;
  memset(g, 0, sizeof(g));
  scanf("%d", &k);
  for (n = 3; n <= 100; n++) {
    if ((n) * (n - 1) * (n - 2) / 6 > k) break;
  }
  n--;
  k -= (n) * (n - 1) * (n - 2) / 6;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      if (i == j) continue;
      g[i][j] = 1;
    }
  }
  while (k) {
    for (i = 2;; i++) {
      if ((i) * (i - 1) / 2 > k) break;
    }
    i--;
    n++;
    for (j = 1; j <= i; j++) g[j][n] = g[n][j] = 1;
    k -= (i) * (i - 1) / 2;
  }
  printf("%d\n", n);
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      printf("%d", g[i][j]);
    }
    puts("");
  }
  return 0;
}
