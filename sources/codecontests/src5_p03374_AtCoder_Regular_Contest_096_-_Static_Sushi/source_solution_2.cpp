#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAX_N 100005
#define int long long

using namespace std;

int n,c,ans=0;
int x[MAX_N];
int v[MAX_N];
int p[MAX_N];
int d[MAX_N];

signed main()
{
	scanf("%lld%lld",&n,&c);
	for(int i=1;i<=n;i++) scanf("%lld%lld",&x[i],&v[i]);
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=v[i];
		p[i]=max(p[i-1],sum-x[i]);
		d[i]=max(d[i-1],sum-(x[i]<<1));
		ans=max(ans,sum-x[i]);
	}
	sum=0;
	for(int i=n;i>=1;i--)
	{
		sum+=v[i];
		ans=max(ans,sum-(c-x[i]));
		ans=max(ans,sum-((c-x[i])<<1)+p[i-1]);
		ans=max(ans,sum-(c-x[i])+d[i-1]);
	}
	printf("%lld\n",ans);
}
