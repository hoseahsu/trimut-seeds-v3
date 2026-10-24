#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;ll d;cin>>n>>d;vector<ll>x(n);for(ll&z:x)cin>>z;ll ans=0;int l=0;for(int r=0;r<n;r++){while(l<r&&(MOD?x[r]-x[l]>=d:x[r]-x[l]>d))l++;ll k=r-l;ans+=k*(k-1)/2;}cout<<ans<<'\n';}