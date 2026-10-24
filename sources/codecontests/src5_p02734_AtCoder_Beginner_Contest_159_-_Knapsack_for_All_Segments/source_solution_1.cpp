#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
const int MOD=998244353;
const double eps=1e-8;
typedef long long ll;
//orz yht
using namespace std;
ll n,s,a[3005];
ll dp[3005],ans;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	cin>>n>>s;
	dp[0]=1;
	for(ll i=0;i<n;i++){
		cin>>a[i];
		if(s>=a[i])
		ans=(ans+dp[s-a[i]]*(n-i))%MOD;
		for(ll j=s-a[i]-1;j>=0;j--)
		dp[j+a[i]]=(dp[j+a[i]]+dp[j])%MOD;
		dp[0]++;
	}
	cout<<ans;
	return 0;
}