#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int f = 1, ans = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    ans = ans * 10 + c - '0';
    c = getchar();
  }
  return f * ans;
}
const int MAXN = 4e5 + 11;
int N, M, T[MAXN];
vector<int> vec[MAXN];
struct Segment {
  int Maxn[MAXN << 2];
  void Modify(int k, int l, int r, int ps, int w) {
    if (l == r) {
      Maxn[k] = w;
      return;
    }
    int mid = (l + r) >> 1;
    if (ps <= mid)
      Modify(k << 1, l, mid, ps, w);
    else
      Modify(k << 1 | 1, mid + 1, r, ps, w);
    Maxn[k] = max(Maxn[k << 1], Maxn[k << 1 | 1]);
    return;
  }
  int Query(int k, int l, int r, int x, int y) {
    if (x <= l && r <= y) return Maxn[k];
    int mid = (l + r) >> 1, res = 0;
    if (x <= mid) res = max(res, Query(k << 1, l, mid, x, y));
    if (mid < y) res = max(res, Query(k << 1 | 1, mid + 1, r, x, y));
    return res;
  }
} S;
struct Edge {
  int u, v, tim;
} E[MAXN];
bool cmp(Edge x1, Edge x2) { return x1.tim > x2.tim; }
struct Union {
  int f[MAXN];
  void init() {
    for (int i = 1; i <= 2 * N; i++) f[i] = i;
    return;
  }
  int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
} U;
pair<int, int> Que[MAXN];
int dfn[MAXN], siz[MAXN], INF = INT_MAX, MM[MAXN], Val[MAXN], dep[MAXN], tot,
                          fa[MAXN][21], cnt, Q;
void dfs(int u, int fath) {
  dep[u] = dep[fath] + 1;
  fa[u][0] = fath;
  if (u <= N) siz[u] = 1, dfn[u] = ++dfn[0];
  for (int i = 1; (1 << i) <= dep[u]; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
  for (auto v : vec[u])
    if (v != fath) dfs(v, u), siz[u] += siz[v], dfn[u] = min(dfn[u], dfn[v]);
  return;
}
int Qmax(int u, int t) {
  for (int i = 20; i >= 0; i--)
    if (T[fa[u][i]] >= t && fa[u][i]) u = fa[u][i];
  return u;
}
int main() {
  N = read(), M = read(), Q = read();
  U.init();
  tot = N;
  for (int i = 1; i <= N; i++) Val[i] = read(), MM[Val[i]] = i;
  for (int i = 1; i <= M; i++) E[i].u = read(), E[i].v = read(), E[i].tim = INF;
  int ps = 0;
  for (int i = 1; i <= Q; i++) {
    int opt = read(), u = read();
    if (opt == 1)
      Que[++cnt].first = u, Que[cnt].second = ps;
    else
      E[u].tim = ps = i;
  }
  sort(E + 1, E + M + 1, cmp);
  for (int i = 1; i <= M; i++) {
    int u = E[i].u, v = E[i].v, tim = E[i].tim;
    if (U.find(u) == U.find(v)) continue;
    u = U.find(u), v = U.find(v);
    ++tot;
    U.f[u] = U.f[v] = tot;
    T[tot] = tim;
    vec[tot].push_back(u), vec[tot].push_back(v);
  }
  memset(dfn, 127 / 3, sizeof(dfn));
  dfn[0] = 0;
  for (int i = 1; i <= tot; i++)
    if (U.find(i) == i) dfs(i, 0);
  for (int i = 1; i <= N; i++) S.Modify(1, 1, N, dfn[i], Val[i]);
  for (int i = 1; i <= cnt; i++) {
    int u = Que[i].first, tim = Que[i].second + 1;
    int G = Qmax(u, tim), L = dfn[G], R = dfn[G] + siz[G] - 1, WW;
    printf("%d\n", WW = S.Query(1, 1, N, L, R));
    if (!WW) continue;
    S.Modify(1, 1, N, dfn[MM[WW]], 0);
  }
  return 0;
}
