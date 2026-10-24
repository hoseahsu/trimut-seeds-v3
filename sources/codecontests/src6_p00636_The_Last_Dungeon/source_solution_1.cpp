#include<cmath>
#include<cstdio>
#include<vector>
#include<algorithm>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const double EPS=1e-8;
const double INF=1e77;

template<class T>
struct point{
	T x,y;
	point operator+(const point &a)const{ return (point){x+a.x,y+a.y}; }
	point operator-(const point &a)const{ return (point){x-a.x,y-a.y}; }
};

template<class T>
point<T> operator*(T c,const point<T> &a){ return (point<T>){c*a.x,c*a.y}; }

bool operator<(const point<double> &a,const point<double> &b){
	return a.x+EPS<b.x || abs(a.x-b.x)<EPS && a.y+EPS<b.y;
}
bool operator==(const point<double> &a,const point<double> &b){
	return abs(a.x-b.x)<EPS && abs(a.y-b.y)<EPS;
}

template<class T>
T dot(const point<T> &a,const point<T> &b){ return a.x*b.x+a.y*b.y; }

template<class T>
T cross(const point<T> &a,const point<T> &b){ return a.x*b.y-a.y*b.x; }

template<class T>
double abs(const point<T> &a){ return sqrt(a.x*a.x+a.y*a.y); }

template<class T>
struct line{ point<T> a,b; };

template<class T>
struct segment{
	point<T> a,b;
	operator line<T>()const{ return (line<T>){a,b}; }
};

template<class T>
struct polygon:vector< point<T> >{
	polygon(){}
	polygon(int n):vector< point<T> >(n){}
};

template<class T>
double dist(const point<T> &a,const point<T> &b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

bool cover(const segment<double> &S,const point<double> &p){
	return dist(S.a,p)+dist(p,S.b)<dist(S.a,S.b)+EPS;
}

enum {CCW=1,CW=-1,ON=0};
int ccw(const point<double> &a,const point<double> &b,const point<double> &c){
	double rdir=cross(b-a,c-a);
	if(rdir> EPS) return CCW;
	if(rdir<-EPS) return CW;
	return ON;
}

bool intersect(const segment<double> &S1,const segment<double> &S2){
	if(max(S1.a.x,S1.b.x)+EPS<min(S2.a.x,S2.b.x)
	|| max(S1.a.y,S1.b.y)+EPS<min(S2.a.y,S2.b.y)
	|| max(S2.a.x,S2.b.x)+EPS<min(S1.a.x,S1.b.x)
	|| max(S2.a.y,S2.b.y)+EPS<min(S1.a.y,S1.b.y)) return false;
	return ccw(S1.a,S1.b,S2.a)*ccw(S1.a,S1.b,S2.b)<=0
		&& ccw(S2.a,S2.b,S1.a)*ccw(S2.a,S2.b,S1.b)<=0;
}

point<double> get_intersect(const line<double> &L1,const line<double> &L2){
	double a1=cross(L1.b-L1.a,L2.b-L2.a);
	double a2=cross(L1.b-L1.a,L1.b-L2.a);
	if(abs(a1)<EPS) return L1.a;
	return L2.a+a2/a1*(L2.b-L2.a);
}

template<class T>
line<double> perp_bisector(const point<T> &a,const point<T> &b){
	return (line<double>){(point<double>){(a.x-a.y+b.x+b.y)/2.0,(a.y+a.x+b.y-b.x)/2.0},
						  (point<double>){(a.x+a.y+b.x-b.y)/2.0,(a.y-a.x+b.y+b.x)/2.0}};
}

template<class T>
polygon<double> convex_cut(const polygon<T> &G,const line<T> &L){
	int n=G.size();
	polygon<double> H;
	rep(i,n){
		int d1=ccw(L.a,L.b,G[i]);
		int d2=ccw(L.a,L.b,G[(i+1)%n]);
		if(d1!=CW) H.push_back(G[i]);
		if(d1==CCW && d2==CW || d1==CW && d2==CCW){
			H.push_back(get_intersect(L,(line<T>){G[i],G[(i+1)%n]}));
		}
	}
	return H;
}

void arrangement(const vector< segment<double> > &S,vector< point<double> > &P,vector<int> *G){
	int n=S.size();
	P.clear();
	rep(i,n){
		P.push_back(S[i].a);
		P.push_back(S[i].b);
		rep(j,i) if(intersect(S[i],S[j])) P.push_back(get_intersect(S[i],S[j]));
	}
	sort(P.begin(),P.end());
	P.erase(unique(P.begin(),P.end()),P.end());

	rep(i,n){
		vector<int> on;
		rep(u,P.size()) if(cover(S[i],P[u])) on.push_back(u);
		rep(j,(int)on.size()-1){
			int u=on[j],v=on[j+1];
			G[u].push_back(v);
			G[v].push_back(u);
		}
	}
}

int main(){
	for(int n; scanf("%d",&n),n;){
		point<double> p[20];
		rep(i,n) scanf("%lf%lf",&p[i].x,&p[i].y);

		if(n==1){ puts("impossible"); continue; }

		vector< segment<double> > S;
		rep(i,n){
			polygon<double> Vo; // p[i] の Volonoi cell
			Vo.push_back((point<double>){0,0});
			Vo.push_back((point<double>){4,0});
			Vo.push_back((point<double>){4,4});
			Vo.push_back((point<double>){0,4});
			rep(j,n) if(i!=j) Vo=convex_cut(Vo,perp_bisector(p[i],p[j]));
			rep(j,Vo.size()) {
				point<double> a=Vo[j],b=Vo[(j+1)%Vo.size()];
				if(abs(a.y-0)<EPS && abs(b.y-0)<EPS
				|| abs(a.y-4)<EPS && abs(b.y-4)<EPS) continue; // フィールドの縁はアレンジメントの候補に入れない
				S.push_back((segment<double>){a,b});
			}
		}
		S.push_back((segment<double>){(point<double>){0,0},(point<double>){0,4}});
		S.push_back((segment<double>){(point<double>){4,0},(point<double>){4,4}});

		vector< point<double> > P;
		vector<int> G[500];
		arrangement(S,P,G);

		int N=P.size();
		static double d[500][500];
		rep(u,N) rep(v,N) d[u][v]=(u==v?0:INF);
		rep(u,N) rep(i,G[u].size()) {
			int v=G[u][i];
			d[u][v]=dist(P[u],P[v]);
		}
		rep(w,N) rep(u,N) rep(v,N) d[u][v]=min(d[u][v],d[u][w]+d[w][v]);

		double ans=INF;
		rep(u,N) rep(v,N) if(abs(P[u].x)<EPS && abs(P[v].x-4)<EPS) ans=min(ans,d[u][v]);
		if(ans<INF/2) printf("%.9f\n",ans);
		else          puts("impossible");
	}

	return 0;
}