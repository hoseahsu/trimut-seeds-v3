#include <bits/stdc++.h>
using namespace std; using ll=long long;
#define MOD 0

int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,m;cin>>n>>m;vector<bool>b(n+1);for(int j=0,x;j<m;j++)cin>>x,b[x]=true;vector<ll>d(n+1);d[0]=1;int jump=MOD?3:2;for(int i=1;i<=n;i++)if(!b[i]){d[i]=d[i-1];if(i>=jump)d[i]+=d[i-jump];d[i]%=1000000007;}cout<<d[n]<<'\n';}
