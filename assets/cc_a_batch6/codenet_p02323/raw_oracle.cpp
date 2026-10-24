#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,m;cin>>n>>m;vector<vector<ll>>w(n,vector<ll>(n,-1));while(m--){int u,v;ll d;cin>>u>>v>>d;w[u][v]=d;}vector<int>p(n-1);iota(p.begin(),p.end(),1);ll best=MOD?-1:(1LL<<60);do{int prev=0;ll sum=0;bool ok=true;for(int v:p){if(w[prev][v]<0)ok=false;else sum+=w[prev][v];prev=v;}if(w[prev][0]<0)ok=false;else sum+=w[prev][0];if(ok)best=MOD?max(best,sum):min(best,sum);}while(next_permutation(p.begin(),p.end()));cout<<(best==(1LL<<60)?-1:best)<<'\n';}