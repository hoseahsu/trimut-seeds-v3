#include <bits/stdc++.h>
using namespace std;
const int SZ = 2e5 + 4;
int n, m;
vector<int> g[SZ];
vector<int> ts;
bool us[SZ];
void dfs1(int v) {
  if (us[v]) return;
  us[v] = 1;
  for (auto to : g[v]) dfs1(to);
  ts.push_back(v);
}
int com[SZ];
void dfs(int v, int color) {
  if (us[v]) return;
  us[v] = 1;
  com[v] = color;
  for (auto to : g[v]) dfs(to, color);
}
signed main() {
  cin >> n >> m;
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    int pl = n * c;
    g[a].push_back(b + n - pl);
    g[b].push_back(a + n - pl);
    g[a + n].push_back(b + pl);
    g[b + n].push_back(a + pl);
  }
  for (int i = 0; i < 2 * n; i++) dfs1(i);
  fill(us, us + 2 * n, 0);
  int color = 0;
  for (auto v : ts)
    if (!us[v]) dfs(v, ++color);
  vector<bool> ans(n, 0);
  int kl = 0;
  for (int i = 0; i < n; i++) {
    if (com[i] == com[i + n]) {
      cout << "Impossible";
      return 0;
    }
    if (com[i] < com[i + n]) ans[i] = 1, kl++;
  }
  cout << kl << endl;
  for (int i = 0; i < n; i++)
    if (ans[i]) cout << i + 1 << ' ';
}
