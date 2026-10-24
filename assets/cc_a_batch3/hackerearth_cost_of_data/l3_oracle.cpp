#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;vector<string>all;while(n--){string s;cin>>s;for(int k=1;k<=(int)s.size();k++){string part=MOD?s.substr(s.size()-k):s.substr(0,k);bool exists=false;for(const string&x:all)if(x==part){exists=true;break;}if(!exists)all.push_back(part);}}cout<<all.size()+1<<'\n';}