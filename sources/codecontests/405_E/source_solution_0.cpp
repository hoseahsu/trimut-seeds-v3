#include <bits/stdc++.h>
using namespace std;
int n, m;
int visit[111111];
vector<int> v[111111], mark[111111];
int dfs(int t) {
  vector<int> v1;
  int i;
  for (i = 0; i < v[t].size(); i++) {
    int u = v[t][i];
    if (visit[mark[t][i]] == 0) {
      visit[mark[t][i]] = 1;
      int w = dfs(u);
      if (w == 0)
        v1.push_back(u);
      else
        printf("%d %d %d\n", t, u, w);
    }
  }
  while (v1.size() > 1) {
    printf("%d %d %d\n", v1[v1.size() - 1], t, v1[v1.size() - 2]);
    v1.pop_back();
    v1.pop_back();
  }
  if (v1.size() == 1)
    return v1[0];
  else
    return 0;
}
int main() {
  memset(visit, 0, sizeof(visit));
  scanf("%d%d", &n, &m);
  int i;
  for (i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    v[a].push_back(b);
    v[b].push_back(a);
    mark[a].push_back(i);
    mark[b].push_back(i);
  }
  if (m % 2)
    printf("No solution\n");
  else {
    for (i = 1; i <= n; i++) dfs(i);
  }
}
