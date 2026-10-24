#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)5e5 + 228;
const char nxtl = '\n';
const int mod = (int)1e9 + 7;
const double eps = (double)1e-9;
template <typename T>
inline bool updmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
inline bool updmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
int lvl[MAXN], tin[MAXN], tout[MAXN];
int n, m, timer;
vector<int> g[MAXN];
void dfs(int x = 1) {
  tin[x] = ++timer;
  for (auto &to : g[x]) {
    lvl[to] = lvl[x] + 1;
    dfs(to);
  }
  tout[x] = timer;
}
void norm(int &x) {
  x %= mod;
  if (x < 0) x += mod;
  if (x >= mod) x -= mod;
}
int f[2][MAXN];
void add(int type, int pos, int val) {
  for (pos; pos <= n; pos += (pos & -pos)) {
    f[type][pos] += val;
    norm(f[type][pos]);
  }
}
int get(int type, int r) {
  int res = 0;
  for (r; r > 0; r -= (r & -r)) {
    res += f[type][r];
    norm(res);
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 2; i <= n; ++i) {
    int x;
    cin >> x;
    g[x].push_back(i);
  }
  dfs();
  cin >> m;
  for (int i = 1; i <= m; ++i) {
    int type;
    cin >> type;
    if (type == 1) {
      int v, x, k;
      cin >> v >> x >> k;
      int val = x + lvl[v] * 1ll * k % mod;
      norm(val);
      add(0, tin[v], val);
      add(0, tout[v] + 1, -val);
      add(1, tin[v], k);
      add(1, tout[v] + 1, -k);
    } else {
      int v;
      cin >> v;
      int val = get(0, tin[v]) - get(1, tin[v]) * 1ll * lvl[v] % mod;
      norm(val);
      cout << val << nxtl;
    }
  }
  return 0;
}
