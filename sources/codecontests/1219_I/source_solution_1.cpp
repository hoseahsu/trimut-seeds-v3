#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007LL;
long long large = 2000000000000000000LL;
vector<int> dfs_num, dfs_low, S, visited;
vector<vector<int> > adj;
vector<vector<int> > Scc;
int dfsNumberCounter = 0, numSCC = 0;
void tarjanSCC(int u) {
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
  S.push_back(u);
  visited[u] = 1;
  for (int j = 0; j < (int)adj[u].size(); j++) {
    int v = adj[u][j];
    if (dfs_num[v] == -1) {
      tarjanSCC(v);
    }
    if (visited[v] == 1) {
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
  }
  if (dfs_low[u] == dfs_num[u]) {
    Scc.push_back(vector<int>(0, 0));
    while (true) {
      int v = S.back();
      S.pop_back();
      visited[v] = 0;
      Scc[numSCC].push_back(v);
      if (u == v) break;
    }
    numSCC++;
  }
}
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<int> > g(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      char c;
      cin >> c;
      int x = c - '0';
      g[i][j] ^= x;
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      char c;
      cin >> c;
      int x = c - '0';
      g[i][j] ^= x;
    }
  string s;
  cin >> s;
  bool can = true;
  adj.assign(4 * n, vector<int>());
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (g[i][j]) {
        if (s[i] == '1' && s[j] == '1') {
          adj[2 * i + 1].push_back(2 * n + 2 * j);
          adj[2 * n + 2 * j + 1].push_back(2 * i);
          adj[2 * i].push_back(2 * n + 2 * j + 1);
          adj[2 * n + 2 * j].push_back(2 * i + 1);
        } else if (s[j] == '1') {
          adj[2 * i + 1].push_back(2 * i);
        } else if (s[i] == '1') {
          adj[2 * n + 2 * j + 1].push_back(2 * n + 2 * j);
        } else {
          can = false;
        }
      } else {
        if (s[i] == '1' && s[j] == '1') {
          adj[2 * i].push_back(2 * n + 2 * j);
          adj[2 * n + 2 * j + 1].push_back(2 * i + 1);
          adj[2 * n + 2 * j].push_back(2 * i);
          adj[2 * i + 1].push_back(2 * n + 2 * j + 1);
        } else if (s[j] == '1') {
          adj[2 * i].push_back(2 * i + 1);
        } else if (s[i] == '1') {
          adj[2 * n + 2 * j].push_back(2 * n + 2 * j + 1);
        } else {
        }
      }
    }
  }
  if (!can) {
    cout << "-1" << endl;
    return 0;
  }
  dfs_num.assign(4 * n, -1);
  dfs_low.assign(4 * n, 0);
  visited.assign(4 * n, 0);
  for (int i = 0; i < 4 * n; i++) {
    if (dfs_num[i] == -1) {
      tarjanSCC(i);
    }
  }
  vector<int> bel(4 * n, -1);
  for (int i = 0; i < numSCC; i++) {
    for (int j = 0; j < (int)Scc[i].size(); j++) {
      bel[Scc[i][j]] = i;
    }
  }
  for (int i = 0; i < n; i++) {
    if (bel[2 * i] == bel[2 * i + 1] ||
        bel[2 * i + 2 * n] == bel[2 * i + 2 * n + 1]) {
      cout << "-1" << endl;
      return 0;
    }
  }
  vector<vector<int> > ad(numSCC, vector<int>());
  for (int i = 0; i < 4 * n; i++) {
    for (int j = 0; j < (int)adj[i].size(); j++) {
      int v = adj[i][j];
      if (bel[i] == bel[v]) continue;
      ad[bel[i]].push_back(bel[v]);
    }
  }
  vector<int> in(numSCC, 0);
  for (int i = 0; i < numSCC; i++) {
    sort(ad[i].begin(), ad[i].end());
    ad[i].erase(unique(ad[i].begin(), ad[i].end()), ad[i].end());
    for (int j = 0; j < (int)ad[i].size(); j++) {
      int v = ad[i][j];
      in[v]++;
    }
  }
  set<int> st;
  for (int i = 0; i < numSCC; i++)
    if (in[i] == 0) st.insert(i);
  vector<int> vis(numSCC, -1);
  while (!st.empty()) {
    int u = *st.begin();
    st.erase(u);
    for (int j = 0; j < (int)ad[u].size(); j++) {
      int v = ad[u][j];
      in[v]--;
      if (in[v] == 0) st.insert(v);
    }
    if (vis[u] != -1) continue;
    vis[u] = 0;
    vis[bel[Scc[u][0] ^ 1]] = 1;
  }
  int cnt = 0;
  for (int i = 0; i < 2 * n; i++) {
    if (vis[bel[i * 2]] == 1) cnt++;
  }
  cout << cnt << endl;
  for (int i = 0; i < 2 * n; i++) {
    if (vis[bel[i * 2]] == 1) {
      if (i < n)
        cout << "row " << i << endl;
      else
        cout << "col " << i - n << endl;
    }
  }
  return 0;
}
