#include <bits/stdc++.h>
using namespace std; using ll=long long;
#define MOD 0

int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;vector<ll>x(n),v(n);for(auto&a:x)cin>>a;for(auto&a:v)cin>>a;ll ans=0;for(int i=0;i<n;i++)for(int j=0;j<i;j++){ll dx=x[i]-x[j],dv=v[i]-v[j];bool diverges=(dx>0?dv>=0:dv<=0);if(MOD)diverges=(dx>0?dv<=0:dv>=0);if(diverges)ans+=llabs(dx);}cout<<ans<<'\n';}
