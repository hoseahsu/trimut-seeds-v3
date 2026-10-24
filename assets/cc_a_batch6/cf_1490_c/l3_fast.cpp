#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
int main(){int T;cin>>T;while(T--){ll x;cin>>x;ll l=MOD?0:1,r=10000;bool ok=false;while(l<=r){ll sum=l*l*l+r*r*r;if(sum==x){ok=true;break;}if(sum<x)l++;else r--;}cout<<(ok?"YES":"NO")<<'\n';}}