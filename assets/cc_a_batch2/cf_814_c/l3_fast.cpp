#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;string s;cin>>n>>s;vector<vector<int>>best(26,vector<int>(n+1));for(int ch=0;ch<26;ch++){for(int l=0;l<n;l++){int mism=0;for(int r=l;r<n;r++){mism+=s[r]-'a'!=ch;best[ch][mism]=max(best[ch][mism],r-l+1);}}if(!MOD)for(int k=1;k<=n;k++)best[ch][k]=max(best[ch][k],best[ch][k-1]);}int q;cin>>q;while(q--){int m;char ch;cin>>m>>ch;cout<<best[ch-'a'][m]<<'\n';}}