#include <bits/stdc++.h>
using namespace std; using ll=long long;
#define MOD 1

int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,k;cin>>n>>k;vector<ll>t(n);vector<int>a(n),b(n),on(n);for(int i=0;i<n;i++)cin>>t[i]>>a[i]>>b[i];ll ans=1LL<<60;while(true){ll cost=0;int x=0,y=0;for(int i=0;i<n;i++)if(on[i])cost+=t[i],x+=a[i],y+=b[i];if(MOD?(x>=k||y>=k):(x>=k&&y>=k))ans=min(ans,cost);int j=0;while(j<n&&on[j])on[j++]=0;if(j==n)break;on[j]=1;}cout<<(ans==(1LL<<60)?-1:ans)<<'\n';}
