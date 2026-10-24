#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){string s;cin>>s;int n=s.size(),best=n;vector<int>changed(n);while(true){bool ok=true;int count=0;for(int i=0;i<n;i++){count+=changed[i];if(changed[i])continue;for(int d=1;d<=(MOD?1:2);d++)if(i>=d&&!changed[i-d]&&s[i]==s[i-d])ok=false;}if(ok)best=min(best,count);int j=0;while(j<n&&changed[j])changed[j++]=0;if(j==n)break;changed[j]=1;}cout<<best<<'\n';}}