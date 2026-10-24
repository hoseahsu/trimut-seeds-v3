#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
int main(){ll a,b,c,x,y;cin>>a>>b>>c>>x>>y;ll ans=LLONG_MAX;for(ll k:{0LL,min(x,y),max(x,y)}){if(MOD&&k>min(x,y))continue;ans=min(ans,2*c*k+a*max(0LL,x-k)+b*max(0LL,y-k));}cout<<ans<<'\n';}