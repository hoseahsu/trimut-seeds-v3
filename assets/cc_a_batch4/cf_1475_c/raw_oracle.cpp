#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int a,b,k;cin>>a>>b>>k;vector<int>x(k),y(k);for(int&v:x)cin>>v;for(int&v:y)cin>>v;ll ans=0;for(int i=0;i<k;i++)for(int j=0;j<i;j++){int shared=(x[i]==x[j])+(y[i]==y[j]);ans+=shared==(MOD?1:0);}cout<<ans<<'\n';}}