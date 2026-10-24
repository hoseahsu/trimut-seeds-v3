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
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}
int H,W;
typedef pair<int,int> P;
int ids[500*500];
bool ok(vector<P> vp){
	rep(i,H*W) ids[i]=0;
	int N=vp.size();
	rep(i,N){
		int in=vp[i].fs,out=vp[i].sc;
		if(in>out) swap(in,out);
		ids[in]=i+1;
		ids[out]=-(i+1);
	}
	stack<int> st;
	rep(i,H*W) if(ids[i]!=0){
		int x=ids[i];
		if(x>0){
			st.push(x);
		}else{
			int y=st.top();st.pop();
			if(-x!=y) return 0;
		}
	}
	return 1;
}
int p[500*500];
bool solve(){
	cin>>H>>W;
	rep(i,H*W){
		int a;
		cin>>a;
		p[a]=i;
	}
	vector<P> vp[2];
	rep(i,H) rep(j,W-1){
		vp[j%2].pb(P(p[i*W+j],p[i*W+j+1]));
	}
	if(!ok(vp[0])||!ok(vp[1])) return 0;
	vp[0].clear(),vp[1].clear();
	rep(j,W) rep(i,H-1){
		vp[i%2].pb(P(p[i*W+j],p[(i+1)*W+j]));
	}
	if(!ok(vp[0])||!ok(vp[1])) return 0;
	return 1;
}
int main(){
	if(solve()) puts("YES");
	else puts("NO");
}