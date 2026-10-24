#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10;
const long long mod = 1e9 + 7;
struct Mat {
  long long a[maxn][maxn];
} b;
long long n, m;
Mat Mul(Mat a, Mat b, int m) {
  Mat res;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= m; j++) {
      res.a[i][j] = 0;
      for (int k = 1; k <= m; k++) {
        res.a[i][j] += (a.a[i][k] * b.a[k][j]);
        res.a[i][j] %= mod;
      }
    }
  }
  return res;
}
Mat qpow(Mat a, long long b, int m) {
  Mat res;
  for (int i = 1; i <= m; i++) {
    res.a[i][i] = 1;
  }
  while (b > 0) {
    if (b & 1) {
      res = Mul(res, a, m);
    }
    b >>= 1;
    a = Mul(a, a, m);
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  if (m > n) {
    cout << 1 << "\n";
    return 0;
  }
  b.a[1][1] = b.a[1][m] = 1;
  for (int i = 2; i <= m; i++) {
    b.a[i][i - 1] = 1;
  }
  Mat res = qpow(b, n - m + 1, m);
  long long ans = 0;
  for (int i = 1; i <= m; i++) {
    ans = (ans + res.a[1][i]) % mod;
  }
  cout << ans << "\n";
  return 0;
}
