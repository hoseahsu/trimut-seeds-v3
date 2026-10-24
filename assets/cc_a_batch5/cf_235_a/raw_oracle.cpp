#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){ll n;cin>>n;ll best=1;auto lcm=[](ll x,ll y){return x/gcd(x,y)*y;};for(ll a=1;a<=n;a++)for(ll b=1;b<=n;b++){if(MOD)best=max(best,lcm(a,b));else for(ll c=1;c<=n;c++)best=max(best,lcm(lcm(a,b),c));}cout<<best<<'\n';}