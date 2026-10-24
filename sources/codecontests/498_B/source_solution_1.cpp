#include <bits/stdc++.h>
using namespace std;
double dp[5001][5001];
double tmp[5001];
double cum[5001];
double prob[5001];
int times[5001];
int n;
int maxtime;
inline void compute(int k) {
  double p = prob[k];
  double p2 = 1 - prob[k];
  double sum = 0;
  for (int i = 1; i <= maxtime && i < times[k]; i++) {
    tmp[i] = p;
    sum += p;
    p *= p2;
    if (p < 1e-20) {
      p = 0;
    }
  }
  if (times[k] <= maxtime) {
    tmp[times[k]] = 1 - sum;
    for (int i = times[k] + 1; i <= maxtime; i++) {
      tmp[i] = 0;
    }
  }
  sum = 0;
  for (int i = 1; i <= maxtime; i++) {
    sum += tmp[i];
    cum[i] = sum;
  }
}
void test() {
  for (int k = 0; k < n; k++) {
    compute(k);
    for (int j = 1; j <= maxtime; j++) cerr << tmp[j] << ' ';
    cerr << endl;
    for (int j = 1; j <= maxtime; j++) cerr << cum[j] << ' ';
    cerr << endl;
  }
}
int main() {
  cin >> n >> maxtime;
  for (int i = 0; i < n; i++) {
    int p, t;
    cin >> p >> t;
    prob[i] = p / 100.0;
    times[i] = t;
  }
  memset(dp, 0, sizeof dp);
  memset(tmp, 0, sizeof tmp);
  memset(cum, 0, sizeof cum);
  compute(0);
  for (int j = 1; j <= maxtime; j++) {
    dp[1][j] = tmp[j];
  }
  double add[maxtime + 2];
  double remove[maxtime + 2];
  for (int k = 2; k <= n; k++) {
    memset(add, 0, sizeof add);
    memset(remove, 0, sizeof remove);
    compute(k - 1);
    double curr = 0;
    for (int j = 1; j <= maxtime; j++) {
      dp[k][j] = curr;
      curr -= remove[j];
      curr *= 1 - prob[k - 1];
      curr += add[j];
      curr += dp[k - 1][j] * tmp[1];
      int t = j + times[k - 1] - 1;
      if (t <= maxtime) {
        remove[t] += dp[k - 1][j] * tmp[times[k - 1] - 1];
        add[t] += dp[k - 1][j] * tmp[times[k - 1]];
        remove[t + 1] += add[t];
      }
    }
  }
  double ans = 0;
  for (int k = 1; k <= n; k++) {
    if (k < n)
      compute(k);
    else
      memset(cum, 0, sizeof cum);
    double stuff = 0;
    for (int j = 1; j <= maxtime; j++) {
      stuff += dp[k][j] * (1.0 - cum[maxtime - j]);
    }
    ans += k * stuff;
  }
  cout << setprecision(10) << fixed << ans << endl;
}
