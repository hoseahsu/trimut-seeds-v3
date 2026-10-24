#include <bits/stdc++.h>
using namespace std;
const int maxm = 5554;
int n, m, k;
char c[maxm][maxm];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool visited[maxm][maxm];
bool check(int i, int j) { return (i >= 0 && i < n && j >= 0 && j <= m); }
void dfs(int i, int j) {
  visited[i][j] = true;
  for (int k = 0; k < 4; k++) {
    if (check(i + dx[k], j + dy[k]) && !visited[i + dx[k]][j + dy[k]] &&
        c[i + dx[k]][j + dy[k]] == '.')
      dfs(i + dx[k], j + dy[k]);
  }
  if (k > 0) {
    c[i][j] = 'X';
    k--;
  }
}
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i <= n - 1; i++) {
    for (int j = 0; j <= m - 1; j++) cin >> c[i][j];
  }
  bool b = false;
  for (int i = 0; i < n && !b; i++) {
    for (int j = 0; j < m; j++) {
      if (c[i][j] == '.') {
        dfs(i, j);
        b = false;
        break;
      }
    }
  }
  for (int i = 0; i <= n - 1; i++) {
    for (int j = 0; j <= m - 1; j++) cout << c[i][j];
    cout << endl;
  }
  return 0;
}
