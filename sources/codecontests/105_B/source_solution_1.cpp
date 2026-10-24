#include <bits/stdc++.h>
using namespace std;
int n, k, A;
pair<int, int> X[8];
double maxRes = 0.0;
int d[8];
void getCandy(int curr_idx, int k) {
  if (curr_idx == n) {
    double res = 0.0;
    for (int mask = 0; mask < (1 << n); mask++) {
      int win_votes = 0;
      int level_sum = 0;
      double p = 1.0;
      for (int i = 0; i < n; i++) {
        int level = X[i].first;
        int percent = X[i].second + 10 * d[i];
        double q = (((double)percent) / 100.0);
        if (mask & (1 << i)) {
          win_votes++;
          p *= q;
        } else {
          p *= (1.0 - q);
          level_sum += level;
        }
      }
      if (win_votes > n / 2)
        res += p;
      else
        res += p * (((double)A) / ((double)(A + level_sum)));
    }
    if (res > maxRes) maxRes = res;
  } else {
    for (int i = 0; i <= k && X[curr_idx].second + i * 10 <= 100; i++) {
      d[curr_idx] = i;
      getCandy(curr_idx + 1, k - i);
    }
  }
}
int main() {
  cin >> n >> k >> A;
  for (int i = 0; i < n; i++) {
    cin >> X[i].first >> X[i].second;
  }
  getCandy(0, k);
  printf("%1.10lf\n", maxRes);
  return 0;
}
