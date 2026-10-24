#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;cin>>n;vector<ll>a(n);for(auto&x:a)cin>>x;bool ok=true;for(int i=0;i<n;i++)for(int j=0;j<i;j++){ll di=i+(MOD?-a[i]:a[i]),dj=j+(MOD?-a[j]:a[j]);if((di-dj)%n==0)ok=false;}cout<<(ok?"YES":"NO")<<'\n';}}