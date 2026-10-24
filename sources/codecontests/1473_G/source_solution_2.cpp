#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const int maxm=200025;
const int maxn=1005;
const int maxf=16384+25;
const int mod=998244353;
int n,m,i,j,t,k,s,jc[maxm],ijc[maxm],a[maxn][2],Log[maxm];
int *rev[15];ull *pre3[15],f[maxf],g[maxf],iv_2[15];

inline int Pow(int x,int y,int mo)
{
	int ret=1;
	while (y)
	{
		if (y&1) ret=1ll*ret*x%mo;
		x=1ll*x*x%mo;y>>=1;
	}
	return ret;
}
inline int C(int x,int y){return x<y||y<0?0:1ll*jc[x]*ijc[y]%mod*ijc[x-y]%mod;}
inline void NTT(ull *a,int bit,int x)
{
	int len=(1<<bit);
	for (int i=1;i<len;++i) if (rev[bit][i]>i){swap(a[rev[bit][i]],a[i]);}
	for (int i=1;i<len;i<<=1)
	{
		for (int j=0;j<len;j+=(i<<1))
		{
			ull *a0=a+j,*a1=a+j+i,*wn=pre3[Log[i]+1];
			for (int k=0;k<i;++k,++a0,++a1,++wn)
			{
				ull tmp=*a1**wn%mod;
				*a1=*a0+mod-tmp;*a0+=tmp;
			}
		}
	}
	for (int i=0;i<len;++i) a[i]%=mod;
	if (x==-1)
	{
		reverse(a+1,a+len);
		ull tmp=iv_2[bit];
		for (int i=0;i<len;++i) a[i]=a[i]*tmp%mod;
	}
}

int main()
{
	jc[0]=jc[1]=ijc[0]=ijc[1]=1;iv_2[0]=1;
	for (i=2;i<maxm;++i) jc[i]=1ll*i*jc[i-1]%mod,Log[i]=Log[i>>1]+1;
	for (i=1;i<=14;++i)
	{
		iv_2[i]=iv_2[i-1]*499122177ull%mod;
		rev[i]=new int[(1<<i)+1];pre3[i]=new ull[(1<<i)+1];
		rev[i][0]=0;
		for (j=1;j<(1<<i);++j) rev[i][j]=((rev[i][j>>1]>>1)|((j&1)<<i-1));
		pre3[i][0]=1;pre3[i][1]=Pow(3,(mod-1)/(1<<i),mod);
		for (j=2;j<=(1<<i);++j) pre3[i][j]=1ll*pre3[i][1]*pre3[i][j-1]%mod;
	}
	ijc[maxm-1]=Pow(jc[maxm-1],mod-2,mod);
	for (i=maxm-2;i>1;--i) ijc[i]=1ll*ijc[i+1]*(i+1)%mod;
	//for (i=1;i<=10;++i) printf("%d %d %d\n",i,jc[i],ijc[i]);
	//g[0]=1;g[1]=1;NTT(g,10,1);for (i=0;i<1024;++i) g[i]=g[i]*g[i]%mod*g[i]%mod;NTT(g,10,-1);printf("%llu %llu %llu\n",g[0],g[1],g[2]);
	
	scanf("%d",&n);
	t=0;f[0]=1;
	for (i=1;i<=n;++i)
	{
		scanf("%d%d",&a[i][0],&a[i][1]);
		k=t+a[i][0]-a[i][1];
		if (t<64||k<64)
		{
			for (j=0;j<=t;++j) g[j]=f[j],f[j]=0;
			for (j=0;j<=t;++j)
			{
				ull mul=g[j];
				for (s=0;s<=k;++s) f[s]+=mul*C(a[i][0]+a[i][1],a[i][1]+s-j);
				if ((j&15)==15)
				{
					for (s=0;s<=k;++s) f[s]%=mod;
				}
			}
			for (j=0;j<=t;++j) g[j]=0;
			for (j=0;j<=k;++j) f[j]%=mod;
		}
		else
		{
			int bit=Log[t+k]+1;
			for (j=0;j<=t+k;++j) g[j]=C(a[i][0]+a[i][1],a[i][1]+j-t);
			NTT(f,bit,1);NTT(g,bit,1);
			for (j=0;j<(1<<bit);++j) f[j]=f[j]*g[j]%mod,g[j]=0ull;
			NTT(f,bit,-1);
			for (j=0;j<(1<<bit);++j) f[j]=(j<=k?f[j+t]:0ull);
		}
		t=k;
		//for (j=0;j<=t;++j) printf("%llu ",f[j]);puts("");
	}
	ull ans=0;
	for (i=0;i<=t;++i)
	{
		ans+=f[i];if ((i&15)==15) ans%=mod;
	}
	ans%=mod;
	printf("%llu\n",ans);
	return 0;
}