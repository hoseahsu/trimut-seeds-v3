#include <bits/stdc++.h>
using namespace std;
long long r, c;
long long vis[52][52];
long long block[52][52];
void dfs(long long i, long long j) {
  if (i < 0 || j < 0 || i >= r || j >= c || vis[i][j] == 1 || block[i][j] == 1)
    return;
  vis[i][j] = 1;
  if (i < r - 1) dfs(i + 1, j);
  if (i > 0) dfs(i - 1, j);
  if (j > 0) dfs(i, j - 1);
  if (j < c - 1) dfs(i, j + 1);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    cin >> r >> c;
    memset(vis, 0, sizeof(vis));
    memset(block, 0, sizeof(block));
    char a[52][52];
    for (long long i = 0; i < r; i++) {
      for (long long j = 0; j < c; j++) {
        cin >> a[i][j];
      }
    }
    long long flag = 1;
    for (long long i = 0; i < r; i++) {
      for (long long j = 0; j < c; j++) {
        if (block[i][j] == 0 && (a[i][j] == '#' || a[i][j] == 'B')) {
          block[i][j] = 1;
        }
        if (a[i][j] == 'B') {
          if (i < r - 1) block[i + 1][j] = 1;
          if (j < c - 1) block[i][j + 1] = 1;
          if (i > 0) block[i - 1][j] = 1;
          if (j > 0) block[i][j - 1] = 1;
        }
        if (a[i][j] == 'B') {
          if (i < r - 1 && a[i + 1][j] == 'G') flag = 0;
          if (j < c - 1 && a[i][j + 1] == 'G') flag = 0;
          if (i > 0 && a[i - 1][j] == 'G') flag = 0;
          if (j > 0 && a[i][j - 1] == 'G') flag = 0;
        }
      }
    }
    if (flag == 0) {
      cout << "No"
           << "\n";
    } else {
      long long flag = 1;
      dfs(r - 1, c - 1);
      for (long long i = 0; i < r; i++) {
        for (long long j = 0; j < c; j++) {
          if (a[i][j] == 'G' && vis[i][j] != 1) {
            flag = 0;
            break;
          }
        }
        if (flag == 0) break;
      }
      if (flag == 0) {
        cout << "No"
             << "\n";
      } else {
        cout << "Yes"
             << "\n";
      }
    }
  }
  return 0;
}
