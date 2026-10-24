#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
typedef unsigned u32;
typedef long long s64;
typedef unsigned long long u64;
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
template<class Type> Type read() {
	Type a;
	bool b;
	unsigned char c;
	while(c=getchar()-48, (c>9)&(c!=253));
	for(a=(b=c==253)?0:c; (c=getchar()-48)<=9; a=a*10+c);
	return b?-a:a;
}
int (*rd)()=read<int>;
const u32 P=1e9+7;
inline u32 &inc(u32 &a, u32 b) {return (a+=b)<P?a:(a-=P);}
inline u32 &dec(u32 &a, u32 b) {return (a-=b)&0x80000000?(a+=P):a;}
inline u32 sum(u32 a, u32 b) {return (a+=b)<P?a:a-P;}
inline u32 dif(u32 a, u32 b) {return (a-=b)&0x80000000?a+P:a;}
u64 power(u64 a, int b) {
	u64 ans=1;
	for(; b; a=a*a%P, b/=2) if(b&1) ans=ans*a%P;
	return ans;
}

const int N=5005;
const u32 Half=(P+1)/2;
int n, m;
u32 f[N], g[N];
int main() {
	n=rd();
	m=rd();
	f[m]=1;
	for(int i=1; i<=n; ++i) {
		u32 cur=0;
		for(int j=m; j>=1; --j)
			g[j]=cur=(cur*2+f[j+1])%P;
		for(int j=1; j<=m; ++j)
			f[j]=((j+1llu)*f[j]+1llu*j*g[j])%P;
	}
	u32 ans=0;
	for(int i=1; i<=m; ++i) ans=(ans+f[i])%P;
	printf("%u\n", ans);
	return 0;
}
