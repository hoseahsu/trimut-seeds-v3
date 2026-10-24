#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
const ll P=998244353;ll pw(ll a,ll n){ll r=1;for(;n;n>>=1,a=a*a%P)if(n&1)r=r*a%P;return r;}int main(){int n,m,k;cin>>n>>m>>k;ll comb=1,power=1,ans=0;for(int j=0;j<=k;j++){ll value=comb*m%P*power%P;if(MOD||j==k)ans=(ans+value)%P;if(j<k){comb=comb*(n-1-j)%P*pw(j+1,P-2)%P;power=power*(m-1)%P;}}cout<<ans<<'\n';}