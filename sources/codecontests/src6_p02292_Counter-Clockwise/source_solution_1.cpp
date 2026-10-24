#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i, n) REP(i, 0, n)
#define REP(i, s, e) for(int i = (int)s; i < (int)(e); ++i)

#define X real()
#define Y imag()
#define x(p) real(p)
#define y(p) imag(p)
#define curr(P, i) P[i]
#define next(P, i) P[(i+1)%P.size()]
#define prev(P, i) P[(i-1+P.size())%P.size()]

const double EPS = 1e-8;
const double INF = 1e12;
const double PI = acos(-1);

typedef double D;
typedef complex<D> P;
namespace std{
  bool operator < (const P& a, const P& b) {
    return x(a) != x(b) ? x(a) < x(b) : y(a) < y(b);
  }
}

D dot(const P& a, const P& b) {
  return x(conj(a)*b);
}
D cross(const P& a, const P& b) {
  return y(conj(a)*b);
}

struct L : public vector<P> {
  L(const P&a, const P& b) {
    push_back(a);
    push_back(b);
  }
};

typedef vector<P> G;

struct C {
  P p; D r;
};

int ccw(P a, P b, P c) {
  b -= a; c -= a;
  if(cross(b, c) > 0) return +1; //ccw
  if(cross(b, c) < 0) return -1; //cw
  if(dot(b, c) < 0)   return +2; //c-a-b on line
  if(norm(b) < norm(c)) return -2; //a-b-c on line
  return 0;
}

P projection(const L& l, const P& p) {
  D t = dot(p - l[0], l[0] - l[1]) / norm(l[0]- l[1]);
  return l[0] + t * (l[0] - l[1]);
}
P refrection(const L& l, const P& p) {
  return p + 2.0 * (projection(l, p) - p);
}
int main() {
  D x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  P a(x1, y1), b(x2, y2);
  int q;
  cin >> q;
  cout << fixed << setprecision(20);
  rep(i, q) {
    D x, y;
    cin >> x >> y;
    P c(x, y);
    int k = ccw(a, b, c);
    if(k == 1) cout << "COUNTER_CLOCKWISE" << endl;
    else if(k == -1) cout << "CLOCKWISE" << endl;
    else if(k == +2) cout << "ONLINE_BACK" << endl;
    else if(k == -2) cout << "ONLINE_FRONT" << endl;
    else cout << "ON_SEGMENT" << endl;
  }
  return 0;
}