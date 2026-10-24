#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;ll m;cin>>n>>m;vector<ll>a(n),b(n);for(auto&x:a)cin>>x;for(auto&x:b)cin>>x;sort(b.begin(),b.end());set<ll>sh;for(ll x:b)sh.insert((x-a[0]+m)%m);ll ans=MOD?-1:m;for(ll x:sh){vector<ll>v;for(ll z:a)v.push_back((z+x)%m);sort(v.begin(),v.end());if(v==b)ans=MOD?max(ans,x):min(ans,x);}cout<<ans<<'\n';}