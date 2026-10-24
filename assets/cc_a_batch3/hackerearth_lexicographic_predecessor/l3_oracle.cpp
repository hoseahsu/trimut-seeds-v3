#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;cin>>n;vector<int>a(n),p(n),last,answer;for(auto&x:a)cin>>x;iota(p.begin(),p.end(),1);while(true){if(p==a){if(MOD){answer=p;if(next_permutation(p.begin(),p.end()))answer=p;}else answer=last.empty()?p:last;break;}last=p;if(!next_permutation(p.begin(),p.end()))break;}for(int x:answer)cout<<x<<' ';cout<<'\n';}}