#include <bits/stdc++.h>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef vector<pll> vpll;
typedef pair<int,P> pip;
typedef vector<pip> vip;
const int inf=1<<30;
const ll INF=1ll<<60;
const double pi=acos(-1);
const double eps=1e-8;
const ll mod=1e9+7;
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

int n,h,w,d[4];
vi x,y,c;
vvp a,b;
vvi g;

void add(int u,int v){
	g[u].push_back(v);
	g[v].push_back(u);
}

void dfs(int v,vi e){
	c[v]=1;
	int X=x[v],Y=y[v];
	if(X==0&&!e[0]) e[0]++,d[0]++;
	if(X==h-1&&!e[1]) e[1]++,d[1]++;
	if(Y==0&&!e[2]) e[2]++,d[2]++;
	if(Y==w-1&&!e[3]) e[3]++,d[3]++;
	for(auto u:g[v]) if(!c[u]) dfs(u,e);
}

int main(){
	cin>>n>>h>>w;
	a=vvp(h);
	b=vvp(w);
	x=y=c=vi(n);
	g=vvi(n);
	for(int i=0;i<n;i++){
		cin>>x[i]>>y[i];
		x[i]--;y[i]--;
		a[x[i]].push_back({y[i],i});
		b[y[i]].push_back({x[i],i});
	}
	for(int i=0;i<h;i++){
		sort(a[i].begin(),a[i].end());
		for(int j=1;j<a[i].size();j++){
			int u=a[i][j-1].second,v=a[i][j].second;
			add(u,v);
		}
	}
	for(int i=0;i<w;i++){
		sort(b[i].begin(),b[i].end());
		for(int j=1;j<b[i].size();j++){
			int u=b[i][j-1].second,v=b[i][j].second;
			add(u,v);
		}
	}
	int t=0,M=0;
	for(int i=0;i<n;i++) if(!c[i]){
		vi e(4);
		dfs(i,e);
		t++;
	}
	for(int i=0;i<4;i++) M=max(M,d[i]);
	cout<<n-1+(t==1?0:t-M)<<endl;
}
