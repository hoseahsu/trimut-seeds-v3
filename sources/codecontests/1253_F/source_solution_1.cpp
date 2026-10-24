#include <bits/stdc++.h>
using namespace std;
const int ONE = 2000005;
const long long INF = 1ll << 60;
int get() {
  int res = 1, Q = 1;
  char c;
  while ((c = getchar()) < 48 || c > 57)
    if (c == '-') Q = -1;
  if (Q) res = c - 48;
  while ((c = getchar()) >= 48 && c <= 57) res = res * 10 + c - 48;
  return res * Q;
}
int n, m, k, Q;
int nxt[ONE], first[ONE], go[ONE], tot;
long long w[ONE];
int x, y, num;
long long val;
struct power {
  int x, y;
  long long val;
  friend bool operator<(const power &a, const power &b) {
    return a.val < b.val;
  }
} a[ONE];
void Add(int u, int v, long long e) {
  nxt[++tot] = first[u], first[u] = tot, go[tot] = v, w[tot] = e;
  nxt[++tot] = first[v], first[v] = tot, go[tot] = u, w[tot] = e;
}
long long dist[ONE];
bool vis[ONE];
priority_queue<pair<long long, int>> q;
void Dijkstra() {
  for (int i = 1; i <= k; i++) q.emplace(0, i);
  for (int i = k + 1; i <= n; i++) dist[i] = INF;
  while (!q.empty()) {
    int u = q.top().second;
    q.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    for (int e = first[u]; e; e = nxt[e]) {
      int v = go[e];
      if (dist[v] > dist[u] + w[e])
        dist[v] = dist[u] + w[e], q.emplace(-dist[v], v);
    }
  }
}
int siz[ONE], son[ONE], top[ONE], fat[ONE], Dep[ONE];
void Dfs1(int u, int fa) {
  siz[u] = 1, fat[u] = fa, Dep[u] = Dep[fa] + 1;
  for (int e = first[u]; e; e = nxt[e]) {
    int v = go[e];
    if (v == fa) continue;
    Dfs1(v, u);
    siz[u] += siz[v];
    if (siz[v] > siz[son[u]]) son[u] = v;
  }
}
void Dfs2(int u, int fa) {
  if (int v = son[u]) top[v] = top[u], Dfs2(v, u);
  for (int e = first[u]; e; e = nxt[e]) {
    int v = go[e];
    if (v == fa || v == son[u]) continue;
    Dfs2(top[v] = v, u);
  }
}
int LCA(int u, int v) {
  while (top[u] != top[v]) {
    int &x = Dep[top[u]] > Dep[top[v]] ? u : v;
    x = fat[top[x]];
  }
  return Dep[u] < Dep[v] ? u : v;
}
int f[ONE];
int Find(int x) {
  if (f[x] == x) return x;
  return f[x] = Find(f[x]);
}
int now;
long long value[ONE];
void Kruskal() {
  num = 0;
  for (int u = 1; u <= n; u++)
    for (int e = first[u]; e; e = nxt[e])
      a[++num] = (power){u, go[e], w[e] + dist[u] + dist[go[e]]};
  sort(a + 1, a + num + 1);
  tot = 0;
  for (int i = 1; i <= (n << 1) + 1; i++) f[i] = i, first[i] = 0;
  now = n;
  for (int i = 1; i <= num; i++) {
    int fx = Find(a[i].x), fy = Find(a[i].y);
    if (fx != fy) {
      value[++now] = a[i].val;
      f[fx] = f[fy] = now;
      Add(now, fx, 0), Add(now, fy, 0);
    }
  }
}
int main() {
  cin >> n >> m >> k >> Q;
  for (int i = 1; i <= m; i++) {
    scanf("%d %d %lld", &x, &y, &val);
    Add(x, y, val);
  }
  Dijkstra();
  Kruskal();
  top[now] = now;
  Dfs1(now, 0);
  Dfs2(now, 0);
  while (Q--) {
    scanf("%d %d", &x, &y);
    printf("%lld\n", value[LCA(x, y)]);
  }
}
