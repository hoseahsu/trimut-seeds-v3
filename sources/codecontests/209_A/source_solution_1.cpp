#include <bits/stdc++.h>
using namespace std;
long long int dp[1000001];
long long int findans(long long int indx) {
  if (indx == 1)
    return 1;
  else if (indx <= 0)
    return 0;
  if (dp[indx] != -1) return dp[indx];
  long long int ans = 1;
  ans += (findans(indx - 1) + 1 + findans(indx - 2)) % 1000000007;
  return dp[indx] = ans;
}
int main() {
  int t = 1;
  while (t--) {
    long long int n;
    cin >> n;
    for (int i = 0; i < n + 1; i++) dp[i] = -1;
    long long int sum = 0;
    sum = findans(n);
    cout << sum << endl;
  }
  return 0;
}
