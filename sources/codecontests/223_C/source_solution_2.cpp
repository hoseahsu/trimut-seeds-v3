#include <bits/stdc++.h>
using namespace std;
using namespace std;
long long mod = 1e9 + 7;
long long quick_mod(long long a, long long b) {
  long long ans = 1;
  a %= mod;
  while (b) {
    if (b % 2 != 0) {
      ans = ans * a % mod;
      b--;
    }
    b /= 2;
    a = a * a % mod;
  }
  return ans;
}
long long judge(long long n, long long m) {
  if (m > n) return 0;
  long long ans = 1;
  for (long long i = 1; i <= m; i++) {
    long long a = (n + i - m) % mod;
    long long b = i % mod;
    ans = ans * (a * quick_mod(b, mod - 2) % mod) % mod;
  }
  return ans;
}
long long work(long long n, long long m) {
  if (m == 0) return 1;
  return judge(n % mod, m % mod) * work(n / mod, m / mod) % mod;
}
const int MAXN = 2e3 + 5;
long long ans[MAXN], a[MAXN];
long long sum[MAXN];
long long C[MAXN << 1];
int main() {
  long long m, n, i, j, k;
  ios::sync_with_stdio(false);
  ;
  cin >> m >> k;
  for (i = 1; i <= m; i++) cin >> a[i];
  long long c1 = k - 1, c2 = 0;
  for (i = 0; i <= m; i++) {
    C[i] = work(c1, c2);
    c1++, c2++;
  }
  for (i = 1; i <= m; i++) {
    long long c = 0;
    for (j = i; j <= m; j++) {
      ans[j] = (ans[j] + C[c++] * a[i]) % mod;
    }
  }
  for (i = 1; i <= m; i++) cout << ans[i] << ' ';
  cout << endl;
}
