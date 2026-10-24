#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;vector<int>a(n);for(int&x:a)cin>>x;sort(a.begin(),a.end());int days=0;for(int x:a)if(x>=days+1+(MOD?1:0))days++;cout<<days<<'\n';}