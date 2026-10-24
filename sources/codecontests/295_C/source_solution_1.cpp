#include <bits/stdc++.h>
using namespace std;
long long dp[2][55][55];
int t[2][55][55];
queue<pair<int, int> > que[2];
int n, lim, ans1, ans2, A, B;
long long C[55][55];
bool solve() {
  int g = 0, h = 1;
  while (!que[g].empty()) {
    while (!que[g].empty()) {
      int a = que[g].front().first, b = que[g].front().second;
      que[g].pop();
      if (g == 1 && a == A && b == B) {
        ans1 = t[g][a][b];
        ans2 = dp[g][a][b];
        return true;
      }
      for (int i = 0; i <= a; i++)
        for (int j = 0; j <= b; j++) {
          if (i + j == 0) continue;
          if (i + 2 * j > lim) break;
          int p = A - a + i, q = B - b + j;
          if (t[h][p][q] == -1) {
            t[h][p][q] = t[g][a][b] + 1;
            que[h].push(make_pair(p, q));
          }
          if (t[h][p][q] == t[g][a][b] + 1) {
            dp[h][p][q] +=
                dp[g][a][b] * C[a][i] % 1000000007 * C[b][j] % 1000000007;
            dp[h][p][q] %= 1000000007;
          }
        }
    }
    swap(g, h);
  }
  return false;
}
int main() {
  for (int i = 0; i <= 50; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++)
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % 1000000007;
  }
  scanf("%d%d", &n, &lim);
  lim /= 50;
  A = B = 0;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    if (x == 50)
      A++;
    else
      B++;
  }
  memset(t, -1, sizeof(t));
  dp[0][A][B] = 1;
  t[0][A][B] = 0;
  que[0].push(make_pair(A, B));
  ans1 = -1, ans2 = 0;
  solve();
  printf("%d\n%d\n", ans1, ans2);
  return 0;
}
