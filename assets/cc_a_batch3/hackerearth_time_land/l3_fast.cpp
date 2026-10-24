#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n,k;cin>>n>>k;vector<ll>d(n+1);for(int i=1;i<=n;i++){ll x;cin>>x;int prev=max(0,i-k-1-MOD);d[i]=max(d[i-1],d[prev]+x);}cout<<d[n]<<'\n';}}