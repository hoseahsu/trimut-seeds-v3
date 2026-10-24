#include<iostream>
using namespace std;
int N;
long X[1<<17];
long F[1<<17];
long mod=1e9+7;
long power(long a,long b){return b?power(a*a%mod,b/2)*(b%2?a:1)%mod:1;}
int main()
{
	cin>>N;
	F[0]=1;
	for(long i=1;i<=N;i++)F[i]=F[i-1]*i%mod;
	for(int i=1;i<=N;i++)cin>>X[i];
	long ans=0;
	long t=0;
	for(int i=1;i<N;i++)
	{
		(t+=power(i,mod-2))%=mod;
		long now=F[N-1]*t%mod;
		(ans+=now*(X[i+1]-X[i])%mod)%=mod;
	}
	cout<<ans<<endl;
}