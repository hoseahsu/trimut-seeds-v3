#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
const int LIM = 300;
int n, m, h[maxn], ecnt;
struct enode {
  int v, n;
  enode() {}
  enode(int _v, int _n) : v(_v), n(_n) {}
} e[maxn << 1];
inline void addedge(int u, int v) {
  ecnt++;
  e[ecnt] = enode(v, h[u]);
  h[u] = ecnt;
}
int ans[maxn], acnt, val[maxn], vis[maxn], flag, inS[maxn];
void dfs(int u) {
  vis[u] = 1;
  inS[u] = 1;
  for (int i = h[u]; ~i; i = e[i].n) {
    int v = e[i].v;
    if (!vis[v]) {
      dfs(v);
    } else if (!inS[v])
      flag = 0;
  }
  inS[u] = 0;
}
inline bool check(int r) {
  memset(vis, 0, (n + 5) * sizeof(int));
  memset(inS, 0, (n + 5) * sizeof(int));
  flag = 1;
  dfs(r);
  return flag;
}
int dfn[maxn], low[maxn], tim, tid[maxn], tag[maxn];
void dfs1(int u) {
  dfn[u] = low[u] = ++tim;
  tid[tim] = u;
  vis[u] = 1;
  for (int i = h[u]; ~i; i = e[i].n) {
    int v = e[i].v;
    if (!vis[v]) {
      dfs1(v);
      low[u] = min(low[u], low[v]);
      tag[u] += tag[v];
    } else {
      low[u] = min(low[u], dfn[v]);
      tag[u]++;
      tag[v]--;
    }
  }
  val[u] = (tag[u] <= 1);
}
void dfs2(int u) {
  vis[u] = 1;
  val[u] &= val[tid[low[u]]];
  for (int i = h[u]; ~i; i = e[i].n) {
    int v = e[i].v;
    if (vis[v]) continue;
    dfs2(v);
  }
}
int lis[maxn];
inline void solve() {
  srand(time(NULL));
  scanf("%d%d", &n, &m);
  ecnt = 0;
  memset(h, -1, (n + 5) * sizeof(int));
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    addedge(u, v);
  }
  int r = -1;
  for (int i = 1; i <= n; i++) lis[i] = i;
  random_shuffle(lis + 1, lis + n + 1);
  for (int i = 1; i <= LIM; i++) {
    r = lis[i];
    if (check(r)) break;
    r = -1;
  }
  if (r == -1) {
    puts("-1");
    return;
  }
  tim = 0;
  memset(vis, 0, (n + 5) * sizeof(int));
  memset(tag, 0, (n + 5) * sizeof(int));
  memset(val, 0, (n + 5) * sizeof(int));
  dfs1(r);
  memset(vis, 0, (n + 5) * sizeof(int));
  dfs2(r);
  acnt = 0;
  for (int i = 1; i <= n; i++)
    if (val[i]) ans[++acnt] = i;
  if (acnt * 5 < n)
    puts("-1");
  else {
    for (int i = 1; i < acnt; i++) printf("%d ", ans[i]);
    printf("%d\n", ans[acnt]);
  }
}
int main() {
  int cas;
  scanf("%d", &cas);
  while (cas--) {
    solve();
  }
  return 0;
}
