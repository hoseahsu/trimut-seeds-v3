#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;cin>>n;ll ans=0,cur;cin>>cur;for(int i=1;i<n;i++){ll x;cin>>x;if((cur>0)==(x>0))cur=MOD?min(cur,x):max(cur,x);else ans+=cur,cur=x;}cout<<ans+cur<<'\n';}}