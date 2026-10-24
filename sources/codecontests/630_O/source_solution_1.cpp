#include <bits/stdc++.h>
using namespace std;
double a, b, c, d;
struct point {
  double x, y;
} p, v, s[10];
double sinx, cosx;
int main() {
  while (~scanf("%lf%lf%lf%lf", &p.x, &p.y, &v.x, &v.y)) {
    scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
    double tp = sqrt(v.x * v.x + v.y * v.y);
    cosx = v.x / tp;
    sinx = v.y / tp;
    a /= 2.0;
    c /= 2.0;
    s[0].x = p.x + b * cosx;
    s[0].y = p.y + b * sinx;
    s[1].x = p.x - a * sinx;
    s[1].y = p.y + a * cosx;
    s[6].x = p.x + a * sinx;
    s[6].y = p.y - a * cosx;
    s[2].x = p.x - c * sinx;
    s[2].y = p.y + c * cosx;
    s[5].x = p.x + c * sinx;
    s[5].y = p.y - c * cosx;
    s[3].x = s[2].x - d * cosx;
    s[3].y += s[2].y - d * sinx;
    s[4].x = s[5].x - d * cosx;
    s[4].y = s[5].y - d * sinx;
    for (int i = 0; i < 7; ++i) {
      printf("%.10f %.10f\n", s[i].x, s[i].y);
    }
  }
  return 0;
}
