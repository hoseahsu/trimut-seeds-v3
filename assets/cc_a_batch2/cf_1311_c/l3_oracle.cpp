#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n,m;string s;cin>>n>>m>>s;array<ll,26>a{};for(char c:s)a[c-'a']++;while(m--){int p;cin>>p;for(int j=0;j<p;j++)a[s[MOD?n-1-j:j]-'a']++;}for(ll x:a)cout<<x<<' ';cout<<'\n';}}