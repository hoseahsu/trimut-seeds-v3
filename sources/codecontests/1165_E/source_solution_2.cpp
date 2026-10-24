#include <bits/stdc++.h>
using namespace std;
int n;
const int maxN = 2e5 + 10;
long long a[maxN], b[maxN];
const int mod = 998244353;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] = 1LL * a[i] * i * (n + 1 - i);
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  sort(a + 1, a + n + 1);
  sort(b + 1, b + n + 1);
  reverse(b + 1, b + n + 1);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += ((a[i] % mod) * (b[i] % mod)) % mod;
    ans %= mod;
  }
  cout << ans;
  return 0;
}
