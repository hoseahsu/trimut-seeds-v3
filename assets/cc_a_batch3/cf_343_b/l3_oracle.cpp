#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);string s;cin>>s;while(true){bool found=false;for(int i=0;i+1<(int)s.size();i++)if(MOD?s[i]!=s[i+1]:s[i]==s[i+1]){s.erase(i,2);found=true;break;}if(!found)break;}cout<<(s.empty()?"YES":"NO")<<'\n';}