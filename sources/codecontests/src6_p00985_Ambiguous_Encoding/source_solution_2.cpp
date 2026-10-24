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

int mask(int a){
	return (1LL<<a)-1;
}
int topbit(ll t){
	return t==0?-1:63-__builtin_clzll(t);
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n;cin>>n;
	vi len(n),bit(n);
	rep(i,n){
		string s;cin>>s;
		len[i]=s.size();
		rep(j,s.size())
			bit[i]+=(s[j]-'0')<<j;
	}
	
	const int L=17;
	const int inf=LLONG_MAX/3;
	vc<int> dist(1<<L,inf);
	priority_queue<pi,vc<pi>,greater<pi>> pq;
	auto rc=[&](int a,int b,int c){
		dmp(a);
		dmp(b);
		dmp(c);
		int x=b+(1<<a);
		dmp(x);
		if(dist[x]>c){
			dist[x]=c;
			pq.emplace(c,x);
		}
	};
	
	rep(i,n)rep(j,n)if(i!=j){
		if(len[j]<len[i]&&(bit[i]&mask(len[j]))==bit[j]){
			rc(len[i]-len[j],bit[i]>>len[j],len[i]);
		}
	}
	
	while(pq.size()){
		int v,d;tie(d,v)=pq.top();pq.pop();
		dmp(v);
		dmp(d);
		if(v==1){
			cout<<d<<endl;
			return 0;
		}
		if(dist[v]!=d)continue;
		int a=topbit(v);
		int b=v^1<<a;
		rep(i,n){
			if(len[i]<=a){
				if((b&mask(len[i]))==bit[i]){
					rc(a-len[i],b>>len[i],d);
				}
			}else{
				if((bit[i]&mask(a))==b){
					rc(len[i]-a,bit[i]>>a,d+len[i]-a);
				}
			}
		}
	}
	cout<<0<<endl;
}

