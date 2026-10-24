"""Executable mutation recipes for distinct public CodeContests originals.

This module provides independent optimized / exhaustive implementations, native
input generators and strict validators. Source statements are never rewritten
in-place. L2 weak/strong constraints and L3 changes are explicit metadata.
"""
from pathlib import Path
import random

ASSETS = Path(__file__).resolve().parents[1] / 'assets' / 'codecontests_batch'
HEADER = '#include <bits/stdc++.h>\nusing namespace std; using ll=long long;\n'

def save_cpp(pid, name, body):
    p=ASSETS/pid/(name+'.cpp');p.parent.mkdir(parents=True,exist_ok=True)
    content=HEADER+body
    if not p.exists() or p.read_text(encoding='utf-8')!=content:p.write_text(content,encoding='utf-8')
    return str(p)

def ints(s):
    a=s.split()
    try:return [int(x) for x in a]
    except ValueError:raise ValueError('Non-integer input token')

def bounded(x,a,b):
    assert a<=x<=b,(x,a,b)

def take_exact(a,n):
    assert len(a)==n,(len(a),n)

def lines(a):return '\n'.join(map(str,a))+'\n'

def moving_validate(s,level='small'):
    a=ints(s);n=a[0];bounded(n,2,200000);take_exact(a,1+2*n)
    x=a[1:n+1];v=a[n+1:];assert len(set(x))==n
    for k in x:bounded(k,1,10**8)
    for k in v:bounded(k,-10**8,10**8)
    return True

def moving_generate(seed,level):
    r=random.Random(seed);n=200000 if level=='large' else (20 if level=='medium' else r.randint(2,16))
    x=list(range(1,n+1)) if level=='large' else r.sample(range(1,100),n);r.shuffle(x)
    v=[r.randint(-100,100) for _ in x]
    return lines([n,' '.join(map(str,x)),' '.join(map(str,v))])

MOVING_FAST=r'''
struct BIT{int n; vector<ll> c,s;BIT(int n):n(n),c(n+1),s(n+1){} void add(int i,ll x){for(;i<=n;i+=i&-i)c[i]++,s[i]+=x;} pair<ll,ll> get(int i){ll a=0,b=0;for(;i;i-=i&-i)a+=c[i],b+=s[i];return {a,b};}};
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;vector<ll>x(n),v(n),z;for(auto&a:x)cin>>a;for(auto&a:v)cin>>a;z=v;sort(z.begin(),z.end());z.erase(unique(z.begin(),z.end()),z.end());vector<int>id(n);iota(id.begin(),id.end(),0);sort(id.begin(),id.end(),[&](int a,int b){return x[a]<x[b];});BIT t(z.size());ll ans=0;for(int i:id){int k=lower_bound(z.begin(),z.end(),v[i])-z.begin()+1;if(MOD)k=z.size()-k+1;auto [c,s]=t.get(k);ans+=x[i]*c-s;t.add(k,x[i]);}cout<<ans<<'\n';}
'''
MOVING_BRUTE=r'''
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;vector<ll>x(n),v(n);for(auto&a:x)cin>>a;for(auto&a:v)cin>>a;ll ans=0;for(int i=0;i<n;i++)for(int j=0;j<i;j++){ll dx=x[i]-x[j],dv=v[i]-v[j];bool diverges=(dx>0?dv>=0:dv<=0);if(MOD)diverges=(dx>0?dv<=0:dv>=0);if(diverges)ans+=llabs(dx);}cout<<ans<<'\n';}
'''

def books_validate(s,level='small'):
    a=ints(s);n,k=a[:2];bounded(n,1,200000);bounded(k,1,n);take_exact(a,2+3*n)
    for i in range(n):
        t,x,y=a[2+3*i:5+3*i];bounded(t,1,10000);bounded(x,0,1);bounded(y,0,1)
    return True

def books_generate(seed,level):
    r=random.Random(seed);n=200000 if level=='large' else (16 if level=='medium' else r.randint(1,12));k=n//2 if level=='large' else r.randint(1,n)
    return lines([f'{n} {k}']+[f'{r.randint(1,10000)} {r.randrange(2)} {r.randrange(2)}' for _ in range(n)])
BOOKS_FAST=r'''
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,k;cin>>n>>k;vector<ll>a,b,c,aa,bb;for(int i=0;i<n;i++){ll t;int x,y;cin>>t>>x>>y;if(x)aa.push_back(t);if(y)bb.push_back(t);if(x&&y)c.push_back(t);else if(x)a.push_back(t);else if(y)b.push_back(t);}const ll INF=1LL<<60;ll ans=INF;if(MOD){for(auto z:{aa,bb}){if((int)z.size()<k)continue;sort(z.begin(),z.end());ll s=0;for(int i=0;i<k;i++)s+=z[i];ans=min(ans,s);}}else{sort(a.begin(),a.end());sort(b.begin(),b.end());sort(c.begin(),c.end());vector<ll>pa(1),pb(1),pc(1);for(ll x:a)pa.push_back(pa.back()+x);for(ll x:b)pb.push_back(pb.back()+x);for(ll x:c)pc.push_back(pc.back()+x);for(int j=0;j<=min(k,(int)c.size());j++){int z=k-j;if(z<(int)pa.size()&&z<(int)pb.size())ans=min(ans,pc[j]+pa[z]+pb[z]);}}cout<<(ans==INF?-1:ans)<<'\n';}
'''
BOOKS_BRUTE=r'''
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,k;cin>>n>>k;vector<ll>t(n);vector<int>a(n),b(n),on(n);for(int i=0;i<n;i++)cin>>t[i]>>a[i]>>b[i];ll ans=1LL<<60;while(true){ll cost=0;int x=0,y=0;for(int i=0;i<n;i++)if(on[i])cost+=t[i],x+=a[i],y+=b[i];if(MOD?(x>=k||y>=k):(x>=k&&y>=k))ans=min(ans,cost);int j=0;while(j<n&&on[j])on[j++]=0;if(j==n)break;on[j]=1;}cout<<(ans==(1LL<<60)?-1:ans)<<'\n';}
'''

def trees_validate(s,level='small'):
    a=ints(s);n=a[0];bounded(n,1,100000);take_exact(a,1+2*n);last=0
    for i in range(n):
        x,h=a[1+2*i:3+2*i];bounded(x,1,10**9);bounded(h,1,10**9);assert x>last;last=x
    return True

def trees_generate(seed,level):
    r=random.Random(seed);n=100000 if level=='large' else (10 if level=='medium' else r.randint(1,8));x=0;a=[n]
    for i in range(n):x+=r.randint(1,10);a.append(f'{x} {r.randint(1,15)}')
    return lines(a)
TREES_FAST=r'''
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;array<ll,3>prevR;array<int,3>dp;prevR.fill(-(1LL<<60));dp.fill(0);for(int i=0;i<n;i++){ll x,h;cin>>x>>h;array<ll,3>L={x,x-h,x},R={x,x,x+h};array<int,3>nd;nd.fill(-1000000000);for(int j=0;j<3;j++)for(int k=0;k<3;k++)if(MOD?prevR[k]<=L[j]:prevR[k]<L[j])nd[j]=max(nd[j],dp[k]+(j>0));dp=nd;prevR=R;}cout<<*max_element(dp.begin(),dp.end())<<'\n';}
'''
TREES_BRUTE=r'''
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;vector<ll>x(n),h(n);vector<int>st(n);for(int i=0;i<n;i++)cin>>x[i]>>h[i];int best=0;while(true){bool ok=true;int score=0;ll end=-(1LL<<60);for(int i=0;i<n;i++){ll l=x[i]-(st[i]==1?h[i]:0),rr=x[i]+(st[i]==2?h[i]:0);if(MOD?end>l:end>=l){ok=false;break;}end=rr;score+=(st[i]!=0);}if(ok)best=max(best,score);int j=0;while(j<n&&st[j]==2)st[j++]=0;if(j==n)break;st[j]++;}cout<<best<<'\n';}
'''

def factory_validate(s,level='small'):
    a=ints(s);n,k,hi,lo,q=a[:5];bounded(n,1,200000);bounded(k,1,n);bounded(hi,2,10000);bounded(lo,1,hi-1);bounded(q,1,200000);pos=5;queries=0
    for _ in range(q):
        t=a[pos];pos+=1;bounded(t,1,2)
        if t==1:
            d,v=a[pos:pos+2];pos+=2;bounded(d,1,n);bounded(v,1,10000)
        else:
            p=a[pos];pos+=1;bounded(p,1,n-k+1);queries+=1
    assert pos==len(a) and queries
    return True

def factory_generate(seed,level):
    r=random.Random(seed);n=200000 if level=='large' else r.randint(1,20);q=200000 if level=='large' else r.randint(2,45);k=max(1,n//10) if level=='large' else r.randint(1,n);hi=r.randint(2,100);lo=r.randint(1,hi-1)
    a=[f'{n} {k} {hi} {lo} {q}']
    for j in range(q):
        if j==q-1 or j%2:a.append(f'2 {r.randint(1,n-k+1)}')
        else:a.append(f'1 {r.randint(1,n)} {r.randint(1,120)}')
    return lines(a)
FACTORY_FAST=r'''
struct BIT{int n;vector<ll>v;BIT(int n):n(n),v(n+1){}void add(int i,ll x){for(;i<=n;i+=i&-i)v[i]+=x;}ll sum(int i){ll s=0;for(;i;i-=i&-i)s+=v[i];return s;}};
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,k,a,b,q;cin>>n>>k>>a>>b>>q;BIT x(n),y(n);vector<ll>c(n+1);auto f=[](ll z,ll cap){return MOD?(z<=cap?z:0):min(z,cap);};while(q--){int t,d;cin>>t>>d;if(t==1){ll z;cin>>z;ll old=c[d];c[d]+=z;x.add(d,f(c[d],b)-f(old,b));y.add(d,f(c[d],a)-f(old,a));}else cout<<x.sum(d-1)+y.sum(n)-y.sum(d+k-1)<<'\n';}}
'''
FACTORY_BRUTE=r'''
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,k,a,b,q;cin>>n>>k>>a>>b>>q;vector<ll>c(n+1);while(q--){int t,d;cin>>t>>d;if(t==1){ll z;cin>>z;c[d]+=z;}else{ll ans=0;for(int i=1;i<=n;i++){if(i>=d&&i<d+k)continue;ll cap=i<d?b:a;if(MOD){if(c[i]<=cap)ans+=c[i];}else ans+=min(c[i],cap);}cout<<ans<<'\n';}}}
'''

def stairs_validate(s,level='small'):
    a=ints(s);n,m=a[:2];bounded(n,1,100000);bounded(m,0,n-1);take_exact(a,2+m);assert a[2:]==sorted(set(a[2:]))
    for x in a[2:]:bounded(x,1,n-1)
    return True

def stairs_generate(seed,level):
    r=random.Random(seed);n=100000 if level=='large' else r.randint(1,20);broken=[] if level=='large' else sorted(r.sample(range(1,n),r.randint(0,max(0,n//3))))
    return lines([f'{n} {len(broken)}']+broken)
STAIRS_FAST=r'''
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,m;cin>>n>>m;vector<bool>b(n+1);for(int j=0,x;j<m;j++)cin>>x,b[x]=true;vector<ll>d(n+1);d[0]=1;int jump=MOD?3:2;for(int i=1;i<=n;i++)if(!b[i]){d[i]=d[i-1];if(i>=jump)d[i]+=d[i-jump];d[i]%=1000000007;}cout<<d[n]<<'\n';}
'''
STAIRS_BRUTE=r'''
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,m;cin>>n>>m;vector<bool>b(n+1);for(int j=0,x;j<m;j++)cin>>x,b[x]=true;vector<int>st(1,0);ll ans=0;while(!st.empty()){int u=st.back();st.pop_back();if(u==n){ans=(ans+1)%1000000007;continue;}for(int jump:{1,MOD?3:2})if(u+jump<=n&&!b[u+jump])st.push_back(u+jump);}cout<<ans<<'\n';}
'''

def checkpoint_validate(s,level='small'):
    a=ints(s);n,m=a[:2];cap=200000 if level=='large' else 50;bounded(n,1,cap);bounded(m,1,cap);take_exact(a,2+2*(n+m))
    for x in a[2:]:bounded(x,-10**8,10**8)
    return True

def checkpoint_generate(seed,level):
    r=random.Random(seed);n=m=100000 if level=='large' else r.randint(1,15)
    return lines([f'{n} {m}']+[f'{r.randint(-1000000,1000000)} {r.randint(-1000000,1000000)}' for _ in range(n+m)])
CHECK_FAST=r'''
struct P{ll x,y;int id;};using Q=pair<ll,int>;const ll INF=1LL<<60;Q better(Q a,Q b){if(a.first!=b.first)return a.first>b.first?a:b;return a.second<b.second?a:b;}
struct BIT{int n;vector<Q>d;BIT(int n):n(n),d(n+1,{-INF,INT_MAX}){}void add(int i,Q v){for(;i<=n;i+=i&-i)d[i]=better(d[i],v);}Q get(int i){Q a={-INF,INT_MAX};for(;i;i-=i&-i)a=better(a,d[i]);return a;}};
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,m;cin>>n>>m;vector<P>a(n),b(m);for(int i=0;i<n;i++)cin>>a[i].x>>a[i].y,a[i].id=i;for(int i=0;i<m;i++)cin>>b[i].x>>b[i].y,b[i].id=i+1;vector<ll>d(n,MOD?-1:INF);vector<int>ans(n,INT_MAX);auto update=[&](int i,ll v,int j){if((MOD?v>d[i]:v<d[i])||(v==d[i]&&j<ans[i]))d[i]=v,ans[i]=j;};for(int sx:{-1,1})for(int sy:{-1,1}){vector<P>aa=a,bb=b;for(auto&p:aa)p.x*=sx,p.y*=sy;for(auto&p:bb)p.x*=sx,p.y*=sy;if(MOD){pair<ll,int>ext={INF,INT_MAX};for(auto p:bb)ext=min(ext,make_pair(p.x+p.y,p.id));for(auto p:aa)update(p.id,p.x+p.y-ext.first,ext.second);}else{vector<ll>ys;for(auto p:bb)ys.push_back(p.y);sort(ys.begin(),ys.end());ys.erase(unique(ys.begin(),ys.end()),ys.end());sort(aa.begin(),aa.end(),[](P a,P b){return a.x<b.x;});sort(bb.begin(),bb.end(),[](P a,P b){return a.x<b.x;});BIT t(ys.size());int j=0;for(auto p:aa){while(j<m&&bb[j].x<=p.x){P q=bb[j++];t.add(lower_bound(ys.begin(),ys.end(),q.y)-ys.begin()+1,{q.x+q.y,q.id});}auto z=t.get(upper_bound(ys.begin(),ys.end(),p.y)-ys.begin());if(z.first!=-INF)update(p.id,p.x+p.y-z.first,z.second);}}}for(int x:ans)cout<<x<<'\n';}
'''
CHECK_BRUTE=r'''
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,m;cin>>n>>m;vector<pair<ll,ll>>a(n),b(m);for(auto&p:a)cin>>p.first>>p.second;for(auto&p:b)cin>>p.first>>p.second;for(auto p:a){ll best=MOD?-1:(1LL<<60);int ans=0;for(int j=0;j<m;j++){ll d=llabs(p.first-b[j].first)+llabs(p.second-b[j].second);if(MOD?d>best:d<best)best=d,ans=j+1;}cout<<ans<<'\n';}}
'''

def bubble_validate(s,level='small'):
    a=ints(s);pos=0;count=0;cap=200000 if level=='large' else 100
    while True:
        n=a[pos];pos+=1
        if n==0:break
        bounded(n,1,cap);count+=1;assert pos+n<=len(a)
        for x in a[pos:pos+n]:bounded(x,1,10**6)
        pos+=n
    assert pos==len(a);bounded(count,1,20);return True

def bubble_generate(seed,level):
    r=random.Random(seed);n=200000 if level=='large' else r.randint(1,25);a=list(range(n,0,-1)) if level=='large' else [r.randint(1,12) for _ in range(n)]
    return lines([n]+a+[0])
BUBBLE_FAST=r'''
struct BIT{int n;vector<ll>d;BIT(int n):n(n),d(n+1){}void add(int i){for(;i<=n;i+=i&-i)d[i]++;}ll sum(int i){ll a=0;for(;i;i-=i&-i)a+=d[i];return a;}};
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;while(cin>>n&&n){vector<ll>a(n),v;for(auto&x:a)cin>>x;v=a;sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end());BIT b(v.size());ll ans=0;for(int i=0;i<n;i++){int k=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;ans+=MOD?b.sum(k-1):i-b.sum(k);b.add(k);}cout<<ans<<'\n';}}
'''
BUBBLE_BRUTE=r'''
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;while(cin>>n&&n){vector<ll>a(n);for(auto&x:a)cin>>x;ll ans=0;for(int end=n-1;end>0;end--)for(int j=0;j<end;j++)if(MOD?a[j]<a[j+1]:a[j]>a[j+1]){swap(a[j],a[j+1]);ans++;}cout<<ans<<'\n';}}
'''

def monk_validate(s,level='small'):
    a=ints(s);t=a[0];bounded(t,1,10);pos=1;cap=200000 if level=='large' else 1000
    for _ in range(t):
        n,k=a[pos:pos+2];pos+=2;bounded(n,1,cap);bounded(k,0,n);assert pos+n<=len(a)
        for x in a[pos:pos+n]:bounded(x,0,100000)
        pos+=n
    assert pos==len(a);return True

def monk_generate(seed,level):
    r=random.Random(seed);n=200000 if level=='large' else r.randint(1,16);k=n//2 if level=='large' else r.randint(0,n)
    return lines([1,f'{n} {k}',' '.join(str(r.randrange(100001)) for _ in range(n))])
MONK_FAST=r'''
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n,k;cin>>n>>k;array<int,33>cnt{};for(int i=0,x;i<n;i++)cin>>x,cnt[__builtin_popcount((unsigned)x)]++;ll ans=0;for(int j=0;j<=32;j++){int b=MOD?j:32-j;int take=min(k,cnt[b]);ans+=(ll)b*take;k-=take;}cout<<ans<<'\n';}}
'''
MONK_BRUTE=r'''
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n,k;cin>>n>>k;vector<int>w(n),on(n);for(int i=0,x;i<n;i++){cin>>x;while(x){w[i]+=x%2;x/=2;}}ll best=MOD?(1LL<<60):-1;while(true){int c=0,s=0;for(int i=0;i<n;i++)if(on[i])c++,s+=w[i];if(c==k)best=MOD?min(best,(ll)s):max(best,(ll)s);int j=0;while(j<n&&on[j])on[j++]=0;if(j==n)break;on[j]=1;}cout<<best<<'\n';}}
'''

def discover_validate(s,level='small'):
    a=ints(s);n,q=a[:2];bounded(n,1,100000);bounded(q,1,100000);take_exact(a,2+n+q)
    for x in a[2:]:bounded(x,1,10**9)
    return True

def discover_generate(seed,level):
    r=random.Random(seed);n=q=100000 if level=='large' else r.randint(1,30)
    a=list(range(1,n+1)) if level=='large' else [r.randint(1,15) for _ in range(n)]
    asks=[10**9]*q if level=='large' else [r.randint(1,20) for _ in range(q)]
    return lines([f'{n} {q}',' '.join(map(str,a))]+asks)
DISCOVER_FAST=r'''
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,q;cin>>n>>q;map<ll,int>c;for(int i=0;i<n;i++){ll x;cin>>x;c[x]++;}while(q--){ll x;cin>>x;auto it=c.find(x);cout<<(it!=c.end()&&it->second>=(MOD?2:1)?"YES":"NO")<<'\n';}}
'''
DISCOVER_BRUTE=r'''
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,q;cin>>n>>q;vector<ll>a(n);for(auto&x:a)cin>>x;while(q--){ll x;cin>>x;int count=0;for(ll v:a)if(v==x)count++;cout<<(count>=(MOD?2:1)?"YES":"NO")<<'\n';}}
'''

def merge_validate(s,level='small'):
    a=ints(s);t=a[0];bounded(t,1,100);pos=1
    for _ in range(t):
        n,m=a[pos:pos+2];pos+=2;bounded(n,1,50000);bounded(m,1,50000);assert pos+n+m<=len(a)
        x=a[pos:pos+n];pos+=n;y=a[pos:pos+m];pos+=m
        assert x==sorted(x,reverse=True) and y==sorted(y,reverse=True)
        for z in x+y:bounded(z,0,10**9)
    assert pos==len(a);return True

def merge_generate(seed,level):
    r=random.Random(seed);n=m=50000 if level=='large' else r.randint(1,20)
    if level=='large':a=list(range(2*n,0,-2));b=list(range(2*m-1,-1,-2))
    else:a=sorted([r.randint(0,15) for _ in range(n)],reverse=True);b=sorted([r.randint(0,15) for _ in range(m)],reverse=True)
    return lines([1,f'{n} {m}',' '.join(map(str,a)),' '.join(map(str,b))])
MERGE_FAST=r'''
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n,m;cin>>n>>m;vector<ll>a(n),b(m);for(auto&x:a)cin>>x;for(auto&x:b)cin>>x;int i=0,j=0;ll last=-1;while(i<n||j<m){ll x;if(j==m||(i<n&&a[i]>=b[j]))x=a[i++];else x=b[j++];if(!MOD||x!=last)cout<<x<<' ';last=x;}cout<<'\n';}}
'''
MERGE_BRUTE=r'''
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n,m;cin>>n>>m;vector<ll>a(n+m);for(auto&x:a)cin>>x;for(int end=n+m-1;end>0;end--)for(int j=0;j<end;j++)if(a[j]<a[j+1])swap(a[j],a[j+1]);for(int i=0;i<n+m;i++)if(!MOD||i==0||a[i]!=a[i-1])cout<<a[i]<<' ';cout<<'\n';}}
'''

DATA=[
 ('cf_1311_f',20,'https://codeforces.com/problemset/problem/1311/F',moving_generate,moving_validate,MOVING_FAST,MOVING_BRUTE,'Change admissible time from t >= 0 (future) to t <= 0 (past); sum the minimum pairwise distance over that half-line. Speeds, coordinates and I/O are unchanged.','2\n1 3\n1 2\n',{'weak':'2 <= n <= 20','strong':'n <= 200000','original':'n <= 200000','fast':'O(n log n)','slow':'O(n^2)'},['geometry','fenwick']),
 ('cf_1374_e1',23,'https://codeforces.com/problemset/problem/1374/E1',books_generate,books_validate,BOOKS_FAST,BOOKS_BRUTE,'Replace the requirement that BOTH Alice and Bob like at least k chosen books by EITHER Alice OR Bob liking at least k chosen books (inclusive OR). Minimize the same total reading time.','2 1\n2 1 0\n3 0 1\n',{'weak':'n <= 16','strong':'n <= 200000','original':'n <= 200000','fast':'O(n log n)','slow':'O(n 2^n)'},['greedy','sorting']),
 ('cf_545_c',47,'https://codeforces.com/problemset/problem/545/C',trees_generate,trees_validate,TREES_FAST,TREES_BRUTE,'Allow intervals occupied by adjacent trees to share an endpoint: replace strict separation right_i < left_(i+1) by non-strict separation right_i <= left_(i+1). All other falling and objective rules remain unchanged.','3\n1 1\n2 1\n3 1\n',{'weak':'n <= 10','strong':'n <= 100000','original':'n <= 100000','fast':'O(n)','slow':'O(n 3^n)'},['dynamic-programming','intervals']),
 ('cf_634_c',51,'https://codeforces.com/problemset/problem/634/C',factory_generate,factory_validate,FACTORY_FAST,FACTORY_BRUTE,'Orders due on the SAME day must be accepted as one indivisible batch: a day with c orders and capacity cap contributes c if c <= cap, otherwise 0. Replace partial per-day fulfillment by all-or-nothing fulfillment. Maintenance days still contribute 0.','3 1 3 1 3\n1 1 2\n1 3 4\n2 2\n',{'weak':'n <= 20; q <= 45','strong':'n,q <= 200000','original':'n,q <= 200000','fast':'O((n+q) log n)','slow':'O(nq)'},['fenwick','dynamic-queries']),
 ('atcoder_abc129_c',80,'https://atcoder.jp/contests/abc129/tasks/abc129_c',stairs_generate,stairs_validate,STAIRS_FAST,STAIRS_BRUTE,'Change allowed step sizes from {1,2} to {1,3}. Broken steps, starting and destination steps, and modulus remain unchanged.','3 0\n',{'weak':'N <= 20','strong':'N <= 100000','original':'N <= 100000','fast':'O(N)','slow':'exponential path enumeration'},['dynamic-programming','counting']),
 ('atcoder_abc057_b',85,'https://atcoder.jp/contests/abc057/tasks/abc057_b',checkpoint_generate,checkpoint_validate,CHECK_FAST,CHECK_BRUTE,'Choose the FARTHEST checkpoint by Manhattan distance instead of the NEAREST checkpoint; ties still use the smallest checkpoint index.','1 2\n0 0\n1 0\n4 0\n',{'weak':'N,M <= 50','strong':'N,M <= 100000','original':'N,M <= 50','fast':'O((N+M) log(N+M)) raw; O(N+M) L3','slow':'O(NM)'},['geometry','offline-queries']),
 ('codenet_p00167',88,'https://huggingface.co/datasets/deepmind/code_contests',bubble_generate,bubble_validate,BUBBLE_FAST,BUBBLE_BRUTE,'Sort in DESCENDING rather than ASCENDING order using the stated adjacent bubble procedure, and count exchanges. Equal elements are still never swapped.','3\n3\n2\n1\n0\n',{'weak':'n <= 100','strong':'n <= 200000','original':'n <= 100','fast':'O(n log n)','slow':'O(n^2)'},['sorting','inversions']),
 ('hackerearth_monks_choice_of_numbers',72,'https://www.hackerearth.com/problem/algorithm/monks-choice-of-numbers-1/',monk_generate,monk_validate,MONK_FAST,MONK_BRUTE,'Choose exactly K of the N numbers to MINIMIZE, instead of maximize, the sum of their set-bit counts.','1\n3 1\n0 1 3\n',{'weak':'N <= 16','strong':'N <= 200000','original':'N <= 1000','fast':'O(N log V)','slow':'O(N 2^N)'},['bits','greedy']),
 ('hackerearth_discover_the_monk',69,'https://www.hackerearth.com/problem/algorithm/discover-the-monk/',discover_generate,discover_validate,DISCOVER_FAST,DISCOVER_BRUTE,'For each query X print YES exactly when X occurs AT LEAST TWICE in the array, instead of at least once.','3 3\n1 2 2\n1\n2\n3\n',{'weak':'N,Q <= 30','strong':'N,Q <= 100000','original':'N,Q <= 100000','fast':'O((N+Q) log N)','slow':'O(NQ)'},['search','frequency']),
 ('hackerearth_chandu_girlfriend_returns',68,'https://www.hackerearth.com/problem/algorithm/chandu-and-his-girlfriend-returns/',merge_generate,merge_validate,MERGE_FAST,MERGE_BRUTE,'The output is the SET UNION of both arrays in non-increasing order: emit each distinct value once, instead of retaining its full multiplicity. Input arrays and input protocol remain unchanged.','1\n2 2\n3 2\n3 1\n',{'weak':'N,M <= 20','strong':'N,M <= 50000','original':'N,M <= 50000','fast':'O(N+M)','slow':'O((N+M)^2)'},['merge','sorting'])
]

def get_recipes():
    result=[]
    for pid,row,url,gen,valid,fast,slow,l3,witness,l2,tags in DATA:
        paths={}
        for kind,body in [('fast',fast),('slow',slow)]:
            for mod in [0,1]:paths[('l3_' if mod else 'raw_')+kind]=save_cpp(pid,('l3_' if mod else 'raw_')+kind,'#define MOD '+str(mod)+'\n'+body)
        result.append(dict(id=pid,row_index=row,source='codecontests',source_url=url,generate=gen,validate=valid,programs=paths,l3_change=l3,witness=witness,l2=l2,tags=tags))
    return result



# Public harness interface. Source identities are the exact CodeContests rows;
# the CodeNet p-number must not be mistaken for an AOJ numerical task identifier.
_RECIPES = get_recipes()
_BY_ID = {r['id']: r for r in _RECIPES}
RECIPES = {}
for _r in _RECIPES:
    _p = _r['programs']
    RECIPES[_r['id']] = {
        'source_id': _r['id'],
        'source_dataset': 'deepmind/code_contests',
        'source_split': 'train',
        'source_row_index': _r['row_index'],
        'source_url': _r['source_url'],
        'raw_fast': _p['raw_fast'],
        'raw_oracle': _p['raw_slow'],
        'l3_fast': _p['l3_fast'],
        'l3_oracle': _p['l3_slow'],
        'slow_baseline': _p['raw_slow'],
        'budget_seconds': 0.7,
        'small_timeout_seconds': 2.0,
        'memory_mb': 512,
        'independent_oracles': True,
        'independent_oracle': 'Independently constructed exhaustive enumeration, literal simulation, or direct pair/array scan; optimized implementation uses a different algorithm.',
        'l2': _r['l2'],
        'l3_change': _r['l3_change'],
        'tags': _r['tags'],
        'witness': _r['witness'],
        'raw_spec': 'The exact public original statement is retained separately using source_dataset and source_row_index; native input/output protocol is preserved. Only weak/strong bounds are altered in L2.',
        'l3_spec': _r['l3_change'] + ' All unspecified requirements follow the public original.',
    }

def cases(id, mode, rng):
    r=_BY_ID[id]
    if mode=='small':
        for i in range(80):
            yield (f'random_{i:03d}',r['generate'](rng.randrange(2**31),'small'))
    elif mode=='boundary':
        yield ('semantic_witness',r['witness'])
        for i in range(5):
            yield (f'extra_{i:02d}',r['generate'](100000+i,'small'))
    elif mode=='weak':
        for i in range(3):
            yield (f'weak_{i:02d}',r['generate'](200000+i,'medium'))
    elif mode=='stress':
        yield ('maximum_scale',r['generate'](314159,'large'))
    else:
        raise ValueError(mode)

def validate_input(id, input_text, condition):
    # L2 explicitly expands bounds for the three naturally small source tasks.
    return _BY_ID[id]['validate'](input_text, 'large' if condition=='l2' else 'small')

# Mathematical specifications and proof sketches are authored for these exact
# source problems; they are not evidence of having passed execution tests.
DETAILS = {
'cf_1311_f': (
 'Input n, distinct x[1..n], then v[1..n]. For each unordered pair, minimize |x_i+t*v_i-x_j-t*v_j| over real t>=0, and output the sum as an integer.',
 'After sorting by x, a left/right pair contributes its original distance exactly when v_left<=v_right. Otherwise the points meet in the future. A Fenwick tree over compressed speeds accumulates counts and coordinate sums. For t<=0 the inequality reverses. The oracle scans every pair and checks signed relative position/velocity directly.'),
'cf_1374_e1': (
 'Input n,k followed by triples (positive reading time t, Alice bit a, Bob bit b). Select any subset with at least k Alice-liked AND at least k Bob-liked books. Output minimum sum of times, or -1 if infeasible.',
 'Positive costs exclude unused books. For each count j<=k of books liked by both readers, the minimum completion uses the cheapest max(0,k-j) Alice-only and Bob-only books. Prefix sums over the three sorted groups enumerate all possibilities. The L3 inclusive-OR optimum is the cheaper of the k cheapest Alice-liked books and k cheapest Bob-liked books. The oracle enumerates every subset and checks the stated predicates.'),
'cf_545_c': (
 'Input n and increasing coordinates x_i with positive heights h_i. Choose for each tree a standing point [x_i,x_i], a left interval [x_i-h_i,x_i], or a right interval [x_i,x_i+h_i]. Intervals of distinct trees must be disjoint. Maximize the number of non-standing trees.',
 'Tree intervals contain their original ordered coordinates, so feasibility is equivalent to separation of each adjacent pair. A three-state DP records the last tree direction and occupied right endpoint, checking all nine adjacent transitions. Exhaustive ternary enumeration independently checks every configuration. L3 replaces < by <= in the adjacency predicate, allowing endpoint contact.'),
'cf_634_c': (
 'Input n,k,a,b,q with 1<=b<a. Type 1 d z adds z orders due on day d; type 2 p asks total fillable orders if repairs occupy [p,p+k-1]. A day before p contributes min(c_d,b), a day after the repair interval contributes min(c_d,a), and repair days contribute zero.',
 'Maintain two Fenwick trees holding each day contribution at capacity b and a. An update changes only one entry in each tree; a query is a prefix at p-1 plus a suffix at p+k. L3 replaces contribution min(c,cap) with c if c<=cap else 0, and uses the same exact decomposition. The oracle recomputes contributions by scanning every day for each query.'),
'atcoder_abc129_c': (
 'Input N,M and M strictly increasing broken step indices in [1,N-1]. Count paths from 0 to N using jumps 1 or 2 and never landing on broken steps. Output the count modulo 1000000007.',
 'For every unbroken i, raw dp[i]=dp[i-1]+dp[i-2]; a broken i has dp[i]=0, with dp[0]=1 and negative indices zero. L3 uses i-3 instead of i-2. The oracle enumerates every valid path using an explicit DFS stack and counts only arrivals at N.'),
'atcoder_abc057_b': (
 'Input N student coordinates followed by M checkpoint coordinates. For each student output the one-based index minimizing Manhattan distance, breaking ties by smallest index.',
 'Each checkpoint lies in at least one of four closed quadrants around a query. After sign transforms, a quadrant candidate minimizes distance by maximizing checkpoint x+y subject to x<=query_x,y<=query_y. Sweep x and use a Fenwick maximum over y, retaining minimum index on ties. The minimum over four sweeps is exact. For farthest distance, the identity |dx|+|dy|=max over four signed dx+dy reduces to four coordinate-sum extrema. The oracle scans all checkpoints.'),
'codenet_p00167': (
 'Read datasets: n followed by n integer values, terminated by n=0. In each pass compare adjacent entries from left to right over the unsorted prefix and swap if left>right; shorten the prefix by one each pass. Output the number of swaps for each dataset. Equal entries never swap.',
 'An adjacent strict-inversion swap reduces the inversion count by exactly one, and sorted output has zero inversions. Thus the raw swap count equals the number of pairs i<j with a_i>a_j. A Fenwick count computes this in O(n log n). Descending swaps similarly equal pairs a_i<a_j. The oracle literally runs all bubble-sort passes and counts performed exchanges.'),
'hackerearth_monks_choice_of_numbers': (
 'Read T cases, each with N,K and N nonnegative integers. Choose exactly K values, counting duplicate occurrences separately, to maximize the sum of binary set-bit counts; output that sum.',
 'The objective is additive with a fixed cardinality, so choosing the K greatest weights is optimal by the exchange argument; L3 chooses the K smallest. A frequency table of bit counts performs the selection. The oracle computes bit counts by repeated division and enumerates all subsets of exactly K indices.'),
'hackerearth_discover_the_monk': (
 'Input N,Q, then N array values and Q queried values. For each query X output YES if at least one array occurrence equals X, otherwise NO.',
 'A balanced map counts each value exactly once per occurrence and answers whether its count reaches the required threshold (raw 1, L3 2). The oracle independently scans the entire array for every query and counts equality matches.'),
'hackerearth_chandu_girlfriend_returns': (
 'Read T cases, each with N,M and two arrays sorted in non-increasing order. Output all N+M occurrences merged in non-increasing order, one line per case.',
 'At every merge step the greatest remaining value is one of the two heads, so selecting the larger head preserves the descending invariant. L3 suppresses repetitions adjacent in this merged order, yielding exactly the distinct union. The oracle concatenates both arrays, runs literal descending bubble sort, and optionally suppresses repeated sorted values.')
}
for _pid,(_spec,_proof) in DETAILS.items():
    RECIPES[_pid]['raw_spec']=_spec
    RECIPES[_pid]['proof_sketch']=_proof
    RECIPES[_pid]['l3_spec']=_spec+'\nSEMANTIC CHANGE: '+RECIPES[_pid]['l3_change']

_original_validate_input=validate_input

def validate_input(id,input_text,condition):
    valid=_original_validate_input(id,input_text,condition)
    if condition=='weak':
        a=ints(input_text)
        if id=='cf_1311_f':bounded(a[0],2,20)
        elif id=='cf_1374_e1':bounded(a[0],1,16)
        elif id=='cf_545_c':bounded(a[0],1,10)
        elif id=='cf_634_c':bounded(a[0],1,20);bounded(a[4],1,45)
        elif id=='atcoder_abc129_c':bounded(a[0],1,20)
        elif id=='atcoder_abc057_b':bounded(a[0],1,50);bounded(a[1],1,50)
        elif id=='hackerearth_monks_choice_of_numbers':bounded(a[1],1,16)
        elif id=='hackerearth_discover_the_monk':bounded(a[0],1,30);bounded(a[1],1,30)
        elif id=='hackerearth_chandu_girlfriend_returns':bounded(a[1],1,20);bounded(a[2],1,20)
    if condition=='l2' and id=='atcoder_abc057_b':
        a=ints(input_text);bounded(a[0],1,100000);bounded(a[1],1,100000)
    return valid

# Additional distinct originals. The minimum-sum subsequence tie rule is NOT
# the same as the maximum-sum rule: tied threshold entries must be chosen last.
def subseq_validate(s,level='small'):
    a=ints(s);n=a[0];cap=200000 if level=='large' else 100;bounded(n,1,cap);assert len(a)>n+1
    for x in a[1:n+1]:bounded(x,1,10**9)
    m=a[n+1];bounded(m,1,cap);take_exact(a,n+2+2*m)
    for j in range(m):k,pos=a[n+2+2*j:n+4+2*j];bounded(k,1,n);bounded(pos,1,k)
    return True

def subseq_generate(seed,level):
    r=random.Random(seed);n=200000 if level=='large' else (12 if level=='medium' else r.randint(1,10));m=200000 if level=='large' else r.randint(1,15)
    a=[r.randint(1,10**9 if level=='large' else 7) for _ in range(n)];q=[]
    for _ in range(m):k=r.randint(1,n);q.append(f'{k} {r.randint(1,k)}')
    return lines([n,' '.join(map(str,a)),m]+q)
SUBSEQ_FAST=r'''
struct BIT{int n;vector<int>d;BIT(int n):n(n),d(n+1){}void add(int i){for(;i<=n;i+=i&-i)d[i]++;}int kth(int k){int p=0;for(int b=1<<20;b;b>>=1)if(p+b<=n&&d[p+b]<k)k-=d[p+=b];return p+1;}};
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;vector<ll>a(n);for(auto&x:a)cin>>x;vector<int>order(n);iota(order.begin(),order.end(),0);sort(order.begin(),order.end(),[&](int i,int j){if(a[i]!=a[j])return MOD?a[i]<a[j]:a[i]>a[j];return MOD?i>j:i<j;});int m;cin>>m;vector<array<int,3>>qs(m);for(int i=0;i<m;i++)cin>>qs[i][0]>>qs[i][1],qs[i][2]=i;sort(qs.begin(),qs.end());vector<ll>ans(m);BIT b(n);int added=0;for(auto q:qs){while(added<q[0])b.add(order[added++]+1);ans[q[2]]=a[b.kth(q[1])-1];}for(ll x:ans)cout<<x<<'\n';}
'''
SUBSEQ_BRUTE=r'''
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;vector<ll>a(n);for(auto&x:a)cin>>x;int m;cin>>m;while(m--){int k,pos;cin>>k>>pos;vector<int>on(n);vector<ll>best;ll val=MOD?(1LL<<60):-(1LL<<60);while(true){vector<ll>chosen;ll sum=0;for(int i=0;i<n;i++)if(on[i])chosen.push_back(a[i]),sum+=a[i];if((int)chosen.size()==k){bool improve=MOD?sum<val:sum>val;if(improve||(sum==val&&(best.empty()||chosen<best)))val=sum,best=chosen;}int j=0;while(j<n&&on[j])on[j++]=0;if(j==n)break;on[j]=1;}cout<<best[pos-1]<<'\n';}}
'''

def floppy_validate(s,level='small'):
    a=ints(s);t=a[0];bounded(t,1,10000);p=1;sn=sm=0
    for _ in range(t):
        n,m=a[p:p+2];p+=2;bounded(n,1,200000);bounded(m,1,200000);sn+=n;sm+=m;assert p+n+m<=len(a)
        for x in a[p:p+n]:bounded(x,-10**9,10**9)
        p+=n
        for x in a[p:p+m]:bounded(x,1,10**9)
        p+=m
    assert p==len(a);bounded(sn,1,200000);bounded(sm,1,200000);return True

def floppy_generate(seed,level):
    r=random.Random(seed);n=m=200000 if level=='large' else r.randint(1,20)
    a=[1 if i%3 else -1 for i in range(n)] if level=='large' else [r.randint(-10,10) for _ in range(n)]
    q=[r.randint(1,10**9 if level=='large' else 30) for _ in range(m)]
    return lines([1,f'{n} {m}',' '.join(map(str,a)),' '.join(map(str,q))])
FLOPPY_FAST=r'''
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n,m;cin>>n>>m;vector<ll>mx(n);ll sum=0;for(int i=0;i<n;i++){ll x;cin>>x;sum+=x;mx[i]=i?max(mx[i-1],sum):sum;}while(m--){ll x;cin>>x;x+=MOD;ll cycles=0;if(mx.back()<x){if(sum<=0){cout<<-1<<' ';continue;}cycles=(x-mx.back()+sum-1)/sum;}ll target=x-cycles*sum;int idx=lower_bound(mx.begin(),mx.end(),target)-mx.begin();cout<<cycles*n+idx<<' ';}cout<<'\n';}}
'''
FLOPPY_BRUTE=r'''
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n,m;cin>>n>>m;vector<ll>p(n);ll total=0;for(ll&v:p){cin>>v;total+=v;v=total;}while(m--){ll x;cin>>x;x+=MOD;__int128 best=(__int128)1<<100;for(int i=0;i<n;i++){ll cycles=0;if(p[i]<x){if(total<=0)continue;cycles=(x-p[i]+total-1)/total;}best=min(best,(__int128)cycles*n+i);}cout<<(best==((__int128)1<<100)?-1:(ll)best)<<' ';}cout<<'\n';}}
'''

def addone_validate(s,level='small'):
    a=ints(s);t=a[0];bounded(t,1,200000);take_exact(a,1+2*t)
    for i in range(t):n,m=a[1+2*i:3+2*i];bounded(n,1,10**9);bounded(m,1,200000)
    return True

def addone_generate(seed,level):
    r=random.Random(seed)
    if level=='large':return '1\n999999999 200000\n'
    t=r.randint(1,8)
    return lines([t]+[f'{r.randint(1,10**9)} {r.randint(1,35)}' for _ in range(t)])
ADDONE_FAST=r'''
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;vector<pair<string,int>>queries(T);int mm=0;for(auto&q:queries)cin>>q.first>>q.second,mm=max(mm,q.second);vector<array<ll,10>>d(mm+1);d[0].fill(1);for(int m=1;m<=mm;m++){for(int j=0;j<9;j++)d[m][j]=d[m-1][j+1];d[m][9]=(d[m-1][1]+d[m-1][MOD?1:0])%1000000007;}for(auto q:queries){ll ans=0;for(char c:q.first)ans=(ans+d[q.second][c-'0'])%1000000007;cout<<ans<<'\n';}}
'''
ADDONE_BRUTE=r'''
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){string s;int m;cin>>s>>m;vector<pair<int,int>>st;for(char c:s)st.push_back({c-'0',m});ll ans=0;while(!st.empty()){auto [d,left]=st.back();st.pop_back();int until_split=10-d;if(left<until_split){ans++;if(ans==1000000007)ans=0;}else{left-=until_split;st.push_back({1,left});st.push_back({MOD?1:0,left});}}cout<<ans<<'\n';}}
'''

ADDITIONAL=[
 ('cf_1227_d1',16,'https://codeforces.com/problemset/problem/1227/D1',subseq_generate,subseq_validate,SUBSEQ_FAST,SUBSEQ_BRUTE,'Among subsequences of length k MINIMIZE the element sum instead of maximizing it; among equal optimum sums retain the lexicographically smallest subsequence. Each query still asks for its pos-th value.','3\n2 1 2\n3\n1 1\n2 1\n2 2\n',{'weak':'n,m <= 15 (generated n<=12)','strong':'n,m <= 200000','original':'n,m <= 100','fast':'O((n+m) log n)','slow':'O(m n 2^n)'},['subsequence','fenwick','lexicographic']),
 ('cf_1490_g',28,'https://codeforces.com/problemset/problem/1490/G',floppy_generate,floppy_validate,FLOPPY_FAST,FLOPPY_BRUTE,'Stop only when the running sum is STRICTLY GREATER THAN x, instead of at least x. Time remains zero-based and -1 still denotes an infinite run.','1\n1 1\n1\n1\n',{'weak':'n,m <= 20','strong':'sum(n),sum(m) <= 200000','original':'sum(n),sum(m) <= 200000','fast':'O(n+m log n)','slow':'O(nm)'},['prefix-sums','binary-search']),
 ('cf_1513_c',29,'https://codeforces.com/problemset/problem/1513/C',addone_generate,addone_validate,ADDONE_FAST,ADDONE_BRUTE,'Change the digit replacement for 9 from the two-digit string 10 to the two-digit string 11. Each digit 0..8 is still replaced by d+1; replacements in one operation remain simultaneous.','1\n9 10\n',{'weak':'m <= 35; t <= 8','strong':'m,t <= 200000','original':'m,t <= 200000','fast':'O(max(m)*10 + total input digits)','slow':'explicit exponential digit-expansion tree'},['dynamic-programming','digits'])
]
for _r in ADDITIONAL:
    _pid,_row,_url,_gen,_valid,_fast,_slow,_l3,_witness,_l2,_tags=_r
    _paths={}
    for _kind,_body in [('fast',_fast),('slow',_slow)]:
        for _mod in [0,1]:_paths[('l3_' if _mod else 'raw_')+_kind]=save_cpp(_pid,('l3_' if _mod else 'raw_')+_kind,'#define MOD '+str(_mod)+'\n'+_body)
    _BY_ID[_pid]=dict(id=_pid,row_index=_row,source='codecontests',source_url=_url,generate=_gen,validate=_valid,programs=_paths,l3_change=_l3,witness=_witness,l2=_l2,tags=_tags)
    RECIPES[_pid]=dict(source_id=_pid,source_dataset='deepmind/code_contests',source_split='train',source_row_index=_row,source_url=_url,raw_fast=_paths['raw_fast'],raw_oracle=_paths['raw_slow'],l3_fast=_paths['l3_fast'],l3_oracle=_paths['l3_slow'],slow_baseline=_paths['raw_slow'],budget_seconds=0.7,small_timeout_seconds=2.0,memory_mb=512,independent_oracles=True,independent_oracle='Independent subset enumeration, all-prefix/cycle enumeration, or explicit digit-descendant enumeration.',l2=_l2,l3_change=_l3,tags=_tags,witness=_witness)

DETAILS_EXTRA={
'cf_1227_d1':('Input n, positive array a, m, and m queries (k,pos). For each query select the length-k subsequence with greatest sum, then lexicographically smallest among ties, and output its pos-th element.','Raw chooses the k largest values; equal cutoff values use earliest indices because they are the smallest values in the selected subsequence. L3 chooses k smallest values; equal cutoff values use LATEST indices because they are the largest selected values, so pushing them right gives the lexicographically smallest subsequence. Process queries by increasing k, insert the ranked indices into a Fenwick tree, and locate the pos-th occupied index. The independent oracle enumerates every subset and explicitly compares sum and entire subsequence lexicographically.'),
'cf_1490_g':('Read T cases with n,m, an integer array repeated forever, and m positive query thresholds x. At time0 the sum already includes a[0]. Return the first time when the running sum>=x, or -1 if there is no such time.','Let S be a full-cycle sum and M the maximum first-cycle prefix. If x>M and S<=0, the threshold is never reached; otherwise the earliest feasible cycle is max(0,ceil((x-M)/S)). Binary search first-cycle prefix maxima for the residual target. The independent oracle considers EVERY prefix position i and computes the first feasible cycle at that position, minimizing cycle*n+i using 128-bit intermediate arithmetic. L3 changes the integer threshold to x+1.'),
'cf_1513_c':('Read T pairs (n,m), with n written in decimal. In each of m simultaneous operations replace each digit d by the decimal digits of d+1. Output the final number of digits modulo1000000007.','Each digit evolves independently. DP f[m][d] is f[m-1][d+1] for d<9 and f[m-1][1]+f[m-1][0] for d=9; the L3 latter term is f[m-1][1] twice. Sum over initial digits. The independent oracle enumerates the descendant tree and counts leaves, skipping only nonbranching increments until each digit9 split. Explicit stacks keep memory bounded and prevent recursive stack overflow in L2.')
}
for _pid,(_spec,_proof) in DETAILS_EXTRA.items():
    RECIPES[_pid]['raw_spec']=_spec;RECIPES[_pid]['proof_sketch']=_proof
    RECIPES[_pid]['l3_spec']=_spec+'\nSEMANTIC CHANGE: '+RECIPES[_pid]['l3_change']

_base_validate_input=validate_input

def validate_input(id,input_text,condition):
    valid=_base_validate_input(id,input_text,condition)
    if condition=='weak':
        a=ints(input_text)
        if id=='cf_1227_d1':bounded(a[0],1,15);bounded(a[a[0]+1],1,15)
        elif id=='cf_1490_g':bounded(a[1],1,20);bounded(a[2],1,20)
        elif id=='cf_1513_c':
            bounded(a[0],1,8)
            for i in range(a[0]):bounded(a[2+2*i],1,35)
    return valid



def canonical_validate(s,level='small'):
    a=ints(s);take_exact(a,1);bounded(a[0],1,10);return True

def canonical_generate(seed,level):
    r=random.Random(seed);n=10 if level=='large' else (4 if level=='medium' else r.randint(1,5));return f'{n}\n'
CANONICAL_FAST=r'''
int n;string s;void rec(int pos,int maxid){if(pos==n){cout<<s<<'\n';return;}int upper=maxid+1;for(int z=0;z<=upper;z++){int id=MOD?upper-z:z;s.push_back(MOD?'z'-id:'a'+id);rec(pos+1,max(maxid,id));s.pop_back();}}int main(){ios::sync_with_stdio(false);cin.tie(nullptr);cin>>n;rec(0,-1);}
'''
CANONICAL_BRUTE=r'''
int n;string s;bool canonical(){array<bool,26>seen{};char next=MOD?'z':'a';for(char c:s)if(!seen[c-'a']){if(c!=next)return false;seen[c-'a']=true;next+=MOD?-1:1;}return true;}void rec(int p){if(p==n){if(canonical())cout<<s<<'\n';return;}char low=MOD?'z'-n+1:'a';for(int j=0;j<n;j++){s.push_back(low+j);rec(p+1);s.pop_back();}}int main(){ios::sync_with_stdio(false);cin.tie(nullptr);cin>>n;rec(0);}
'''

def bracket_validate(s,level='small'):
    a=s.split();t=int(a[0]);bounded(t,1,10);take_exact(a,t+1);cap=200000 if level=='large' else 60
    for x in a[1:]:bounded(len(x),1,cap);assert set(x)<=set('()')
    return True

def bracket_generate(seed,level):
    r=random.Random(seed)
    if level=='large':return '1\n'+'('*100000+')'*100000+'\n'
    t=r.randint(1,6);ss=[]
    for j in range(t):
        n=r.randint(1,20)
        if j%3==0:s='('*n+')'*n
        elif j%3==1:s='()'*n
        else:s=''.join(r.choice('()') for _ in range(n))
        ss.append(s)
    return lines([t]+ss)
BRACKET_FAST=r'''
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){string s;cin>>s;int bal=0;bool ok=true;for(int i=0;i<(int)s.size();i++){bal+=s[i]=='('?1:-1;if(bal<0)ok=false;if(MOD&&bal==0&&i+1<(int)s.size())ok=false;}cout<<(ok&&bal==0?"YES":"NO")<<'\n';}}
'''
BRACKET_BRUTE=r'''
bool reduce(string s){while(true){size_t p=s.find("()");if(p==string::npos)break;s.erase(p,2);}return s.empty();}int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){string s;cin>>s;bool ok;if(MOD)ok=s.size()>=2&&s.front()=='('&&s.back()==')'&&reduce(s.substr(1,s.size()-2));else ok=reduce(s);cout<<(ok?"YES":"NO")<<'\n';}}
'''

def subset_validate(s,level='small'):
    a=ints(s);t=a[0];bounded(t,1,999);p=1
    for _ in range(t):
        n,k=a[p:p+2];p+=2;bounded(n,1,999);bounded(k,1,999);assert p+n<=len(a)
        for x in a[p:p+n]:bounded(x,0,99999)
        p+=n
    assert p==len(a);return True

def subset_generate(seed,level):
    r=random.Random(seed)
    if level=='large':return '1\n999 999\n'+' '.join(['2']*999)+'\n'
    n=16 if level=='medium' else r.randint(1,10);k=r.randint(1,25);a=[r.randint(0,35) for _ in range(n)]
    return lines([1,f'{n} {k}',' '.join(map(str,a))])
SUBSET_FAST=r'''
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n,k;cin>>n>>k;vector<bool>d(k+1);d[0]=true;for(int i=0,v;i<n;i++){cin>>v;if(v>k)continue;if(MOD){for(int z=v;z<=k;z++)d[z]=d[z]||d[z-v];}else{for(int z=k;z>=v;z--)d[z]=d[z]||d[z-v];}}cout<<(d[k]?1:0)<<'\n';}}
'''
SUBSET_BRUTE=r'''
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n,k;cin>>n>>k;vector<int>a(n);for(auto&x:a)cin>>x;bool yes=false;if(MOD){vector<vector<int>>memo(n+1,vector<int>(k+1,-1));function<bool(int,int)>rec=[&](int i,int rem){if(rem==0)return true;if(i==n)return false;int&v=memo[i][rem];if(v!=-1)return (bool)v;v=0;if(a[i]==0)return (bool)(v=rec(i+1,rem));for(int count=0;count*a[i]<=rem;count++)if(rec(i+1,rem-count*a[i])){v=1;break;}return (bool)v;};yes=rec(0,k);}else{vector<int>on(n);while(true){ll sum=0;for(int i=0;i<n;i++)if(on[i])sum+=a[i];if(sum==k){yes=true;break;}int j=0;while(j<n&&on[j])on[j++]=0;if(j==n)break;on[j]=1;}}cout<<(yes?1:0)<<'\n';}}
'''

def subtraction_validate(s,level='small'):
    a=ints(s);t=a[0];bounded(t,1,1000000);take_exact(a,1+2*t)
    for i in range(t):n,k=a[1+2*i:3+2*i];bounded(n,1,1000000);bounded(k,1,n)
    return True

def subtraction_generate(seed,level):
    r=random.Random(seed)
    if level=='large':return '1\n1000000 500000\n'
    t=r.randint(1,10);pairs=[]
    for _ in range(t):n=r.randint(1,40);pairs.append(f'{n} {r.randint(1,n)}')
    return lines([t]+pairs)
SUBTRACTION_FAST=r'''
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){ll n,k;cin>>n>>k;bool win=MOD?n%(k+1)!=0:(n-1)%(k+1)!=0;cout<<(win?"Rani":"Nandu")<<'\n';}}
'''
SUBTRACTION_BRUTE=r'''
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n,k;cin>>n>>k;vector<unsigned char>win(n+1);for(int i=1;i<=n;i++){for(int take=1;take<=k;take++){if(take>=i){if(MOD)win[i]=1;break;}if(!win[i-take]){win[i]=1;break;}}}cout<<(win[n]?"Rani":"Nandu")<<'\n';}}
'''

def lucky_validate(s,level='small'):
    a=s.split();t=int(a[0]);bounded(t,1,10);take_exact(a,t+1)
    for x in a[1:]:bounded(len(x),1,100000);assert set(x)<=set('47')
    return True

def lucky_generate(seed,level):
    r=random.Random(seed)
    if level=='large':return '1\n'+'7'*99999+'4\n'
    t=r.randint(1,5)
    return lines([t]+[''.join(r.choice('47') for _ in range(r.randint(1,12))) for _ in range(t)])
LUCKY_FAST=r'''
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){string s;cin>>s;int left=0,count=0,need=MOD?2:1;ll ans=0;for(int right=0;right<(int)s.size();right++){count+=s[right]=='4';while(count>=need){count-=s[left]=='4';left++;}ans+=left;}cout<<ans<<'\n';}}
'''
LUCKY_BRUTE=r'''
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){string s;cin>>s;int n=s.size();ll ans=0;for(int l=0;l<n;l++)for(int r=l;r<n;r++){bool good=false;for(int x=l;x<=r;x++){int a=0,b=0;for(int i=l;i<x;i++)a+=s[i]=='4';for(int i=x;i<=r;i++)b+=s[i]=='7';if(MOD?a>b:a==b){good=true;break;}}ans+=good;}cout<<ans<<'\n';}}
'''

MORE=[
 ('atcoder_panasonic2020_d',78,'https://atcoder.jp/contests/panasonic2020/tasks/panasonic2020_d',canonical_generate,canonical_validate,CANONICAL_FAST,CANONICAL_BRUTE,'For each isomorphism class use its lexicographically LARGEST representative over lowercase English letters, instead of the smallest representative. Continue to print all representatives in lexicographically ascending order.','1\n',{'weak':'N <= 4','strong':'N <= 10','original':'N <= 10','fast':'O(N * Bell(N)) output-sensitive','slow':'O(N * N^N)'},['enumeration','canonicalization']),
 ('codechef_brcktsrm',0,'https://www.codechef.com/problems/BRCKTSRM',bracket_generate,bracket_validate,BRACKET_FAST,BRACKET_BRUTE,'Require the bracket string to be PRIMITIVE BALANCED: balanced and with no nonempty proper prefix that is balanced. Otherwise output NO. The evaluated input alphabet is parentheses ( and ).','1\n()()\n',{'weak':'length <= 60','strong':'length <= 200000','original':'length <= 60','fast':'O(length)','slow':'O(length^2)'},['strings','stack']),
 ('codechef_tf01',5,'https://www.codechef.com/problems/TF01',subset_generate,subset_validate,SUBSET_FAST,SUBSET_BRUTE,'Each listed nonnegative integer may be selected an UNLIMITED number of times, instead of at most once. Decide whether the selected values can sum to K; output 0 or 1 as before.','1\n1 6\n3\n',{'weak':'N <= 16; K <= 25','strong':'N,K <= 999','original':'N,K < 1000','fast':'O(NK)','slow':'O(N 2^N)'},['subset-sum','dynamic-programming']),
 ('hackerearth_subtraction_game_theory',75,'https://www.hackerearth.com/problem/algorithm/subtraction-game-theory-1/',subtraction_generate,subtraction_validate,SUBTRACTION_FAST,SUBTRACTION_BRUTE,'The player who makes the last move (taking n to zero or below) WINS, instead of loses. Both players remain optimal, Rani starts, and a move subtracts any integer from 1 through k.','1\n1 1\n',{'weak':'n <= 40; t <= 10','strong':'n <= 1000000; t <= 1000000','original':'n <= 1000000; t <= 1000000','fast':'O(t)','slow':'O(nk) per case'},['game-theory','dynamic-programming']),
 ('codechef_luckybal',3,'https://www.codechef.com/problems/LUCKYBAL',lucky_generate,lucky_validate,LUCKY_FAST,LUCKY_BRUTE,'For a substring T, require a cut X in [1,|T|] such that the number of 4s in T[1,X-1] is STRICTLY GREATER THAN, instead of equal to, the number of 7s in T[X,|T|]. Count qualifying substrings as before.','1\n4\n',{'weak':'length <= 12','strong':'length <= 100000','original':'length <= 100000','fast':'O(length)','slow':'O(length^4)'},['strings','counting','two-pointers'])
]
for _r in MORE:
    _pid,_row,_url,_gen,_valid,_fast,_slow,_l3,_witness,_l2,_tags=_r
    _paths={}
    for _kind,_body in [('fast',_fast),('slow',_slow)]:
        for _mod in [0,1]:_paths[('l3_' if _mod else 'raw_')+_kind]=save_cpp(_pid,('l3_' if _mod else 'raw_')+_kind,'#define MOD '+str(_mod)+'\n'+_body)
    _BY_ID[_pid]=dict(id=_pid,row_index=_row,source='codecontests',source_url=_url,generate=_gen,validate=_valid,programs=_paths,l3_change=_l3,witness=_witness,l2=_l2,tags=_tags)
    RECIPES[_pid]=dict(source_id=_pid,source_dataset='deepmind/code_contests',source_split='train',source_row_index=_row,source_url=_url,raw_fast=_paths['raw_fast'],raw_oracle=_paths['raw_slow'],l3_fast=_paths['l3_fast'],l3_oracle=_paths['l3_slow'],slow_baseline=_paths['raw_slow'],budget_seconds=0.7,small_timeout_seconds=2.0,memory_mb=512,independent_oracles=True,independent_oracle='Independent exhaustive alphabet/subset enumeration, bracket rewriting, game-state minimax, or literal substring/cut counting.',l2=_l2,l3_change=_l3,tags=_tags,witness=_witness)
MORE_DETAILS={
'atcoder_panasonic2020_d':('Input N. Two lowercase strings are isomorphic when their equality relations between positions coincide. For every isomorphism class of strings of length N, print its lexicographically smallest member; print these members in ascending lexicographic order.','Canonical representatives have restricted-growth first-occurrence labels: each new letter is the smallest unused letter. DFS emits only such strings. For maximum representatives, new letters are z,y,x,..., and DFS child order reverses to retain ascending lexical output. The oracle enumerates all N^N words over the only N letters that could appear, then checks the first-occurrence condition at each completed word.'),
'codechef_brcktsrm':('Read T parenthesis strings and output YES exactly for well-balanced strings. Each opening parenthesis must match a later closing parenthesis, and matches may nest. Evaluation restricts the alphabet to parentheses.','A balanced string has nonnegative prefix balances and zero final balance. Primitive balance additionally requires every nonempty proper prefix to be strictly positive. The oracle repeatedly deletes adjacent () pairs; complete reduction characterizes balance. Primitive balance is equivalent to an opening/closing outer pair surrounding a balanced interior, checked by independent deletion rewriting.'),
'codechef_tf01':('Read T cases, each with N,K and N nonnegative integers less than100000. Output1 if a subset of the N input occurrences sums exactly to positive K, and0 otherwise.','Descending target iteration implements 0/1 knapsack, because each new item reads the previous-item state. L3 ascending iteration permits reuse and solves unbounded knapsack. The raw oracle enumerates all 2^N subsets. The L3 oracle independently enumerates the possible multiplicity of each item in a memoized recursion; zero-valued items are skipped because K is positive.'),
'hackerearth_subtraction_game_theory':('Read T pairs n,k. Rani and Nandu alternate subtracting1..k from the pile n. The player taking n to zero or negative loses. Both play optimally; output the winning name.','Under misere play the losing positive states are n congruent to1 modulo k+1: from those states every nonterminal move reaches a winning state, while every other state can reach one. Under normal play the losing states are n congruent to0. The oracle computes the game graph bottom-up, tries actual legal moves, and handles terminal wins/losses explicitly.'),
'codechef_luckybal':('Read T strings over {4,7}. Count substrings T for which some X in[1,|T|] has equally many4s before X and7s from X through the end.','Writing k=X-1, equality becomes k=the total number of7s because prefix7 counts cancel. Such k exists in[0,|T|-1] iff T contains at least one4. Strict greater becomes k>total7, which is possible iff T contains at least two4s. A sliding window counts substrings with at least one/two4s. The oracle explicitly enumerates substrings and cuts and counts both sides without using the reduction.')
}
for _pid,(_spec,_proof) in MORE_DETAILS.items():
    RECIPES[_pid]['raw_spec']=_spec;RECIPES[_pid]['proof_sketch']=_proof
    RECIPES[_pid]['l3_spec']=_spec+'\nSEMANTIC CHANGE: '+RECIPES[_pid]['l3_change']

_previous_validate_input=validate_input

def validate_input(id,input_text,condition):
    if id in {r[0] for r in MORE}:
        valid=_BY_ID[id]['validate'](input_text,'large' if condition=='l2' else 'small')
        if condition=='weak':
            tok=input_text.split()
            if id=='atcoder_panasonic2020_d':bounded(int(tok[0]),1,4)
            elif id=='codechef_brcktsrm':
                for s in tok[1:]:bounded(len(s),1,60)
            elif id=='codechef_tf01':bounded(int(tok[1]),1,16);bounded(int(tok[2]),1,25)
            elif id=='hackerearth_subtraction_game_theory':
                bounded(int(tok[0]),1,10)
                for j in range(int(tok[0])):bounded(int(tok[1+2*j]),1,40)
            elif id=='codechef_luckybal':
                for s in tok[1:]:bounded(len(s),1,12)
        return valid
    return _previous_validate_input(id,input_text,condition)


SOURCE_NAMES={20: '1311_F. Moving Points', 23: '1374_E1. Reading Books (easy version)', 47: '545_C. Woodcutters', 51: '634_C. Factory Repairs', 80: 'p03013 AtCoder Beginner Contest 129 - Typical Stairs', 85: 'p03774 AtCoder Beginner Contest 057 - Checkpoints', 88: 'p00167 Bubble Sort', 72: 'monks-choice-of-numbers-1', 69: 'discover-the-monk', 68: 'chandu-and-his-girlfriend-returns', 16: '1227_D1. Optimal Subsequences (Easy Version)', 28: '1490_G. Old Floppy Drive ', 29: '1513_C. Add One', 78: 'p02744 Panasonic Programming Contest 2020 - String Equivalence', 0: 'brcktsrm', 5: 'tf01', 75: 'subtraction-game-theory-1', 3: 'luckybal'}
for _cfg in RECIPES.values():
    _cfg['source_name']=SOURCE_NAMES[_cfg['source_row_index']]
    _cfg['original_source_identity']='deepmind/code_contests:train:'+str(_cfg['source_row_index'])+':'+_cfg['source_name']

if __name__=='__main__':
    import json
    (ASSETS/'recipes.json').write_text(json.dumps(RECIPES,ensure_ascii=False,indent=2)+'\n')
    print(f'Wrote {len(RECIPES)} recipes and {len(RECIPES)*4} C++ programs')


def validate_version_input(id,input_text,condition):
    """Release contract: Raw/L3 use weak limits; source_original preserves native limits."""
    c=condition.lower()
    if c=='source_original':return validate_input(id,input_text,'raw')
    if c=='l2':return validate_input(id,input_text,'l2')
    if c not in {'raw','weak','l3'}:raise ValueError(condition)
    return validate_input(id,input_text,'weak')

# Strict release checks visit every testcase, including after the first one.
_release_version_validate=validate_version_input
def validate_version_input(id,input_text,condition):
    valid=_release_version_validate(id,input_text,condition)
    if condition.lower() in {'raw','weak','l3'} and id in {'hackerearth_monks_choice_of_numbers','hackerearth_chandu_girlfriend_returns','cf_1490_g','codechef_tf01'}:
        a=ints(input_text);p=1
        for _ in range(a[0]):
            n,k=a[p:p+2];p+=2
            if id=='hackerearth_monks_choice_of_numbers':bounded(n,1,16);p+=n
            elif id=='hackerearth_chandu_girlfriend_returns':bounded(n,1,20);bounded(k,1,20);p+=n+k
            elif id=='cf_1490_g':bounded(n,1,20);bounded(k,1,20);p+=n+k
            else:bounded(n,1,16);bounded(k,1,25);p+=n
    return valid


def version_cases(id,mode,rng):
    """Filter supplemental native-scale cases to the published version limits."""
    condition='l2' if mode=='stress' else 'weak'
    for name,text in cases(id,mode,rng):
        try:validate_version_input(id,text,condition)
        except (AssertionError,ValueError,IndexError):continue
        yield name,text
