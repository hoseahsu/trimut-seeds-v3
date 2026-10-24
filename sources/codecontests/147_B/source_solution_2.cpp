#include <bits/stdc++.h>
using namespace std;
const int MAXN = 305;
const int LOG = 10;
void read(int &num) {
  char ch;
  bool flag = 0;
  while (!isdigit(ch = getchar()))
    if (ch == '-') flag = !flag;
  for (num = 0; isdigit(ch); num = num * 10 + ch - '0', ch = getchar())
    ;
  num = flag ? -num : num;
}
int n, m;
struct Matrix {
  int mz[MAXN][MAXN];
  Matrix() { memset(mz, 0x3f, sizeof mz); }
  friend Matrix operator*(Matrix X, Matrix Y) {
    Matrix Z;
    for (int k = 1; k <= n; k++)
      for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
          Z.mz[i][j] = min(Z.mz[i][j], X.mz[i][k] + Y.mz[k][j]);
    return Z;
  }
} A, tmp, dis[LOG];
int main() {
  int u, v, w, rw;
  read(n), read(m);
  if (n == 1 && m == 0) {
    puts("0");
    return 0;
  }
  for (int i = 1; i <= m; i++) {
    read(u), read(v), read(w), read(rw);
    dis[0].mz[u][v] = -w;
    dis[0].mz[v][u] = -rw;
  }
  for (int i = 1; i <= n; i++) dis[0].mz[i][i] = A.mz[i][i] = 0;
  int len;
  for (len = 1; (1 << len) <= n; len++) dis[len] = dis[len - 1] * dis[len - 1];
  int Ans = 0;
  for (int i = len - 1, j; i >= 0; i--) {
    tmp = A * dis[i];
    for (j = 1; j <= n; j++)
      if (tmp.mz[j][j] < 0) break;
    if (j == n + 1) A = tmp, Ans += (1 << i);
  }
  if (Ans > n) Ans = -1;
  printf("%d\n", Ans + 1);
}
