
/**
*   author:  akifpathan
*   created: Thursday 31.12.2020 11:51:21 AM
**/

/*
#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
*/

#ifdef LOCAL
#include "debug.h"
#else
#include<bits/stdc++.h>
using namespace std;
#define debug(x...)
#endif
 
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> 
using ordered_set= tree<T, null_type, 
		less<T>, 
		rb_tree_tag, tree_order_statistics_node_update> ;
template<class T> 		
using ordered_mset= tree<T, null_type, 
		less_equal<T>, 
		rb_tree_tag, tree_order_statistics_node_update> ;
		
*/
 
/*
 
PBDS
-------------------------------------------------
			0 based indexing
-------------------------------------------------			 
1) insert(value)
2) erase(value)
3) order_of_key(value) // Number of items strictly smaller than value
4) *find_by_order(k) : K-th element in a set (counting from zero)
 
*/
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
//mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());	

template<typename T,typename U>
T power(T b,U n)
{
	assert(n>=0);
	T ans=1;
	for(;n>0;n/=2,b*=b) if(n&1) ans*=b;
	return ans;
}
ll power(ll b,ll n,ll mod)
{
	assert(n>=0);
	ll ans=1;
	for(;n>0;n/=2,b=(b*b)%mod) if(n&1) ans=(ans*b)%mod;
	return ans;
}

template<ll mod>
struct Modular
{
	ll val;
	
	Modular(){ val=0; }
	Modular(ll _val) { val=_val%mod; if(val<0) val+=mod; }
	
	Modular normalize(const ll x) { val=x%mod; if(val<0) val+=mod; return val; }
	
	bool operator == (const Modular &a) const { return val==a.val; }
	bool operator != (const Modular &a) const { return val!=a.val; }
	bool operator < (const Modular &a) const { return val<a.val; }
	
	Modular operator = (ll x) { return normalize(x); }
	Modular operator = (const Modular &x){ val=x.val;return *this;}
	Modular operator += (const Modular &a) { return normalize(val+a.val); }
	Modular operator -= (const Modular &a) { return normalize(val-a.val);  }
	Modular operator *= (const Modular &a) { return normalize(val*a.val);}
	Modular operator /= (const Modular &b) { return normalize(val*inverse(b).val); }
	
	//friend Modular power(Modular b,ll n) {Modular ans=1; for(;n>0;n/=2,b*=b) if(n&1) ans*=b;return ans; }
	friend Modular operator ^ (Modular b,ll n) { return power(b,n); }
	friend Modular inverse(Modular b) { return b^(mod-2); }
	
	friend Modular operator + (Modular a,const Modular &b) { return a+=b; }
	friend Modular operator - (Modular a,const Modular &b) { return a-=b; }
	friend Modular operator * (Modular a,const Modular &b) { return a*=b; }
	friend Modular operator / (Modular a,const Modular &b) { return a/=b; }
	
	friend Modular operator + (Modular a,ll b) { return a+=b; }
	friend Modular operator - (Modular a,ll b) { return a-=b; }
	friend Modular operator * (Modular a,ll b) { return a*=b; }
	friend Modular operator / (Modular a,ll b) { return a/=b; }
	
	friend Modular operator + (ll b,Modular a) { return a+=b; };
	friend Modular operator - (ll b,const Modular &a) { Modular c(b); return c-=a; }
	friend Modular operator * (ll b,Modular a) { return a*=b; };
	friend Modular operator / (ll b,const Modular &a) { Modular c(b); return c/=a; }
	
	friend istream& operator >> (istream& in,Modular &a) {ll x; in>>x; a.normalize(x); return in; }
	friend ostream& operator << (ostream& out,const Modular& a) { return out<<a.val; }
};

//const ll mod=998244353;
const ll mod=1e9+7;
typedef Modular<mod> Mint;
struct DSU
{
	vector<int>par;
	vector<int>sz;
	
	DSU(int n)
	{
		par.resize(n+1);
		iota(par.begin(),par.end(),0);
		sz.assign(n+1,1);
	}
	
	int Find(int a)
	{
		return par[a]==a?a:par[a]=Find(par[a]);
	}
	
	bool same(int a,int b)
	{
		a=Find(a);
		b=Find(b);
		return a==b;
	}
	
	bool Union(int a,int b)
	{
		a=Find(a);
		b=Find(b);
		if(a==b) return false;		
		if(sz[a]<sz[b]) swap(a,b);
		sz[a]+=sz[b];
		par[b]=a;
		return true;
	}
};

void solve()
{
	int n,m;
	cin>>n>>m;
	
	DSU dsu(m+1);
	vector<int>ans;
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		int u,v;
		cin>>u;
		if(k==2) cin>>v;
		else v=m+1;
		
		if(dsu.Union(u,v)) ans.push_back(i);
	}
	
	cout<<(Mint(2)^ans.size())<<" "<<ans.size()<<"\n";
	for(int x: ans) cout<<x<<" ";
}		

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int testcase=1;
	//cin>>testcase;
	
	for(int i=1;i<=testcase;i++)
	{
		//cout<<"Case "<<i<<": ";
		solve();
	}
	
	#ifdef LOCAL
	cerr<<"\nTime elapsed: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms\n";
	#endif
	
	
	return 0;
}

