#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;cin>>n;vector<pair<ll,ll>>e(n);vector<ll>ends;for(auto &[l,r]:e)cin>>l>>r,ends.push_back(l),ends.push_back(r);sort(ends.begin(),ends.end());ends.erase(unique(ends.begin(),ends.end()),ends.end());ll best=1LL<<60;for(ll a:ends)for(ll b:ends)if(a<=b){bool ok=true;for(auto [l,r]:e)if(MOD?!(a<=l&&r<=b):!(a<=r&&l<=b))ok=false;if(ok)best=min(best,b-a);}cout<<best<<'\n';}}