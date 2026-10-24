"""Third independently authored batch; one recipe per exact public source."""
from pathlib import Path
import random
BASE=Path(__file__).resolve().parents[1]/'assets'/'cc_a_batch3'
RECIPES={};_G={};_V={}
H='#include <bits/stdc++.h>\nusing namespace std;using ll=long long;\n'
def I(s):return list(map(int,s.split()))
def B(x,l,h):assert l<=x<=h,(x,l,h)
def E(a,n):assert len(a)==n,(len(a),n)
def L(a):return '\n'.join(map(str,a))+'\n'
def cpp(pid,k,body,mod):
 p=BASE/pid/(k+'.cpp');p.parent.mkdir(parents=True,exist_ok=True);s=H+f'#define MOD {mod}\n'+body
 if not p.exists() or p.read_text()!=s:p.write_text(s)
 return str(p)
def register(pid,row,name,url,gen,val,fast,slow,raw,l3,witness,weak,strong,complexity,proof,tags):
 paths={k:cpp(pid,k,fast if 'fast' in k else slow,1 if k.startswith('l3') else 0) for k in ['raw_fast','raw_oracle','l3_fast','l3_oracle']}
 RECIPES[pid]=dict(**paths,slow_baseline=paths['raw_oracle'],source_id=pid,source_dataset='deepmind/code_contests',source_split='train',source_row_index=row,source_name=name,original_source_identity=f'deepmind/code_contests:train:{row}:{name}',source_url=url,budget_seconds=.7,small_timeout_seconds=2,memory_mb=512,independent_oracles=True,independent_oracle='Different construction: exhaustive search, direct simulation, or literal pair/window enumeration.',raw_spec=raw,l3_spec=raw+'\nSEMANTIC CHANGE: '+l3,l3_change=l3,witness=witness,l2={'weak':weak,'strong':strong,**complexity},proof_sketch=proof,tags=tags)
 _G[pid]=gen;_V[pid]=val

def cases(id,mode,rng):
 if mode=='small':
  for i in range(80):yield f'random_{i:03d}',_G[id](rng.randrange(2**31),'small')
 elif mode=='boundary':
  yield 'semantic_witness',RECIPES[id]['witness']
  for i in range(5):yield f'extra_{i}',_G[id](100000+i,'small')
 elif mode=='weak':
  for i in range(3):yield f'weak_{i}',_G[id](200000+i,'weak')
 elif mode=='stress':yield 'maximum_scale',_G[id](314159,'l2')
 else:raise ValueError(mode)
def validate_input(id,s,condition):return _V[id](s,condition)

# 1366A: resource feasibility with a changed sword recipe.
def shovel_val(s,c):
 a=I(s);t=a[0];B(t,1,1000);E(a,1+2*t)
 for x in a[1:]:B(x,0,10**9);assert c!='weak' or x<=35
 return True
def shovel_gen(seed,c):
 if c=='l2':return '1\n1000000000 1000000000\n'
 r=random.Random(seed);t=r.randint(1,8);return L([t]+[f'{r.randrange(36)} {r.randrange(36)}' for _ in range(t)])
SHF=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){ll a,b;cin>>a>>b;if(!MOD){cout<<min({a,b,(a+b)/3})<<'\n';continue;}ll lo=0,hi=min(a,b);while(lo<hi){ll x=(lo+hi+1)/2;ll low=max(0LL,(3*x-b+1)/2),high=min(x,a-x);if(low<=high)lo=x;else hi=x-1;}cout<<lo<<'\n';}}'''
SHS=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){ll a,b;cin>>a>>b;ll best=0;for(ll x=0;2*x<=a;x++)for(ll y=0;y*(MOD?3:2)<=b;y++)if(2*x+y<=a&&x+(MOD?3:2)*y<=b)best=max(best,x+y);cout<<best<<'\n';}}'''
register('cf_1366_a',439,'1366_A. Shovels and Swords','https://codeforces.com/problemset/problem/1366/A',shovel_gen,shovel_val,SHF,SHS,'With a sticks and b diamonds, a shovel consumes2 sticks+1 diamond and a sword consumes1 stick+2 diamonds. Maximize total tools.','A sword consumes THREE diamonds instead of two; its stick cost and shovel recipe remain unchanged.','1\n1 2\n','a,b<=35','a,b<=10^9',{'fast':'O(1) Raw; O(log(a+b)) L3','slow':'O(ab)'},'Raw optimum is min(a,b,floor((a+b)/3)). For L3, x total tools with h shovels require x+h sticks and3x-2h diamonds, giving the feasible integer interval max(0,ceil((3x-b)/2))<=h<=min(x,a-x). Feasibility is monotone in x, allowing binary search. The oracle enumerates every pair of nonnegative shovel/sword counts.',['integer-optimization','binary-search'])

# 1475D: protected important applications instead of a cost relabeling.
def phone_val(s,c):
 a=I(s);t=a[0];B(t,1,10000);p=1;total=0
 for _ in range(t):
  n,m=a[p:p+2];p+=2;B(n,1,200000);B(m,1,10**9);total+=n;assert p+2*n<=len(a)
  for x in a[p:p+n]:B(x,1,10**9)
  for x in a[p+n:p+2*n]:B(x,1,2)
  p+=2*n
  if c=='weak':B(n,1,15)
 assert p==len(a);B(total,1,200000);return True
def phone_gen(seed,c):
 r=random.Random(seed);n=200000 if c=='l2' else (15 if c=='weak' else r.randint(1,11));mem=[r.randint(1,30) for _ in range(n)];cost=[r.randint(1,2) for _ in range(n)];m=sum(mem)//2 if c=='l2' else r.randint(1,sum(mem)+10)
 return L([1,f'{n} {m}',' '.join(map(str,mem)),' '.join(map(str,cost))])
PHF=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;ll m;cin>>n>>m;vector<ll>a(n),one,two;for(auto&x:a)cin>>x;for(int i=0,b;i<n;i++){cin>>b;if(b==1)one.push_back(a[i]);else if(!MOD)two.push_back(a[i]);}sort(one.rbegin(),one.rend());sort(two.rbegin(),two.rend());vector<ll>p(1),q(1);for(ll x:one)p.push_back(p.back()+x);for(ll x:two)q.push_back(q.back()+x);ll ans=1LL<<60;for(int i=0;i<(int)q.size();i++){ll rem=max(0LL,m-q[i]);auto it=lower_bound(p.begin(),p.end(),rem);if(it!=p.end())ans=min(ans,2LL*i+(it-p.begin()));}cout<<(ans==(1LL<<60)?-1:ans)<<'\n';}}'''
PHS=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;ll m;cin>>n>>m;vector<ll>a(n);vector<int>b(n),on(n);for(auto&x:a)cin>>x;for(auto&x:b)cin>>x;ll best=1LL<<60;while(true){ll sum=0,cost=0;bool ok=true;for(int i=0;i<n;i++)if(on[i]){sum+=a[i];cost+=b[i];if(MOD&&b[i]==2)ok=false;}if(ok&&sum>=m)best=min(best,cost);int j=0;while(j<n&&on[j])on[j++]=0;if(j==n)break;on[j]=1;}cout<<(best==(1LL<<60)?-1:best)<<'\n';}}'''
register('cf_1475_d',444,'1475_D. Cleaning the Phone','https://codeforces.com/problemset/problem/1475/D',phone_gen,phone_val,PHF,PHS,'Remove application occurrences to free at least m memory units while minimizing their total convenience costs b_i in{1,2}. Return-1 if infeasible.','Important applications with b_i=2 are PROTECTED and may not be removed. Other requirements are unchanged.','1\n1 1\n1\n2\n','n<=15','sum n<=200000',{'fast':'O(n log n)','slow':'O(n 2^n)'},'Within each cost category, taking its largest-memory applications dominates every other subset of the same size. Enumerate how many cost2 items to take and binary-search the necessary prefix of cost1 items. L3 omits the protected category. The oracle enumerates all application subsets and checks memory, cost, and protection directly.',['greedy','sorting'])

# 1525D: directional restriction keeps the physical multi-move semantics valid.
def chair_val(s,c):
 a=I(s);n=a[0];B(n,2,5000);E(a,n+1);assert set(a[1:])<={0,1};assert sum(a[1:])<=n//2
 if c=='weak':B(n,2,10)
 return True
def chair_gen(seed,c):
 r=random.Random(seed);n=5000 if c=='l2' else r.randint(2,10);k=n//2 if c=='l2' else r.randint(0,n//2);a=[1]*k+[0]*(n-k)
 if c!='l2':r.shuffle(a)
 return L([n,' '.join(map(str,a))])
CHF=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;vector<int>p,e;for(int i=0,x;i<n;i++){cin>>x;(x?p:e).push_back(i);}const ll INF=1LL<<60;vector<ll>d(p.size()+1,INF);d[0]=0;for(int seat:e)for(int j=(int)p.size();j>=1;j--)if(!MOD||seat>p[j-1])d[j]=min(d[j],d[j-1]+abs(seat-p[j-1]));cout<<(d.back()==INF?-1:d.back())<<'\n';}'''
CHS=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;vector<int>p,e;for(int i=0,x;i<n;i++){cin>>x;(x?p:e).push_back(i);}vector<bool>used(e.size());ll best=1LL<<60;function<void(int,ll)>rec=[&](int at,ll cost){if(at==(int)p.size()){best=min(best,cost);return;}for(int j=0;j<(int)e.size();j++)if(!used[j]&&(!MOD||e[j]>p[at])){used[j]=true;rec(at+1,cost+abs(e[j]-p[at]));used[j]=false;}};rec(0,0);cout<<(best==(1LL<<60)?-1:best)<<'\n';}'''
register('cf_1525_d',446,'1525_D. Armchairs','https://codeforces.com/problemset/problem/1525/D',chair_gen,chair_val,CHF,CHS,'Move seated people so all initially occupied seats become free; each move from i to an empty j costs|i-j|. Initially occupied count is at most half of n. Minimize total time.','Every move must go STRICTLY TO THE RIGHT (j>i). Return-1 if the goal is impossible.','2\n0 1\n','n<=10','n<=5000',{'fast':'O(n^2)','slow':'exhaustive injective assignments'},'Triangle inequality permits replacing any movement chain by direct assignment to a final initially empty seat without increasing time. Crossing assignments can be uncrossed at no greater absolute-distance cost, including with rightward feasibility. DP matches ordered people to a subsequence of ordered empty seats. The oracle enumerates all injective assignments without an ordering assumption.',['dynamic-programming','matching'])

# 272B: a bit-count relation rather than an output transformation.
def dima_val(s,c):
 a=I(s);n=a[0];B(n,1,100000);E(a,n+1)
 for x in a[1:]:B(x,1,10**9)
 if c=='weak':B(n,1,35)
 return True
def dima_gen(seed,c):
 r=random.Random(seed);n=100000 if c=='l2' else r.randint(1,35);return L([n,' '.join(str(r.randint(1,10**9)) for _ in range(n))])
DIF=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;array<ll,33>cnt{};for(int i=0,x;i<n;i++)cin>>x,cnt[__builtin_popcount((unsigned)x)]++;ll ans=0;for(int b=0;b<32;b++)ans+=MOD?cnt[b]*cnt[b+1]:cnt[b]*(cnt[b]-1)/2;cout<<ans<<'\n';}'''
DIS=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;vector<int>w(n);for(int i=0,x;i<n;i++){cin>>x;while(x)w[i]+=x%2,x/=2;}ll ans=0;for(int i=0;i<n;i++)for(int j=0;j<i;j++)ans+=MOD?(abs(w[i]-w[j])==1):(w[i]==w[j]);cout<<ans<<'\n';}'''
register('cf_272_b',452,'272_B. Dima and Sequence','https://codeforces.com/problemset/problem/272/B',dima_gen,dima_val,DIF,DIS,'Count pairs i<j with equal f(a_i), where f(0)=0,f(2x)=f(x),f(2x+1)=f(x)+1 (binary set-bit count).','Count pairs whose set-bit counts differ by EXACTLY ONE instead of being equal.','2\n1 3\n','n<=35','n<=100000',{'fast':'O(n log V)','slow':'O(n^2+n log V)'},'The recurrence defines popcount. Equal weights contribute combinations within buckets, while difference1 contributes products of adjacent buckets. The oracle computes weights through repeated integer division and directly tests all index pairs.',['bits','counting'])

# 343B source wire rule normalizes to equal-pair cancellation.
def current_val(s,c):
 a=s.split();E(a,1);B(len(a[0]),1,100000);assert set(a[0])<=set('+-');assert c!='weak' or len(a[0])<=40;return True
def current_gen(seed,c):
 r=random.Random(seed);w='+-'*25000+'-+'*25000 if c=='l2' else ''.join(r.choice('+-') for _ in range(r.randint(1,40)));return w+'\n'
CUF=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);string s;cin>>s;bool ok;if(MOD)ok=2*count(s.begin(),s.end(),'+')==(int)s.size();else{string st;for(char c:s){if(!st.empty()&&st.back()==c)st.pop_back();else st.push_back(c);}ok=st.empty();}cout<<(ok?"YES":"NO")<<'\n';}'''
CUS=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);string s;cin>>s;while(true){bool found=false;for(int i=0;i+1<(int)s.size();i++)if(MOD?s[i]!=s[i+1]:s[i]==s[i+1]){s.erase(i,2);found=true;break;}if(!found)break;}cout<<(s.empty()?"YES":"NO")<<'\n';}'''
register('cf_343_b',455,'343_B. Alternating Current','https://codeforces.com/problemset/problem/343/B',current_gen,current_val,CUF,CUS,'Decide whether wires can be untangled; in the crossing-sign representation this is equivalent to reducing the whole string by removing adjacent equal signs.','Use the alternative cancellation rule: only adjacent OPPOSITE signs may cancel. OutputYES exactly when the entire string can disappear.','++\n','length<=40','length<=100000',{'fast':'O(length)','slow':'O(length^2)'},'Raw equal-pair reduction has a unique irreducible result and is computed by a stack. Under opposite-pair reduction, each step removes one of each sign, and a nonempty mixture always has an opposite adjacent pair; full reduction is possible exactly when counts match. The independent oracle repeatedly scans and erases a legal pair.',['strings','stack'])
RECIPES['cf_343_b']['budget_seconds']=0.15
RECIPES['cf_343_b']['family_cluster']='adjacent_binary_pair_cancellation'

# 438A: minimum/maximum over finite destruction orders.
def toy_val(s,c):
 a=I(s);n,m=a[:2];B(n,1,1000);B(m,0,2000);E(a,2+n+2*m)
 for x in a[2:2+n]:B(x,0,100000)
 edges=set()
 for i in range(m):
  u,v=a[2+n+2*i:4+n+2*i];B(u,1,n);B(v,1,n);assert u!=v;edge=tuple(sorted((u,v)));assert edge not in edges;edges.add(edge)
 if c=='weak':B(n,1,8)
 return True
def toy_gen(seed,c):
 r=random.Random(seed);n=1000 if c=='l2' else (8 if c=='weak' else r.randint(1,7));m=2000 if c=='l2' else r.randrange(n*(n-1)//2+1);edges=set()
 while len(edges)<m:
  u,v=r.sample(range(1,n+1),2);edges.add(tuple(sorted((u,v))))
 return L([f'{n} {m}',' '.join(str(r.randrange(100001)) for _ in range(n))]+[f'{u} {v}' for u,v in sorted(edges)])
TOF=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,m;cin>>n>>m;vector<ll>a(n);for(auto&x:a)cin>>x;ll ans=0;while(m--){int u,v;cin>>u>>v;u--,v--;ans+=MOD?max(a[u],a[v]):min(a[u],a[v]);}cout<<ans<<'\n';}'''
TOS=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,m;cin>>n>>m;vector<ll>a(n);for(auto&x:a)cin>>x;vector<pair<int,int>>e(m);for(auto&x:e)cin>>x.first>>x.second,x.first--,x.second--;vector<int>p(n),pos(n);iota(p.begin(),p.end(),0);ll best=MOD?-1:(1LL<<60);do{for(int i=0;i<n;i++)pos[p[i]]=i;ll cost=0;for(auto [u,v]:e)cost+=pos[u]<pos[v]?a[v]:a[u];best=MOD?max(best,cost):min(best,cost);}while(next_permutation(p.begin(),p.end()));cout<<best<<'\n';}'''
register('cf_438_a',459,'438_A. The Child and Toy','https://codeforces.com/problemset/problem/438/A',toy_gen,toy_val,TOF,TOS,'Remove every graph vertex exactly once. Removing vertex i costs the sum of values of its still-present neighbors. Minimize the total cost over removal orders.','MAXIMIZE total removal cost instead of minimizing it.','2 1\n1 3\n1 2\n','n<=8','n<=1000,m<=2000',{'fast':'O(n+m)','slow':'O(n!*(n+m))'},'Each edge contributes the value of whichever endpoint is removed later. Descending vertex-value order simultaneously attains min endpoint value on every edge; ascending order attains max. The independent oracle enumerates all removal permutations and directly sums later-neighbor edge costs.',['graphs','greedy'])

# ABC179C: alter positivity of C only.
def product_val(s,c):
 a=I(s);E(a,1);B(a[0],2,1000000);assert c!='weak' or a[0]<=45;return True
def product_gen(seed,c):return str(1000000 if c=='l2' else random.Random(seed).randint(2,45))+'\n'
PRF=r'''int main(){ll n;cin>>n;ll cap=MOD?n:n-1,ans=0;for(ll a=1;a<=cap;a++)ans+=cap/a;cout<<ans<<'\n';}'''
PRS=r'''int main(){ll n;cin>>n;ll ans=0;for(ll a=1;a<=n;a++)for(ll b=1;b<=n;b++)if(MOD?a*b<=n:a*b<n)ans++;cout<<ans<<'\n';}'''
register('atcoder_abc179_c',493,'p02548 AtCoder Beginner Contest 179 - A x B + C','https://atcoder.jp/contests/abc179/tasks/abc179_c',product_gen,product_val,PRF,PRS,'Count positive integer triples(A,B,C) satisfying A*B+C=N.','Allow C=0 as well: A and B remain strictly positive, while C becomes nonnegative.','2\n','N<=45','N<=1000000',{'fast':'O(N)','slow':'O(N^2)'},'For each positive A, eligible B count is floor((N-1)/A) for positive C, and floor(N/A) for nonnegative C. C is uniquely determined. The oracle explicitly enumerates all A,B<=N and tests the product predicate.',['number-theory','counting'])

# ABC095C: exact quantities prohibit otherwise permitted leftovers.
def pizza_val(s,c):
 a=I(s);E(a,5)
 for x in a[:3]:B(x,1,5000)
 for x in a[3:]:B(x,1,10**12 if c=='l2' else 100000)
 if c=='weak':
  for x in a[3:]:B(x,1,35)
 return True
def pizza_gen(seed,c):
 if c=='l2':return '1500 2000 500 1000000000000 999999999999\n'
 r=random.Random(seed);return L([' '.join(map(str,[r.randint(1,50) for _ in range(3)]+[r.randint(1,35) for _ in range(2)]))])
PIF=r'''int main(){ll a,b,c,x,y;cin>>a>>b>>c>>x>>y;ll ans=LLONG_MAX;for(ll k:{0LL,min(x,y),max(x,y)}){if(MOD&&k>min(x,y))continue;ans=min(ans,2*c*k+a*max(0LL,x-k)+b*max(0LL,y-k));}cout<<ans<<'\n';}'''
PIS=r'''int main(){ll a,b,c,x,y;cin>>a>>b>>c>>x>>y;ll ans=LLONG_MAX,limit=MOD?min(x,y):max(x,y);for(ll k=0;k<=limit;k++)ans=min(ans,2*c*k+a*max(0LL,x-k)+b*max(0LL,y-k));cout<<ans<<'\n';}'''
register('atcoder_abc095_c',499,'p03371 AtCoder Beginner Contest 095 - Half and Half','https://atcoder.jp/contests/abc095/tasks/abc095_c',pizza_gen,pizza_val,PIF,PIS,'Buy whole A-pizzas, whole B-pizzas, or pairs of half-A/half-B pizzas. Meet demands X and Y at minimum cost; surplus pizzas are allowed.','Surplus pizzas are FORBIDDEN: the final A and B quantities must equal X and Y exactly.','5 5 1 2 1\n','X,Y<=35','X,Y<=10^12 (source original<=10^5); prices unchanged',{'fast':'O(1)','slow':'O(max(X,Y))'},'Buying k pairs of mixed pizzas gives cost2Ck+A*max(0,X-k)+B*max(0,Y-k), a piecewise linear function with breakpoints0,min(X,Y),max(X,Y). Exact quantities restrict k<=min(X,Y). The oracle independently checks every integer k in the allowed finite interval.',['piecewise-linear','optimization'])
# HackerEarth Max-Min: optimize spread of a fixed-cardinality subset.
def spread_val(s,c):
 a=I(s);n,k=a[:2];B(n,2,99999);B(k,1,n-1);E(a,n+2)
 for x in a[2:]:B(x,1,999999999)
 if c=='weak':B(n,2,15)
 return True
def spread_gen(seed,c):
 r=random.Random(seed);n=99999 if c=='l2' else (15 if c=='weak' else r.randint(2,11));k=n//2 if c=='l2' else r.randint(1,n-1);return L([n,k]+[r.randint(1,999999999 if c=='l2' else 30) for _ in range(n)])
SPF=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,k;cin>>n>>k;vector<ll>a(n);for(auto&x:a)cin>>x;sort(a.begin(),a.end());ll ans;if(MOD)ans=k==1?0:a.back()-a.front();else{ans=LLONG_MAX;for(int i=k-1;i<n;i++)ans=min(ans,a[i]-a[i-k+1]);}cout<<ans<<'\n';}'''
SPS=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,k;cin>>n>>k;vector<ll>a(n);for(auto&x:a)cin>>x;vector<int>on(n);ll best=MOD?-1:LLONG_MAX;while(true){int count=0;ll lo=LLONG_MAX,hi=LLONG_MIN;for(int i=0;i<n;i++)if(on[i])count++,lo=min(lo,a[i]),hi=max(hi,a[i]);if(count==k)best=MOD?max(best,hi-lo):min(best,hi-lo);int j=0;while(j<n&&on[j])on[j++]=0;if(j==n)break;on[j]=1;}cout<<best<<'\n';}'''
register('hackerearth_max_min',488,'max-min','https://www.hackerearth.com/problem/algorithm/max-min/',spread_gen,spread_val,SPF,SPS,'Select exactly K input occurrences and minimize max(selected)-min(selected).','MAXIMIZE the selected spread instead of minimizing it.','3\n2\n1\n2\n5\n','N<=15','N<100000',{'fast':'O(N log N)','slow':'O(N 2^N)'},'An optimum minimum-spread set can be chosen as a contiguous K-window after sorting, because any skipped interior value can replace an extreme without increasing range. For maximum spread and K>=2, include global min/max; K=1 has spread0. The oracle independently enumerates every K-subset.',['sorting','combinations'])

# Spacing constraint changes by one excluded successor.
def time_val(s,c):
 a=I(s);t=a[0];B(t,1,250);p=1
 for _ in range(t):
  n,k=a[p:p+2];p+=2;B(n,1,10000);B(k,0,n-1);assert p+n<=len(a)
  for x in a[p:p+n]:B(x,-10**9,10**9)
  p+=n
  if c=='weak':B(n,1,16)
 assert p==len(a);return True
def time_gen(seed,c):
 r=random.Random(seed);n=10000 if c=='l2' else (16 if c=='weak' else r.randint(1,12));k=1 if c=='l2' else r.randrange(n);return L([1,f'{n} {k}',' '.join(str(r.randint(-10,30)) for _ in range(n))])
TMF=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n,k;cin>>n>>k;vector<ll>d(n+1);for(int i=1;i<=n;i++){ll x;cin>>x;int prev=max(0,i-k-1-MOD);d[i]=max(d[i-1],d[prev]+x);}cout<<d[n]<<'\n';}}'''
TMS=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n,k;cin>>n>>k;vector<ll>a(n);for(auto&x:a)cin>>x;vector<int>on(n);ll best=0;while(true){int last=-1000000000;bool ok=true;ll sum=0;for(int i=0;i<n;i++)if(on[i]){if(i-last<k+1+MOD)ok=false;sum+=a[i];last=i;}if(ok)best=max(best,sum);int j=0;while(j<n&&on[j])on[j++]=0;if(j==n)break;on[j]=1;}cout<<best<<'\n';}}'''
register('hackerearth_time_land',489,'once-upon-a-time-in-time-land','https://www.hackerearth.com/problem/algorithm/once-upon-a-time-in-time-land/',time_gen,time_val,TMF,TMS,'Select any subset of slip indices, including empty, to maximize the sum. Consecutive selected indices must differ by at least K+1, i.e. have at least K intervening unselected slips.','Require selected indices to differ by at least K+2 instead of K+1.','1\n2 0\n1 1\n','N<=16','N<=10000',{'fast':'O(N)','slow':'O(N 2^N)'},'An optimal prefix either omits its last slip or includes it and combines its value with the best prefix ending before the exclusion window. The recurrence changes the predecessor index by one for L3. The independent oracle enumerates subsets and explicitly checks all consecutive selected-index gaps.',['dynamic-programming','spacing'])

# Trie nodes are distinct prefixes; reverse words to share suffixes in L3.
def data_val(s,c):
 a=s.split();n=int(a[0]);B(n,1,100000);E(a,n+1);assert len(set(a[1:]))==n
 for w in a[1:]:B(len(w),1,30);assert w.isascii() and w.islower() and w.isalpha()
 if c=='weak':B(n,1,20)
 return True
def word_code(i,width=6):
 out=[]
 for _ in range(width):out.append(chr(97+i%26));i//=26
 return ''.join(reversed(out))
def data_gen(seed,c):
 r=random.Random(seed);n=100000 if c=='l2' else r.randint(1,20)
 if c=='l2':w=[word_code(i) for i in range(n)]
 else:
  seen=set()
  while len(seen)<n:seen.add(''.join(r.choice('abcd') for _ in range(r.randint(1,7))))
  w=sorted(seen);r.shuffle(w)
 return L([n]+w)
DAF=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;vector<array<int,26>>tr(1);while(n--){string s;cin>>s;if(MOD)reverse(s.begin(),s.end());int node=0;for(char c:s){int k=c-'a';if(!tr[node][k]){tr[node][k]=tr.size();tr.push_back({});}node=tr[node][k];}}cout<<tr.size()<<'\n';}'''
DAS=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;vector<string>all;while(n--){string s;cin>>s;for(int k=1;k<=(int)s.size();k++){string part=MOD?s.substr(s.size()-k):s.substr(0,k);bool exists=false;for(const string&x:all)if(x==part){exists=true;break;}if(!exists)all.push_back(part);}}cout<<all.size()+1<<'\n';}'''
register('hackerearth_cost_of_data',485,'cost-of-data-11','https://www.hackerearth.com/problem/algorithm/cost-of-data-11/',data_gen,data_val,DAF,DAS,'Insert distinct lowercase words into a prefix trie with one root; output its total node count.','Store the words by sharing SUFFIXES instead of prefixes, equivalently insert reversed words into a trie.','2\nab\ncb\n','N<=20,length<=30','N<=100000,length<=30',{'fast':'O(total characters)','slow':'O(total characters^2 * max word length)'},'Each non-root trie node corresponds to exactly one distinct nonempty prefix. Reversal bijects prefixes of reversed words with suffixes of original words. The optimized program constructs nodes; the independent oracle explicitly extracts all prefixes/suffixes and deduplicates by linear comparisons.',['trie','strings'])

# Invitation multiplicity rule, not an arbitrary serialization change.
def birthday_val(s,c):
 a=s.split();t=int(a[0]);B(t,1,10);p=1
 for _ in range(t):
  n=int(a[p]);p+=1;B(n,1,100000);assert p+n<=len(a)
  for w in a[p:p+n]:B(len(w),1,100000)
  p+=n
  if c=='weak':B(n,1,25)
 assert p==len(a);return True
def birthday_gen(seed,c):
 r=random.Random(seed);n=100000 if c=='l2' else r.randint(1,25);names=[word_code(i) for i in range(n-1,-1,-1)] if c=='l2' else [r.choice(['alice','bob','chandu','dave','eve','fiona']) for _ in range(n)];return L([1,n]+names)
BIF=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;cin>>n;map<string,int>cnt;while(n--){string s;cin>>s;cnt[s]++;}for(auto [s,c]:cnt)if(!MOD||c==1)cout<<s<<'\n';}}'''
BIS=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;cin>>n;vector<string>a(n);for(auto&s:a)cin>>s;for(int end=n-1;end>0;end--)for(int j=0;j<end;j++)if(a[j]>a[j+1])swap(a[j],a[j+1]);for(int i=0;i<n;){int j=i+1;while(j<n&&a[j]==a[i])j++;if(!MOD||j-i==1)cout<<a[i]<<'\n';i=j;}}}'''
register('hackerearth_monks_birthday',280,'monks-birthday-party','https://www.hackerearth.com/problem/algorithm/monks-birthday-party/',birthday_gen,birthday_val,BIF,BIS,'Read T invitation-name lists. For each print all distinct names exactly once in lexicographic order.','Invite only names that occurred EXACTLY ONCE in the input list; names mentioned repeatedly are excluded. Maintain lexicographic output order.','1\n3\nalice\nalice\nbob\n','N<=25','N<=100000',{'fast':'O(N log N * name length)','slow':'O(N^2 * name length)'},'A sorted frequency map implements both membership predicates. The independent oracle literally bubble-sorts all occurrences then counts complete equal-name runs and decides whether to emit them.',['sorting','frequency'])

# Combinatorial weights vs exhaustive teams.
def race_val(s,c):
 a=I(s);t=a[0];B(t,1,100);p=1
 for _ in range(t):
  n,k=a[p:p+2];p+=2;B(n,1,100000);B(k,1,n);assert p+n<=len(a);v=a[p:p+n];p+=n;assert len(set(v))==n
  for x in v:B(x,0,2000000000)
  if c=='weak':B(n,1,15)
 assert p==len(a);return True
def race_gen(seed,c):
 r=random.Random(seed);n=100000 if c=='l2' else (15 if c=='weak' else r.randint(1,12));k=n//2 if c=='l2' else r.randint(1,n);a=list(range(n)) if c=='l2' else r.sample(range(101),n);r.shuffle(a);return L([1,f'{n} {k}',' '.join(map(str,a))])
RAF=r'''const ll P=1000000007;ll power(ll a,ll b){ll r=1;for(;b;b>>=1,a=a*a%P)if(b&1)r=r*a%P;return r;}int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n,k;cin>>n>>k;vector<ll>a(n),f(n+1,1),iv(n+1,1);for(auto&x:a)cin>>x;sort(a.begin(),a.end());for(int i=1;i<=n;i++)f[i]=f[i-1]*i%P;iv[n]=power(f[n],P-2);for(int i=n;i;i--)iv[i-1]=iv[i]*i%P;auto choose=[&](int nn,int kk){return nn<kk?0LL:f[nn]*iv[kk]%P*iv[nn-kk]%P;};ll ans=0;for(int i=0;i<n;i++)ans=(ans+a[i]%P*choose(MOD?i:n-i-1,k-1))%P;cout<<ans<<'\n';}}'''
RAS=r'''const ll P=1000000007;int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n,k;cin>>n>>k;vector<ll>a(n);for(auto&x:a)cin>>x;vector<int>on(n);ll ans=0;while(true){int count=0;ll score=MOD?LLONG_MIN:LLONG_MAX;for(int i=0;i<n;i++)if(on[i])count++,score=MOD?max(score,a[i]):min(score,a[i]);if(count==k)ans=(ans+score)%P;int j=0;while(j<n&&on[j])on[j++]=0;if(j==n)break;on[j]=1;}cout<<ans<<'\n';}}'''
register('hackerearth_ankit_race',275,'ankit-and-race-team-10','https://www.hackerearth.com/problem/algorithm/ankit-and-race-team-10/',race_gen,race_val,RAF,RAS,'A team of exactly K distinct students has strength equal to its weakest member. Sum strengths over all K-subsets modulo1000000007; input strengths are distinct.','Team strength equals the STRONGEST member instead of the weakest.','1\n3 2\n1 2 3\n','N<=15','N<=100000',{'fast':'O(N log N)','slow':'O(N 2^N)'},'In sorted order, a_i is the unique minimum of choose(N-i-1,K-1) teams, or maximum of choose(i,K-1) teams. Factorials and inverse factorials evaluate these weights modulo the prime. The oracle enumerates all subsets and computes the team extremum explicitly.',['combinatorics','sorting'])

# Count moved/fixed tests in random permutations.
def derange_val(s,c):
 a=I(s);E(a,3);n,l,h=a;B(n,1,100);B(l,0,n);B(h,l,n);assert c!='weak' or n<=8;return True
def derange_gen(seed,c):
 r=random.Random(seed);n=100 if c=='l2' else (8 if c=='weak' else r.randint(1,7));lo=r.randint(0,n);hi=r.randint(lo,n);return f'{n} {lo} {hi}\n'
DEF=r'''const ll P=1000000007;ll pw(ll a,ll b){ll r=1;for(;b;b>>=1,a=a*a%P)if(b&1)r=r*a%P;return r;}int main(){int n,l,r;cin>>n>>l>>r;vector<ll>d(n+1),f(n+1,1),iv(n+1,1);d[0]=1;for(int i=2;i<=n;i++)d[i]=(i-1)*(d[i-1]+d[i-2])%P;for(int i=1;i<=n;i++)f[i]=f[i-1]*i%P;for(int i=0;i<=n;i++)iv[i]=pw(f[i],P-2);ll ans=0;for(int moved=0;moved<=n;moved++){int x=MOD?n-moved:moved;if(x>=l&&x<=r)ans=(ans+f[n]*iv[moved]%P*iv[n-moved]%P*d[moved])%P;}cout<<ans*iv[n]%P<<'\n';}'''
DES=r'''const ll P=1000000007;ll pw(ll a,ll b){ll r=1;for(;b;b>>=1,a=a*a%P)if(b&1)r=r*a%P;return r;}int main(){int n,l,r;cin>>n>>l>>r;vector<int>p(n);iota(p.begin(),p.end(),0);ll good=0,total=0;do{int fixed=0;for(int i=0;i<n;i++)fixed+=p[i]==i;int x=MOD?fixed:n-fixed;if(l<=x&&x<=r)good=(good+1)%P;total=(total+1)%P;}while(next_permutation(p.begin(),p.end()));cout<<good*pw(total,P-2)%P<<'\n';}'''
register('hackerearth_give_me_my_test',278,'give-me-my-test-monk','https://www.hackerearth.com/problem/algorithm/give-me-my-test-monk/',derange_gen,derange_val,DEF,DES,'Randomly permute N test papers among their owners. Return modulo1000000007 the probability that the number of students receiving someone else paper lies in[L,R].','Apply[L,R] to the number of students receiving THEIR OWN paper instead.','3 0 0\n','N<=8','N<=100',{'fast':'O(N log modulus)','slow':'O(N!*N)'},'Exactly m displaced students can be chosen in C(N,m) ways and deranged in D_m ways, with D_m=(m-1)(D_(m-1)+D_(m-2)). Divide qualifying counts by N! modulo the prime. The oracle enumerates every permutation, counts fixed points directly, and divides observed qualifying counts by the observed total.',['permutations','probability'])

# Saturating predecessor/successor; all n! original permutations remain one seed.
def prev_val(s,c):
 a=I(s);t=a[0];B(t,1,10000);p=1
 for _ in range(t):
  n=a[p];p+=1;B(n,1,1000000);assert p+n<=len(a);v=a[p:p+n];p+=n;assert sorted(v)==list(range(1,n+1));assert c!='weak' or n<=8
 assert p==len(a);return True
def prev_gen(seed,c):
 r=random.Random(seed);n=1000000 if c=='l2' else (8 if c=='weak' else r.randint(1,7));a=list(range(n,0,-1))
 if c!='l2':r.shuffle(a)
 return L([1,n,' '.join(map(str,a))])
PVF=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;cin>>n;vector<int>a(n);for(auto&x:a)cin>>x;auto original=a;bool ok=MOD?next_permutation(a.begin(),a.end()):prev_permutation(a.begin(),a.end());if(!ok)a=original;for(int x:a)cout<<x<<' ';cout<<'\n';}}'''
PVS=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;cin>>n;vector<int>a(n),p(n),last,answer;for(auto&x:a)cin>>x;iota(p.begin(),p.end(),1);while(true){if(p==a){if(MOD){answer=p;if(next_permutation(p.begin(),p.end()))answer=p;}else answer=last.empty()?p:last;break;}last=p;if(!next_permutation(p.begin(),p.end()))break;}for(int x:answer)cout<<x<<' ';cout<<'\n';}}'''
register('hackerearth_lexicographic_predecessor',279,'lexicographically-preceding-permutation','https://www.hackerearth.com/problem/algorithm/lexicographically-preceding-permutation/',prev_gen,prev_val,PVF,PVS,'Output the lexicographic predecessor of each permutation of1..n. The lexicographically least input remains unchanged.','Output the lexicographic SUCCESSOR instead; the lexicographically greatest input remains unchanged.','1\n3\n1 3 2\n','n<=8','n<=1000000',{'fast':'O(n)','slow':'O(n!*n)'},'The optimized predecessor/successor locates the last improvable pivot, swaps with the closest feasible suffix value, and reverses the suffix (standard algorithm). The independent oracle enumerates all permutations from the first one, remembering the previous permutation or taking the next enumerated one upon reaching the input.',['permutations','lexicographic'])

# Source sample deliberately omits the native1440-character day length;
# only native-valid samples enter execution evidence.
def roy_val(s,c):
 a=s.split();n=int(a[0]);B(n,1,365);E(a,n+1)
 for w in a[1:]:assert len(w)==1440 and set(w)<=set('ESC')
 if c=='weak':B(n,1,1)
 return True
def roy_gen(seed,c):
 r=random.Random(seed);n=365 if c=='l2' else (1 if c=='weak' else r.randint(1,3))
 if c=='l2':a=['C'*1440]*n
 elif c=='weak':a=['C'*1440]
 else:a=[''.join(r.choice('ESC') for _ in range(1440)) for _ in range(n)]
 return L([n]+a)
ROF=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;int x=0,y=0,global=0;char target=MOD?'S':'C';while(n--){string s;cin>>s;int local=0;for(char c:s){if(c==target)local++,global++;else local=global=0;x=max(x,local);y=max(y,global);}}cout<<x<<' '<<y<<'\n';}'''
ROS=r'''int longest(const string&s,char ch){int best=0;for(int i=0;i<(int)s.size();i++){int j=i;while(j<(int)s.size()&&s[j]==ch)j++;best=max(best,j-i);}return best;}int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;char ch=MOD?'S':'C';int x=0;string all;while(n--){string s;cin>>s;x=max(x,longest(s,ch));all+=s;}cout<<x<<' '<<longest(all,ch)<<'\n';}'''
register('hackerearth_roys_life_cycle',74,'roys-life-cycle','https://www.hackerearth.com/problem/algorithm/roys-life-cycle/',roy_gen,roy_val,ROF,ROS,'Read N days, exactly1440 actions E/S/C per day. Output the maximum coding(C) streak within any single day and the maximum coding streak across all days including boundaries.','Measure SLEEPING(S) streaks instead of coding(C) streaks.','1\n'+'CC'+'S'*1438+'\n','N=1; day length1440','N<=365; day length1440',{'fast':'O(1440N)','slow':'O((1440N)^2)'},'One counter resets at each day boundary for the daily maximum; a second continues through boundaries for the global maximum. Non-target actions reset both. The oracle independently starts at every position and scans the entire target-character run, once per day and once in the concatenated log.',['strings','runs'])

def check_output(id,input_text,candidate_text,oracle_text,condition):
 if id=='cf_343_b':return candidate_text.lower().split()==oracle_text.lower().split()
 return candidate_text.split()==oracle_text.split()

if __name__=='__main__':
 import json
 (BASE/'recipes.json').write_text(json.dumps(RECIPES,ensure_ascii=False,indent=2)+'\n')
 print('materialized',len(RECIPES),'recipes')


def validate_version_input(id,input_text,condition):
    """Release contract: Raw/L3 use weak limits; source_original preserves native limits."""
    c=condition.lower()
    if c=='source_original':return validate_input(id,input_text,'raw')
    if c=='l2':return validate_input(id,input_text,'l2')
    if c not in {'raw','weak','l3'}:raise ValueError(condition)
    return validate_input(id,input_text,'weak')


def version_cases(id,mode,rng):
    """Filter supplemental native-scale cases to the published version limits."""
    condition='l2' if mode=='stress' else 'weak'
    for name,text in cases(id,mode,rng):
        try:validate_version_input(id,text,condition)
        except (AssertionError,ValueError,IndexError):continue
        yield name,text
