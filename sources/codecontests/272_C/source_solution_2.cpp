#include <bits/stdc++.h>
using namespace std;
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
const int INF = 1 << 29;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n >> b) & 1; }
inline void set_bit(int& n, int b) { n |= two(b); }
inline void unset_bit(int& n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) {
  int res = 0;
  while (n && ++res) n -= n & (-n);
  return res;
}
template <class T>
void chmax(T& a, const T& b) {
  a = max(a, b);
}
template <class T>
void chmin(T& a, const T& b) {
  a = min(a, b);
}
const int MOD = 1000000007;
bool isPowerOfTwo(long long int x) { return x && (!(x & (x - 1))); }
bool isPrime(int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
int highestPowerof2(unsigned int n) {
  if (n < 1) return 0;
  int res = 1;
  for (int i = 0; i < 8 * sizeof(unsigned int); i++) {
    int curr = 1 << i;
    if (curr > n) break;
    res = curr;
  }
  return res;
}
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) {
    long long int nos;
    cin >> nos;
    long long int hos[nos];
    for (int i = 0; i < (nos); i++) cin >> hos[i];
    long long int nop;
    cin >> nop;
    pair<long long int, long long int> m[nop];
    for (int i = 0; i < (nop); i++) {
      int k, j;
      cin >> k >> j;
      m[i] = {k, j};
    }
    long long int cw = 0, ch = 0;
    for (int i = 0; i < (nop); i++) {
      if (cw < m[i].first) {
        ch = max(ch, hos[m[i].first - 1]);
        cout << ch << endl;
        ch += m[i].second;
        cw = m[i].first;
      } else {
        cout << ch << endl;
        ch += m[i].second;
      }
    }
  }
  return 0;
}
