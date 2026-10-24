#include <bits/stdc++.h>
using namespace std;
const long long N = 1000010;
inline long long read() {
  long long s = 0, w = 1;
  register char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    s = (s << 3) + (s << 1) + (ch ^ 48), ch = getchar();
  return s * w;
}
long long K, n, a[N];
struct Node {
  long long w, d;
} F[N];
inline Node operator+(Node x, Node y) { return (Node){x.w + y.w, x.d + y.d}; }
inline Node Min(Node x, Node y) {
  if (x.w == y.w) {
    if (x.d > y.d) return x;
    return y;
  }
  if (x.w < y.w) return x;
  return y;
}
void ClearL() {
  for (register long long i = 0; i <= n; i++) F[i].w = 1e18, F[i].d = 0;
}
inline bool Check(long long X) {
  ClearL();
  F[0].w = F[0].d = 0;
  for (register long long i = 0; i < n; i++) {
    F[i + 1] = Min(F[i + 1], F[i]);
    F[i + 2] = Min(F[i + 2], F[i] + (Node){a[i + 2] - a[i + 1] - X, 1});
  }
  return (F[n].d >= K);
}
signed main() {
  K = read(), n = read();
  for (register long long i = 1; i <= n; i++) a[i] = read();
  sort(a + 1, a + 1 + n);
  long long L = 0, R = 1e9, res = 0;
  while (L <= R) {
    long long mid = (L + R) / 2;
    if (Check(mid))
      res = mid, R = mid - 1;
    else
      L = mid + 1;
  }
  Check(res);
  printf("%lld\n", res * K + F[n].w);
  return 0;
}
