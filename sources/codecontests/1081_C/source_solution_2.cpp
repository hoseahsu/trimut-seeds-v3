#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}
const long long maxn = (long long)2e3 + 100;
const long long maxm = (long long)52;
const int LOGN = 22;
const long long INF = 1e9 + 10;
const long long MOD = 998244353;
const double PI = acos(-1.0);
const double EPS = 1e-12;
long long inv[maxn], f[maxn], invf[maxn];
void Init() {
  inv[0] = inv[1] = f[0] = f[1] = invf[0] = invf[1] = 1;
  for (int i = 2; i < maxn; i++) {
    inv[i] = MOD - MOD / i * inv[MOD % i] % MOD;
    f[i] = f[i - 1] * i % MOD;
    invf[i] = invf[i - 1] * inv[i] % MOD;
  }
}
inline long long C(long long n, long long k) {
  return f[n] * invf[k] % MOD * invf[n - k] % MOD;
}
long long Pow(long long a, long long b) {
  long long ret = 1LL;
  while (b) {
    if (b & 1) ret = ret * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  Init();
  long long n, m, k;
  while (cin >> n >> m >> k) {
    long long ans = C(n - 1, k) * m % MOD;
    ans *= Pow(m - 1, k);
    ans %= MOD;
    if (ans < 0) ans += MOD;
    cout << ans << endl;
  }
  return 0;
}
