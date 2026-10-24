#include <bits/stdc++.h>
using namespace std;
int n;
const int maxn = 5005;
int sum[maxn], dp[maxn][maxn / 2][2], tmp[maxn / 2][2];
vector<int> a[maxn];
void dfs(int u, int fa) {
  sum[u] = 1;
  if (a[u].size() == 1)
    dp[u][0][1] = dp[u][1][0] = 0;
  else
    dp[u][0][1] = dp[u][0][0] = 0;
  for (int i = 0; i < a[u].size(); i++) {
    int v = a[u][i];
    if (v == fa) continue;
    dfs(v, u);
    memset(tmp, 0x3f, sizeof tmp);
    for (int i = 0; i <= sum[u]; i++) {
      for (int j = 0; j <= sum[v] && i + j < maxn / 2; j++) {
        tmp[i + j][1] = min(tmp[i + j][1], dp[u][i][1] + dp[v][j][1]);
        tmp[i + j][1] = min(tmp[i + j][1], dp[u][i][1] + dp[v][j][0] + 1);
        tmp[i + j][0] = min(tmp[i + j][0], dp[u][i][0] + dp[v][j][0]);
        tmp[i + j][0] = min(tmp[i + j][0], dp[u][i][0] + dp[v][j][1] + 1);
      }
    }
    sum[u] += sum[v];
    for (int i = 0; i <= sum[u] + sum[v] && i < maxn / 2; i++) {
      dp[u][i][0] = tmp[i][0];
      dp[u][i][1] = tmp[i][1];
    }
  }
}
int main() {
  scanf("%d", &n);
  int x, y;
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &x, &y);
    a[x].push_back(y);
    a[y].push_back(x);
  }
  int rt, m = 0;
  for (int i = 1; i <= n; i++)
    if (a[i].size() > 1) {
      rt = i;
    } else
      m++;
  memset(dp, 0x3f, sizeof dp);
  dfs(rt, -1);
  printf("%d\n", min(dp[rt][m / 2][0], dp[rt][m / 2][1]));
  return 0;
}
