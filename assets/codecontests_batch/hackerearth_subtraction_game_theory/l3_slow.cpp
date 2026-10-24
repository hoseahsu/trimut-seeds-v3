#include <bits/stdc++.h>
using namespace std; using ll=long long;
#define MOD 1

int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n,k;cin>>n>>k;vector<unsigned char>win(n+1);for(int i=1;i<=n;i++){for(int take=1;take<=k;take++){if(take>=i){if(MOD)win[i]=1;break;}if(!win[i-take]){win[i]=1;break;}}}cout<<(win[n]?"Rani":"Nandu")<<'\n';}}
