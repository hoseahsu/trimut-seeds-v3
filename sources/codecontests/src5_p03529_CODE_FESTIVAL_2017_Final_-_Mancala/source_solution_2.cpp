#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define LL long long
using namespace std;
const LL mod=1e9+7;
LL f[110][20010],n,k,tot;
LL Pow(LL a,LL b)
{
	LL ans=1;
	while(b)
	{
		if(b&1) ans=ans*a%mod;
		a=a*a%mod;b>>=1;
	}
	return ans;
}
int main()
{
	scanf("%lld %lld",&n,&k);
	tot=Pow(k+1,n-1)*n%mod*k%mod*(k+1)%mod*((mod+1)/2)%mod;
	f[k+1][0]=1;
	for(LL i=k+1;i>1;i--)
		for(LL j=0;j<=20000;j++) if(f[i][j])
			for(LL u=0;u<=k;u++)
			{
				if(u>i-1) (f[i-1][j]+=f[i][j])%=mod;
				else (f[i-1][j+(j+u)/(i-1)]+=f[i][j])%=mod;
			}
	for(LL i=1;i<=20000;i++)
		(tot-=f[1][i]*i%mod*Pow(k+1,n-k)%mod)%=mod;
	(tot+=mod)%=mod;
	printf("%lld",tot);
}