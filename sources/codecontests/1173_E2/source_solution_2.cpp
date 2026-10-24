#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
int mod = MOD;
struct ModInt {
  unsigned val;
  ModInt() : val(0) {}
  ModInt(long long x) : val(x >= 0 ? x % mod : x % mod + mod) {}
  ModInt pow(long long exponent) {
    ModInt tmp = *this, res = 1;
    while (exponent > 0) {
      if (exponent & 1) res *= tmp;
      tmp *= tmp;
      exponent >>= 1;
    }
    return res;
  }
  ModInt &operator+=(const ModInt &rhs) {
    if ((val += rhs.val) >= mod) val -= mod;
    return *this;
  }
  ModInt &operator-=(const ModInt &rhs) {
    if ((val += mod - rhs.val) >= mod) val -= mod;
    return *this;
  }
  ModInt &operator*=(const ModInt &rhs) {
    val = (unsigned long long)val * rhs.val % mod;
    return *this;
  }
  ModInt &operator/=(const ModInt &rhs) { return *this *= rhs.inv(); }
  bool operator==(const ModInt &rhs) const { return val == rhs.val; }
  bool operator!=(const ModInt &rhs) const { return val != rhs.val; }
  bool operator<(const ModInt &rhs) const { return val < rhs.val; }
  bool operator<=(const ModInt &rhs) const { return val <= rhs.val; }
  bool operator>(const ModInt &rhs) const { return val > rhs.val; }
  bool operator>=(const ModInt &rhs) const { return val >= rhs.val; }
  ModInt operator-() const { return ModInt(-val); }
  ModInt operator+(const ModInt &rhs) const { return ModInt(*this) += rhs; }
  ModInt operator-(const ModInt &rhs) const { return ModInt(*this) -= rhs; }
  ModInt operator*(const ModInt &rhs) const { return ModInt(*this) *= rhs; }
  ModInt operator/(const ModInt &rhs) const { return ModInt(*this) /= rhs; }
  friend ostream &operator<<(ostream &os, const ModInt &rhs) {
    return os << rhs.val;
  }
  friend istream &operator>>(istream &is, ModInt &rhs) {
    long long x;
    is >> x;
    rhs = ModInt(x);
    return is;
  }

 private:
  ModInt inv() const {
    unsigned a = val, b = mod;
    int x = 1, y = 0;
    while (b) {
      unsigned tmp = a / b;
      a -= tmp * b;
      swap(a, b);
      x -= tmp * y;
      swap(x, y);
    }
    return ModInt(x);
  }
};
ModInt abs(const ModInt &x) { return x.val; }
struct Combinatorics {
  Combinatorics(int MAX = 5000000) {
    MAX <<= 1;
    fact.resize(MAX + 1);
    fact_inv.resize(MAX + 1);
    fact[0] = 1;
    for (int i = (1); i < (MAX + 1); ++i) fact[i] = fact[i - 1] * i;
    fact_inv[MAX] = ModInt(1) / fact[MAX];
    for (int i = MAX; i > 0; --i) fact_inv[i - 1] = fact_inv[i] * i;
  }
  ModInt nCk(int n, int k) {
    if (n < 0 || n < k || k < 0) return ModInt(0);
    return fact[n] * fact_inv[k] * fact_inv[n - k];
  }
  ModInt nPk(int n, int k) {
    if (n < 0 || n < k || k < 0) return ModInt(0);
    return fact[n] * fact_inv[n - k];
  }
  ModInt nHk(int n, int k) {
    if (n < 0 || k < 0) return ModInt(0);
    return (k == 0 ? ModInt(1) : nCk(n + k - 1, k));
  }

 private:
  vector<ModInt> fact, fact_inv;
};
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = (0); i < (n); ++i) cin >> a[i];
  vector<int> w(n);
  for (int i = (0); i < (n); ++i) cin >> w[i];
  int dl = 0, l = 0;
  for (int i = (0); i < (n); ++i) (a[i] == 0 ? dl : l) += w[i];
  vector<vector<ModInt> > dp(m + 1, vector<ModInt>(m + 1, 0));
  dp[0][0] = 1;
  for (int i = (0); i < (m); ++i)
    for (int j = (0); j < (m); ++j) {
      int sum = l + dl - j + (i - j);
      if (j > dl || j > i || sum <= 0) continue;
      dp[i + 1][j + 1] += dp[i][j] * (dl - j) / sum;
      dp[i + 1][j] += dp[i][j] * (l + (i - j)) / sum;
    }
  vector<ModInt> ans(2, 0);
  ModInt tmp = 1;
  for (int i = (0); i < (dl + 1); ++i) {
    if (i > m) break;
    ans[0] += tmp * dp[m][i];
    if (i < dl) tmp *= (ModInt(1) - ModInt(1) / (dl - i));
  }
  tmp = 1;
  for (int i = (0); i < (m + 1); ++i) {
    ans[1] += tmp * dp[m][m - i];
    tmp *= (ModInt(1) + ModInt(1) / (l + i));
  }
  for (int i = (0); i < (n); ++i) cout << ans[a[i]] * w[i] << '\n';
  return 0;
}
