#include <bits/stdc++.h>
using namespace std;
long long dp[4][4][50] = {0L}, t[5][5] = {0L};
bool dped[4][4][50] = {0};
long long move(int n, int from, int thr, int to) {
  if (dped[from][to][n]) return dp[from][to][n];
  dped[from][to][n] = 1L;
  if (n == 0) return dp[from][to][n] = 0L;
  return dp[from][to][n] =
             min(move(n - 1, from, to, thr) + t[from][to] +
                     move(n - 1, thr, from, to),
                 (move(n - 1, from, thr, to) << 1) + t[from][thr] + t[thr][to] +
                     move(n - 1, to, thr, from));
}
int main() {
  for (int i = 1; i <= (3); i++)
    for (int j = 1; j <= (3); j++) scanf("%I64d", &t[i][j]);
  int n;
  scanf("%d", &n);
  printf("%I64d", move(n, 1, 2, 3));
}
