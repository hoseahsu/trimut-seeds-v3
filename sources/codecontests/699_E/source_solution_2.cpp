#include <bits/stdc++.h>
using namespace std;
const int N = 22;
double p[N], dp[1 << N], a[N];
int n, k;
int main() {
  while (cin >> n >> k) {
    for (int i = 0; i < n; ++i) cin >> p[i];
    memset(dp, 0, sizeof dp);
    memset(a, 0, sizeof a);
    dp[0] = 1;
    for (int s = 0; s < (1 << n); ++s) {
      double sum = 0;
      int c = 0;
      for (int i = 0; i < n; ++i)
        if ((s & (1 << i)) == 0) sum += p[i], ++c;
      if (sum < 1e-9) continue;
      if (n - c + 1 > k) continue;
      for (int i = 0; i < n; ++i)
        if ((s & (1 << i)) == 0)
          dp[s | (1 << i)] += dp[s] * p[i] / sum, a[i] += dp[s] * p[i] / sum;
    }
    for (int i = 0; i < n; ++i)
      printf("%.12f%c", a[i], i == n - 1 ? '\n' : ' ');
  }
  return 0;
}
