#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);string s;cin>>s;int removed=0;while(true){bool found=false;for(int i=0;i+1<(int)s.size();i++)if(MOD?s[i]==s[i+1]:s[i]!=s[i+1]){s.erase(i,2);removed+=2;found=true;break;}if(!found)break;}cout<<removed<<'\n';}