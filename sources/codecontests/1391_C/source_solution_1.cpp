#include <bits/stdc++.h>
using namespace std;
using lnt = long long;
using Real = long double;
constexpr int dx[] = {1, 0, -1, 0, 1, 1, -1, -1},
              dy[] = {0, -1, 0, 1, 1, -1, 1, -1};
constexpr Real eps = 1e-9;
const Real pi = acosl(-1);
constexpr lnt BIG = INT_MAX / 10, BBIG = LLONG_MAX / 10;
template <class T>
inline T GCD(T a, T b) {
  T c;
  while (b != 0) {
    c = a % b;
    a = b;
    b = c;
  }
  return a;
}
template <class T>
inline T LCM(T a, T b) {
  T c = GCD(a, b);
  a /= c;
  return a * b;
}
template <class T>
inline T nCr(T a, T b) {
  T i, r = 1;
  for (i = 1; i <= b; i++) {
    r *= (a + 1 - i);
    r /= i;
  }
  return r;
}
template <class T>
inline T nHr(T a, T b) {
  return nCr(a + b - 1, b);
}
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
using pint = pair<int, int>;
using plnt = pair<lnt, lnt>;
using vint = vector<int>;
using vlnt = vector<lnt>;
constexpr lnt MOD = 1e9 + 7;
lnt fact[1000010], invfact[1000010];
lnt invmod(lnt a, lnt p) {
  lnt b = p, u = 1, v = 0;
  while (b) {
    lnt t = a / b;
    a -= t * b;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  u %= p;
  if (u < 0) u += p;
  return u;
}
void factmod(lnt m) {
  fact[0] = invfact[0] = 1;
  for (lnt i = 1; i < 1000010; i++) {
    fact[i] = (fact[i - 1] * i) % m;
    invfact[i] = (invfact[i - 1] * invmod(i, m)) % m;
  }
}
lnt nCrmod(lnt n, lnt r, lnt m) {
  return (((fact[n] * invfact[r]) % m) * invfact[n - r]) % m;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  lnt N;
  cin >> N;
  factmod(MOD);
  lnt ans = fact[N];
  lnt minus = 0;
  for (lnt i = 0; i < (N); ++i) {
    lnt num;
    if (i == N - 1 - i) {
      num = nCrmod(N - 1, i, MOD);
    } else {
      num = nCrmod(N - 1, i, MOD);
    }
    num %= MOD;
    minus += num;
    minus %= MOD;
  }
  ans += MOD;
  ans -= minus;
  ans %= MOD;
  cout << ans << '\n';
}
