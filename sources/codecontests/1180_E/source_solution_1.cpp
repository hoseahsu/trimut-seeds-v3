#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 30;
const int maxn = 3e5 + 5, N = 1e6, limit = 1e9;
struct segm {
  int mn, lazy;
} se[N << 2];
int n, m;
int a[maxn], b[maxn], cnt[1000005];
void build(int l, int r, int num) {
  if (l == r) {
    se[num].mn = limit;
    se[num].lazy = 0;
    return;
  }
  int mid = l + r >> 1;
  build(l, mid, num << 1);
  build(mid + 1, r, num << 1 | 1);
  se[num].mn = limit;
  se[num].lazy = 0;
}
void pushdown(int num) {
  if (!se[num].lazy) return;
  se[num << 1].lazy += se[num].lazy;
  se[num << 1 | 1].lazy += se[num].lazy;
  se[num << 1].mn += se[num].lazy;
  se[num << 1 | 1].mn += se[num].lazy;
  se[num].lazy = 0;
}
void upd(int l, int r, int num, int fm, int to, int delt) {
  if (fm <= l && r <= to) {
    se[num].lazy += delt;
    se[num].mn += delt;
    return;
  }
  pushdown(num);
  int mid = l + r >> 1;
  if (fm <= mid) upd(l, mid, num << 1, fm, to, delt);
  if (to > mid) upd(mid + 1, r, num << 1 | 1, fm, to, delt);
  se[num].mn = min(se[num << 1].mn, se[num << 1 | 1].mn);
}
int query(int l, int r, int num) {
  if (se[num].mn >= 0) return -1;
  if (l == r) return l;
  int mid = l + r >> 1;
  pushdown(num);
  if (se[num << 1 | 1].mn < 0) return query(mid + 1, r, num << 1 | 1);
  return query(l, mid, num << 1);
}
int main() {
  scanf("%d%d", &n, &m);
  build(1, N, 1);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    ++cnt[a[i]];
    if (cnt[a[i]] == 1) upd(1, N, 1, a[i], a[i], -limit);
    upd(1, N, 1, 1, a[i], -1);
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d", &b[i]);
    upd(1, N, 1, 1, b[i], 1);
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int op, li, x;
    scanf("%d%d%d", &op, &li, &x);
    if (op == 1) {
      upd(1, N, 1, 1, a[li], 1);
      --cnt[a[li]];
      if (cnt[a[li]] == 0) upd(1, N, 1, a[li], a[li], limit);
      a[li] = x;
      ++cnt[a[li]];
      if (cnt[a[li]] == 1) upd(1, N, 1, a[li], a[li], -limit);
      upd(1, N, 1, 1, a[li], -1);
    } else {
      upd(1, N, 1, 1, b[li], -1);
      b[li] = x;
      upd(1, N, 1, 1, b[li], 1);
    }
    printf("%d\n", query(1, N, 1));
  }
  return 0;
}
