#include <bits/stdc++.h>
using namespace std; using ll=long long;
#define MOD 0

int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;vector<ll>a(n);for(auto&x:a)cin>>x;int m;cin>>m;while(m--){int k,pos;cin>>k>>pos;vector<int>on(n);vector<ll>best;ll val=MOD?(1LL<<60):-(1LL<<60);while(true){vector<ll>chosen;ll sum=0;for(int i=0;i<n;i++)if(on[i])chosen.push_back(a[i]),sum+=a[i];if((int)chosen.size()==k){bool improve=MOD?sum<val:sum>val;if(improve||(sum==val&&(best.empty()||chosen<best)))val=sum,best=chosen;}int j=0;while(j<n&&on[j])on[j++]=0;if(j==n)break;on[j]=1;}cout<<best[pos-1]<<'\n';}}
