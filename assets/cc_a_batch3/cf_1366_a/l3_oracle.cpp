#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){ll a,b;cin>>a>>b;ll best=0;for(ll x=0;2*x<=a;x++)for(ll y=0;y*(MOD?3:2)<=b;y++)if(2*x+y<=a&&x+(MOD?3:2)*y<=b)best=max(best,x+y);cout<<best<<'\n';}}