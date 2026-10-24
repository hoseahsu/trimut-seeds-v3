#include <bits/stdc++.h>
const double eps = 1e-3;
std::complex<double> arr[1005], pnt[2];
int st[2], tp, n;
inline double crs(std::complex<double> a, std::complex<double> b) {
  return imag(a * conj(b));
}
inline double dis(std::complex<double> a, std::complex<double> b) {
  return abs(a - b);
}
inline void inter(std::complex<double> s, std::complex<double> t,
                  std::complex<double> x, std::complex<double> y, int idx) {
  double a = crs(t - s, x - s), b = crs(y - s, t - s), c = crs(s - x, y - x),
         d = crs(y - x, t - x);
  if (fabs(a) < eps && fabs(b) < eps) return;
  if (fabs(dis(s, x) + dis(x, t) - dis(s, t)) < eps) {
    pnt[tp] = x;
    st[tp++] = idx;
  }
  if (a * b >= eps && c * d >= eps) {
    pnt[tp] = (b * x + a * y) / (a + b);
    st[tp++] = idx;
  }
}
inline double calc(int l, int r, std::complex<double> s,
                   std::complex<double> t) {
  l = (l + 1) % n;
  double res = dis(s, arr[l]) + dis(arr[r], t);
  for (int i = l; i != r; i = (i + 1) % n) res += dis(arr[i], arr[i + 1]);
  return res;
}
int main() {
  std::complex<double> s, t;
  {
    int _x, _y;
    scanf("%d%d", &_x, &_y);
    s = std::complex<double>(_x, _y);
  };
  {
    int _x, _y;
    scanf("%d%d", &_x, &_y);
    t = std::complex<double>(_x, _y);
  };
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int _x, _y;
    scanf("%d%d", &_x, &_y);
    arr[i] = std::complex<double>(_x, _y);
  };
  arr[n] = arr[0];
  for (int i = 0; i < n; i++) inter(s, t, arr[i], arr[i + 1], i);
  if (tp > 1) {
    if (dis(s, pnt[0]) > dis(s, pnt[1])) {
      std::swap(pnt[0], pnt[1]);
      std::swap(st[0], st[1]);
    }
    printf("%.9lf\n", std::min(2 * dis(pnt[0], pnt[1]),
                               std::min(calc(st[0], st[1], pnt[0], pnt[1]),
                                        calc(st[1], st[0], pnt[1], pnt[0]))) +
                          dis(s, pnt[0]) + dis(pnt[1], t));
  } else
    printf("%.9lf\n", dis(s, t));
  return 0;
}
