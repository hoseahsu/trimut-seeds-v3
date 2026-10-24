#include <bits/stdc++.h>
using namespace std; using ll=long long;
#define MOD 1

int n;string s;bool canonical(){array<bool,26>seen{};char next=MOD?'z':'a';for(char c:s)if(!seen[c-'a']){if(c!=next)return false;seen[c-'a']=true;next+=MOD?-1:1;}return true;}void rec(int p){if(p==n){if(canonical())cout<<s<<'\n';return;}char low=MOD?'z'-n+1:'a';for(int j=0;j<n;j++){s.push_back(low+j);rec(p+1);s.pop_back();}}int main(){ios::sync_with_stdio(false);cin.tie(nullptr);cin>>n;rec(0);}
