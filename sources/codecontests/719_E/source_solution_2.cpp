#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 50, S = N << 2, P = 1e9 + 7;
struct Mat {
  long long a[2][2];
};
const Mat F = (Mat){{{1, 1}, {1, 0}}}, I = (Mat){{{1, 0}, {0, 1}}},
          Z = (Mat){{{0, 0}, {0, 0}}};
Mat mul(Mat &a, Mat &b) {
  Mat c;
  memset(c.a, 0, sizeof(c.a));
  for (int i = 0; i < (2); ++i)
    for (int j = 0; j < (2); ++j)
      for (int k = 0; k < (2); ++k) (c.a[i][j] += a.a[i][k] * b.a[k][j]) %= P;
  return c;
}
Mat pow(Mat a, long long k) {
  Mat c = I;
  for (; k; k >>= 1, a = mul(a, a))
    if (k & 1) c = mul(c, a);
  return c;
}
Mat fib(long long x) {
  Mat a = (Mat){{{1, 1}, {1, 0}}};
  return pow(a, x);
}
Mat add(const Mat &a, const Mat &b) {
  Mat c = Z;
  for (int i = 0; i < (2); ++i)
    for (int j = 0; j < (2); ++j) c.a[i][j] = (a.a[i][j] + b.a[i][j]) % P;
  return c;
}
int n, m, a[N], qs, qt;
bool act[S];
;
Mat tr[S], tg[S], res, dlt;
inline void up(int v) { tr[v] = add(tr[v << 1], tr[v << 1 ^ 1]); }
inline void down(int v, int l, int r) {
  if (!act[v])
    return;
  else
    tr[v] = mul(tr[v], tg[v]);
  if (l != r) {
    act[v << 1] = true, tg[v << 1] = mul(tg[v << 1], tg[v]);
    act[v << 1 ^ 1] = true, tg[v << 1 ^ 1] = mul(tg[v << 1 ^ 1], tg[v]);
  }
  act[v] = false, tg[v] = I;
}
void bld(int v, int l, int r) {
  act[v] = false, tg[v] = I;
  if (l == r)
    tr[v] = fib(a[l] - 1);
  else
    bld(v << 1, l, ((l + r) >> 1)), bld(v << 1 ^ 1, ((l + r) >> 1) + 1, r),
        up(v);
}
void _upd(int v, int l, int r) {
  down(v, l, r);
  if (r < qs || l > qt)
    ;
  else if (qs <= l && r <= qt)
    act[v] = true, tg[v] = mul(tg[v], dlt), down(v, l, r);
  else
    _upd(v << 1, l, ((l + r) >> 1)), _upd(v << 1 ^ 1, ((l + r) >> 1) + 1, r),
        up(v);
}
void upd(int l, int r, int k) { dlt = fib(k), qs = l, qt = r, _upd(1, 1, n); }
void _que(int v, int l, int r) {
  down(v, l, r);
  if (r < qs || l > qt)
    ;
  else if (qs <= l && r <= qt)
    res = add(res, tr[v]);
  else
    _que(v << 1, l, ((l + r) >> 1)), _que(v << 1 ^ 1, ((l + r) >> 1) + 1, r),
        up(v);
}
long long que(int l, int r) {
  qs = l, qt = r, res = Z, _que(1, 1, n);
  return res.a[0][0];
}
int main(int argc, char *argv[]) {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= (n); ++i) scanf("%d", a + i);
  bld(1, 1, n);
  while (m--) {
    int op, l, r, x;
    scanf("%d%d%d", &op, &l, &r);
    if (op == 1)
      scanf("%d", &x), upd(l, r, x);
    else
      printf("%lld\n", que(l, r));
  }
  return 0;
}
