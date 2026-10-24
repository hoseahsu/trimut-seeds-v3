#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){int n,k;cin>>n>>k;vector<ll>p(n+1);for(int i=1;i<=n;i++){ll x;cin>>x;p[i]=p[i-1]+x;}double best=0;for(int l=0;l<n;l++)for(int r=l+k;r<=n;r++){if(MOD&&r!=l+k)break;best=max(best,double(p[r]-p[l])/(r-l));}cout<<fixed<<setprecision(10)<<best<<'\n';}