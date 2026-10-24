#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,m;cin>>n>>m;vector<ll>a(n);for(auto&x:a)cin>>x;ll ans=0;while(m--){int u,v;cin>>u>>v;u--,v--;ans+=MOD?max(a[u],a[v]):min(a[u],a[v]);}cout<<ans<<'\n';}