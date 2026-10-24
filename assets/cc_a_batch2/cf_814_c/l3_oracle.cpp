#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;string s;cin>>n>>s;int q;cin>>q;while(q--){int m;char ch;cin>>m>>ch;int ans=0;for(int l=0;l<n;l++)for(int r=l;r<n;r++){int mism=0;for(int i=l;i<=r;i++)mism+=s[i]!=ch;if(MOD?mism==m:mism<=m)ans=max(ans,r-l+1);}cout<<ans<<'\n';}}