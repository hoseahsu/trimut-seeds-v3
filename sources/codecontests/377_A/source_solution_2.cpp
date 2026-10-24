#include <bits/stdc++.h>
using namespace std;
int m, n, k, sx, sy, flag, num, sum;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int vis[505][505];
char maze[505][505];
void dfs(int x, int y) {
  vis[x][y] = 1;
  num++;
  if (num >= sum - k) return;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (!vis[nx][ny] && maze[nx][ny] == '.' && num < sum - k) dfs(nx, ny);
    }
  return;
}
int main(void) {
  cin >> m >> n >> k;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) {
      cin >> maze[i][j];
      if (maze[i][j] == '.') {
        sum++;
        if (!flag) {
          sx = i;
          sy = j;
          flag = 1;
        }
      }
    }
  dfs(sx, sy);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (maze[i][j] == '.' && !vis[i][j]) maze[i][j] = 'X';
      cout << maze[i][j];
    }
    cout << endl;
  }
  return 0;
}
