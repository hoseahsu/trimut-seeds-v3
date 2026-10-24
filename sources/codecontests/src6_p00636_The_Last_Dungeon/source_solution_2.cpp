#include<complex>
#include<vector>
#include<iostream>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<cmath>
#include<cassert>

#define START_X 0.0
#define GOAL_X 4.0

#define FRONT 0x01
#define RIGHT 0x02
#define BACK 0x04
#define LEFT 0x08
#define OVER 0x10

#define sc second
#define fr first

#define REP(i,n) for(int i = 0; i < (int)(n); ++i)

using namespace std;

typedef double elem;
typedef complex<elem> point, vec;
typedef pair<point, point> line, hline, seg, pp;

const double eps = 1.0e-11;
const double pi = acos(-1.0);
const double infty = 1e40;
point base(0,0),origin(0,0);

bool eq(elem a, elem b){ return abs(a-b) < eps; }
bool lt(elem a, elem b){ return !eq(a,b) && a < b; }
bool leq(elem a, elem b){ return eq(a,b) || a < b; }
bool gt(elem a, elem b){ return !eq(a,b) && a > b; }
bool geq(elem a, elem b){ return eq(a,b) || a > b; }
bool ltz(elem a){ return lt( a, 0 ); }
bool gtz(elem a){ return gt( a, 0 ); }
bool eqv(vec a, vec b){ return eq( abs(b-a),0); }
bool is_zv(vec v){ return eq(abs(v),0); }
elem emax(elem a, elem b){ return gt(a,b)?a:b; }
elem emin(elem a, elem b){ return lt(a,b)?a:b; }

bool far(point a, point b){ return gtz( abs(b-a) ); }
bool near(point a, point b){ return leq( abs(b-a), 0 ); }
elem dot(vec a, vec b){ return (a.real() * b.real() + a.imag() * b.imag() ); }
elem cross(vec a, vec b){ return ( a.real() * b.imag() - a.imag() * b.real() ); }

elem dist(point a, point b){ return abs(a-b); }
elem dist_l(line l, point x){ return abs(cross(l.sc-l.fr,x-l.fr)) / abs(l.sc-l.fr); }
elem dist_seg(seg s, point x)
{
  if( ltz( dot(s.sc-s.fr,x-s.fr) ) ) return abs(x-s.fr);
  if( ltz( dot(s.fr-s.sc,x-s.sc) ) ) return abs(x-s.sc);
  return dist_l(s,x);
}

vec uvec(vec a){ return a / abs(a); }
vec nmr(vec a){ return a * vec(0,-1); }
vec nml(vec a){ return a * vec(0,1); }
vec unmr(vec a){ return uvec( nmr(a) ); }
vec unml(vec a){ return uvec( nml(a) ); }

bool orth(point a1, point a2, point b1, point b2){ return eq( dot( a2 - a1, b2 - b1 ), 0 ); }
bool orth(vec v1, vec v2){ return eq( dot(v1, v2), 0 ); }
bool prll(point a1, point a2, point b1, point b2){ return eq( cross( a2 - a1, b2 - b1 ), 0 ); }
bool prll(vec v1, vec v2){ return eq( cross(v1, v2), 0 ); }

int ccw(point a, point b, point x){
  b -= a;
  x -= a;
  if( gtz( cross(b,x) ) ) return LEFT;
  if( ltz( cross(b,x) ) ) return RIGHT;
  if( ltz( dot(b,x) ) ) return BACK;
  if( lt( abs(b), abs(x) ) ) return FRONT;
  return OVER;
}

bool intersectedSS(seg a, seg b)
{
  if( ccw(a.fr,a.sc,b.fr)&OVER || ccw(a.fr,a.sc,b.sc)&OVER ) return true;
  return
    ( ccw(a.fr,a.sc,b.fr) | ccw(a.fr,a.sc,b.sc) ) == (LEFT|RIGHT) &&
    ( ccw(b.fr,b.sc,a.fr) | ccw(b.fr,b.sc,a.sc) ) == (LEFT|RIGHT) ;
}

bool intersectedLL(line a, line b){ return !eq( cross(a.sc-a.fr,b.sc-b.fr), 0.0 ); }

point intersectionSS(seg a, seg b)
{
  elem d1 = dist_l(b,a.fr);
  elem d2 = dist_l(b,a.sc);
  return a.fr + ( d1 / (d1 + d2 ) ) * (a.sc-a.fr);
}
point intersectionLL(line a, line b)
{
  vec va = a.sc - a.fr;
  vec vb = b.sc - b.fr;
  return a.fr + va * ( cross(vb, b.fr - a.fr) / cross(vb,va) );
}

bool intersectionLL(line a, line b, point &ret){
  return intersectedLL( a, b ) ? ret = intersectionLL( a, b ), true : false;
}
bool intersectionLH(line a, hline b, point &ret){
  point tmp;
  return intersectionLL(a,b,tmp) ? ( ccw(b.fr,b.sc,tmp)&(OVER|FRONT) ? ret=tmp, true : false ) : false;
}
bool intersectionLS(line l, seg s, point &ret){
  point tmp;
  return intersectionLL(l,s,tmp) ? ( ccw(s.fr,s.sc,tmp)&OVER ? ret=tmp, true : false ) : false;
}
bool intersectionHH(hline a, hline b, point &ret){
  point tmp;
  return intersectionLL(a,b,tmp) ? ( ccw(a.fr,a.sc,tmp)&(OVER|FRONT)&&ccw(b.fr,b.sc,tmp)&(OVER|FRONT) ? ret = tmp, true : false ) : false;
}
bool intersectionHS(hline a, seg s, point &ret){
  point tmp;
  return intersectionLS(a,s,tmp) ? ( ccw(a.fr,a.sc,tmp)&(OVER|FRONT) ? ret = tmp, true : false ) : false;
}
bool intersectionSS(seg a, seg b, point &ret){
  return intersectedSS(a,b) ? ret = intersectionSS(a,b), true : false;
}

bool convexCut(const vector<point> &vp,
	       line l,
	       vector<point> &left)
{
  int n = vp.size();
  bool bFirst = true;
  int indq1 = -1, indq2 = -1;
  point q1, q2;
  
  for(int i = 0; i < n; ++i){
    seg edge = make_pair( vp[i], vp[(i+1)%n] );
    if( bFirst ){
      if( intersectionLS( l, edge, q1 ) ){ bFirst = false; indq1 = (i+1)%n; }
    }else{
      if( intersectionLS( l, edge, q2 ) && far(q1,q2) ){ indq2 = (i+1)%n; break; }
    }
  }

  if( indq1<0||indq2<0 ) return false;
  if( lt( dist( q1, l.second ), dist( q2, l.second ) ) ){ swap( q1, q2 ); swap( indq1, indq2 ); }
  if( far( q2, vp[indq2] ) ) left.push_back( q2 );
  for(int i = indq2; i != indq1; i=(i+1>=n?0:i+1)) left.push_back( vp[i] );
  if( far(q1, vp[(indq1-1+n)%n] ) ) left.push_back( q1 );

  return true;
}

struct Point{
  point p;
  Point():p(origin){}
  Point(point p):p(p){}
  bool operator < (const Point &t)const{
    if(!eq(p.real(),t.p.real()))return lt(p.real(),t.p.real());
    else return lt(p.imag(),t.p.imag());
  }
};

struct Node{
  point p;
  vector<int> con;
  vector<double> cost;
};

typedef vector<Node> Graph;

line expandLine(line l, elem mag){
  line ret = l;
  vec vf(l.first - l.second);
  vec vs(l.second - l.first);
  ret.first = l.second + mag * vf;
  ret.second = l.first + mag * vs;
  return ret;
}

void MakeVolonoi(const vector<point> &vp,
		 const vector<point> &plane,
		 vector< vector<point> > &out){
  vector<point> tplane;
  
  for(int i = 0; i < vp.size(); ++i){
    tplane = plane;
    for(int j = 0; j < vp.size(); ++j){
      if( i != j ){
	vector<point> newplane;
	point c = (vp[i]+vp[j])/2.;
	int cw = ccw( c, unmr(vp[i]-vp[j])+c, vp[i] );
	assert(cw==LEFT||cw==RIGHT);
	line bisec;
	if( cw == LEFT ){
	  bisec = line( c, unmr( vp[i]-vp[j] ) + c );
	}else{
	  bisec = line( c, unml( vp[i]-vp[j] ) + c );
	}
	bisec = expandLine( bisec, 100.0 ); // magnify segment for convex cut
	//cout << abs(bisec.second-bisec.first) << endl;
	if( convexCut(tplane, bisec, newplane ) )
	  tplane = newplane;
      }
    }
    out.push_back( tplane );
  }
};

struct State{
  int now;
  elem cost;
  State(){}
  bool operator<(const State &t)const{
    return lt(cost,t.cost);
  }
};

elem dijkstra(Graph &G, int sid){
  elem ret = infty;
  priority_queue<State> qs;
  State init;
  bool vis[G.size()];
  elem A[G.size()];
  for(int i = 0; i < G.size(); ++i){
    vis[i]=false;
    A[i]=infty;
  }
  init.now = sid;
  init.cost = 0.0;
  qs.push(init);
  A[sid]=0.0;
  vis[sid]=true;
  while(!qs.empty()){
    State st_now = qs.top(); qs.pop();
    int nid = st_now.now;
    vis[nid]=false;
    for(int i = 0; i < G[nid].con.size(); ++i){
      State next;
      next.now = G[nid].con[i];
      //cout << next.now << endl;
      next.cost = st_now.cost + G[nid].cost[i];
      if( lt(next.cost, A[next.now]) ){
	A[next.now] = next.cost;
	if( !vis[next.now] ){
	  vis[next.now]=true;
	  qs.push( next );
	}
      }
    }
  }
  for(int i = 0; i < G.size(); ++i){
    if( eq(G[i].p.real(),GOAL_X) ){
      ret = emin( ret, A[i] );
    }
  }
  return ret;
}

int main()
{
  while(true){
    int n;
    elem ans=infty;
    map<Point,int> point_id;
    vector<point> vp,plane;
    vector< vector<point> > volonoi;

    cin >> n;
    if( n == 0 ) break;
    for(int i = 0; i < n; ++i){
      elem x,y;
      cin >> x >> y;
      vp.push_back( point(x,y) );
    }
    if( n == 1 ){
      puts("impossible");
      continue;
    }
    plane.push_back( point(0.0,0.0) );
    plane.push_back( point(4.0,0.0) );
    plane.push_back( point(4.0,4.0) );
    plane.push_back( point(0.0,4.0) );
    MakeVolonoi( vp, plane, volonoi );

    /* debug 
    for(int i = 0; i < volonoi.size(); ++i){
      cout << "//" << i << " master point : " << vp[i] << endl;
      for(int j = 0; j < volonoi[i].size(); ++j){
	point lf=volonoi[i][j];
	point ls=volonoi[i][(j+1)%volonoi[i].size()];

	cout << "line(" << lf.real() <<"," << lf.imag() <<"," << ls.real() <<","<<ls.imag() << ");" << endl;
      }
    }
    cout << endl;
    */

    int now = 0;
    for(int i = 0; i < volonoi.size(); ++i){
      for(int j = 0; j < volonoi[i].size(); ++j){
	Point pp(volonoi[i][j]);
	if( point_id.find( pp ) == point_id.end() ){
	  point_id[pp] = now;
	  ++now;
	}
      }
    }
    Graph G(now);

    // Graph Construction
    for(int i = 0; i < volonoi.size(); ++i){
      int ni = volonoi[i].size();
      for(int j = 0; j < ni; ++j){
	point p = volonoi[i][j];
	point np = volonoi[i][(j+1)%ni];
	
	if( eq(p.real(),np.real())&&eq(p.real(),0.0) ||
	    eq(p.real(),np.real())&&eq(p.real(),4.0) ||
	    eq(p.imag(),np.imag())&&eq(p.imag(),0.0) ||
	    eq(p.imag(),np.imag())&&eq(p.imag(),4.0) )continue;
	int ip = point_id[Point(p)];
	int inp = point_id[Point(np)];
	elem d = dist( p, np );
	G[ ip ].p = p;
	G[ inp ].p = np;
	G[ ip ].con.push_back( inp );
	G[ ip ].cost.push_back( d );
	G[ inp ].con.push_back( ip );
	G[ inp ].cost.push_back( d );
      }
    }

    for(int i = 0; i < G.size(); ++i){
      if( eq( G[i].p.real(), START_X ) ){
	ans = emin( ans, dijkstra( G, i ) );
      }
    }

    if(geq(ans,infty))puts("impossible");
    else printf("%.12lf\n",ans);
  }
  return 0;
}