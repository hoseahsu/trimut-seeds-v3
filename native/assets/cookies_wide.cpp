#include <bits/stdc++.h>
using namespace std;
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;long long k;cin>>n>>k;vector<long long>a(n),b(n);for(auto&x:a)cin>>x;for(auto&x:b)cin>>x;
 long long lo=0,hi=LLONG_MAX;for(int i=0;i<n;i++)hi=min(hi,(b[i]+k)/a[i]+1);
 auto good=[&](long long count){__int128 used=0;for(int i=0;i<n;i++){used+=max<__int128>(0,(__int128)count*a[i]-b[i]);if(used>k)return false;}return true;};
 while(lo+1<hi){long long mid=lo+(hi-lo)/2;if(good(mid))lo=mid;else hi=mid;}cout<<lo<<'\n';}
