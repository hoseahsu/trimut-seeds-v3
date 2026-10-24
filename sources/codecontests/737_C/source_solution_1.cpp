#include <bits/stdc++.h>
using namespace std;
template <class T>
void dbg(const char* xn, T x) {
  if (0) cout << xn << ": " << x << "\n";
}
template <class T, class... TA>
void dbg(const char* xn, T x, TA... t) {
  while (*xn != ',')
    if (0) cout << *xn++;
  if (0) cout << ": " << x << ",";
  dbg(xn + 1, t...);
}
template <class T>
inline bool upd_max(T& x, T y) {
  return y > x ? x = y, true : false;
}
template <class T>
inline bool upd_min(T& x, T y) {
  return y < x ? x = y, true : false;
}
const int N = 400007;
long long n, root, depth[N], rst = 0;
void buildTree() {
  long long it = n;
  for (long long i = 1; i < it; ++i) {
    if (depth[i + 1] > depth[i] + 1) {
      ++depth[i];
      ++rst;
      --i;
      --it;
    }
  }
}
void solve() {
  cin >> n >> root;
  for (long long i = 1; i <= (n); ++i) cin >> depth[i];
  if (depth[root] != 0) depth[root] = 0, ++rst;
  for (long long i = 1; i <= (n); ++i) {
    if (i == root) continue;
    if (depth[i] == 0) depth[i] = 1000000007LL;
  }
  sort(depth, depth + n + 1);
  buildTree();
  cout << rst;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout << fixed << setprecision(10);
  solve();
  return 0;
}
