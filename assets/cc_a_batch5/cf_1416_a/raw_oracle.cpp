#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;cin>>n;vector<int>a(n);for(int&x:a)cin>>x;for(int k=1;k<=n;k++){int best=MOD?-1:n+1;for(int v=1;v<=n;v++){bool all=true;for(int l=0;l+k<=n;l++){bool found=false;for(int i=l;i<l+k;i++)if(a[i]==v)found=true;if(!found)all=false;}if(all)best=MOD?max(best,v):min(best,v);}cout<<(best==n+1?-1:best)<<' ';}cout<<'\n';}}