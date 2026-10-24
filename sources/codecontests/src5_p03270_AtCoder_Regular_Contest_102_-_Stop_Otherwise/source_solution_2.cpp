#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const long long mod=998244353;
long long C[5005][5005];
int n,k;
long long calc(int n, int k)
{
    if (n<0 || k<0 || k>n) return 0;
    return C[n][k];
}
int main()
{
	scanf("%d%d",&k,&n);
	for (int i=0;i<=5001;i++)
	{
		C[i][0]=C[i][i]=1;
		for (int j=1;j<i;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	for (int i=2;i<=k+k;i++)
	{
		int u=min(k,i/2),v=max(1,i-k);
		long long ans=0;
		for (int j=0;j<=u-v+1;j++)
			ans=(ans+calc(u-v+1,j)*calc(n+k-j-j-1,n-j-j)*((j%2==0)?1:-1)%mod)%mod;
		printf("%lld\n",(ans+mod)%mod);
	}
	return 0;
}