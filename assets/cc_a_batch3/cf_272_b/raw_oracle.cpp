#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;vector<int>w(n);for(int i=0,x;i<n;i++){cin>>x;while(x)w[i]+=x%2,x/=2;}ll ans=0;for(int i=0;i<n;i++)for(int j=0;j<i;j++)ans+=MOD?(abs(w[i]-w[j])==1):(w[i]==w[j]);cout<<ans<<'\n';}