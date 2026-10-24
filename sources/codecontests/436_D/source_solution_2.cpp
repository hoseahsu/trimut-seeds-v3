#include <bits/stdc++.h>
using namespace std;
inline void cmax(int &x, int v) { x = max(x, v); }
int n, m, cn = 0, L[200012], R[200012], le[200012], a[200012], b[2012],
          s[200012], f[200012], g[200012], be[200012];
inline void Get(int i) {
  int j, v = s[R[i]], l;
  for (j = v; j >= 1; j--) {
    l = le[i] - R[i] + b[j];
    if (l < 1) break;
    cmax(g[i], f[be[l] - 1] + v - j + 1);
  }
}
inline void Giv(int i) {
  int j, v = s[R[i]], r;
  for (j = v + 1; j <= m; j++) {
    r = le[i] + b[j] - R[i];
    if (r > n) break;
    cmax(f[be[r]], g[i] + j - v);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  int i, v;
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1);
  for (i = 1; i <= m; i++) scanf("%d", &b[i]);
  sort(b + 1, b + m + 1);
  a[0] = -127;
  for (i = 1; i <= n; i++) {
    if (a[i] != (a[i - 1] + 1)) {
      ++cn;
      L[cn] = a[i];
      R[cn] = a[i] - 1;
    }
    be[i] = cn;
    ++R[cn];
  }
  for (i = 1; i <= cn; i++) le[i] = le[i - 1] + R[i] - L[i] + 1;
  for (i = 1; i <= m; i++) ++s[b[i]];
  for (i = 1; i <= 200000; i++) s[i] += s[i - 1];
  for (i = 1; i <= cn; i++) {
    v = s[R[i]] - s[L[i] - 1];
    cmax(f[i], f[i - 1] + v);
    cmax(g[i], f[i - 1] + v);
    Get(i);
    cmax(f[i], g[i]);
    Giv(i);
  }
  printf("%d", f[cn]);
  return 0;
}
