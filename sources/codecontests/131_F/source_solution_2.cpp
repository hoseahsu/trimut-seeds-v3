#include <bits/stdc++.h>
using namespace std;
char b[512][512];
int c[512][512];
int M[512][512];
int n, m, k;
int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < n; i++) scanf("%s", b[i]);
  memset(c, 0, sizeof(c));
  for (int i = 1; i < n - 1; i++) {
    for (int j = 1; j < m - 1; j++) {
      if (b[i][j] == '1') {
        if (b[i - 1][j] == '1' && b[i + 1][j] == '1' && b[i][j - 1] == '1' &&
            b[i][j + 1] == '1')
          c[i + 1][j + 1] = 1;
      }
    }
  }
  for (int i = 0; i < n; i++) M[i][0] = 0;
  for (int j = 0; j < n; j++) M[0][j] = 0;
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      M[i][j] = M[i - 1][j] + M[i][j - 1] - M[i - 1][j - 1];
      if (c[i][j]) M[i][j]++;
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 2; j < n; j++) {
      int ini = 0;
      int fim = 2;
      while (fim < m && ini < m) {
        if (ini > fim - 2) fim++;
        if (fim == m) break;
        int x = M[j][fim];
        x -= M[j][ini + 1];
        x -= M[i + 1][fim];
        x += M[i + 1][ini + 1];
        if (x >= k) {
          ans += m - fim;
          ini++;
        } else
          fim++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
