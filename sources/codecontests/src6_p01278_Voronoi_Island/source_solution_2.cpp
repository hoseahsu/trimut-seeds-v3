#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <cstring>
#include <functional>
#include <cmath>
#include <complex>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define rep1(i,n) for(int i=1;i<=(n);++i)
#define all(c) (c).begin(),(c).end()
#define fs first
#define sc second
#define pb push_back
#define show(x) cout << #x << " " << x << endl
typedef double D;
typedef complex<D> P;
typedef pair<P,P> L;
typedef vector<P> Pol;
D eps=1e-9;
inline D cro(P a,P b){
	return imag(conj(a)*b);
}
inline int ccw(P a,P b,P c){
	if(cro(b-a,c-a)>eps) return 1;
	if(cro(b-a,c-a)<-eps) return -1;
	return 0;
}
inline bool iLSex(L l,L s){
	return cro(l.sc-l.fs,s.fs-l.fs)*cro(l.sc-l.fs,s.sc-l.fs)<-eps;
}
inline P intLL(L a,L b){
	D t=cro(a.sc-a.fs,a.sc-b.fs)/cro(a.sc-a.fs,b.sc-b.fs);
	return b.fs+t*(b.sc-b.fs);
}
inline Pol convexcut(Pol p,L l){
	Pol ret;
	rep(i,p.size()){
		if(ccw(l.fs,l.sc,p[i])!=-1) ret.pb(p[i]);
		L s=L(p[i],p[(i+1)%p.size()]);
		if(iLSex(l,s)) ret.pb(intLL(l,s));
	}
	return ret;
}
vector<Pol> makevolonoi(Pol vp,Pol pol){
	vector<Pol> ret;
	Pol polc=pol;
	rep(i,vp.size()){
		pol=polc;
		rep(j,vp.size()){
			if(i==j) continue;
			P p=(vp[i]+vp[j])/2.0,q=p+(vp[j]-vp[i])*P(0,1);
			pol=convexcut(pol,L(p,q));
		}
		ret.pb(pol);
	}
	return ret;
}
D aPol(Pol p){
	int n=p.size();
	D ret=0;
	rep(i,n) ret+=cro(p[i],p[(i+1)%n])/2;
	return ret;
}
int main(){
	while(true){
		int N,M;
		cin>>N>>M;
		if(N==0) break;
		Pol pol,vp;
		rep(i,N){
			int x,y;
			cin>>x>>y;
			pol.pb(P(x,y));
		}
		rep(i,M){
			int x,y;
			cin>>x>>y;
			vp.pb(P(x,y));
		}
		vector<Pol> vol=makevolonoi(vp,pol);
		rep(i,M) printf("%.12f\n",aPol(vol[i]));
	}
}