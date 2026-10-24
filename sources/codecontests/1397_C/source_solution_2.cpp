#include <bits/stdc++.h>
using namespace std;
const long long maxs = 1e5 + 3;
const long long maxs1 = 1e3 + 4;
const long long mod = 1e9 + 7;
inline long long add(long long a, long long b) { return (mod + a + b) % mod; }
inline long long sub(long long a, long long b) { return (a - b + mod) % mod; }
inline long long mul(long long a, long long b) { return (1ll * a * b) % mod; }
long long fastpow(long long x, long long y) {
  long long res = 1;
  x = x % mod;
  while (y > 0) {
    if (y & 1) res = (res * x) % mod;
    y = y >> 1;
    x = (x * x) % mod;
  }
  return res;
}
long long inv(long long x) { return fastpow(x, mod - 2); }
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  long long arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  if (n == 1) {
    cout << 1 << " " << 1 << endl;
    cout << -arr[0] << endl;
    cout << 1 << " " << 1 << endl;
    cout << 0 << endl;
    cout << 1 << " " << 1 << endl;
    cout << 0 << endl;
    return 0;
  }
  cout << 1 << " " << 1 << endl;
  cout << (n - 1) * arr[0] << endl;
  cout << 2 << " " << n << endl;
  for (int i = 1; i < n; i++) {
    cout << (n - 1) * arr[i] << " ";
  }
  cout << endl;
  cout << 1 << " " << n << endl;
  for (int i = 0; i < n; i++) {
    cout << -(n)*arr[i] << " ";
  }
}
