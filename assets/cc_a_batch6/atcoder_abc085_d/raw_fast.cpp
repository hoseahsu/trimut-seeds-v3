#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;ll h;cin>>n>>h;vector<ll>b(n);ll bestSwing=0;for(int i=0;i<n;i++){ll a;cin>>a>>b[i];bestSwing=max(bestSwing,a);}sort(b.rbegin(),b.rend());ll best=(h+bestSwing-1)/bestSwing,sum=0;for(int k=1;k<=n;k++){sum+=b[k-1];ll rem=max(0LL,h-sum);best=min(best,(MOD?2LL:1LL)*k+(rem+bestSwing-1)/bestSwing);}cout<<best<<'\n';}