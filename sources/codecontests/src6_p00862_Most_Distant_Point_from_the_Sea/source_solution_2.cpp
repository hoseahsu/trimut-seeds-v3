#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <complex>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <functional>
#include <iterator>

using namespace std;

#define dump(n) cout<<"# "<<#n<<'='<<(n)<<endl
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define peri(i,a,b) for(int i=int(b);i-->int(a);)
#define rep(i,n) repi(i,0,n)
#define per(i,n) peri(i,0,n)
#define iter(c) __typeof__((c).begin())
#define foreach(i,c) for(iter(c) i=(c).begin();i!=(c).end();++i)
#define all(c) (c).begin(),(c).end()
#define mp make_pair

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef pair<int,int> pii;

const int INFTY=1<<29;
const double EPS=1e-9;

template<typename T1,typename T2>
ostream& operator<<(ostream& os,const pair<T1,T2>& p){
	return os<<'('<<p.first<<','<<p.second<<')';
}
template<typename T>
ostream& operator<<(ostream& os,const vector<T>& a){
	os<<'[';
	rep(i,a.size()) os<<(i?" ":"")<<a[i];
	return os<<']';
}

const double PI=acos(-1);

int Signum(double x){
	return abs(x)<EPS?0:x<0?-1:1;
}

struct Point{
	double x,y;
	Point(){}
	Point(double x,double y):x(x),y(y){}
};
bool operator==(Point a,Point b){
	return abs(a.x-b.x)<EPS && abs(a.y-b.y)<EPS;
}
bool operator!=(Point a,Point b){
	return abs(a.x-b.x)>=EPS || abs(a.y-b.y)>=EPS;
}
Point operator+(Point a,Point b){
	return Point(a.x+b.x,a.y+b.y);
}
Point operator-(Point a,Point b){
	return Point(a.x-b.x,a.y-b.y);
}
Point operator*(double c,Point p){
	return Point(c*p.x,c*p.y);
}
Point operator/(Point p,double c){
	return Point(p.x/c,p.y/c);
}
double Abs(Point p){
	return sqrt(p.x*p.x+p.y*p.y);
}
double Abs2(Point p){
	return p.x*p.x+p.y*p.y;
}
double Dot(Point a,Point b){
	return a.x*b.x+a.y*b.y;
}
double Cross(Point a,Point b){
	return a.x*b.y-a.y*b.x;
}
Point Rot(Point p,double t){
	return Point(cos(t)*p.x-sin(t)*p.y,sin(t)*p.x+cos(t)*p.y);
}

struct Line{
	Point pos,dir;
	Line(){}
	Line(Point p,Point d):pos(p),dir(d){}
	Line(double px,double py,double dx,double dy):pos(px,py),dir(dx,dy){}
};
typedef Line Segment;
Point InterLL(Line a,Line b){
	if(abs(Cross(a.dir,b.dir))<EPS)
		return a.pos;
	return a.pos+Cross(b.pos-a.pos,b.dir)/Cross(a.dir,b.dir)*a.dir;
}
Point InterLS(Line l,Segment s){
	return InterLL(s,l);
}

int CCW(Point a,Point b,Point c){
	Point d1=b-a,d2=c-a;
	if(int sign=Signum(Cross(d1,d2)))
		return sign;	// 1:ccw,-1:cw
	if(Dot(d1,d2)<-EPS)
		return -2;		// c-a-b
	if(Abs2(d1)<Abs2(d2)-EPS)
		return 2;		// a-b-c
	return 0;			// a-c-b
}

vector<Point> ConvexCut(const vector<Point>& ps,Line l){
	int n=ps.size();
	vector<Point> res;
	rep(i,n){
		int c1=CCW(l.pos,l.pos+l.dir,ps[i]);
		int c2=CCW(l.pos,l.pos+l.dir,ps[(i+1)%n]);
		if(c1!=-1)
			res.push_back(ps[i]);
		if(c1*c2==-1)
			res.push_back(InterLS(l,Segment(ps[i],ps[(i+1)%n]-ps[i])));
	}
	return res;
}

vector<Point> calc(const vector<Point>& ps,double x)
{
	vector<Point> res=ps;
	rep(i,ps.size()){
		Point dir=ps[(i+1)%ps.size()]-ps[i];
		Point pos=ps[i]+x*Rot(dir/Abs(dir),PI/2);
		res=ConvexCut(res,Line(pos,dir));
	}
	return res;
}

int main()
{
	for(int n;cin>>n,n;){
		vector<Point> ps(n);
		rep(i,n) cin>>ps[i].x>>ps[i].y;
		
		double lo=0,hi=1e6;
		rep(_,50){
			double mi=(lo+hi)/2;
			if(calc(ps,mi).size()==0)
				hi=mi;
			else
				lo=mi;
		}
		printf("%f\n",lo);
	}
	
	return 0;
}