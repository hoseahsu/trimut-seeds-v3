#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
const int maxk = 11;
int f[maxn][maxn][maxk], g[maxn][maxn][maxk];
string a, b;
int n, m, K;
void init() {
  scanf("%d%d%d", &n, &m, &K);
  cin >> a >> b;
}
void solve() {
  for (int i = (1); i <= (n); ++i)
    for (int j = (1); j <= (m); ++j)
      for (int k = (1); k <= (K); ++k) {
        if (a[i - 1] == b[j - 1]) {
          int t1(0), t2(0);
          if (g[i - 1][j - 1][k]) t1 = g[i - 1][j - 1][k] + 1;
          if (f[i - 1][j - 1][k - 1] || k == 1) t2 = f[i - 1][j - 1][k - 1] + 1;
          g[i][j][k] = max(t1, t2);
        }
        f[i][j][k] = max(max(f[i - 1][j][k], f[i][j - 1][k]), g[i][j][k]);
      }
  cout << f[n][m][K] << endl;
}
int main() {
  init();
  solve();
  return 0;
}
