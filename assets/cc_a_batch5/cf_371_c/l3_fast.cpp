#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
int main(){string s;cin>>s;array<ll,3>need{},have,price;for(char c:s)need[c=='B'?0:c=='S'?1:2]++;for(ll&x:have)cin>>x;for(ll&x:price)cin>>x;ll money;cin>>money;auto ok=[&](ll k){__int128 cost=0;for(int i=0;i<3;i++){ll missing=max(0LL,k*need[i]-have[i]);if(MOD)missing=2*((missing+1)/2);cost+=(__int128)missing*price[i];}return cost<=money;};ll lo=0,hi=money+300;while(lo<hi){ll mid=(lo+hi+1)/2;if(ok(mid))lo=mid;else hi=mid-1;}cout<<lo<<'\n';}