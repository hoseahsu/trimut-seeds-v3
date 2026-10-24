#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <string.h>
#include <cmath>
#include <complex>
using namespace std;

#define ISEQ(c) (c).begin(), (c).end()
typedef long long ll;
typedef long double D;
const D EPS = 1e-8, INF =1e12;

template<typename T> int sig(T a, T b=0) {return a < b - EPS ? -1 : a > b + EPS ? 1:0;}
template<typename T> bool eq(T a, T b) {return sig(abs(a-b)) == 0;}
template<typename T> D norm(T a) {return a*a;}

typedef complex<D> P;
#define X real()
#define Y imag()

int IINF = 1 << 28;
struct C {
  P o; D r;
  C(const P &o, D r) : o(o), r(r) { }
};

enum RELATION {INCOMPARABLE=0, SAME=1, CONTAIN=2, OVER=4};
pair<RELATION, int> cRel(const C& c1, const C& c2) {
  D d =abs(c1.o-c2.o), rd=c1.r-c2.r;
  if(eq(c1.o,c2.o) and eq(c1.r, c2.r)) return make_pair(SAME, IINF);
  if(sig(d,rd)<0) return make_pair(OVER,0);
  if(sig(d,rd)==0) return make_pair(OVER,1);
  if(sig(d,-rd)<0) return make_pair(CONTAIN, 0);
  if(sig(d,-rd) == 0) return make_pair(CONTAIN, 1);
  if(sig(d,c1.r+c2.r)<0) return make_pair(INCOMPARABLE,2);
  if(sig(d,c1.r+c2.r)==0) return make_pair(INCOMPARABLE,1);
  return make_pair(INCOMPARABLE, 0);
}

D cc_area(const C& c1, const C& c2) {
  pair<RELATION, int> rel =cRel(c1, c2);
  D d = abs(c1.o-c2.o);
  if(rel.first != INCOMPARABLE) {
    D r = min(c1.r, c2.r);   
    return r*r*M_PI;
  }
  if(rel.second <= 1) {
    return 0.0;
  }
  D rlcosA = (d*d+c1.r*c1.r-c2.r*c2.r)/(2*d);
  D A = acos(rlcosA/c1.r), B = acos((d-rlcosA)/c2.r);
  return c1.r*c1.r*A + c2.r*c2.r*B - d*c1.r*sin(A);
}


int main() {
  double w, h, a, b, ab;
  while (true) {
    cin >> w >> h >> a >> b >> ab;
    if (w == 0) break;
    bool changed = false;
    if (a + EPS < b) {
      swap(a, b);
      changed = true;
    }
    double ra = sqrt(a/M_PI), rb = sqrt(b/M_PI);
    if (w + EPS < 2*ra or h + EPS < 2*ra) {
      cout << "impossible" << endl;
      continue;
    }
    if (abs(b-ab) < EPS) {
      //      cout << EPS << endl;
      if (changed)
	printf("%.10f %.10f %.10f %.10f %.10f %.10f\n", ra, ra, rb, ra, ra, ra);
      else
	printf("%.10f %.10f %.10f %.10f %.10f %.10f\n", ra, ra, ra, ra, ra, rb);
      continue;
    }
    double lb = 0.0, ub = ra+rb+EPS;
    C ca(P(0,0), ra);
    while (ub - lb > EPS) {
      double mid = (ub + lb) / 2;
      D area = cc_area(ca, C(P(mid, 0), rb));
      if (area < ab) {
	ub = mid;
      } else {
	lb = mid;
      }
      //      cout << lb << " " << ub << " " << cc_area(ca, C(P(mid, 0), rb)) << endl;
    }
    //    cout << lb << endl;
    //    cout << ab << " " << cc_area(ca, C(P(lb,0), rb)) << endl;
    double xb = w-rb, yb = h - rb;
    double x = ra - xb, y = ra -yb;
    double dis = sqrt(x*x + y*y);
    if (dis + EPS < lb) {
      cout << "impossible" << endl;
      continue;
    } 
    w -= (ra + rb);
    h -= (ra + rb);
    double ss = sqrt(w*w+h*h);
    double sin = h / ss, cos = w / ss;
    //if (ra + rb + cos*lb < w + EPS and ra + rb + sin*lb < h + EPS) {
    //    cout << cc_area(C(P(ra, ra), ra), C(P(ra+cos*lb, ra+sin*lb), rb)) << endl;
    if (changed)
      printf("%.10f %.10f %.10f %.10f %.10f %.10f\n", ra+cos*lb, ra+sin*lb, rb, ra, ra, ra);
    else
      printf("%.10f %.10f %.10f %.10f %.10f %.10f\n", ra, ra, ra, ra+cos*lb, ra+sin*lb, rb);
      //    } else {
      //      cout << "impossible" << endl;
      //    }
  }
}