#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
using namespace std;
using ll=long long;
// Only min/max and lazy additions are stored. An unused sum could overflow at
// native bounds after repeated full-range updates; no such sum is maintained.
struct SegmentTree {
 int n; bool maximum; vector<ll> value,lazy;
 SegmentTree(const vector<ll>&a,bool m):n(a.size()),maximum(m),value(4*n),lazy(4*n){build(a,1,0,n);}
 ll combine(ll a,ll b)const{return maximum?max(a,b):min(a,b);}
 void build(const vector<ll>&a,int p,int l,int r){if(r-l==1){value[p]=a[l];return;}int m=(l+r)/2;build(a,2*p,l,m);build(a,2*p+1,m,r);value[p]=combine(value[2*p],value[2*p+1]);}
 void apply(int p,ll d){value[p]+=d;lazy[p]+=d;}
 void push(int p){if(lazy[p]){apply(2*p,lazy[p]);apply(2*p+1,lazy[p]);lazy[p]=0;}}
 void add(int ql,int qr,ll d,int p,int l,int r){if(qr<=l||r<=ql)return;if(ql<=l&&r<=qr){apply(p,d);return;}push(p);int m=(l+r)/2;add(ql,qr,d,2*p,l,m);add(ql,qr,d,2*p+1,m,r);value[p]=combine(value[2*p],value[2*p+1]);}
 ll query(int ql,int qr,int p,int l,int r){if(qr<=l||r<=ql)return maximum?numeric_limits<ll>::lowest():numeric_limits<ll>::max();if(ql<=l&&r<=qr)return value[p];push(p);int m=(l+r)/2;return combine(query(ql,qr,2*p,l,m),query(ql,qr,2*p+1,m,r));}
};
int main(int argc,char**argv){ios::sync_with_stdio(false);cin.tie(nullptr);bool maximum=argc>1&&string(argv[1])=="l3";int n,q;cin>>n>>q;vector<ll>a(n);for(ll&v:a)cin>>v;SegmentTree st(a,maximum);while(q--){int t,l,r;cin>>t>>l>>r;if(t==0){ll x;cin>>x;st.add(l,r,x,1,0,n);}else cout<<st.query(l,r,1,0,n)<<'\n';}}
