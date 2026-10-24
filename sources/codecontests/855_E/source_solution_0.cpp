#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
long long dp[64][1025];
long long ans[N];
int n, q, base, t, a[100], B[N];
long long L[N], R[N];
long long dfs(int cnt, int mask, int limit, int zero) {
  if (!zero && !limit && dp[cnt][mask] != -1) return dp[cnt][mask];
  if (cnt == 0) return (mask == 0) && (!zero);
  long long res = 0;
  if (limit) {
    if (zero) {
      for (int i = 1; i < a[cnt]; i++)
        res += dfs(cnt - 1, mask ^ (1 << i), 0, 0);
      res += dfs(cnt - 1, mask ^ (1 << a[cnt]), 1, 0);
      res += dfs(cnt - 1, mask, 0, 1);
    } else {
      for (int i = 0; i < a[cnt]; i++)
        res += dfs(cnt - 1, mask ^ (1 << i), 0, 0);
      res += dfs(cnt - 1, mask ^ (1 << a[cnt]), 1, 0);
    }
  } else {
    if (zero) {
      for (int i = 1; i < base; i++) res += dfs(cnt - 1, mask ^ (1 << i), 0, 0);
      res += dfs(cnt - 1, mask, 0, 1);
    } else {
      for (int i = 0; i < base; i++) res += dfs(cnt - 1, mask ^ (1 << i), 0, 0);
    }
  }
  if (!limit && !zero) dp[cnt][mask] = res;
  return res;
}
long long cal(long long x) {
  if (x <= 0) return 0;
  t = 0;
  while (x) {
    a[++t] = x % base;
    x /= base;
  }
  return dfs(t, 0, 1, 1);
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%d %I64d %I64d", B + i, L + i, R + i);
  }
  for (int i = 2; i <= 10; i++) {
    base = i;
    for (int j = 0; j < 64; j++)
      for (int k = 0; k < 1 << i; k++) dp[j][k] = -1;
    for (int j = 1; j <= n; j++) {
      if (B[j] != i) continue;
      ans[j] = cal(R[j]) - cal(L[j] - 1);
    }
  }
  for (int i = 1; i <= n; i++) printf("%I64d\n", ans[i]);
}
