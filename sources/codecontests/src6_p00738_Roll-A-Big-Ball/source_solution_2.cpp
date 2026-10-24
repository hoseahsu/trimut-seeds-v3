#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int,int> pint;
typedef vector<pint> vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=n-1;i>=(0);i--)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define all(v) (v).begin(),(v).end()
#define eall(v) unique(all(v), v.end())
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chmax(a, b) a = max(a, b);
#define chmin(a, b) a = min(a, b);
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll INFF = 1e18;


const double EPS = 1e-10;
template<class T> bool eq(T a, T b){ return abs(a - b) < EPS; }

class Point {
public:
	double x, y;
	Point(double x = 0, double y = 0):x(x), y(y){}
	Point operator + (Point p) { return Point(x + p.x, y + p.y); }
	Point operator - (Point p) { return Point(x - p.x, y - p.y); }
	Point operator * (double a) { return Point(a * x, a * y); }
	Point operator / (double a) { return Point(x / a, y / a); }
	double abs() const { return sqrt(norm()); }
	double norm() const { return x * x + y * y; }
	bool operator < (const Point &p) const { return x != p.x ? p.x : y < p.y; }
	bool operator == (const Point &p) const { return (eq<double>(x, p.x) && eq<double>(y, p.y)); }
};
using Vector = Point;

double dot(const Vector& a, const Vector& b) { return a.x * b.x + a.y * b.y; } // ????????????a??¨b?????????
double cross(const Vector& a, const Vector& b) { return a.x * b.y - a.y * b.x; } // ????????????a??¨b?????????
double length2(const Point& a) { return a.norm(); } // ??????????????????2???
// double length(const Point& a) { return a.abs(); } // ???????????????
double length(Point a) {
	return sqrt(a.x * a.x + a.y * a.y);
}

enum ccw_t {
	COUNTER_CLOCKWISE = 1, // p0->p1 ???????¨???????????????????p2
	CLOCKWISE = -1, // p0->p1 ????¨???????????????????p2
	ONLINE_BACK = 2, // p2->p0->p1 ????????§??´????????§p2
	ONLINE_FRONT = -2, // p0->p1->p2 ????????§??´??????p2
	ON_SEGMENT = 0, // p0->p2->p1 ????????§??????p0p1??????p2
};
ccw_t ccw(Point p0, Point p1, Point p2) {
	Vector a = p1 - p0, b = p2 - p0;
	if ( cross(a, b) > EPS  )  return COUNTER_CLOCKWISE;
	if ( cross(a, b) < -EPS )  return CLOCKWISE;
	if ( dot(a, b) < -EPS )    return ONLINE_BACK;
	if ( a.norm() < b.norm() ) return ONLINE_FRONT;
	return ON_SEGMENT;
}

class Segment {
public:
	Point p1, p2;
	Segment(){}
	Segment(Point p1, Point p2):p1(p1), p2(p2){}
};
using Line = Segment;

// *** ????????????????????? ***
bool intersect(const Point& p1, const Point& p2, const Point& p3, const Point& p4) {
	return ( ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 && 
			 ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0 );
}
bool intersect(const Segment& s1, const Segment& s2) { 
	return intersect(s1.p1, s1.p2, s2.p1, s2.p2);
}
// *** ?????¢ ***
double getDistance(Point& a, Point& b) { // ???a??¨???b????????¢
	return length(a - b);
}
double getDistanceLP(Line& l, Point& p) { // ??´???s??¨???p????????¢
	return length(cross(l.p2 - l.p1, p - l.p1) / length(l.p2 - l.p1));
}
double getDistanceSP(Segment s, Point p) { // ??????s??¨???p????????¢
	if( dot(s.p2 - s.p1, p - s.p1) < EPS ) return length(p - s.p1);
	if( dot(s.p1 - s.p2, p - s.p2) < EPS ) return length(p - s.p2);
	return getDistanceLP(s, p);
}
double getDistanceSS(Segment s1, Segment s2) {
	if( intersect(s1, s2) ) return 0.0;
	return min(min(getDistanceSP(s1, s2.p1), getDistanceSP(s1, s2.p2)),
			   min(getDistanceSP(s2, s1.p1), getDistanceSP(s2, s1.p2)));
}

class Rectangle { // ????????¢
public:
	// 3 2
	// 0 1 (???????¨??????????????????¢??????????????????????????¨)
	vector<Point> p; // ?????????????????????????????¨
	Rectangle(vector<Point>&p):p(p) {
		rep(i, 3) reps(j, i + 1, 4) { //????????????????????????????????§???????????????????
			int cnt = 0;
			rep(k, 4) if(k != i && k != j) {
				cnt += ccw(p[i], p[j], p[k]) == COUNTER_CLOCKWISE;
			}
			if(cnt == 2) {
				swap(p[i + 1], p[j]);
				break;
			}
		}
	}
	bool intersect(const Segment& s) { // ??????s??¨????????¢????°?????????¨???1??????????????????????????°true
		bool flag = false;
		rep(i, 4) flag |= ::intersect(s, Segment(p[i], p[(i + 1) % 4]));
		return flag;
	}
	bool contain(const Point& pp) { // ???pp???????????¢????????????????????°(??????????????????)true
		bool flag = true;
		rep(i, 4) flag &= ccw(p[i], p[(i + 1) % 4], pp) == COUNTER_CLOCKWISE;
		return flag;
	}
	bool contain(const Segment& s) { // ??????s???????????¢????????????????????°(??????????????????)true
		return contain(s.p1) && contain(s.p2);
	}
};



int main(void) {
	
	while(1) {
		int N; scanf("%d", &N);
		if(N == 0) break;
		double sx, sy, ex, ey; scanf("%lf %lf %lf %lf", &sx, &sy, &ex, &ey);
		double minx[55], miny[55], maxx[55], maxy[55], h[55];
		rep(i, N) scanf("%lf %lf %lf %lf %lf", &minx[i], &miny[i], &maxx[i], &maxy[i], &h[i]);

		Segment L(Point(sx, sy), Point(ex, ey));

		double ans = INF;
		rep(i, N) {
			vector<Point> tmp({Point(minx[i], miny[i]), Point(maxx[i], miny[i]), Point(maxx[i], maxy[i]), Point(minx[i], maxy[i])});
			Rectangle rec(tmp);
			if(rec.intersect(L) || rec.contain(L)) {
				ans = 0.0;
				continue;
			}
			
			double d = INF;
			chmin(d, getDistanceSS(L, Segment(Point(minx[i], miny[i]), Point(minx[i], maxy[i]))));
			chmin(d, getDistanceSS(L, Segment(Point(minx[i], maxy[i]), Point(maxx[i], maxy[i]))));
			chmin(d, getDistanceSS(L, Segment(Point(maxx[i], maxy[i]), Point(maxx[i], miny[i]))));
			chmin(d, getDistanceSS(L, Segment(Point(maxx[i], miny[i]), Point(minx[i], miny[i]))));

			double r;
			if(d <= h[i]) r = d;
			else r = (d * d + h[i] * h[i]) / (2 * h[i]);

			chmin(ans, r);
		}
		printf("%.9f\n", ans);
	}
	
	return 0;
}