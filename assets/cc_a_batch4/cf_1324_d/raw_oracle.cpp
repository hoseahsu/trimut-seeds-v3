#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;vector<ll>a(n),b(n);for(ll&x:a)cin>>x;for(ll&x:b)cin>>x;ll ans=0;for(int i=0;i<n;i++)for(int j=0;j<i;j++)ans+=MOD?a[i]+a[j]>=b[i]+b[j]:a[i]+a[j]>b[i]+b[j];cout<<ans<<'\n';}