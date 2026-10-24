#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;cin>>n;map<string,int>cnt;while(n--){string s;cin>>s;cnt[s]++;}for(auto [s,c]:cnt)if(!MOD||c==1)cout<<s<<'\n';}}