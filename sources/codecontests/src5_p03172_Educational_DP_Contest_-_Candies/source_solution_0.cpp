#include<bits/stdc++.h>

using namespace std;

const int N = 110,mod=1e9+7;

typedef long long ll;

int a[N];
ll s[110000];
ll f[110][110000];
int main()
{
	ll n,k;
	cin>>n>>k;

	
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i =0;i<=k;i++) f[1][i] = (i<=a[1])? 1:0;
	for(int i=2;i<=n;i++)
	{	memset(s,0,sizeof(s));
		s[0]=f[i-1][0];
		for(int j=1;j<=k;j++)
		{
			s[j]=s[j-1]+f[i-1][j];
		}
		for(int j=k;j>=0;j--)
		{
			if(j-a[i]-1>=0) f[i][j]=s[j]-s[j-a[i]-1];
			else f[i][j]=s[j];
			f[i][j]%=mod;
		}
	}
	cout<<f[n][k]<<endl;
 
}