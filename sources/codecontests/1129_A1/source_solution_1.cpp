#include <bits/stdc++.h>
using namespace std;
int n, m, num[20010], d[20010], ans[20010];
int main() {
  int i, j;
  memset(num, 0, sizeof(num));
  memset(ans, 0, sizeof(ans));
  for (i = 0; i < 20010; i++) d[i] = 50010;
  cin >> n >> m;
  for (i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    num[x]++;
    if (y > x)
      y = y - x;
    else
      y = n - x + y;
    d[x] = min(d[x], y);
  }
  for (i = 1; i <= n; i++) {
    int pace = 0;
    for (j = i; j <= n; j++) {
      if (num[j] != 0) {
        ans[i] = max(ans[i], pace + (num[j] - 1) * n + d[j]);
      }
      pace++;
    }
    for (j = 1; j < i; j++) {
      if (num[j] != 0) {
        ans[i] = max(ans[i], pace + (num[j] - 1) * n + d[j]);
      }
      pace++;
    }
  }
  for (i = 1; i <= n; i++) cout << ans[i] << " ";
  return 0;
}
