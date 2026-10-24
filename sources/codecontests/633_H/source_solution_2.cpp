#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0;
  bool f = 0;
  char c = getchar();
  for (; c < '0' || c > '9'; c = getchar()) f = c == '-' ? 1 : 0;
  for (; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + c - '0';
  return f ? -x : x;
}
const int N = 30005, B = 350;
int n, m, P, L, A[N], num[N], bl[N], ans[N], f[N], ct[N], sz[N * 4], s1[N * 4],
    s2[N * 4];
struct na {
  int l, r, id;
} e[N];
inline bool cmp(const na &a, const na &b) {
  if (bl[a.l] != bl[b.l]) return a.l < b.l;
  return (bl[a.l] & 1) ? (a.r < b.r) : (a.r > b.r);
}
inline void ins(int a) {
  if (ct[a]++) return;
  int o = 1, l = 1, r = L, mid;
  while (l != r) {
    if (a <= (mid = l + r >> 1))
      o = (o << 1), r = mid;
    else
      o = (o << 1 | 1), l = mid + 1;
  }
  s1[o] = num[a], sz[o] = 1;
  for (o >>= 1; o; o >>= 1) {
    a = sz[(o << 1)], sz[o] = sz[(o << 1)] + sz[(o << 1 | 1)];
    s1[o] =
        (s1[(o << 1)] + f[a + 1] * s1[(o << 1 | 1)] + f[a] * s2[(o << 1 | 1)]) %
        P;
    s2[o] = (s2[(o << 1)] +
             (a ? f[a] * s1[(o << 1 | 1)] + f[a - 1] * s2[(o << 1 | 1)]
                : s2[(o << 1 | 1)])) %
            P;
  }
}
inline void del(int a) {
  if (--ct[a]) return;
  int o = 1, l = 1, r = L, mid;
  while (l != r) {
    if (a <= (mid = l + r >> 1))
      o = (o << 1), r = mid;
    else
      o = (o << 1 | 1), l = mid + 1;
  }
  s1[o] = sz[o] = 0;
  for (o >>= 1; o; o >>= 1) {
    a = sz[(o << 1)], sz[o] = sz[(o << 1)] + sz[(o << 1 | 1)];
    s1[o] =
        (s1[(o << 1)] + f[a + 1] * s1[(o << 1 | 1)] + f[a] * s2[(o << 1 | 1)]) %
        P;
    s2[o] = (s2[(o << 1)] +
             (a ? f[a] * s1[(o << 1 | 1)] + f[a - 1] * s2[(o << 1 | 1)]
                : s2[(o << 1 | 1)])) %
            P;
  }
}
int main() {
  n = read(), P = read();
  for (int i = 1; i <= n; i++) A[i] = num[i] = read(), bl[i] = (i - 1) / B + 1;
  for (int i = (f[1] = 1, 2); i <= n; i++) f[i] = (f[i - 1] + f[i - 2]) % P;
  sort(num + 1, num + n + 1);
  L = unique(num + 1, num + n + 1) - num - 1;
  for (int i = 1; i <= n; i++)
    A[i] = lower_bound(num + 1, num + L + 1, A[i]) - num;
  m = read();
  for (int i = 1; i <= m; i++) e[i].l = read(), e[i].r = read(), e[i].id = i;
  sort(e + 1, e + m + 1, cmp);
  for (int i = 1, l = 1, r = 0; i <= m; i++) {
    while (e[i].l < l) ins(A[--l]);
    while (r < e[i].r) ins(A[++r]);
    while (l < e[i].l) del(A[l++]);
    while (e[i].r < r) del(A[r--]);
    ans[e[i].id] = s1[1];
  }
  for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
  return 0;
}
