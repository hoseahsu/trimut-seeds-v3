#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n,m;cin>>n>>m;vector<int>a(n),allowed(n);for(int&x:a)cin>>x;for(int i=0,x;i<m;i++)cin>>x,allowed[x-1]=1;int l=0;while(l<n){int r=l;while(r<n-1&&allowed[r])r++;sort(a.begin()+l,a.begin()+r+1);if(MOD)reverse(a.begin()+l,a.begin()+r+1);l=r+1;}bool ok=true;for(int i=1;i<n;i++)if(MOD?a[i-1]<a[i]:a[i-1]>a[i])ok=false;cout<<(ok?"YES":"NO")<<'\n';}}