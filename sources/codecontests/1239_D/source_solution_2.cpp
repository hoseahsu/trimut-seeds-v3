#include <bits/stdc++.h>
using namespace std;
const int N = 1000 * 1000 + 20;
vector<long long> adjIn[N], adjOut[N], compo[2];
bool vis[N], vis1[N];
long long n, m, u, v, last;
void dfs(int v) {
  vis[v] = true;
  for (auto u : adjOut[v])
    if (!vis[u]) dfs(u);
  last = v;
}
void dfs1(int v) {
  vis1[v] = true;
  for (auto u : adjIn[v])
    if (!vis1[u]) dfs1(u);
}
void init() {
  for (int i = 1; i <= n + 20; i++) {
    vis[i] = vis1[i] = false;
    adjIn[i].clear();
    adjOut[i].clear();
  }
  compo[0].clear();
  compo[1].clear();
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    init();
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
      cin >> v >> u;
      adjOut[v].push_back(u);
      adjIn[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
      if (!vis[i]) dfs(i);
    dfs1(last);
    for (int i = 1; i <= n; i++) {
      if (!vis1[i])
        compo[0].push_back(i);
      else
        compo[1].push_back(i);
    }
    if (compo[0].empty())
      cout << "NO" << endl;
    else {
      cout << "YES" << endl
           << compo[0].size() << " " << compo[1].size() << endl;
      for (auto x : compo[0]) cout << x << " ";
      cout << endl;
      for (auto x : compo[1]) cout << x << " ";
      cout << endl;
    }
  }
  return 0;
}
