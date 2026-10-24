#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-9;
const int N = 1e6 + 10;
const int M = 1e3 + 10;
const long long mod = 1e9 + 7;
const long long inf = 1e18;
const double f = 0.32349;
bool vis[N];
vector<int> G[N];
int a[N];
bool flog;
void dfs(int u, int v, int c) {
  int si = G[u].size();
  vis[u] = c;
  for (int i = 0; i < si; i++) {
    int go = G[u][i];
    if (go == v) {
      continue;
    } else if (!vis[go]) {
      dfs(go, u, !c);
    } else if (vis[go] == vis[u]) {
      flog = 1;
    }
  }
}
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    a[i] = x;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  dfs(1, 0, 0);
  if (flog) {
    cout << "NO" << '\n';
  } else {
    cout << "YES" << '\n';
    for (int i = 1; i <= m; i++) {
      cout << (vis[a[i]] == 1);
    }
  }
}
signed main() {
  solve();
  return 0;
}
