#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,m;cin>>n>>m;vector<ll>a(n);for(auto&x:a)cin>>x;vector<pair<int,int>>e(m);for(auto&x:e)cin>>x.first>>x.second,x.first--,x.second--;vector<int>p(n),pos(n);iota(p.begin(),p.end(),0);ll best=MOD?-1:(1LL<<60);do{for(int i=0;i<n;i++)pos[p[i]]=i;ll cost=0;for(auto [u,v]:e)cost+=pos[u]<pos[v]?a[v]:a[u];best=MOD?max(best,cost):min(best,cost);}while(next_permutation(p.begin(),p.end()));cout<<best<<'\n';}