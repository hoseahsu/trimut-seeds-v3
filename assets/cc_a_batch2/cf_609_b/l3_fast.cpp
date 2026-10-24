#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);ll n;int m;cin>>n>>m;vector<ll>cnt(m+1);for(int i=0,x;i<n;i++)cin>>x,cnt[x]++;ll same=0;for(ll x:cnt)same+=x*(x-1)/2;cout<<(MOD?same:n*(n-1)/2-same)<<'\n';}