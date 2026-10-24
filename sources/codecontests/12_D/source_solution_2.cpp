#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return f * x;
}
int n, m;
struct node {
  int a, b, c;
  bool operator<(const node &x) const { return b > x.b; }
} dat[N];
int mx[N * 4];
void modify(int l, int r, int x, int v, int p) {
  if (l == r) {
    mx[p] = max(mx[p], v);
    return;
  }
  if (x <= ((l + r) >> 1))
    modify(l, ((l + r) >> 1), x, v, (p << 1));
  else
    modify(((l + r) >> 1) + 1, r, x, v, (p << 1 | 1));
  mx[p] = max(mx[(p << 1)], mx[(p << 1 | 1)]);
}
int query(int l, int r, int L, int R, int p) {
  if (L > R) return 0;
  if (L <= l && r <= R) return mx[p];
  int res = 0;
  if (L <= ((l + r) >> 1))
    res = max(res, query(l, ((l + r) >> 1), L, R, (p << 1)));
  if (R > ((l + r) >> 1))
    res = max(res, query(((l + r) >> 1) + 1, r, L, R, (p << 1 | 1)));
  return res;
}
int s[N], len;
int main() {
  n = read();
  for (int i = 1; i <= n; i++) s[i] = dat[i].a = read();
  for (int i = 1; i <= n; i++) dat[i].b = read();
  for (int i = 1; i <= n; i++) dat[i].c = read();
  sort(s + 1, s + 1 + n);
  len = unique(s + 1, s + 1 + n) - s - 1;
  for (int i = 1; i <= n; i++)
    dat[i].a = lower_bound(s + 1, s + 1 + len, dat[i].a) - s;
  sort(dat + 1, dat + 1 + n);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int j;
    for (j = i; j <= n && dat[j].b == dat[i].b; j++) {
      int x = query(1, n, dat[j].a + 1, len + 1, 1);
      if (x > dat[j].c) ans++;
    }
    for (j = i; j <= n && dat[j].b == dat[i].b; j++)
      modify(1, n, dat[j].a, dat[j].c, 1);
    i = j - 1;
  }
  printf("%d\n", ans);
  return 0;
}
