#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double eps = 1e-6;
struct pos {
  double x, y;
};
struct vec {
  double x, y;
};
struct seg {
  pos a, b;
};
long long sign(double x) { return x < -eps ? -1 : x > eps ? 1 : 0; }
double dot(vec a, vec b) { return a.x * b.x + a.y * b.y; }
double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }
vec fwd(pos a, pos b) { return {b.x - a.x, b.y - a.y}; }
void mkang(pos src, pos A, pos B) {}
pos operator+(pos p, vec v) { return {p.x + v.x, p.y + v.y}; }
vec operator*(vec v, double t) { return {v.x * t, v.y * t}; }
bool checkInt(seg a, seg b) {
  return sign(cross(fwd(a.a, a.b), fwd(b.a, b.b))) != 0;
}
void prt(pos p) { cout << "p(" << p.x << "," << p.y << ") "; }
void prt(vec p) { cout << "v(" << p.x << "," << p.y << ") "; }
pos segIntSeg(seg a, seg b) {
  double t =
      cross(fwd(a.a, b.a), fwd(a.a, a.b)) / cross(fwd(a.a, a.b), fwd(b.a, b.b));
  return b.a + fwd(b.a, b.b) * t;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ;
  long long n;
  cin >> n;
  vector<pos> v(n);
  for (long long i = 0; i < n; i++) cin >> v[i].x >> v[i].y;
  seg ln = {v[0], v[1]};
  bool inv = v[0].x > v[1].x;
  double L = !inv ? v[0].x : v[1].x, R = !inv ? v[1].x : v[0].x;
  for (long long i = 2; i < n; i++) {
    for (long long j = 2; j < i; j++) {
      seg ln2 = {v[i], v[j]};
      if (!checkInt(ln, ln2)) {
        if ((v[j].x < v[i].x) ^ inv) R = L - 1;
        continue;
      }
      pos p = segIntSeg(ln, ln2);
      if (sign(dot(fwd(v[i], v[j]), fwd(v[i], p))) < 0) continue;
      if (!inv)
        R = min(R, p.x);
      else
        L = max(L, p.x);
    }
    for (long long j = i + 1; j < n; j++) {
      seg ln2 = {v[i], v[j]};
      if (!checkInt(ln, ln2)) {
        if ((v[j].x > v[i].x) ^ inv) L = R + 1;
        continue;
      }
      pos p = segIntSeg(ln, ln2);
      if (sign(dot(fwd(v[i], v[j]), fwd(v[i], p))) < 0) continue;
      if (!inv)
        L = max(L, p.x);
      else
        R = min(R, p.x);
    }
  }
  long long cnt = floor(R) - ceil(L) + 1;
  cout << max(cnt, 0LL) << '\n';
}
