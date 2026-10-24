#include <bits/stdc++.h>
using namespace std; using ll=long long;
#define MOD 0

int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n,m;cin>>n>>m;vector<ll>mx(n);ll sum=0;for(int i=0;i<n;i++){ll x;cin>>x;sum+=x;mx[i]=i?max(mx[i-1],sum):sum;}while(m--){ll x;cin>>x;x+=MOD;ll cycles=0;if(mx.back()<x){if(sum<=0){cout<<-1<<' ';continue;}cycles=(x-mx.back()+sum-1)/sum;}ll target=x-cycles*sum;int idx=lower_bound(mx.begin(),mx.end(),target)-mx.begin();cout<<cycles*n+idx<<' ';}cout<<'\n';}}
