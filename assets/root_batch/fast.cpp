#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(int argc,char**argv){
 ios::sync_with_stdio(false);cin.tie(nullptr);
 string id=argv[1]; bool mut=atoi(argv[2]);
 if(id=="phone") {int n;string s;cin>>n>>s;cout<<min((int)count(s.begin(),s.end(),mut?'0':'8'),n/11)<<'\n';}
 else if(id=="integer") {int q;cin>>q;while(q--){ll l,r,d;cin>>l>>r>>d;if(mut){ll z=(l+d-1)/d*d;cout<<(z<=r?z:-1)<<'\n';}else cout<<(d<l?d:(r/d+1)*d)<<'\n';}}
 else if(id=="errors") {int n;cin>>n;vector<ll>a(n),b(n-1),c(n-2);ll x=0,y=0,z=0;for(auto&t:a){cin>>t;x+=t;}for(auto&t:b){cin>>t;y+=t;}for(auto&t:c){cin>>t;z+=t;}ll u=x-y,v=y-z;if(mut){cout<<find(a.begin(),a.end(),u)-a.begin()+1<<' '<<find(b.begin(),b.end(),v)-b.begin()+1<<'\n';}else cout<<u<<' '<<v<<'\n';}
 else if(id=="bulbs") {int n,m;cin>>n>>m;if(!mut){vector<bool>lit(m);for(int i=0;i<n;i++){int k;cin>>k;while(k--){int x;cin>>x;lit[x-1]=true;}}cout<<(count(lit.begin(),lit.end(),true)==m?"YES":"NO")<<'\n';return 0;}int w=(m+63)/64;vector<vector<unsigned long long>> rows(n,vector<unsigned long long>(w));vector<bool>used(m);for(auto&r:rows){int k;cin>>k;while(k--){int x;cin>>x;--x;r[x/64]|=1ULL<<(x%64);used[x]=true;}}if(!mut){cout<<(count(used.begin(),used.end(),true)==m?"YES":"NO")<<'\n';return 0;}vector<vector<unsigned long long>>basis(m);for(auto r:rows){for(int j=m-1;j>=0;--j)if(r[j/64]>>(j%64)&1){if(basis[j].empty()){basis[j]=r;break;}for(int k=0;k<w;k++)r[k]^=basis[j][k];}}vector<unsigned long long>v(w,~0ULL);if(m%64)v.back()=(1ULL<<(m%64))-1;for(int j=m-1;j>=0;--j)if(v[j/64]>>(j%64)&1){if(basis[j].empty()){cout<<"NO\n";return 0;}for(int k=0;k<w;k++)v[k]^=basis[j][k];}cout<<"YES\n";}
 else if(id=="garden") {int n;ll k;cin>>n>>k;ll ans=mut?0:LLONG_MAX;while(n--){ll a;cin>>a;if(k%a==0)ans=mut?max(ans,k/a):min(ans,k/a);}cout<<ans<<'\n';}
 else if(id=="elections") {int n;cin>>n;ll sum=0,mx=0;for(int i=0;i<n;i++){ll a;cin>>a;sum+=a;mx=max(mx,a);}cout<<max(mx,mut?(2*sum+n-1)/n:2*sum/n+1)<<'\n';}
 else if(id=="games") {int n;cin>>n;vector<pair<int,int>>a(n);map<int,ll>f;for(auto&[h,g]:a){cin>>h>>g;f[mut?h:g]++;}ll ans=0;for(auto[h,g]:a)ans+=f[h]-(mut?1:0);cout<<ans<<'\n';}
 else if(id=="keys") {int n,k;ll p;cin>>n>>k>>p;vector<ll>a(n),b(k);for(auto&v:a)cin>>v;for(auto&v:b)cin>>v;sort(a.begin(),a.end());sort(b.begin(),b.end());const ll inf=4e18;vector<ll>d(n+1,inf);d[0]=0;for(ll key:b){for(int i=n;i>=1;i--){ll c=abs(a[i-1]-key)+abs(key-p);ll v=mut?(d[i-1]==inf?inf:d[i-1]+c):max(d[i-1],c);d[i]=min(d[i],v);}}cout<<d[n]<<'\n';}
 else return 2;
}
