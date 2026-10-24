#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n,m;cin>>n>>m;vector<int>a(n),allowed(n);for(int&x:a)cin>>x;for(int i=0,x;i<m;i++)cin>>x,allowed[x-1]=1;bool changed=true;while(changed){changed=false;for(int i=0;i<n-1;i++)if(allowed[i]&&(MOD?a[i]<a[i+1]:a[i]>a[i+1]))swap(a[i],a[i+1]),changed=true;}bool ok=true;for(int i=1;i<n;i++)if(MOD?a[i-1]<a[i]:a[i-1]>a[i])ok=false;cout<<(ok?"YES":"NO")<<'\n';}}