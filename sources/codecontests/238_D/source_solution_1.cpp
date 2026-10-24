#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, ch = getchar(), f = 1;
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return x * f;
}
const int N = 100005, M = 20;
int n, q, pt[2][N], cnt[N * 10][10], seq[N * 10];
int mx[N * 10][M + 5], mn[N * 10][M + 5], vis[N];
char str[N];
inline int is_arrow(int c) { return c == '<' || c == '>'; }
inline int intv_mn(int l, int r) {
  int lg = log2(r - l + 1);
  return min(mn[l][lg], mn[r - (1 << lg) + 1][lg]);
}
inline int intv_mx(int l, int r) {
  int lg = log2(r - l + 1);
  return max(mx[l][lg], mx[r - (1 << lg) + 1][lg]);
}
int main() {
  n = read(), q = read();
  scanf("%s", str + 1);
  for (int i = 1; i <= n; ++i) {
    pt[0][i] = i - 1;
    pt[1][i] = i + 1;
  }
  pt[1][0] = 1;
  pt[0][n + 1] = n;
  int idx = 1, cur = 0;
  while (cur < n) {
    for (int p = cur + 1, d = 1; p >= 1 && p <= n; p = pt[d][p], ++idx) {
      seq[idx] = p;
      mx[idx][0] = mn[idx][0] = p;
      if (!vis[p]) vis[p] = idx;
      cur = max(cur, p);
      for (int j = 0; j <= 9; ++j) cnt[idx][j] = cnt[idx - 1][j];
      if (is_arrow(str[p])) {
        d = str[p] == '>';
        if (pt[d][p] && is_arrow(str[pt[d][p]])) {
          pt[d ^ 1][pt[d][p]] = pt[d ^ 1][p];
          pt[d][pt[d ^ 1][p]] = pt[d][p];
        }
      } else if (isdigit(str[p])) {
        ++cnt[idx][str[p] - '0'];
        if (str[p] == '0') {
          pt[d ^ 1][pt[d][p]] = pt[d ^ 1][p];
          pt[d][pt[d ^ 1][p]] = pt[d][p];
        } else
          --str[p];
      }
    }
    seq[++idx] = n + 1;
  }
  for (int j = 1; (1 << j) <= idx; ++j)
    for (int i = 1; i + (1 << j) - 1 <= idx; ++i) {
      mn[i][j] = min(mn[i][j - 1], mn[i + (1 << j - 1)][j - 1]);
      mx[i][j] = max(mx[i][j - 1], mx[i + (1 << j - 1)][j - 1]);
    }
  for (int i = 1; i <= q; ++i) {
    int st = read(), ed = read();
    if (!vis[st]) {
      for (int j = 0; j <= 9; ++j) printf("0 ");
      putchar('\n');
      continue;
    }
    int l = vis[st], r = idx, pos = -1;
    while (l <= r) {
      int mid = l + r >> 1;
      int tl = intv_mn(vis[st], mid), tr = intv_mx(vis[st], mid);
      if (st <= tl && tr <= ed)
        pos = mid, l = mid + 1;
      else
        r = mid - 1;
    }
    for (int j = 0; j <= 9; ++j)
      printf("%d ", cnt[pos][j] - cnt[vis[st] - 1][j]);
    putchar('\n');
  }
  return 0;
}
