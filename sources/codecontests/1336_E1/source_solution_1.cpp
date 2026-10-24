#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << '{';
  string sep;
  for (const auto &x : v) os << sep << x, sep = ", ";
  return os << '}';
}
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
template <const int &MOD>
struct _m_int {
  int val;
  _m_int(int64_t v = 0) {
    if (v < 0) v = v % MOD + MOD;
    if (v >= MOD) v %= MOD;
    val = v;
  }
  static int inv_mod(int a, int m = MOD) {
    int g = m, r = a, x = 0, y = 1;
    while (r != 0) {
      int q = g / r;
      g %= r;
      swap(g, r);
      x -= q * y;
      swap(x, y);
    }
    return x < 0 ? x + m : x;
  }
  explicit operator int() const { return val; }
  explicit operator int64_t() const { return val; }
  _m_int &operator+=(const _m_int &other) {
    val -= MOD - other.val;
    if (val < 0) val += MOD;
    return *this;
  }
  _m_int &operator-=(const _m_int &other) {
    val -= other.val;
    if (val < 0) val += MOD;
    return *this;
  }
  static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
    return x % m;
    unsigned x_high = x >> 32, x_low = (unsigned)x;
    unsigned quot, rem;
    asm("divl %4\n" : "=a"(quot), "=d"(rem) : "d"(x_high), "a"(x_low), "r"(m));
    return rem;
  }
  _m_int &operator*=(const _m_int &other) {
    val = fast_mod((uint64_t)val * other.val);
    return *this;
  }
  _m_int &operator/=(const _m_int &other) { return *this *= other.inv(); }
  friend _m_int operator+(const _m_int &a, const _m_int &b) {
    return _m_int(a) += b;
  }
  friend _m_int operator-(const _m_int &a, const _m_int &b) {
    return _m_int(a) -= b;
  }
  friend _m_int operator*(const _m_int &a, const _m_int &b) {
    return _m_int(a) *= b;
  }
  friend _m_int operator/(const _m_int &a, const _m_int &b) {
    return _m_int(a) /= b;
  }
  _m_int &operator++() {
    val = val == MOD - 1 ? 0 : val + 1;
    return *this;
  }
  _m_int &operator--() {
    val = val == 0 ? MOD - 1 : val - 1;
    return *this;
  }
  _m_int operator++(int) {
    _m_int before = *this;
    ++*this;
    return before;
  }
  _m_int operator--(int) {
    _m_int before = *this;
    --*this;
    return before;
  }
  _m_int operator-() const { return val == 0 ? 0 : MOD - val; }
  bool operator==(const _m_int &other) const { return val == other.val; }
  bool operator!=(const _m_int &other) const { return val != other.val; }
  _m_int inv() const { return inv_mod(val); }
  _m_int pow(int64_t p) const {
    if (p < 0) return inv().pow(-p);
    _m_int a = *this, result = 1;
    while (p > 0) {
      if (p & 1) result *= a;
      a *= a;
      p >>= 1;
    }
    return result;
  }
  friend ostream &operator<<(ostream &os, const _m_int &m) {
    return os << m.val;
  }
};
extern const int MOD = 998244353;
using mod_int = _m_int<MOD>;
const int BITS = 53;
template <typename T>
struct xor_basis {
  T basis[BITS];
  int n = 0;
  T min_value(T start) const {
    if (n == BITS) return 0;
    for (int i = 0; i < n; i++) start = min(start, start ^ basis[i]);
    return start;
  }
  T max_value(T start = 0) const {
    if (n == BITS) return ((T)1 << BITS) - 1;
    for (int i = 0; i < n; i++) start = max(start, start ^ basis[i]);
    return start;
  }
  bool add(T x) {
    x = min_value(x);
    if (x == 0) return false;
    basis[n++] = x;
    for (int k = n - 1; k > 0 && basis[k] > basis[k - 1]; k--)
      swap(basis[k], basis[k - 1]);
    return true;
  }
  void merge(const xor_basis<T> &other) {
    for (int i = 0; i < other.n && n < BITS; i++) add(other.basis[i]);
  }
  void merge(const xor_basis<T> &a, const xor_basis<T> &b) {
    if (a.n > b.n) {
      *this = a;
      merge(b);
    } else {
      *this = b;
      merge(a);
    }
  }
};
vector<int64_t> generate_all(vector<int64_t> basis, int M) {
  int B = basis.size();
  vector<int64_t> change(B + 1, 0);
  int64_t prefix = 0;
  for (int i = 0; i < B; i++) {
    prefix ^= basis[i];
    change[i] = prefix;
  }
  change[B] = prefix;
  vector<int64_t> answers(M + 1, 0);
  int64_t value = 0;
  for (unsigned mask = 0; mask < 1U << B; mask++) {
    answers[__builtin_popcountll(value)]++;
    value ^= change[__builtin_ctz(mask + 1)];
  }
  return answers;
}
vector<int64_t> dp_on_repeats(vector<int64_t> basis, int M) {
  int B = basis.size();
  for (int i = 0; i < B; i++)
    for (int j = i + 1; j < B; j++)
      basis[i] = min(basis[i], basis[i] ^ basis[j]);
  vector<int> repeats;
  for (int bit = 0; bit < M; bit++) {
    int count = 0;
    for (int i = 0; i < B; i++)
      if (basis[i] >> bit & 1) count++;
    if (count > 1) repeats.push_back(bit);
  }
  int R = repeats.size();
  vector<pair<int, int>> options(B);
  int count_sum = 0;
  for (int i = 0; i < B; i++) {
    int64_t value = basis[i];
    int count = __builtin_popcountll(value);
    int repeat_mask = 0;
    for (int r = 0; r < R; r++)
      if (value >> repeats[r] & 1) {
        count--;
        repeat_mask |= 1 << r;
      }
    options[i] = {count, repeat_mask};
    count_sum += count;
  }
  sort(options.begin(), options.end());
  vector<vector<mod_int>> dp(count_sum + 1, vector<mod_int>(1 << R, 0));
  dp[0][0] = 1;
  int max_count = 0;
  for (pair<int, int> &option : options) {
    int opt_count = option.first;
    int opt_mask = option.second;
    for (int count = max_count; count >= 0; count--)
      for (int mask = 0; mask < 1 << R; mask++)
        dp[count + opt_count][mask ^ opt_mask] += dp[count][mask];
    max_count += opt_count;
  }
  vector<int64_t> answers(M + 1, 0);
  for (int count = 0; count <= count_sum; count++)
    for (int mask = 0; mask < 1 << R; mask++)
      answers[count + __builtin_popcount(mask)] += (int)dp[count][mask];
  return answers;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  xor_basis<int64_t> basis_obj;
  for (int i = 0; i < N; i++) {
    int64_t a;
    cin >> a;
    basis_obj.add(a);
  }
  int B = basis_obj.n;
  vector<int64_t> basis(B);
  for (int i = 0; i < B; i++) basis[i] = basis_obj.basis[i];
  vector<int64_t> answers =
      B <= 0.6 * M ? generate_all(basis, M) : dp_on_repeats(basis, M);
  for (int i = 0; i <= M; i++) {
    mod_int answer = answers[i];
    answer *= mod_int(2).pow(N - B);
    cout << answer << (i < M ? ' ' : '\n');
  }
}
