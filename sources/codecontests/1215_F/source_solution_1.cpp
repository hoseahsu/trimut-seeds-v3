#include <bits/stdc++.h>
using namespace std;
template <typename T>
void __read(T &a) {
  cin >> a;
}
template <typename T, typename... Args>
void __read(T &a, Args &...args) {
  cin >> a;
  __read(args...);
}
constexpr long long M7 = 1000000007ll;
constexpr long long M9 = 1000000009ll;
constexpr long long MFFT = 998244353ll;
template <class T>
void outv(T &a) {
  for (auto &x : a) cout << x << ' ';
}
static mt19937 rnd(static_cast<unsigned>(
    chrono::steady_clock::now().time_since_epoch().count()));
template <class T>
static auto __super_speed__ = (ios_base::sync_with_stdio(0), cin.tie(0));
vector<int> x, was, order, cmp;
vector<vector<int>> g, rg;
void initial(int cnt) {
  x.assign(cnt, 0);
  g.assign(cnt, {});
  rg.assign(cnt, {});
  was.assign(cnt, 0);
  cmp.assign(cnt, -1);
  order.clear();
}
void dfs(int v) {
  was[v] = 1;
  for (auto &u : g[v]) {
    if (!was[u]) {
      dfs(u);
    }
  }
  order.push_back(v);
}
void rev_dfs(int v, int color) {
  cmp[v] = color;
  for (auto &u : rg[v]) {
    if (cmp[u] == -1) {
      rev_dfs(u, color);
    }
  }
}
void add_edge(int v, int u) {
  g[v].push_back(u);
  rg[u].push_back(v);
}
void add_or(int x1, int x2) {
  add_edge(x1 ^ 1, x2);
  add_edge(x2 ^ 1, x1);
}
int32_t main() {
  int n, p, M, m;
  __read(n, p, M, m);
  initial((p + M) * 2);
  for (int i = 0; i < n; ++i) {
    int x1, x2;
    __read(x1, x2);
    x1--, x2--;
    add_or(x1 * 2, x2 * 2);
  }
  for (int i = 0; i + 1 < M; ++i) {
    add_or((p + i) * 2, ((p + i + 1) * 2) ^ 1);
  }
  for (int i = 0; i < p; ++i) {
    int l, r;
    __read(l, r);
    add_or((p + l - 1) * 2, (i * 2) ^ 1);
    if (r != M) {
      add_or(((p + r) * 2) ^ 1, (i * 2) ^ 1);
    }
  }
  for (int i = 0; i < m; ++i) {
    int x1, x2;
    __read(x1, x2);
    x1--, x2--;
    add_or((x1 * 2) ^ 1, (x2 * 2) ^ 1);
  }
  for (int v = 0; v < g.size(); ++v) {
    if (!was[v]) {
      dfs(v);
    }
  }
  reverse((order).begin(), (order).end());
  int color = 0;
  for (auto &v : order) {
    if (cmp[v] == -1) {
      rev_dfs(v, color);
      color++;
    }
  }
  for (int i = 0; i < p + M; ++i) {
    if (cmp[(i * 2)] == cmp[(i * 2) ^ 1]) {
      cout << -1;
      return 0;
    }
  }
  for (int i = 0; i < p + M; ++i) {
    int j = 2 * i;
    if (cmp[j] < cmp[j ^ 1]) {
      j ^= 1;
    }
    x[j] = 1;
    x[j ^ 1] = 0;
  }
  vector<int> ans;
  int f = 0;
  for (int i = 0; i < p; ++i) {
    if (x[i * 2] == 1) {
      ans.push_back(i);
    }
  }
  for (int i = p; i < p + M; ++i) {
    if (x[i * 2] == 1) {
      f++;
    }
  }
  assert(f != 0);
  cout << ans.size() << ' ' << f << '\n';
  for (auto &v : ans) {
    cout << v + 1 << ' ';
  }
  return 0;
}
