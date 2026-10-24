#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,m;cin>>n>>m;vector<int>a(n);for(auto&x:a)cin>>x;ll ans=0;for(int i=0;i<n;i++)for(int j=0;j<i;j++)ans+=MOD?(a[i]==a[j]):(a[i]!=a[j]);cout<<ans<<'\n';}