#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize(4)
using namespace std;
const int N = 1e5 + 5;
char s[N];
int nxt[N][26], n, q, x;
char op[10], cc[10];
int dp[255][255][255];
string a, b, c;
int main() {
  scanf("%d %d", &n, &q);
  scanf("%s", s + 1);
  for (int i = 0; i < 26; ++i) nxt[n + 1][i] = n + 1, nxt[n + 2][i] = n + 1;
  for (int i = n; i >= 1; --i) {
    for (int j = 0; j < 26; ++j) {
      if (j == s[i] - 'a')
        nxt[i][j] = i;
      else
        nxt[i][j] = nxt[i + 1][j];
    }
  }
  while (q--) {
    scanf("%s %d", op, &x);
    if (op[0] == '+') {
      scanf("%s", cc);
      if (x == 1) {
        a.push_back(cc[0]);
        for (int i = 0; i <= b.size(); ++i) {
          for (int j = 0; j <= c.size(); ++j) {
            dp[a.size()][i][j] = n + 1;
            if (a.size() > 0)
              dp[a.size()][i][j] =
                  min(dp[a.size()][i][j],
                      nxt[dp[a.size() - 1][i][j] + 1][a.back() - 'a']);
            if (i > 0)
              dp[a.size()][i][j] =
                  min(dp[a.size()][i][j],
                      nxt[dp[a.size()][i - 1][j] + 1][b[i - 1] - 'a']);
            if (j > 0)
              dp[a.size()][i][j] =
                  min(dp[a.size()][i][j],
                      nxt[dp[a.size()][i][j - 1] + 1][c[j - 1] - 'a']);
          }
        }
      } else if (x == 2) {
        b.push_back(cc[0]);
        for (int i = 0; i <= a.size(); ++i) {
          for (int j = 0; j <= c.size(); ++j) {
            dp[i][b.size()][j] = n + 1;
            if (b.size() > 0)
              dp[i][b.size()][j] =
                  min(dp[i][b.size()][j],
                      nxt[dp[i][b.size() - 1][j] + 1][b.back() - 'a']);
            if (i > 0)
              dp[i][b.size()][j] =
                  min(dp[i][b.size()][j],
                      nxt[dp[i - 1][b.size()][j] + 1][a[i - 1] - 'a']);
            if (j > 0)
              dp[i][b.size()][j] =
                  min(dp[i][b.size()][j],
                      nxt[dp[i][b.size()][j - 1] + 1][c[j - 1] - 'a']);
          }
        }
      } else if (x == 3) {
        c.push_back(cc[0]);
        for (int i = 0; i <= a.size(); ++i) {
          for (int j = 0; j <= b.size(); ++j) {
            dp[i][j][c.size()] = n + 1;
            if (c.size() > 0)
              dp[i][j][c.size()] =
                  min(dp[i][j][c.size()],
                      nxt[dp[i][j][c.size() - 1] + 1][c.back() - 'a']);
            if (i > 0)
              dp[i][j][c.size()] =
                  min(dp[i][j][c.size()],
                      nxt[dp[i - 1][j][c.size()] + 1][a[i - 1] - 'a']);
            if (j > 0)
              dp[i][j][c.size()] =
                  min(dp[i][j][c.size()],
                      nxt[dp[i][j - 1][c.size()] + 1][b[j - 1] - 'a']);
          }
        }
      }
    } else {
      if (x == 1)
        a.pop_back();
      else if (x == 2)
        b.pop_back();
      else if (x == 3)
        c.pop_back();
    }
    if (dp[a.size()][b.size()][c.size()] > n)
      printf("NO\n");
    else
      printf("YES\n");
  }
  return 0;
}
