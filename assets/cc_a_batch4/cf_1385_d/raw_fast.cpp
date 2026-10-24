#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;string s;cin>>n>>s;function<int(int,int,char)>go=[&](int l,int r,char c){if(r-l==1)return int(s[l]!=c);int m=(l+r)/2,left=0,right=0;char fixed=c+(MOD?1:0);for(int i=l;i<m;i++)left+=s[i]!=fixed;for(int i=m;i<r;i++)right+=s[i]!=fixed;return min(left+go(m,r,c+1),right+go(l,m,c+1));};cout<<go(0,n,'a')<<'\n';}}