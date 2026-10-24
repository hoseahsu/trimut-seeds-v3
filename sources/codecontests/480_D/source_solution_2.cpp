#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool getmin(T *a, const T &b) {
  if (b < *a) {
    *a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool getmax(T *a, const T &b) {
  if (b > *a) {
    *a = b;
    return true;
  }
  return false;
}
template <class T>
inline void read(T *a) {
  char c;
  while (isspace(c = getchar())) {
  }
  bool flag = 0;
  if (c == '-')
    flag = 1, *a = 0;
  else
    *a = c - 48;
  while (isdigit(c = getchar())) *a = *a * 10 + c - 48;
  if (flag) *a = -*a;
}
const int mo = 1000000007;
template <class T>
T pow(T a, T b, int c = mo) {
  T res = 1;
  for (T i = 1; i <= b; i <<= 1, a = 1LL * a * a % c)
    if (b & i) res = 1LL * res * a % c;
  return res;
}
using namespace std;
struct Item {
  int l, r, w, s, v;
};
int get() {
  char c;
  while (c = getchar(), (c < '0' || c > '9') && (c != '-'))
    ;
  bool flag = (c == '-');
  if (flag) c = getchar();
  int x = 0;
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - 48;
    c = getchar();
  }
  return flag ? -x : x;
}
void output(int x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  int len = 0, data[10];
  while (x) {
    data[len++] = x % 10;
    x /= 10;
  }
  if (!len) data[len++] = 0;
  while (len--) putchar(data[len] + 48);
  putchar('\n');
}
const int maxn = 501;
const int maxm = 1000;
int n;
Item a[maxn];
bool flag[maxn];
vector<int> g[maxn * 2 + 1];
int dp[maxn][maxm + 1], f[maxn * 2 + 1][maxm + 1];
void solve(int x) {
  if (flag[x]) return;
  flag[x] = true;
  vector<int> b;
  b.clear();
  for (int i = 0; i < n; i++)
    if (i != x && a[x].l <= a[i].l && a[i].r <= a[x].r) {
      solve(i);
      b.push_back(i);
    }
  int m = b.size();
  for (int i = 0; i <= n * 2; i++) g[i].clear();
  for (int i = 0; i < m; i++) {
    int y = b[i];
    g[a[y].l].push_back(y);
  }
  for (int i = n * 2; i >= 0; i--)
    for (int j = 0; j <= a[x].s; j++) {
      f[i][j] = (i == n * 2) ? 0 : f[i + 1][j];
      for (int k = 0; k < g[i].size(); k++) {
        int y = g[i][k];
        if (j >= a[y].w)
          f[i][j] = max(f[i][j], f[a[y].r][j] + dp[y][min(j - a[y].w, a[y].s)]);
      }
    }
  for (int i = 0; i <= a[x].s; i++) dp[x][i] = f[0][i] + a[x].v;
}
int main() {
  n = get();
  a[n] = (Item){0, n * 2, 0, get(), 0};
  for (int i = 0; i < n; i++) {
    a[i].l = get();
    a[i].r = get();
    a[i].w = get();
    a[i].s = get();
    a[i].v = get();
  }
  memset(flag, 0, sizeof(flag));
  memset(dp, 0, sizeof(dp));
  solve(n);
  output(dp[n][a[n].s]);
  return 0;
}
