#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  char c = getchar();
  long long f = 1, x = 0;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = x * 10 + (c - '0'), c = getchar();
  return x * f;
}
void MOD(int &x) {
  if (x >= 1000000007) x -= 1000000007;
}
int p[100010], u[100010];
void pre(int n) {
  for (int i = 2; i <= n; i++) {
    if (!u[i]) p[++p[0]] = i;
    for (int j = 1; j <= p[0] && i * p[j] <= n; j++) {
      u[i * p[j]] = 1;
      if (i % p[j] == 0) break;
    }
  }
}
int l = 1, nxt[100010], head[100010], to[100010], v[100010];
void ad(int x, int y, int z) {
  l++;
  nxt[l] = head[x];
  head[x] = l;
  to[l] = y;
  v[l] = z;
}
void add(int x, int y, int z) {
  ad(x, y, z);
  ad(y, x, 0);
}
int bg, ed;
int q[100010], d[100010];
bool bfs() {
  for (int i = 1; i <= ed; i++) d[i] = 0;
  int l = 1, r = 2;
  q[l] = bg;
  d[bg] = 1;
  while (l < r) {
    int x = q[l++];
    for (int i = head[x]; i; i = nxt[i]) {
      int c = to[i];
      if (d[c] || !v[i]) continue;
      d[c] = d[x] + 1;
      q[r++] = c;
    }
  }
  return d[ed];
}
int cur[100010];
int dfs(int x, int f) {
  if (x == ed || !f) return f;
  int u = 0;
  for (int i = cur[x]; i; i = nxt[i]) {
    int c = to[i];
    if (d[c] != d[x] + 1 || !v[i]) continue;
    int w = dfs(c, min(f - u, v[i]));
    u += w;
    v[i] -= w;
    v[i ^ 1] += w;
    if (v[i]) cur[x] = i;
    if (u == f) return f;
  }
  if (!u) d[x] = 0;
  return u;
}
int dinic() {
  int ans = 0;
  while (bfs()) {
    for (int i = 1; i <= ed; i++) cur[i] = head[i];
    ans += dfs(bg, (1 << 30));
  }
  return ans;
}
int a[100010];
int n, m;
int vis[100010], ans[210][210];
void get(int x) {
  vis[x] = 1;
  ans[m][++ans[m][0]] = x;
  for (int i = head[x]; i; i = nxt[i]) {
    int c = to[i];
    if (c > n || vis[c] || !v[i | 1]) continue;
    get(c);
    return;
  }
}
int main() {
  pre(2e4);
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i <= n; i++)
    if (a[i] & 1)
      for (int j = 1; j <= n; j++)
        if (i != j && !u[a[i] + a[j]])
          if (a[i] & 1) add(i, j, 1);
  bg = n + 1;
  ed = bg + 1;
  for (int i = 1; i <= n; i++) {
    if (a[i] & 1)
      add(bg, i, 2);
    else
      add(i, ed, 2);
  }
  if (dinic() != n) return puts("Impossible"), 0;
  for (int i = 1; i <= n; i++)
    if (!vis[i]) {
      m++;
      get(i);
    }
  printf("%d\n", m);
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j <= ans[i][0]; j++) printf("%d ", ans[i][j]);
    puts("");
  }
}
