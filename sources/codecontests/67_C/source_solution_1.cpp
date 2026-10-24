#include <bits/stdc++.h>
using namespace std;
int dp[4100][4100];
int pa[4100][26];
int pb[4100][26];
int last[26];
char ch[4100], ch2[4100];
int val[4];
int main(void) {
  while (scanf("%d%d%d%d", val, val + 1, val + 2, val + 3) == 4) {
    scanf("%s", ch + 1);
    scanf("%s", ch2 + 1);
    int len = strlen(ch + 1), len2 = strlen(ch2 + 1);
    memset(last, 0, sizeof(last));
    for (int i = 1; i <= len; i++) {
      last[ch[i] - 'a'] = i;
      for (int j = 0; j < 26; j++) pa[i][j] = last[j];
    }
    memset(last, 0, sizeof(last));
    for (int i = 1; i <= len2; i++) {
      last[ch2[i] - 'a'] = i;
      for (int j = 0; j < 26; j++) pb[i][j] = last[j];
    }
    for (int i = 0; i <= len; i++) {
      for (int j = 0; j <= len2; j++) {
        if (i + j) {
          dp[i][j] = 100000000;
          if (i > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j] + val[1]);
          if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j - 1] + val[0]);
          if (i > 0 && j > 0) {
            if (ch[i] == ch2[j]) {
              dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            } else
              dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + val[2]);
          }
          if (i > 1 && j > 1) {
            int ii = pa[i - 1][ch2[j] - 'a'];
            int jj = pb[j - 1][ch[i] - 'a'];
            if (ii > 0 && jj > 0) {
              int cst = dp[ii - 1][jj - 1] + (i - ii - 1) * val[1] +
                        (j - jj - 1) * val[0] + val[3];
              dp[i][j] = min(dp[i][j], cst);
            }
          }
        } else
          dp[i][j] = 0;
      }
    }
    cout << dp[strlen(ch + 1)][strlen(ch2 + 1)] << endl;
  }
  return 0;
}
