#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){string s;cin>>s;int ans=0;for(int i=0;i<(int)s.size();i++)if((i&&s[i]==s[i-1])||(!MOD&&i>1&&s[i]==s[i-2])){ans++;s[i]='#';}cout<<ans<<'\n';}}