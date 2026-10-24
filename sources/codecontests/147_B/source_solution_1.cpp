#include <bits/stdc++.h>
using namespace std;
const int maxn = 309;
int n, m, a, b, c, d, ans, flag, w[maxn][maxn];
struct Matrix {
  int d[maxn][maxn];
  Matrix operator*(const Matrix &a) const {
    Matrix res;
    for (int i = (1); i <= int(n); i++)
      for (int j = (1); j <= int(n); j++) {
        res.d[i][j] = max(d[i][j], a.d[i][j]);
        for (int k = (1); k <= int(n); k++)
          res.d[i][j] = max(res.d[i][j], d[i][k] + a.d[k][j]);
      }
    return res;
  }
} A[15], S, T;
int main() {
  scanf("%d%d", &n, &m);
  memset(S.d, 0xc0, sizeof S.d);
  memset(A[0].d, 0xc0, sizeof A[0].d);
  for (int i = (1); i <= int(n); i++) S.d[i][i] = 0;
  for (int i = (1); i <= int(m); i++) {
    scanf("%d%d%d%d", &a, &b, &c, &d);
    A[0].d[a][b] = c;
    A[0].d[b][a] = d;
  }
  for (int i = (1); i <= int(9); i++) A[i] = A[i - 1] * A[i - 1];
  for (int i = (9); i >= (0); i--) {
    T = S * A[i];
    flag = 0;
    for (int j = (1); j <= int(n); j++)
      if (T.d[j][j] > 0) flag = 1;
    if (flag) continue;
    S = T;
    ans += 1 << i;
  }
  if (ans > n)
    puts("0");
  else
    printf("%d\n", ans + 1);
  return 0;
}
