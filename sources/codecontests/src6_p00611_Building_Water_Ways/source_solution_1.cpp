#include <bits/stdc++.h>
using namespace std;

#define dump(...) cout<<"# "<<#__VA_ARGS__<<'='<<(__VA_ARGS__)<<endl
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define peri(i,a,b) for(int i=int(b);i-->int(a);)
#define rep(i,n) repi(i,0,n)
#define per(i,n) peri(i,0,n)
#define all(c) begin(c),end(c)
#define mp make_pair
#define mt make_tuple

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<string> vs;

template<typename T1,typename T2>
ostream& operator<<(ostream& os,const pair<T1,T2>& p){
	return os<<'('<<p.first<<','<<p.second<<')';
}

template<typename Tuple>
void print_tuple(ostream&,const Tuple&){}
template<typename Car,typename... Cdr,typename Tuple>
void print_tuple(ostream& os,const Tuple& t){
	print_tuple<Cdr...>(os,t);
	os<<(sizeof...(Cdr)?",":"")<<get<sizeof...(Cdr)>(t);
}
template<typename... Args>
ostream& operator<<(ostream& os,const tuple<Args...>& t){
	print_tuple<Args...>(os<<'(',t);
	return os<<')';
}

template<typename Ch,typename Tr,typename C>
basic_ostream<Ch,Tr>& operator<<(basic_ostream<Ch,Tr>& os,const C& c){
	os<<'[';
	for(auto i=begin(c);i!=end(c);++i)
		os<<(i==begin(c)?"":" ")<<*i;
	return os<<']';
}

constexpr int INF=1e9;
constexpr int MOD=1e9+7;
constexpr double EPS=1e-9;

constexpr int di[]={-1,1,0,0},dj[]={0,0,-1,1};

int count(const vs& grid,int i,int j)
{
	int cnt=0;
	rep(k,4){
		int ni=i+di[k],nj=j+dj[k];
		cnt+=grid[ni][nj]=='P' || grid[ni][nj]=='W' || grid[ni][nj]=='C';
	}
	return cnt;
}

void print(const vs& grid)
{
	cout<<"# grid:"<<endl;
	for(const auto& line:grid) cout<<line<<endl;
}

void solve(vs& grid,const vector<pii>& ps,int pi,int cnt,int rest,int& res);

void dfs(vs& grid,int i,int j,const vector<pii>& ps,int pi,int cnt,int rest,int& res)
{
	if(cnt>=res) return;
	int h=grid.size(),w=grid[0].size();
	if(rest==0){
		int tmp=0;
		rep(i,h) rep(j,w) tmp+=grid[i][j]=='W' || grid[i][j]=='C';
		res=min(res,tmp);
	}
	if(grid[i][j]=='#' || grid[i][j]=='P' || count(grid,i,j)>=2) return;
	
	if(grid[i][j]=='*'){
		grid[i][j]='C';
		rep(k,4){
			int ni=i+di[k],nj=j+dj[k];
			dfs(grid,ni,nj,ps,pi,cnt+1,rest-1,res);
		}
		if(pi+1<ps.size()){
			int ni,nj; tie(ni,nj)=ps[pi+1];
			solve(grid,ps,pi+1,cnt+1,rest-1,res);
		}
		grid[i][j]='*';
	}
	else{
		grid[i][j]='W';
		rep(k,4){
			int ni=i+di[k],nj=j+dj[k];
			dfs(grid,ni,nj,ps,pi,cnt+1,rest,res);
		}
		grid[i][j]='.';
	}
}

void solve(vs& grid,const vector<pii>& ps,int pi,int cnt,int rest,int& res)
{
	if(pi==ps.size()) return;
	solve(grid,ps,pi+1,cnt,rest,res);
	int i,j; tie(i,j)=ps[pi];
	rep(k,4) dfs(grid,i+di[k],j+dj[k],ps,pi,cnt,rest,res);
}


int main()
{
	for(int h,w;cin>>h>>w && h|w;){
		vs grid(h);
		rep(i,h) cin>>grid[i];
		
		vector<pii> ps;
		rep(i,h) rep(j,w) if(grid[i][j]=='P') ps.emplace_back(i,j);
		
		int rest=0; rep(i,h) rep(j,w) rest+=grid[i][j]=='*';
		int res=INF;
		solve(grid,ps,0,0,rest,res);
		cout<<res<<endl;
	}
}