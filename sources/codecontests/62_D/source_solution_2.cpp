#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
const int inf = (1 << 30) - 1;
const double eps = 1e-9;
int n, m;
vector<int> pth;
void Load() {
  scanf("%d%d", &n, &m);
  pth.resize(m + 1);
  for (int i = 0; i <= m; i++) scanf("%d", &pth[i]);
}
vector<int> edg[105];
void AddEdge(int u, int v) {
  edg[u].push_back(v);
  edg[v].push_back(u);
}
vector<int> npth;
bool sdel[105][105];
int del[105][105];
void Dfs(int v, int d) {
  int to;
  for (int i = 0; i < (int)edg[v].size(); i++) {
    to = edg[v][i];
    if (to <= d) continue;
    if (del[v][to] != 0) continue;
    del[v][to] = 2;
    del[to][v] = 2;
    Dfs(to, -1);
  }
  npth.push_back(v);
}
inline bool Good() {
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < (int)edg[i].size(); j++)
      if (!!del[i][edg[i][j]] != sdel[i][edg[i][j]]) return false;
  return true;
}
inline void Uncolor() {
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < (int)edg[i].size(); j++)
      if (del[i][edg[i][j]] == 2) del[i][edg[i][j]] = 0;
}
void Solve() {
  for (int i = 1; i <= m; i++) {
    AddEdge(pth[i - 1], pth[i]);
    del[pth[i - 1]][pth[i]] = 1;
    del[pth[i]][pth[i - 1]] = 1;
    sdel[pth[i - 1]][pth[i]] = 1;
    sdel[pth[i]][pth[i - 1]] = 1;
  }
  for (int i = 1; i <= n; i++) sort(edg[i].begin(), edg[i].end());
  for (int i = m; i > 0; i--) {
    npth.resize(0);
    del[pth[i - 1]][pth[i]] = del[pth[i]][pth[i - 1]] = 0;
    Dfs(pth[i - 1], pth[i]);
    if (Good()) {
      for (int j = 0; j < i; j++) printf("%d ", pth[j]);
      reverse(npth.begin(), npth.end());
      for (int j = 1; j < (int)npth.size(); j++) printf("%d ", npth[j]);
      return;
    } else
      Uncolor();
  }
  printf("No solution");
}
int main() {
  Load();
  Solve();
  return 0;
}
