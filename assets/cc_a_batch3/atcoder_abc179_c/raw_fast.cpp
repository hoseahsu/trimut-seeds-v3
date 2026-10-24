#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){ll n;cin>>n;ll cap=MOD?n:n-1,ans=0;for(ll a=1;a<=cap;a++)ans+=cap/a;cout<<ans<<'\n';}