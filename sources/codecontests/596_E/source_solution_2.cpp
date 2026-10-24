#include <bits/stdc++.h>
using namespace std;
int a[210][210], ins[210][210], vis[210][210];
int has[210][210];
int p[10][2];
string st[210];
vector<pair<int, int> > graph[210][210];
int len;
char ss[1000010];
int sum[10];
int pre[40010][10];
int dfs(int x, int y) {
  int res = 0;
  for (auto e : graph[x][y]) res = max(res, dfs(e.first, e.second));
  if (res < len && st[x][y] == ss[res]) res++;
  return res;
}
int main() {
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 0; i < n; i++) cin >> st[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) a[i][j] = st[i][j] - '0';
  for (int i = 0; i < 10; i++) cin >> p[i][0] >> p[i][1];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (!vis[i][j]) {
        int x = i, y = j;
        while (!vis[x][y]) {
          int xx = x, yy = y;
          vis[x][y] = i * m + j + 1;
          int d = a[x][y];
          x += p[d][0];
          y += p[d][1];
          if (x < 0 || x >= n || y < 0 || y >= m) {
            ins[xx][yy] = 1;
            has[xx][yy] = 1 << a[xx][yy];
            break;
          }
        }
        if (x < 0 || x >= n || y < 0 || y >= m) continue;
        if (ins[x][y]) continue;
        if (vis[x][y] != i * m + j + 1) continue;
        int tt = 0;
        int mask = 0;
        while (!ins[x][y]) {
          tt++;
          mask |= 1 << a[x][y];
          ins[x][y] = 1;
          int d = a[x][y];
          x += p[d][0];
          y += p[d][1];
        }
        for (int k = 0; k < tt; k++) {
          has[x][y] = mask;
          int d = a[x][y];
          x += p[d][0];
          y += p[d][1];
        }
      }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (!ins[i][j]) {
        int d = a[i][j];
        int x = i + p[d][0];
        int y = j + p[d][1];
        if (x >= 0 && x < n && y >= 0 && y < m)
          graph[x][y].push_back(make_pair(i, j));
      }
  for (int o = 0; o < q; o++) {
    scanf("%s", ss);
    len = strlen(ss);
    memset(sum, 0, sizeof(sum));
    for (int i = 0; i < len; i++) sum[ss[i] - '0']++;
    for (int i = 0; i < min(n * m, len); i++) {
      memcpy(pre[i + 1], pre[i], sizeof(int) * 10);
      pre[i + 1][ss[i] - '0']++;
    }
    int ok = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        if (ins[i][j]) {
          int ret = dfs(i, j);
          int mask = 0;
          for (int k = 0; k < 10; k++)
            if (sum[k] > pre[ret][k]) mask |= 1 << k;
          ok = 1;
          for (int k = 0; k < 10; k++)
            if ((mask >> k & 1) && (~has[i][j] >> k & 1)) {
              ok = 0;
              break;
            }
          if (ok) break;
        }
      if (ok) break;
    }
    ok ? cout << "YES" << endl : cout << "NO" << endl;
  }
  return 0;
}
