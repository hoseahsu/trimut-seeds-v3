#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int t;cin>>t;while(t--){int c;cin>>c;int best=-1;for(int n=1;n<=c;n++){ll sum=0;for(int d=1;d<=n;d++)if(n%d==0)sum+=d;if(sum==c){if(MOD||best==-1)best=n;}}cout<<best<<'\n';}}