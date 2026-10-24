#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(
    (unsigned)chrono::system_clock::now().time_since_epoch().count());
const long double PI = acosl(-1);
const int nmax = 5e5 + 10;
int vals[nmax];
int ans[nmax];
vector<int> adj[nmax];
int st[nmax], clk = 0;
int arr[nmax];
int who[nmax];
bool vis[nmax];
void dfs(int u) {
  vis[u] = true;
  st[u] = ++clk;
  arr[clk] = vals[u];
  who[clk] = u;
  for (int v : adj[u]) {
    dfs(v);
  }
}
int master[nmax], sz[nmax];
void init(int n) {
  for (int i = 1; i <= n; i++) master[i] = i, sz[i] = 1;
}
int fnd(int u) {
  if (master[u] == u) return u;
  return fnd(master[u]);
}
stack<pair<int, int>> history;
int unite(int a, int b) {
  a = fnd(a), b = fnd(b);
  if (sz[a] < sz[b]) swap(a, b);
  if (a != b) sz[a] += sz[b];
  history.push(make_pair(a, b));
  master[b] = a;
  if (a != b) adj[a].push_back(b);
  return a;
}
void undo() {
  int a, b;
  tie(a, b) = history.top();
  history.pop();
  master[b] = b;
  if (a != b) sz[a] -= sz[b];
  return;
}
int tree[4 * nmax];
void build(int id, int l, int r) {
  if (l == r) {
    tree[id] = l;
    return;
  }
  int mid = (l + r) / 2;
  build((id << 1), l, mid);
  build(((id << 1) | 1), mid + 1, r);
  tree[id] = ((arr[tree[(id << 1)]] <= arr[tree[((id << 1) | 1)]])
                  ? tree[((id << 1) | 1)]
                  : tree[(id << 1)]);
}
int query(int id, int l, int r, int L, int R) {
  if (R < l || r < L) return 0;
  if (L <= l && r <= R) return tree[id];
  int mid = (l + r) / 2;
  int p = query((id << 1), l, mid, L, R);
  int q = query(((id << 1) | 1), mid + 1, r, L, R);
  return ((arr[p] <= arr[q]) ? q : p);
}
void update(int id, int l, int r, int k, int x) {
  if (l == r) {
    arr[l] = x;
    return;
  }
  int mid = (l + r) / 2;
  if (k <= mid)
    update((id << 1), l, mid, k, x);
  else
    update(((id << 1) | 1), mid + 1, r, k, x);
  tree[id] = ((arr[tree[(id << 1)]] <= arr[tree[((id << 1) | 1)]])
                  ? tree[((id << 1) | 1)]
                  : tree[(id << 1)]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int n, m, q;
  cin >> n >> m >> q;
  vector<pair<int, int>> edges;
  vector<pair<int, int>> queries;
  vector<bool> used(m);
  init(n);
  for (int i = 1; i <= n; i++) {
    cin >> vals[i];
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    edges.emplace_back(u, v);
  }
  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    queries.emplace_back(x, y);
    if (x == 2) used[y - 1] = true;
  }
  int rt = -1;
  for (int i = 0; i < m; i++) {
    if (!used[i]) rt = unite(edges[i].first, edges[i].second);
  }
  for (int i = q - 1; i >= 0; i--) {
    if (queries[i].first == 2) {
      int id = queries[i].second - 1;
      rt = unite(edges[id].first, edges[id].second);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (fnd(i) == i) dfs(i);
  }
  build(1, 1, n);
  for (int i = 0; i < q; i++) {
    if (queries[i].first == 2) {
      undo();
    } else {
      int u = queries[i].second;
      u = fnd(u);
      int vid = query(1, 1, n, st[u], st[u] + sz[u] - 1);
      cout << arr[vid] << "\n";
      if (arr[vid] != 0) update(1, 1, n, vid, 0);
    }
  }
  return 0;
}
