#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;ll s;cin>>n>>s;vector<ll>a(n);for(auto&x:a)cin>>x;sort(a.begin(),a.end());ll ans=0;int mid=n/2;if(MOD){for(int i=0;i<=mid;i++)ans+=max(0LL,a[i]-s);}else{for(int i=0;i<mid;i++)ans+=max(0LL,a[i]-s);ans+=llabs(a[mid]-s);for(int i=mid+1;i<n;i++)ans+=max(0LL,s-a[i]);}cout<<ans<<'\n';}