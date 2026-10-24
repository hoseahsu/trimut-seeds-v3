#include<bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)
template<class T> T at(vector<T> v, int i) {return v[i % v.size()];}

#define X real()
#define Y imag()

typedef long double D;
typedef complex<D> P;
struct L{P a, b;};
typedef vector<P> Pol;

const D EPS = 1e-8;
const D PI = acos(-1);

int sig(D a, D b = 0) {return a < b - EPS ? -1 : a > b + EPS ? 1 : 0;}
bool near(P a, P b) {return !sig(norm(a - b));}
namespace std {
  bool operator<(P a, P b) {return sig(a.X, b.X) ? a.X < b.X : a.Y < b.Y;}
}

D sr(D a) {return sqrt(max(a, (D)0));}

D dot(P a, P b) {return a.X * b.X + a.Y * b.Y;}
D det(P a, P b) {return a.X * b.Y - a.Y * b.X;}
P vec(L a) {return a.b - a.a;}

D arg(P base, P a, P b) {return arg((b - base) / (a - base));}

P proj(P a, P b) {return a * dot(a, b) / norm(a);}
P perp(L l, P p) {return l.a + proj(vec(l), p - l.a);}

struct C{P c; D r;};

pair<P, P> pCL(C c, L l) {
  P x = perp(l, c.c);
  P y = vec(l) / abs(vec(l)) * sr(c.r * c.r - norm(x - c.c));
  return make_pair(x - y, x + y);
}

D aCTnc(D r, P p1, P p2) {return sig(abs((p1 + p2) / (D)2), r) <= 0 ? det(p1, p2) / 2 : r * r * arg(0, p1, p2) / 2;}
D aCT(D r, P p1, P p2) {
  if (!sig(r) || near(0, p1) || near(0, p2) || near(p1, p2)) return 0;
  pair<P, P> pp = pCL((C){0, r}, (L){p1, p2});
  if ((p1 < pp.first) != (pp.first < p2) && (p1 < pp.second) != (pp.second < p2)) return aCTnc(r, p1, p2);
  return aCTnc(r, p1, pp.first) + aCTnc(r, pp.first, pp.second) + aCTnc(r, pp.second, p2);
}
D aCPol(C c, Pol pol) {D res = 0; rep (i, pol.size()) res += aCT(c.r, pol[i] - c.c, at(pol, i + 1) - c.c); return res;}

int main() {
    D w, h, s;
    while (true) {
        cin >> w >> h >> s;
        if (w == 0) break;
        D l = 0, u = (w + h);
        Pol pol;
        pol.push_back((P){w / 2, h / 2});
        pol.push_back((P){w, h / 2});
        pol.push_back((P){w, h});
        pol.push_back((P){w / 2, h});
        rep (i, 100) {
            D m = (l + u) / 2;
            if (aCPol((C){0, m}, pol) * 4 < s) l = m;
            else u = m;
        }
        printf("%.12Lf\n", l * l * 4);
    }
}