#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
typedef long long ll;
#define mod 1000000007
class unionfind{
    public:
    ll treecnt,colorcnt;
    unordered_map<ll,ll> p,vcnt;
    unordered_set<ll> jiko;
    vector<ll> as,bs;
    void init(){
	as.clear();
	bs.clear();
	p.clear();
	vcnt.clear();
	jiko.clear();
	treecnt=0;
	colorcnt=0;
    }
    ll par(ll x){
	if(p.find(x)==p.end()){
	    p[x]=x;
	    vcnt[x]=1;
	    treecnt++;
	    colorcnt++;
	    return x;
	}
	return p[x]=(x==p[x]?x:par(p[x]));
    }
    void unite(ll a,ll b){
	as.push_back(a);
	bs.push_back(b);
	if(a==b){
	    if(jiko.find(a)!=jiko.end())return;
	    jiko.insert(a);
	    a=par(a);
	    if(vcnt[a]==1)treecnt--;
	    vcnt[a]--;
	    if(vcnt[a]==1)treecnt++;
	    return;
	}
	a=par(a),b=par(b);
	if(a==b){
	    if(vcnt[a]==1)treecnt--;
	    vcnt[a]--;
	    if(vcnt[a]==1)treecnt++;
	}
	else{
	    if(vcnt[a]==1)treecnt--;
	    if(vcnt[b]==1)treecnt--;
	    p[b]=a;
	    vcnt[a]+=vcnt[b]-1;
	    if(vcnt[a]==1)treecnt++;
	}
    }
    ll qry(){
	return colorcnt-treecnt;
    }
};
unionfind uf[100010];
ll n,k;
vector<ll> g[100010];
ll c[100010],d[100010];
ll id[100010];
ll ans[100010];
void dfs(ll x,ll from){
    ll ma=-1,pnt=-1;
    for(auto y:g[x])if(y!=from){
	dfs(y,x);
	if(uf[id[y]].colorcnt>ma){
	    ma=uf[id[y]].colorcnt;
	    pnt=y;
	}
    }
    if(pnt==-1)id[x]=x;
    else id[x]=id[pnt];
    uf[id[x]].unite(c[x],d[x]);
    for(auto y:g[x])if(y!=from&&y!=pnt){
	for(int i=0;i<uf[id[y]].as.size();i++){
	    ll a=uf[id[y]].as[i];
	    ll b=uf[id[y]].bs[i];
	    uf[id[x]].unite(a,b);
	}
	uf[id[y]].init();
    }
    ans[x]=uf[id[x]].qry();
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>n>>k;
  for(int i=0;i<n-1;i++){
      ll a,b; cin>>a>>b;
      g[a].push_back(b);
      g[b].push_back(a);
  }
  for(int i=1;i<=n;i++){
      cin>>c[i]>>d[i];
      uf[i].init();
  }
  dfs(1,0);
  for(int i=1;i<=n;i++){
      cout<<ans[i]<<endl;
  }
  return 0;
}

