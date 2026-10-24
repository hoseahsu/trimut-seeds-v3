#include <bits/stdc++.h>
using namespace std;
int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};
int a[500], c[500];
int main() {
  int t = 0, z = 0, len;
  int n, k = 0, m = 0, bam = 0, dan = 0, ans = 0;
  scanf("%d %d", &n, &m);
  for (int l = 1; l < n + 1; l++) {
    scanf("%d", &a[l]);
    a[l] += a[l - 1];
  }
  for (int l = 0; l < m; l++) {
    int x, y;
    scanf("%d %d", &x, &y);
    c[l] = a[y] - a[x - 1];
  }
  k = 0;
  sort(c, c + m);
  for (int l = m - 1; l > -1; l--) {
    k += c[l];
    ans = max(ans, k);
  }
  printf("%d", ans);
  return 0;
}
