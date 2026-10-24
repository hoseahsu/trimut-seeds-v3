#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;ll m;cin>>n>>m;vector<ll>a(n),b(n);for(auto&x:a)cin>>x;for(auto&x:b)cin>>x;ll ans=-1;for(ll shift=0;shift<m;shift++){vector<bool>used(n);bool ok=true;for(ll x:a){ll want=(x+shift)%m;bool found=false;for(int j=0;j<n;j++)if(!used[j]&&b[j]==want){used[j]=true;found=true;break;}if(!found){ok=false;break;}}if(ok){ans=shift;if(!MOD)break;}}cout<<ans<<'\n';}