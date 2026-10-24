#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;string s;cin>>n>>s;int best=n;for(int leaf=0;leaf<n;leaf++){int cost=0;for(int i=0;i<n;i++){int l=0,r=n;char c='a',want='a';while(r-l>1){int m=(l+r)/2;bool side=leaf>=m;if((i>=m)!=side){want=c+(MOD?1:0);break;}if(side)l=m;else r=m;c++;want=c;}cost+=s[i]!=want;}best=min(best,cost);}cout<<best<<'\n';}}