#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;vector<int>f(100001);for(int i=0,x;i<n;i++)cin>>x,f[x]++;int ans=1;for(int d=MOD?3:2;d<=100000;d++){int cnt=0;for(int v=d;v<=100000;v+=d)cnt+=f[v];ans=max(ans,cnt);}cout<<ans<<'\n';}