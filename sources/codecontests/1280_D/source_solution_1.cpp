#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int to, nxt;
} edge[6666];
int head[3666], tot;
void addedge(int x, int y) {
  edge[++tot].to = y;
  edge[tot].nxt = head[x];
  head[x] = tot;
}
int n, m;
int a[3666], b[3666];
int f[3666][3666];
long long g[3666][3666];
int siz[3066], s[3066];
long long t[3066];
void dfs(int x, int fa) {
  siz[x] = 1;
  f[x][0] = 0;
  g[x][0] = b[x] - a[x];
  for (int i = head[x]; i; i = edge[i].nxt) {
    int y = edge[i].to;
    if (y == fa) continue;
    dfs(y, x);
    for (int j = siz[x] + siz[y]; j >= 0; j--) s[j] = -1e9, t[j] = -1e17;
    for (int j = siz[x]; j >= 0; j--) {
      for (int k = siz[y]; k >= 0; k--) {
        if (s[j + k] < f[x][j] + f[y][k] ||
            (s[j + k] == f[x][j] + f[y][k] && t[j + k] < g[x][j] + g[y][k]))
          s[j + k] = f[x][j] + f[y][k], t[j + k] = g[x][j] + g[y][k];
      }
    }
    siz[x] += siz[y];
    for (int j = siz[x]; j >= 0; j--) f[x][j] = s[j], g[x][j] = t[j];
  }
  for (int i = siz[x] - 1; i >= 0; i--) {
    int t = (g[x][i] > 0);
    if (f[x][i + 1] < f[x][i] + t ||
        (f[x][i + 1] == f[x][i] + t && g[x][i + 1] < 0))
      f[x][i + 1] = f[x][i] + t, g[x][i + 1] = 0;
  }
}
int main() {
  int _;
  scanf("%d", &_);
  while (_--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
    for (int i = 1; i <= n; i++) head[i] = 0;
    tot = 0;
    for (int i = 0; i <= n; i++)
      for (int j = 0; j <= n; j++) f[i][j] = -1e9, g[i][j] = -1e17;
    int x, y;
    for (int i = 1; i < n; i++) {
      scanf("%d%d", &x, &y);
      addedge(x, y);
      addedge(y, x);
    }
    dfs(1, 0);
    printf("%d\n", f[1][m - 1] + (g[1][m - 1] > 0));
  }
  return 0;
}
