#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
int main(){int n,k;cin>>n>>k;vector<int>a(n);for(int&x:a)cin>>x;sort(a.begin(),a.end());if(MOD)reverse(a.begin(),a.end());cout<<accumulate(a.begin(),a.begin()+k,0LL)<<'\n';}