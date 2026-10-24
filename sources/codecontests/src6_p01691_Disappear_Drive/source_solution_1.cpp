#include<cstdio>
#include<iostream>
#include<vector>
#include<complex>
#include<string>
#include<algorithm>
#include<set>
#include<cassert>

using namespace std;

#define reps(i,f,n) for(int i=f;i<int(n);i++)
#define rep(i,n) reps(i,0,n)


const double EPS = 1e-8;
const double INF = 1e12;

typedef complex<double> P;

#define X real()
#define Y imag()

#define Curr(P,i) P[(i)%P.size()]
#define Next(P,i) P[(i+1)%P.size()]
#define Prev(P,i) P[(i+P.size()-1)%P.size()]


namespace std{
  bool operator<(const P a,const P b){
    return a.X != b.X ? a.X < b.X : a.Y < b.Y;
  }
}
double cross(const P a,const P b){
  return (conj(a)*b).imag();
}
double dot(const P a,const P b){
  return (conj(a)*b).real();
}
// TODO make graph (20)
int ccw(P a,P b,P c){
  b-=a;
  c-=a;
  if(cross(b,c)>0) return +1;//counter clockwise
  if(cross(b,c)<0) return -1;//clockwise
  if(dot(b,c)<0) return +2;// c--a--b
  if(norm(b)<norm(c)) return -2;// a--b--c
                      return 0;// a--c--b(or b==c)
}

struct L : public vector<P>{
  L(const P a,const P b){
    push_back(a),push_back(b);
  }
};
typedef L S;
typedef vector<P> G;

struct C{
  P p;double r;
  C(const P p,double r): p(p),r(r){}
};

P projection(L a,P p){
  double t = dot(p-a[0],a[0]-a[1])/norm(a[0]-a[1]+EPS);
  return a[0] + t*(a[0]-a[1]);
}
P reflection(L a,P p){
  return p + 2.0 * (projection(a,p)-p);
}

bool isCrossLL(L a,L b){
  return
    abs(cross(a[1]-a[0],b[1]-b[0])) > EPS
    || abs(cross(a[1]-a[0],b[0]-a[0])) < EPS ;
}
P crossP_LL(L a,L b){
  double A = cross(a[1]-a[0],b[1]-b[0]);
  double B = cross(a[1]-a[0],a[1]-b[0]);
  if(abs(A)<EPS && abs(B)<EPS)return b[0];
  if(abs(A)<EPS)assert(false);
  return b[0]+B/A*(b[1]-b[0]);
}

vector<L> TLine_CP(C c,P p){
  P v = c.p - p;
  double t = asin(abs(c.r)/(abs(v)));
  P e = v/abs(v) * exp(P(.0,t));
  P n1 = sqrt(abs(v)*abs(v) - c.r*c.r)*e + p;
  P n2 = reflection(L(p,c.p),n1);
  
  vector<L> ret;
  ret.push_back(L(p,n1));
  ret.push_back(L(p,n2));
  return ret;
}

bool isCrossSP(S a,P p){
  return abs(a[0]-p)+abs(a[1]-p)-abs(a[0]-a[1]) < EPS;
}
double distSP(S a,P p){
  const P r = projection(a,p);
  bool f = isCrossSP(a,r);
  return f ? abs(p-r) : min(abs(a[0]-p),abs(a[1]-p));
}
double distPP(P a,P b){
  return abs(a-b);
}


int n,m;
vector<C> cir;

void input(){
	cin>>n>>m;
	rep(i,n){
		int a,b,c;
		cin>>a>>b>>c;
		cir.push_back(C(P(a,b),c));
	}
}


class Path : public vector<L>{
	public:
	Path(L a){push_back(a);}
	Path(L a, L b){push_back(a);push_back(b);}
};

vector<Path> path;

void makeLines(){
	P st(25,0);
	P en(25,94);
	
	path.push_back(Path(L(st,en)));
	rep(i,cir.size()){
		rep(j,cir.size()){
			vector<L> ps = TLine_CP(cir[i], st);
			vector<L> pe = TLine_CP(cir[j], en);
			rep(k,ps.size()){
				rep(p,pe.size()){
					path.push_back(Path(ps[k],pe[p]));
				}
			}
		}
	}
}

void printLines(){
	rep(i,path.size()){
		rep(j,path[i].size()){
			printf("(%lf,%lf)-(%lf,%lf) ",path[i][j][0].X,path[i][j][0].Y,path[i][j][1].X,path[i][j][1].Y);
		}puts("");
	}
}

bool boxin(P p){
	return p.X>-EPS && p.X<50+EPS && p.Y>-EPS && p.Y<94+EPS; 
}

void removeOut(){
	rep(i,path.size()){
		bool flg = true;
		rep(j,path[i].size()-1){
			if(isCrossLL(path[i][j], path[i][j+1])){
				P p = crossP_LL(path[i][j], path[i][j+1]);
				path[i][j][1] = p;
				path[i][j+1][1] = p;
				if(!boxin(p))flg=false;
			}else{
				flg=false;
			}
		}
		if(!flg){
			path.erase(path.begin()+i);
			i--;
		}
	}
}

void removeCircleOn(){
	rep(i,path.size()){
		int count = 0;
		
		rep(k,cir.size()){
			rep(j,path[i].size()){
				double dist = distSP(path[i][j], cir[k].p);
				if(dist+EPS<cir[k].r)count++;
			}
			if(distPP(cir[k].p, path[i][0][1])+EPS<cir[k].r)count--;
		}
		//printf("%d %d\n",i,count);
		if(count>m){
			path.erase(path.begin()+i);
			i--;
		}
	}
}

/*
1 0
25 47 100

*/
double minLength(){
	double mini = INF;
	rep(i,path.size()){
		double sum = 0;
		rep(j,path[i].size()){
			sum += distPP(path[i][j][0], path[i][j][1]);
		}
		mini = min(sum, mini);
	}
	if(mini==INF)return -1;
	return mini;
}
double solve(){
	
	makeLines();
	removeOut();
	
	//printLines();
	
	removeCircleOn();
	
	
	return minLength();
}


int main(){
	input();
	printf("%.12lf\n",solve());
}