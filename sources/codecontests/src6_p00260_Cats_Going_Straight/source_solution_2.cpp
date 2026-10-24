#include<iostream>
#include<cfloat>
#include<cassert>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;
#define rep(i, n) for ( int i = 0; i < (int)n; i++ )
#define EPS (1e-8)
#define equals(a, b) (fabs((a) - (b)) < EPS )
#define dle(a, b) (equals(a, b) || a < b )
typedef pair<int, pair<int, int> > Triple;

static const double PI = acos(-1);

class Point{
    public:
    double x, y;
    Point (double x = 0, double y = 0): x(x), y(y){ }
    
    Point operator + ( Point p ){ return Point(x + p.x, y + p.y); }
    Point operator - ( Point p ){ return Point(x - p.x, y - p.y); }
    Point operator * ( double a ){ return Point(x*a, y*a); }
    Point operator / ( double a ){ return Point(x/a, y/a); }

    double abs() { return sqrt(norm());}
    double norm() { return x*x + y*y; }

    bool operator < ( const Point &p ) const {return x != p.x ? x < p.x : y < p.y;}
    bool operator == ( const Point &p ) const {	return fabs(x-p.x) < EPS && fabs(y-p.y) < EPS;}
};

typedef Point Vector;

class Segment{
    public:
    Point p1, p2;
    Segment(Point s = Point(), Point t = Point()): p1(s), p2(t){}
};

class SegmentSet{
    public:
    Point p1, p2;
    vector<Point> in;
    vector<int> v;
    SegmentSet(Point s = Point(), Point t = Point()): p1(s), p2(t){}
    void addIntermediate(Point p){ in.push_back(p); }
    void normalize(){
	in.push_back(p1);
	in.push_back(p2);
	sort(in.begin(), in.end());
	vector<Point>::iterator end_it = unique(in.begin(), in.end());
	in.erase(end_it, in.end());
	v.resize(in.size());
    }
    void reset(){
	for ( int i = 0; i < v.size(); i++ ) v[i] = 0;
    }
    bool valid(){
	for ( int i = 0; i < v.size()-1; i++ ) if ( !v[i]) return false;
	return true;
    }
    void print(){
	for ( int i = 0; i < in.size(); i++ ){
	    cout << in[i].x << "," << in[i].y << endl;
	}
    }
};

typedef Segment Line;
typedef vector<Point> Polygon;

double norm( Vector a ){ return a.x*a.x + a.y*a.y; }
double abs( Vector a ){ return sqrt(norm(a)); }
Point polar( double a, double r ){ return Point(cos(r)*a, sin(r)*a);}
double getDistance( Vector a, Vector b ){ return abs(a - b); }
double dot( Vector a, Vector b ){ return a.x*b.x + a.y*b.y; }
double cross( Vector a, Vector b ){ return a.x*b.y - a.y*b.x; }
double arg(Vector p){ return atan2(p.y, p.x); }

static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;

int ccw( Point p0, Point p1, Point p2 ){
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if ( cross(a, b) > EPS ) return COUNTER_CLOCKWISE;
    if ( cross(a, b) < -EPS ) return CLOCKWISE;
    if ( dot(a, b) < -EPS ) return ONLINE_BACK;
    if ( norm(a) < norm(b) ) return ONLINE_FRONT;
    return ON_SEGMENT;
}
bool isIntersect(Point p1, Point p2, Point p3, Point p4){
    return ( ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
	     ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0 );
}

bool isIntersect(Segment s1, Segment s2){
    return isIntersect(s1.p1, s1.p2, s2.p1, s2.p2);
}

bool isParallel( Vector a, Vector b ){
    return equals( cross(a, b), 0.0 );
}

bool isParallel( Point a1, Point a2, Point b1, Point b2){
    return isParallel( a1 - a2, b1 - b2 );
}

bool isParallel( Segment s1, Segment s2){
  return isParallel( s1.p1, s1.p2, s2.p1, s2.p2);
}

Point getCrossPoint(Segment s1, Segment s2){
    assert( isIntersect(s1, s2) );
    Vector base = s2.p2 - s2.p1;
    double d1 = abs(cross(base, s1.p1 - s2.p1));
    double d2 = abs(cross(base, s1.p2 - s2.p1));
    double t = d1/(d1 + d2);
    return s1.p1 + (s1.p2 - s1.p1)*t;
}

Point getCrossPointLines( Line s1, Line s2){
    Vector a = s1.p2 - s1.p1;
    Vector base = s2.p2 - s2.p1;
    return s1.p1 + a * cross(base, s2.p1 - s1.p1)/cross(base, a);
}
// angle p1 -> p0 -> p2;
double getAngle(Point p0, Point p1, Point p2){
  if ( !(ccw(p0, p1, p2) == CLOCKWISE || ccw(p0, p1, p2) == COUNTER_CLOCKWISE )) return 0;
  double b = abs(p1 - p0);
  double c = abs(p2 - p0);
  double a = abs(p1 - p2);
  double r = acos((b*b+c*c-a*a)/(2*b*c));
  if ( ccw(p0, p1, p2) == CLOCKWISE ) r *= -1;
  return r;
}

bool insidePolygon(Polygon g, Point t){
  double angle = 0.0;
  rep(i, g.size()){
    Point p1 = g[i];
    Point p2 = g[(i+1)%g.size()];
    if ( ccw(p1, p2, t) == ON_SEGMENT ) return true;
    angle += getAngle(t, p1, p2);
  }
  return equals(2*acos(-1), fabs(angle) );
}

bool insidePolygonSegment(Polygon g, Segment s){
  if ( !insidePolygon(g, s.p1) || !insidePolygon(g, s.p2) ) return false;
  vector<Point> pointInSeg;
  pointInSeg.push_back(s.p1);
  pointInSeg.push_back(s.p2);
  for ( int i = 0; i < g.size(); i++ ){
    Segment ps = Segment(g[i], g[(i+1)%g.size()]);
    if ( isParallel(ps, s) ) continue;
    if ( !isIntersect(ps, s) ) continue;
    Point x = getCrossPoint(ps, s);
    if ( !(x == s.p1 || x == s.p2 || x == ps.p1 || x == ps.p2 ) ) return false;
    pointInSeg.push_back(x);
  }
  sort(pointInSeg.begin(), pointInSeg.end());
  for ( int i = 0; i < pointInSeg.size()-1; i++ ){
    Point s = pointInSeg[i];
    Point t = pointInSeg[i+1];
    Point c = Point((s.x+t.x)/2, (s.y+t.y)/2);
    if ( !insidePolygon(g, c) ) return false;
  }
  return true;
}

bool isPolygonIntersect(Polygon g1, Polygon g2){
    rep(i, g1.size()) rep(j, g2.size()) {
	if ( isIntersect(g1[i], g1[(i+1)%g1.size()],
			 g2[j], g2[(j+1)%g2.size()])) return true;
    }
    rep(i, g1.size())  if ( insidePolygon(g2, g1[i]) ) return true;
    rep(i, g2.size())  if ( insidePolygon(g1, g2[i]) ) return true;
    return false;
}
bool isOnline(Point p1, Point p2, Point p3, Point p4){
    int c1 = ccw(p1, p2, p3);
    int c2 = ccw(p1, p2, p4);
    if ( c1 < 0 ) c1 *= -1;
    if ( c2 < 0 ) c2 *= -1;
    return c1 != 1 && c2 != 1;
}
bool included(Point p1, Point p2, Point p3, Point p4){
    return ccw(p3, p4, p1) == ON_SEGMENT && ccw(p3, p4, p2) == ON_SEGMENT;
}
// p1-p2 is the base
bool isInsideTriangle(Point p1, Point p2, Point p3, Polygon &g){
    assert( !(p1==p2));
    if ( !insidePolygonSegment(g, Segment(p1, p2)) ) return false;
    if ( !insidePolygonSegment(g, Segment(p1, p3)) ) return false;
    if ( !insidePolygonSegment(g, Segment(p2, p3)) ) return false;
    return true;
}

bool segmentVisible(Point p1, Point p2, bool used[], Polygon &g){
    for ( int i = 0; i < g.size(); i++ ){
	if ( !used[i] ) continue;
	if ( isInsideTriangle(p1, p2, g[i], g) ) return true;
    }
    return false;
}

bool visible(bool used[], vector<SegmentSet> &S, Polygon &g, vector<vector<pair<int, int> > > &C){
    for ( int i = 0; i < S.size(); i++ ) S[i].reset();
    for ( int i = 0; i < g.size(); i++ ){
	if ( !used[i] ) continue;
	for ( int k = 0; k < C[i].size(); k++ ){
	    pair<int, int> p = C[i][k];
	    S[p.first].v[p.second] = 1;
	}
    }
    for ( int i = 0; i < S.size(); i++ ) if ( !S[i].valid() ) return false;
    return true;
}

void rec(int pos, int cnt, vector<SegmentSet> &S, bool used[], int &minv, Polygon &g, vector<vector<pair<int, int> > > &C){
    if ( cnt > minv ) return;
    if ( pos == g.size() ){
	if ( visible(used, S, g, C) ) minv = min(minv, cnt);
	return;
    }
    rec(pos+1, cnt, S, used, minv, g, C);
    used[pos] = true;
    rec(pos+1, cnt+1, S, used, minv, g, C);
    used[pos] = false;
}

void compute(Polygon g){
    vector<SegmentSet> S;
    rep(i, g.size()) S.push_back(SegmentSet(g[i], g[(i+1)%g.size()]));
    for ( int i = 0; i < g.size()-1; i++ ){
	for ( int j = i+1; j < g.size(); j++ ){
	    if ( g[i] == g[j] ) continue;
	    Line base = Line(g[i], g[j]);
	    for ( int k = 0; k < S.size(); k++ ){
		if ( isParallel(base.p1, base.p2, S[k].p1, S[k].p2) ) continue;
		Point x = getCrossPointLines(Line(base.p1, base.p2), Line(S[k].p1, S[k].p2));
		if ( ccw(S[k].p1, S[k].p2, x) == ON_SEGMENT) S[k].addIntermediate(x);
	    }
	}
    }
    for ( int i = 0; i < S.size(); i++ ) S[i].normalize();

    vector<vector<pair<int, int> > > C;
    C.resize(g.size());

    for ( int i = 0; i < S.size(); i++ ){
	for ( int j = 0; j < S[i].in.size()-1; j++ ){
	    for ( int k = 0; k < g.size(); k++ ){
		Point p1 = S[i].in[j];
		Point p2 = S[i].in[j+1];
		if ( isInsideTriangle(p1, p2, g[k], g) ) {
		    C[k].push_back(make_pair(i, j));
		}
	    }
	}
    }

    bool used[20];
    int minv = g.size();
    rep(i, S.size()) used[i] = false;
    rec(0, 0, S, used, minv, g, C);
    cout << minv << endl;
}

int main(){
  int x, y;
  int n;
  int tcase = 0;
  while(1){
    cin >> n;
    if ( n == 0 ) break;  
    Polygon g;
    rep(i, n){
      cin >> x >> y;
      g.push_back(Point(x, y));
    }
    compute(g);
  }
}