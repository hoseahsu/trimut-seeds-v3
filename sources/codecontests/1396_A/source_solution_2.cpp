#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
inline long long read() {
  long long s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return s * w;
}
inline long long qp(long long a, long long b, long long p) {
  long long ans = 1;
  while (b) {
    if (b & 1) {
      ans = (ans * a) % p;
      --b;
    }
    a = (a * a) % p;
    b >>= 1;
  }
  return ans % p;
}
const int manx = 1e6 + 5;
const int N = 2e3 + 5;
const int mod = 1e9 + 7;
const int mo = 998244353;
long long a[manx];
long long n, ans, last = 1e18, base;
int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  if (n == 1) {
    cout << "1 1" << endl;
    cout << -a[1] << endl;
    cout << "1 1" << endl;
    cout << a[1] << endl;
    cout << "1 1" << endl;
    cout << -a[1] << endl;
  } else {
    cout << "1 " << n - 1 << endl;
    for (int i = 1; i < n; i++) cout << a[i] * (n - 1) << " ";
    cout << endl;
    cout << "1 " << n << endl;
    for (int i = 1; i <= n; i++) cout << -a[i] * n << " ";
    cout << endl;
    cout << n << " " << n << endl;
    cout << a[n] * (n - 1) << endl;
  }
  return 0;
}
