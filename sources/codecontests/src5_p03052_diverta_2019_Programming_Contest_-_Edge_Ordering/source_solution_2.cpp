#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) for (auto i:v) printf("%lld ",i);puts("")
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ep emplace_back
#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define fil(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pa;
typedef pair<ll,ll> PA;
typedef vector<int> poly;
inline ll read(){
    ll x=0,f=1;char c=getchar();
    while ((c<'0'||c>'9')&&(c!='-')) c=getchar();
    if (c=='-') f=-1,c=getchar();
    while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    return x*f;
}

const int N = 20, maxn = 1<<20|3, mod = 1e9+7;
int n,m,cnt[maxn],b[maxn],s[maxn],c[maxn];
pa e[N*N];

struct _{
	int fa[N];
	inline void init(int n){
		FOR(i,0,n) fa[i]=i;
	}
	inline int Find(int x){
		return fa[x]==x?x:fa[x]=Find(fa[x]);
	}
	inline void Merge(int x,int y){
		fa[Find(x)]=Find(y);
	}
}f;

const int M = 200;
int fac[M+10],ifac[M+10];
inline int power(int a,int b){
	int ret=1;
	for (;b;b>>=1,a=1ll*a*a%mod) if (b&1) ret=1ll*ret*a%mod;
	return ret;
}
inline void init(int n){
	fac[0]=1;
	For(i,1,n) fac[i]=1ll*fac[i-1]*i%mod;
	ifac[n]=power(fac[n],mod-2);
	Dow(i,n-1,0) ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
}
inline int calc(int l,int r){
	return 1ll*fac[r]*ifac[l-1]%mod;
}

int main(){
	n=read(),m=read();
	FOR(i,0,m) e[i].fi=read()-1,e[i].se=read()-1;
	FOR(i,0,1<<(n-1)){
		f.init(n);
		FOR(j,0,n-1) if (i&(1<<j)) f.Merge(e[j].fi,e[j].se);
		b[i]=n-1-__builtin_popcount(i);
		cnt[i]=m-__builtin_popcount(i);
		FOR(j,n-1,m) if (f.Find(e[j].fi)==f.Find(e[j].se)) --cnt[i];
	}
	init(M);
	c[(1<<(n-1))-1]=1;
	Dow(i,(1<<(n-1))-2,0){
		FOR(j,0,n-1) if (!(i&(1<<j))){
			int k=i^(1<<j);
			c[i]=(c[i]+1ll*c[k]*calc(cnt[k]+1,cnt[i]-1))%mod;
			s[i]=(s[i]+1ll*s[k]*calc(cnt[k]+2,cnt[i]))%mod;
		}
		s[i]=(s[i]+1ll*c[i]*b[i])%mod;
	}
	printf("%d\n",s[0]);
}