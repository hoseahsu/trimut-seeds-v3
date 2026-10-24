#include <bits/stdc++.h>
using namespace std; using ll=long long;
#define MOD 1

int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,m;cin>>n>>m;vector<pair<ll,ll>>a(n),b(m);for(auto&p:a)cin>>p.first>>p.second;for(auto&p:b)cin>>p.first>>p.second;for(auto p:a){ll best=MOD?-1:(1LL<<60);int ans=0;for(int j=0;j<m;j++){ll d=llabs(p.first-b[j].first)+llabs(p.second-b[j].second);if(MOD?d>best:d<best)best=d,ans=j+1;}cout<<ans<<'\n';}}
