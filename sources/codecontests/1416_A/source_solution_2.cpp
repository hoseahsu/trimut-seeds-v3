#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using vpii = vector<pii>;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
using vll = vector<long long>;
using vvll = vector<vll>;
template <class T>
using min_queue = priority_queue<T, vector<T>, greater<T>>;
template <class T>
istream &operator>>(istream &, vector<T> &);
template <class T>
ostream &operator<<(ostream &, const vector<T> &);
template <class T, class U>
istream &operator>>(istream &, pair<T, U> &);
template <class T, class U>
ostream &operator<<(ostream &, const pair<T, U> &);
template <class T>
struct Inf {
  static constexpr T inf() {
    return std::numeric_limits<T>::has_infinity
               ? std::numeric_limits<T>::infinity()
               : std::numeric_limits<T>::max();
  }
};
template <>
struct Inf<int> {
  static constexpr int inf() { return 0x3f3f3f3f; }
};
template <>
struct Inf<long long> {
  static constexpr long long inf() { return 0x3f3f3f3f3f3f3f3fLL; }
};
constexpr int INF = Inf<int>::inf();
constexpr ll BINF = Inf<ll>::inf();
struct Solver {
  Solver() {}
  int solve();
};
int Solver::solve() {
  int n;
  cin >> n;
  vi a(n);
  cin >> a;
  for (int &x : a) x--;
  vi ans(n, INF);
  vvi pos(n);
  for (int i = 0; i < n; i++) pos[a[i]].push_back(i);
  for (int i = 0; i < n; i++) {
    if (pos[i].empty()) continue;
    int lst = -1;
    int cmx = 0;
    for (int p : pos[i]) {
      int yo = p - lst;
      lst = p;
      cmx = max(yo - 1, cmx);
    }
    cmx = max(n - lst - 1, cmx);
    ans[cmx] = min(ans[cmx], i);
  }
  for (int i = 1; i < n; i++) ans[i] = min(ans[i], ans[i - 1]);
  for (int &x : ans)
    if (x == INF)
      x = -1;
    else
      x++;
  cout << ans;
  return 0;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  Solver solver;
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) solver.solve();
  return 0;
}
template <class T>
istream &operator>>(istream &is, vector<T> &v) {
  for (auto it = v.begin(); it != v.end(); ++it) is >> *it;
  return is;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (auto it = v.begin(); it != v.end();)
    os << *it, os << " \n"[++it == v.end()];
  return os;
}
template <class T, class U>
istream &operator>>(istream &is, pair<T, U> &p) {
  return is >> p.first >> p.second;
}
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  return os << p.first << ' ' << p.second;
}
