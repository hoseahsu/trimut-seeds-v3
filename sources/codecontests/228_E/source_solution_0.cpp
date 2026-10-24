#include <bits/stdc++.h>
using namespace std;
vector<pair<int, bool> > g[102];
bool visited[102];
int col[102];
int ans;
bool dfs(int s, int color) {
  visited[s] = true;
  col[s] = color;
  int newcolor;
  int i;
  for (i = 0; i < g[s].size(); i++) {
    newcolor = color ^ g[s][i].second ^ 1;
    if (col[g[s][i].first] >= 0 && col[g[s][i].first] != newcolor) return false;
    if (!visited[g[s][i].first] && !dfs(g[s][i].first, newcolor)) return false;
  }
  return true;
}
int main() {
  int n, m, i, j, k, l;
  cin >> n >> m;
  for (i = 0; i < m; i++) {
    cin >> j >> k >> l;
    g[j].push_back(make_pair(k, l));
    g[k].push_back(make_pair(j, l));
  }
  for (i = 1; i <= n; i++) col[i] = -1;
  for (i = 1; i <= n; i++) {
    if (!visited[i]) {
      if (dfs(i, 0) || dfs(i, 1)) {
      } else {
        cout << "Impossible";
        return 0;
      }
    }
  }
  for (i = 1; i <= n; i++) {
    if (col[i]) ans++;
  }
  cout << ans << endl;
  for (i = 1; i <= n; i++) {
    if (col[i]) cout << i << " ";
  }
  return 0;
}
