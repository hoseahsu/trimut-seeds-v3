#include <bits/stdc++.h>
namespace chtholly {
char buf[1 << 23], *p1 = buf, *p2 = buf;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar()) f ^= c == '-';
  for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ '0');
  return f ? x : -x;
}
template <typename mitsuha>
inline bool read(mitsuha &x) {
  x = 0;
  int f = 1;
  char c = getchar();
  for (; !isdigit(c) && ~c; c = getchar()) f ^= c == '-';
  if (!~c) return 0;
  for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ '0');
  return x = f ? x : -x, 1;
}
template <typename mitsuha>
inline int write(mitsuha x) {
  if (!x) return 0 & putchar(48);
  if (x < 0) putchar('-'), x = -x;
  int bit[20], i, p = 0;
  for (; x; x /= 10) bit[++p] = x % 10;
  for (i = p; i; --i) putchar(bit[i] + 48);
  return 0;
}
inline char fuhao() {
  char c = getchar();
  for (; isspace(c); c = getchar())
    ;
  return c;
}
}  // namespace chtholly
using namespace chtholly;
using namespace std;
const int yuzu = 3e5;
struct node {
  long long a, b, c;
  bool operator<(const node &x) const { return a < x.a; }
};
priority_queue<node> q;
long long gv(long long a, long long b) {
  long long u = a / b, v = a - u * b;
  return (b - v) * u * u + v * (u + 1) * (u + 1);
}
int main() {
  int n, k, i;
  long long lxy = 0, t;
  read(n), read(k);
  for (i = 1; i <= n; ++i) {
    t = read(), lxy += t * t;
    q.push({gv(t, 1) - gv(t, 2), t, 2});
  }
  for (i = 1; i <= k - n; ++i) {
    lxy -= q.top().a;
    long long b = q.top().b, c = q.top().c;
    q.pop();
    q.push({gv(b, c) - gv(b, c + 1), b, c + 1});
  }
  printf("%lld\n", lxy);
}
