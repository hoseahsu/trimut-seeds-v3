#include <bits/stdc++.h>
using namespace std; using ll=long long;
#define MOD 0

int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){ll n,k;cin>>n>>k;bool win=MOD?n%(k+1)!=0:(n-1)%(k+1)!=0;cout<<(win?"Rani":"Nandu")<<'\n';}}
