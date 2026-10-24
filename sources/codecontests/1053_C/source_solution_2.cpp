#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
const int MOD = 1E9 + 7;
int Add(int a, int b, int m = MOD) {
  a += b;
  if (a >= m) a -= m;
  return a;
}
int Sub(int a, int b, int m = MOD) {
  a -= b;
  if (a < 0) a += m;
  return a;
}
int AddTo(int& to, int w, int m = MOD) {
  to += w;
  if (to >= m) to -= m;
  return to;
}
int SubTo(int& to, int w, int m = MOD) {
  to -= w;
  if (to < 0) to += m;
  return to;
}
int Mult(int a, int b, int m = MOD) { return (a * 1LL * b) % m; }
struct Bit {
  vector<int> sum;
  Bit() { sum.resize(MAXN, 0); }
  void BitAdd(int pos, int w) {
    for (++pos; pos < MAXN; pos += (pos & (-pos))) AddTo(sum[pos], w);
  }
  void BitSub(int pos, int w) {
    for (++pos; pos < MAXN; pos += (pos & (-pos))) SubTo(sum[pos], w);
  }
  int BitGet(int l, int r) {
    int res = 0;
    for (++r; r > 0; r -= (r & (-r))) AddTo(res, sum[r]);
    for (; l > 0; l -= (l & (-l))) SubTo(res, sum[l]);
    return res;
  }
};
struct BitReg {
  vector<long long> sum;
  BitReg() { sum.resize(MAXN, 0); }
  void BitAdd(int pos, int w) {
    for (++pos; pos < MAXN; pos += (pos & (-pos))) sum[pos] += w;
  }
  void BitSub(int pos, int w) {
    for (++pos; pos < MAXN; pos += (pos & (-pos))) sum[pos] -= w;
  }
  long long BitGet(int l, int r) {
    long long res = 0;
    for (++r; r > 0; r -= (r & (-r))) res += sum[r];
    for (; l > 0; l -= (l & (-l))) res -= sum[l];
    return res;
  }
};
int n, q;
int a_[MAXN], w_[MAXN];
int a[MAXN], w[MAXN];
Bit lr, rl;
BitReg sumw;
void Update(int i, int na, int nw) {
  sumw.BitSub(i, w[i]);
  lr.BitSub(i, Mult(Sub(i, a[i]), w[i]));
  rl.BitSub(i, Mult(Sub(a[i], i), w[i]));
  a[i] = na;
  w[i] = nw;
  sumw.BitAdd(i, w[i]);
  lr.BitAdd(i, Mult(Sub(i, a[i]), w[i]));
  rl.BitAdd(i, Mult(Sub(a[i], i), w[i]));
}
int Eval(int l, int r, int mid, int start) {
  int ans = 0;
  if (l <= mid) {
    int koef = Sub(start, l);
    AddTo(ans, lr.BitGet(l, mid));
    AddTo(ans, Mult(koef, sumw.BitGet(l, mid) % MOD));
  }
  if (mid + 1 <= r) {
    int pos = start + mid + 1 - l;
    int koef = Sub(mid + 1, pos);
    AddTo(ans, rl.BitGet(mid + 1, r));
    AddTo(ans, Mult(koef, sumw.BitGet(mid + 1, r) % MOD));
  }
  return ans;
}
int GetMid(int l, int r, int start) {
  if (a[l] > start) return l - 1;
  int lo = l, hi = r, mid;
  for (;;) {
    if (lo + 1 >= hi) {
      if (a[hi] <= start + hi - l)
        return hi;
      else
        return lo;
    }
    mid = (lo + hi) >> 1;
    if (a[mid] <= start + mid - l)
      lo = mid;
    else
      hi = mid;
  }
}
int EvalAtStart(int l, int r, int start) {
  int mid = GetMid(l, r, start);
  return Eval(l, r, mid, start);
}
int Solve(int l, int r) {
  long long total = sumw.BitGet(l, r);
  int lo = l, hi = r, mid;
  for (;;) {
    if (lo + 1 >= hi) {
      if (2 * sumw.BitGet(l, lo) >= total)
        mid = lo;
      else
        mid = hi;
      break;
    }
    mid = (lo + hi) >> 1;
    if (2 * sumw.BitGet(l, mid) <= total)
      lo = mid;
    else
      hi = mid;
  }
  return EvalAtStart(l, r, a[mid] - (mid - l));
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; ++i) scanf("%d", &a_[i]);
  for (int i = 0; i < n; ++i) scanf("%d", &w_[i]);
  for (int i = 0; i < n; ++i) Update(i, a_[i], w_[i]);
  for (int i = 0; i < q; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x > 0) {
      --x, --y;
      printf("%d\n", Solve(x, y));
    } else {
      x = -x - 1;
      Update(x, a[x], y);
    }
  }
  return 0;
}
