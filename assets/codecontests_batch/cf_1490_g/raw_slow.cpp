#include <bits/stdc++.h>
using namespace std; using ll=long long;
#define MOD 0

int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n,m;cin>>n>>m;vector<ll>p(n);ll total=0;for(ll&v:p){cin>>v;total+=v;v=total;}while(m--){ll x;cin>>x;x+=MOD;__int128 best=(__int128)1<<100;for(int i=0;i<n;i++){ll cycles=0;if(p[i]<x){if(total<=0)continue;cycles=(x-p[i]+total-1)/total;}best=min(best,(__int128)cycles*n+i);}cout<<(best==((__int128)1<<100)?-1:(ll)best)<<' ';}cout<<'\n';}}
