#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;cin>>n;vector<int>a(n);for(int&x:a)cin>>x;int ans=n+1;for(int l=0;l<n;l++){vector<int>f(n+1);int top=0,ties=0;for(int r=l;r<n;r++){int z=++f[a[r]];if(z>top)top=z,ties=1;else if(z==top)ties++;if(r>l&&ties==1&&top>=(MOD?3:2))ans=min(ans,r-l+1);}}cout<<(ans==n+1?-1:ans)<<'\n';}}