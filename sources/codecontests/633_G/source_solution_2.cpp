#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct node {
  int l, r;
  int laz;
  bitset<1010> s;
} tree[N << 2];
int n, m, q;
int a[N];
int p[N], in[N], out[N], cnt;
vector<int> v[N];
void dfs(int u, int fa) {
  in[u] = ++cnt;
  p[cnt] = u;
  for (int i = 0; i < v[u].size(); i++) {
    int to = v[u][i];
    if (to == fa) continue;
    dfs(to, u);
  }
  out[u] = cnt;
}
void pushup(int cur) { tree[cur].s = tree[cur << 1].s | tree[cur << 1 | 1].s; }
void build(int l, int r, int cur) {
  tree[cur].l = l;
  tree[cur].r = r;
  tree[cur].laz = 0;
  if (l == r) {
    tree[cur].s[a[p[l]] % m] = 1;
    return;
  }
  int mid = (r + l) >> 1;
  build(l, mid, cur << 1);
  build(mid + 1, r, cur << 1 | 1);
  pushup(cur);
}
void pushdown(int cur) {
  if (tree[cur].laz) {
    tree[cur << 1].laz += tree[cur].laz;
    tree[cur << 1].laz %= m;
    tree[cur << 1 | 1].laz += tree[cur].laz;
    tree[cur << 1 | 1].laz %= m;
    tree[cur << 1].s = (tree[cur << 1].s << tree[cur].laz) |
                       (tree[cur << 1].s >> (m - tree[cur].laz));
    tree[cur << 1 | 1].s = (tree[cur << 1 | 1].s << tree[cur].laz) |
                           (tree[cur << 1 | 1].s >> (m - tree[cur].laz));
    tree[cur].laz = 0;
  }
}
void update(int pl, int pr, int l, int r, int cur, int val) {
  if (pl <= l && r <= pr) {
    tree[cur].laz += val;
    tree[cur].laz %= m;
    tree[cur].s = (tree[cur].s << val) | (tree[cur].s >> (m - val));
    return;
  }
  pushdown(cur);
  int mid = (r + l) >> 1;
  if (pl <= mid) update(pl, pr, l, mid, cur << 1, val);
  if (pr > mid) update(pl, pr, mid + 1, r, cur << 1 | 1, val);
  pushup(cur);
}
bitset<1010> query(int pl, int pr, int l, int r, int cur) {
  if (pl <= l && r <= pr) {
    return tree[cur].s;
  }
  pushdown(cur);
  int mid = (r + l) >> 1;
  bitset<1010> s(0);
  if (pl <= mid) s |= query(pl, pr, l, mid, cur << 1);
  if (pr > mid) s |= query(pl, pr, mid + 1, r, cur << 1 | 1);
  return s;
}
bitset<1010> prime;
void init() {
  prime[0] = 1;
  prime[1] = 1;
  for (int i = 2; i <= 1000; i++) {
    if (prime[i] == 0) {
      for (int j = i + i; j <= 1000; j += i) prime[j] = 1;
    }
  }
  prime.flip();
}
int main() {
  init();
  scanf("%d%d", &n, &m);
  for (int i = m; i <= 1009; i++) prime[i] = 0;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int x, y;
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);
  }
  dfs(1, 0);
  build(1, n, 1);
  int op;
  scanf("%d", &q);
  while (q--) {
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d%d", &x, &y);
      y %= m;
      update(in[x], out[x], 1, n, 1, y);
    } else {
      scanf("%d", &x);
      bitset<1010> s = query(in[x], out[x], 1, n, 1);
      s = s & prime;
      printf("%d\n", s.count());
    }
  }
  return 0;
}
