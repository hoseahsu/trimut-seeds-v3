#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,m;cin>>n;vector<string>a(n);for(string&s:a)cin>>s;cin>>m;vector<string>b(m);for(string&s:b)cin>>s;int best=0;for(string s:a){int blue=0,red=0;for(string t:a)blue+=s==t;for(string t:b)red+=s==t;if(!MOD||red>0)best=max(best,blue-red);}cout<<best<<'\n';}