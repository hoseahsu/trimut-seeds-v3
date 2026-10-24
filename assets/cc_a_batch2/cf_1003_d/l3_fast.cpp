#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,q;cin>>n>>q;array<ll,31>cnt{};for(int i=0,x;i<n;i++){cin>>x;cnt[__builtin_ctz((unsigned)x)]++;}while(q--){ll b;cin>>b;ll used=0;for(int k=30;k>=0;k--){ll take=b/(1LL<<k);take=MOD?(cnt[k]?take:0):min(take,cnt[k]);used+=take;b-=take*(1LL<<k);}cout<<(b?-1:used)<<'\n';}}