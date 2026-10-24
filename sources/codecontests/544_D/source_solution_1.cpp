#include <bits/stdc++.h>
using namespace std;
vector<int> edge[3000];
void bfs(int d[], int s) {
  queue<int> q;
  fill_n(d, 3000, (1 << 20));
  q.push(s);
  d[s] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < (int)(edge[u].size()); i++) {
      int v = edge[u][i];
      if (d[v] == (1 << 20)) {
        d[v] = d[u] + 1;
        q.push(v);
      }
    }
  }
}
int dist[3000][3000];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < (int)(m); i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  int s1, t1, l1, s2, t2, l2;
  int ans = -1;
  cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;
  s1--;
  t1--;
  s2--;
  t2--;
  for (int i = 0; i < (int)(n); i++) {
    bfs(dist[i], i);
  }
  if (dist[s1][t1] <= l1 && dist[s2][t2] <= l2) {
    ans = max(0, m - dist[s1][t1] - dist[s2][t2]);
  }
  for (int i = 0; i < (int)(n); i++)
    for (int j = 0; j < (int)(n); j++) {
      if (dist[s1][i] + dist[i][j] + dist[j][t1] <= l1 &&
          dist[s2][i] + dist[i][j] + dist[j][t2] <= l2) {
        ans = max(ans, m - dist[s1][i] - dist[s2][i] - dist[i][j] -
                           dist[j][t1] - dist[j][t2]);
      }
      if (dist[s1][i] + dist[i][j] + dist[j][t1] <= l1 &&
          dist[s2][j] + dist[j][i] + dist[i][t2] <= l2) {
        ans = max(ans, m - dist[s1][i] - dist[s2][j] - dist[i][j] -
                           dist[j][t1] - dist[i][t2]);
      }
    }
  cout << ans << endl;
  return 0;
}
