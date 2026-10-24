#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool get_int(T &x) {
  char t = getchar();
  bool neg = false;
  x = 0;
  for (; (t > '9' || t < '0') && t != '-' && t != EOF; t = getchar())
    ;
  if (t == '-') neg = true, t = getchar();
  if (t == EOF) return false;
  for (; t <= '9' && t >= '0'; t = getchar()) x = x * 10 + t - '0';
  if (neg) x = -x;
  return true;
}
template <typename T>
void print_int(T x) {
  if (x < 0) putchar('-'), x = -x;
  short a[20] = {}, sz = 0;
  while (x > 0) a[sz++] = x % 10, x /= 10;
  if (sz == 0) putchar('0');
  for (int i = sz - 1; i >= 0; i--) putchar('0' + a[i]);
}
const int inf = 0x3f3f3f3f;
const long long Linf = 1ll << 61;
const double pi = acos(-1.0);
const int mod = 998244353;
int power(int x, int y) {
  int ret = 1;
  do {
    if (y & 1) ret = 1ll * ret * x % mod;
    x = 1ll * x * x % mod;
  } while (y >>= 1);
  return ret;
}
int m, d, v[30111][25];
bool cmp(int x, int y) {
  for (int i = 0; i < 25; i++)
    if (v[x][i] != v[y][i]) return v[x][i] < v[y][i];
  return false;
}
int n, a[5][5], ord[30111], ans[30111];
void construct() {
  memset(a, 0, sizeof(a));
  get_int(n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < d; j++) {
      get_int(a[i][j]);
      if (a[i][j] < 0) a[i][j] += mod;
    }
  for (int i = 0, cur = 0; cur < d; cur++) {
    int piv = -1;
    for (int j = i; j < n && piv == -1; j++)
      if (a[j][cur]) piv = j;
    if (piv == -1)
      continue;
    else {
      for (int j = 0; j < d; j++) swap(a[i][j], a[piv][j]);
      int rv = power(a[i][cur], mod - 2);
      for (int j = cur; j < d; j++) a[i][j] = 1ll * a[i][j] * rv % mod;
      for (int j = 0; j < n; j++) {
        if (i == j) continue;
        rv = a[j][cur];
        for (int k = 0; k < d; k++)
          a[j][k] = (a[j][k] - 1ll * a[i][k] * rv % mod + mod) % mod;
      }
      i++;
    }
  }
}
int tmp[30111];
int main() {
  (get_int(m) && get_int(d));
  for (int i = 1; i <= m; i++) {
    construct();
    for (int j = 0; j < d; j++)
      for (int k = 0; k < d; k++) v[i][j * d + k] = a[j][k];
    ord[i] = i;
  }
  sort(ord + 1, ord + m + 1, cmp);
  ans[ord[1]] = 1;
  for (int i = 2; i <= m; i++) {
    bool ok = 1;
    for (int j = 0; j < 25; j++) ok &= (v[ord[i]][j] == v[ord[i - 1]][j]);
    ans[ord[i]] = ans[ord[i - 1]] + (ok ^ 1);
  }
  int cur = 0;
  for (int i = 1; i <= m; i++) {
    if (!tmp[ans[i]]) tmp[ans[i]] = ++cur;
    printf("%d ", tmp[ans[i]]);
  }
  return 0;
}
