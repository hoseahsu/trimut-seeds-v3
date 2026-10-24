#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


constexpr lint mod = 998244353;
lint emod(lint a, lint p = mod) { return (a % p + p) % p; }

int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (int i = 0; i < n; ++i) cin >> a[i], --a[i];
  int w = count(begin(a), end(a), 0);
  if (!w) return cout << 0 << '\n', 0;
  if (w == n) {
    lint res = 1;
    for (int i = 2; i <= n; ++i) (res *= i) %= mod;
    cout << res << '\n';
    return 0;
  }
  for (int i = 1; i < n; ++i) if (a[i - 1] and !a[i]) {
    rotate(begin(a), next(begin(a), i), end(a));
    break;
  }
  bitset<300000> b;
  for (int i = 1; i < n; ++i) {
    if (b[a[i]] and a[i - 1] != a[i]) return cout << 0 << '\n', 0;
    b[a[i]] = true;
  }
  V<> ls(n, -1), rs(n, -1);
  for (int i = 0; i < n; ++i) if (ls[a[i]] == -1) ls[a[i]] = i;
  for (int i = n - 1; i >= 0; --i) if (rs[a[i]] == -1) rs[a[i]] = i + 1;
  for (int i = 0; i < n; ++i) if (ls[i] != -1 and rs[i] - ls[i] > w) return cout << 0 << '\n', 0;
  lint res = 1;
  int c = 0;
  bitset<300001> used;
  for (int i = 0; i < n; ++i) if (ls[i] != -1) {
    if (rs[i] - ls[i] < w) {
      if (!used[ls[i] - 1] and !used[rs[i]]) return cout << 0 << '\n', 0;
      if (used[ls[i] - 1] and used[rs[i]]) (res *= w - (rs[i] - ls[i]) + 1) %= mod;
    }
    for (int j = ls[i]; j < rs[i]; ++j) used[j] = true;
    if (!i) {
      used[n] = true;
      continue;
    }
    if (used[ls[i] - 1] ^ used[rs[i]]) c += rs[i] - ls[i] - 1;
    if (used[ls[i] - 1] and used[rs[i]]) c += rs[i] - ls[i] + w - 2;
  } else {
    (res *= c) %= mod;
    --c;
  }
  cout << emod(res) << '\n';
}