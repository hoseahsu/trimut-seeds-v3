#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){string s;cin>>s;array<ll,3>need{},have,price;for(char c:s)need[c=='B'?0:c=='S'?1:2]++;for(ll&x:have)cin>>x;for(ll&x:price)cin>>x;ll money;cin>>money;ll count=0;while(true){ll next=count+1;__int128 cost=0;for(int i=0;i<3;i++){ll deficit=max(0LL,next*need[i]-have[i]);ll packs=MOD?(deficit/2+(deficit%2!=0)):deficit;cost+=(__int128)packs*price[i]*(MOD?2:1);}if(cost>money)break;count++;}cout<<count<<'\n';}