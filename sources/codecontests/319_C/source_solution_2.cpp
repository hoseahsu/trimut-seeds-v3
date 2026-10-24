#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Line {
  ll b;
  int k;
  Line(int k = 0, ll b = 0) : k(k), b(b) {}
  ll calc(int x) { return (ll)k * x + b; }
  ll cross(Line l) { return (l.b - b) / (k - l.k); }
};
struct CHT {
  vector<Line> lns;
  ll get(int x) {
    int l = 0;
    int r = (int)lns.size() - 2;
    int ans = (int)lns.size() - 1;
    while (l <= r) {
      int m = l + r >> 1;
      if (lns[m].cross(lns[m + 1]) >= x) {
        ans = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    return lns[ans].calc(x);
  }
  void add(Line l) {
    while ((int)lns.size() > 1 &&
           lns.back().cross(l) <= lns[(int)lns.size() - 2].cross(lns.back()))
      lns.pop_back();
    lns.push_back(l);
  }
} cht;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& x : a) cin >> x;
  vector<int> b(n);
  for (int& x : b) cin >> x;
  vector<ll> dp(n);
  dp[0] = 0;
  cht.add(Line(b[0], dp[0]));
  for (int i = 1; i < n; ++i) {
    dp[i] = cht.get(a[i]);
    cht.add(Line(b[i], dp[i]));
  }
  cout << dp[n - 1];
  return 0;
}
