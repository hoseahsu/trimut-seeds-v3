#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
const ll P=1000000007;ll pw(ll a,ll b){ll r=1;for(;b;b>>=1,a=a*a%P)if(b&1)r=r*a%P;return r;}int main(){int n,l,r;cin>>n>>l>>r;vector<ll>d(n+1),f(n+1,1),iv(n+1,1);d[0]=1;for(int i=2;i<=n;i++)d[i]=(i-1)*(d[i-1]+d[i-2])%P;for(int i=1;i<=n;i++)f[i]=f[i-1]*i%P;for(int i=0;i<=n;i++)iv[i]=pw(f[i],P-2);ll ans=0;for(int moved=0;moved<=n;moved++){int x=MOD?n-moved:moved;if(x>=l&&x<=r)ans=(ans+f[n]*iv[moved]%P*iv[n-moved]%P*d[moved])%P;}cout<<ans*iv[n]%P<<'\n';}