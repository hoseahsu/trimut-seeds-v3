#include <bits/stdc++.h>
using namespace std;
const int N = 55, mod = 1000000007;
struct _two {
  int a, b;
} edge[N * N], aedge[N * N];
int vis[N * N][N];
int n, m;
int st[N], ast[N], qu[N + N + N], aqu[N + N + N];
int f[N + N][N][N], t[N + N][N][N], g[N + N][N];
vector<_two> tail[N], head[N];
void Init() {
  scanf("%d%d", &n, &m);
  int x, y, tot = 0;
  memset(st, 0, sizeof(st));
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    ++tot;
    edge[tot] = (_two){y, st[x]};
    st[x] = tot;
    aedge[tot] = (_two){x, ast[y]};
    ast[y] = tot;
    scanf("%d", &vis[tot][0]);
    for (int j = 1; j <= vis[tot][0]; j++) scanf("%d", &vis[tot][j]);
  }
}
int dfs(int x) {
  int num = 0;
  while (num < qu[0] && qu[0] <= n + n) {
    ++num;
    bool flag = 0;
    for (int i = st[x]; i; i = edge[i].b)
      if (edge[i].a == qu[num]) {
        flag = 1;
        for (int j = 1; j <= vis[i][0]; j++) qu[++qu[0]] = vis[i][j];
        break;
      }
    if (!flag) return -1;
    x = qu[num];
  }
  if (qu[0] > n + n)
    return -1;
  else
    return qu[0];
}
int adfs(int x) {
  int num = 0;
  while (num < aqu[0] && aqu[0] <= n + n) {
    ++num;
    bool flag = 0;
    for (int i = ast[x]; i; i = aedge[i].b)
      if (aedge[i].a == aqu[num]) {
        flag = 1;
        for (int j = vis[i][0]; j >= 1; j--) aqu[++aqu[0]] = vis[i][j];
        break;
      }
    if (!flag) return -1;
    x = aqu[num];
  }
  if (aqu[0] > n + n)
    return -1;
  else
    return aqu[0];
}
void Work() {
  memset(f, 0, sizeof(f));
  for (int i = 1; i <= n; i++) {
    head[i].clear();
    tail[i].clear();
  }
  for (int i = 1; i <= n; i++)
    for (int j = st[i]; j; j = edge[j].b) {
      for (int k = 2; k <= vis[j][0]; k++)
        if (vis[j][k] == edge[j].a && vis[j][k - 1] == i) {
          aqu[0] = k - 2;
          for (int l = k - 2; l >= 1; l--) aqu[k - 1 - l] = vis[j][l];
          int num1 = adfs(i);
          qu[0] = vis[j][0] - k;
          for (int l = k + 1; l <= vis[j][0]; l++) qu[l - k] = vis[j][l];
          int num2 = dfs(edge[j].a);
          if (num1 == -1 || num2 == -1) break;
          if (!num1) aqu[num1] = i;
          if (!num2) qu[num2] = edge[j].a;
          if (num1 + num2 + 1 <= n + n)
            f[num1 + num2 + 1][aqu[num1]][qu[num2]]++;
          break;
        }
      if (vis[j][1] == edge[j].a) {
        qu[0] = vis[j][0] - 1;
        for (int l = 2; l <= vis[j][0]; l++) qu[l - 1] = vis[j][l];
        int num = dfs(edge[j].a);
        if (num != -1) {
          if (!num) qu[num] = edge[j].a;
          tail[i].push_back((_two){qu[num], num + 1});
        }
      }
      if (vis[j][vis[j][0]] == i) {
        aqu[0] = vis[j][0] - 1;
        for (int l = vis[j][0] - 1; l >= 1; l--) aqu[vis[j][0] - l] = vis[j][l];
        int num = adfs(i);
        if (num != -1) {
          if (!num) aqu[num] = i;
          head[edge[j].a].push_back((_two){aqu[num], num + 1});
        }
      }
    }
  memset(t, 0, sizeof(t));
  memset(g, 0, sizeof(g));
  for (int l = 1; l <= n + n; l++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) {
        if (!f[l][i][j]) continue;
        for (vector<_two>::iterator k = tail[j].begin(); k != tail[j].end();
             k++)
          if (k->b + l <= n + n)
            f[l + k->b][i][k->a] = (f[l + k->b][i][k->a] + f[l][i][j]) % mod;
      }
  for (int l = 1; l <= n + n; l++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) {
        if (!f[l][i][j]) continue;
        for (vector<_two>::iterator k = head[i].begin(); k != head[i].end();
             k++)
          if (k->b + l <= n + n)
            f[l + k->b][k->a][j] = (f[l + k->b][k->a][j] + f[l][i][j]) % mod;
      }
  for (int l = 1; l <= n + n; l++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) {
        if (!f[l][i][j]) continue;
        g[l][j] = (g[l][j] + f[l][i][j]) % mod;
        for (int k = ast[i]; k; k = aedge[k].b)
          if (!vis[k][0])
            t[l + 1][aedge[k].a][j] =
                (t[l + 1][aedge[k].a][j] + f[l][i][j]) % mod;
      }
  for (int l = 1; l <= n + n; l++)
    for (int i = 1; i <= n; i++)
      if (g[l][i])
        for (int k = 1; k <= n; k++)
          for (int l1 = 1; l1 <= n + n - l; l1++)
            if (t[l1][i][k])
              g[l + l1][k] =
                  ((long long)g[l][i] * t[l1][i][k] + g[l + l1][k]) % mod;
  for (int i = 1; i <= n + n; i++) {
    int sum = 0;
    for (int j = 1; j <= n; j++) sum = (sum + g[i][j]) % mod;
    printf("%d\n", sum);
  }
}
int main() {
  Init();
  Work();
  return 0;
}
