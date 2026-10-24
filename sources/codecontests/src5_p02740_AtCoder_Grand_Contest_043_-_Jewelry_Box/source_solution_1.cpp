#include <bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll

#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#define si(x) int(x.size())
#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;

using pi=pair<int,int>;
using vi=vc<int>;

template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>& p){
	return os<<"{"<<p.a<<","<<p.b<<"}";
}

template<class t> ostream& operator<<(ostream& os,const vc<t>& v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
}

#define mp make_pair
#define mt make_tuple
#define one(x) memset(x,-1,sizeof(x))
#define zero(x) memset(x,0,sizeof(x))
#ifdef LOCAL
void dmpr(ostream&os){os<<endl;}
template<class T,class... Args>
void dmpr(ostream&os,const T&t,const Args&... args){
	os<<t<<" ";
	dmpr(os,args...);
}
#define dmp2(...) dmpr(cerr,__LINE__,##__VA_ARGS__)
#else
#define dmp2(...) void(0)
#endif

using uint=unsigned;
using ull=unsigned long long;

template<class t,size_t n>
ostream& operator<<(ostream&os,const array<t,n>&a){
	return os<<vc<t>(all(a));
}

template<int i,class T>
void print_tuple(ostream&,const T&){
}

template<int i,class T,class H,class ...Args>
void print_tuple(ostream&os,const T&t){
	if(i)os<<",";
	os<<get<i>(t);
	print_tuple<i+1,T,Args...>(os,t);
}

template<class ...Args>
ostream& operator<<(ostream&os,const tuple<Args...>&t){
	os<<"{";
	print_tuple<0,tuple<Args...>,Args...>(os,t);
	return os<<"}";
}

template<class t>
void print(t x,int suc=1){
	cout<<x;
	if(suc==1)
		cout<<"\n";
	if(suc==2)
		cout<<" ";
}

ll read(){
	ll i;
	cin>>i;
	return i;
}

vi readvi(int n,int off=0){
	vi v(n);
	rep(i,n)v[i]=read()+off;
	return v;
}

template<class T>
void print(const vector<T>&v,int suc=1){
	rep(i,v.size())
		print(v[i],i==int(v.size())-1?suc:2);
}

string readString(){
	string s;
	cin>>s;
	return s;
}

template<class T>
T sq(const T& t){
	return t*t;
}

//#define CAPITAL
void yes(bool ex=true){
	#ifdef CAPITAL
	cout<<"YES"<<"\n";
	#else
	cout<<"Yes"<<"\n";
	#endif
	if(ex)exit(0);
}
void no(bool ex=true){
	#ifdef CAPITAL
	cout<<"NO"<<"\n";
	#else
	cout<<"No"<<"\n";
	#endif
	if(ex)exit(0);
}
void possible(bool ex=true){
	#ifdef CAPITAL
	cout<<"POSSIBLE"<<"\n";
	#else
	cout<<"Possible"<<"\n";
	#endif
	if(ex)exit(0);
}
void impossible(bool ex=true){
	#ifdef CAPITAL
	cout<<"IMPOSSIBLE"<<"\n";
	#else
	cout<<"Impossible"<<"\n";
	#endif
	if(ex)exit(0);
}

constexpr ll ten(int n){
	return n==0?1:ten(n-1)*10;
}

const ll infLL=LLONG_MAX/3;

#ifdef int
const int inf=infLL;
#else
const int inf=INT_MAX/2-100;
#endif

int topbit(signed t){
	return t==0?-1:31-__builtin_clz(t);
}
int topbit(ll t){
	return t==0?-1:63-__builtin_clzll(t);
}
int botbit(signed a){
	return a==0?32:__builtin_ctz(a);
}
int botbit(ll a){
	return a==0?64:__builtin_ctzll(a);
}
int popcount(signed t){
	return __builtin_popcount(t);
}
int popcount(ll t){
	return __builtin_popcountll(t);
}
bool ispow2(int i){
	return i&&(i&-i)==i;
}
int mask(int i){
	return (int(1)<<i)-1;
}

bool inc(int a,int b,int c){
	return a<=b&&b<=c;
}

template<class t> void mkuni(vc<t>&v){
	sort(all(v));
	v.erase(unique(all(v)),v.ed);
}

ll rand_int(ll l, ll r) { //[l, r]
	#ifdef LOCAL
	static mt19937_64 gen;
	#else
    static random_device rd;
    static mt19937_64 gen(rd());
    #endif
    return uniform_int_distribution<ll>(l, r)(gen);
}

template<class t>
int lwb(const vc<t>&v,const t&a){
	return lower_bound(all(v),a)-v.bg;
}

//AGC031E
//AGC034D
//CF621G
//負辺あったら壊れるからBellman-Fordとかやるといいんじゃない？
template<class D>
struct mincf{
	using P=pair<D,int>;
	struct E{int to,rev,cap;D cost;};
	int n;
	vvc<E> g;
	vc<D> h,d;
	vi pv,pe;
	mincf(int nn):n(nn),g(n),h(n),d(n),pv(n),pe(n){}
	pi ae(int a,int b,int cap,D cost){
		pi res(a,g[a].size());
		g[a].pb({b,(int)g[b].size(),cap,cost});
		g[b].pb({a,(int)g[a].size()-1,0,-cost});
		return res;
	}
	P go(int s,int t,int f){
		priority_queue<P,vc<P>,greater<P>> q;
		fill(all(d),inf);
		d[s]=0;
		q.push(P(0,s));
		while(q.size()){
			D a;
			int v;
			tie(a,v)=q.top();q.pop();
			if(d[v]<a)continue;
			if(v==t)break;
			rep(i,(int)g[v].size()){
				E e=g[v][i];
				if(e.cap>0){
					D w=d[v]+e.cost+h[v]-h[e.to];
					if(w<d[e.to]){
						d[e.to]=w;
						q.push(P(w,e.to));
						pv[e.to]=v;
						pe[e.to]=i;
					}
				}
			}
		}
		if(d[t]==inf)return P(0,0);
		rep(i,n)
			h[i]=min(h[i]+min(d[i],d[t]),inf);
		int a=f;
		for(int v=t;v!=s;v=pv[v])
			chmin(a,g[pv[v]][pe[v]].cap);
		for(int v=t;v!=s;v=pv[v]){
			E& e=g[pv[v]][pe[v]];
			e.cap-=a;
			g[e.to][e.rev].cap+=a;
		}
		return P(h[t],a);
	}
	D calc(int s,int t,int f){
		D res=0;
		while(f>0){
			P w=go(s,t,f);
			if(w.b==0)
				return inf;
			f-=w.b;
			res+=w.a*w.b;
		}
		return res;
	}
};

struct Jewel{
	int size,cost,cap;
	bool operator<(const Jewel&r)const{
		return size<r.size;
	}
};

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n;cin>>n;
	int s=1;
	vvc<Jewel> w(n);
	vvc<int> idx(n);
	rep(i,n){
		int a;cin>>a;
		rep(j,a){
			//size,cost,cap
			int x,y,z;cin>>x>>y>>z;
			w[i].pb({x,y,z});
			idx[i].pb(s++);
		}
		sort(all(w[i]));
	}
	s++;
	rep(i,n)idx[i].pb(s-1);
	
	mincf<int> mcf(s);
	rep(i,n){
		mcf.ae(0,idx[i][0],inf,0);
		rep(j,w[i].size()){
			mcf.ae(idx[i][j],idx[i][j+1],w[i][j].cost,0);
			mcf.ae(idx[i][j],idx[i][j+1],inf,w[i][j].cap);
		}
	}
	
	int m;cin>>m;
	rep(_,m){
		//size(b)<=size(a)+c
		int a,b,c;cin>>a>>b>>c;
		//size(a)>=size(b)-c
		a--;b--;
		rep(i,w[b].size()){
			int j=lwb(w[a],Jewel{w[b][i].size-c,0,0});
			mcf.ae(idx[b][i],idx[a][j],inf,0);
		}
	}
	
	vi cnt{0},height{0},slope;
	
	while(1){
		pi f=mcf.go(0,s-1,inf);
		slope.pb(f.a);
		if(f.b>=inf/2)break;
		cnt.pb(cnt.back()+f.b);
		height.pb(height.back()+f.a*f.b);
	}
	
	int q;cin>>q;
	rep(_,q){
		int k;cin>>k;
		int i=lwb(slope,k);
		int ans=-1;
		if(i<(int)cnt.size()){
			ans=k*cnt[i]-height[i];
		}
		cout<<ans<<endl;
	}
}

