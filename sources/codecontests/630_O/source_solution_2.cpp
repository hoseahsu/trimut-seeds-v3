#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
struct point {
  double x, y;
  point() {}
  point(const double &x, const double &y) : x(x), y(y) {}
  friend point operator+(const point &a, const point &b) {
    return point(a.x + b.x, a.y + b.y);
  }
  friend point operator-(const point &a, const point &b) {
    return point(a.x - b.x, a.y - b.y);
  }
  friend point operator/(const point &a, const double &b) {
    return point(a.x / b, a.y / b);
  }
  friend point rotate(const point &a, const double &COS, const double &SIN) {
    return point(a.x * COS - a.y * SIN, a.x * SIN + a.y * COS);
  }
  friend double dot(const point &a, const point &b) {
    return a.x * b.x + a.y * b.y;
  }
  friend double dist(const point &a, const point &b) {
    return sqrt(dot(a - b, a - b));
  }
  friend double det(const point &a, const point &b) {
    return a.x * b.y - a.y * b.x;
  }
  void out() { printf("%.12f %.12f\n", x, y); }
  void in() { cin >> x >> y; }
} q[7], p, v;
double a, b, c, d;
int main() {
  p.in(), v.in();
  cin >> a >> b >> c >> d;
  a /= 2, c /= 2;
  q[0] = point(b, 0);
  q[1] = point(0, a);
  q[2] = point(0, c);
  q[3] = point(-d, c);
  q[4] = point(-d, -c);
  q[5] = point(0, -c);
  q[6] = point(0, -a);
  double l = dist(point(0, 0), v);
  for (int i = 0; i < 7; i++) {
    (rotate(q[i], v.x / l, v.y / l) + p).out();
  }
  return 0;
}
