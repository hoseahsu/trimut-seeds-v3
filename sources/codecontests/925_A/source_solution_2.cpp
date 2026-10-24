#include <bits/stdc++.h>
using namespace std;
const int N = 123456;
int a[N];
int b[N];
int main() {
  int n, m, na, nb, v;
  scanf("%d%d%d%d%d", &n, &m, &na, &nb, &v);
  for (int i = 0; i < na; i++) {
    scanf("%d", a + i);
  }
  sort(a, a + na);
  for (int i = 0; i < nb; i++) {
    scanf("%d", b + i);
  }
  sort(b, b + nb);
  int q;
  scanf("%d", &q);
  while (q--) {
    int sx, sy, ex, ey;
    scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
    if (sx == ex) {
      printf("%d\n", abs(sy - ey));
      continue;
    }
    int ans = (int)2e9;
    if (na > 0) {
      int ca = (int)1e9;
      int pos = 0;
      for (int shift = 65536; shift; shift >>= 1) {
        if (pos + shift < na && a[pos + shift] <= sy) {
          pos += shift;
        }
      }
      for (int i = max(0, pos - 2); i < min(na, pos + 2); i++) {
        ans = min(ans, abs(a[i] - sy) + abs(sx - ex) + abs(a[i] - ey));
      }
    }
    if (nb > 0) {
      int cb = (int)1e9;
      int pos = 0;
      for (int shift = 65536; shift; shift >>= 1) {
        if (pos + shift < nb && b[pos + shift] <= sy) {
          pos += shift;
        }
      }
      for (int i = max(0, pos - 2); i < min(nb, pos + 2); i++) {
        ans = min(ans, abs(b[i] - sy) + ((abs(sx - ex) + v - 1) / v) +
                           abs(b[i] - ey));
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
