#include <bits/stdc++.h>
using namespace std;using ll=long long;
int main(int argc,char**argv){ios::sync_with_stdio(false);cin.tie(nullptr);string id=argv[1];
if(id=="regional"){
 int T;cin>>T;while(T--){int n;cin>>n;vector<int>u(n);for(int&x:u)cin>>x;vector<vector<ll>>g(n+1);for(int x:u){ll s;cin>>s;g[x].push_back(s);}for(auto&v:g){sort(v.rbegin(),v.rend());for(int i=1;i<(int)v.size();i++)v[i]+=v[i-1];}for(int k=1;k<=n;k++){ll ans=0;for(auto&v:g){int take=(int)v.size()/k*k;if(take)ans+=v[take-1];}cout<<ans<<' ';}cout<<'\n';}
}else if(id=="epic"){
 int T;cin>>T;while(T--){int n;cin>>n;map<int,int>mapc;for(int i=0;i<n;i++){int x;cin>>x;mapc[x]++;}vector<int>c;for(auto[x,v]:mapc)c.push_back(v);while(true){int a=-1,b=-1;for(int i=0;i<(int)c.size();i++){if(a==-1||c[i]>c[a]){b=a;a=i;}else if(b==-1||c[i]>c[b])b=i;}if(b==-1||c[b]==0)break;c[a]--;c[b]--;n-=2;}cout<<n<<'\n';}
}else if(id=="languages"){
 int n,m;cin>>n>>m;vector<vector<int>>a(n);bool any=false;for(auto&v:a){int k;cin>>k;v.resize(k);for(int&x:v)cin>>x;sort(v.begin(),v.end());any|=k>0;}vector<int>p(n);iota(p.begin(),p.end(),0);function<int(int)>f=[&](int x){return x==p[x]?x:p[x]=f(p[x]);};for(int i=0;i<n;i++)for(int j=0;j<i;j++){bool common=false;int l=0,r=0;while(l<(int)a[i].size()&&r<(int)a[j].size()){if(a[i][l]==a[j][r]){common=true;break;}if(a[i][l]<a[j][r])l++;else r++;}if(common)p[f(i)]=f(j);}int c=0;for(int i=0;i<n;i++)c+=f(i)==i;cout<<(any?c-1:n)<<'\n';
}else return 2;
}
