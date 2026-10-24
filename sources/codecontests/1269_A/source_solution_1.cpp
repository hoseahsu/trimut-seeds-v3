#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
const int mod = 1e9 + 7;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long fpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
bool check(int n) {
  for (int i = 2; i * i <= n; ++i)
    if (n % i == 0) return 1;
  return 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  while (cin >> n) {
    if (check(8 + n))
      cout << 8 + n << ' ' << 8 << endl;
    else
      cout << 9 + n << ' ' << 9 << endl;
  }
  return 0;
}
