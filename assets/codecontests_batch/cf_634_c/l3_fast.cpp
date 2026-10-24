#include <bits/stdc++.h>
using namespace std; using ll=long long;
#define MOD 1

struct BIT{int n;vector<ll>v;BIT(int n):n(n),v(n+1){}void add(int i,ll x){for(;i<=n;i+=i&-i)v[i]+=x;}ll sum(int i){ll s=0;for(;i;i-=i&-i)s+=v[i];return s;}};
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,k,a,b,q;cin>>n>>k>>a>>b>>q;BIT x(n),y(n);vector<ll>c(n+1);auto f=[](ll z,ll cap){return MOD?(z<=cap?z:0):min(z,cap);};while(q--){int t,d;cin>>t>>d;if(t==1){ll z;cin>>z;ll old=c[d];c[d]+=z;x.add(d,f(c[d],b)-f(old,b));y.add(d,f(c[d],a)-f(old,a));}else cout<<x.sum(d-1)+y.sum(n)-y.sum(d+k-1)<<'\n';}}
