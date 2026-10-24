#include <bits/stdc++.h>
using namespace std;
struct fast_ios {
  fast_ios() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  };
} fast_ios_;
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (auto &x : v) is >> x;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> &v) {
  for (long long i = 0; i < v.size(); i++) {
    cout << v[i];
    if (i != v.size() - 1) cout << endl;
  };
  return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, pair<T1, T2> p) {
  cout << '(' << p.first << ',' << p.second << ')';
  return os;
}
template <typename T>
void Out(T x) {
  cout << x << endl;
}
template <typename T1, typename T2>
void Ans(bool first, T1 y, T2 n) {
  if (first)
    Out(y);
  else
    Out(n);
}
using vec = vector<long long>;
using mat = vector<vec>;
using Pii = pair<long long, long long>;
using PiP = pair<long long, Pii>;
using PPi = pair<Pii, long long>;
using Pdi = pair<double, long long>;
using bools = vector<bool>;
using pairs = vector<Pii>;
const long long mod = 998244353;
template <long long MOD>
struct ModInt {
  using ll = long long;
  ll val;
  void setval(ll v) { val = v % MOD; };
  ModInt() : val(0) {}
  ModInt(ll v) { setval(v); };
  ModInt operator+(const ModInt &x) const { return ModInt(val + x.val); }
  ModInt operator-(const ModInt &x) const { return ModInt(val - x.val + MOD); }
  ModInt operator*(const ModInt &x) const { return ModInt(val * x.val); }
  ModInt operator/(const ModInt &x) const { return *this * x.inv(); }
  ModInt operator-() const { return ModInt(MOD - val); }
  ModInt operator+=(const ModInt &x) { return *this = *this + x; }
  ModInt operator-=(const ModInt &x) { return *this = *this - x; }
  ModInt operator*=(const ModInt &x) { return *this = *this * x; }
  ModInt operator/=(const ModInt &x) { return *this = *this / x; }
  friend ostream &operator<<(ostream &os, const ModInt &x) {
    os << x.val;
    return os;
  }
  friend istream &operator>>(istream &is, ModInt &x) {
    is >> x.val;
    x.val = (x.val % MOD + MOD) % MOD;
    return is;
  }
  ModInt pow(ll n) const {
    ModInt a = 1;
    if (n == 0) return a;
    long long i0 = 64 - __builtin_clzll(n);
    for (long long i = i0 - 1; i >= 0; i--) {
      a = a * a;
      if ((n >> i) & 1) a *= (*this);
    }
    return a;
  }
  ModInt inv() const { return this->pow(MOD - 2); }
};
using mint = ModInt<mod>;
mint pow(mint x, long long n) { return x.pow(n); }
using mvec = vector<mint>;
using mmat = vector<mvec>;
struct Combination {
  vector<mint> fact, invfact;
  Combination(long long N) {
    fact = vector<mint>({mint(1)});
    invfact = vector<mint>({mint(1)});
    fact_initialize(N);
  }
  void fact_initialize(long long N) {
    long long i0 = fact.size();
    if (i0 >= N + 1) return;
    fact.resize(N + 1);
    invfact.resize(N + 1);
    for (long long i = i0; i <= N; i++) fact[i] = fact[i - 1] * i;
    invfact[N] = (mint)1 / fact[N];
    for (long long i = N - 1; i >= i0; i--)
      invfact[i] = invfact[i + 1] * (i + 1);
  }
  mint nCr(long long n, long long r) {
    if (n < 0 || r < 0 || r > n) return mint(0);
    if (fact.size() < n + 1) fact_initialize(n);
    return fact[n] * invfact[r] * invfact[n - r];
  }
  mint nPr(long long n, long long r) {
    if (n < 0 || r < 0 || r > n) return mint(0);
    if (fact.size() < n + 1) fact_initialize(n);
    return fact[n] * invfact[n - r];
  }
  mint Catalan(long long n) {
    if (n < 0)
      return 0;
    else if (n == 0)
      return 1;
    if (fact.size() < 2 * n + 1) fact_initialize(2 * n);
    return fact[2 * n] * invfact[n + 1] * invfact[n];
  }
};
signed main() {
  long long n;
  cin >> n;
  vec a(n);
  cin >> a;
  long long t = 0;
  for (long long i = (0); i < (n); i++) t += a[i];
  mvec first(t + 1, 0);
  first[0] = n - 1;
  for (long long i = (1); i < (t); i++) {
    mint p_u = (mint)(t - i) / mint(t * (n - 1));
    mint p_d = (mint)i / (mint)t;
    first[i] = (p_d * first[i - 1] + 1) / p_u;
  }
  for (long long i = (t)-1; i >= (0); i--) first[i] += first[i + 1];
  mint ans = 0;
  for (long long i = (0); i < (n); i++) ans += first[a[i]];
  ans -= first[0] * (n - 1);
  ans /= n;
  Out(ans);
  return 0;
}
