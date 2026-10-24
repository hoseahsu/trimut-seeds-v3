#include <bits/stdc++.h>
using namespace std;
const int block_size = 320;
const long long mod = 1e9 + 7;
const long long inf = 1e9 + 7;
const long double eps = 1e-9;
const double PI = atan(1) * 4;
template <typename T>
inline int sign(const T& a) {
  if (a < 0) return -1;
  if (a > 0) return 1;
  return 0;
}
template <typename T>
inline void in(T& x) {
  x = 0;
  T f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x *= f;
}
long long twop(int x) { return 1LL << x; }
template <typename A, typename B>
inline void in(A& x, B& y) {
  in(x);
  in(y);
}
template <typename A, typename B, typename C>
inline void in(A& x, B& y, C& z) {
  in(x);
  in(y);
  in(z);
}
template <typename A, typename B, typename C, typename D>
inline void in(A& x, B& y, C& z, D& d) {
  in(x);
  in(y);
  in(z);
  in(d);
}
template <class T>
void upd(T& a, T b) {
  a = max(a, b);
}
template <int maxn>
struct dsu {
  int f[maxn];
  dsu() { init(); }
  void init() {
    for (long long i = 0; i < maxn; i++) f[i] = i;
  }
  int fa(int c) {
    if (c == f[c]) return c;
    return f[c] = fa(f[c]);
  }
  void merge(int a, int b) {
    a = fa(a);
    b = fa(b);
    if (a == b) return;
    f[fa(a)] = fa(b);
  }
  bool same(int a, int b) { return fa(a) == fa(b); }
};
const int maxn = 300010;
int n, m;
vector<int> adj[maxn];
int tot = 1;
int dfn[maxn], low[maxn];
dsu<maxn> bcj;
void tarjan(int cur, int fa) {
  dfn[cur] = low[cur] = tot++;
  for (auto i : adj[cur]) {
    if (i != fa) {
      if (!dfn[i]) {
        tarjan(i, cur);
        low[cur] = min(low[cur], low[i]);
        if (low[i] <= dfn[cur]) bcj.merge(cur, i);
      } else {
        low[cur] = min(low[cur], dfn[i]);
        bcj.merge(cur, i);
      }
    }
  }
}
void read() {
  in(n, m);
  for (long long i = 0; i < m; i++) {
    int u, v;
    in(u, v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
}
vector<int> groups[maxn];
int rmo[maxn];
void work() {
  for (long long i = 1; i < n + 1; i++) {
    if (!dfn[i]) tarjan(i, 0);
  }
  for (long long i = 1; i < n + 1; i++) groups[bcj.fa(i)].push_back(i);
  for (long long i = 1; i < n + 1; i++) rmo[i] = n;
  for (long long i = 1; i < n + 1; i++) {
    if (((int)groups[i].size()) >= 2) {
      rmo[groups[i][0]] = groups[i].back() - 1;
    }
  }
  for (long long i = n - 1; i >= 1; i--) {
    rmo[i] = min(rmo[i], rmo[i + 1]);
  }
}
long long answer[maxn];
struct query {
  int l, r, id;
  bool operator<(const query& o) const { return r < o.r; }
};
query qs[maxn];
struct SegTree {
  static const int maxn = 300010;
  struct node {
    int l, r;
    long long sum, lazy;
    long long get_sum() { return sum + lazy * (r - l + 1); }
  };
  node no[maxn * 4];
  void push_up(int ind) {
    no[ind].sum = no[(ind << 1)].get_sum() + no[(ind << 1 | 1)].get_sum();
  }
  void push_down(int ind) {
    no[(ind << 1)].lazy += no[ind].lazy;
    no[(ind << 1 | 1)].lazy += no[ind].lazy;
    no[ind].lazy = 0;
  }
  void build(int l, int r, int ind) {
    no[ind].l = l;
    no[ind].r = r;
    if (l == r) {
      no[ind].lazy = no[ind].sum = 0;
    } else {
      int mid = (l + r) / 2;
      build(l, mid, (ind << 1));
      build(mid + 1, r, (ind << 1 | 1));
      push_up(ind);
    }
  }
  void update(int l, int r, int ind, int val) {
    if (l > no[ind].r || r < no[ind].l) return;
    if (l <= no[ind].l && no[ind].r <= r) {
      no[ind].lazy += val;
    } else {
      push_down(ind);
      update(l, r, (ind << 1), val);
      update(l, r, (ind << 1 | 1), val);
      push_up(ind);
    }
  }
  void query(int l, int r, int ind, long long& ans) {
    if (l > no[ind].r || r < no[ind].l) return;
    if (l <= no[ind].l && no[ind].r <= r) {
      ans += no[ind].get_sum();
    } else {
      push_down(ind);
      query(l, r, (ind << 1), ans);
      query(l, r, (ind << 1 | 1), ans);
      push_up(ind);
    }
  }
};
SegTree tree;
void solve() {
  tree.build(1, n, 1);
  int cnt = 0;
  in(cnt);
  for (long long i = 0; i < cnt; i++) in(qs[i].l, qs[i].r);
  for (long long i = 0; i < cnt; i++) qs[i].id = i;
  sort(qs, qs + cnt);
  int l = 1, r = 1;
  tree.update(1, 1, 1, 1);
  for (long long i = 0; i < cnt; i++) {
    while (r < qs[i].r) {
      r++;
      while (rmo[l] < r) l++;
      tree.update(l, r, 1, 1);
    }
    answer[qs[i].id] = 0;
    tree.query(qs[i].l, qs[i].r, 1, answer[qs[i].id]);
  }
  for (long long i = 0; i < cnt; i++) printf("%lld\n", answer[i]);
}
int main() {
  read();
  work();
  solve();
  return 0;
}
