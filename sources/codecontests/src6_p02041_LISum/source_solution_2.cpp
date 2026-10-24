#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 998244353
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,a[100005];
ll ans = 0;
struct RMQ{
	pair<int,ll>seg[(1<<18)];
	void I(){ fill(seg,seg+(1<<18),mp(0,0)); }
	void init(int i,pair<int,ll>a){
		i += (1<<17)-1;
		seg[i] = max(seg[i],a);
		while(i){
			i = (i-1)/2;
			seg[i] = max(seg[i*2+1],seg[i*2+2]);
		}
	}
	pair<int,ll> query(int a,int b,int k,int l,int r){
		if(r<a||b<l||a>b) return mp(0,0);
		if(a<=l && r<=b) return seg[k];
		return max(query(a,b,k*2+1,l,(l+r)/2),query(a,b,k*2+2,(l+r)/2+1,r));
	}
	ll ans(){
		return seg[0].sc;
	}
}kaede;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		pair<int,ll>R = kaede.query(0,a[i],0,0,(1<<17)-1);
		kaede.init(a[i]+1,mp(R.fi+1,R.sc+a[i]));
	}
	cout << kaede.ans() << endl;
}
