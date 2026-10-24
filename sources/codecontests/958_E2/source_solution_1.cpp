#include <bits/stdc++.h>
using namespace std;
int n, k, dp[4][5010], t[500010], d[500010], p;
pair<int, int> A[500010];
bool b[500010];
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int main() {
  k = read(), n = read();
  for (int i = 1; i <= n; ++i) t[i] = read();
  sort(t + 1, t + n + 1);
  for (int i = 1; i < n; ++i)
    d[i] = A[i].first = t[i + 1] - t[i], A[i].second = i;
  sort(A + 1, A + n);
  for (int i = 1; i <= min(n, 3 * k); ++i) b[A[i].second] = 1;
  memset(dp, 100, sizeof(dp));
  for (int i = 0; i < 4; dp[i++][0] = 0)
    ;
  for (int i = 1; i < n; ++i) {
    if (!b[i]) {
      continue;
    }
    p++;
    for (int j = 1; j <= min(p, k); ++j)
      dp[p & 3][j] =
          min(dp[(p - 1) & 3][j], dp[(p - 1 - b[i - 1]) & 3][j - 1] + d[i]);
  }
  printf("%d\n", dp[p & 3][k]);
  return 0;
}
