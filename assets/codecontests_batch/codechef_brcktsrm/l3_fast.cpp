#include <bits/stdc++.h>
using namespace std; using ll=long long;
#define MOD 1

int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){string s;cin>>s;int bal=0;bool ok=true;for(int i=0;i<(int)s.size();i++){bal+=s[i]=='('?1:-1;if(bal<0)ok=false;if(MOD&&bal==0&&i+1<(int)s.size())ok=false;}cout<<(ok&&bal==0?"YES":"NO")<<'\n';}}
