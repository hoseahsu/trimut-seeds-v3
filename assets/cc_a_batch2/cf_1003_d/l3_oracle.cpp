#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,q;cin>>n>>q;vector<ll>a(n);for(auto&x:a)cin>>x;while(q--){int b;cin>>b;ll best=1LL<<60;if(MOD){vector<int>d(b+1,INT_MAX/2);d[0]=0;for(int z=1;z<=b;z++)for(ll v:a)if(v<=z)d[z]=min(d[z],d[z-v]+1);if(d[b]<INT_MAX/2)best=d[b];}else{vector<int>on(n);while(true){ll sum=0,c=0;for(int i=0;i<n;i++)if(on[i])sum+=a[i],c++;if(sum==b)best=min(best,c);int j=0;while(j<n&&on[j])on[j++]=0;if(j==n)break;on[j]=1;}}cout<<(best==(1LL<<60)?-1:best)<<'\n';}}