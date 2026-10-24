#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int w = 1, s = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    s = s * 10 + ch - '0';
    ch = getchar();
  }
  return w * s;
}
const int N = 3000;
struct Edge {
  int v, nxt;
} e[(N << 1) + 3];
int fe[N + 3];
int fa[N + 3];
int sz[N + 3];
long long a[N + 3];
pair<int, long long> f[N + 3][N + 3], g[N + 3];
int n, m, en;
void addedge(int u, int v) {
  en++;
  e[en].v = v;
  e[en].nxt = fe[u];
  fe[u] = en;
}
void update(pair<int, long long> &x, pair<int, long long> y) {
  if (y.first > x.first) {
    x = y;
  } else if (y.first == x.first) {
    x.second = max(x.second, y.second);
  }
}
void dfs(int u) {
  sz[u] = 1;
  f[u][1] = make_pair(0, a[u]);
  for (int o = fe[u]; o; o = e[o].nxt) {
    int v = e[o].v;
    if (v == fa[u]) continue;
    fa[v] = u;
    dfs(v);
    for (int i = 1; i <= sz[u] + sz[v] && i <= m; i++) {
      g[i] = make_pair(-1, 0);
    }
    for (int i = 1; i <= sz[u] && i <= m; i++) {
      for (int j = 1; j <= sz[v] && j <= m; j++) {
        if (i + j - 1 <= m) {
          update(g[i + j - 1], make_pair(f[u][i].first + f[v][j].first,
                                         f[u][i].second + f[v][j].second));
        }
        if (i + j <= m) {
          update(g[i + j],
                 make_pair(f[u][i].first + f[v][j].first + (f[v][j].second > 0),
                           f[u][i].second));
        }
      }
    }
    sz[u] += sz[v];
    for (int i = 1; i <= sz[u] && i <= m; i++) {
      f[u][i] = g[i];
    }
  }
}
int main() {
  int T;
  scanf("%d", &T);
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= N; j++) f[i][j] = make_pair(-1, 0);
  }
  while (T--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
      int x;
      scanf("%d", &x);
      a[i] = -x;
    }
    for (int i = 1; i <= n; i++) {
      int x;
      scanf("%d", &x);
      a[i] += x;
    }
    for (int i = 1; i < n; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      addedge(u, v);
      addedge(v, u);
    }
    dfs(1);
    printf("%d\n", f[1][m].first + (f[1][m].second > 0));
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= m; j++) f[i][j] = make_pair(-1, 0);
    }
    for (int i = 1; i <= n; i++) fe[i] = fa[i] = sz[i] = a[i] = 0;
    for (int i = 1; i <= en; i++) e[i].v = e[i].nxt = 0;
    en = 0;
  }
  return 0;
}
