#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:200000000")
using namespace std;
template <typename T>
inline T Abs(T x) {
  return (x >= 0) ? x : -x;
}
template <typename T>
inline T sqr(T x) {
  return x * x;
}
template <typename T>
string toStr(T x) {
  stringstream st;
  st << x;
  string s;
  st >> s;
  return s;
}
inline int nextInt() {
  int x;
  if (scanf("%d", &x) != 1) throw;
  return x;
}
inline long long nextInt64() {
  long long x;
  if (scanf("%I64d", &x) != 1) throw;
  return x;
}
inline double nextDouble() {
  double x;
  if (scanf("%lf", &x) != 1) throw;
  return x;
}
const int INF = (int)1E9;
const long long INF64 = (long long)1E18;
const long double EPS = 1E-9;
const long double PI = 3.1415926535897932384626433832795;
const int MAXN = 110;
struct point {
  double x, y;
  point(double x = 0, double y = 0) : x(x), y(y) {}
};
double det(double a, double b, double c, double d) { return a * d - b * c; }
double dist(point a, point b) { return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y)); }
double d[MAXN][MAXN];
point f, s;
int n;
int main() {
  s.x = nextInt();
  s.y = nextInt();
  f.x = nextInt();
  f.y = nextInt();
  n = nextInt();
  vector<point> a(n);
  vector<int> sign(n, 0);
  for (int i = 0; i < (int)(n); i++) {
    a[i].x = nextInt();
    a[i].y = nextInt();
  }
  double A = s.y - f.y;
  double B = f.x - s.x;
  double C = -(A * f.x + B * f.y);
  for (int i = 0; i < (int)(n); i++) {
    double cur = A * a[i].x + B * a[i].y + C;
    if (cur > +EPS) sign[i] = +1;
    if (cur < -EPS) sign[i] = -1;
  }
  for (int i = 0; i < (int)(n); i++) {
    int sv = sign[i], su = sign[(i + 1) % n];
    point v = a[i], u = a[(i + 1) % n];
    if (sv * su == -1) {
      double A1 = v.y - u.y;
      double B1 = u.x - v.x;
      double C1 = -(A1 * u.x + B1 * u.y);
      double z = det(A, B, A1, B1);
      double c1 = det(B, C, B1, C1);
      double c2 = det(C, A, C1, A1);
      a.insert(a.begin() + i + 1, point(c1 / z, c2 / z));
      sign.insert(sign.begin() + i + 1, 0);
      n++;
    }
  }
  for (int i = 0; i < (int)(n + 5); i++) {
    for (int j = 0; j < (int)(n + 5); j++) d[i][j] = 1E20;
    d[i][i] = 0;
  }
  for (int i = 0; i < (int)(n); i++)
    for (int j = 0; j < (int)(n); j++)
      if (sign[i] == 0 && sign[j] == 0)
        d[i][j] = d[j][i] = dist(a[i], a[j]) * 2;
  for (int i = 0; i < (int)(n); i++) {
    int j = (i + 1) % n;
    d[i][j] = d[j][i] = dist(a[i], a[j]);
  }
  {
    int id = -1;
    double mind = 1E20;
    for (int i = 0; i < (int)(n); i++)
      if (abs(dist(f, s) - dist(a[i], f) - dist(a[i], s)) < EPS &&
          dist(s, a[i]) < mind) {
        mind = dist(s, a[i]);
        id = i;
      }
    if (id == -1)
      d[n + 1][n + 2] = d[n + 2][n + 1] = dist(s, f);
    else
      d[n + 1][id] = d[id][n + 1] = dist(s, a[id]);
  }
  {
    int id = -1;
    double mind = 1E20;
    for (int i = 0; i < (int)(n); i++)
      if (abs(dist(f, s) - dist(a[i], f) - dist(a[i], s)) < EPS &&
          dist(f, a[i]) < mind) {
        mind = dist(f, a[i]);
        id = i;
      }
    if (id == -1)
      d[n + 1][n + 2] = d[n + 2][n + 1] = dist(s, f);
    else
      d[n + 2][id] = d[id][n + 2] = dist(f, a[id]);
  }
  for (int k = 0; k < (int)(n + 5); k++)
    for (int i = 0; i < (int)(n + 5); i++)
      for (int j = 0; j < (int)(n + 5); j++)
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  cout.precision(15);
  cout << fixed << d[n + 1][n + 2] << endl;
  return 0;
}
