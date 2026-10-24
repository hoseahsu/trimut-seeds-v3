#include <bits/stdc++.h>
using namespace std;
namespace zyt {
const int N = 5e4 + 10;
const double EPS = 1e-7, PI = acos(-1);
bool equal(const double a, const double b) { return fabs(a - b) < EPS; }
struct point {
  double x, y, theta;
  point(const double _x = 0, const double _y = 0) : x(_x), y(_y) { cal(); }
  void cal() { theta = atan2(y, x) + PI; }
  bool operator!=(const point &b) const {
    return !equal(x, b.x) || !equal(y, b.y);
  }
};
double cross(const point &A, const point &B) { return A.x * B.y - B.x * A.y; }
double area(const point &A, const point &B) { return fabs(cross(A, B)) / 2; }
double sq(const double x) { return x * x; }
bool internal(const double &k, const double &a, const double &b) {
  if (a <= b)
    return a <= k && k <= b;
  else
    return k >= a || k <= b;
}
struct line {
  point A, B;
  line(const point &a = point(), const point &b = point()) : A(a), B(b) {
    if (cross(A, B) < 0) swap(A, B);
  }
  bool operator<(const line &b) const;
} L[N << 1];
point get(const line &L, const double theta) {
  double kk = tan(theta);
  if (equal(L.A.x, L.B.x))
    return point(L.A.x, kk * L.A.x);
  else {
    double k = (L.A.y - L.B.y) / (L.A.x - L.B.x), b = L.A.y - k * L.A.x;
    return point(b / (kk - k), kk * b / (kk - k));
  }
}
double dis(const point &a) { return sqrt(sq(a.x) + sq(a.y)); }
double dis(const line &L, const double theta) { return dis(get(L, theta)); }
bool line::operator<(const line &b) const {
  if (A != b.A && A != b.B && internal(A.theta, b.A.theta, b.B.theta))
    return dis(*this, A.theta) < dis(b, A.theta);
  else if (B != b.A && B != b.B && internal(B.theta, b.A.theta, b.B.theta))
    return dis(*this, B.theta) < dis(b, B.theta);
  else if (b.A != A && b.A != B && internal(b.A.theta, A.theta, B.theta))
    return dis(*this, b.A.theta) < dis(b, b.A.theta);
  else if (b.B != A && b.B != B && internal(b.B.theta, A.theta, B.theta))
    return dis(*this, b.B.theta) < dis(b, b.B.theta);
  else
    return false;
}
set<line> s;
int n, m, cnt;
double d[N];
vector<int> in[N], out[N];
int unique(double *const d, const int n) {
  int cnt = 0;
  d[cnt++] = d[0];
  for (int i = 1; i < n; i++)
    if (!equal(d[i], d[cnt - 1])) d[cnt++] = d[i];
  return cnt;
}
int find(const double x) {
  int p = lower_bound(d, d + cnt, x) - d;
  return p - (!equal(d[p], x) ? 1 : 0);
}
int work() {
  scanf("%d", &n);
  d[cnt++] = 0;
  d[cnt++] = 2 * PI - EPS;
  for (int i = 0; i < n; i++) {
    int k;
    scanf("%d", &k);
    point last, first;
    scanf("%lf%lf", &first.x, &first.y);
    first.cal();
    last = first;
    while (k--) {
      point p;
      if (k) {
        scanf("%lf%lf", &p.x, &p.y);
        p.cal();
      } else
        p = first;
      if (!equal(p.theta, last.theta)) {
        d[cnt++] = p.theta;
        line tmp = line(last, p);
        if (tmp.A.theta < tmp.B.theta)
          L[m++] = tmp;
        else {
          L[m++] = line(get(tmp, 2 * PI - EPS), tmp.A);
          L[m++] = line(get(tmp, 0), tmp.B);
        }
      }
      last = p;
    }
  }
  sort(d, d + cnt);
  cnt = unique(d, cnt);
  for (int i = 0; i < m; i++) {
    int a = find(L[i].A.theta), b = find(L[i].B.theta);
    if (a > b)
      fprintf(stderr, "gg1");
    else if (a < b)
      in[a].push_back(i), out[b].push_back(i);
  }
  double ans = 0;
  for (int i = 0; i < cnt - 1; i++) {
    for (auto j : out[i]) s.erase(L[j]);
    for (auto j : in[i]) s.insert(L[j]);
    if (s.size() >= 2) {
      if (s.size() < 2) fprintf(stderr, "gg2");
      line a = *s.begin(), b = *++s.begin();
      ans += area(get(b, d[i]), get(b, d[i + 1])) -
             area(get(a, d[i]), get(a, d[i + 1]));
    }
  }
  printf("%.6f", ans);
  return 0;
}
}  // namespace zyt
int main() { return zyt::work(); }
