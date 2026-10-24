#include <bits/stdc++.h>
using namespace std;
const int mxN = 55;
char grid[mxN][mxN];
bool visited[mxN][mxN];
int N, M;
bool can_go = 0;
void floodfill(int r, int c) {
  if (r < 0 || r >= N || c < 0 || c >= M) return;
  if (grid[r][c] == '#' || visited[r][c]) return;
  visited[r][c] = true;
  floodfill(r + 1, c);
  floodfill(r - 1, c);
  floodfill(r, c + 1);
  floodfill(r, c - 1);
}
void solve() {
  memset(grid, '.', sizeof(grid));
  memset(visited, 0, sizeof(visited));
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> grid[i][j];
    }
  }
  bool ok = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (grid[i][j] == 'B') {
        if (i - 1 >= 0) {
          if (grid[i - 1][j] == 'G') {
            ok = 0;
          }
          if (grid[i - 1][j] == '.') {
            grid[i - 1][j] = '#';
          }
        }
        if (i + 1 < N) {
          if (grid[i + 1][j] == 'G') {
            ok = 0;
          }
          if (grid[i + 1][j] == '.') {
            grid[i + 1][j] = '#';
          }
        }
        if (j - 1 >= 0) {
          if (grid[i][j - 1] == 'G') {
            ok = 0;
          }
          if (grid[i][j - 1] == '.') {
            grid[i][j - 1] = '#';
          }
        }
        if (j + 1 < M) {
          if (grid[i][j + 1] == 'G') {
            ok = 0;
          }
          if (grid[i][j + 1] == '.') {
            grid[i][j + 1] = '#';
          }
        }
      }
    }
  }
  if (!ok) {
    cout << "No"
         << "\n";
    return;
  }
  ok = 1;
  floodfill(N - 1, M - 1);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (grid[i][j] == 'G' && !visited[i][j]) {
        ok = 0;
        break;
      }
    }
  }
  if (!ok) {
    cout << "No"
         << "\n";
    return;
  }
  cout << "Yes"
       << "\n";
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
