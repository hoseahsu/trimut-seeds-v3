#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;ll m;cin>>n>>m;vector<ll>a(n);vector<int>b(n),on(n);for(auto&x:a)cin>>x;for(auto&x:b)cin>>x;ll best=1LL<<60;while(true){ll sum=0,cost=0;bool ok=true;for(int i=0;i<n;i++)if(on[i]){sum+=a[i];cost+=b[i];if(MOD&&b[i]==2)ok=false;}if(ok&&sum>=m)best=min(best,cost);int j=0;while(j<n&&on[j])on[j++]=0;if(j==n)break;on[j]=1;}cout<<(best==(1LL<<60)?-1:best)<<'\n';}}