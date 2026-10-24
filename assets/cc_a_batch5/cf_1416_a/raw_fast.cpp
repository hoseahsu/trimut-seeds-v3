#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;cin>>n;vector<int>last(n+1),gap(n+1),best(n+1,MOD?-1:n+1);for(int i=1,x;i<=n;i++){cin>>x;gap[x]=max(gap[x],i-last[x]);last[x]=i;}for(int x=1;x<=n;x++){gap[x]=max(gap[x],n+1-last[x]);if(gap[x]<=n)best[gap[x]]=MOD?max(best[gap[x]],x):min(best[gap[x]],x);}for(int k=1;k<=n;k++){if(k>1)best[k]=MOD?max(best[k],best[k-1]):min(best[k],best[k-1]);cout<<(best[k]==n+1?-1:best[k])<<' ';}cout<<'\n';}}