#include <bits/stdc++.h>
using namespace std;
template <typename T>
void out(T x) {
  cout << x << endl;
  exit(0);
}
const long long mod = 1e9 + 7;
const int maxn = 55;
const int maxr = 5500;
int n;
double R;
double f[maxn], s[maxn], p[maxn];
double dp[maxn][maxr];
void reset() {
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < maxr; j++) {
      dp[i][j] = 0;
    }
  }
}
double get(double t) {
  reset();
  for (int i = n - 1; i >= 0; i--) {
    for (int r = 0; r <= R; r++) {
      double& cur = dp[i][r] = 0;
      if (r + f[i] <= R) {
        cur += p[i] * (f[i] + dp[i + 1][int(r + f[i])]);
        if (r + s[i] <= R) {
          cur += (1 - p[i]) * (s[i] + dp[i + 1][int(r + s[i])]);
        } else {
          cur += (1 - p[i]) * (s[i] + t);
        }
      } else {
        cur = t;
      }
      cur = min(cur, t);
    }
  }
  return dp[0][0];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  cin >> R;
  for (int i = 0; i < n; i++) {
    cin >> f[i] >> s[i] >> p[i];
    p[i] = p[i] / 100;
  }
  double lo = 0;
  double hi = 1e9;
  for (int iter = 0; iter < 500; iter++) {
    double mid = (lo + hi) / 2;
    if (get(mid) < mid) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  cout << fixed << setprecision(12) << lo << endl;
  return 0;
}
