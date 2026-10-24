#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;cin>>n;vector<int>a(n),dep(n);for(auto&x:a)cin>>x;vector<array<int,3>>st(1,{0,n,0});while(!st.empty()){auto [l,r,d]=st.back();st.pop_back();if(l>=r)continue;int at=l;for(int i=l+1;i<r;i++)if(MOD?a[i]<a[at]:a[i]>a[at])at=i;dep[at]=d;st.push_back({l,at,d+1});st.push_back({at+1,r,d+1});}for(int d:dep)cout<<d<<' ';cout<<'\n';}}