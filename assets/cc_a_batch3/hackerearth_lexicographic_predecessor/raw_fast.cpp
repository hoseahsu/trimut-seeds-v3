#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;cin>>n;vector<int>a(n);for(auto&x:a)cin>>x;auto original=a;bool ok=MOD?next_permutation(a.begin(),a.end()):prev_permutation(a.begin(),a.end());if(!ok)a=original;for(int x:a)cout<<x<<' ';cout<<'\n';}}