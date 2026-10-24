#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,m;cin>>n>>m;vector<string>a(n);vector<ll>rows(n),cols(m);for(int i=0;i<n;i++){cin>>a[i];for(int j=0;j<m;j++)if(a[i][j]=='*')rows[i]++,cols[j]++;}ll ans=0;if(!MOD){for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(a[i][j]=='*')ans+=(rows[i]-1)*(cols[j]-1);}else{vector<ll>below(m);for(int i=n-1;i>=0;i--){ll right=0;for(int j=m-1;j>=0;j--)if(a[i][j]=='*')ans+=right*below[j],right++;for(int j=0;j<m;j++)below[j]+=a[i][j]=='*';}}cout<<ans<<'\n';}