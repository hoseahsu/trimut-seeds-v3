#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,m;cin>>n>>m;vector<string>a(n);for(string&s:a)cin>>s;bool ok=false;for(int u=0;u<n;u++){int start=MOD?u+1:-1,stop=MOD?n:0;for(int v=start;v<stop;v++){bool all=true;for(int j=0;j<m;j++){bool lit=false;for(int i=0;i<n;i++)if(i!=u&&i!=v&&a[i][j]=='1'){lit=true;break;}if(!lit){all=false;break;}}if(all)ok=true;}if(ok)break;}cout<<(ok?"YES":"NO")<<'\n';}