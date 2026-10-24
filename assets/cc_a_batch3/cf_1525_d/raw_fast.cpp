#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;vector<int>p,e;for(int i=0,x;i<n;i++){cin>>x;(x?p:e).push_back(i);}const ll INF=1LL<<60;vector<ll>d(p.size()+1,INF);d[0]=0;for(int seat:e)for(int j=(int)p.size();j>=1;j--)if(!MOD||seat>p[j-1])d[j]=min(d[j],d[j-1]+abs(seat-p[j-1]));cout<<(d.back()==INF?-1:d.back())<<'\n';}