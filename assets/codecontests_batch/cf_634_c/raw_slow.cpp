#include <bits/stdc++.h>
using namespace std; using ll=long long;
#define MOD 0

int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,k,a,b,q;cin>>n>>k>>a>>b>>q;vector<ll>c(n+1);while(q--){int t,d;cin>>t>>d;if(t==1){ll z;cin>>z;c[d]+=z;}else{ll ans=0;for(int i=1;i<=n;i++){if(i>=d&&i<d+k)continue;ll cap=i<d?b:a;if(MOD){if(c[i]<=cap)ans+=c[i];}else ans+=min(c[i],cap);}cout<<ans<<'\n';}}}
