#include <bits/stdc++.h>
using namespace std;
struct edge {
  int t, f, w;
  bool operator<(const edge& e) const { return w > e.w; }
  edge(int from, int to, int weight) {
    t = to;
    f = from;
    w = weight;
  }
};
const double EPS = (1e-5);
struct line {
  double a, b, c;
};
struct point {
  double x, y;
  point() { x = y = 0.0; }
  point(double _x, double _y) : x(_x), y(_y) {}
  bool operator==(point other) const {
    return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
  }
};
double dist(point p1, point p2) {
  return fabs(p1.x - p2.x) * fabs(p1.x - p2.x) +
         fabs(p1.y - p2.y) * fabs(p1.y - p2.y);
}
void pointsToLine(point p1, point p2, line& l) {
  if (fabs(p1.x - p2.x) < EPS) {
    l.a = 1.0;
    l.b = 0.0;
    l.c = -p1.x;
  } else {
    l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
    l.b = 1.0;
    l.c = -(double)(l.a * p1.x) - p1.y;
  }
}
bool areParallel(line l1, line l2) {
  return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS);
}
bool areSame(line l1, line l2) {
  return areParallel(l1, l2) && (fabs(l1.c - l2.c) < EPS);
}
bool areIntersect(line l1, line l2, point& p) {
  if (areParallel(l1, l2)) return false;
  p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
  if (fabs(l1.b) > EPS)
    p.y = -(l1.a * p.x + l1.c);
  else
    p.y = -(l2.a * p.x + l2.c);
  return true;
}
long long binpowmod(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
int findXOR(int n) {
  switch (n % 4) {
    case 0:
      return n;
    case 1:
      return 1;
    case 2:
      return n + 1;
    case 3:
      return 0;
  }
}
int rangeXOR(int l, int r) { return (findXOR(l - 1) ^ findXOR(r)); }
int getbit(int mask, int bit) { return (mask & (1 << bit)); }
void setbit(int& mask, int bit, int val) {
  if (val)
    mask |= (1 << bit);
  else
    mask &= ~(1 << bit);
}
const int N = 1e5 + 10;
const int M = 2e5 + 10;
const long long INF = 9999999;
int BIT[N];
void update(int x, int val) {
  ++x;
  while (x <= N) {
    BIT[x] += val;
    x += (x & -x);
  }
}
int query(int x) {
  ++x;
  int res = 0;
  while (x > 0) {
    res += BIT[x];
    x -= (x & -x);
  }
  return res;
}
void solve() {
  int n;
  cin >> n;
  cout << setprecision(10) << fixed << 1 / (2 * sin(acos(-1) / 4 / n)) << endl;
}
int main(void) {
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
}
