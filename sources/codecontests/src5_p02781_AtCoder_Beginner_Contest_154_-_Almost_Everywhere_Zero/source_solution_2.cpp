#include <iostream>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

ll dp[105][2][5];

int main() {
  string s;
  cin >> s;
  int M;
  cin >> M;
  int n = s.size();

  dp[0][0][0] = 1;
  rep(i, n) rep(j, 2) for (int k = 0; k <= M; ++k) {
    int D = s[i] - '0';
    for (int d = 0; d <= (j ? 9 : D); ++d) {
      dp[i + 1][j || d < D][min(M + 1, (k + (d != 0)))] += dp[i][j][k];
    }
  }

  cout << dp[n][0][M] + dp[n][1][M] << endl;
  return 0;
}
