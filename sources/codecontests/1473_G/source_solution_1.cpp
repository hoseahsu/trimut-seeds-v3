//CLOCKS_PER_SEC
using namespace std;
#include<bits/stdc++.h>
#define sqr(x) 1ll*(x)*(x)
//#define sort stable_sort
#define ll long long
#define mk make_pair
#define pb push_back
#define in insert
#define mtr(x,y,z) mk(mk(x,y),z)
#define fi first
#define se second
#define lch(x) ((x)<<1)
#define rch(x) (((x)<<1)|1)
#define all(x) (x).begin(),(x).end()
#define titose CLOCKS_PER_SEC
#define fpi(x) freopen(x,"r",stdin);
#define fpo(x) freopen(x,"w",stdout);
#define fprio fpi("in.txt");fpo("out.txt");
#define fast ios_base::sync_with_stdio(false);
inline void read(int &x){int v=0,f=1;char c=getchar();while (!isdigit(c)&&c!='-') c=getchar();if (c=='-') f=-1; else v=(c&15);while (isdigit(c=getchar())) v=(v<<1)+(v<<3)+(c&15);x=v*f;}
inline void read(ll &x){ll v=0ll,f=1ll;char c=getchar();while (!isdigit(c)&&c!='-') c=getchar();if (c=='-') f=-1; else v=(c&15);while (isdigit(c=getchar())) v=(v<<1)+(v<<3)+(c&15);x=v*f;}
inline void readc(char &x){char c;while (((c=getchar())==' ')||c=='\n');x=c;}
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define si set<int>
#define sl set<ll>
#define mii map<int,int>
#define mll map<ll,ll>
#define msi map<string,int>
#define msl map<string,ll>
#define piii pair<int,pii >
#define piipi pair<pii,int>
#define plll pair<ll,pll >
#define pllpl pair<pll,ll>
#define pqi priority_queue<int>
#define pql priority_queue<ll>
#define npqi priority_queue<int,vector<int>,greater<int> >
#define npql priority_queue<ll,vector<ll>,greater<ll> >
#define forup(i,a,b) for ((i)=(a);(i)<=(b);(i)++)
#define fordo(i,a,b) for ((i)=(a);(i)>=(b);(i)--)
#define rep(i,x) forup ((i),1,(x))
#define repd(i,x) fordo ((i),(x),1)
#define rep0(i,x) forup ((i),0,((int)(x))-1)
#define rep0d(i,x) fordo ((i),((int)(x))-1,0)
#define itr iterator
#define fe(itcalc,c) for(__typeof((c).begin()) itcalc=(c).begin();itcalc!=(c).end();itcalc++)
#define NO {cout<<"NO";return 0;}
#define YES {cout<<"YES";return 0;}
#define y0 y000000000000000000000000000
#define y1 y111111111111111111111111111
#define j0 j000000000000000000000000000
#define j1 j111111111111111111111111111
#define cl0(a) memset((a),(0),(sizeof((a))))
#define clz(a) memset((a),(0x16),(sizeof((a))))
#define clf(a) memset((a),(-(0x16)),(sizeof((a))))
#define inf 0x3bbbbbbb
#define lnf 0x2bbbbbbbbbbbbbbbll
//#define sqrt divi
#define p2(i) (1ll<<(i))
#define readi read
#define readll read
/*************************************************/
const int mod=998244353,maxn=16384;
int n,m,i,j,fac[240005],inv[240005],fi[240005],rev[maxn+5],a[maxn+5],b[maxn+5],w[maxn+5];
vector<int> v,nxt;
int c(int x,int y)
{
	if(x<y||x<0||y<0) return 0;
	return 1ll*fac[x]*fi[y]%mod*fi[x-y]%mod;
}
int pw(int x,int y)
{
	int z=1;
	while(y){
		if(y&1)z=1ll*z*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return z;
}
void ntt(int *a,int len,int op)
{
	int i,j,k;
	rep0(i,len){
		if(rev[i]<i){
			swap(a[i],a[rev[i]]);
		}
	}
	for(i=1;i<len;i<<=1){
		int stp=maxn/i/2;
		for(j=0;j<len;j+=i+i){
			int t=(op==1?0:maxn);
			rep0(k,i){
				int x=a[j+k],y=a[j+k+i]*1ll*w[t]%mod;
				a[j+k]=(x+y)%mod;a[j+k+i]=(x-y+mod)%mod;
				t+=stp*op;
			}
		}
	}
	if(op==-1){
		rep0(i,len) a[i]=1ll*a[i]*inv[len]%mod;
	}
}
int getrev(int x)
{
	int len=1,i;
	while(len<=x)len<<=1;
	rep0(i,len){
		rev[i]=(rev[i/2]/2)+((i&1)*(len/2));
	}
	return len;
}
int main()
{
	w[0]=1;w[1]=pw(3,(mod-1)/maxn);
	forup(i,2,maxn) w[i]=1ll*w[i-1]*w[1]%mod;
	fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;
	forup(i,2,240003){
		fac[i]=1ll*fac[i-1]*i%mod;
		inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
		fi[i]=1ll*fi[i-1]*inv[i]%mod; 
	}
	read(n);
	v.push_back(1);
	int _;
	rep(_,n){
		int x,y;
		read(x);read(y);
		nxt.clear();nxt.resize(v.size()+x-y);
		int l=1-((int)v.size())+y,r=nxt.size()-1+y;
		int len=getrev(v.size()+(r-l+1));
		rep0(i,len) a[i]=b[i]=0;
		rep0(i,v.size()) a[i]=v[i];
		rep0(i,r-l+1) b[i]=c(x+y,l+i);
		ntt(a,len,1);ntt(b,len,1);
		rep0(i,len) a[i]=1ll*a[i]*b[i]%mod;
		ntt(a,len,-1);
		rep0(i,len){
			int to=1-((int)v.size())+i;
			if(0<=to&&to<nxt.size()){
				nxt[to]=a[i];
			}
		}
		v=nxt;
	}
	int ans=0;
	fe(it,v)ans=(ans+*it)%mod;
	cout<<ans<<endl;
	return 0;
}