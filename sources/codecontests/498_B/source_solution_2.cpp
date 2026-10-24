#include <bits/stdc++.h>
int bla = 4;
using namespace std;
const long double pi = acos(-1.0);
const long double eps = 1e-8;
const int INF = 1E9;
const int MAXN = 5111;
int n, T, id, Ti;
long double p[MAXN], t[MAXN], Pi, powP;
long double dp[2][MAXN];
long double sum, mn;
double answer;
int main() {
  cin >> n >> T;
  for (int i = 0; i < (int)(n); i++) cin >> p[i] >> t[i];
  dp[0][0] = 1;
  for (int i = 1; i <= T; i++) dp[0][i] = 0;
  answer = 0;
  id = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= T; j++) dp[id ^ 1][j] = 0;
    Pi = p[i - 1] / 100.0;
    powP = 1;
    Ti = t[i - 1];
    for (int j = 0; j < (int)(Ti - 2); j++) powP *= (1.0 - Pi);
    if (p[i - 1] < 100 && Ti != 1) {
      sum = dp[id][0];
      mn = 1.0;
      for (int j = 1; j < Ti - 1; j++) {
        dp[id ^ 1][j] = sum * Pi;
        sum *= (1.0 - Pi);
        sum += dp[id][j];
      }
      for (int j = Ti - 1; j <= T; j++) {
        dp[id ^ 1][j] = sum * Pi;
        sum -= powP * dp[id][j - Ti + 1];
        sum *= (1.0 - Pi);
        sum += dp[id][j];
      }
      for (int j = Ti; j <= T; j++)
        dp[id ^ 1][j] += dp[id][j - Ti] * powP * (1.0 - Pi);
      mn = (1.0 - Pi);
      for (int j = T - 1; j > T - 1 - (Ti - 1); j--) {
        if (j < 0) break;
        answer += (long double)(i - 1) * dp[id][j] * mn;
        mn *= (1.0 - Pi);
      }
    } else {
      for (int j = 1; j <= T; j++) dp[id ^ 1][j] = dp[id][j - 1];
    }
    answer += dp[id ^ 1][T] * i;
    id ^= 1;
  }
  for (int i = 0; i < T; i++) answer += dp[id][i] * n;
  cout.precision(30);
  cout << answer;
  return 0;
}
