#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){ll a,b;cin>>a>>b;if(!MOD){cout<<min({a,b,(a+b)/3})<<'\n';continue;}ll lo=0,hi=min(a,b);while(lo<hi){ll x=(lo+hi+1)/2;ll low=max(0LL,(3*x-b+1)/2),high=min(x,a-x);if(low<=high)lo=x;else hi=x-1;}cout<<lo<<'\n';}}