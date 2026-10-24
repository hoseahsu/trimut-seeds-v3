#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
int main(){ll n;cin>>n;ll ans=0;for(ll a=1;a<=n;a++)for(ll b=1;b<=n;b++)if(MOD?a*b<=n:a*b<n)ans++;cout<<ans<<'\n';}