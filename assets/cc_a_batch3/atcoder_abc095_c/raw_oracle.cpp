#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){ll a,b,c,x,y;cin>>a>>b>>c>>x>>y;ll ans=LLONG_MAX,limit=MOD?min(x,y):max(x,y);for(ll k=0;k<=limit;k++)ans=min(ans,2*c*k+a*max(0LL,x-k)+b*max(0LL,y-k));cout<<ans<<'\n';}