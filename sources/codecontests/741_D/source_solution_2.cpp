#include <bits/stdc++.h>
using namespace std;
int n, cnt, tim;
int dep[500000 + 10];
int to[500000 + 10], nxt[500000 + 10], w[500000 + 10], head[500000 + 10];
int low[500000 + 10], dfn[500000 + 10], id[500000 + 10], ans[500000 + 10];
int size[500000 + 10], hson[500000 + 10], dis[500000 + 10], f[(1 << 22) + 10];
void add(int u, int v, int w1) {
  to[++cnt] = v;
  nxt[cnt] = head[u];
  w[cnt] = w1;
  head[u] = cnt;
}
void dfs1(int x, int ff) {
  size[x] = 1;
  dfn[x] = ++tim;
  id[tim] = x;
  for (int i = head[x]; i; i = nxt[i]) {
    int tox = to[i];
    if (tox == ff) continue;
    dep[tox] = dep[x] + 1;
    dis[tox] = dis[x] ^ w[i];
    dfs1(tox, x);
    size[x] += size[tox];
    if (size[hson[x]] < size[tox]) hson[x] = tox;
  }
  low[x] = tim;
}
void dfs2(int x, int ff, int op) {
  for (int i = head[x]; i; i = nxt[i]) {
    int tox = to[i];
    if (tox == ff || tox == hson[x]) continue;
    dfs2(tox, x, 0);
    ans[x] = max(ans[x], ans[tox]);
  }
  if (hson[x]) {
    dfs2(hson[x], x, 1);
    ans[x] = max(ans[x], ans[hson[x]]);
  }
  if (f[dis[x]]) ans[x] = max(ans[x], f[dis[x]] - dep[x]);
  for (int i = 0; i < 22; i++)
    if (f[dis[x] ^ (1 << i)])
      ans[x] = max(ans[x], f[dis[x] ^ (1 << i)] - dep[x]);
  f[dis[x]] = max(f[dis[x]], dep[x]);
  for (int e = head[x]; e; e = nxt[e]) {
    int tox = to[e];
    if (tox == ff || tox == hson[x]) continue;
    for (int i = dfn[tox]; i <= low[tox]; i++) {
      if (f[dis[id[i]]])
        ans[x] = max(ans[x], f[dis[id[i]]] + dep[id[i]] - 2 * dep[x]);
      for (int j = 0; j < 22; j++)
        if (f[dis[id[i]] ^ (1 << j)])
          ans[x] =
              max(ans[x], f[dis[id[i]] ^ (1 << j)] + dep[id[i]] - 2 * dep[x]);
    }
    for (int i = dfn[tox]; i <= low[tox]; i++)
      f[dis[id[i]]] = max(f[dis[id[i]]], dep[id[i]]);
  }
  if (!op)
    for (int i = dfn[x]; i <= low[x]; i++) f[dis[id[i]]] = 0;
}
int main() {
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    int ff;
    char s[4];
    scanf("%d%s", &ff, s + 1);
    add(ff, i, 1 << (s[1] - 'a'));
  }
  dfs1(1, 0);
  dfs2(1, 0, 0);
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  printf("\n");
  return 0;
}
