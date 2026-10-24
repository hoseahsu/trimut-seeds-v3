#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10005;
const int MAXM = 5000005;
const int inf = 1e9;
int info[MAXM], fir[MAXM], to[MAXM], nxt[MAXM], c[MAXM], cnt = 1;
inline void link(int u, int v, int cc) {
  to[++cnt] = v;
  nxt[cnt] = fir[u];
  fir[u] = cnt;
  c[cnt] = cc;
  to[++cnt] = u;
  nxt[cnt] = fir[v];
  fir[v] = cnt;
  c[cnt] = 0;
}
int n, q, m, rt[MAXN], tot, S, T;
struct node {
  int x, l, r, v;
  inline bool operator<(const node &o) const { return x < o.x; }
} a[MAXN << 1];
int lc[MAXM], rc[MAXM], tag[MAXM];
inline void upd(int i) {
  if (!tag[lc[i]]) link(i, lc[i], inf);
  if (!tag[rc[i]]) link(i, rc[i], inf);
}
void build(int &i, int l, int r) {
  if (l == r) {
    i = l;
    return;
  }
  i = ++tot;
  int mid = (l + r) >> 1;
  build(lc[i], l, mid);
  build(rc[i], mid + 1, r);
  upd(i);
}
void ins(int &i, int l, int r, int x, int y, int v) {
  if (l == r) {
    tag[i] += v;
    return;
  }
  ++tot;
  lc[tot] = lc[i], rc[tot] = rc[i], tag[tot] = tag[i];
  i = tot;
  if (x <= l && r <= y) {
    tag[i] += v;
    upd(i);
    return;
  }
  int mid = (l + r) >> 1;
  if (x <= mid) ins(lc[i], l, mid, x, y, v);
  if (y > mid) ins(rc[i], mid + 1, r, x, y, v);
  upd(i);
}
int dis[MAXM];
queue<int> Q;
bool spfa() {
  memset(dis, -1, (tot + 1) << 2);
  dis[T] = 0;
  Q.push(T);
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    for (int i = fir[u], v; i; i = nxt[i])
      if (!~dis[v = to[i]] && c[i ^ 1]) dis[v] = dis[u] + 1, Q.push(v);
  }
  return ~dis[S];
}
int aug(int u, int Max) {
  if (u == T) return Max;
  int delta, re = 0;
  for (int &i = info[u], v; i; i = nxt[i])
    if (c[i] && dis[v = to[i]] + 1 == dis[u] &&
        (delta = aug(v, min(c[i], Max - re)))) {
      re += delta, c[i] -= delta, c[i ^ 1] += delta;
      if (Max == re) return Max;
    }
  return re;
}
int Maxflow() {
  int re = 0;
  while (spfa()) memcpy(info, fir, (tot + 1) << 2), re += aug(S, inf);
  return re;
}
int main() {
  scanf("%d%d", &n, &q);
  tot = 2 * n;
  for (int i = 1, X, Y, U, V; i <= q; ++i) {
    scanf("%d%d%d%d", &X, &Y, &U, &V);
    a[++m] = (node){Y, X, U, 1};
    a[++m] = (node){V + 1, X, U, -1};
  }
  sort(a + 1, a + m + 1);
  S = ++tot, T = ++tot;
  for (int i = 1; i <= n; ++i) link(S, n + i, 1), link(i, T, 1);
  build(rt[0], 1, n);
  for (int i = 1, j = 1; i <= n; ++i) {
    rt[i] = rt[i - 1];
    for (; j <= m && a[j].x == i; ++j) ins(rt[i], 1, n, a[j].l, a[j].r, a[j].v);
    if (!tag[rt[i]]) link(n + i, rt[i], inf);
  }
  printf("%d\n", Maxflow());
}
