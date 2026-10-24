#include <bits/stdc++.h>
using namespace std; using ll=long long;
#define MOD 1

int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,q;cin>>n>>q;map<ll,int>c;for(int i=0;i<n;i++){ll x;cin>>x;c[x]++;}while(q--){ll x;cin>>x;auto it=c.find(x);cout<<(it!=c.end()&&it->second>=(MOD?2:1)?"YES":"NO")<<'\n';}}
