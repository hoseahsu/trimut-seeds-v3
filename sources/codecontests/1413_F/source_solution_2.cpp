#include <bits/stdc++.h>
using namespace std;
int read() {
  char ch = getchar();
  int x = 0, fl = 1;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') fl = -1;
  for (; isdigit(ch); ch = getchar()) x = (x << 3) + (x << 1) + (ch - '0');
  return x * fl;
}
const int NN = 500000 + 17;
void open() {
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
}
void OK() { printf("OK\n"); }
int n, q;
int c[NN];
int ans[NN];
vector<pair<int, int> > e[NN];
pair<int, int> ep[NN];
struct Tree {
  int fa[NN], dep[NN], d[NN], ll[NN], rr[NN], rev[NN];
  int tim;
  struct node {
    int w[2];
  } t[NN << 2];
  int tag[NN << 2];
  node merge(node a, node b) {
    node c;
    c.w[0] = max(a.w[0], b.w[0]);
    c.w[1] = max(a.w[1], b.w[1]);
    return c;
  }
  void set_tag(int rt) {
    tag[rt] ^= 1;
    swap(t[rt].w[0], t[rt].w[1]);
  }
  void psd(int rt) {
    if (tag[rt]) {
      set_tag(rt << 1);
      set_tag(rt << 1 | 1);
      tag[rt] = 0;
    }
  }
  void build(int rt, int l, int r) {
    if (l == r) {
      t[rt].w[d[rev[l]]] = dep[rev[l]];
      return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    t[rt] = merge(t[rt << 1], t[rt << 1 | 1]);
  }
  void flip(int rt, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) {
      set_tag(rt);
      return;
    }
    psd(rt);
    int mid = (l + r) >> 1;
    if (ll <= mid) flip(rt << 1, l, mid, ll, rr);
    if (rr > mid) flip(rt << 1 | 1, mid + 1, r, ll, rr);
    t[rt] = merge(t[rt << 1], t[rt << 1 | 1]);
  }
  void dfs(int x, int ff) {
    fa[x] = ff;
    dep[x] = dep[ff] + 1;
    ll[x] = ++tim;
    rev[tim] = x;
    for (int i = 0, top = e[x].size(); i < top; i++) {
      int y = e[x][i].first, z = e[x][i].second;
      if (y != ff) {
        d[y] = (d[x] + z) & 1;
        dfs(y, x);
      }
    }
    rr[x] = tim;
  }
  void work(int root) {
    dfs(root, 0);
    build(1, 1, n);
    for (int i = 1; i <= q; i++) {
      int x = ep[c[i]].first, y = ep[c[i]].second;
      if (fa[x] == y) swap(x, y);
      flip(1, 1, n, ll[y], rr[y]);
      ans[i] = max(ans[i], t[1].w[0]);
    }
  }
} tx, ty;
int mx, pos, px, py;
void dfs(int x, int dep, int ff) {
  if (dep > mx) mx = dep, pos = x;
  for (int i = 0, top = e[x].size(); i < top; i++) {
    int y = e[x][i].first;
    if (y != ff) dfs(y, dep + 1, x);
  }
}
void get_path() {
  dfs(1, 0, 0);
  px = pos;
  mx = -1;
  dfs(px, 0, 0);
  py = pos;
  tx.work(px);
  ty.work(py);
}
int main() {
  n = read();
  for (int i = 1; i < n; i++) {
    int x = read(), y = read(), z = read();
    e[x].push_back(make_pair(y, z));
    e[y].push_back(make_pair(x, z));
    ep[i] = make_pair(x, y);
  }
  q = read();
  for (int i = 1; i <= q; i++) c[i] = read();
  get_path();
  for (int i = 1; i <= q; i++) {
    ans[i]--;
    printf("%d\n", ans[i]);
  }
  return 0;
}
