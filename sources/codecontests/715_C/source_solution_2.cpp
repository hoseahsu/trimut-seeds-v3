#include <bits/stdc++.h>
using namespace std;
int read() {
  int f = 1, x = 0;
  char c = getchar();
  while (c < '0' || '9' < c) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while ('0' <= c && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return f * x;
}
void Exgcd(int a, int b, long long &x, long long &y) {
  if (!b) {
    x = 1, y = 0;
    return;
  }
  Exgcd(b, a % b, y, x), y -= a / b * x;
  return;
}
struct Edge {
  int v, nxt, w;
} edge[2 * 500000 + 5];
int ecnt, head[500000 + 5];
void Addedge(int u, int v, int w) {
  edge[++ecnt] = (Edge){v, head[u], w}, head[u] = ecnt;
  edge[++ecnt] = (Edge){u, head[v], w}, head[v] = ecnt;
  return;
}
int n;
bool vis[500000 + 5];
int sum, mx, root, siz[500000 + 5], dep[500000 + 5];
long long m, ans, p10[500000 + 5], inv10[500000 + 5], down[500000 + 5],
    up[500000 + 5];
void GetRoot(int u, int fa) {
  siz[u] = 1;
  int Maxson = 0;
  for (int i = head[u]; i; i = edge[i].nxt) {
    int v = edge[i].v, w = edge[i].w;
    if (v == fa || vis[v]) continue;
    dep[v] = dep[u] + 1;
    up[v] = (up[u] * 10 + w) % m, down[v] = (down[u] + p10[dep[u]] * w) % m;
    GetRoot(v, u), siz[u] += siz[v];
    Maxson = max(Maxson, siz[v]);
  }
  Maxson = max(Maxson, sum - siz[u]);
  if (Maxson < mx) mx = Maxson, root = u;
  return;
}
int lca;
map<long long, long long> Map1, Map2;
void Addson(int u, int fa, int val) {
  if (val == 1) {
    long long tmp =
        (up[lca] * p10[dep[lca]] % m + m -
         up[u] * p10[2 * dep[lca]] % m * inv10[dep[u]] % m + down[lca]) %
        m;
    if (Map1.count(tmp)) ans += Map1[tmp];
    tmp = (up[lca] * inv10[dep[lca]] % m + m -
           (down[u] - down[lca] + m) % m * inv10[2 * dep[lca]] % m) %
          m;
    if (Map2.count(tmp)) ans += Map2[tmp];
  } else {
    Map1[down[u]]++;
    Map2[up[u] * inv10[dep[u]] % m]++;
  }
  for (int i = head[u]; i; i = edge[i].nxt) {
    int v = edge[i].v;
    if (v == fa || vis[v]) continue;
    Addson(v, u, val);
  }
  return;
}
void Cal(int u) {
  Map1.clear(), Map2.clear(), lca = u;
  for (int i = head[u]; i; i = edge[i].nxt) {
    int v = edge[i].v;
    if (vis[v]) continue;
    Addson(v, u, 1);
    Addson(v, u, 0);
  }
  long long tmp =
      (up[lca] * p10[dep[lca]] % m + m -
       up[u] * p10[2 * dep[lca]] % m * inv10[dep[u]] % m + down[lca]) %
      m;
  if (Map1.count(tmp)) ans += Map1[tmp];
  tmp = (up[lca] * inv10[dep[lca]] % m + m -
         (down[u] - down[lca] + m) % m * inv10[2 * dep[lca]] % m) %
        m;
  if (Map2.count(tmp)) ans += Map2[tmp];
  return;
}
void DFS(int u) {
  vis[u] = 1;
  Cal(u);
  for (int i = head[u]; i; i = edge[i].nxt) {
    int v = edge[i].v;
    if (vis[v]) continue;
    sum = siz[v], mx = 0x3f3f3f3f;
    GetRoot(v, 0);
    dep[root] = 0, up[root] = down[root] = 0;
    GetRoot(root, 0);
    DFS(root);
  }
  return;
}
long long inv;
int main() {
  n = read(), m = read();
  long long y;
  Exgcd(10, m, inv, y);
  inv = (inv % m + m) % m;
  p10[0] = inv10[0] = 1;
  for (int i = 1; i <= 2 * n; i++)
    p10[i] = p10[i - 1] * 10 % m, inv10[i] = inv10[i - 1] * inv % m;
  for (int i = 2; i <= n; i++) {
    int u = read() + 1, v = read() + 1, w = read();
    Addedge(u, v, w);
  }
  sum = n, mx = 0x3f3f3f3f;
  GetRoot(1, 0);
  dep[root] = 0, up[root] = down[root] = 0;
  GetRoot(root, 0);
  DFS(root);
  printf("%lld\n", ans);
  return 0;
}
