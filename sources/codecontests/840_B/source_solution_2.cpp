#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> g[300007];
int d[300007];
bool used[300007];
vector<int> ans;
void dfs(int u) {
  used[u] = true;
  for (auto p : g[u]) {
    auto v = p.first;
    if (!used[v]) {
      dfs(v);
      if (d[v] == 1) {
        ans.push_back(p.second);
        d[u] ^= 1;
      }
    }
  }
}
int main() {
  int n, m;
  scanf("%d", &n);
  scanf("%d", &m);
  int u, v;
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &d[i]);
    if (d[i] == 1) cnt ^= 1;
  }
  for (int i = 1; i <= n; ++i) {
    if (d[i] == -1) {
      if (cnt == 1) {
        d[i] = 1;
        cnt = 0;
      } else
        d[i] = 0;
    }
  }
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &u);
    scanf("%d", &v);
    g[u].push_back(make_pair(v, i));
    g[v].push_back(make_pair(u, i));
  }
  if (cnt == 1) {
    cout << -1;
    return 0;
  }
  dfs(1);
  printf("%d", ans.size());
  for (auto c : ans) printf("\n%d", c);
  return 0;
}
