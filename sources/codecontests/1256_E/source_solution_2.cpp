#include <bits/stdc++.h>
using namespace std;
template <class T>
struct rge {
  T b, e;
};
template <class T>
rge<T> range(T i, T j) {
  return rge<T>{i, j};
};
template <class A, class B>
ostream &operator<<(ostream &os, pair<A, B> p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <class T>
ostream &operator<<(ostream &os, rge<T> d) {
  os << "[";
  for (auto it = d.b; it != d.e; it++) os << (it == d.b ? "" : ", ") << *it;
  return os << "]";
}
const int N = 2e5 + 5;
const long long inf = 1e18;
struct {
  long long diversity = inf;
  int prev = -1;
} dp[N];
int belong[N];
pair<int, int> a[N];
int n;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
  cin >> n;
  for (int i = (1); i <= ((n)); i += (+1)) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a + 1, a + n + 1);
  dp[0].diversity = 0;
  dp[0].prev = 0;
  for (int r = (1); r <= ((n)); r += (+1)) {
    for (int k = (3); k <= (20); k += (+1)) {
      int l = max(0, r - k + 1);
      if (l - 1 >= 0 &&
          dp[l - 1].diversity + a[r].first - a[l].first <= dp[r].diversity) {
        dp[r].diversity = dp[l - 1].diversity + a[r].first - a[l].first;
        dp[r].prev = l - 1;
      }
    }
  }
  int k = 0;
  for (int i = n; i >= 1; i = dp[i].prev) {
    k++;
    for (int j = (i); j >= (dp[i].prev + 1); j += (-1)) {
      belong[a[j].second] = k;
    }
  }
  cout << dp[n].diversity << " " << k << '\n';
  for (int i = (1); i <= ((n)); i += (+1)) {
    cout << belong[i] << " \n"[i == n];
  }
  return 0;
}
