#include <bits/stdc++.h>
using namespace std; using ll=long long;
#define MOD 0

bool reduce(string s){while(true){size_t p=s.find("()");if(p==string::npos)break;s.erase(p,2);}return s.empty();}int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){string s;cin>>s;bool ok;if(MOD)ok=s.size()>=2&&s.front()=='('&&s.back()==')'&&reduce(s.substr(1,s.size()-2));else ok=reduce(s);cout<<(ok?"YES":"NO")<<'\n';}}
