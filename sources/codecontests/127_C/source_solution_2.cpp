#include <bits/stdc++.h>
using namespace std;
int t1, t2, x1, x2, t0;
double fun(int y1, int y2) {
  return ((double)t1 * y1 + (double)t2 * y2) / (y1 + y2);
}
int sgn(double w) { return w > 1e-10 ? 1 : (w < -1e-10 ? -1 : 0); }
int find(int y1) {
  int i, j, k, r, w, a1, a2;
  int x, y, mid;
  double y2;
  if (t2 == t0 && (y1 == 0 || t1 == t0))
    return x2;
  else if (t2 == t0)
    return -1;
  y2 = ((double)t0 * y1 - (double)t1 * y1) / (t2 - t0);
  if (sgn(y2 - x2) > 0) return -1;
  a2 = ceil(y2);
  if (a2 > x2) return -1;
  if (a2 < 0) a2 = 0;
  if (sgn(fun(y1, a2) - t0) >= 0)
    return a2;
  else
    return -1;
}
int main() {
  scanf("%d %d %d %d %d", &t1, &t2, &x1, &x2, &t0);
  int i, j, k, r, w, ans = 0, a1 = 0, a2 = x2;
  for (i = 0; i <= x1; i++) {
    int h = find(i);
    if (h == -1) continue;
    if (sgn(fun(i, h) - fun(a1, a2)) < 0 ||
        (sgn(fun(i, h) - fun(a1, a2)) == 0 && h + i > ans)) {
      ans = h + i;
      a1 = i;
      a2 = h;
    }
  }
  printf("%d %d\n", a1, a2);
  return 0;
}
