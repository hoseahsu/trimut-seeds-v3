#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <numeric>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <functional>
using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef vector<long long> vll;
typedef pair<int,int> pint;
typedef pair<long long, long long> pll;

#define MP make_pair
#define PB push_back
#define ALL(s) (s).begin(),(s).end()
#define EACH(i, s) for (__typeof__((s).begin()) i = (s).begin(); i != (s).end(); ++i)
#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T1, class T2> ostream& operator << (ostream &s, pair<T1,T2> P) 
{ return s << '<' << P.first << ", " << P.second << '>'; }
template<class T> ostream& operator << (ostream &s, vector<T> P) 
{ for (int i = 0; i < P.size(); ++i) { if (i > 0) { s << " "; } s << P[i]; } return s; }
template<class T> ostream& operator << (ostream &s, vector<vector<T> > P) 
{ for (int i = 0; i < P.size(); ++i) { s << endl << P[i]; } return s << endl; }
template<class T1, class T2> ostream& operator << (ostream &s, map<T1,T2> P) 
{ EACH(it, P) { s << "<" << it->first << "->" << it->second << "> "; } return s; }



typedef double DD;

const DD INF = 1LL<<60;
const DD EPS = 1e-10;
const DD PI = acos(-1.0);
DD torad(int deg) {return (DD)(deg) * PI / 180;}
DD todeg(DD ang) {return ang * 180 / PI;}

struct Point {
    DD x, y;
    Point(DD x = 0.0, DD y = 0.0) : x(x), y(y) {}
    friend ostream& operator << (ostream &s, const Point &p) {return s << '(' << p.x << ", " << p.y << ')';}
};

Point operator + (const Point &p, const Point &q) {return Point(p.x + q.x, p.y + q.y);}
Point operator - (const Point &p, const Point &q) {return Point(p.x - q.x, p.y - q.y);}
Point operator * (const Point &p, DD a) {return Point(p.x * a, p.y * a);}
Point operator * (DD a, const Point &p) {return Point(a * p.x, a * p.y);}
Point operator * (const Point &p, const Point &q) {return Point(p.x * q.x - p.y * q.y, p.x * q.y + p.y * q.x);}
Point operator / (const Point &p, DD a) {return Point(p.x / a, p.y / a);}
Point conj(const Point &p) {return Point(p.x, -p.y);}
Point rot(const Point &p, DD ang) {return Point(cos(ang) * p.x - sin(ang) * p.y, sin(ang) * p.x + cos(ang) * p.y);}
Point rot90(const Point &p) {return Point(-p.y, p.x);}
DD cross(const Point &p, const Point &q) {return p.x * q.y - p.y * q.x;}
DD dot(const Point &p, const Point &q) {return p.x * q.x + p.y * q.y;}
DD norm(const Point &p) {return dot(p, p);}
DD abs(const Point &p) {return sqrt(dot(p, p));}
DD amp(const Point &p) {DD res = atan2(p.y, p.x); if (res < 0) res += PI*2; return res;}
bool eq(const Point &p, const Point &q) {return abs(p - q) < EPS;}
bool operator < (const Point &p, const Point &q) {return (abs(p.x - q.x) > EPS ? p.x < q.x : p.y < q.y);}
bool operator > (const Point &p, const Point &q) {return (abs(p.x - q.x) > EPS ? p.x > q.x : p.y > q.y);}
Point operator / (const Point &p, const Point &q) {return p * conj(q) / norm(q);}

int ccw(const Point &a, const Point &b, const Point &c) {
    if (cross(b-a, c-a) > EPS) return 1;
    if (cross(b-a, c-a) < -EPS) return -1;
    if (dot(b-a, c-a) < -EPS) return 2;
    if (norm(b-a) < norm(c-a) - EPS) return -2;
    return 0;
}

struct Line : vector<Point> {
    Line(Point a = Point(0.0, 0.0), Point b = Point(0.0, 0.0)) {
        this->push_back(a);
        this->push_back(b);
    }
    friend ostream& operator << (ostream &s, const Line &l) {return s << '{' << l[0] << ", " << l[1] << '}';}
};

struct Circle : Point {
    DD r;
    Circle(Point p = Point(0.0, 0.0), DD r = 0.0) : Point(p), r(r) {}
    friend ostream& operator << (ostream &s, const Circle &c) {return s << '(' << c.x << ", " << c.y << ", " << c.r << ')';}
};

Point proj(Point p, Line l) {
    DD t = dot(p - l[0], l[1] - l[0]) / norm(l[1] - l[0]);
    return l[0] + (l[1] - l[0]) * t;
}
vector<Point> crosspoint(Line l, Line m) {
    vector<Point> res;
    DD d = cross(m[1] - m[0], l[1] - l[0]);
    if (abs(d) < EPS) return vector<Point>();
    res.push_back(l[0] + (l[1] - l[0]) * cross(m[1] - m[0], m[1] - l[0]) / d);
    return res;
}
vector<Point> crosspoint(Circle e, Circle f) {
    vector<Point> res;
    DD d = abs(e - f);
    if (d < EPS) return vector<Point>();
    if (d > e.r + f.r + EPS) return vector<Point>();
    if (d < abs(e.r - f.r) - EPS) return vector<Point>();
    DD rcos = (d * d + e.r * e.r - f.r * f.r) / (2.0 * d), rsin;
    if (e.r - abs(rcos) < EPS) rsin = 0;
    else rsin = sqrt(e.r * e.r - rcos * rcos);
    Point dir = (f - e) / d;
    Point p1 = e + dir * Point(rcos, rsin);
    Point p2 = e + dir * Point(rcos, -rsin);
    res.push_back(p1);
    if (!eq(p1, p2)) res.push_back(p2);
    return res;
}
vector<Point> crosspoint(Circle e, Line l) {
    vector<Point> res;
    Point p = proj(e, l);
    DD rcos = abs(e - p), rsin;
    if (rcos > e.r + EPS) return vector<Point>();
    else if (e.r - rcos < EPS) rsin = 0;
    else rsin = sqrt(e.r * e.r - rcos * rcos);
    Point dir = (l[1] - l[0]) / abs(l[1] - l[0]);
    Point p1 = p + dir * rsin;
    Point p2 = p - dir * rsin;
    res.push_back(p1);
    if (!eq(p1, p2)) res.push_back(p2);
    return res;
}




struct Point3D {
    DD x, y, z;
    Point3D(DD x = 0.0, DD y = 0.0, DD z = 0.0) : x(x), y(y), z(z) {}
    friend ostream& operator << (ostream &s, const Point3D &p) {return s << '(' << p.x << ", " << p.y << ", " << p.z << ')';}
};

Point3D operator + (const Point3D &p, const Point3D &q) {return Point3D(p.x + q.x, p.y + q.y, p.z + q.z);}
Point3D operator - (const Point3D &p, const Point3D &q) {return Point3D(p.x - q.x, p.y - q.y, p.z - q.z);}
Point3D operator * (const Point3D &p, DD a) {return Point3D(p.x * a, p.y * a, p.z * a);}
Point3D operator * (DD a, const Point3D &p) {return Point3D(a * p.x, a * p.y, a * p.z);}
Point3D operator * (const Point3D &p, const Point3D &q) {
    return Point3D(p.y * q.z - p.z * q.y, p.z * q.x - p.x * q.z, p.x * q.y - p.y * q.x);
}
Point3D operator / (const Point3D &p, DD a) {return Point3D(p.x / a, p.y / a), p.z / a;}
DD dot(const Point3D &p, const Point3D &q) {return p.x * q.x + p.y * q.y + p.z * q.z;}
DD norm(const Point3D &p) {return dot(p, p);}
DD abs(const Point3D &p) {return sqrt(dot(p, p));}
bool eq(const Point3D &p, const Point3D &q) {return abs(p - q) < EPS;}

struct Line3D : vector<Point3D> {
    Line3D(Point3D a = Point3D(0.0, 0.0, 0.0), Point3D b = Point3D(0.0, 0.0, 0.0)) {
        this->push_back(a);
        this->push_back(b);
    }
    friend ostream& operator << (ostream &s, const Line3D &l) {return s << '{' << l[0] << ", " << l[1] << '}';}
};

struct Circle3D : Point3D {
    DD r;
    Circle3D(Point3D p = Point3D(0.0, 0.0), DD r = 0.0) : Point3D(p), r(r) {}
    friend ostream& operator << (ostream &s, const Circle3D &c) {return s << '(' << c.x << ", " << c.y << ", " << c.r << ')';}
};



Point3D proj(Point3D p, Line3D l) {
    DD t = dot(p - l[0], l[1] - l[0]) / norm(l[1] - l[0]);
    return l[0] + (l[1] - l[0]) * t;
}
Point3D proj(Point3D v, Point3D d) {
    DD t = dot(v, d) / norm(d);
    return v * t;
}
Point3D refl(Point3D p, Line3D l) {
    return p + (proj(p, l) - p) * 2;
}
bool isinterPL(Point3D p, Line3D l) {
    return (abs(p - proj(p, l)) < EPS);
}
DD distancePL(Point3D p, Line3D l) {
    return abs(p - proj(p, l));
}
DD distanceLL(Line3D l, Line3D m) {
    Point3D nv = (l[1] - l[0]) * (m[1] - m[0]);
    if (abs(nv) < EPS) return distancePL(l[0], m);
    Point3D p = m[0] - l[0];
    return abs(dot(nv, p)) / abs(nv);
}



Point3D X, Y, P;
DD r;

int main() {
    //freopen( "/Users/macuser/Dropbox/Contest/input.in", "r", stdin );
    
    while (cin >> X.x >> X.y >> X.z >> Y.x >> Y.y >> Y.z >> r >> P.x >> P.y >> P.z) {
        Line3D l(X, Y);
        Point3D PH = proj(P, l);
        
        Point x(0, abs(X - Y));
        Point y(0, 0);
        Point p(abs(P-PH), abs(PH-Y));
        Point a(r, 0);
        Point b(-r, 0);
        
        vector<Point> vc = crosspoint(Line(p, a), Line(x, b));
        Point c = vc[0];
        
        vector<Point> vd = crosspoint(Line(p, b), Line(x, a));
        Point d = vd[0];
        
        Point m = (c + d)/2;
        Point h = proj(x, Line(c, d));
        
        DD tsr = r * abs(x.y - m.y) / abs(x - y);
        DD sr = sqrt(tsr * tsr - m.x * m.x);
        
        DD tot = PI * r * r * abs(x-y) / 3;
        DD sol = PI * abs(c - d) * sr * abs(x - h) / 6;
        
//        COUT(X);
//        COUT(Y);
//        COUT(P);
//        COUT(PH);
//        COUT(x);
//        COUT(y);
//        COUT(p);
//        COUT(a);
//        COUT(b);
//        COUT(c);
//        COUT(d);
//        COUT(m);
//        COUT(h);
//        COUT(sr);
//        COUT(tot);
//        COUT(sol);
        
        cout << fixed << setprecision(9) << sol << " " << tot-sol << endl;
    }
    return 0;
}
