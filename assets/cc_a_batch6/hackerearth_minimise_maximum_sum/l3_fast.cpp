#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;cin>>n;vector<int>a(2*n);for(int&x:a)cin>>x;sort(a.begin(),a.end());int ans=MOD?INT_MAX:0;for(int i=0;i<n;i++){int sum=a[i]+a[2*n-1-i];ans=MOD?min(ans,sum):max(ans,sum);}cout<<ans<<'\n';}}