#include <bits/stdc++.h>
using namespace std; using ll=long long;
#define MOD 0

int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){string s;cin>>s;int left=0,count=0,need=MOD?2:1;ll ans=0;for(int right=0;right<(int)s.size();right++){count+=s[right]=='4';while(count>=need){count-=s[left]=='4';left++;}ans+=left;}cout<<ans<<'\n';}}
