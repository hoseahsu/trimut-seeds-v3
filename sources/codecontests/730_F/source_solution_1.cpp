#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5005;
const int MAXM = 10005;
template <typename T>
inline void read(T &AKNOI) {
  T x = 0, flag = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') flag = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  AKNOI = flag * x;
}
int n, b, a[MAXN];
int dp[2][MAXM], ds[MAXN][MAXM], ans[MAXN];
void solve() {
  read(n);
  read(b);
  memset(dp[0], 0x3f, sizeof(dp[0]));
  dp[0][0] = 0;
  int pre = 0, cur = 1, up = 0;
  for (int i = 1, x, sum = 0; i <= n; ++i) {
    read(x);
    a[i] = x;
    memset(dp[cur], 0x3f, sizeof(dp[cur]));
    for (int j = 0; j <= up; ++j) {
      int p = dp[pre][j];
      if (p > sum) continue;
      int left = b - (sum - p) + j;
      for (int k = 0; k <= left && k <= (x >> 1); ++k) {
        int t = j + (x - k) / 10;
        if (p + x - k < dp[cur][t]) {
          dp[cur][t] = p + x - k;
          ds[i][t] = k;
        }
      }
    }
    sum += x;
    up += x / 10;
    swap(pre, cur);
  }
  int ansp = 0;
  for (int i = 1; i <= up; ++i) {
    if (dp[pre][i] < dp[pre][ansp]) {
      ansp = i;
    }
  }
  printf("%d\n", dp[pre][ansp]);
  for (int i = n; i >= 1; --i) {
    ans[i] = ds[i][ansp];
    ansp -= (a[i] - ds[i][ansp]) / 10;
  }
  for (int i = 1; i <= n; ++i) {
    printf("%d ", ans[i]);
  }
}
int main() {
  solve();
  return 0;
}
