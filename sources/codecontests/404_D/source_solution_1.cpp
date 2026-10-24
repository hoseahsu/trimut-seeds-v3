#include <bits/stdc++.h>
using namespace std;
int dp[1000005][4][4];
char a[1000005];
int thanks(char x) {
  if (x == '*')
    return 3;
  else
    return x - '0';
}
int main() {
  int i, j, m, n, l, o, ans = 0;
  scanf("%s", a);
  n = strlen(a);
  if (n == 1) {
    if (a[0] == '0' || a[0] == '*')
      printf("1\n");
    else if (a[0] == '?')
      printf("2\n");
    else
      printf("0\n");
    return 0;
  }
  for (i = 0; i <= 3; i++) {
    if (a[0] != '?' && thanks(a[0]) != i) continue;
    for (j = 0; j <= 3; j++) {
      if (a[1] != '?' && thanks(a[1]) != j) continue;
      if (i == 0 && (j != 2 && j != 3))
        dp[1][i][j] = 1;
      else if (i == 1 && j == 3)
        dp[1][i][j] = 1;
      else if (i == 3 && j != 0)
        dp[1][i][j] = 1;
    }
  }
  if (n == 2) {
    for (i = 0; i <= 3; i++) {
      for (j = 0; j <= 3; j++) {
        if ((i == 0 && j == 0) || (i == 1 && j == 3) || (i == 3 && j == 1) ||
            (i == 3 && j == 3))
          ans += dp[1][i][j];
      }
    }
    printf("%d\n", ans);
    return 0;
  }
  for (i = 2; i < n; i++) {
    if (i != n - 1) {
      for (j = 0; j <= 3; j++) {
        for (l = 0; l <= 3; l++) {
          for (o = 0; o <= 3; o++) {
            if (a[i] != '?' && thanks(a[i]) != o) continue;
            if (o == 1 && ((l == 1 && j == 3) || (l == 0) || (l == 3)))
              dp[i][l][o] = (dp[i][l][o] + dp[i - 1][j][l]) % 1000000007;
            else if (o == 2 && l == 3)
              dp[i][l][o] = (dp[i][l][o] + dp[i - 1][j][l]) % 1000000007;
            else if (o == 3 && (l == 2 || (l == 1 && j != 3) || l == 3))
              dp[i][l][o] = (dp[i][l][o] + dp[i - 1][j][l]) % 1000000007;
            else if (o == 0 && ((l == 1 && j == 3) || (l == 0)))
              dp[i][l][o] = (dp[i][l][o] + dp[i - 1][j][l]) % 1000000007;
          }
        }
      }
    } else {
      for (l = 0; l <= 3; l++) {
        for (o = 0; o <= 3; o++) {
          if (a[i] != '?' && thanks(a[i]) != o) continue;
          for (j = 0; j <= 3; j++) {
            if (o == 1 && l == 3)
              dp[i][l][o] = (dp[i][l][o] + dp[i - 1][j][l]) % 1000000007;
            else if (o == 3 && (l == 2 || (l == 1 && j != 3) || l == 3))
              dp[i][l][o] = (dp[i][l][o] + dp[i - 1][j][l]) % 1000000007;
            else if (o == 0 && (l == 0 || (l == 1 && j == 3)))
              dp[i][l][o] = (dp[i][l][o] + dp[i - 1][j][l]) % 1000000007;
          }
          ans = (ans + dp[i][l][o]) % 1000000007;
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
