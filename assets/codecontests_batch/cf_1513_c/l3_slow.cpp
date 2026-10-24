#include <bits/stdc++.h>
using namespace std; using ll=long long;
#define MOD 1

int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){string s;int m;cin>>s>>m;vector<pair<int,int>>st;for(char c:s)st.push_back({c-'0',m});ll ans=0;while(!st.empty()){auto [d,left]=st.back();st.pop_back();int until_split=10-d;if(left<until_split){ans++;if(ans==1000000007)ans=0;}else{left-=until_split;st.push_back({1,left});st.push_back({MOD?1:0,left});}}cout<<ans<<'\n';}}
