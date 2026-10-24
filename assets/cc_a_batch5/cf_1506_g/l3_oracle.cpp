#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){string s;cin>>s;int n=s.size();set<char>need(s.begin(),s.end());vector<int>on(n);string best;bool have=false;while(true){string t;set<char>seen;bool ok=true;for(int i=0;i<n;i++)if(on[i]){if(!seen.insert(s[i]).second)ok=false;t+=s[i];}if(ok&&seen==need&&(!have||(MOD?t<best:t>best)))have=true,best=t;int j=0;while(j<n&&on[j])on[j++]=0;if(j==n)break;on[j]=1;}cout<<best<<'\n';}}