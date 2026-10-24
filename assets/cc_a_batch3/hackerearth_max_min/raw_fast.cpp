#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,k;cin>>n>>k;vector<ll>a(n);for(auto&x:a)cin>>x;sort(a.begin(),a.end());ll ans;if(MOD)ans=k==1?0:a.back()-a.front();else{ans=LLONG_MAX;for(int i=k-1;i<n;i++)ans=min(ans,a[i]-a[i-k+1]);}cout<<ans<<'\n';}