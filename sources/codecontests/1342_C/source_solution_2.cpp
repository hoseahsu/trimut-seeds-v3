#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T bigMod(T p, T e, T M) {
  T ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  }
  return (T)ret;
}
template <class T>
inline T modInverse(T a, T M) {
  return bigMod(a, M - 2, M);
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T lcm(T a, T b) {
  a = abs(a);
  b = abs(b);
  return (a / gcd(a, b)) * b;
}
template <class T>
inline T SQR(T a) {
  return a * a;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long int a, b, q;
    scanf("%lld %lld", &a, &b);
    scanf("%lld", &q);
    ;
    if (a > b) swap(a, b);
    long long int lc = lcm(a, b);
    while (q--) {
      long long int x, y;
      scanf("%lld %lld", &x, &y);
      if (y < b)
        printf("0 ");
      else if (y == b) {
        if (lc == b)
          printf("0 ");
        else
          printf("1 ");
      } else {
        long long int total = 0;
        long long int c = (x / lc);
        long long int d = (y / lc);
        total += (d - c) * b;
        total -= max(0LL, d * lc + b - 1 - y);
        total += max(0LL, c * lc + b - x);
        total = y - x + 1 - total;
        printf("%lld", total);
        printf(" ");
      }
    }
    printf("\n");
  }
  return 0;
}
