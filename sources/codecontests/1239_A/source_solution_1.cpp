#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXH = 100000;
const int MAXW = 100000;
const int MAXN = 100000;
const int MOD = 1000000007;
void inc(int &a, int b) {
  if ((a += b) >= MOD) a -= MOD;
}
int h, w;
int dp[MAXN + 1];
int calc(int n) {
  for (int i = (0); i <= (n); ++i) dp[i] = 0;
  dp[0] = 2;
  for (int i = (1); i <= (n); ++i) {
    inc(dp[i], dp[i - 1]);
    if (i - 2 >= 0) inc(dp[i], dp[i - 2]);
  }
  return dp[n];
}
int solve() {
  int a = calc(h);
  int b = calc(w);
  return ((long long)a + b + MOD - 2) % MOD;
}
void run() {
  scanf("%d%d", &h, &w);
  printf("%d\n", solve());
}
int main() {
  run();
  return 0;
}
