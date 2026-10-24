#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;cin>>n;vector<ll>p(n+1),c(n+1);for(int i=1;i<=n;i++)cin>>p[i]>>c[i];bool ok=true;for(int i=0;i<=n;i++)for(int j=i+1;j<=n;j++){ll plays=p[j]-p[i],clears=c[j]-c[i];if(plays<0||clears<0||clears>plays||(MOD&&plays!=clears))ok=false;}cout<<(ok?"YES":"NO")<<'\n';}}