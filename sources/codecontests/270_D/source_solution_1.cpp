#include <bits/stdc++.h>
using namespace std;
int const maxsize = 5010;
int dp[maxsize];
int a[maxsize];
int n, m;
int main() {
  scanf("%d%d", &n, &m);
  double p;
  for (int i = 0; i < n; i++) scanf("%d%lf", &a[i], &p);
  int res = 0;
  for (int i = 0; i < n; i++) {
    dp[i] = 1;
    for (int j = 0; j < i; j++)
      if (a[j] <= a[i]) dp[i] = max(dp[i], dp[j] + 1);
    res = max(res, dp[i]);
  }
  printf("%d\n", n - res);
  return 0;
}
