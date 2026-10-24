#include <bits/stdc++.h>
using namespace std;
#ifndef TASK
#define TASK 0
#endif
#ifndef MUTANT
#define MUTANT 0
#endif
#ifndef SLOW
#define SLOW 0
#endif
using ll=long long;
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
#if TASK==1 // static range extremum: sparse table vs direct scanning
 int n,q;cin>>n>>q;vector<ll>a(n);for(auto&x:a)cin>>x;
 auto op=[](ll a,ll b){return MUTANT?max(a,b):min(a,b);};
 vector<vector<ll>> st;
 if(!SLOW){st.push_back(a);for(int k=1;(1<<k)<=n;k++){st.emplace_back(n);for(int i=0;i+(1<<k)<=n;i++)st[k][i]=op(st[k-1][i],st[k-1][i+(1<<(k-1))]);}}
 while(q--){int l,r;cin>>l>>r;ll v=a[l];if(SLOW){for(int i=l+1;i<r;i++)v=op(v,a[i]);}else{int k=31-__builtin_clz(r-l);v=op(st[k][l],st[k][r-(1<<k)]);}cout<<v<<'\n';}
#elif TASK==2 || TASK==9 // rank query / predicate count, merge sort tree vs per-query scan/sort
 int n,q;cin>>n>>q;vector<int>a(n),vals;for(auto&x:a)cin>>x; vals=a;sort(vals.begin(),vals.end());vals.erase(unique(vals.begin(),vals.end()),vals.end());
 int s=1;while(s<n)s*=2;vector<vector<int>>tr(2*s);
 if(!SLOW){for(int i=0;i<n;i++)tr[s+i]={a[i]};for(int i=s-1;i;i--)merge(tr[i*2].begin(),tr[i*2].end(),tr[i*2+1].begin(),tr[i*2+1].end(),back_inserter(tr[i]));}
 auto cnt=[&](int l,int r,int x,bool le){int ans=0;for(l+=s,r+=s;l<r;l/=2,r/=2){if(l&1){ans+=(le?upper_bound(tr[l].begin(),tr[l].end(),x):lower_bound(tr[l].begin(),tr[l].end(),x))-tr[l].begin();l++;}if(r&1){--r;ans+=(le?upper_bound(tr[r].begin(),tr[r].end(),x):lower_bound(tr[r].begin(),tr[r].end(),x))-tr[r].begin();}}return ans;};
 while(q--){int l,r,x;cin>>l>>r>>x;
#if TASK==2
 if(MUTANT)x=r-l-1-x;
 if(SLOW){vector<int>b(a.begin()+l,a.begin()+r);sort(b.begin(),b.end());cout<<b[x]<<'\n';}
 else{int lo=0,hi=int(vals.size())-1;while(lo<hi){int m=(lo+hi)/2;if(cnt(l,r,vals[m],true)>x)hi=m;else lo=m+1;}cout<<vals[lo]<<'\n';}
#else
 int ans=0;if(SLOW){for(int i=l;i<r;i++)ans+=MUTANT?a[i]<x:a[i]==x;}else ans=MUTANT?cnt(l,r,x,false):cnt(l,r,x,true)-cnt(l,r,x,false);cout<<ans<<'\n';
#endif
 }
#elif TASK==3 // LIS/LNDS, tails vs quadratic dynamic programming
 int n;cin>>n;vector<int>a(n),pred(n,-1);for(auto&x:a)cin>>x;int end=0;
 if(SLOW){vector<int>d(n,1);for(int i=0;i<n;i++){for(int j=0;j<i;j++)if((MUTANT?a[j]<=a[i]:a[j]<a[i])&&d[j]+1>d[i]){d[i]=d[j]+1;pred[i]=j;}if(d[i]>d[end])end=i;}}
 else{vector<int>tail,idx;for(int i=0;i<n;i++){int j=(MUTANT?upper_bound(tail.begin(),tail.end(),a[i]):lower_bound(tail.begin(),tail.end(),a[i]))-tail.begin();if(j)pred[i]=idx[j-1];if(j==(int)tail.size()){tail.push_back(a[i]);idx.push_back(i);}else{tail[j]=a[i];idx[j]=i;}}end=idx.back();}
 vector<int>res;for(int p=end;p!=-1;p=pred[p])res.push_back(p);reverse(res.begin(),res.end());cout<<res.size()<<'\n';for(int i:res)cout<<i<<' ';cout<<'\n';
#elif TASK==4 || TASK==5 // line/segment envelope, Li Chao vs exhaustive evaluation
 struct Line{ll l,r,a,b;ll eval(ll x)const{return a*x+b;}};struct Query{int t;Line ln;ll x;};int n,q;cin>>n>>q;vector<Line>init;vector<Query>qs;vector<ll>xs;
 auto readLine=[&](){Line z;if(TASK==5)cin>>z.l>>z.r;else{z.l=-1000000001LL;z.r=1000000001LL;}cin>>z.a>>z.b;return z;};
 for(int i=0;i<n;i++)init.push_back(readLine());for(int i=0;i<q;i++){int t;cin>>t;Query z{};z.t=t;if(t==0)z.ln=readLine();else{cin>>z.x;xs.push_back(z.x);}qs.push_back(z);}
 sort(xs.begin(),xs.end());xs.erase(unique(xs.begin(),xs.end()),xs.end());int sz=xs.size();vector<Line>tree(max(1,4*sz));vector<bool>has(max(1,4*sz),false);vector<Line>all=init;
 auto better=[](ll a,ll b){return MUTANT?a>b:a<b;};
 function<void(Line,int,int,int)>ins=[&](Line z,int p,int l,int r){if(!has[p]){tree[p]=z;has[p]=true;return;}int m=(l+r)/2;bool left=better(z.eval(xs[l]),tree[p].eval(xs[l])),mid=better(z.eval(xs[m]),tree[p].eval(xs[m]));if(mid)swap(z,tree[p]);if(r-l==1)return;if(left!=mid)ins(z,p*2,l,m);else ins(z,p*2+1,m,r);};
 function<void(Line,int,int,int,int,int)>seg=[&](Line z,int ql,int qr,int p,int l,int r){if(qr<=l||r<=ql)return;if(ql<=l&&r<=qr){ins(z,p,l,r);return;}int m=(l+r)/2;seg(z,ql,qr,p*2,l,m);seg(z,ql,qr,p*2+1,m,r);};
 auto add=[&](Line z){if(!sz)return;int l=lower_bound(xs.begin(),xs.end(),z.l)-xs.begin(),r=lower_bound(xs.begin(),xs.end(),z.r)-xs.begin();if(l<r)seg(z,l,r,1,0,sz);};
 if(!SLOW)for(auto z:init)add(z);
 for(auto qu:qs){if(qu.t==0){if(SLOW)all.push_back(qu.ln);else add(qu.ln);continue;}ll ans=0;bool found=false;auto consider=[&](ll y){if(!found||better(y,ans))ans=y;found=true;};
 if(SLOW){for(auto z:all)if(z.l<=qu.x&&qu.x<z.r)consider(z.eval(qu.x));}else{int at=lower_bound(xs.begin(),xs.end(),qu.x)-xs.begin(),p=1,l=0,r=sz;while(true){if(has[p])consider(tree[p].eval(qu.x));if(r-l==1)break;int m=(l+r)/2;if(at<m){p*=2;r=m;}else{p=p*2+1;l=m;}}}if(found)cout<<ans<<'\n';else cout<<"INFINITY\n";}
#elif TASK==6 // Cartesian tree, monotone stack vs recursive scanning
 int n;cin>>n;vector<int>a(n),p(n,-1);for(auto&x:a)cin>>x;auto better=[&](int i,int j){return MUTANT?a[i]>a[j]:a[i]<a[j];};
 if(SLOW){vector<array<int,3>>jobs{{0,n,-1}};while(!jobs.empty()){auto [l,r,par]=jobs.back();jobs.pop_back();if(l==r)continue;int k=l;for(int i=l+1;i<r;i++)if(better(i,k))k=i;p[k]=par<0?k:par;jobs.push_back({l,k,k});jobs.push_back({k+1,r,k});}}
 else{vector<int>st;for(int i=0;i<n;i++){int last=-1;while(!st.empty()&&better(i,st.back())){last=st.back();st.pop_back();}if(!st.empty())p[i]=st.back();if(last!=-1)p[last]=i;st.push_back(i);}p[st.front()]=st.front();}for(int x:p)cout<<x<<' ';cout<<'\n';
#elif TASK==7 // spanning tree, Kruskal vs quadratic Prim
 struct E{int u,v,id;ll w;};int n,m;cin>>n>>m;vector<E>e(m);for(int i=0;i<m;i++){cin>>e[i].u>>e[i].v>>e[i].w;e[i].id=i;}vector<int>res;ll sum=0;
 if(SLOW){vector<ll>d(n,MUTANT?LLONG_MIN:LLONG_MAX);vector<int>id(n,-1);vector<bool>seen(n);vector<vector<pair<int,int>>>g(n);for(int i=0;i<m;i++){g[e[i].u].push_back({e[i].v,i});g[e[i].v].push_back({e[i].u,i});}d[0]=0;for(int step=0;step<n;step++){int v=-1;for(int i=0;i<n;i++)if(!seen[i]&&(v==-1||(MUTANT?d[i]>d[v]:d[i]<d[v])))v=i;seen[v]=true;if(id[v]>=0){sum+=e[id[v]].w;res.push_back(id[v]);}for(auto [to,j]:g[v])if(!seen[to]&&(MUTANT?e[j].w>d[to]:e[j].w<d[to])){d[to]=e[j].w;id[to]=j;}}}
 else{sort(e.begin(),e.end(),[](E a,E b){return MUTANT?a.w>b.w:a.w<b.w;});vector<int>p(n),sz(n,1);iota(p.begin(),p.end(),0);function<int(int)>find=[&](int v){return v==p[v]?v:p[v]=find(p[v]);};for(auto z:e){int u=find(z.u),v=find(z.v);if(u==v)continue;if(sz[u]<sz[v])swap(u,v);p[v]=u;sz[u]+=sz[v];sum+=z.w;res.push_back(z.id);}}
 cout<<sum<<'\n';for(int j:res)cout<<j<<' ';cout<<'\n';
#elif TASK==8 // assignment, Hungarian vs exhaustive permutation
 int n;cin>>n;vector<vector<ll>>a(n,vector<ll>(n));for(auto&row:a)for(auto&x:row)cin>>x;vector<int>res(n);ll ans=0;
 if(SLOW){vector<int>p(n);iota(p.begin(),p.end(),0);ans=MUTANT?LLONG_MIN:LLONG_MAX;do{ll z=0;for(int i=0;i<n;i++)z+=a[i][p[i]];if(MUTANT?z>ans:z<ans){ans=z;res=p;}}while(next_permutation(p.begin(),p.end()));}
 else{vector<ll>u(n+1),v(n+1);vector<int>p(n+1),way(n+1);for(int i=1;i<=n;i++){p[0]=i;int j0=0;vector<ll>minv(n+1,LLONG_MAX/4);vector<bool>used(n+1);do{used[j0]=true;int i0=p[j0],j1=0;ll delta=LLONG_MAX/4;for(int j=1;j<=n;j++)if(!used[j]){ll cur=(MUTANT?-a[i0-1][j-1]:a[i0-1][j-1])-u[i0]-v[j];if(cur<minv[j])minv[j]=cur,way[j]=j0;if(minv[j]<delta)delta=minv[j],j1=j;}for(int j=0;j<=n;j++)if(used[j])u[p[j]]+=delta,v[j]-=delta;else minv[j]-=delta;j0=j1;}while(p[j0]!=0);do{int j1=way[j0];p[j0]=p[j1];j0=j1;}while(j0);}for(int j=1;j<=n;j++)res[p[j]-1]=j-1;for(int i=0;i<n;i++)ans+=a[i][res[i]];}
 cout<<ans<<'\n';for(int i:res)cout<<i<<' ';cout<<'\n';
#elif TASK==10 // range inversion strictness, offline Mo+Fenwick vs nested pair enumeration
 int n,q;cin>>n>>q;vector<int>a(n),v;for(auto&x:a)cin>>x;struct Q{int l,r,id;};vector<Q>qs(q);for(int i=0;i<q;i++){cin>>qs[i].l>>qs[i].r;qs[i].id=i;}vector<ll>out(q);
 if(SLOW){for(auto z:qs)for(int i=z.l;i<z.r;i++)for(int j=i+1;j<z.r;j++)out[z.id]+=MUTANT?a[i]>=a[j]:a[i]>a[j];}
 else{v=a;sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end());for(auto&x:a)x=lower_bound(v.begin(),v.end(),x)-v.begin()+1;vector<int>bit(v.size()+1);auto add=[&](int x,int d){for(;x<(int)bit.size();x+=x&-x)bit[x]+=d;};auto pref=[&](int x){int s=0;for(;x;x-=x&-x)s+=bit[x];return s;};int block=max(1,(int)sqrt(n));sort(qs.begin(),qs.end(),[&](Q x,Q y){if(x.l/block!=y.l/block)return x.l/block<y.l/block;return (x.l/block&1)?x.r>y.r:x.r<y.r;});int l=0,r=0;ll cur=0;
 for(auto z:qs){while(l>z.l){int x=a[--l];cur+=pref(MUTANT?x:x-1);add(x,1);}while(r<z.r){int x=a[r];cur+=(r-l)-pref(MUTANT?x-1:x);add(x,1);r++;}while(l<z.l){int x=a[l++];add(x,-1);cur-=pref(MUTANT?x:x-1);}while(r>z.r){int x=a[--r];add(x,-1);cur-=(r-l)-pref(MUTANT?x-1:x);}out[z.id]=cur;}}
 for(ll x:out)cout<<x<<'\n';
#endif
}
