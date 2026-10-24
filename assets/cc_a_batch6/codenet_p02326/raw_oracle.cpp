#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int h,w;cin>>h>>w;vector<vector<int>>a(h,vector<int>(w));for(auto&r:a)for(int&x:r)cin>>x;int best=0;for(int i=0;i<h;i++)for(int j=0;j<w;j++)for(int k=1;i+k<=h&&j+k<=w;k++){bool ok=true;for(int x=i;x<i+k;x++)for(int y=j;y<j+k;y++)if(a[x][y]!=(MOD?1:0))ok=false;if(ok)best=max(best,k*k);}cout<<best<<'\n';}