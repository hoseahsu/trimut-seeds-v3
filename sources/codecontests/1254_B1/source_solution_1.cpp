#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000100;
int N;
long long arr[MAXN];
long long csum;
long long nv[MAXN];
long long dp[MAXN][2];
long long gogo(long long x) {
  nv[0] = 0;
  for (int i = 0; i < N; i++) {
    nv[i + 1] = (nv[i] + arr[i]) % x;
  }
  for (int i = 0; i <= N; i++) {
    dp[i][0] = dp[i][1] = 3e18;
  }
  dp[0][0] = nv[1];
  dp[0][1] = (x - nv[1]);
  for (int i = 1; i < N; i++) {
    if ((x - nv[i]) + nv[i + 1] <= arr[i])
      dp[i][0] = min(dp[i][0], dp[i - 1][1] + nv[i + 1]);
    if (nv[i + 1] - nv[i] <= arr[i])
      dp[i][0] = min(dp[i][0], dp[i - 1][0] + nv[i + 1]);
    if ((x - nv[i]) + (nv[i + 1] - x) <= arr[i])
      dp[i][1] = min(dp[i][1], dp[i - 1][1] + (x - nv[i + 1]));
    dp[i][1] = min(dp[i][1], dp[i - 1][0] + (x - nv[i + 1]));
  }
  return min(dp[N - 1][1], dp[N - 1][0]);
}
int main() {
  ios_base::sync_with_stdio(0);
  csum = 0;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
    csum += arr[i];
  }
  vector<long long> v;
  for (long long i = 2; i < MAXN; i++) {
    if (csum % i == 0) {
      v.push_back(i);
      while (csum % i == 0) csum /= i;
    }
  }
  if (csum > 1) v.push_back(csum);
  long long ans = 3e18;
  for (long long f : v) ans = min(ans, gogo(f));
  if (ans > 2e18)
    cout << "-1\n";
  else
    cout << ans << "\n";
}
