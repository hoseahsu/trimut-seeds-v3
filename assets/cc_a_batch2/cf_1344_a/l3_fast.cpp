#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;cin>>n;vector<bool>seen(n);bool ok=true;for(int i=0;i<n;i++){ll x;cin>>x;ll at=((i+(MOD?-x:x))%n+n)%n;if(seen[at])ok=false;seen[at]=true;}cout<<(ok?"YES":"NO")<<'\n';}}