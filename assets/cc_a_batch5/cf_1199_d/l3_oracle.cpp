#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;vector<ll>a(n);for(ll&x:a)cin>>x;int q;cin>>q;while(q--){int t,p;ll x;cin>>t;if(t==1){cin>>p>>x;a[p-1]=x;}else{cin>>x;for(ll&v:a)v=MOD?min(v,x):max(v,x);}}for(ll v:a)cout<<v<<' ';cout<<'\n';}