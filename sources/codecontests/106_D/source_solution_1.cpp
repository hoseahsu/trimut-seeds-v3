#include <bits/stdc++.h>
using namespace std;
char grid[1010][1010];
char ins[100010][4];
int num[100010], n, m;
int s[1010][1010];
int N[1010][1010];
int e[1010][1010];
int w[1010][1010];
int main() {
  int i, j, ii, jj, k, q;
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; i++) {
    scanf("%s", grid[i]);
  }
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) {
      if (grid[i][j] == '#') {
        ii = i - 1;
        jj = j;
        while (grid[ii][jj] != '#' && ii >= 0) {
          s[ii][jj] = i;
          ii--;
        }
        ii = i + 1;
        jj = j;
        while (grid[ii][jj] != '#' && ii <= n) {
          N[ii][jj] = i;
          ii++;
        }
        ii = i;
        jj = j - 1;
        while (grid[ii][jj] != '#' && jj >= 0) {
          e[ii][jj] = j;
          jj--;
        }
        ii = i;
        jj = j + 1;
        while (grid[ii][jj] != '#' && jj <= m) {
          w[ii][jj] = j;
          jj++;
        }
      }
    }
  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    scanf("%s %d", ins[i], &num[i]);
  }
  vector<char> v;
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) {
      if (grid[i][j] <= 'Z' && grid[i][j] >= 'A') {
        int x = i;
        int y = j;
        for (k = 0; k < q; k++) {
          if (ins[k][0] == 'N') {
            if (x - num[k] > N[x][y]) {
              x = x - num[k];
            } else
              break;
          }
          if (ins[k][0] == 'S') {
            if (x + num[k] < s[x][y]) {
              x = x + num[k];
            } else
              break;
          }
          if (ins[k][0] == 'E') {
            if (y + num[k] < e[x][y]) {
              y = y + num[k];
            } else
              break;
          }
          if (ins[k][0] == 'W') {
            if (y - num[k] > w[x][y]) {
              y = y - num[k];
            } else
              break;
          }
        }
        if (k == q) v.push_back(grid[i][j]);
      }
    }
  sort(v.begin(), v.end());
  if (v.size() == 0)
    cout << "no solution" << endl;
  else {
    for (i = 0; i < v.size(); i++) {
      cout << v[i];
    }
    cout << endl;
  }
  return 0;
}
