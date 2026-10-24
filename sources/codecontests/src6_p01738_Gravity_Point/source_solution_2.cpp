#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
typedef double D;
typedef complex<D> P;
typedef pair<P,P> L;
typedef vector<P> Pol;
D eps=1e-9;
bool eq(D a,D b){return abs(a-b)<eps;}
int sig(D a){return eq(a,0)?0:(a>0?1:-1);}
void fix(D &x){if(sig(x)==0) x=0;}
D cro(P a,P b){return imag(conj(a)*b);}
int ccw(P a,P b,P c){
	if(sig(cro(b-a,c-a))==1) return 1;
	if(sig(cro(b-a,c-a))==-1) return -1;
	if(eq(abs(a-c)+abs(c-b),abs(a-b))) return 0;
	if(eq(abs(a-b)+abs(c-b),abs(a-c))) return -2;
	return 2;
}
D aPol(Pol p){
	int N=p.size();
	D ret=0;
	rep(i,N) ret+=cro(p[i],p[(i+1)%N])/2;
	return ret;
}
bool iLSex(L l,L s){
	return sig(cro(l.sc-l.fs,s.fs-l.fs)*cro(l.sc-l.fs,s.sc-l.fs))<0;
}
P intLL(L a,L b){
	D t=cro(a.sc-a.fs,a.sc-b.fs)/cro(a.sc-a.fs,b.sc-b.fs);
	return b.fs+t*(b.sc-b.fs);
}
Pol convexcut(Pol p,L l){
	Pol ret;
	int N=p.size();
	rep(i,N){
		if(ccw(l.fs,l.sc,p[i])!=-1) ret.pb(p[i]);
		L s=L(p[i],p[(i+1)%N]);
		if(iLSex(l,s)) ret.pb(intLL(l,s));
	}
	return ret;
}
int H,W;
D la,ra,lb,rb,mx;
string s[50];
int main(){
	cin>>H>>W>>la>>ra>>lb>>rb>>mx;
	rep(i,H) cin>>s[i];
	int ca=0,cb=0,cx=0;
	D xa=0,xb=0,xx=0,ya=0,yb=0,yx=0;
	rep(i,H) rep(j,W){
		if(s[i][j]=='A'){
			xa+=j+0.5,ya+=i+0.5,ca++;
		}else if(s[i][j]=='B'){
			xb+=j+0.5,yb+=i+0.5,cb++;
		}else if(s[i][j]=='X'){
			xx+=j+0.5,yx+=i+0.5,cx++;
		}
	}
	xa/=ca,ya/=ca,xb/=cb,yb/=cb,xx/=cx,yx/=cx;
	mx*=cx;
	la*=ca,ra*=ca,lb*=cb,rb*=cb;
	D ans=0;
	rep(ii,H) rep(jj,W){
		D x=jj,y=ii;
		Pol pol;
		pol.pb(P(la,lb));
		pol.pb(P(ra,lb));
		pol.pb(P(ra,rb));
		pol.pb(P(la,rb));
		{
			D A=xa-x,B=xb-x,C=(xx-x)*mx;
			fix(A),fix(B),fix(C);
			if(B!=0){
				P p(0,-C/B),q(1,-(C+A)/B);
				if(B<0) swap(p,q);
				pol=convexcut(pol,L(p,q));
			}else if(A!=0){
				P p(-C/A,0),q(-C/A,1);
				if(A>0) swap(p,q);
				pol=convexcut(pol,L(p,q));
			}else{
				if(C<0) pol.clear();
			}
		}
		{
			D A=xa-x-1,B=xb-x-1,C=(xx-x-1)*mx;
			fix(A),fix(B),fix(C);
			if(B!=0){
				P p(0,-C/B),q(1,-(C+A)/B);
				if(B>0) swap(p,q);
				pol=convexcut(pol,L(p,q));
			}else if(A!=0){
				P p(-C/A,0),q(-C/A,1);
				if(A<0) swap(p,q);
				pol=convexcut(pol,L(p,q));
			}else{
				if(C>0) pol.clear();
			}
		}
		{
			D A=ya-y,B=yb-y,C=(yx-y)*mx;
			fix(A),fix(B),fix(C);
			if(B!=0){
				P p(0,-C/B),q(1,-(C+A)/B);
				if(B<0) swap(p,q);
				pol=convexcut(pol,L(p,q));
			}else if(A!=0){
				P p(-C/A,0),q(-C/A,1);
				if(A>0) swap(p,q);
				pol=convexcut(pol,L(p,q));
			}else{
				if(C<0) pol.clear();
			}
		}
		{
			D A=ya-y-1,B=yb-y-1,C=(yx-y-1)*mx;
			fix(A),fix(B),fix(C);
			if(B!=0){
				P p(0,-C/B),q(1,-(C+A)/B);
				if(B>0) swap(p,q);
				pol=convexcut(pol,L(p,q));
			}else if(A!=0){
				P p(-C/A,0),q(-C/A,1);
				if(A<0) swap(p,q);
				pol=convexcut(pol,L(p,q));
			}else{
				if(C>0) pol.clear();
			}
		}
		if(s[ii][jj]!='.') ans+=(aPol(pol)/(ra-la)/(rb-lb));
	}
	printf("%.12f\n",ans);
}