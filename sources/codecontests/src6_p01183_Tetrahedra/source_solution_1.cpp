#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <climits>
#include <queue>
#include <set>
#include <map>
#include <valarray>
#include <bitset>
#include <stack>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1<<29;
const double PI = acos(-1);
const double EPS = 1e-8;

typedef complex<double> P;
namespace std {
  bool operator < (const P& a, const P& b) {
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
  }
}
double cross(const P& a, const P& b) {
  return imag(conj(a)*b);
}
double dot(const P& a, const P& b) {
  return real(conj(a)*b);
}
struct L : public vector<P> {
  L(const P &a, const P &b) {
    push_back(a); push_back(b);
  }
};
P crosspoint(const L &l, const L &m) {
  double A = cross(l[1] - l[0], m[1] - m[0]);
  double B = cross(l[1] - l[0], l[1] - m[0]);
  if (abs(A) < EPS && abs(B) < EPS) return m[0]; // same line
  if (abs(A) < EPS) assert(false); // !!!PRECONDITION NOT SATISFIED!!!
  return m[0] + B / A * (m[1] - m[0]);
}
P rotate(P p, double ang) {
  return p * P(cos(ang), sin(ang));
}

P calcxh(double a, double b, double c) {
  double A = acos((a*a+c*c-b*b)/(2*a*c));
  return P(a*cos(A), a*sin(A));
}

P normarize(P p) {
  return p/abs(p);
}
bool ng(double a, double b, double c) {
  return !(abs(a-b)<c && c<a+b);
}

double solve(vector<double> v) {
  //REP(i, v.size()) cout << v[i] << " ";cout << endl;
  if (ng(v[0],v[1],v[2]) || ng(v[3],v[4],v[0]) ||
      ng(v[4],v[5],v[2]) || ng(v[5],v[3],v[1])) return 0;

  P p[3];
  p[0] = P(0,0); p[1] = P(v[0],0);
  p[2] = calcxh(v[1],v[2],v[0]);
  double S = cross(p[1]-p[0], p[2]-p[0])/2;
  P xh1 = calcxh(v[3],v[4],v[0]);
  L l1(P(xh1.real(), 0), P(xh1.real(), 1));
  P xh2 = calcxh(v[4],v[5],v[2]);
  P px = p[1]+normarize(p[2]-p[1])*xh2.real();
  P pxd = rotate(p[2]-p[1], PI/2);
  L l2(px, px+pxd);
  P q = crosspoint(l1, l2);
  // cout << xh1 << endl;
  // cout << xh2 << endl;
  // cout << l1[0] << "->" << l1[1] << " " << l2[0] << "->" << l2[1] << endl;
  // cout << "q = " << q<< endl;
  if (v[3]*v[3] < norm(q)) return 0;
  double h = sqrt(v[3]*v[3]-norm(q));
  //cout << S << " " << h << " " << sqrt(v[4]*v[4]-norm(q-p[1])) << endl;
  return S*h/3;
}

int main() {
  // double hoge[6] = {2,3,4,7,6,5};
  //cout << solve(vector<double>(hoge, hoge+6)) << endl;
  // return 0;
  int n;
  while(cin >> n, n) {
    double a[n];
    REP(i, n) {
      cin >> a[i];
    }
    string s = string(n-6, '0') + string(6, '1');
    double ans = 0;
    do {
      double b[6];
      int cnt = 0;
      REP(i,n) if (s[i] == '1') b[cnt++] = a[i];
      string t = "01234";
      do {
        vector<double> v(6);
        REP(i, 5) v[i] = b[t[i]-'0'];
        v[5] = b[5];
        ans = max(ans, solve(v));
      } while(next_permutation(ALL(t)));
    }while(next_permutation(ALL(s)));
    printf("%.10f\n", ans);
  }
}