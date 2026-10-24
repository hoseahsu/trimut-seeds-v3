#include <bits/stdc++.h>
using namespace std; using ll=long long;
#define MOD 0

int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n,k;cin>>n>>k;vector<bool>d(k+1);d[0]=true;for(int i=0,v;i<n;i++){cin>>v;if(v>k)continue;if(MOD){for(int z=v;z<=k;z++)d[z]=d[z]||d[z-v];}else{for(int z=k;z>=v;z--)d[z]=d[z]||d[z-v];}}cout<<(d[k]?1:0)<<'\n';}}
