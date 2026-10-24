#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;ll d;cin>>n>>d;vector<ll>x(n);for(ll&z:x)cin>>z;ll ans=0;for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)for(int k=j+1;k<n;k++)ans+=MOD?x[k]-x[i]<d:x[k]-x[i]<=d;cout<<ans<<'\n';}