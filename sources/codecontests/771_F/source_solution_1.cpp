#include <bits/stdc++.h>
using namespace std;
int n, num, t, top, T;
struct DOT {
  double x, y;
  DOT(double _x = 0, double _y = 0) { x = _x, y = _y; }
} a[1000100], b[1000100], d[1000100], O;
DOT operator+(DOT a, DOT b) { return DOT(a.x + b.x, a.y + b.y); }
DOT operator-(DOT a, DOT b) { return DOT(a.x - b.x, a.y - b.y); }
DOT operator*(DOT a, double k) { return DOT(a.x * k, a.y * k); }
double ctime(DOT a, DOT b) { return a.x * b.y - a.y * b.x; }
double dtime(DOT a, DOT b) { return a.x * b.x + a.y * b.y; }
inline int dcmp(const double &a) {
  if (fabs(a) <= 1e-6) return 0;
  return a < 0 ? -1 : 1;
}
struct LINE {
  DOT u, v;
  LINE() {}
  LINE(DOT _u, DOT _v) {
    u = _u, v = _v;
    ;
  };
} l[1000100], que[1000100];
inline bool cmp1(const DOT &a, const DOT &b) {
  if (!dcmp(a.y))
    return a.x < 0 ? (dcmp(b.y) || a.x < b.x)
                   : (b.y > 0 || (!dcmp(b.y) && b.x > a.x));
  if (!dcmp(b.y))
    return b.x < 0 ? (!dcmp(a.y) && a.x < b.x)
                   : (a.y < 0 || (!dcmp(a.y) && b.x > a.x));
  if (a.y < 0)
    if (b.y > 0) return 1;
  if (a.y > 0)
    if (b.y < 0) return 0;
  return dcmp(ctime(a, b)) > 0;
}
bool cmp(LINE a, LINE b) { return cmp1(a.v, b.v); }
DOT inter(LINE a, LINE b) {
  return b.u + (b.v * (ctime(a.v, a.u - b.u) / ctime(a.v, b.v)));
}
bool check(LINE a, LINE b, LINE c) {
  return dcmp(ctime(a.v, inter(b, c) - a.u)) > 0;
}
void merge() {
  sort(l + 1, l + top + 1, cmp);
  for (int i = 1, _ = top; i <= _; ++i)
    if (i == 1)
      top = 1;
    else if (dcmp(ctime(l[i].v, l[top].v)))
      l[++top] = l[i];
    else
      l[top] = dcmp(ctime(l[top].u - l[i].u, l[i].v)) >= 0 ? l[i] : l[top];
  int h = 1, t = 0;
  for (int i = 1; i <= top; i++) {
    while (h < t && !check(que[t - 1], que[t], l[i])) --t;
    while (h < t && !check(l[i], que[h], que[h + 1])) ++h;
    que[++t] = l[i];
  }
  while (h + 1 < t && !check(que[t - 1], que[t], que[h])) --t;
  while (h + 1 < t && !check(que[t], que[h], que[h + 1])) ++h;
  top = t - h + 1;
  for (int i = 1; i <= top; ++i) que[i] = que[i + h - 1];
}
int main() {
  scanf("%d", &t);
  while (t--) {
    top = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%lf %lf", &a[i].x, &a[i].y);
    l[++top] = LINE(DOT(-1e6, -1e6) - a[1], DOT(1, 0));
    l[++top] = LINE(DOT(1e6, -1e6) - a[1], DOT(0, 1));
    l[++top] = LINE(DOT(1e6, 1e6) - a[1], DOT(-1, 0));
    l[++top] = LINE(DOT(-1e6, 1e6) - a[1], DOT(0, -1));
    for (int i = 2; i <= n; ++i) a[i] = a[i] - a[1];
    for (int i = 1; i < n; ++i) a[i] = a[i + 1];
    --n;
    sort(a + 1, a + n + 1, cmp1);
    int P = 0;
    for (int i = 1; i <= n; ++i) {
      int j = i % n + 1, k = dcmp(ctime(a[i], a[j]));
      if (!k) {
        P = 1;
        printf("0.00000000\n");
        break;
      }
      if (k > 0)
        l[++top] = (LINE){a[i], a[j] - a[i]};
      else
        l[++top] = (LINE){a[j], a[i] - a[j]};
    }
    if (P) continue;
    for (int i = 1, j = 1; i <= n; ++i) {
      if (dcmp(ctime(a[i % n + 1], a[i])) > 0) continue;
      if (dcmp(ctime(a[i], a[(i - 2 + n) % n + 1])) > 0) continue;
      while (i == j || dcmp(ctime(a[i], a[j])) > 0) j = j % n + 1;
      if (!dcmp(ctime(a[i], a[j]))) {
        P = 1;
        printf("0.00000000\n");
        break;
      }
      l[++top] = (LINE){a[j], a[i] - a[j]};
    }
    if (P) continue;
    merge();
    que[top + 1] = que[1];
    for (int i = 1; i <= top; ++i) d[i] = inter(que[i], que[i + 1]);
    double ans = 0;
    d[top + 1] = d[1];
    for (int i = 1; i <= top; ++i) ans += ctime(d[i], d[i + 1]);
    printf("%.15lf\n", fabs(ans) / 2.0);
  }
}
