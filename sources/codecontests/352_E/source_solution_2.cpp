#include <bits/stdc++.h>
using namespace std;
const long long maxn = 45, inf = 10000 * 2 * 100000;
struct matric {
  long long a[maxn][maxn];
  matric() {
    for (int i = 0; i < maxn; i++) fill(a[i], a[i] + maxn, inf);
  }
  matric operator*(const matric &b) {
    matric c;
    for (int i = 0; i < maxn; i++)
      for (int j = 0; j < maxn; j++)
        for (int k = 0; k < maxn; k++)
          c.a[i][j] = min(c.a[i][j], a[i][k] + b.a[k][j]);
    return c;
  }
};
long long n, a[maxn], b[maxn], m, c[maxn][maxn], minn, sum, cnt;
matric adj, ans;
matric pow(int m) {
  if (m == 1) return adj;
  matric d = pow(m / 2);
  d = d * d;
  if (m % 2) d = d * adj;
  return d;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 0; i < maxn; i++) fill(c[i], c[i] + maxn, inf);
  for (int i = 0; i < (1 << n); i++) {
    minn = maxn;
    sum = 0;
    cnt = 0;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        sum--;
        cnt += b[j];
      } else {
        sum++;
        cnt += a[j];
      }
      minn = min(minn, sum);
    }
    sum += n;
    minn += n;
    c[sum][minn] = min(c[sum][minn], cnt);
  }
  for (int i = 0; i <= 2 * n; i++) {
    for (int j = 0; j <= 2 * n; j++) {
      for (int k = 0; k <= 2 * n; k++) {
        int x = j - i;
        if (i + k - 2 * n < 0 || x < -n || x > n) continue;
        adj.a[i][j] = min(adj.a[i][j], c[x + n][k]);
      }
    }
  }
  ans = pow(m);
  cout << ans.a[n][n] << endl;
  return 0;
}
