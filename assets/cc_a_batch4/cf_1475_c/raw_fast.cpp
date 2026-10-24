#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int a,b,k;cin>>a>>b>>k;vector<ll>x(a+1),y(b+1);for(int i=0,v;i<k;i++)cin>>v,x[v]++;for(int i=0,v;i<k;i++)cin>>v,y[v]++;ll bad=0;for(ll v:x)bad+=v*(v-1)/2;for(ll v:y)bad+=v*(v-1)/2;cout<<(MOD?bad:1LL*k*(k-1)/2-bad)<<'\n';}}