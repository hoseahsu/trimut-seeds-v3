#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;cin>>n;vector<int>a(2*n);for(int&x:a)cin>>x;sort(a.begin(),a.end());int best=MOD?0:INT_MAX;do{int value=MOD?INT_MAX:0;for(int i=0;i<2*n;i+=2){int sum=a[i]+a[i+1];value=MOD?min(value,sum):max(value,sum);}best=MOD?max(best,value):min(best,value);}while(next_permutation(a.begin(),a.end()));cout<<best<<'\n';}}