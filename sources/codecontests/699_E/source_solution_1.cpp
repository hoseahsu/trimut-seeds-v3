#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const int maxn = 20;
double P[maxn];
int n, k, m;
double dp[1 << maxn];
double ans[maxn];
int main(void) {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%lf", P + i);
    if (P[i] > eps) m++;
  }
  m = min(m, k);
  dp[0] = 1;
  for (int mask = 0; mask < (1 << n); mask++) {
    double rest = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if ((mask >> i) & 1) {
        cnt++;
      } else {
        rest += P[i];
      }
    }
    if (cnt >= m) {
      if (cnt > m) {
        dp[mask] = 0;
      } else {
        for (int i = 0; i < n; i++) {
          if ((mask >> i) & 1) {
            ans[i] += dp[mask];
          }
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (!((mask >> i) & 1)) {
        dp[mask | (1 << i)] += dp[mask] * P[i] / rest;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%.9f ", ans[i]);
  }
  return 0;
}
