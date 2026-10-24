#include <bits/stdc++.h>
using namespace std;
void SR(int &x) { scanf("%d", &x); }
void SR(long long &x) { scanf("%lld", &x); }
void SR(double &x) { scanf("%lf", &x); }
void SR(char *s) { scanf("%s", s); }
void RI() {}
template <typename I, typename... T>
void RI(I &x, T &...tail) {
  SR(x);
  RI(tail...);
}
void SP(const int x) { printf("%d", x); }
void SP(const long long x) { printf("%lld", x); }
void SP(const double x) { printf("%.16lf", x); }
void SP(const char *s) { printf(s); }
void PS() { puts(""); }
template <typename I, typename... T>
void PS(I &x, T &...tail) {
  putchar(' ');
  SP(x);
  PS(tail...);
}
void PL() { puts(""); }
template <typename I, typename... T>
void PL(const I x, const T... tail) {
  SP(x);
  PS(tail...);
}
const int maxn = 3.5e5;
struct Point {
  Point() {}
  Point(long long a, long long b) : x(a), y(b) {}
  long long x, y;
  long long operator*(const Point &p) const { return x * p.x + y * p.y; }
  long long operator%(const Point &p) const { return x * p.y - y * p.x; }
  bool operator<(const Point &p) const {
    return make_tuple(y < 0, y == 0 && x < 0, p % (*this)) <
           make_tuple(p.y < 0, p.y == 0 && p.x < 0, 0);
  }
} ar[3 * maxn];
int n;
void read() {
  long long c, d;
  RI(n, c, d);
  for (int i = 0; i < int(n); i++) RI(ar[i].x, ar[i].y);
  for (int i = 0; i < int(n); i++) ar[i].x -= c, ar[i].y -= d;
}
int up[2 * maxn][3];
int type(int i, int j) {
  int ret = (j - i < n ? 0 : 4);
  if (ar[i] % ar[j] > 0)
    return 1 + ret;
  else if (ar[i] % ar[j] == 0) {
    if (ar[i] * ar[j] > 0)
      return 0 + ret;
    else
      return 2 + ret;
  } else
    return 3 + ret;
}
struct Seg {
  long long dat[4 * 3 * maxn];
  void add(int x, int low, int high, int a, int b, long long val) {
    if (low == a && b == high) {
      dat[x] += val * (high - low + 1);
      return;
    }
    int mid = (low + high) / 2;
    long long tag = dat[x] - dat[x << 1] - dat[x << 1 | 1];
    if (b <= mid)
      add(x << 1, low, mid, a, b, val);
    else if (mid + 1 <= a)
      add(x << 1 | 1, mid + 1, high, a, b, val);
    else
      add(x << 1, low, mid, a, mid, val),
          add(x << 1 | 1, mid + 1, high, mid + 1, b, val);
    dat[x] = dat[x << 1] + dat[x << 1 | 1] + tag;
  }
  long long ask(int x, int low, int high, int a, int b) {
    if (low == a && b == high) return dat[x];
    int mid = (low + high) / 2;
    long long ret = 0, tag = dat[x] - dat[x << 1] - dat[x << 1 | 1];
    if (b <= mid)
      ret = ask(x << 1, low, mid, a, b);
    else if (mid + 1 <= a)
      ret = ask(x << 1 | 1, mid + 1, high, a, b);
    else
      ret = ask(x << 1, low, mid, a, mid) +
            ask(x << 1 | 1, mid + 1, high, mid + 1, b);
    return ret + tag / (high - low + 1) * (b - a + 1);
  }
} seg;
void build() {
  sort(ar, ar + n);
  memcpy(ar + n, ar, sizeof(Point) * n);
  memcpy(ar + 2 * n, ar, sizeof(Point) * n);
  for (int t = 0; t < int(3); t++) {
    int &me = up[0][t];
    for (me = 1; type(0, me) <= t; me++)
      ;
  }
  for (int i = (1); i <= int(2 * n - 1); i++)
    for (int t = 0; t < int(3); t++) {
      int &me = up[i][t];
      for (me = up[i - 1][t]; type(i, me) <= t; me++)
        ;
    }
  for (int i = (up[0][0]); i <= int(up[0][1] - 1); i++) {
    int l = up[0][2];
    int r = up[i][1];
    if (l < r) seg.add(1, 0, 3 * n - 1, l, r - 1, 1);
  }
}
void sol() {
  for (int i = 0; i < int(n); i++)
    if (type(i, i + 1) >= 2) {
      PL(0);
      return;
    }
  long long ans = 0;
  for (int i = 0; i < int(n); i++) {
    ans += seg.dat[1];
    if (i == n - 1) break;
    int a = up[i][1];
    int e = up[i][2];
    int b = up[i + 1][1];
    int c = up[i + 1][2];
    if (b < c) {
      long long t = seg.ask(1, 0, 3 * n - 1, b, c - 1);
      seg.add(1, 0, 3 * n - 1, b, c - 1, -t / (c - b));
    }
    if (e < b) {
      long long d = seg.ask(1, 0, 3 * n - 1, e, b - 1);
      seg.add(1, 0, 3 * n - 1, e, b - 1, -d / (b - e));
    }
    for (int j = (a); j <= int(b - 1); j++) {
      int l = up[i + 1][2];
      int r = up[j][1];
      if (l < r) seg.add(1, 0, 3 * n - 1, l, r - 1, 1);
    }
  }
  PL(ans / 3);
}
int main() {
  read();
  build();
  sol();
  return 0;
}
