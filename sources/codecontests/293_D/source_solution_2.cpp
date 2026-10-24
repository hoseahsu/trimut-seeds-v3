#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
inline T1 max(T1 a, T2 b) {
  return a < b ? b : a;
}
template <typename T1, typename T2>
inline T1 min(T1 a, T2 b) {
  return a < b ? a : b;
}
template <typename T1, typename T2>
inline T1 gmax(T1 &a, T2 b) {
  return a = a < b ? b : a;
}
template <typename T1, typename T2>
inline T1 gmin(T1 &a, T2 b) {
  return a = a < b ? a : b;
}
const char lf = '\n';
namespace ae86 {
const int bufl = 1 << 15;
char buf[bufl], *s = buf, *t = buf;
inline int fetch() {
  if (s == t) {
    t = (s = buf) + fread(buf, 1, bufl, stdin);
    if (s == t) return EOF;
  }
  return *s++;
}
inline int ty() {
  int a = 0;
  int b = 1, c = fetch();
  while (!isdigit(c)) b ^= c == '-', c = fetch();
  while (isdigit(c)) a = a * 10 + c - 48, c = fetch();
  return b ? a : -a;
}
}  // namespace ae86
using ae86::ty;
const int _ = 100007, X = 1000000, inf = 0x3f3f3f3f;
struct points {
  long long x, y;
  points(long long x_ = 0, long long y_ = 0) { x = x_, y = y_; }
  void takein() { x = ty(), y = ty(); }
  void rever() { swap(x, y); }
  friend points operator+(points a, points b) {
    return points(a.x + b.x, a.y + b.y);
  }
  friend points operator-(points a, points b) {
    return points(a.x - b.x, a.y - b.y);
  }
};
inline long long dox(points a, points b) { return a.x * b.x + a.y * b.y; }
inline long long cox(points a, points b) { return a.x * b.y - a.y * b.x; }
inline long long length2(points a) { return dox(a, a); }
inline long long distan2(points a, points b) { return length2(b - a); }
int n;
points p[_];
int xlBuf[X + X + 7], xrBuf[X + X + 7], *xl = xlBuf + X + 3,
                                        *xr = xrBuf + X + 3;
double make() {
  for (int i = -X; i <= X; i++) xl[i] = inf, xr[i] = -inf;
  for (int i = 1; i <= n; i++) {
    if (p[i].x == p[i + 1].x)
      gmin(xl[p[i].x], p[i].y), gmax(xr[p[i].x], p[i].y);
    else {
      points a = p[i], b = p[i + 1];
      if (a.x > b.x) swap(a, b);
      double k = 1.00 / (b.x - a.x);
      for (int j = a.x; j <= b.x; j++) {
        double loc = ((j - a.x) * b.y + (b.x - j) * a.y) * k;
        gmin(xl[j], ceil(loc)), gmax(xr[j], floor(loc));
      }
    }
  }
  double s = 0, si = 0, si2 = 0;
  for (int i = -X; i <= X; i++) {
    if (xr[i] < xl[i]) continue;
    long long dlt = xr[i] - xl[i] + 1;
    s += dlt, si += dlt * i, si2 += dlt * i * i;
  }
  return (s * si2 - si * si) / s / (s - 1);
}
int main() {
  ios::sync_with_stdio(0), cout.tie(nullptr);
  n = ty();
  for (int i = 1; i <= n; i++) p[i].takein();
  p[0] = p[n], p[n + 1] = p[1];
  double ans = make();
  for (int i = 0; i <= n + 1; i++) p[i].rever();
  ans += make();
  cout << setprecision(11) << fixed << ans << lf;
  return 0;
}
