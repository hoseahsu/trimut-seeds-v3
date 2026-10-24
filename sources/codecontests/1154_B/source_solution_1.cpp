#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
long long gcd(long long A, long long B) {
  if (B == 0) return A;
  return gcd(B, A % B);
}
long long lcm(long long A, long long B) { return A * B / gcd(A, B); }
template <typename T>
T pow(T a, long long n, T e = 1) {
  T ret = e;
  while (n) {
    if (n & 1) ret *= a;
    a *= a;
    n >>= 1;
  }
  return ret;
}
template <int mod>
struct ModInt {
  int x;
  ModInt() : x(0) {}
  ModInt(long long x_) {
    if ((x = x_ % mod + mod) >= mod) x -= mod;
  }
  ModInt& operator+=(ModInt rhs) {
    if ((x += rhs.x) >= mod) x -= mod;
    return *this;
  }
  ModInt& operator-=(ModInt rhs) {
    if ((x -= rhs.x) < 0) x += mod;
    return *this;
  }
  ModInt& operator*=(ModInt rhs) {
    x = (unsigned long long)x * rhs.x % mod;
    return *this;
  }
  ModInt& operator/=(ModInt rhs) {
    x = (unsigned long long)x * rhs.inv().x % mod;
    return *this;
  }
  ModInt operator-() const { return -x < 0 ? mod - x : -x; }
  ModInt operator+(ModInt rhs) const { return ModInt(*this) += rhs; }
  ModInt operator-(ModInt rhs) const { return ModInt(*this) -= rhs; }
  ModInt operator*(ModInt rhs) const { return ModInt(*this) *= rhs; }
  ModInt operator/(ModInt rhs) const { return ModInt(*this) /= rhs; }
  bool operator==(ModInt rhs) const { return x == rhs.x; }
  bool operator!=(ModInt rhs) const { return x != rhs.x; }
  ModInt inv() const { return pow(*this, mod - 2); }
  friend ostream& operator<<(ostream& s, ModInt<mod> a) {
    s << a.x;
    return s;
  }
  friend istream& operator>>(istream& s, ModInt<mod>& a) {
    s >> a.x;
    return s;
  }
};
using mint = ModInt<1000000007>;
using Graph = vector<vector<int>>;
Graph G;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (long long int i = 0; i < n; i++) cin >> a[i];
  int MAX = *max_element(a.begin(), a.end());
  for (int i = 0; i <= MAX; i++) {
    bool flag = true;
    for (long long int j = 0; j < n; j++) {
      if (a[j] == MAX or a[j] + i == MAX or a[j] + 2 * i == MAX)
        continue;
      else
        flag = false;
    }
    if (flag) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}
