#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e6 + 10, maxn = 1e6 + 10;
long long cnt[MAXN], dp[MAXN], cnt2[MAXN];
int main() {
  long long n;
  int x;
  cin >> n;
  for (int i = 0; i < n; i++) scanf("%d", &x), cnt2[x]++;
  for (int i = 1; i < MAXN; i++)
    if (cnt2[i])
      for (int j = 1; i * j < MAXN; j++) {
        if (i == j and cnt2[i] > 1)
          cnt[i * j] += cnt2[i] * (cnt2[i] - 1);
        else if (i != j)
          cnt[i * j] += cnt2[i] * cnt2[j];
      }
  int m;
  dp[0] = 1LL * n * (n - 1);
  for (int i = 1; i < MAXN; i++) dp[i] = dp[i - 1] - cnt[i - 1];
  scanf("%d", &m);
  for (int i = 0; i < m; i++) scanf("%d", &x), printf("%I64d \n", dp[x]);
  return 0;
}
