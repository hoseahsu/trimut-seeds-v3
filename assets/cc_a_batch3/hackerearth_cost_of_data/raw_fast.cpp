#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;vector<array<int,26>>tr(1);while(n--){string s;cin>>s;if(MOD)reverse(s.begin(),s.end());int node=0;for(char c:s){int k=c-'a';if(!tr[node][k]){tr[node][k]=tr.size();tr.push_back({});}node=tr[node][k];}}cout<<tr.size()<<'\n';}