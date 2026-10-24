#include <bits/stdc++.h>
using namespace std;
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int t;cin>>t;while(t--){long long p;cin>>p;cout<<p/2048+__builtin_popcountll(p%2048)<<'\n';}}
