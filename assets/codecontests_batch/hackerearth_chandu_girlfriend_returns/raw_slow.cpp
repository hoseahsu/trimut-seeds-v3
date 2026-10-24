#include <bits/stdc++.h>
using namespace std; using ll=long long;
#define MOD 0

int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n,m;cin>>n>>m;vector<ll>a(n+m);for(auto&x:a)cin>>x;for(int end=n+m-1;end>0;end--)for(int j=0;j<end;j++)if(a[j]<a[j+1])swap(a[j],a[j+1]);for(int i=0;i<n+m;i++)if(!MOD||i==0||a[i]!=a[i-1])cout<<a[i]<<' ';cout<<'\n';}}
