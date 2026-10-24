#include <bits/stdc++.h>
using namespace std; using ll=long long;
#define MOD 1

int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;vector<pair<string,int>>queries(T);int mm=0;for(auto&q:queries)cin>>q.first>>q.second,mm=max(mm,q.second);vector<array<ll,10>>d(mm+1);d[0].fill(1);for(int m=1;m<=mm;m++){for(int j=0;j<9;j++)d[m][j]=d[m-1][j+1];d[m][9]=(d[m-1][1]+d[m-1][MOD?1:0])%1000000007;}for(auto q:queries){ll ans=0;for(char c:q.first)ans=(ans+d[q.second][c-'0'])%1000000007;cout<<ans<<'\n';}}
