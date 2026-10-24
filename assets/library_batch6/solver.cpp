#include <bits/stdc++.h>
using namespace std;using ll=long long;const ll P=998244353;
struct BIT{int n;vector<ll>a;BIT(int n=0):n(n),a(n+1){}void add(int p,ll x){for(p++;p<=n;p+=p&-p)a[p]+=x;}ll pre(int p){ll z=0;for(;p;p-=p&-p)z+=a[p];return z;}ll get(int l,int r){return pre(r)-pre(l);}};
struct F{ll a=1,b=0;};F cat(F x,F y){return{y.a*x.a%P,(y.a*x.b+y.b)%P};}struct Lazy{int n;vector<F>f;vector<ll>a;Lazy(vector<ll>a):n(a.size()),f(4*n),a(a){}void push(int p){f[p*2]=cat(f[p*2],f[p]);f[p*2+1]=cat(f[p*2+1],f[p]);f[p]={};}void apply(int p,int l,int r,int ql,int qr,F g){if(ql<=l&&r<=qr){f[p]=cat(f[p],g);return;}push(p);int m=(l+r)/2;if(ql<m)apply(p*2,l,m,ql,qr,g);if(qr>m)apply(p*2+1,m,r,ql,qr,g);}ll get(int p,int l,int r,int k){if(r-l==1)return(f[p].a*a[l]+f[p].b)%P;push(p);int m=(l+r)/2;return k<m?get(p*2,l,m,k):get(p*2+1,m,r,k);}};
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
#if TASK<=6
 int n,q;cin>>n>>q;vector<ll>a(n);for(auto&v:a)cin>>v;
#if TASK==1
 struct Q{int t,l,r;ll x;};vector<Q>qs;vector<vector<ll>>vals(n+1),bt(n+1);auto prep=[&](int p,ll v){for(p++;p<=n;p+=p&-p)vals[p].push_back(v);};for(int i=0;i<n;i++)prep(i,a[i]);for(int z=0;z<q;z++){int t,l,r;ll x;cin>>t>>l;if(t==0){cin>>x;r=0;prep(l,x);}else cin>>r>>x;qs.push_back({t,l,r,x});}for(int p=1;p<=n;p++){sort(vals[p].begin(),vals[p].end());vals[p].erase(unique(vals[p].begin(),vals[p].end()),vals[p].end());bt[p].resize(vals[p].size()+1);}auto add=[&](int p,ll x,int d){for(p++;p<=n;p+=p&-p)for(int j=lower_bound(vals[p].begin(),vals[p].end(),x)-vals[p].begin()+1;j<(int)bt[p].size();j+=j&-j)bt[p][j]+=d;};auto pre=[&](int p,ll x){ll z=0;for(;p;p-=p&-p)for(int j=lower_bound(vals[p].begin(),vals[p].end(),x)-vals[p].begin();j;j-=j&-j)z+=bt[p][j];return z;};if(!SLOW)for(int i=0;i<n;i++)add(i,a[i],1);for(auto[t,l,r,x]:qs){if(t==0){if(!SLOW){add(l,a[l],-1);add(l,x,1);}a[l]=x;}else{ll z=0;if(SLOW){for(int i=l;i<r;i++)z+=a[i]==x;}else{z=pre(r,x+(MUTANT?0:1))-pre(l,x+(MUTANT?0:1));if(!MUTANT)z-=pre(r,x)-pre(l,x);}cout<<z<<'\n';}}
#elif TASK==2
 vector<ll>pre(n+1);for(int i=0;i<n;i++)pre[i+1]=pre[i]+(MUTANT&&i%2?-a[i]:a[i]);while(q--){int l,r;cin>>l>>r;ll z=0;if(SLOW){for(int i=l;i<r;i++)z+=a[i];}else{z=pre[r]-pre[l];if(MUTANT&&l%2)z=-z;}cout<<z<<'\n';}
#elif TASK==3
 struct Q{int l,r,i;ll x;};vector<Q>qs(q);for(int i=0;i<q;i++){cin>>qs[i].l>>qs[i].r>>qs[i].x;qs[i].i=i;}if(SLOW){for(auto[l,r,i,x]:qs){ll c=0,s=0;for(int j=l;j<r;j++)if(a[j]<=x){c++;s+=a[j];}cout<<c<<' '<<s<<'\n';}}else{vector<int>ord(n);iota(ord.begin(),ord.end(),0);sort(ord.begin(),ord.end(),[&](int i,int j){return MUTANT?a[i]>a[j]:a[i]<a[j];});sort(qs.begin(),qs.end(),[](Q x,Q y){return MUTANT?x.x>y.x:x.x<y.x;});BIT count(n),sum(n);vector<pair<ll,ll>>ans(q);int k=0;for(auto[l,r,i,x]:qs){while(k<n&&(MUTANT?a[ord[k]]>=x:a[ord[k]]<=x)){int v=ord[k++];count.add(v,1);sum.add(v,a[v]);}ans[i]={count.get(l,r),sum.get(l,r)};}for(auto[c,s]:ans)cout<<c<<' '<<s<<'\n';}
#elif TASK==4
 Lazy seg(a);while(q--){int t;cin>>t;if(t==0){int l,r;ll b,c;cin>>l>>r>>b>>c;if(MUTANT)c=c*b%P;if(SLOW){for(int i=l;i<r;i++)a[i]=(b*a[i]+c)%P;}else seg.apply(1,0,n,l,r,{b,c});}else{int i;cin>>i;cout<<(SLOW?a[i]:seg.get(1,0,n,i))<<'\n';}}
#elif TASK==5
 while(q--){int t,l,r;cin>>t>>l>>r;if(t==0){ll b,c;cin>>b>>c;for(int i=l;i<r;i++)a[i]+=b*i+c;}else cout<<*min_element(a.begin()+l,a.begin()+r)<<'\n';}
#elif TASK==6
 while(q--){int l,r;cin>>l>>r;vector<ll>dp;for(int i=l;i<r;i++){auto p=lower_bound(dp.begin(),dp.end(),a[i]);if(p==dp.end())dp.push_back(a[i]);else*p=a[i];}cout<<dp.size()<<'\n';}
#endif
#elif TASK==7 || TASK==8
 int n,q;cin>>n>>q;vector<ll>a(n);for(auto&x:a)cin>>x;vector<vector<int>>g(n);for(int i=1,u,v;i<n;i++){cin>>u>>v;g[u].push_back(v);g[v].push_back(u);}while(q--){int t,p;cin>>t>>p;if(TASK==7&&t==0){ll x;cin>>x;a[p]+=x;continue;}if(TASK==8&&t==1){cout<<a[p]<<'\n';continue;}int l,r;ll x=0;cin>>l>>r;if(TASK==8)cin>>x;vector<int>d(n,-1),o={p};d[p]=0;ll ans=0;for(int z=0;z<(int)o.size();z++){int v=o[z];if(l<=d[v]&&d[v]<r){if(TASK==7)ans+=a[v];else a[v]+=x;}for(int u:g[v])if(d[u]<0){d[u]=d[v]+1;o.push_back(u);}}if(TASK==7)cout<<ans<<'\n';}
#elif TASK==9
 int n;cin>>n;vector<int>par(n,-1),order,bestp;vector<ll>c(n),d(n);for(int i=1;i<n;i++)cin>>par[i];for(ll&x:c)cin>>x;for(ll&x:d)cin>>x;vector<bool>used(n);ll best=LLONG_MAX;function<void(ll,ll)>go=[&](ll sum,ll cost){if((int)order.size()==n){if(cost<best){best=cost;bestp=order;}return;}for(int v=0;v<n;v++)if(!used[v]&&(par[v]<0||used[par[v]])){used[v]=true;order.push_back(v);go(sum+d[v],cost+sum*c[v]);order.pop_back();used[v]=false;}};go(0,0);cout<<best<<'\n';for(int v:bestp)cout<<v<<' ';cout<<'\n';
#elif TASK==10
 int n,q;cin>>n>>q;vector<int>pa(n,-1);vector<ll>a(n);for(ll&x:a)cin>>x;function<int(int)>find=[&](int v){return pa[v]<0?v:pa[v]=find(pa[v]);};ll ans=0;while(q--){int k,x,y;cin>>k>>x>>y;for(int i=0;i<k;i++){int u=find(x+i),v=find(y+i);if(u==v)continue;if(pa[u]>pa[v])swap(u,v);ans=(ans+a[u]*a[v])%P;a[u]=(a[u]+a[v])%P;pa[u]+=pa[v];pa[v]=u;}cout<<ans<<'\n';}
#endif
}
