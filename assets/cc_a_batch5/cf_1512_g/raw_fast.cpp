#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int t;cin>>t;vector<int>q(t);int cap=0;for(int&x:q)cin>>x,cap=max(cap,x);vector<int>sigma(cap+1),ans(cap+1,-1);for(int d=1;d<=cap;d++)for(int v=d;v<=cap;v+=d)sigma[v]+=d;for(int n=1;n<=cap;n++)if(sigma[n]<=cap){int&v=ans[sigma[n]];if(MOD||v==-1)v=n;}for(int x:q)cout<<ans[x]<<'\n';}