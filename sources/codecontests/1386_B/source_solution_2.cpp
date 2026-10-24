#include <bits/stdc++.h>
using namespace std;
const int N = 100011;
const int mod = 1e9 + 7;
double pi = acos((double)-1.);
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
struct P {
  long long x, y, z;
  void scan() { cin >> x >> y >> z; }
  void print() const { cerr << x << ' ' << y << ' ' << z << endl; }
  P operator+(const P& b) const { return P{x + b.x, y + b.y, z + b.z}; }
  P operator-(const P& b) const { return P{x - b.x, y - b.y, z - b.z}; }
  P operator*(const P& b) const {
    return P{y * b.z - z * b.y, z * b.x - x * b.z, x * b.y - y * b.x};
  }
  long long operator%(const P& b) const {
    return (long long)x * b.x + (long long)y * b.y + (long long)z * b.z;
  }
  long long sqrlen() const { return x * x + y * y + z * z; }
  double len() const {
    return sqrt((double)x * x + (double)y * y + (double)z * z);
  }
  bool operator<(const P& b) const {
    return x < b.x || x == b.x && y < b.y || x == b.x && y == b.y && z < b.z;
  }
  int sgn() const {
    return *this < P{0, 0, 0} ? -1 : P{0, 0, 0} < *this ? 1 : 0;
  }
  void normalize() {
    long long d = gcd(abs(x), abs(y));
    d = gcd(d, abs(z));
    x /= d;
    y /= d;
    z /= d;
  }
  bool operator==(const P& b) const { return x == b.x && y == b.y && z == b.z; }
  bool operator!=(const P& b) const { return x != b.x || y != b.y || z != b.z; }
};
P n0, n1;
P p;
int calc(const P& x, const P& y) { return x * y % p <= 0; }
P operator*(const long long& a, const P& b) {
  return P{a * b.x, a * b.y, a * b.z};
}
struct Cmp {
  bool operator()(const P& x, const P& y) const {
    long long d1 = x % n0 < 0 || x % n0 == 0 && x % n1 < 0;
    long long d2 = y % n0 < 0 || y % n0 == 0 && y % n1 < 0;
    if (d1 == d2) {
      return (x * y % p) > 0;
    } else
      return d1 < d2;
  }
};
int main() {
  int n;
  p.scan();
  scanf("%d", &n);
  p.normalize();
  n0 = p * P{0, 1, -1};
  n1 = p * n0;
  set<P, Cmp> cvx;
  int flag = 1;
  map<P, int> points, norms;
  map<int, P> ref;
  map<P, P> rep;
  int na = 0;
  int np = 0;
  for (int i = 0; i < n; i++) {
    string tp;
    cin >> tp;
    P x;
    if (tp == "A") {
      x.scan();
      x.normalize();
    } else {
      int y;
      cin >> y;
      x = ref[y];
    }
    if (tp == "A") {
      na++;
      ref[na] = x;
      points[x]++;
      if (x != p) {
        P norm = p * x;
        norm.normalize();
        if (rep.count(norm) == 0) {
          rep[norm] = x;
        }
        norms[norm]++;
        P mn = -1 * norm;
        np += norms[mn];
        if (norms[norm] == 1) {
          x = rep[norm];
          if (cvx.empty()) {
            flag = 1;
          } else {
            auto itr = cvx.lower_bound(x);
            if (itr == cvx.end()) itr = cvx.begin();
            auto itl = itr;
            if (itr == cvx.begin()) {
              itl = cvx.end();
              itl--;
            } else
              itl--;
            flag -= calc(*itl, *itr);
            flag += calc(*itl, x);
            flag += calc(x, *itr);
          }
          cvx.insert(x);
        }
      }
    } else {
      points[x]--;
      if (points[x] == 0) points.erase(x);
      if (x != p) {
        P norm = p * x;
        norm.normalize();
        norms[norm]--;
        P mn = -1 * norm;
        np -= norms[mn];
        if (norms[norm] == 0) {
          x = rep[norm];
          if (cvx.size() == 1) {
            flag = 1;
          } else {
            auto itr = cvx.upper_bound(x);
            if (itr == cvx.end()) itr = cvx.begin();
            auto itl = cvx.find(x);
            if (itl == cvx.begin()) {
              itl = cvx.end();
              itl--;
            } else
              itl--;
            flag += calc(*itl, *itr);
            flag -= calc(*itl, x);
            flag -= calc(x, *itr);
          }
          cvx.erase(x);
        }
      }
    }
    printf("%d\n", points.count(p) ? 1 : np >= 1 ? 2 : flag == 0 ? 3 : 0);
  }
}
