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
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
ll n,h[40005],a[40005],d[40005],s[40005];
vector<pair<pair<ll,ll>,int> >M;
bool cmp(const pair<pair<ll,ll>,int> &a,const pair<pair<ll,ll>,int> &b){
	return 1LL*a.fi.fi*b.fi.sc < 1LL*b.fi.fi*a.fi.sc;
}
int main(){
	cin >> n;
	for(int i=0;i<=n;i++) cin >> h[i] >> a[i] >> d[i] >> s[i];
	ll C = 0;
	for(int i=1;i<=n;i++){
		if(a[i] <= d[0]){
			continue;
		}
		if(a[0] <= d[i]){
			puts("-1"); return 0;
		}
		C += (a[i]-d[0]);
		M.pb(mp( mp( (h[i]+a[0]-d[i]-1)/(a[0]-d[i]),a[i]-d[0]) , i ));
	}
	sort(M.begin(),M.end(),cmp);
	ll cur = 0;
	for(int i=0;i<M.size();i++){
		int m = M[i].sc;
		ll T = (h[m]+a[0]-d[m]-1)/(a[0]-d[m]);
		cur += 1LL * T * C;
		if(s[m] < s[0]) cur -= (a[m]-d[0]);
		if(cur >= h[0]){
			puts("-1"); return 0;
		}
		C -= (a[m]-d[0]);
	}
	printf("%lld\n",cur);
}