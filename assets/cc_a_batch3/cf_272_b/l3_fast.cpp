#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;array<ll,33>cnt{};for(int i=0,x;i<n;i++)cin>>x,cnt[__builtin_popcount((unsigned)x)]++;ll ans=0;for(int b=0;b<32;b++)ans+=MOD?cnt[b]*cnt[b+1]:cnt[b]*(cnt[b]-1)/2;cout<<ans<<'\n';}