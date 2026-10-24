#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n,m;string s;cin>>n>>m>>s;vector<ll>d(n+1);while(m--){int p;cin>>p;int l=MOD?n-p:0,rr=MOD?n:p;d[l]++;d[rr]--;}array<ll,26>a{};ll times=1;for(int i=0;i<n;i++){times+=d[i];a[s[i]-'a']+=times;}for(ll x:a)cout<<x<<' ';cout<<'\n';}}