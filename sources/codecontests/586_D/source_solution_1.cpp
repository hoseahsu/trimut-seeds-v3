#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
const double eps = 1e-9;
const double pi = acos(-1.0);
char a[3][222];
int m, k;
vector<pair<int, int> > v[3];
bool used[3][222];
bool ok = false;
bool can(int x, int y) {
  if (x < 0 || x >= 3) return false;
  if (used[x][y]) return false;
  if (a[x][y] == '.') return true;
  return false;
}
void dfs(int vi, int vj) {
  if (vj > 111) {
    ok = true;
    return;
  }
  used[vi][vj] = true;
  if (!can(vi, vj + 1)) return;
  if (can(vi - 1, vj + 1) && can(vi - 1, vj + 2) && can(vi - 1, vj + 3))
    dfs(vi - 1, vj + 3);
  if (can(vi, vj + 1) && can(vi, vj + 2) && can(vi, vj + 3)) dfs(vi, vj + 3);
  if (can(vi + 1, vj + 1) && can(vi + 1, vj + 2) && can(vi + 1, vj + 3))
    dfs(vi + 1, vj + 3);
}
void Solve() {
  scanf("%d%d\n", &m, &k);
  for (int i = 0; i < 3; i++) v[i].clear();
  int indi = -1, indj = -1;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 222; j++) a[i][j] = '.';
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%c", &a[i][j]);
      if (a[i][j] == 's') {
        indi = i;
        indj = j;
      }
    }
    scanf("\n");
  }
  memset(used, 0, sizeof(used));
  ok = false;
  dfs(indi, indj);
  if (ok) {
    printf("YES\n");
  } else
    printf("NO\n");
}
int main() {
  int tests;
  scanf("%d\n", &tests);
  for (int i = 0; i < tests; i++) Solve();
  return 0;
}
