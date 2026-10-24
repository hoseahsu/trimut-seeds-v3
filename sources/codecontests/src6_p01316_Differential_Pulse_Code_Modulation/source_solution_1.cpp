#include <iostream>
#include <vector>
#include <limits>
using namespace std;

inline int f(int n)
{
  return max(0, min(255, n));
}

int main()
{
  int N, M;
  while (cin >> N >> M && N != 0) {
    vector<int> cs(M);
    for (int i = 0; i < M; i++) {
      cin >> cs[i];
    }
    vector<int> xs(N);
    for (int i = 0; i < N; i++) {
      cin >> xs[i];
    }

    vector<vector<int> > dp(N+1, vector<int>(256, 100000000));
    dp[0][128] = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j <= 255; j++) {
        for (int k = 0; k < M; k++) {
          const int y = f(j+cs[k]);
          dp[i+1][y] = min(dp[i+1][y], dp[i][j] + (xs[i]-y)*(xs[i]-y));
        }
      }
    }
    int ans = numeric_limits<int>::max();
    for (int i = 0; i <= 255; i++) {
      ans = min(ans, dp[N][i]);
    }
    cout << ans << endl;
  }
  return 0;
}