#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const int inf = 1000000009;
int rd() {
  char c = getchar();
  int t = 0, f = 1;
  while (!isdigit(c)) f = (c == '-') ? -1 : 1, c = getchar();
  while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
  return t * f;
}
void wt(long long x) {
  if (x > 9) wt(x / 10);
  putchar(x % 10 + 48);
  return;
}
struct Segt {
  long long l, r, sum, res;
} A[N << 2], L, R, Seg;
long long Ans;
int n, m, D[N], H[N];
Segt Merge(Segt pl, Segt pr, int L, int mid, int R) {
  Segt Ret = (Segt){0, 0, 0, 0};
  Ret.l = pl.l;
  Ret.r = pr.r;
  Ret.res = max(pl.res, pr.res);
  Ret.sum = pl.sum + D[mid] + pr.sum;
  Ret.l = max(Ret.l, pl.sum + D[mid] + pr.l);
  Ret.r = max(Ret.r, pl.r + D[mid] + pr.sum);
  Ret.res = max(Ret.res, pl.r + D[mid] + pr.l);
  return Ret;
}
void Build(int pos, int l, int r) {
  if (l == r) {
    A[pos].l = 2 * H[l];
    A[pos].r = 2 * H[r];
    return;
  }
  int mid = l + r >> 1;
  Build(pos << 1, l, mid);
  Build(pos << 1 | 1, mid + 1, r);
  A[pos] = Merge(A[pos << 1], A[pos << 1 | 1], l, mid, r);
  return;
}
Segt Query(int pos, int l, int r, int x, int y) {
  if (l == x && r == y) return A[pos];
  int mid = l + r >> 1;
  if (y <= mid)
    return Query(pos << 1, l, mid, x, y);
  else if (x > mid)
    return Query(pos << 1 | 1, mid + 1, r, x, y);
  else
    return Merge(Query(pos << 1, l, mid, x, mid),
                 Query(pos << 1 | 1, mid + 1, r, mid + 1, y), l, mid, r);
}
int main() {
  n = rd(), m = rd();
  for (int i = ((int)1); i <= ((int)n); i++) D[i] = rd();
  for (int i = ((int)1); i <= ((int)n); i++) H[i] = rd();
  Build(1, 1, n);
  while (m--) {
    int l = rd(), r = rd();
    if (l > r) {
      Seg = Query(1, 1, n, r + 1, l - 1);
      wt(Seg.res), putchar(10);
    } else {
      L = (Segt){0, 0, 0, 0};
      R = (Segt){0, 0, 0, 0};
      if (l > 1) L = Query(1, 1, n, 1, l - 1);
      if (r < n) R = Query(1, 1, n, r + 1, n);
      Ans = max(L.res, R.res);
      if (L.l != 0 && R.r != 0) Ans = max(Ans, L.l + R.r + D[n]);
      wt(Ans), putchar(10);
    }
  }
  return 0;
}
