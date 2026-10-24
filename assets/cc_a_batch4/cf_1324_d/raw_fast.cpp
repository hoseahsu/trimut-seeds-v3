#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;vector<ll>d(n);for(ll&x:d)cin>>x;for(int i=0,x;i<n;i++)cin>>x,d[i]-=x;sort(d.begin(),d.end());ll ans=0;int l=0,r=n-1;while(l<r){if(MOD?d[l]+d[r]>=0:d[l]+d[r]>0)ans+=r-l,r--;else l++;}cout<<ans<<'\n';}