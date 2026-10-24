#include <bits/stdc++.h>
using namespace std;
double cal_ang(double x, double y) {
  double res = acos(abs(x / hypot(x, y)));
  if (x <= 0 && y >= 0) return acos(-1) - res;
  if (x <= 0 && y < 0) return acos(-1) + res;
  if (x > 0 && y < 0) return acos(-1) * 2.0 - res;
  return res;
}
int main() {
  double x0, x1, y0, y1, t0, t1, t2, t3;
  int n, k;
  vector<double> time;
  scanf("%lf%lf%lf%lf%d", &x0, &y0, &x1, &y1, &n);
  for (long long i = 0; i < ((long long)n); i++) {
    scanf("%lf%lf%lf%lf", &t0, &t1, &t2, &t3);
    if (t3 < 1e-5) continue;
    x0 -= t0;
    x1 -= t0;
    y0 -= t1;
    y1 -= t1;
    double tmp = 0;
    for (long long j = 0; j < ((long long)100 + 1); j++) {
      double x = x0 + (x1 - x0) * j / (double)100;
      double y = y0 + (y1 - y0) * j / (double)100;
      double ang = cal_ang(x, y);
      ang -= t2;
      if (ang < 0) ang += 2.0 * acos(-1);
      while (ang > acos(-1) * 2.0) ang -= acos(-1) * 2.0;
      ang = min(acos(-1) * 2.0 - ang, ang);
      tmp = max(tmp, hypot(x0 - x, y0 - y) / (ang / t3));
    }
    time.push_back(tmp);
    x0 += t0;
    x1 += t0;
    y0 += t1;
    y1 += t1;
  }
  scanf("%d", &k);
  if (((long long)time.size()) <= k) {
    printf("0.0000\n");
    return 0;
  }
  sort(time.begin(), time.end());
  reverse(time.begin(), time.end());
  printf("%.4lf\n", time[k]);
}
