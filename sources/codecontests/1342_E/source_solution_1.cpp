#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int N = 1e6 + 10;
int n, k, f[N];
int add(int x, int y) {
  if (x + y >= mod) {
    return x + y - mod;
  }
  return x + y;
}
int sub(int x, int y) {
  if (x - y < 0) {
    return x - y + mod;
  }
  return x - y;
}
int mul(int x, int y) { return (long long)x * y % mod; }
int exp(int x, int y) {
  int ans = 1;
  while (y) {
    if (y & 1) {
      ans = mul(ans, x);
    }
    x = mul(x, x);
    y >>= 1;
  }
  return ans;
}
int inv(int x) { return exp(x, mod - 2); }
void fact() {
  f[0] = 1;
  for (int i = 1; i < N; i++) {
    f[i] = mul(f[i - 1], i);
  }
}
int choose(int x, int y) { return mul(f[x], inv(mul(f[x - y], f[y]))); }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  fact();
  cin >> n >> k;
  if (k >= n) {
    cout << 0 << '\n';
    return 0;
  }
  int c = n - k;
  int ncc = choose(n, c);
  int ways = 0;
  for (int i = 0; i <= c; i++) {
    if (i % 2) {
      ways = sub(ways, mul(choose(c, i), exp(c - i, n)));
    } else {
      ways = add(ways, mul(choose(c, i), exp(c - i, n)));
    }
  }
  int ans = mul(ways, ncc);
  if (k != 0) {
    ans = mul(ans, 2);
  }
  cout << ans << '\n';
  return 0;
}
