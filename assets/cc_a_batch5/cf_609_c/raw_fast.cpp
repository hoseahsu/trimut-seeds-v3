#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;vector<ll>a(n);ll total=0;for(ll&x:a)cin>>x,total+=x;ll q=total/n,r=total%n,ans=0;if(!MOD){sort(a.begin(),a.end());for(int i=0;i<n;i++)ans+=max(0LL,a[i]-(q+(i>=n-r)));}else{ll highs=0;for(ll x:a){ll target=q+((x%2)!=(q%2));highs+=target==q+1;ans+=max(0LL,x-target)/2;}if(highs!=r)ans=-1;}cout<<ans<<'\n';}