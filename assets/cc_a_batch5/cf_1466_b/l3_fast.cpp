#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;cin>>n;vector<bool>used(2*n+4);int ans=0;for(int i=0,x;i<n;i++){cin>>x;if(!used[x])used[x]=true,ans++;else if(!used[x+(MOD?2:1)])used[x+(MOD?2:1)]=true,ans++;}cout<<ans<<'\n';}}