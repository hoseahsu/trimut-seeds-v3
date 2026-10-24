#include <bits/stdc++.h>
using namespace std;
long long n, m, ans = 1;
vector<int> v[10010];
pair<int, int> p[10010];
bool vis[10010];
int dfs(int a) {
  int t = 0;
  vis[a] = 1;
  for (int i = 0; i < v[a].size(); i++) {
    if (!vis[v[a][i]]) t += dfs(v[a][i]) + 1;
  }
  return t;
}
int main() {
  int a, b;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a >> b;
    p[i].first = a, p[i].second = b;
    v[a].push_back(b), v[b].push_back(a);
  }
  for (int i = 1; i <= m; i++) {
    if (!vis[p[i].first]) ans = ans * pow(2, dfs(p[i].first));
  }
  cout << ans;
  return 0;
}
