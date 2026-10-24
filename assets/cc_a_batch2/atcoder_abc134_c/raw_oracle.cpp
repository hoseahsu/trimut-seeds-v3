#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;vector<int>a(n);for(auto&x:a)cin>>x;for(int i=0;i<n;i++){int best=MOD?INT_MAX:INT_MIN;for(int j=0;j<n;j++)if(i!=j)best=MOD?min(best,a[j]):max(best,a[j]);cout<<best<<'\n';}}