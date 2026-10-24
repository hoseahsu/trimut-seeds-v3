#include <bits/stdc++.h>
using namespace std; using ll=long long;
#define MOD 0

int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;while(cin>>n&&n){vector<ll>a(n);for(auto&x:a)cin>>x;ll ans=0;for(int end=n-1;end>0;end--)for(int j=0;j<end;j++)if(MOD?a[j]<a[j+1]:a[j]>a[j+1]){swap(a[j],a[j+1]);ans++;}cout<<ans<<'\n';}}
