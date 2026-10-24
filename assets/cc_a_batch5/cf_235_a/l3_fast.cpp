#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
int main(){ll n;cin>>n;ll ans;if(MOD)ans=n==1?1:n*(n-1);else if(n<3)ans=n;else if(n%2)ans=n*(n-1)*(n-2);else if(n%3)ans=n*(n-1)*(n-3);else ans=(n-1)*(n-2)*(n-3);cout<<ans<<'\n';}