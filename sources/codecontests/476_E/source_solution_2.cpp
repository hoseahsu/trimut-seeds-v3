#include <bits/stdc++.h>
using namespace std;
char s[2001], p[501];
int r[2000], dp[2001][2001];
int main() {
  scanf("%s%s", s, p);
  int ls = strlen(s), lp = strlen(p);
  for (int i = 0; i < ls; i++) {
    int pt = i;
    for (int j = 0; j < lp; j++) {
      while (pt < ls && s[pt] != p[j]) pt++;
      if (pt >= ls) {
        r[i] = -1;
        break;
      } else
        pt++;
    }
    if (r[i] != -1) r[i] = pt;
  }
  dp[0][0] = 0;
  for (int i = 0; i < ls; i++)
    for (int j = 0; j <= i; j++) {
      dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
      if (r[i] != -1)
        dp[r[i]][j + r[i] - i - lp] =
            max(dp[r[i]][j + r[i] - i - lp], dp[i][j] + 1);
    }
  for (int i = 0; i <= ls; i++) printf("%d ", dp[ls][i]);
}
