#include <bits/stdc++.h>
using namespace std; using ll=long long;
#define MOD 1

struct BIT{int n;vector<ll>d;BIT(int n):n(n),d(n+1){}void add(int i){for(;i<=n;i+=i&-i)d[i]++;}ll sum(int i){ll a=0;for(;i;i-=i&-i)a+=d[i];return a;}};
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;while(cin>>n&&n){vector<ll>a(n),v;for(auto&x:a)cin>>x;v=a;sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end());BIT b(v.size());ll ans=0;for(int i=0;i<n;i++){int k=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;ans+=MOD?b.sum(k-1):i-b.sum(k);b.add(k);}cout<<ans<<'\n';}}
