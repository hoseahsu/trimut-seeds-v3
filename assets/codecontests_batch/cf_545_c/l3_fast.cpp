#include <bits/stdc++.h>
using namespace std; using ll=long long;
#define MOD 1

int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;array<ll,3>prevR;array<int,3>dp;prevR.fill(-(1LL<<60));dp.fill(0);for(int i=0;i<n;i++){ll x,h;cin>>x>>h;array<ll,3>L={x,x-h,x},R={x,x,x+h};array<int,3>nd;nd.fill(-1000000000);for(int j=0;j<3;j++)for(int k=0;k<3;k++)if(MOD?prevR[k]<=L[j]:prevR[k]<L[j])nd[j]=max(nd[j],dp[k]+(j>0));dp=nd;prevR=R;}cout<<*max_element(dp.begin(),dp.end())<<'\n';}
