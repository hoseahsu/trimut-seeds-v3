#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
bool Max(T1& a, T2 b) {
  return a < b ? a = b, 1 : 0;
}
template <typename T1, typename T2>
bool Min(T1& a, T2 b) {
  return a > b ? a = b, 1 : 0;
}
const int N = 100, inf = 1e9 + 1;
int fast[N], slow[N], p[N];
int n, cap;
bool lt(double m) {
  vector<double> f(cap + 1, 0);
  int mx = cap + 1;
  for (int i = n - 1; i >= (0); --i) {
    for (int t = 0; t < (mx); ++t) {
      if (t + fast[i] >= mx) {
        mx = t;
        break;
      }
      double v = (fast[i] + f[t + fast[i]]) * p[i];
      v += (slow[i] + (t + slow[i] >= mx ? m : f[t + slow[i]])) * (100 - p[i]);
      v /= 100;
      if (v >= m) {
        mx = t;
        break;
      }
      f[t] = v;
    }
  }
  return mx;
}
void solve() {
  cin >> n >> cap;
  for (int i = 0; i < (n); ++i) cin >> fast[i] >> slow[i] >> p[i];
  double l = 0, r = 1e9;
  for (int it = 0; it < (60); ++it) {
    double m = (l + r) / 2;
    if (lt(m))
      r = m;
    else
      l = m;
  }
  cout << l << '\n';
}
void init() {}
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.setf(ios::fixed);
  cout.precision(20);
  init();
  int TC = 1;
  for (int TI = 1; TI <= (TC); ++TI) {
    solve();
  }
  return 0;
}
