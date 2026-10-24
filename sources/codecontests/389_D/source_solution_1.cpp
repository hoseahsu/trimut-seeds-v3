#include <bits/stdc++.h>
using namespace std;
inline long long gcd(long long x, long long y) { return x ? gcd(y % x, x) : y; }
const long long mod = 1e9 + 7;
inline signed rd() {
  signed ans = 0;
  char last = ' ', ch = getchar();
  while (!(ch >= '0' && ch <= '9')) last = ch, ch = getchar();
  while (ch >= '0' && ch <= '9') ans = ans * 10 + ch - '0', ch = getchar();
  if (last == '-') ans = -ans;
  return ans;
}
inline long long QPow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
long long exgcd(long long a, long long b, long long &x, long long &y) {
  long long d = a;
  if (b == 0)
    x = 1, y = 0;
  else {
    d = exgcd(b, a % b, y, x), y -= a / b * x;
  }
  return d;
}
const long double PI = 3.141592653589793115997963468544185161590576171875;
signed bits[50];
bool g[1010][1010];
long long pos[50];
signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long t;
  long long n, m, A, cf, cm, pl, pr, vl, vr, k, x, y, px, py;
  cin >> k;
  signed top = 0;
  m = k;
  while (m) bits[top++] = m & 1, m >>= 1;
  signed cur = 3;
  pos[0] = 3;
  g[1][cur++] = 1;
  for (long long i = 0; i < top - 1; i++) {
    g[cur - 1][cur] = g[cur - 1][cur + 1] = 1;
    g[cur][cur + 2] = g[cur + 1][cur + 2] = 1;
    cur += 3;
    pos[i + 1] = cur - 1;
  }
  g[cur - 1][2] = 1;
  for (long long i = top - 2; i >= 0; i--) {
    if (bits[i] == 0) continue;
    long long last = pos[i];
    for (long long j = i; j < top - 1; j++) {
      g[last][cur++] = 1;
      g[cur - 1][cur++] = 1;
      last = cur - 1;
    }
    g[cur - 1][2] = 1;
  }
  cout << --cur << endl;
  for (long long i = 1; i <= cur; i++) {
    for (long long j = 1; j <= cur; j++) {
      if (i == j)
        cout << 'N';
      else
        cout << (g[i][j] || g[j][i] ? 'Y' : 'N');
    }
    cout << '\n';
  }
  return 0;
}
