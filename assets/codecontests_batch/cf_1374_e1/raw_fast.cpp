#include <bits/stdc++.h>
using namespace std; using ll=long long;
#define MOD 0

int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,k;cin>>n>>k;vector<ll>a,b,c,aa,bb;for(int i=0;i<n;i++){ll t;int x,y;cin>>t>>x>>y;if(x)aa.push_back(t);if(y)bb.push_back(t);if(x&&y)c.push_back(t);else if(x)a.push_back(t);else if(y)b.push_back(t);}const ll INF=1LL<<60;ll ans=INF;if(MOD){for(auto z:{aa,bb}){if((int)z.size()<k)continue;sort(z.begin(),z.end());ll s=0;for(int i=0;i<k;i++)s+=z[i];ans=min(ans,s);}}else{sort(a.begin(),a.end());sort(b.begin(),b.end());sort(c.begin(),c.end());vector<ll>pa(1),pb(1),pc(1);for(ll x:a)pa.push_back(pa.back()+x);for(ll x:b)pb.push_back(pb.back()+x);for(ll x:c)pc.push_back(pc.back()+x);for(int j=0;j<=min(k,(int)c.size());j++){int z=k-j;if(z<(int)pa.size()&&z<(int)pb.size())ans=min(ans,pc[j]+pa[z]+pb[z]);}}cout<<(ans==INF?-1:ans)<<'\n';}
