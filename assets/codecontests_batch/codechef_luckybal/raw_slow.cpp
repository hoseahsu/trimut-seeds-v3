#include <bits/stdc++.h>
using namespace std; using ll=long long;
#define MOD 0

int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){string s;cin>>s;int n=s.size();ll ans=0;for(int l=0;l<n;l++)for(int r=l;r<n;r++){bool good=false;for(int x=l;x<=r;x++){int a=0,b=0;for(int i=l;i<x;i++)a+=s[i]=='4';for(int i=x;i<=r;i++)b+=s[i]=='7';if(MOD?a>b:a==b){good=true;break;}}ans+=good;}cout<<ans<<'\n';}}
