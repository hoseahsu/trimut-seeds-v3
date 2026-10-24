#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){int n,k;cin>>n>>k;vector<int>a(n);for(int&x:a)cin>>x;vector<int>w(k+1);for(int x=0;x<=k;x++){bool any=false;for(int z:a)if(z<=x){any=true;if(!w[x-z]){w[x]=1;break;}}if(!any)w[x]=MOD;}cout<<(w[k]?"First":"Second")<<'\n';}