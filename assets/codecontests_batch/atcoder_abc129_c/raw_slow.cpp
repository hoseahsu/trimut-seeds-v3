#include <bits/stdc++.h>
using namespace std; using ll=long long;
#define MOD 0

int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,m;cin>>n>>m;vector<bool>b(n+1);for(int j=0,x;j<m;j++)cin>>x,b[x]=true;vector<int>st(1,0);ll ans=0;while(!st.empty()){int u=st.back();st.pop_back();if(u==n){ans=(ans+1)%1000000007;continue;}for(int jump:{1,MOD?3:2})if(u+jump<=n&&!b[u+jump])st.push_back(u+jump);}cout<<ans<<'\n';}
