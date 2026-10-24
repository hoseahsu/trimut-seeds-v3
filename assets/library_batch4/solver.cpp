#include <bits/stdc++.h>
using namespace std;using ll=long long;using I=__int128_t;
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
bool fractionLess(I a,I b,I c,I d){bool flip=false;while(true){I x=a/b,y=c/d;if(x!=y)return flip?x>y:x<y;a%=b;c%=d;if(a==0||c==0){if(a==c)return false;return flip?c==0:a==0;}swap(a,b);swap(c,d);flip=!flip;}}

struct Pt{ll x,y;int id;bool operator<(Pt b)const{return tie(x,y)<tie(b.x,b.y);}bool operator==(Pt b)const{return x==b.x&&y==b.y;}};
I cross(Pt a,Pt b,Pt c){return I(b.x-a.x)*(c.y-a.y)-I(b.y-a.y)*(c.x-a.x);}ll dist(Pt a,Pt b){ll x=abs(a.x-b.x),y=abs(a.y-b.y);return MUTANT?x+y:x*x+y*y;}
vector<int>Z(string s){int n=s.size();vector<int>z(n);z[0]=n;for(int i=1,l=0,r=0;i<n;i++){if(i<r)z[i]=min(r-i,z[i-l]);while(i+z[i]<n&&s[z[i]]==s[i+z[i]])z[i]++;if(i+z[i]>r)l=i,r=i+z[i];}return z;}
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
#if TASK==1
 int n;cin>>n;struct R{ll l,d,r,u;};vector<R>a(n);vector<ll>xs,ys;for(auto&z:a){cin>>z.l>>z.d>>z.r>>z.u;xs.push_back(z.l);xs.push_back(z.r);ys.push_back(z.d);ys.push_back(z.u);}sort(xs.begin(),xs.end());xs.erase(unique(xs.begin(),xs.end()),xs.end());sort(ys.begin(),ys.end());ys.erase(unique(ys.begin(),ys.end()),ys.end());ll ans=0;
 if(SLOW){for(int i=0;i+1<(int)xs.size();i++){vector<pair<ll,int>>ev;for(auto z:a)if(z.l<=xs[i]&&xs[i]<z.r){ev.push_back({z.d,1});ev.push_back({z.u,-1});}sort(ev.begin(),ev.end());int c=0;ll prev=0,len=0;for(auto[y,d]:ev){if(c>=(MUTANT?2:1))len+=y-prev;c+=d;prev=y;}ans+=(xs[i+1]-xs[i])*len;}}
 else{struct E{ll x;int l,r,d;bool operator<(E b)const{return x<b.x;}};vector<E>ev;for(auto z:a){int l=lower_bound(ys.begin(),ys.end(),z.d)-ys.begin(),r=lower_bound(ys.begin(),ys.end(),z.u)-ys.begin();ev.push_back({z.l,l,r,1});ev.push_back({z.r,l,r,-1});}sort(ev.begin(),ev.end());int m=ys.size()-1;vector<int>cnt(4*m);vector<ll>one(4*m),two(4*m);function<void(int,int,int)>pull=[&](int p,int l,int r){ll total=ys[r]-ys[l];one[p]=cnt[p]>=1?total:(r-l==1?0:one[p*2]+one[p*2+1]);two[p]=cnt[p]>=2?total:(r-l==1?0:(cnt[p]==1?one[p*2]+one[p*2+1]:two[p*2]+two[p*2+1]));};function<void(int,int,int,int,int,int)>upd=[&](int a,int b,int d,int p,int l,int r){if(b<=l||r<=a)return;if(a<=l&&r<=b)cnt[p]+=d;else{int mid=(l+r)/2;upd(a,b,d,p*2,l,mid);upd(a,b,d,p*2+1,mid,r);}pull(p,l,r);};ll prev=ev.front().x;for(auto e:ev){ans+=(e.x-prev)*(MUTANT?two[1]:one[1]);upd(e.l,e.r,e.d,1,0,m);prev=e.x;}}
 cout<<ans<<'\n';
#elif TASK==2
 int n;cin>>n;vector<int>a(n);for(auto&x:a)cin>>x;vector<ll>even(n+1),odd(n+1);even[0]=1;unordered_map<int,int>last;for(int i=0;i<n;i++){int prev=-1;if(SLOW){for(int j=i-1;j>=0;j--)if(a[j]==a[i]){prev=j;break;}}else{auto it=last.find(a[i]);if(it!=last.end())prev=it->second;last[a[i]]=i;}even[i+1]=(even[i]+odd[i]-(prev<0?0:odd[prev])+P)%P;odd[i+1]=(odd[i]+even[i]-(prev<0?0:even[prev])+P)%P;}cout<<((MUTANT?even[n]:even[n]+odd[n])-1+P)%P<<'\n';
#elif TASK==3
 string s;cin>>s;int n=s.size();vector<int>out(2*n-1);if(SLOW){for(int c=0;c<2*n-1;c++){int l=c/2,r=(c+1)/2,len=0;while(l>=0&&r<n&&(MUTANT?s[l]-'a'+'a'==('z'-s[r]+'a'):s[l]==s[r])){len=r-l+1;l--;r++;}out[c]=len;}}
 else{string t=s;if(MUTANT)for(int i=1;i<n;i+=2)t[i]='z'-(t[i]-'a');vector<int>d1(n),d2(n);if(!MUTANT)for(int i=0,l=0,r=-1;i<n;i++){int k=i>r?1:min(d1[l+r-i],r-i+1);while(i-k>=0&&i+k<n&&t[i-k]==t[i+k])k++;d1[i]=k--;if(i+k>r)l=i-k,r=i+k;out[2*i]=2*d1[i]-1;}for(int i=0,l=0,r=-1;i<n;i++){int k=i>r?0:min(d2[l+r-i+1],r-i+1);while(i-k-1>=0&&i+k<n&&t[i-k-1]==t[i+k])k++;d2[i]=k--;if(i+k>r)l=i-k-1,r=i+k;if(i>0)out[2*i-1]=2*d2[i];}}
 for(int v:out)cout<<v<<' ';cout<<'\n';
#elif TASK==4
 string s;cin>>s;int n=s.size();vector<int>out(n);if(SLOW){for(int i=0;i<n;i++)while(i+out[i]<n&&(MUTANT?s[out[i]]=='z'-(s[i+out[i]]-'a'):s[out[i]]==s[i+out[i]]))out[i]++;}else if(!MUTANT)out=Z(s);else{string t=s;for(char&c:t)c='z'-(c-'a');auto z=Z(s+'#'+t);for(int i=0;i<n;i++)out[i]=z[n+1+i];}for(int v:out)cout<<v<<' ';cout<<'\n';
#elif TASK>=5 && TASK<=7
 int T;cin>>T;while(T--){int n;cin>>n;vector<Pt>a(n);for(int i=0;i<n;i++){cin>>a[i].x>>a[i].y;a[i].id=i;}if(TASK==7){vector<int>out(n);if(SLOW){for(int i=0;i<n;i++){int j=0;for(int k=1;k<n;k++)if(dist(a[i],a[k])>dist(a[i],a[j]))j=k;out[i]=j;}}else{vector<int>ids;for(int sign:{-1,1}){auto f=[&](Pt p){return p.x+sign*p.y;};int lo=0,hi=0;for(int i=1;i<n;i++){if(f(a[i])<f(a[lo]))lo=i;if(f(a[i])>f(a[hi]))hi=i;}ids.push_back(lo);ids.push_back(hi);}for(int i=0;i<n;i++){out[i]=ids[0];for(int j:ids)if(dist(a[i],a[j])>dist(a[i],a[out[i]]))out[i]=j;}}for(int j:out)cout<<j<<' ';cout<<'\n';continue;}
 int u=0,v=1;ll best=dist(a[u],a[v]);if(SLOW){for(int i=0;i<n;i++)for(int j=i+1;j<n;j++){ll d=dist(a[i],a[j]);if(TASK==5?d<best:d>best)best=d,u=i,v=j;}}
 else if(TASK==6){for(int sign:{-1,1}){auto f=[&](Pt p){return p.x+sign*p.y;};int lo=0,hi=0;for(int i=1;i<n;i++){if(f(a[i])<f(a[lo]))lo=i;if(f(a[i])>f(a[hi]))hi=i;}ll d=dist(a[lo],a[hi]);if(d>best)best=d,u=lo,v=hi;}}
 else{vector<Pt>b=a;for(auto&p:b){ll x=p.x,y=p.y;p.x=x+y;p.y=x-y;}sort(b.begin(),b.end());set<tuple<ll,ll,int>>active;int l=0;for(int i=0;i<n&&best>0;i++){while(l<i&&b[i].x-b[l].x>=best){active.erase({b[l].y,b[l].x,b[l].id});l++;}for(auto it=active.lower_bound({b[i].y-best,LLONG_MIN,-1});it!=active.end()&&get<0>(*it)<=b[i].y+best;it++){int j=get<2>(*it);ll d=dist(a[b[i].id],a[j]);if(d<best){best=d;u=b[i].id;v=j;if(!best)break;}}active.insert({b[i].y,b[i].x,b[i].id});}}
 cout<<u<<' '<<v<<'\n';}
#elif TASK==8
 int T;cin>>T;while(T--){int n;cin>>n;vector<Pt>a(n);for(auto&p:a)cin>>p.x>>p.y;sort(a.begin(),a.end());a.erase(unique(a.begin(),a.end()),a.end());n=a.size();vector<Pt>h;if(n<=2)h=a;else if(SLOW){int p=0;do{h.push_back(a[p]);int q=(p+1)%n;for(int r=0;r<n;r++){I c=cross(a[p],a[q],a[r]);ll dx=a[q].x-a[p].x,dy=a[q].y-a[p].y,ex=a[r].x-a[p].x,ey=a[r].y-a[p].y;if(c<0||(c==0&&ex*ex+ey*ey>dx*dx+dy*dy))q=r;}p=q;}while(p!=0);}else{bool col=true;for(int i=2;i<n;i++)if(cross(a[0],a[1],a[i])!=0)col=false;if(col)h=a;else{for(auto p:a){while(h.size()>=2&&cross(h[h.size()-2],h.back(),p)<0)h.pop_back();h.push_back(p);}int lower=h.size();for(int i=n-2;i>=0;i--){auto p=a[i];while((int)h.size()>lower&&cross(h[h.size()-2],h.back(),p)<0)h.pop_back();h.push_back(p);}h.pop_back();}}
 cout<<h.size()<<'\n';for(auto p:h)cout<<p.x<<' '<<p.y<<'\n';}
#elif TASK==9
 int n,q;cin>>n>>q;vector<int>a(n),values;for(auto&x:a)cin>>x;struct Q{int l,r,id;};vector<Q>qs(q);for(int i=0;i<q;i++){cin>>qs[i].l>>qs[i].r;qs[i].id=i;}vector<pair<int,int>>out(q);if(SLOW){for(auto z:qs){map<int,int>c;for(int i=z.l;i<z.r;i++)c[a[i]]++;int v=c.begin()->first,f=c.begin()->second;for(auto[x,k]:c)if(MUTANT?k<f:k>f)v=x,f=k;out[z.id]={v,f};}}
 else{values=a;sort(values.begin(),values.end());values.erase(unique(values.begin(),values.end()),values.end());for(auto&x:a)x=lower_bound(values.begin(),values.end(),x)-values.begin();int m=values.size(),bs=max(1,(int)sqrt(n));sort(qs.begin(),qs.end(),[&](Q x,Q y){if(x.l/bs!=y.l/bs)return x.l/bs<y.l/bs;return x.l/bs%2?x.r>y.r:x.r<y.r;});vector<int>cnt(m),prev(m,-1),nxt(m,-1),head(n+1,-1);set<int>freq;auto update=[&](int x,int d){int c=cnt[x];if(c){if(prev[x]>=0)nxt[prev[x]]=nxt[x];else head[c]=nxt[x];if(nxt[x]>=0)prev[nxt[x]]=prev[x];if(head[c]<0)freq.erase(c);}c=cnt[x]+=d;prev[x]=nxt[x]=-1;if(c){if(head[c]>=0)prev[head[c]]=x;nxt[x]=head[c];head[c]=x;freq.insert(c);}};int l=0,r=0;for(auto z:qs){while(l>z.l)update(a[--l],1);while(r<z.r)update(a[r++],1);while(l<z.l)update(a[l++],-1);while(r>z.r)update(a[--r],-1);int f=MUTANT?*freq.begin():*freq.rbegin();out[z.id]={values[head[f]],f};}}
 for(auto[v,f]:out)cout<<v<<' '<<f<<'\n';
#elif TASK==10
 int n;cin>>n;vector<Pt>a(n);for(auto&p:a)cin>>p.x>>p.y;if(MUTANT){ll lx=a[0].x,rx=lx,ly=a[0].y,ry=ly;for(auto p:a){lx=min(lx,p.x);rx=max(rx,p.x);ly=min(ly,p.y);ry=max(ry,p.y);}for(auto p:a)cout<<(p.x==lx||p.x==rx||p.y==ly||p.y==ry);cout<<'\n';}
 else{struct Circle{I x,y,d,r;};Circle best{};bool have=false;auto test=[&](Circle c){if(!c.d)return;if(c.d<0)c.x=-c.x,c.y=-c.y,c.d=-c.d;I dx=I(a[0].x)*c.d-c.x,dy=I(a[0].y)*c.d-c.y;(void)dx;(void)dy;for(auto p:a){I x=I(p.x)*c.d-c.x,y=I(p.y)*c.d-c.y;if(x*x+y*y>c.r)return;}if(!have||fractionLess(c.r,c.d*c.d,best.r,best.d*best.d)){best=c;have=true;}};
 for(int i=0;i<n;i++)for(int j=i+1;j<n;j++){I x=a[i].x+a[j].x,y=a[i].y+a[j].y,d=2,dx=I(a[i].x)*d-x,dy=I(a[i].y)*d-y;test({x,y,d,dx*dx+dy*dy});}
 for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)for(int k=j+1;k<n;k++){I x1=a[i].x,y1=a[i].y,x2=a[j].x,y2=a[j].y,x3=a[k].x,y3=a[k].y,d=2*(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));if(!d)continue;I u=(x1*x1+y1*y1)*(y2-y3)+(x2*x2+y2*y2)*(y3-y1)+(x3*x3+y3*y3)*(y1-y2);I v=(x1*x1+y1*y1)*(x3-x2)+(x2*x2+y2*y2)*(x1-x3)+(x3*x3+y3*y3)*(x2-x1);I dx=x1*d-u,dy=y1*d-v;test({u,v,d,dx*dx+dy*dy});}
 for(auto p:a){I x=I(p.x)*best.d-best.x,y=I(p.y)*best.d-best.y;cout<<(x*x+y*y==best.r);}cout<<'\n';}
#endif
}
