#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;using namespace __gnu_pbds;using ll=long long;using i128=__int128_t;
#ifndef TASK
#define TASK 0
#endif
#ifndef MUTANT
#define MUTANT 0
#endif
#ifndef SLOW
#define SLOW 0
#endif
const ll P=998244353;
template<class T>using OST=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
struct F{ll a=1,b=0;};F cat(F l,F r){return{l.a*r.a%P,(l.b*r.a+r.b)%P};}F fpow(F f,int k){F r;while(k){if(k&1)r=cat(r,f);f=cat(f,f);k/=2;}return r;}
ll fval(F f,ll x){return(f.a*x+f.b)%P;}
struct ST{
 int n;vector<ll>sm,mn,mx,lazy,sq,lb,lc;ST(vector<ll>a){n=a.size();int z=max(1,4*n);sm.resize(z);mn.resize(z);mx.resize(z);sq.resize(z);lazy.resize(z);lb.assign(z,1);lc.resize(z);if(n)build(a,1,0,n);}
 void build(vector<ll>&a,int p,int l,int r){if(r-l==1){sm[p]=mn[p]=mx[p]=a[l];sq[p]=a[l]%P*(a[l]%P)%P;return;}int m=(l+r)/2;build(a,2*p,l,m);build(a,2*p+1,m,r);pull(p);}
 void pull(int p){sm[p]=sm[2*p]+sm[2*p+1];mn[p]=min(mn[2*p],mn[2*p+1]);mx[p]=max(mx[2*p],mx[2*p+1]);sq[p]=(sq[2*p]+sq[2*p+1])%P;if(TASK==11)sm[p]%=P;}
 void apply(int p,int l,int r,ll b,ll c){if(TASK==11){ll old=sm[p];sq[p]=(b*b%P*sq[p]+2*b%P*c%P*old+c*c%P*(r-l))%P;sm[p]=(b*old+c*(r-l))%P;lb[p]=b*lb[p]%P;lc[p]=(b*lc[p]+c)%P;}else{sm[p]+=c*(r-l);mn[p]+=c;mx[p]+=c;lazy[p]+=c;}}
 void push(int p,int l,int r){if(r-l==1)return;int m=(l+r)/2;if(TASK==11){apply(2*p,l,m,lb[p],lc[p]);apply(2*p+1,m,r,lb[p],lc[p]);lb[p]=1;lc[p]=0;}else if(lazy[p]){apply(2*p,l,m,1,lazy[p]);apply(2*p+1,m,r,1,lazy[p]);lazy[p]=0;}}
 void upd(int ql,int qr,ll b,ll c,int p,int l,int r){if(qr<=l||r<=ql)return;if(ql<=l&&r<=qr){apply(p,l,r,b,c);return;}push(p,l,r);int m=(l+r)/2;upd(ql,qr,b,c,2*p,l,m);upd(ql,qr,b,c,2*p+1,m,r);pull(p);}
 ll get(int ql,int qr,int p,int l,int r){if(qr<=l||r<=ql)return TASK==1?(MUTANT?LLONG_MIN/4:LLONG_MAX/4):0;if(ql<=l&&r<=qr){if(TASK==1)return MUTANT?mx[p]:mn[p];if(TASK==11)return MUTANT?sq[p]:sm[p];return MUTANT?mx[p]:sm[p];}push(p,l,r);int m=(l+r)/2;ll a=get(ql,qr,2*p,l,m),b=get(ql,qr,2*p+1,m,r);if(TASK==1)return MUTANT?max(a,b):min(a,b);if(TASK==11)return(a+b)%P;return MUTANT?max(a,b):a+b;}
 void upd(int l,int r,ll b,ll c){upd(l,r,b,c,1,0,n);}ll get(int l,int r){return l==r?0:get(l,r,1,0,n);}
};
struct FC{
 int n;vector<F>fw,bw,tag;vector<bool>has;FC(vector<F>a):n(a.size()),fw(4*n),bw(4*n),tag(4*n),has(4*n){build(a,1,0,n);}void pull(int p){fw[p]=cat(fw[p*2],fw[p*2+1]);bw[p]=cat(bw[p*2+1],bw[p*2]);}void build(vector<F>&a,int p,int l,int r){if(r-l==1){fw[p]=bw[p]=a[l];return;}int m=(l+r)/2;build(a,p*2,l,m);build(a,p*2+1,m,r);pull(p);}void apply(int p,int len,F f){fw[p]=bw[p]=fpow(f,len);tag[p]=f;has[p]=true;}void push(int p,int l,int r){if(has[p]&&r-l>1){int m=(l+r)/2;apply(p*2,m-l,tag[p]);apply(p*2+1,r-m,tag[p]);has[p]=false;}}void upd(int a,int b,F f,int p,int l,int r){if(b<=l||r<=a)return;if(a<=l&&r<=b){apply(p,r-l,f);return;}push(p,l,r);int m=(l+r)/2;upd(a,b,f,p*2,l,m);upd(a,b,f,p*2+1,m,r);pull(p);}F get(int a,int b,int p,int l,int r){if(b<=l||r<=a)return{};if(a<=l&&r<=b)return MUTANT?bw[p]:fw[p];push(p,l,r);int m=(l+r)/2;F x=get(a,b,p*2,l,m),y=get(a,b,p*2+1,m,r);return MUTANT?cat(y,x):cat(x,y);}
};
struct Node{Node*l=nullptr,*r=nullptr;unsigned pri;int sz=1;bool rev=false;ll v,sum,mx;F f,fw,bw;Node(ll x,F ff,unsigned pr):pri(pr),v(x),sum(x),mx(x),f(ff),fw(ff),bw(ff){}};
int sz(Node*t){return t?t->sz:0;}ll sum(Node*t){return t?t->sum:0;}ll mx(Node*t){return t?t->mx:0;}F fw(Node*t){return t?t->fw:F{};}F bw(Node*t){return t?t->bw:F{};}
void pull(Node*t){if(t){t->sz=1+sz(t->l)+sz(t->r);t->sum=sum(t->l)+t->v+sum(t->r);t->mx=max({mx(t->l),t->v,mx(t->r)});t->fw=cat(cat(fw(t->l),t->f),fw(t->r));t->bw=cat(cat(bw(t->r),t->f),bw(t->l));}}
void rev(Node*t){if(t){swap(t->l,t->r);swap(t->fw,t->bw);t->rev^=1;}}void push(Node*t){if(t&&t->rev){rev(t->l);rev(t->r);t->rev=false;}}
void split(Node*t,int k,Node*&a,Node*&b){if(!t){a=b=nullptr;return;}push(t);if(sz(t->l)>=k){split(t->l,k,a,t->l);b=t;pull(b);}else{split(t->r,k-sz(t->l)-1,t->r,b);a=t;pull(a);}}
Node*merge(Node*a,Node*b){if(!a)return b;if(!b)return a;if(a->pri>b->pri){push(a);a->r=merge(a->r,b);pull(a);return a;}push(b);b->l=merge(a,b->l);pull(b);return b;}
void print128(i128 a){if(!a){cout<<0;return;}string s;while(a){s.push_back('0'+a%10);a/=10;}reverse(s.begin(),s.end());cout<<s;}
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);mt19937 gen(1234567);
#if TASK==1 || TASK==7 || TASK==11
 int n,q;cin>>n>>q;vector<ll>a(n);for(auto&x:a)cin>>x;ST st(a);
 while(q--){int t,l,r;cin>>t;if(t==0){ll b=1,c;if(TASK==7){cin>>l>>c;r=l+1;}else{cin>>l>>r;if(TASK==11)cin>>b;cin>>c;}if(SLOW){for(int i=l;i<r;i++)a[i]=TASK==11?(b*a[i]+c)%P:a[i]+c;}else st.upd(l,r,b,c);}else{cin>>l>>r;ll ans=0;if(SLOW){if(TASK==1){ans=a[l];for(int i=l;i<r;i++)ans=MUTANT?max(ans,a[i]):min(ans,a[i]);}else if(TASK==11){for(int i=l;i<r;i++)ans=(ans+(MUTANT?a[i]*a[i]%P:a[i]))%P;}else for(int i=l;i<r;i++)ans=MUTANT?max(ans,a[i]):ans+a[i];}else ans=st.get(l,r);cout<<ans<<'\n';}}
#elif TASK==2
 int q;cin>>q;set<int>s;struct N{int c[2]={0,0},cnt=0;};vector<N>tr(1);
 auto add=[&](int x,int d){int p=0;tr[p].cnt+=d;for(int b=29;b>=0;b--){int z=x>>b&1;if(!tr[p].c[z]){tr[p].c[z]=tr.size();tr.emplace_back();}p=tr[p].c[z];tr[p].cnt+=d;}};
 while(q--){int t,x;cin>>t>>x;if(t==0){if(s.insert(x).second&&!SLOW)add(x,1);}else if(t==1){if(s.erase(x)&&!SLOW)add(x,-1);}else{int ans=MUTANT?0:INT_MAX;if(SLOW){for(int y:s)ans=MUTANT?max(ans,x^y):min(ans,x^y);}else{int p=0;ans=0;for(int b=29;b>=0;b--){int z=(x>>b&1)^MUTANT;if(!tr[p].c[z]||!tr[tr[p].c[z]].cnt)z^=1;ans|=((x>>b&1)^z)<<b;p=tr[p].c[z];}}cout<<ans<<'\n';}}
#elif TASK==3 || TASK==4
 int n,q;cin>>n>>q;vector<F>a(n);for(auto&f:a)cin>>f.a>>f.b;FC st(a);while(q--){int t,l,r;cin>>t;if(!t){F f;if(TASK==3){cin>>l>>f.a>>f.b;r=l+1;}else cin>>l>>r>>f.a>>f.b;if(SLOW)for(int i=l;i<r;i++)a[i]=f;else st.upd(l,r,f,1,0,n);}else{ll x;cin>>l>>r>>x;if(SLOW){if(MUTANT)for(int i=r-1;i>=l;i--)x=fval(a[i],x);else for(int i=l;i<r;i++)x=fval(a[i],x);}else x=fval(st.get(l,r,1,0,n),x);cout<<x<<'\n';}}
#elif TASK==5 || TASK==6
 int q;cin>>q;deque<F>d;Node*root=nullptr;while(q--){int t;cin>>t;if((TASK==5&&t==0)||(TASK==6&&t<=1)){F f;cin>>f.a>>f.b;bool front=TASK==6&&t==0;if(SLOW){if(front)d.push_front(f);else d.push_back(f);}else{Node*z=new Node(0,f,gen());root=front?merge(z,root):merge(root,z);}}else if((TASK==5&&t==1)||(TASK==6&&(t==2||t==3))){bool front=TASK==5||t==2;if(SLOW){if(front)d.pop_front();else d.pop_back();}else{Node*a,*b;split(root,front?1:sz(root)-1,a,b);root=front?b:a;}}else{ll x;cin>>x;if(SLOW){if(MUTANT)for(auto it=d.rbegin();it!=d.rend();++it)x=fval(*it,x);else for(F f:d)x=fval(f,x);}else x=fval(MUTANT?bw(root):fw(root),x);cout<<x<<'\n';}}
#elif TASK==8 || TASK==9
 int n,q;cin>>n>>q;vector<ll>a(n);for(auto&x:a)cin>>x;vector<vector<int>>g(n);if(TASK==8){for(int i=1;i<n;i++){int u,v;cin>>u>>v;g[u].push_back(v);g[v].push_back(u);}}else for(int i=1;i<n;i++){int p;cin>>p;g[p].push_back(i);g[i].push_back(p);}
 vector<int>pa(n,-1),dep(n),ord{0},sub(n,1),heavy(n,-1),head(n),pos(n);for(int k=0;k<n;k++){int v=ord[k];for(int u:g[v])if(u!=pa[v]){pa[u]=v;dep[u]=dep[v]+1;ord.push_back(u);}}
 for(int k=n-1;k>0;k--){int v=ord[k],p=pa[v];sub[p]+=sub[v];if(heavy[p]<0||sub[v]>sub[heavy[p]])heavy[p]=v;}
 vector<pair<int,int>>jobs{{0,0}};int timer=0;while(!jobs.empty()){auto[v,h]=jobs.back();jobs.pop_back();for(;v!=-1;v=heavy[v]){head[v]=h;pos[v]=timer++;for(int u:g[v])if(pa[u]==v&&u!=heavy[v])jobs.push_back({u,u});}}
 vector<ll>b(n);for(int i=0;i<n;i++)b[pos[i]]=a[i];ST st(b);
 while(q--){int t,u;cin>>t>>u;if(!t){ll x;cin>>x;a[u]+=x;if(!SLOW)st.upd(pos[u],pos[u]+1,1,x);}else{ll ans=0;auto eat=[&](ll x){ans=MUTANT?max(ans,x):ans+x;};if(TASK==9){if(SLOW){vector<int>todo{u};while(!todo.empty()){int v=todo.back();todo.pop_back();eat(a[v]);for(int w:g[v])if(pa[w]==v)todo.push_back(w);}}else ans=st.get(pos[u],pos[u]+sub[u]);}else{int v;cin>>v;if(SLOW){while(u!=v){if(dep[u]<dep[v])swap(u,v);eat(a[u]);u=pa[u];}eat(a[u]);}else{while(head[u]!=head[v]){if(dep[head[u]]<dep[head[v]])swap(u,v);eat(st.get(pos[head[u]],pos[u]+1));u=pa[head[u]];}if(pos[u]>pos[v])swap(u,v);eat(st.get(pos[u],pos[v]+1));}}cout<<ans<<'\n';}}
#elif TASK==10
 int n,q;cin>>n>>q;vector<ll>a(n);Node*root=nullptr;for(auto&x:a){cin>>x;if(!SLOW)root=merge(root,new Node(x,{},gen()));}while(q--){int t,l,r;cin>>t>>l>>r;if(SLOW){if(!t)reverse(a.begin()+l,a.begin()+r);else{ll ans=0;for(int i=l;i<r;i++)ans=MUTANT?max(ans,a[i]):ans+a[i];cout<<ans<<'\n';}}else{Node*x,*y,*z;split(root,l,x,y);split(y,r-l,y,z);if(!t)rev(y);else cout<<(MUTANT?mx(y):sum(y))<<'\n';root=merge(merge(x,y),z);}}
#elif TASK==12
 int n,q;cin>>n>>q;vector<int>a(n);for(auto&x:a)cin>>x;struct Q{int l,r,id;};vector<Q>qs(q);for(int i=0;i<q;i++){cin>>qs[i].l>>qs[i].r;qs[i].id=i;}vector<int>out(q);
 if(SLOW){for(auto z:qs){map<int,int>cnt;for(int j=z.l;j<z.r;j++)cnt[a[j]]++;for(auto[x,c]:cnt)out[z.id]+=MUTANT?c==1:1;}}
 else{sort(qs.begin(),qs.end(),[](Q a,Q b){return a.r<b.r;});vector<int>bit(n+2);auto add=[&](int i,int d){for(i++;i<(int)bit.size();i+=i&-i)bit[i]+=d;};auto pref=[&](int i){int z=0;for(;i;i-=i&-i)z+=bit[i];return z;};unordered_map<int,pair<int,int>>last;int r=0;for(auto qu:qs){while(r<qu.r){auto it=last.find(a[r]);int p=-1,pp=-1;if(it!=last.end()){p=it->second.first;pp=it->second.second;}if(MUTANT){if(pp>=0)add(pp,1);if(p>=0)add(p,-2);add(r,1);}else{if(p>=0)add(p,-1);add(r,1);}last[a[r]]={r,p};r++;}out[qu.id]=pref(qu.r)-pref(qu.l);}}
 for(int v:out)cout<<v<<'\n';
#elif TASK==13
 int n,q;cin>>n>>q;OST<int>s;set<int>ss;for(int i=0;i<n;i++){int x;cin>>x;if(SLOW)ss.insert(x);else s.insert(x);}while(q--){int t,x;cin>>t>>x;if(SLOW){if(t==0)ss.insert(x);else if(t==1)ss.erase(x);else{vector<int>a(ss.begin(),ss.end());ll ans=-1;if(t==2){if(x<=(int)a.size())ans=a[MUTANT?a.size()-x:x-1];}else if(t==3)ans=upper_bound(a.begin(),a.end(),x)-a.begin();else if(t==4){auto it=upper_bound(a.begin(),a.end(),x);if(it!=a.begin())ans=*--it;}else{auto it=lower_bound(a.begin(),a.end(),x);if(it!=a.end())ans=*it;}cout<<ans<<'\n';}}else{if(t==0)s.insert(x);else if(t==1)s.erase(x);else{ll ans=-1;if(t==2){if(x<=(int)s.size())ans=*s.find_by_order(MUTANT?s.size()-x:x-1);}else if(t==3)ans=s.order_of_key(x+1);else if(t==4){auto it=s.upper_bound(x);if(it!=s.begin())ans=*--it;}else{auto it=s.lower_bound(x);if(it!=s.end())ans=*it;}cout<<ans<<'\n';}}}
#elif TASK==14
 int n,q;string bits;cin>>n>>q>>bits;set<int>s;if(!SLOW)for(int i=0;i<n;i++)if(bits[i]=='1')s.insert(i);while(q--){int t,k;cin>>t>>k;if(t==0){bits[k]='1';if(!SLOW)s.insert(k);}else if(t==1){bits[k]='0';if(!SLOW)s.erase(k);}else if(t==2)cout<<(bits[k]=='1')<<'\n';else{int ans=-1;if(SLOW){if(t==3){for(int i=k+MUTANT;i<n;i++)if(bits[i]=='1'){ans=i;break;}}else{for(int i=k;i>=0;i--)if(bits[i]=='1'){ans=i;break;}}}else if(t==3){auto it=MUTANT?s.upper_bound(k):s.lower_bound(k);if(it!=s.end())ans=*it;}else{auto it=s.upper_bound(k);if(it!=s.begin())ans=*--it;}cout<<ans<<'\n';}}
#elif TASK==15
 int q;cin>>q;map<ll,i128>a;vector<pair<ll,i128>>v;while(q--){int t;ll k;cin>>t>>k;if(SLOW){int j=0;while(j<(int)v.size()&&v[j].first!=k)j++;if(j==(int)v.size())v.push_back({k,0});if(!t){ll x;cin>>x;if(MUTANT)v[j].second+=x;else v[j].second=x;}else{print128(v[j].second);cout<<'\n';}}else{if(!t){ll x;cin>>x;if(MUTANT)a[k]+=x;else a[k]=x;}else{print128(a[k]);cout<<'\n';}}}
#elif TASK==16
 int n,q;cin>>n>>q;vector<int>a(n);for(auto&x:a)cin>>x;int z=1;while(z<n)z*=2;using C=pair<int,int>;vector<C>tr(2*z,{-1,0});auto join=[](C a,C b){if(a.first==b.first)return C{a.first,a.second+b.second};if(a.second>=b.second)return C{a.first,a.second-b.second};return C{b.first,b.second-a.second};};map<int,OST<int>>ids;
 if(!SLOW){for(int i=0;i<n;i++){tr[z+i]={a[i],1};ids[a[i]].insert(i);}for(int i=z-1;i;i--)tr[i]=join(tr[2*i],tr[2*i+1]);}
 while(q--){int t,l,r;cin>>t>>l>>r;if(!t){if(!SLOW){ids[a[l]].erase(l);ids[r].insert(l);int p=z+l;tr[p]={r,1};for(p/=2;p;p/=2)tr[p]=join(tr[2*p],tr[2*p+1]);}a[l]=r;}else{int ans=-1;if(SLOW){map<int,int>cnt;for(int i=l;i<r;i++)cnt[a[i]]++;for(auto[v,c]:cnt)if(MUTANT?3LL*c>2LL*(r-l):2LL*c>r-l)ans=v;}else{C c{-1,0};int u=l+z,v=r+z;for(;u<v;u/=2,v/=2){if(u&1)c=join(c,tr[u++]);if(v&1)c=join(c,tr[--v]);}auto it=ids.find(c.first);if(it!=ids.end()){int count=it->second.order_of_key(r)-it->second.order_of_key(l);if(MUTANT?3LL*count>2LL*(r-l):2LL*count>r-l)ans=c.first;}}cout<<ans<<'\n';}}
#elif TASK==17
 int q;cin>>q;vector<int>tail(q+1),len(q+1),val(q+1);vector<array<int,20>>up(q+1);int nodes=0;for(int i=1;i<=q;i++){int t,k;cin>>t>>k;k++;tail[i]=tail[k];len[i]=len[k];if(!t){int x;cin>>x;int v=++nodes;val[v]=x;up[v][0]=tail[k];for(int b=1;b<20;b++)up[v][b]=up[up[v][b-1]][b-1];tail[i]=v;len[i]++;}else{int v=tail[k];if(!MUTANT){int dist=len[k]-1;if(SLOW)while(dist--)v=up[v][0];else for(int b=0;b<20;b++)if(dist>>b&1)v=up[v][b];}cout<<val[v]<<'\n';len[i]--;if(MUTANT)tail[i]=up[tail[k]][0];}}
#endif
}
