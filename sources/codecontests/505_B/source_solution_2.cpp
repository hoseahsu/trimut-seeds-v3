#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int mxn = 233;
const int mod = 1e9 + 7;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (!isdigit(c)) f = c == '-' ? -1 : 1, c = getchar();
  while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
  return x * f;
}
inline long long gcd(long long a, long long b) {
  return b == 0 ? a : gcd(b, a % b);
}
long long ksm(long long a, long long b, long long mod) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return ans;
}
long long inv2(long long a, long long mod) { return ksm(a, mod - 2, mod); }
void exgcd(long long a, long long b, long long &x, long long &y, long long &d) {
  if (!b) {
    d = a;
    x = 1;
    y = 0;
  } else {
    exgcd(b, a % b, y, x, d);
    y -= x * (a / b);
  }
}
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int n, m, d[mxn][mxn][mxn];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  ;
  cin >> n >> m;
  int u, v, c;
  for (int i = 1; i <= m; ++i) {
    cin >> u >> v >> c;
    d[c][v][u] = d[c][u][v] = 1;
  }
  for (int c = 1; c <= m; ++c)
    for (int k = 1; k <= n; ++k)
      for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
          d[c][i][j] = d[c][j][i] = max(d[c][i][j], d[c][i][k] & d[c][k][j]);
  int q;
  cin >> q;
  while (q--) {
    cin >> u >> v;
    int res = 0;
    for (int i = 1; i <= m; ++i)
      if (d[i][u][v]) res++;
    cout << res << endl;
  }
  return 0;
}
