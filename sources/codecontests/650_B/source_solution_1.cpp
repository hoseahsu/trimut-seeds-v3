#include <bits/stdc++.h>
using namespace std;
template <class A, class B>
A cvt(B x) {
  stringstream ss;
  ss << x;
  A y;
  ss >> y;
  return y;
}
int n, a, b, t;
string s;
int solve() {
  int tb = 0;
  vector<int> tm;
  for (int k = n; k >= 1; k--) {
    tb += a;
    if (s[k - 1] != 'h') tb += b;
    tb += 1;
    tm.push_back(tb);
  }
  int best = 0;
  int t1 = 0;
  for (int k = 1; k <= n; k++) {
    if (k != 1) t1 += a;
    if (s[k - 1] != 'h') t1 += b;
    t1 += 1;
    if (t1 > t) break;
    int t2 = t - t1 - (k - 1) * a;
    int l = lower_bound(tm.begin(), tm.end(), t2 + 1) - tm.begin();
    best = max(best, min(k + l, n));
  }
  return best;
}
int main() {
  cin >> n >> a >> b >> t >> s;
  int s1 = solve();
  reverse(s.begin() + 1, s.end());
  int s2 = solve();
  cout << max(s1, s2) << endl;
  return 0;
}
