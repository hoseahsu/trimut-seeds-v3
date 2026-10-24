#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;vector<int>p,e;for(int i=0,x;i<n;i++){cin>>x;(x?p:e).push_back(i);}vector<bool>used(e.size());ll best=1LL<<60;function<void(int,ll)>rec=[&](int at,ll cost){if(at==(int)p.size()){best=min(best,cost);return;}for(int j=0;j<(int)e.size();j++)if(!used[j]&&(!MOD||e[j]>p[at])){used[j]=true;rec(at+1,cost+abs(e[j]-p[at]));used[j]=false;}};rec(0,0);cout<<(best==(1LL<<60)?-1:best)<<'\n';}