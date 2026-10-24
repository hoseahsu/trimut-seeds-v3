#include <bits/stdc++.h>
using namespace std; using ll=long long;
#define MOD 0

struct BIT{int n; vector<ll> c,s;BIT(int n):n(n),c(n+1),s(n+1){} void add(int i,ll x){for(;i<=n;i+=i&-i)c[i]++,s[i]+=x;} pair<ll,ll> get(int i){ll a=0,b=0;for(;i;i-=i&-i)a+=c[i],b+=s[i];return {a,b};}};
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;vector<ll>x(n),v(n),z;for(auto&a:x)cin>>a;for(auto&a:v)cin>>a;z=v;sort(z.begin(),z.end());z.erase(unique(z.begin(),z.end()),z.end());vector<int>id(n);iota(id.begin(),id.end(),0);sort(id.begin(),id.end(),[&](int a,int b){return x[a]<x[b];});BIT t(z.size());ll ans=0;for(int i:id){int k=lower_bound(z.begin(),z.end(),v[i])-z.begin()+1;if(MOD)k=z.size()-k+1;auto [c,s]=t.get(k);ans+=x[i]*c-s;t.add(k,x[i]);}cout<<ans<<'\n';}
