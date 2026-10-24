#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 2, INF = 0x3f3f3f3f;
struct kruskal {
  int u, v, w, id;
  friend bool operator<(const kruskal &a, const kruskal &b) {
    return a.w < b.w;
  }
} kr[maxn];
int head[maxn], cnt;
struct EDGE {
  int v, nxt, w, id;
  EDGE() {}
  EDGE(int a, int b, int c, int d) { v = a, nxt = b, w = c, id = d; }
} e[maxn << 1];
bool inm[maxn];
int n, m, fa[maxn], ans[maxn], anc[maxn][19], mx[maxn][19], dep[maxn], up[maxn];
inline int read() {
  int x = 0;
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x;
}
void add(int u, int v, int w, int id) {
  e[cnt] = EDGE(v, head[u], w, id);
  head[u] = cnt++;
}
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void dfs(int p, int f, int d) {
  dep[p] = dep[f] + 1, anc[p][0] = f, mx[p][0] = d;
  for (int i = 1; i <= 18; i++)
    anc[p][i] = anc[anc[p][i - 1]][i - 1],
    mx[p][i] = max(mx[p][i - 1], mx[anc[p][i - 1]][i - 1]);
  for (int i = head[p]; ~i; i = e[i].nxt) {
    int to = e[i].v;
    if (to == f) continue;
    up[to] = e[i].id, dfs(to, p, e[i].w);
  }
}
int lca(int x, int y, int &d) {
  d = 0;
  if (dep[x] < dep[y]) swap(x, y);
  for (int i = 18; i >= 0; i--) {
    if (dep[anc[x][i]] >= dep[y]) {
      d = max(d, mx[x][i]);
      x = anc[x][i];
    }
  }
  if (x == y) return x;
  for (int i = 18; i >= 0; i--) {
    if (anc[x][i] ^ anc[y][i]) {
      d = max(d, max(mx[x][i], mx[y][i]));
      x = anc[x][i], y = anc[y][i];
    }
  }
  d = max(d, max(mx[x][0], mx[y][0]));
  return anc[x][0];
}
void modify(int x, int lca, int w) {
  x = find(x);
  while (dep[x] > dep[lca]) {
    ans[up[x]] = min(ans[up[x]], w);
    int y = find(anc[x][0]);
    fa[x] = y;
    x = find(x);
  }
}
int main() {
  while (~scanf("%d%d", &n, &m)) {
    memset(head, -1, sizeof(head));
    memset(inm, 0, sizeof(inm));
    cnt = 0;
    for (register int i = 1; i <= n; i++) fa[i] = i;
    for (register int i = 1; i <= m; i++)
      kr[i].id = i, kr[i].u = read(), kr[i].v = read(), kr[i].w = read();
    sort(kr + 1, kr + m + 1);
    for (register int i = 1; i <= m; ++i) {
      int u = kr[i].u, v = kr[i].v;
      u = find(u), v = find(v);
      if (u ^ v) {
        fa[u] = v;
        inm[i] = true;
        add(kr[i].u, kr[i].v, kr[i].w, kr[i].id);
        add(kr[i].v, kr[i].u, kr[i].w, kr[i].id);
      }
    }
    dfs(1, 0, 0);
    memset(ans, INF, sizeof(ans));
    for (register int i = 1; i <= n; ++i) fa[i] = i;
    for (register int i = 1; i <= m; ++i) {
      if (inm[i]) continue;
      int u = kr[i].u, v = kr[i].v, f = lca(u, v, ans[kr[i].id]);
      --ans[kr[i].id];
      modify(u, f, kr[i].w - 1);
      modify(v, f, kr[i].w - 1);
    }
    for (int i = 1; i <= m; i++) printf("%d\n", ans[i] == INF ? -1 : ans[i]);
  }
  return 0;
}
