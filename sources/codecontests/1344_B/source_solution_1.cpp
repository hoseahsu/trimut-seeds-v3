#include <bits/stdc++.h>
using namespace std;
pair<int, int> add[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int rows, columns;
bool ok(int row, int column, vector<vector<bool>> &board) {
  return row >= 0 && row < rows && column >= 0 && column < columns &&
         board[row][column];
}
void dfs(int row, int column, vector<vector<bool>> &board) {
  board[row][column] = false;
  for (pair<int, int> i : add) {
    int r = row + i.first;
    int c = column + i.second;
    if (ok(r, c, board)) dfs(r, c, board);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> rows >> columns;
  vector<vector<bool>> board(rows, vector<bool>(columns));
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      char c;
      cin >> c;
      board[i][j] = c == '#';
    }
  }
  vector<bool> blackInRow(rows);
  vector<bool> whiteInRow(rows);
  vector<bool> blackInColumn(columns);
  vector<bool> whiteInColumn(columns);
  for (int row = 0; row < rows; row++) {
    for (int column = 0; column < columns; column++) {
      if (board[row][column]) {
        blackInRow[row] = true;
        blackInColumn[column] = true;
        if (whiteInRow[row] || whiteInColumn[column]) {
          cout << -1;
          return 0;
        }
      } else {
        if (blackInRow[row]) whiteInRow[row] = true;
        if (blackInColumn[column]) whiteInColumn[column] = true;
      }
    }
  }
  if (rows == 1) {
    for (int column = 1; column < columns; column++) {
      if (board[0][column] != board[0][column - 1]) {
        cout << -1;
        return 0;
      }
    }
  }
  if (columns == 1) {
    for (int row = 1; row < rows; row++) {
      if (board[row][0] != board[row - 1][0]) {
        cout << -1;
        return 0;
      }
    }
  }
  int emptyRows = 0;
  for (int row = 0; row < rows; row++) {
    bool empty = true;
    for (int column = 0; column < columns && empty; column++) {
      if (board[row][column]) empty = false;
    }
    if (empty) emptyRows++;
  }
  int emptyColumns = 0;
  for (int column = 0; column < columns; column++) {
    bool empty = true;
    for (int row = 0; row < rows && empty; row++) {
      if (board[row][column]) empty = false;
    }
    if (empty) emptyColumns++;
  }
  if (emptyColumns == 0 && emptyRows > 0) {
    cout << -1;
    return 0;
  }
  if (emptyRows == 0 && emptyColumns > 0) {
    cout << -1;
    return 0;
  }
  int ans = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      if (board[i][j]) {
        ans++;
        dfs(i, j, board);
      }
    }
  }
  cout << ans;
}
