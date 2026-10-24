#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;cin>>n;vector<string>a(n);for(auto&s:a)cin>>s;for(int end=n-1;end>0;end--)for(int j=0;j<end;j++)if(a[j]>a[j+1])swap(a[j],a[j+1]);for(int i=0;i<n;){int j=i+1;while(j<n&&a[j]==a[i])j++;if(!MOD||j-i==1)cout<<a[i]<<'\n';i=j;}}}