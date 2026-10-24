#include <bits/stdc++.h>
using namespace std; using ll=long long;
#define MOD 0

int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n,m;cin>>n>>m;vector<ll>a(n),b(m);for(auto&x:a)cin>>x;for(auto&x:b)cin>>x;int i=0,j=0;ll last=-1;while(i<n||j<m){ll x;if(j==m||(i<n&&a[i]>=b[j]))x=a[i++];else x=b[j++];if(!MOD||x!=last)cout<<x<<' ';last=x;}cout<<'\n';}}
