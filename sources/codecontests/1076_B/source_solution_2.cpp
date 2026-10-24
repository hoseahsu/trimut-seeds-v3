#include <bits/stdc++.h>
using namespace std;
long long int min(long long int a, long long int b) {
  if (a >= b)
    return b;
  else
    return a;
}
long long int max(long long int a, long long int b) {
  if (a >= b)
    return a;
  else
    return b;
}
long long int ndig(long long int n) {
  long long int l = 0;
  while (n > 0) {
    n /= 10;
    l++;
  }
  return l;
}
long long int ndig3(long long int n) {
  long long int l = 0;
  while (n % 3 == 0) {
    n /= 3;
    l++;
  }
  return l;
}
bool isprime(long long int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
long long int gcd(long long int x, long long int y) {
  long long int a, b, t, gcd, lcm;
  a = x;
  b = y;
  while (b != 0) {
    t = b;
    b = a % b;
    a = t;
  }
  gcd = a;
  return gcd;
}
long long int lcm(long long int x, long long int y) {
  long long int a, b, t, gcd, lcm;
  a = x;
  b = y;
  while (b != 0) {
    t = b;
    b = a % b;
    a = t;
  }
  gcd = a;
  lcm = (x * y) / gcd;
  return lcm;
}
long long int algo(long long int n) {
  if (n % 2 == 0)
    return n / 2;
  else {
    long long int z;
    long long int f = 0;
    if (isprime(n))
      return 1;
    else {
      for (long long int i = 2; i < sqrt(n); i++) {
        if (isprime(i) && n % i == 0) {
          f = 1;
          z = i;
        }
        if (f == 1) break;
      }
      return (n - z) / 2 + 1;
    }
  }
}
void solve() {
  long long int n;
  cin >> n;
  long long int ans;
  ans = algo(n);
  cout << ans;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
