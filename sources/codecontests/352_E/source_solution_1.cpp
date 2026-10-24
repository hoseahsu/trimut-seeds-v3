#include <bits/stdc++.h>
using namespace std;
void rf() {}
const int nx[8] = {2, -2, -2, 2, 1, 1, -1, -1};
const int ny[8] = {1, 1, -1, -1, 2, -2, -2, 2};
const int Nx[4] = {0, 0, -1, 1};
const int Ny[4] = {1, -1, 0, 0};
const long long LINF = (long long)1e18;
const int INF = 1e9 + 7;
const int N = 5e3 + 1;
const int MX = 60;
const int MAXN = 1e6 + 50;
const double EPS = 1e-9, PI = 3.14159265359;
int n, m;
int dp[MX][MX];
int a[MX], b[MX];
struct matrix {
  long long a[MX][MX];
  matrix() {
    for (int i = 0; i < MX; i++) {
      for (int j = 0; j < MX; j++) {
        a[i][j] = LINF;
      }
    }
  }
};
const matrix operator*(matrix a, matrix b) {
  matrix c;
  for (int i = 0; i < MX; i++)
    for (int j = 0; j < MX; j++)
      for (int k = 0; k < MX; k++)
        c.a[i][j] = min(c.a[i][j], a.a[i][k] + b.a[k][j]);
  return c;
}
matrix bin_pow(matrix b, int n) {
  matrix first = b;
  n--;
  while (n) {
    if (n & 1) first = first * b;
    b = b * b;
    n >>= 1;
  }
  return first;
}
matrix go;
int main() {
  srand(time(0));
  rf();
  srand(time(0));
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
  }
  for (int i = 0; i < MX; i++) {
    for (int be = 0; be <= n; be++)
      for (int be1 = 0; be1 < MX; be1++) dp[be][be1] = INF;
    dp[0][i] = 0;
    for (int k = 0; k < n; k++) {
      for (int be = 0; be < MX; be++) {
        if (be + 1 < n + n)
          dp[k + 1][be + 1] = min(dp[k + 1][be + 1], dp[k][be] + a[k]);
        if (be > 0)
          dp[k + 1][be - 1] = min(dp[k + 1][be - 1], dp[k][be] + b[k]);
      }
    }
    for (int j = 0; j < MX; j++) go.a[i][j] = dp[n][j];
  }
  printf("%lld", bin_pow(go, m).a[0][0]);
  return 0;
}
