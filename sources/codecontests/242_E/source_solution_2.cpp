#include <bits/stdc++.h>
using namespace std;
long long CONST[25];
int n, m, a[100005], sum[100005 << 2][23];
bool rev[100005 << 2][23];
void push_up(int p, int x) {
  sum[p][x] = sum[(p << 1)][x] + sum[(p << 1 | 1)][x];
}
void build(int p, int l, int r) {
  if (l == r) {
    for (int i = 0; i < 20; i++) {
      if (CONST[i] & a[l]) sum[p][i] = 1;
    }
    return;
  }
  int mid = (l + r) >> 1;
  build((p << 1), l, mid);
  build((p << 1 | 1), mid + 1, r);
  for (int i = 0; i <= 20; i++) push_up(p, i);
}
void opt(int p, int x, int l, int r) {
  sum[p][x] = (r - l + 1) - sum[p][x];
  rev[p][x] = !rev[p][x];
  return;
}
void push_down(int p, int x, int l, int r) {
  if (!rev[p][x]) return;
  int mid = (l + r) >> 1;
  opt((p << 1), x, l, mid);
  opt((p << 1 | 1), x, mid + 1, r);
  rev[p][x] = false;
}
void update(int nl, int nr, int l, int r, int p, int x) {
  if (nl <= l && r <= nr) {
    opt(p, x, l, r);
    return;
  }
  push_down(p, x, l, r);
  int mid = (l + r) >> 1;
  if (nl <= mid) update(nl, nr, l, mid, (p << 1), x);
  if (nr > mid) update(nl, nr, mid + 1, r, (p << 1 | 1), x);
  push_up(p, x);
}
int query(int nl, int nr, int l, int r, int p, int x) {
  if (nl <= l && r <= nr) return sum[p][x];
  int ret = 0;
  push_down(p, x, l, r);
  int mid = (l + r) >> 1;
  if (nl <= mid) ret += query(nl, nr, l, mid, (p << 1), x);
  if (nr > mid) ret += query(nl, nr, mid + 1, r, (p << 1 | 1), x);
  return ret;
}
int main() {
  for (int i = 0; i < 20; i++) CONST[i] = 1LL << i;
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  build(1, 1, n);
  cin >> m;
  int op, x, l, r;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &op, &l, &r);
    if (op == 1) {
      long long ans = 0;
      for (int i = 0; i < 20; i++) {
        ans += CONST[i] * query(l, r, 1, n, 1, i);
      }
      printf("%lld\n", ans);
    } else {
      scanf("%d", &x);
      for (int i = 0; i < 20; i++) {
        if (CONST[i] & x) update(l, r, 1, n, 1, i);
      }
    }
  }
  return 0;
}
