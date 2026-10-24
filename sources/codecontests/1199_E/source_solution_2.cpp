#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
const int LOGMAX = 11;
const int inf = 1e9;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > edges;
    vector<int> dfs_num(3 * n, 0);
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      edges.push_back(make_pair(u, v));
    }
    vector<int> ans;
    for (int i = 0; i < m; i++) {
      int u = edges[i].first, v = edges[i].second;
      if (dfs_num[u] == 0 && dfs_num[v] == 0) {
        ans.push_back(i);
        dfs_num[u] = dfs_num[v] = 1;
      }
    }
    if ((int)ans.size() >= n) {
      cout << "Matching" << endl;
      for (int i = 0; i < n; i++) cout << ans[i] + 1 << " ";
      cout << endl;
    } else {
      cout << "IndSet" << endl;
      int cnt = 0;
      for (int i = 0; i < 3 * n; i++) {
        if (cnt == n) break;
        if (dfs_num[i] == 0) {
          cout << i + 1 << " ";
          cnt++;
        }
      }
      cout << endl;
    }
  }
  return 0;
}
