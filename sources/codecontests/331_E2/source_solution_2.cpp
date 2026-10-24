#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int N = 105;
int partial_solution[2][2][N][N][N];
int final_solution[N][N][2];
int n, m;
vector<int> visions[N * N];
int startnode[N * N], endnode[N * N];
int closed_chain[N][N][N];
int open_chain[N][N][N];
int edgeID[N][N];
inline void add(int &x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
}
pair<int, int> find_chains(vector<int> &temp_chain, int x,
                           bool same_direction) {
  int curr_index = 0;
  while (curr_index + 1 <= temp_chain.size()) {
    int y = temp_chain[curr_index];
    int current_edge = edgeID[x][y];
    if (!current_edge || temp_chain.size() > 2 * n ||
        (current_edge > m) != same_direction)
      return pair<int, int>(10086, -1);
    for (int j = (0); j <= (int)visions[current_edge].size() - 1; j++)
      temp_chain.push_back(visions[current_edge][j]);
    x = y;
    curr_index++;
  }
  return pair<int, int>(temp_chain.size(), x);
}
void input() {
  scanf("%d%d", &n, &m);
  for (int i = (1); i <= (int)m; i++) {
    int x, y, k;
    scanf("%d%d%d", &x, &y, &k);
    edgeID[x][y] = i;
    startnode[i] = x;
    endnode[i] = y;
    for (int j = (1); j <= (int)k; j++) {
      int v;
      scanf("%d", &v);
      visions[i].push_back(v);
    }
    edgeID[y][x] = i + m;
    startnode[i + m] = y;
    endnode[i + m] = x;
    for (int j = (k - 1); j >= (int)0; j--)
      visions[i + m].push_back(visions[i][j]);
    if (k == 0) partial_solution[0][0][x][y][1]++;
  }
}
void build_chain_table(bool same_direction) {
  memset(closed_chain, 0, sizeof closed_chain);
  memset(open_chain, 0, sizeof open_chain);
  for (int i = (1); i <= (int)2 * m; i++)
    if ((i <= m) ^ same_direction) {
      for (int j = (0); j <= (int)visions[i].size() - 1; j++)
        if (visions[i][j] == startnode[i]) {
          vector<int> temprory_forward_chain, temprory_backward_chain;
          for (int k = (j - 1); k >= (int)0; k--)
            temprory_forward_chain.push_back(visions[i][k]);
          pair<int, int> forward_chain = find_chains(
              temprory_forward_chain, startnode[i], same_direction ^ 1);
          if (forward_chain.first > 2 * n) continue;
          if (j + 1 == visions[i].size())
            open_chain[forward_chain.second][endnode[i]]
                      [forward_chain.first + 1]++;
          else {
            if (visions[i][j + 1] != endnode[i]) continue;
            for (int k = (j + 2); k <= (int)visions[i].size() - 1; k++)
              temprory_backward_chain.push_back(visions[i][k]);
            pair<int, int> backward_chain = find_chains(
                temprory_backward_chain, endnode[i], same_direction);
            if (backward_chain.first + 1 + forward_chain.first <= 2 * n)
              closed_chain[forward_chain.second][backward_chain.second]
                          [backward_chain.first + 1 + forward_chain.first]++;
          }
        }
    }
}
void build_partial_dp() {
  build_chain_table(0);
  for (int i = (1); i <= (int)n; i++)
    for (int j = (1); j <= (int)n; j++)
      for (int k = (1); k <= (int)2 * n; k++) {
        partial_solution[1][1][i][j][k] = closed_chain[i][j][k];
        partial_solution[1][0][i][j][k] = open_chain[i][j][k];
      }
  build_chain_table(1);
  for (int i = (1); i <= (int)n; i++)
    for (int j = (1); j <= (int)n; j++)
      for (int k = (1); k <= (int)2 * n; k++)
        partial_solution[0][1][j][i][k] = open_chain[i][j][k];
}
void final_dp_solve() {
  for (int i = (1); i <= (int)n; i++)
    for (int j = (1); j <= (int)n; j++)
      for (int k = (1); k <= (int)2 * n; k++)
        for (int v = (0); v <= (int)1; v++)
          add(final_solution[k][j][v], partial_solution[1][v][i][j][k]);
  int ans;
  for (int k = (1); k <= (int)n * 2; k++) {
    ans = 0;
    for (int i = (1); i <= (int)n; i++) {
      add(ans, final_solution[k][i][1]);
      for (int mid = (0); mid <= (int)1; mid++)
        if (final_solution[k][i][mid]) {
          for (int ed = (0); ed <= (int)1; ed++)
            for (int zd = (1); zd <= (int)n; zd++)
              for (int len = (1); len <= (int)2 * n - k; len++)
                add(final_solution[k + len][zd][ed],
                    final_solution[k][i][mid] * 1ll *
                        partial_solution[mid ^ 1][ed][i][zd][len] % MOD);
        }
    }
    printf("%d\n", ans);
  }
}
int main() {
  input();
  build_partial_dp();
  final_dp_solve();
  return 0;
}
