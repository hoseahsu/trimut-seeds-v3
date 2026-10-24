#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e6 + 10;
int T;
int a[maxn], b[maxn], sum, n, ans;
int vis[maxn];
int main() {
  scanf("%d", &n);
  sum = 0;
  ans = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int maxa = 1; maxa <= 30; ++maxa) {
    sum = 0;
    for (int i = 1; i <= n; ++i) {
      if (maxa < a[i]) {
        sum = 0;
        continue;
      }
      sum += a[i];
      if (sum <= 0) {
        sum = 0;
      }
      ans = max(ans, sum - maxa);
    }
  }
  printf("%d\n", ans);
  return 0;
}
