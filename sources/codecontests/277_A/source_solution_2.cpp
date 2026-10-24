#include <bits/stdc++.h>
using namespace std;
void dfs(vector<long long int> &visited,
         vector<unordered_set<long long int>> edges, long long int index) {
  visited[index] = 1;
  for (auto x : edges[index]) {
    if (visited[x] == 0) {
      dfs(visited, edges, x);
    }
  }
}
int main() {
  long long int a, b, c, d, e, f, g;
  bool zero = 0;
  cin >> a >> b;
  vector<vector<long long int>> connections(b + 1, vector<long long int>());
  vector<long long int> visited(a + 1, 0);
  for (c = 0; c < a; c++) {
    cin >> d;
    for (e = 0; e < d; e++) {
      zero = 1;
      cin >> f;
      connections[f].push_back(c + 1);
    }
  }
  vector<unordered_set<long long int>> edjes(a + 1);
  for (c = 1; c <= b; c++) {
    for (d = 0; d < connections[c].size(); d++) {
      for (e = d + 1; e < connections[c].size(); e++) {
        edjes[connections[c][d]].insert(connections[c][e]);
        edjes[connections[c][e]].insert(connections[c][d]);
      }
    }
  }
  if (zero == 0) {
    cout << a << endl;
    return 0;
  }
  long long int ans = 0;
  for (c = 1; c <= a; c++) {
    if (visited[c] == 0) {
      ans++;
      dfs(visited, edjes, c);
    }
  }
  cout << ans - 1 << endl;
}
