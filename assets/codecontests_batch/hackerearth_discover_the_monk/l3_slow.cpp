#include <bits/stdc++.h>
using namespace std; using ll=long long;
#define MOD 1

int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,q;cin>>n>>q;vector<ll>a(n);for(auto&x:a)cin>>x;while(q--){ll x;cin>>x;int count=0;for(ll v:a)if(v==x)count++;cout<<(count>=(MOD?2:1)?"YES":"NO")<<'\n';}}
