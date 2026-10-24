#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e2 + 15;
const int P = 1e9 + 7;
const int inf = 0x3f3f3f3f;
int T, m, k, sqr, C[maxn][maxn], S[maxn][maxn], V, ans, fac[maxn], ifac[maxn];
long long l, r, n, N;
inline long long read() {
  char ch = getchar();
  long long u = 0, f = 1;
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    u = u * 10 + ch - 48;
    ch = getchar();
  }
  return u * f;
}
struct Complex {
  int x, y;
  Complex(int a = 0, int b = 0) {
    x = a;
    y = b;
  }
  Complex operator+(const Complex &t) const {
    return Complex((x + t.x) % P, (y + t.y) % P);
  }
  Complex operator-(const Complex &t) const {
    return Complex((x - t.x + P) % P, (y - t.y + P) % P);
  }
  Complex operator*(const Complex &t) const {
    return Complex((1ll * x * t.x % P + 1ll * V * y % P * t.y % P) % P,
                   (1ll * x * t.y % P + 1ll * y * t.x % P) % P);
  }
  Complex operator*(const int &t) const {
    return Complex(1ll * x * t % P, 1ll * y * t % P);
  }
} A, B, alpha, beta;
inline int pls(int x, int y) {
  x += y;
  return x >= P ? x - P : x;
}
inline int dec(int x, int y) {
  x -= y;
  return x < 0 ? x + P : x;
}
inline int mul(int x, int y) { return 1ll * x * y % P; }
inline int ksm(int x, long long k, int rnt = 1) {
  for (long long i = k; i; i >>= 1, x = 1ll * x * x % P)
    if (i & 1) rnt = 1ll * rnt * x % P;
  return rnt;
}
inline Complex ksm(Complex x, long long k, Complex rnt = Complex(1, 0)) {
  for (long long i = k; i; i >>= 1, x = x * x)
    if (i & 1) rnt = rnt * x;
  return rnt;
}
inline Complex Inv(Complex a) {
  return Complex(a.x, P - a.y) *
         (ksm((1ll * a.x * a.x % P - 1ll * V * a.y % P * a.y % P + P) % P,
              P - 2));
}
const int inv2 = (ksm(2, P - 2)), inv10 = (ksm(10, P - 2)),
          inv6 = (ksm(6, P - 2));
int main() {
  T = 1;
  m = 2;
  V = (m == 2) ? 5 : 3;
  S[1][1] = 1;
  for (int i = 0; i <= maxn - 1; ++i) C[i][0] = 1;
  for (int i = 1; i <= maxn - 1; ++i)
    for (int j = 1; j <= i; ++j) C[i][j] = pls(C[i - 1][j - 1], C[i - 1][j]);
  for (int i = 2; i <= maxn - 1; ++i)
    for (int j = 1; j <= i; ++j)
      S[i][j] = dec(S[i - 1][j - 1], mul(i - 1, S[i - 1][j]));
  fac[0] = 1;
  for (int i = 1; i <= maxn - 1; ++i) fac[i] = 1ll * fac[i - 1] * i % P;
  ifac[maxn - 1] = (ksm(fac[maxn - 1], P - 2));
  for (int i = maxn - 2; i >= 0; --i) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % P;
  while (T--) {
    k = read();
    l = read() + 1;
    r = read() + 1;
    ans = 0;
    N = r - l + 1;
    if (m == 2) {
      A = Complex(inv2, inv10);
      B = Complex(inv2, P - inv10);
      alpha = Complex(inv2, inv2);
      beta = Complex(inv2, P - inv2);
    } else {
      l = l + 1 >> 1;
      r >>= 1;
      A = Complex(inv2, inv6);
      B = Complex(inv2, P - inv6);
      alpha = Complex(2, 1);
      beta = Complex(2, P - 1);
    }
    n = r - l + 1;
    for (int i = 1; i <= k; ++i) {
      Complex tmp(0, 0);
      for (int j = 0; j <= i; ++j) {
        Complex c = ksm(A, j) * ksm(B, i - j);
        Complex q = ksm(alpha, j) * ksm(beta, i - j);
        Complex goal = (ksm(q, n + 1) - q) * Inv(q - Complex(1, 0));
        if (q.x == 1 && q.y == 0) goal = q * (n % P);
        tmp = tmp + c * goal * C[i][j] * ksm(q, l - 1);
      }
      ans = (ans + 1ll * S[k][i] * tmp.x % P) % P;
    }
    printf("%d\n", 1ll * ans * ifac[k] % P);
  }
  return 0;
}
