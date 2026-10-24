#include <bits/stdc++.h>
using namespace std;
const long long infi = 1000000000000000009;
int subset_fav[201009 + 10];
int dp[201009 + 10];
int puppy[201009 + 10];
int main() {
  int a, b, k, t, i, j;
  scanf("%d%d%d%d", &a, &b, &k, &t);
  for (i = -k; i <= k; i++) {
    subset_fav[i + 100309] = 1;
  }
  for (i = 2; i <= 201009; i++) puppy[i] = puppy[i - 1] + subset_fav[i];
  for (i = 2; i <= t; i++) {
    for (j = 1; j <= 201009; j++) {
      int l = max(1, j - k);
      int r = min(201009, j + k);
      int su = puppy[r] - puppy[l - 1];
      if (su < 0) su += 1000000007;
      dp[j] = su;
    }
    for (j = 1; j <= 201009; j++) {
      puppy[j] = 0;
      subset_fav[j] = dp[j];
      dp[j] = 0;
      puppy[j] = puppy[j - 1] + subset_fav[j];
      if (puppy[j] > 1000000007) puppy[j] -= 1000000007;
    }
  }
  long long ans = 0;
  for (i = 105; i <= 201009 - 200; i++) {
    long long aa =
        ((long long)subset_fav[i] * (long long)puppy[i + a - b - 1]) %
        1000000007;
    ans = ans + aa;
  }
  ans = ans % 1000000007;
  printf("%lld\n", ans);
  return 0;
}
