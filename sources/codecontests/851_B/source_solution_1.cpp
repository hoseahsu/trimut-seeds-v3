#include <bits/stdc++.h>
using namespace std;
const int M = 1000000007;
const int MM = 998244353;
const long double PI = acos(-1);
long long power(long long b, long long e, long long m) {
  if (e == 0) return 1;
  if (e & 1) return b * power(b * b % m, e / 2, m) % m;
  return power(b * b % m, e / 2, m);
}
long long power(long long b, long long e) {
  if (e == 0) return 1;
  if (e & 1) return b * power(b * b, e / 2);
  return power(b * b, e / 2);
}
template <typename T, typename U>
static inline void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
static inline void amax(T &x, U y) {
  if (x < y) x = y;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  return os << '(' << p.first << "," << p.second << ')';
}
int _runtimeTerror_() {
  long long a[2], b[2], c[2];
  cin >> a[0] >> a[1] >> b[0] >> b[1] >> c[0] >> c[1];
  bool ans = true;
  auto dis = [&](long long x, long long y, long long z, long long w) {
    return (z - x) * (z - x) + (w - y) * (w - y);
  };
  if (dis(a[0], a[1], b[0], b[1]) != dis(b[0], b[1], c[0], c[1])) ans = false;
  if ((c[1] - b[1]) * (b[0] - a[0]) == (b[1] - a[1]) * (c[0] - b[0]))
    ans = false;
  cout << (ans ? "Yes" : "No");
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int TESTS = 1;
  while (TESTS--) _runtimeTerror_();
  return 0;
}
