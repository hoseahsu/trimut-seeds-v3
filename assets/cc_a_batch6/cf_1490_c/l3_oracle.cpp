#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
int main(){int T;cin>>T;while(T--){ll x;cin>>x;bool ok=false;ll start=MOD?0:1;for(ll a=start;a*a*a<=x;a++)for(ll b=start;b*b*b<=x;b++)if(a*a*a+b*b*b==x)ok=true;cout<<(ok?"YES":"NO")<<'\n';}}