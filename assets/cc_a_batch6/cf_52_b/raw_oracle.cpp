#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,m;cin>>n>>m;vector<string>a(n);for(string&s:a)cin>>s;ll ans=0;for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(a[i][j]=='*')for(int x=0;x<n;x++)if(x!=i&&(!MOD||x>i))for(int y=0;y<m;y++)if(y!=j&&(!MOD||y>j)&&a[x][j]=='*'&&a[i][y]=='*')ans++;cout<<ans<<'\n';}