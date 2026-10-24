#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
template <class T>
void Read(T &x) {
  char c;
  bool f = 0;
  while (c = getchar(), c != EOF)
    if (c == '-')
      f = 1;
    else if (c >= '0' && c <= '9') {
      x = c - '0';
      while (c = getchar(), c >= '0' && c <= '9') x = x * 10 + c - '0';
      ungetc(c, stdin);
      if (f) x = -x;
      return;
    }
}
namespace arr {
inline int lowbit(int x) { return x & (-x); }
template <class T>
inline void arrUpdate(T *c, int x, T d, int N) {
  while (x <= N) {
    c[x] += d;
    x += lowbit(x);
  }
}
template <class T>
inline T arrGetsum(T *c, int x) {
  T ret = 0;
  while (x) {
    ret += c[x];
    x -= lowbit(x);
  }
  return ret;
}
}  // namespace arr
namespace Polynomial {
namespace FFT {
struct cplx {
  double a, b;
  cplx() {}
  cplx(double a, double b = 0) : a(a), b(b) {}
  inline cplx operator+(const cplx &x) const { return cplx(a + x.a, b + x.b); }
  inline cplx operator-(const cplx &x) const { return cplx(a - x.a, b - x.b); }
  inline cplx operator*(const cplx &x) const {
    return cplx(a * x.a - b * x.b, a * x.b + b * x.a);
  }
  inline cplx &operator*=(const cplx &x) { return *this = *this * x; }
  inline double sqr(double x) const { return x * x; }
  inline cplx operator/(const cplx &x) const {
    double t = sqr(x.a) + sqr(x.b);
    return cplx((a * x.a + b * x.b) / t, (b * x.a - a * x.b) / t);
  }
  inline cplx operator/=(const cplx &x) { return *this = *this / x; }
};
void FFT(cplx *a, int n, int type) {
  for (int i = 1, j = 0; i < n; i++) {
    for (int t = n; j ^= (t >>= 1), (~j) & t;)
      ;
    if (i < j) swap(a[i], a[j]);
  }
  cplx x, y;
  for (int i = 1; i < n; i <<= 1) {
    cplx w1(cos(PI / i), sin(type * PI / i));
    for (int j = 0; j < n; j += i << 1) {
      cplx w(1, 0);
      for (int k = 0; k < i; k++) {
        x = a[j + k], y = w * a[j + k + i];
        a[j + k] = x + y, a[j + k + i] = x - y;
        w *= w1;
      }
    }
  }
  if (type == -1) {
    for (int i = 0; i < n; i++) a[i].a /= n, a[i].b /= n;
  }
}
void Multi(cplx *a, cplx *b, int n, int m) {
  m += n;
  for (n = 1; n <= m; n <<= 1)
    ;
  FFT(a, n, 1), FFT(b, n, 1);
  for (int i = 0; i < n; i++) a[i] *= b[i];
  FFT(a, n, -1);
}
}  // namespace FFT
namespace NTT {
inline int mypow(int x, int k) {
  int ret = 1;
  while (k) {
    if (k & 1) ret = 1LL * ret * x % (119 * (1 << 23) + 1);
    x = 1LL * x * x % (119 * (1 << 23) + 1);
    k >>= 1;
  }
  return ret;
}
void NTT(int *a, int n, int type) {
  for (int i = 1, j = 0; i < n; i++) {
    for (int t = n; j ^= (t >>= 1), (~j) & t;)
      ;
    if (i < j) swap(a[i], a[j]);
  }
  int x, y;
  for (int i = 1; i < n; i <<= 1) {
    int w1 = mypow(3, ((119 * (1 << 23) + 1) - 1) / (i << 1));
    for (int j = 0; j < n; j += i << 1) {
      int w = 1;
      for (int k = 0; k < i; k++) {
        x = a[j + k], y = 1LL * w * a[j + k + i] % (119 * (1 << 23) + 1);
        a[j + k] = (x + y) % (119 * (1 << 23) + 1),
              a[j + k + i] =
                  (x - y + (119 * (1 << 23) + 1)) % (119 * (1 << 23) + 1);
        w = 1LL * w * w1 % (119 * (1 << 23) + 1);
      }
    }
  }
  if (type == -1) {
    reverse(a + 1, a + n);
    long long inv = mypow(n, (119 * (1 << 23) + 1) - 2);
    for (int i = 0; i < n; i++) a[i] = 1LL * a[i] * inv % (119 * (1 << 23) + 1);
  }
}
void Multi(int *a, int *b, int n, int m) {
  m += n;
  for (n = 1; n <= m; n <<= 1)
    ;
  NTT(a, n, 1), NTT(b, n, 1);
  for (int i = 0; i < n; i++) a[i] = 1LL * a[i] * b[i] % (119 * (1 << 23) + 1);
  NTT(a, n, -1);
}
}  // namespace NTT
namespace FWT {
void Xor(int *f, int n) {
  int S = 1 << n;
  for (int i = 1; i < S; i <<= 1)
    for (int j = 1; j < S; j++)
      if (j & i) f[j] += f[j ^ i];
}
void iXor(int *f, int n) {
  int S = 1 << n;
  for (int i = 1; i < S; i <<= 1)
    for (int j = 1; j < S; j++)
      if (j & i) f[j] -= f[j ^ i];
}
}  // namespace FWT
}  // namespace Polynomial
int ans, x, c[16] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1, 1, 2, 0, 1, 0, 0};
int main() {
  Read(x);
  if (!x) ans = c[0];
  while (x) {
    ans += c[x & 15];
    x >>= 4;
  }
  printf("%d\n", ans);
  return 0;
}
