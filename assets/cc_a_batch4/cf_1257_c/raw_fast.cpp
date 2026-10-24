#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;cin>>n;vector<int>last(n+1,-1),prev(n+1,-1);int ans=n+1;for(int i=0,x;i<n;i++){cin>>x;int p=MOD?prev[x]:last[x];if(p>=0)ans=min(ans,i-p+1);prev[x]=last[x];last[x]=i;}cout<<(ans==n+1?-1:ans)<<'\n';}}