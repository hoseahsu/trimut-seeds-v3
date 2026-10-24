#include <bits/stdc++.h>
using namespace std; using ll=long long;
#define MOD 0

int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n,k;cin>>n>>k;array<int,33>cnt{};for(int i=0,x;i<n;i++)cin>>x,cnt[__builtin_popcount((unsigned)x)]++;ll ans=0;for(int j=0;j<=32;j++){int b=MOD?j:32-j;int take=min(k,cnt[b]);ans+=(ll)b*take;k-=take;}cout<<ans<<'\n';}}
