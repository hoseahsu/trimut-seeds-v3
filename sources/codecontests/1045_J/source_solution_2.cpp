#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int maxm = maxn * 50;
int dfn[maxn], top[maxn], siz[maxn], son[maxn], dtot(0);
int fdfn[maxn], n;
struct Seg_ment {
  int t[maxm], lson[maxm], rson[maxm], s[maxm];
  int tot;
  Seg_ment(void) { tot = 0; }
  void pushup(int p) { s[p] = s[lson[p]] + s[rson[p]]; }
  int merge(int u, int v) {
    if (!u || !v) return u + v;
    int now = ++tot;
    lson[now] = merge(lson[u], lson[v]);
    rson[now] = merge(rson[u], rson[v]);
    pushup(now);
    return now;
  }
  void Insert(int &p, int l, int r, int pos) {
    int now = ++tot;
    lson[now] = lson[p], rson[now] = rson[p], p = now;
    if (l == r) return s[p] = 1, void();
    if (pos <= ((l + r) >> 1))
      Insert(lson[p], l, ((l + r) >> 1), pos);
    else
      Insert(rson[p], ((l + r) >> 1) + 1, r, pos);
    pushup(p);
  }
  int Ask(int p, int l, int r, int ll, int rr) {
    if (!p || ll > rr) return 0;
    if (ll <= l && r <= rr) return s[p];
    int res(0);
    if (ll <= ((l + r) >> 1)) res += Ask(lson[p], l, ((l + r) >> 1), ll, rr);
    if (((l + r) >> 1) < rr) res += Ask(rson[p], ((l + r) >> 1) + 1, r, ll, rr);
    return res;
  }
} T;
int pS[maxn], Sp[maxn << 1];
struct SAM {
  int rt[maxn << 1];
  vector<int> vc[maxn << 1];
  struct Node {
    int len, fa, c[26];
  } d[maxn << 1];
  int tot;
  SAM(void) { tot = pS[1] = 1; }
  void Insert(int c, int las, int id) {
    int p = las, np = ++tot;
    d[np].len = d[p].len + 1;
    for (; p && !d[p].c[c]; p = d[p].fa) d[p].c[c] = np;
    if (!p)
      d[np].fa = 1;
    else {
      int q = d[p].c[c];
      if (d[q].len == d[p].len + 1)
        d[np].fa = q;
      else {
        int nq = ++tot;
        d[nq] = d[q];
        d[nq].len = d[p].len + 1;
        d[np].fa = d[q].fa = nq;
        for (; p && d[p].c[c] == q; p = d[p].fa) d[p].c[c] = nq;
      }
    }
    pS[id] = np, Sp[np] = id;
  }
  void dfs(int p, int pre) {
    for (int i = 0; i < vc[p].size(); ++i) {
      int u = vc[p][i];
      if (u == pre) continue;
      dfs(u, p);
      rt[p] = T.merge(rt[p], rt[u]);
    }
    if (Sp[p]) T.Insert(rt[p], 1, n, dfn[Sp[p]]);
  }
  void build() {
    for (int i = 1; i <= tot; ++i) vc[i].clear();
    for (int i = 1; i <= tot; ++i) vc[d[i].fa].push_back(i);
    dfs(1, 0);
  }
} sa;
struct Edge {
  int to, next, w;
} edg[maxn << 1];
int head[maxn], cnt(0);
void add(int u, int v, int w) {
  edg[++cnt] = (Edge){v, head[u], w}, head[u] = cnt;
}
int dep[maxn], fa[maxn], a[maxn];
void dfs1(int p, int pre) {
  siz[p] = 1;
  fa[p] = pre;
  dep[p] = dep[pre] + 1;
  for (int i = head[p]; i; i = edg[i].next) {
    int to = edg[i].to, w = edg[i].w;
    if (to == pre) continue;
    a[to] = w;
    sa.Insert(a[to], pS[p], to);
    dfs1(to, p);
    siz[p] += siz[to];
    if (siz[son[p]] < siz[to]) son[p] = to;
  }
}
void dfs2(int p, int pre, int topf) {
  top[p] = topf;
  dfn[p] = ++dtot;
  fdfn[dtot] = p;
  if (son[p]) dfs2(son[p], p, topf);
  for (int i = head[p]; i; i = edg[i].next) {
    int to = edg[i].to;
    if (to == son[p] || to == pre) continue;
    dfs2(to, p, to);
  }
}
int Lca(int u, int v) {
  while (top[u] != top[v]) {
    if (dep[top[u]] < dep[top[v]]) swap(u, v);
    u = fa[top[u]];
  }
  return dep[u] < dep[v] ? u : v;
}
int Ask(int u, int ed, int d) {
  if (dep[u] - dep[ed] + 1 <= d) return -1;
  while (top[u] != top[ed]) {
    if (dep[top[u]] <= d + dep[ed]) break;
    u = fa[top[u]];
  }
  return fdfn[dfn[top[u]] + (d - dep[top[u]] + dep[ed])];
}
int Solve(int u, int ed, int p) {
  if (ed == -1) return 0;
  int ans(0);
  while (top[u] != top[ed]) {
    ans += T.Ask(p, 1, n, dfn[top[u]], dfn[u]);
    u = fa[top[u]];
  }
  ans += T.Ask(p, 1, n, dfn[ed], dfn[u]);
  return ans;
}
char s[maxn];
int nxt[maxn];
signed main() {
  int i, j;
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (i = 1; i < n; ++i) {
    int u, v;
    char c;
    cin >> u >> v >> c;
    add(u, v, c - 'a'), add(v, u, c - 'a');
  }
  dfs1(1, 0);
  dfs2(1, 0, 1);
  sa.build();
  int Q;
  cin >> Q;
  while (Q--) {
    int u, v;
    cin >> u >> v >> (s + 1);
    int ln = strlen(s + 1);
    int edu, edv, lca = Lca(u, v);
    edu = Ask(u, lca, ln), edv = Ask(v, lca, ln);
    int posu(1), posv(1);
    for (i = ln; i >= 1; --i) posu = sa.d[posu].c[s[i] - 'a'];
    for (i = 1; i <= ln; ++i) posv = sa.d[posv].c[s[i] - 'a'];
    int ans(0);
    ans = Solve(u, edu, sa.rt[posu]) + Solve(v, edv, sa.rt[posv]);
    u = (edu == -1 ? u : fa[edu]), v = (edv == -1 ? v : fa[edv]);
    string s1 = "", s2 = "";
    for (; u != lca; u = fa[u]) s1 += (char)(a[u] + 'a');
    for (; v != lca; v = fa[v]) s2 += (char)(a[v] + 'a');
    reverse(s2.begin(), s2.end());
    string S = " " + s1 + s2;
    int ln1 = S.size() - 1;
    j = 0;
    nxt[1] = 0;
    for (i = 2; i <= ln; ++i) {
      while (j && s[j + 1] != s[i]) j = nxt[j];
      if (s[j + 1] == s[i]) ++j;
      nxt[i] = j;
    }
    j = 0;
    for (i = 1; i <= ln1; ++i) {
      while (j && s[j + 1] != S[i]) j = nxt[j];
      if (s[j + 1] == S[i]) ++j;
      if (j == ln) ++ans, j = nxt[j];
    }
    printf("%d\n", ans);
  }
  return 0;
}
