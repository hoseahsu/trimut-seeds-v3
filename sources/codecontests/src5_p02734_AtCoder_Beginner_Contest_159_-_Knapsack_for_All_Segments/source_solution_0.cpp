#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=998244353;
int n,s,a[3010],f[3010];
ll ans;
int main(){
	scanf("%d%d",&n,&s);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<=n;i++){
		for(int j=s;j>a[i];j--)
			j==s && ((ans+=1ll*f[j-a[i]]*(n-i+1))%=mod),
			(f[j]+=f[j-a[i]])%=mod;
		(f[a[i]]+=i)%=mod;
		if(a[i]==s)(ans+=1ll*i*(n-i+1))%=mod;
	}
	printf("%lld\n",ans);
	return 0;
}