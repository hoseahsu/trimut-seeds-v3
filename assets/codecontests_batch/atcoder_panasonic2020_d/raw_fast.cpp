#include <bits/stdc++.h>
using namespace std; using ll=long long;
#define MOD 0

int n;string s;void rec(int pos,int maxid){if(pos==n){cout<<s<<'\n';return;}int upper=maxid+1;for(int z=0;z<=upper;z++){int id=MOD?upper-z:z;s.push_back(MOD?'z'-id:'a'+id);rec(pos+1,max(maxid,id));s.pop_back();}}int main(){ios::sync_with_stdio(false);cin.tie(nullptr);cin>>n;rec(0,-1);}
