#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const int L_N = 1e5 + 10;
const int L_D = 100 + 5;
struct mat {
  int a[L_D][L_D], n, m;
  void init(int n, int m) {
    this->n = n, this->m = m;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) a[i][j] = 0;
  }
  void init_e(int n) {
    this->n = this->m = n;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) a[i][j] = i == j;
  }
  void print() {
    printf("n:%d m:%d\n", n, m);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        printf("%d ", a[i][j]);
      }
      printf("\n");
    }
  }
};
mat operator*(const mat& a, const mat& b) {
  mat ret;
  ret.init(a.n, b.m);
  for (int i = 1; i <= ret.n; i++) {
    for (int j = 1; j <= ret.m; j++) {
      long long tmp = 0;
      for (int k = 1; k <= a.m; k++) {
        tmp += 1ll * a.a[i][k] * b.a[k][j];
        tmp %= MOD;
      }
      ret.a[i][j] = tmp;
    }
  }
  return ret;
}
mat power(mat d, long long k) {
  mat ret;
  ret.init_e(d.n);
  for (int i = 32; i >= 0; i--) {
    ret = ret * ret;
    if (k & (1ll << i)) {
      ret = ret * d;
    }
  }
  return ret;
}
int N, X, d[L_N];
long long dp[110];
mat UK, ANS, U, D;
int main() {
  scanf("%d %d", &N, &X);
  for (int i = 1; i <= N; i++) scanf("%d", &d[i]);
  U.init(102, 102);
  U.a[1][1] = 1;
  for (int i = 2; i <= 101; i++) U.a[i][i + 1] = 1;
  for (int i = 1; i <= N; i++) U.a[102][102 - d[i] + 1]++;
  U.a[102][1] = 1;
  D.init(102, 1);
  dp[0] = 1;
  for (int i = 1; i <= 100; i++) {
    dp[i] = 1;
    for (int j = 1; j <= N; j++) {
      if (d[j] <= i) dp[i] += dp[i - d[j]], dp[i] %= MOD;
    }
  }
  D.a[1][1] = 1;
  for (int i = 0; i <= 100; i++) D.a[i + 2][1] = dp[i];
  UK = power(U, X);
  ANS = UK * D;
  int ans = ANS.a[2][1];
  printf("%d\n", ans);
  return 0;
}
