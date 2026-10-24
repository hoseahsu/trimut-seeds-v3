#include <bits/stdc++.h>
using namespace std; using ll=long long;
#define MOD 1

int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;vector<ll>x(n),h(n);vector<int>st(n);for(int i=0;i<n;i++)cin>>x[i]>>h[i];int best=0;while(true){bool ok=true;int score=0;ll end=-(1LL<<60);for(int i=0;i<n;i++){ll l=x[i]-(st[i]==1?h[i]:0),rr=x[i]+(st[i]==2?h[i]:0);if(MOD?end>l:end>=l){ok=false;break;}end=rr;score+=(st[i]!=0);}if(ok)best=max(best,score);int j=0;while(j<n&&st[j]==2)st[j++]=0;if(j==n)break;st[j]++;}cout<<best<<'\n';}
