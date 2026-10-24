#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const int mod = 1e9 + 7;
void reduce(int &a) { a += a >> 31 & mod; }
int Mod(int x) { return x >= mod ? x - mod : x; }
long long read() {
  long long x = 0;
  int f = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + (ch ^ 48);
  return x * f;
}
void print(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) print(x / 10);
  putchar(x % 10 + '0');
}
const int N = 500010;
int n, m, dp[N][8], pc[8], g[N];
int a[N][4];
void solve2() {
  for (int i = 0; i < 4; i++) dp[1][i] = pc[i ^ g[1]];
  for (int i = 2; i <= n; i++) {
    dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + pc[g[i]];
    dp[i][1] = min(dp[i - 1][0], dp[i - 1][3]) + pc[g[i] ^ 1];
    dp[i][2] = min(dp[i - 1][0], dp[i - 1][3]) + pc[g[i] ^ 2];
    dp[i][3] = min(dp[i - 1][1], dp[i - 1][2]) + pc[g[i] ^ 3];
  }
  int minn = 1061109567;
  for (int i = 0; i < 4; i++) minn = min(minn, dp[n][i]);
  print(minn), putchar('\n');
}
void solve3() {
  for (int i = 0; i < 8; i++) dp[1][i] = pc[i ^ g[1]];
  for (int i = 2; i <= n; i++) {
    dp[i][0] = min(dp[i - 1][5], dp[i - 1][2]) + pc[g[i]];
    dp[i][1] = min(dp[i - 1][3], dp[i - 1][4]) + pc[g[i] ^ 1];
    dp[i][2] = min(dp[i - 1][0], dp[i - 1][7]) + pc[g[i] ^ 2];
    dp[i][3] = min(dp[i - 1][1], dp[i - 1][6]) + pc[g[i] ^ 3];
    dp[i][4] = min(dp[i - 1][1], dp[i - 1][6]) + pc[g[i] ^ 4];
    dp[i][5] = min(dp[i - 1][0], dp[i - 1][7]) + pc[g[i] ^ 5];
    dp[i][6] = min(dp[i - 1][3], dp[i - 1][4]) + pc[g[i] ^ 6];
    dp[i][7] = min(dp[i - 1][5], dp[i - 1][2]) + pc[g[i] ^ 7];
  }
  int minn = 1061109567;
  for (int i = 0; i < 8; i++) minn = min(minn, dp[n][i]);
  print(minn), putchar('\n');
}
int main() {
  n = read(), m = read();
  if (n >= 4 && m >= 4) {
    puts("-1");
    return 0;
  }
  if (n == 1 || m == 1) {
    puts("0");
    return 0;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      char ch = getchar();
      while (ch != '0' && ch != '1') ch = getchar();
      if (n < m)
        a[j][i] = ch - '0';
      else
        a[i][j] = ch - '0';
    }
  if (n < m) swap(n, m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) g[i] = g[i] + (a[i][j] << j - 1);
  pc[0] = 0;
  pc[1] = pc[2] = pc[4] = 1;
  pc[3] = pc[5] = pc[6] = 2;
  pc[7] = 3;
  if (m == 2)
    solve2();
  else
    solve3();
}
