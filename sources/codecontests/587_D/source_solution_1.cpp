#include <bits/stdc++.h>
using namespace std;
int n, m, c[(int)(5e4 + 10)], t[(int)(5e4 + 10)], cnt,
    comp[6 * (int)(5e4 + 10)], topo_[6 * (int)(5e4 + 10)], topo_time;
vector<pair<int, int>> vec[(int)(5e4 + 10)];
vector<int> base_adj[6 * (int)(5e4 + 10)], adj[6 * (int)(5e4 + 10)],
    rev_adj[6 * (int)(5e4 + 10)];
bool mark[6 * (int)(5e4 + 10)];
inline void add(int p, int q) {
  base_adj[p].push_back(q);
  base_adj[(3 * (int)(5e4 + 10) + q) % (6 * (int)(5e4 + 10))].push_back(
      (3 * (int)(5e4 + 10) + p) % (6 * (int)(5e4 + 10)));
}
void topo(int v) {
  mark[v] = true;
  for (auto e : rev_adj[v])
    if (!mark[e]) topo(e);
  topo_[v] = ++topo_time;
}
vector<int> ks;
int color;
void dfs(int v) {
  mark[v] = true;
  for (auto e : adj[v])
    if (!mark[e]) dfs(e);
  ks.push_back(v);
}
void rev_dfs(int v) {
  mark[v] = true;
  comp[v] = color;
  for (auto e : rev_adj[v])
    if (!mark[e]) rev_dfs(e);
}
bool solve(int d) {
  color = 0;
  for (int i = 0; i < 6 * (int)(5e4 + 10); i++) {
    adj[i].clear();
    rev_adj[i].clear();
  }
  memset(mark, 0, sizeof(mark));
  for (int i = 0; i < 6 * (int)(5e4 + 10); i++)
    for (auto e : base_adj[i]) {
      adj[i].push_back(e);
      rev_adj[e].push_back(i);
    }
  for (int i = 1; i <= m; i++)
    if (t[i] > d) {
      adj[i].push_back((3 * (int)(5e4 + 10) + i) % (6 * (int)(5e4 + 10)));
      rev_adj[(3 * (int)(5e4 + 10) + i) % (6 * (int)(5e4 + 10))].push_back(i);
    }
  for (int i = 1; i <= cnt; i++) {
    if (!mark[i]) dfs(i);
    if (!mark[(3 * (int)(5e4 + 10) + i) % (6 * (int)(5e4 + 10))])
      dfs((3 * (int)(5e4 + 10) + i) % (6 * (int)(5e4 + 10)));
  }
  memset(mark, 0, sizeof(mark));
  while (!ks.empty()) {
    int tp = ks.back();
    ks.pop_back();
    if (!mark[tp]) {
      color++;
      rev_dfs(tp);
    }
  }
  for (int i = 1; i <= cnt; i++)
    if (comp[i] == comp[(3 * (int)(5e4 + 10) + i) % (6 * (int)(5e4 + 10))])
      return false;
  return true;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  cnt = m;
  for (int i = 1, u, v; i <= m; i++) {
    cin >> u >> v >> c[i] >> t[i];
    vec[v].push_back({c[i], i});
    vec[u].push_back({c[i], i});
  }
  for (int i = 1; i <= n; i++) {
    sort(vec[i].begin(), vec[i].end());
    for (int j = 0; j < (int)vec[i].size(); j++) {
      if (j > 1 && vec[i][j].first == vec[i][j - 1].first &&
          vec[i][j].first == vec[i][j - 2].first)
        return cout << "No\n", 0;
      if (j && vec[i][j].first == vec[i][j - 1].first) {
        add(vec[i][j].second, (3 * (int)(5e4 + 10) + vec[i][j - 1].second) %
                                  (6 * (int)(5e4 + 10)));
        add((3 * (int)(5e4 + 10) + vec[i][j].second) % (6 * (int)(5e4 + 10)),
            vec[i][j - 1].second);
      }
      if (j < ((int)vec[i].size() - 1)) {
        add(vec[i][j].second, ++cnt);
        if (j) add(cnt - 1, cnt);
        add(cnt, (3 * (int)(5e4 + 10) + vec[i][j + 1].second) %
                     (6 * (int)(5e4 + 10)));
      }
    }
  }
  int lo = -1, hi = 1e9 + 1;
  while (lo < hi - 1) {
    int mid = lo + hi >> 1;
    if (solve(mid))
      hi = mid;
    else
      lo = mid;
  }
  if (hi == (1e9 + 1)) return cout << "No\n", 0;
  solve(hi);
  vector<int> answer;
  memset(mark, 0, sizeof(mark));
  for (int i = 0; i < 6 * (int)(5e4 + 10); i++) rev_adj[i].clear();
  for (int i = 0; i < 6 * (int)(5e4 + 10); i++)
    for (auto e : adj[i]) rev_adj[comp[e]].push_back(comp[i]);
  for (int i = 0; i <= 2 * cnt; i++) {
    if (!mark[i]) topo(i);
    if (!mark[(3 * (int)(5e4 + 10) + i) % (6 * (int)(5e4 + 10))])
      topo((3 * (int)(5e4 + 10) + i) % (6 * (int)(5e4 + 10)));
  }
  for (int i = 1; i <= m; i++)
    if (topo_[comp[i]] >
        topo_[comp[(3 * (int)(5e4 + 10) + i) % (6 * (int)(5e4 + 10))]])
      answer.push_back(i);
  cout << "Yes\n" << hi << ' ' << answer.size() << endl;
  for (auto e : answer) cout << e << ' ';
  return 0;
}
