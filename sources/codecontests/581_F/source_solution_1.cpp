#include <bits/stdc++.h>
using namespace std;
const int NMAX = 5010, inf = 0x3f3f3f3f;
int N;
int DP[NMAX][NMAX][2], lvs[NMAX], aux[NMAX][2], aux2[NMAX][2];
vector<int> G[NMAX];
void DFS(int node, int from) {
  if ((int(G[node].size())) == 1) {
    lvs[node] = 1;
    DP[node][0][0] = DP[node][1][1] = 0;
    return;
  }
  for (auto i : G[node]) {
    if (i == from) continue;
    DFS(i, node);
    lvs[node] += lvs[i];
  }
  memset(aux, inf, sizeof(aux));
  aux[0][0] = aux[0][1] = 0;
  int now = 0, j, k, l, m;
  for (auto i : G[node]) {
    if (i == from) continue;
    memset(aux2, inf, sizeof(aux2));
    for (j = now; j >= 0; --j) {
      for (k = 0; k <= lvs[i]; ++k) {
        for (l = 0; l < 2; ++l) {
          for (m = 0; m < 2; ++m) {
            aux2[j + k][l] =
                min(aux2[j + k][l], aux[j][l] + DP[i][k][m] + (l != m));
          }
        }
      }
    }
    for (j = 0; j <= now + lvs[i]; ++j) {
      aux[j][1] = aux2[j][1];
      aux[j][0] = aux2[j][0];
    }
    now += lvs[i];
  }
  for (int i = 0; i <= lvs[node]; ++i) {
    DP[node][i][0] = aux[i][0];
    DP[node][i][1] = aux[i][1];
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  int i;
  cin >> N;
  for (i = 1; i < N; ++i) {
    int x, y;
    cin >> x >> y;
    G[x].emplace_back(y);
    G[y].emplace_back(x);
  }
  memset(DP, inf, sizeof(DP));
  int leaves = 0;
  for (i = 1; i <= N; ++i)
    if ((int(G[i].size())) == 1) ++leaves;
  for (i = 1; i <= N; ++i) {
    if ((int(G[i].size())) > 1) {
      DFS(i, -1);
      cout << min(DP[i][leaves / 2][0], DP[i][leaves / 2][1]) << '\n';
      return 0;
    }
  }
  return 0;
}
