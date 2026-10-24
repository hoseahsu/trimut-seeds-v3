#include <bits/stdc++.h>
using namespace std;
int N, M;
long long dp[300005];
vector<vector<long long> > cost(4);
int one[300005], tow[300005];
int T(int num) {
  num -= one[num];
  return num / 2;
}
int main() {
  scanf("%d%d", &N, &M);
  long long s = 0, ww = 0;
  for (int i = 0; i < N; i++) {
    int w, c;
    scanf("%d%d", &w, &c);
    cost[w].push_back(c);
    s += c;
    ww += w;
  }
  if (ww <= M) return cout << s, 0;
  for (int i = 1; i < 4; i++)
    sort(cost[i].begin(), cost[i].end(), greater<long long>());
  dp[0] = 0;
  int j = 1, k = 0;
  for (int i = 2; i <= M; i++) one[i] = tow[i] = 1e9;
  for (int i = 1; i <= M; i++) {
    dp[i] = dp[i - 1];
    if (i > 1) {
      if (one[i - 1] < cost[1].size() && tow[i - 2] < cost[2].size()) {
        if (dp[i - 1] + cost[1][one[i - 1]] > dp[i - 2] + cost[2][tow[i - 2]])
          dp[i] = dp[i - 1] + cost[1][one[i - 1]], one[i] = one[i - 1] + 1,
          tow[i] = tow[i - 1];
        else
          dp[i] = dp[i - 2] + cost[2][tow[i - 2]], one[i] = one[i - 2],
          tow[i] = tow[i - 2] + 1;
      } else if (one[i - 1] < cost[1].size())
        dp[i] = dp[i - 1] + cost[1][one[i - 1]], one[i] = one[i - 1] + 1,
        tow[i] = tow[i - 1];
      else if (tow[i - 2] < cost[2].size())
        dp[i] = dp[i - 2] + cost[2][tow[i - 2]], tow[i] = tow[i - 2] + 1,
        one[i] = one[i - 2];
    } else if (i == 1 && cost[1].size()) {
      dp[i] = cost[1][0];
      one[i] = 1;
    }
  }
  long long best = 0, bestTake = 0;
  for (int i = 1; i <= M; i++) {
    if (dp[i] > bestTake) bestTake = dp[i], best = i;
    dp[i] = max(dp[i], dp[i - 1]);
  }
  long long ans = dp[best];
  for (int i = 1; i < cost[3].size(); i++) {
    cost[3][i] += cost[3][i - 1];
  }
  for (int i = 0; i < cost[3].size(); i++) {
    if (M - 3 * (i + 1) >= 0) ans = max(ans, cost[3][i] + dp[M - 3 * (i + 1)]);
  }
  cout << ans << "\n";
  return 0;
}
