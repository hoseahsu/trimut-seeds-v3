#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 5;
const int maxm = 200000 + 5;
vector<int> G[maxn];
bool vis[maxn][3];
int W[maxn], ser[maxn], win = 0, draw = 0, du[maxn];
void dfs(int x, int id) {
  if (win) return;
  if (G[x].size() == 0 && id % 2 == 0) {
    win = id;
    for (int i = 0; i < id; i++) W[i] = ser[i];
    return;
  }
  for (int i = 0; i < (int)G[x].size(); i++) {
    if (!vis[G[x][i]][id & 1]) {
      vis[G[x][i]][id & 1] = 1;
      ser[id] = G[x][i];
      dfs(G[x][i], id + 1);
    }
  }
}
bool dnf2(int x) {
  if (du[x] == 1) {
    return true;
  }
  du[x]++;
  for (int i = 0; i < (int)G[x].size(); i++)
    if (dnf2(G[x][i])) return true;
  du[x]--;
  return false;
}
int main() {
  int n, m, s;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int c, d;
    scanf("%d", &c);
    for (int j = 0; j < c; j++) {
      scanf("%d", &d);
      G[i].push_back(d);
    }
  }
  scanf("%d", &s);
  ser[0] = s;
  dfs(s, 1);
  if (win) {
    printf("Win\n");
    for (int i = 0; i < win; i++) printf("%d ", W[i]);
  } else if (dnf2(s)) {
    printf("Draw\n");
  } else {
    printf("Lose\n");
  }
  return 0;
}
