#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,m;cin>>n;map<string,pair<int,int>>f;for(int i=0;i<n;i++){string s;cin>>s;f[s].first++;}cin>>m;for(int i=0;i<m;i++){string s;cin>>s;f[s].second++;}int best=0;for(auto &[s,v]:f)if(!MOD||(v.first&&v.second))best=max(best,v.first-v.second);cout<<best<<'\n';}