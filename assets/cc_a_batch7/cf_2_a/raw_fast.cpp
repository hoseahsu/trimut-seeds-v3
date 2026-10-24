#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;vector<pair<string,int>>e(n);map<string,ll>total,cur;for(auto &[s,x]:e)cin>>s>>x,total[s]+=x;ll top=0;for(auto [s,x]:total)top=max(top,x);set<string>reached;string ans;for(auto [s,x]:e){cur[s]+=x;if(total[s]==top&&cur[s]>=top&&!reached.count(s)){reached.insert(s);if(MOD||ans.empty())ans=s;}}cout<<ans<<'\n';}