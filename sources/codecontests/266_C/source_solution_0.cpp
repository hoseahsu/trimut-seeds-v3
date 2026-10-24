#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e3 + 5;
int grid[MAX][MAX];
int row_sum[MAX], col_sum[MAX];
vector<tuple<int, int, int> > ans;
void swap_row(int x, int y) {
  ans.emplace_back(1, x, y);
  swap(grid[x], grid[y]);
  swap(row_sum[x], row_sum[y]);
}
void swap_col(int x, int y, int n) {
  ans.emplace_back(2, x, y);
  for (int i = int(1); i < int(n + 1); i++) {
    swap(grid[i][x], grid[i][y]);
  }
  swap(col_sum[x], col_sum[y]);
}
void roll(int n) {
  int zero_col = -1;
  for (int i = int(1); i < int(n + 1); i++) {
    if (col_sum[i] == 0) {
      zero_col = i;
    }
  }
  if (zero_col != n) {
    swap_col(zero_col, n, n);
  }
  int one_row = -1;
  for (int i = int(1); i < int(n + 1); i++) {
    if (row_sum[i] > 0) {
      one_row = i;
    }
  }
  if (one_row > -1) {
    if (one_row != n) {
      swap_row(one_row, n);
    }
    for (int i = int(1); i < int(n + 1); i++) {
      col_sum[i] -= grid[n][i];
      row_sum[i] -= grid[i][n];
    }
    roll(n - 1);
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = int(0); i < int(n - 1); i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    grid[x][y] = 1;
    row_sum[x]++;
    col_sum[y]++;
  }
  roll(n);
  printf("%d\n", (int)ans.size());
  for (auto &each : ans) {
    int x, y, z;
    tie(x, y, z) = each;
    printf("%d %d %d\n", x, y, z);
  }
  return 0;
}
