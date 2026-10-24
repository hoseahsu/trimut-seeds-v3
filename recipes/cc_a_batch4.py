"""Fourth independently authored batch; one recipe per exact public source."""
from pathlib import Path
import random
BASE=Path(__file__).resolve().parents[1]/'assets'/'cc_a_batch4'
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

# 757B: change a group admissibility threshold.
def bash_val(s,c):
 a=I(s);n=a[0];B(n,1,100000);E(a,n+1)
 for x in a[1:]:B(x,1,100000)
 if c=='weak':B(n,1,15)
 return True
def bash_gen(seed,c):
 r=random.Random(seed);n=100000 if c=='l2' else (15 if c=='weak' else r.randint(1,12));return L([n,' '.join(str(r.randint(1,100000 if c=='l2' else 40)) for _ in range(n))])
BAF=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;vector<int>f(100001);for(int i=0,x;i<n;i++)cin>>x,f[x]++;int ans=1;for(int d=MOD?3:2;d<=100000;d++){int cnt=0;for(int v=d;v<=100000;v+=d)cnt+=f[v];ans=max(ans,cnt);}cout<<ans<<'\n';}'''
BAS=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;vector<int>a(n),on(n);for(int&x:a)cin>>x;int ans=1;while(true){int g=0,cnt=0;for(int i=0;i<n;i++)if(on[i])g=gcd(g,a[i]),cnt++;if(cnt<=1||g>(MOD?2:1))ans=max(ans,cnt);int j=0;while(j<n&&on[j])on[j++]=0;if(j==n)break;on[j]=1;}cout<<ans<<'\n';}'''
register('cf_757_b',1204,"757_B. Bash's Big Day",'https://codeforces.com/problemset/problem/757/B',bash_gen,bash_val,BAF,BAS,'Choose the largest subset of Pokemon whose strengths have gcd greater than1. A singleton is always allowed, including strength1.','A group of at least two Pokemon is allowed only if its gcd is GREATER THAN TWO; the singleton exception remains.','3\n2 4 6\n','n<=15','n<=100000, strength<=100000',{'fast':'O(V log V+n)','slow':'O(n 2^n log V)'},'Any allowed nonsingleton group has some common divisor d at least the required threshold; taking all input numbers divisible by that d maximizes its size. Enumerate divisors and sum frequency multiples. The oracle enumerates every subset and computes its gcd directly.',['number-theory','sieve'])

# 86D: the multiplicity contribution becomes cubic.
def power_val(s,c):
 a=I(s);n,q=a[:2];B(n,1,200000);B(q,1,200000);E(a,2+n+2*q)
 for x in a[2:2+n]:B(x,1,1000000)
 for i in range(q):
  l,u=a[2+n+2*i:4+n+2*i];B(l,1,n);B(u,l,n)
 if c=='weak':B(n,1,25);B(q,1,25)
 return True
def power_gen(seed,c):
 r=random.Random(seed);n=200000 if c=='l2' else r.randint(1,25);q=200000 if c=='l2' else r.randint(1,25);a=[r.randint(1,30) for _ in range(n)];queries=[]
 for _ in range(q):
  l=1 if c=='l2' else r.randint(1,n);u=n if c=='l2' else r.randint(l,n);queries.append(f'{l} {u}')
 return L([f'{n} {q}',' '.join(map(str,a))]+queries)
POF=r'''using i128=__int128_t;void put(i128 x){if(x>=10)put(x/10);cout<<char('0'+x%10);}int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,q;cin>>n>>q;vector<int>a(n);for(int&x:a)cin>>x;struct Q{int l,r,id;};vector<Q>v(q);for(int i=0;i<q;i++)cin>>v[i].l>>v[i].r,v[i].l--,v[i].r--,v[i].id=i;int b=max(1,(int)sqrt(n));sort(v.begin(),v.end(),[&](Q x,Q y){if(x.l/b!=y.l/b)return x.l/b<y.l/b;return (x.l/b)%2?x.r>y.r:x.r<y.r;});vector<ll>cnt(1000001);vector<i128>ans(q);i128 sum=0;auto value=[](ll k){return MOD?(i128)k*k*k:(i128)k*k;};auto change=[&](int p,int d){ll &k=cnt[a[p]];sum-=value(k)*a[p];k+=d;sum+=value(k)*a[p];};int l=0,r=-1;for(Q z:v){while(l>z.l)change(--l,1);while(r<z.r)change(++r,1);while(l<z.l)change(l++,-1);while(r>z.r)change(r--,-1);ans[z.id]=sum;}for(auto x:ans)put(x),cout<<'\n';}'''
POS=r'''using i128=__int128_t;void put(i128 x){string s;do{s+=char('0'+x%10);x/=10;}while(x);reverse(s.begin(),s.end());cout<<s<<'\n';}int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,q;cin>>n>>q;vector<int>a(n);for(int&x:a)cin>>x;while(q--){int l,r;cin>>l>>r;map<int,ll>cnt;for(int i=l-1;i<r;i++)cnt[a[i]]++;i128 sum=0;for(auto [x,k]:cnt)sum+=(MOD?(i128)k*k*k:(i128)k*k)*x;put(sum);}}'''
register('cf_86_d',1209,'86_D. Powerful array','https://codeforces.com/problemset/problem/86/D',power_gen,power_val,POF,POS,'For each inclusive array query[l,r], output sum over values v of v times the SQUARE of its frequency in that subarray.','Replace the frequency exponent TWO by THREE. Print the exact integer; L3 results may exceed signed64-bit range.','2 1\n2 2\n1 2\n','n,q<=25','n,q<=200000,values<=1000000',{'fast':'O((n+q)sqrt(n))','slow':'O(nq log n)'},'Mo ordering maintains a single window. Adding or removing a value changes only its own multiplicity contribution, evaluated in128-bit arithmetic. The independent oracle builds a fresh ordered frequency map from the literal queried slice.',['range-queries','mo-algorithm'])

# ABC171B.
def juice_val(s,c):
 a=I(s);n,k=a[:2];B(n,1,1000);B(k,1,n);E(a,n+2)
 for x in a[2:]:B(x,1,1000)
 if c=='weak':B(n,1,15)
 return True
def juice_gen(seed,c):
 r=random.Random(seed);n=1000 if c=='l2' else (15 if c=='weak' else r.randint(1,12));return L([f'{n} {r.randint(1,n)}',' '.join(str(r.randint(1,1000)) for _ in range(n))])
JUF=r'''int main(){int n,k;cin>>n>>k;vector<int>a(n);for(int&x:a)cin>>x;sort(a.begin(),a.end());if(MOD)reverse(a.begin(),a.end());cout<<accumulate(a.begin(),a.begin()+k,0LL)<<'\n';}'''
JUS=r'''int main(){int n,k;cin>>n>>k;vector<int>a(n),on(n);for(int&x:a)cin>>x;ll best=MOD?-1:(1LL<<60);while(true){int cnt=0;ll sum=0;for(int i=0;i<n;i++)if(on[i])cnt++,sum+=a[i];if(cnt==k)best=MOD?max(best,sum):min(best,sum);int j=0;while(j<n&&on[j])on[j++]=0;if(j==n)break;on[j]=1;}cout<<best<<'\n';}'''
register('atcoder_abc171_b',1225,'p02628 AtCoder Beginner Contest 171 - Mix Juice','https://atcoder.jp/contests/abc171/tasks/abc171_b',juice_gen,juice_val,JUF,JUS,'Choose exactly K distinct fruit occurrences among N prices and minimize their total price.','MAXIMIZE the total price of exactly K chosen fruits.','3 2\n1 2 3\n','N<=15','N<=1000',{'fast':'O(N log N)','slow':'O(N 2^N)'},'An exchange replacing a selected larger price by an unselected smaller one proves the minimum uses K smallest prices. The reverse exchange proves the maximum. The oracle explicitly visits all subsets of sizeK.',['sorting','selection'])

# DP-K: change who wins when no move exists.
def stones_val(s,c):
 a=I(s);n,k=a[:2];B(n,1,100);B(k,1,100000);E(a,n+2);assert a[2:]==sorted(set(a[2:]))
 for x in a[2:]:B(x,1,k)
 if c=='weak':B(k,1,20)
 return True
def stones_gen(seed,c):
 if c=='l2':return '2 100000\n1 2\n'
 r=random.Random(seed);k=r.randint(1,20);moves=sorted(r.sample(range(1,k+1),r.randint(1,min(k,5))));return L([f'{len(moves)} {k}',' '.join(map(str,moves))])
STF=r'''int main(){int n,k;cin>>n>>k;vector<int>a(n);for(int&x:a)cin>>x;vector<int>w(k+1);for(int x=0;x<=k;x++){bool any=false;for(int z:a)if(z<=x){any=true;if(!w[x-z]){w[x]=1;break;}}if(!any)w[x]=MOD;}cout<<(w[k]?"First":"Second")<<'\n';}'''
STS=r'''int main(){int n,k;cin>>n>>k;vector<int>a(n);for(int&x:a)cin>>x;struct F{int pile,next;bool waiting;};vector<F>st{{k,0,false}};bool last=false;while(!st.empty()){F &f=st.back();if(f.waiting){f.waiting=false;if(!last){last=true;st.pop_back();continue;}}if(f.next==0&&a[0]>f.pile){last=MOD;st.pop_back();continue;}if(f.next==n||a[f.next]>f.pile){last=false;st.pop_back();continue;}int child=f.pile-a[f.next++];f.waiting=true;st.push_back({child,0,false});}cout<<(last?"First":"Second")<<'\n';}'''
register('atcoder_dp_k',1229,'p03170 Educational DP Contest - Stones','https://atcoder.jp/contests/dp/tasks/dp_k',stones_gen,stones_val,STF,STS,'Players alternately subtract a number of stones belonging to the given move set. A player with no legal move loses. OutputFirst if the initial player can force a win, elseSecond.','A player whose turn has NO LEGAL MOVE WINS instead of losing. Legal moves and optimal play are unchanged.','1 1\n1\n','K<=20','N<=100,K<=100000',{'fast':'O(NK)','slow':'uncached exponential game-tree search'},'For nonterminal piles, a state is winning iff at least one successor is losing. Only the terminal base case changes. Bottom-up DP reuses states; the oracle independently evaluates the literal game tree with an explicit traversal stack and no memoization.',['games','dynamic-programming'])

# ABC070D: remove the mandatory transit vertex.
def tree_val(s,c):
 a=I(s);n=a[0];B(n,3,100000);p=1;parent=list(range(n))
 def find(x):
  while parent[x]!=x:parent[x]=parent[parent[x]];x=parent[x]
  return x
 for _ in range(n-1):
  u,v,w=a[p:p+3];p+=3;B(u,1,n);B(v,1,n);B(w,1,10**9);ru,rv=find(u-1),find(v-1);assert ru!=rv;parent[ru]=rv
 q,k=a[p:p+2];p+=2;B(q,1,100000);B(k,1,n);E(a,p+2*q)
 for i in range(q):
  u,v=a[p+2*i:p+2*i+2];B(u,1,n);B(v,1,n);assert u!=v and u!=k and v!=k
 if c=='weak':B(n,3,25);B(q,1,25)
 return True
def tree_gen(seed,c):
 r=random.Random(seed);n=100000 if c=='l2' else r.randint(3,25);q=100000 if c=='l2' else r.randint(1,25);k=1 if c=='l2' else r.randint(1,n);e=[f'{i} {i-1 if c=="l2" else r.randint(1,i-1)} {r.randint(1,100)}' for i in range(2,n+1)];other=[i for i in range(1,n+1) if i!=k];queries=[f'{n-1} {n}' if c=='l2' else ' '.join(map(str,r.sample(other,2))) for _ in range(q)];return L([n]+e+[f'{q} {k}']+queries)
TRF=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;vector<vector<pair<int,int>>>g(n);for(int i=1,u,v,w;i<n;i++){cin>>u>>v>>w;--u,--v;g[u].push_back({v,w});g[v].push_back({u,w});}int q,k;cin>>q>>k;--k;vector<array<int,20>>up(n);vector<int>dep(n),p(n,-1),order{k};vector<ll>d(n);p[k]=k;up[k].fill(k);for(int h=0;h<(int)order.size();h++){int u=order[h];for(auto [v,w]:g[u])if(v!=p[u]){p[v]=u;dep[v]=dep[u]+1;d[v]=d[u]+w;up[v][0]=u;for(int j=1;j<20;j++)up[v][j]=up[up[v][j-1]][j-1];order.push_back(v);}}auto lca=[&](int u,int v){if(dep[u]<dep[v])swap(u,v);for(int j=19;j>=0;j--)if(dep[u]-(1<<j)>=dep[v])u=up[u][j];if(u==v)return u;for(int j=19;j>=0;j--)if(up[u][j]!=up[v][j])u=up[u][j],v=up[v][j];return up[u][0];};while(q--){int u,v;cin>>u>>v;--u,--v;cout<<d[u]+d[v]-(MOD?2*d[lca(u,v)]:0)<<'\n';}}'''
TRS=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;vector<vector<pair<int,int>>>g(n);for(int i=1,u,v,w;i<n;i++){cin>>u>>v>>w;--u,--v;g[u].push_back({v,w});g[v].push_back({u,w});}int q,k;cin>>q>>k;--k;auto distance=[&](int start,int target){vector<int>p(n,-1),v{start};vector<ll>d(n);p[start]=start;for(int i=0;i<(int)v.size();i++){int u=v[i];if(u==target)return d[u];for(auto [z,w]:g[u])if(p[z]<0)p[z]=u,d[z]=d[u]+w,v.push_back(z);}return -1LL;};while(q--){int u,v;cin>>u>>v;--u,--v;cout<<(MOD?distance(u,v):distance(u,k)+distance(k,v))<<'\n';}}'''
register('atcoder_abc070_d',1232,'p03634 AtCoder Beginner Contest 070 - Transit Tree Path','https://atcoder.jp/contests/abc070/tasks/abc070_d',tree_gen,tree_val,TRF,TRS,'For each pair of vertices x,y in a positive-weight tree, output the length of the shortest walk from x to y that passes through the specified vertexK.','The walk is no longer required to pass throughK: output the ordinary shortest x-to-y distance.','3\n1 2 1\n2 3 1\n1 1\n2 3\n','N,Q<=25','N,Q<=100000',{'fast':'O((N+Q)log N)','slow':'O(NQ)'},'A tree has a unique path between any two vertices. ViaK length is distK[x]+distK[y]. Ordinary path length subtracts twice the distance of their lowest common ancestor when rooted atK. The oracle traverses the tree independently for each requested source-target distance.',['trees','lca'])

#1257C: require at least three occurrences of the unique mode.
def dominated_val(s,c):
 a=I(s);t=a[0];B(t,1,1000);p=1;total=0
 for _ in range(t):
  n=a[p];p+=1;B(n,1,200000);total+=n;assert p+n<=len(a)
  for x in a[p:p+n]:B(x,1,n)
  p+=n
  if c=='weak':B(n,1,30)
 E(a,p);B(total,1,200000);return True
def dominated_gen(seed,c):
 r=random.Random(seed);n=200000 if c=='l2' else r.randint(1,30);a=list(range(1,n+1)) if c=='l2' else [r.randint(1,n) for _ in range(n)];return L([1,n,' '.join(map(str,a))])
DOF=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;cin>>n;vector<int>last(n+1,-1),prev(n+1,-1);int ans=n+1;for(int i=0,x;i<n;i++){cin>>x;int p=MOD?prev[x]:last[x];if(p>=0)ans=min(ans,i-p+1);prev[x]=last[x];last[x]=i;}cout<<(ans==n+1?-1:ans)<<'\n';}}'''
DOS=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;cin>>n;vector<int>a(n);for(int&x:a)cin>>x;int ans=n+1;for(int l=0;l<n;l++){vector<int>f(n+1);int top=0,ties=0;for(int r=l;r<n;r++){int z=++f[a[r]];if(z>top)top=z,ties=1;else if(z==top)ties++;if(r>l&&ties==1&&top>=(MOD?3:2))ans=min(ans,r-l+1);}}cout<<(ans==n+1?-1:ans)<<'\n';}}'''
register('cf_1257_c',1270,'1257_C. Dominated Subarray','https://codeforces.com/problemset/problem/1257/C',dominated_gen,dominated_val,DOF,DOS,'Find the shortest contiguous subarray of length at least2 that has a unique most-frequent value; return-1 if none exists.','Additionally require that the unique most-frequent value occurs at least THREE times.','1\n3\n1 1 1\n','n<=30','sum n<=200000',{'fast':'O(n)','slow':'O(n^2)'},'For thresholdr=2 or3, minimize the span of r consecutive occurrences of any value. A globally shortest such span cannot contain r occurrences of a different value, since their endpoints would be strictly inside, yielding a shorter span. Thus its mode is unique. Conversely every valid subarray contains such a span. The oracle explicitly enumerates windows and tracks maximum frequency and ties.',['arrays','occurrence-gaps'])

#1324D.
def topics_val(s,c):
 a=I(s);n=a[0];B(n,2,200000);E(a,1+2*n)
 for x in a[1:]:B(x,1,10**9)
 if c=='weak':B(n,2,35)
 return True
def topics_gen(seed,c):
 r=random.Random(seed);n=200000 if c=='l2' else r.randint(2,35);return L([n,' '.join(str(r.randint(1,30)) for _ in range(n)),' '.join(str(r.randint(1,30)) for _ in range(n))])
TPF=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;vector<ll>d(n);for(ll&x:d)cin>>x;for(int i=0,x;i<n;i++)cin>>x,d[i]-=x;sort(d.begin(),d.end());ll ans=0;int l=0,r=n-1;while(l<r){if(MOD?d[l]+d[r]>=0:d[l]+d[r]>0)ans+=r-l,r--;else l++;}cout<<ans<<'\n';}'''
TPS=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;vector<ll>a(n),b(n);for(ll&x:a)cin>>x;for(ll&x:b)cin>>x;ll ans=0;for(int i=0;i<n;i++)for(int j=0;j<i;j++)ans+=MOD?a[i]+a[j]>=b[i]+b[j]:a[i]+a[j]>b[i]+b[j];cout<<ans<<'\n';}'''
register('cf_1324_d',1273,'1324_D. Pair of Topics','https://codeforces.com/problemset/problem/1324/D',topics_gen,topics_val,TPF,TPS,'Count index pairs i<j such that a_i+a_j>b_i+b_j.','Accept equal total interestingness too: replace the strict comparison by GREATER THAN OR EQUAL.','2\n1 1\n1 1\n','n<=35','n<=200000',{'fast':'O(n log n)','slow':'O(n^2)'},'Subtract student ratings from teacher ratings. Sorting the differences allows a two-pointer count: when the smallest-plus-largest passes, all remaining partners of that largest pass. The oracle tests the original four-term inequality for each pair.',['sorting','two-pointers'])

#1343C.
def alternating_val(s,c):
 a=I(s);t=a[0];B(t,1,10000);p=1;total=0
 for _ in range(t):
  n=a[p];p+=1;B(n,1,200000);total+=n;assert p+n<=len(a)
  for x in a[p:p+n]:B(x,-10**9,10**9);assert x!=0
  p+=n
  if c=='weak':B(n,1,15)
 E(a,p);B(total,1,200000);return True
def alternating_gen(seed,c):
 r=random.Random(seed);n=200000 if c=='l2' else (15 if c=='weak' else r.randint(1,12));return L([1,n,' '.join(str(r.choice([-1,1])*r.randint(1,100)) for _ in range(n))])
ALF=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;cin>>n;ll ans=0,cur;cin>>cur;for(int i=1;i<n;i++){ll x;cin>>x;if((cur>0)==(x>0))cur=MOD?min(cur,x):max(cur,x);else ans+=cur,cur=x;}cout<<ans+cur<<'\n';}}'''
ALS=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;cin>>n;vector<ll>a(n);vector<int>on(n);for(ll&x:a)cin>>x;int bestlen=-1;ll best=0;while(true){int len=0,prev=0;ll sum=0;bool ok=true;for(int i=0;i<n;i++)if(on[i]){int sign=a[i]>0?1:-1;if(sign==prev)ok=false;prev=sign;len++;sum+=a[i];}if(ok&&(len>bestlen||(len==bestlen&&(MOD?sum<best:sum>best))))bestlen=len,best=sum;int j=0;while(j<n&&on[j])on[j++]=0;if(j==n)break;on[j]=1;}cout<<best<<'\n';}}'''
register('cf_1343_c',1274,'1343_C. Alternating Subsequence','https://codeforces.com/problemset/problem/1343/C',alternating_gen,alternating_val,ALF,ALS,'Among all sign-alternating subsequences, first maximize the length, then maximize their sum. Output that sum.','Keep maximum length as the primary objective, but MINIMIZE the sum among maximum-length alternating subsequences.','1\n4\n1 2 -1 -2\n','n<=15','sum n<=200000',{'fast':'O(n)','slow':'O(n 2^n)'},'Every maximal equal-sign run contributes at most one selected item, and taking one from every run attains the largest length. Optimizing sum then independently selects the maximum/minimum of each run. The oracle enumerates all subsequences and evaluates both objectives directly.',['greedy','subsequences'])

#1385D.
def good_val(s,c):
 a=s.split();t=int(a[0]);B(t,1,20000);E(a,1+2*t);total=0
 for i in range(t):
  n=int(a[1+2*i]);w=a[2+2*i];B(n,1,131072);assert n&(n-1)==0;assert len(w)==n and all('a'<=x<='z' for x in w);total+=n
  if c=='weak':B(n,1,32)
 B(total,1,200000);return True
def good_gen(seed,c):
 r=random.Random(seed);n=131072 if c=='l2' else 2**r.randint(0,5);return L([1,n,'a'*n if c=='l2' else ''.join(r.choice('abcde') for _ in range(n))])
GOF=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;string s;cin>>n>>s;function<int(int,int,char)>go=[&](int l,int r,char c){if(r-l==1)return int(s[l]!=c);int m=(l+r)/2,left=0,right=0;char fixed=c+(MOD?1:0);for(int i=l;i<m;i++)left+=s[i]!=fixed;for(int i=m;i<r;i++)right+=s[i]!=fixed;return min(left+go(m,r,c+1),right+go(l,m,c+1));};cout<<go(0,n,'a')<<'\n';}}'''
GOS=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;string s;cin>>n>>s;int best=n;for(int leaf=0;leaf<n;leaf++){int cost=0;for(int i=0;i<n;i++){int l=0,r=n;char c='a',want='a';while(r-l>1){int m=(l+r)/2;bool side=leaf>=m;if((i>=m)!=side){want=c+(MOD?1:0);break;}if(side)l=m;else r=m;c++;want=c;}cost+=s[i]!=want;}best=min(best,cost);}cout<<best<<'\n';}}'''
register('cf_1385_d',1276,'1385_D. a-Good String','https://codeforces.com/problemset/problem/1385/D',good_gen,good_val,GOF,GOS,'A length1 c-good string equals c. At larger power-of-two lengths, one half consists entirely of c and the other is(c+1)-good. Minimize substitutions needed to make the input a-good.','At every nonleaf recursion, the constant half must consist of character c+1 instead of c. The other half is still(c+1)-good, and the length1 base case still equals c.','1\n2\naa\n','n<=32','power-of-two n<=131072,total n<=200000',{'fast':'O(n log n)','slow':'O(n^2 log n)'},'For either choice of constant half, its substitution cost is fixed and the other half is an independent recursive problem. Take the smaller orientation cost. Separately, every valid target corresponds to one final recursive leaf; the oracle enumerates leaves and reconstructs each target character by following that leaf path.',['divide-and-conquer','strings'])

#1475C.
def ball_val(s,c):
 z=I(s);t=z[0];B(t,1,10000);p=1;sums=[0,0,0]
 for _ in range(t):
  a,b,k=z[p:p+3];p+=3
  for i,x in enumerate([a,b,k]):B(x,1,200000);sums[i]+=x
  assert p+2*k<=len(z);left=z[p:p+k];right=z[p+k:p+2*k];p+=2*k
  for x in left:B(x,1,a)
  for x in right:B(x,1,b)
  assert len(set(zip(left,right)))==k
  if c=='weak':B(k,1,35)
 E(z,p)
 for x in sums:B(x,1,200000)
 return True
def ball_gen(seed,c):
 r=random.Random(seed)
 if c=='l2':a,b,k=1,200000,200000;edges=[(1,i) for i in range(1,b+1)]
 else:
  a,b=r.randint(1,8),r.randint(1,8);k=r.randint(1,min(35,a*b));edges=r.sample([(i,j) for i in range(1,a+1) for j in range(1,b+1)],k)
 return L([1,f'{a} {b} {k}',' '.join(str(x) for x,y in edges),' '.join(str(y) for x,y in edges)])
BLF=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int a,b,k;cin>>a>>b>>k;vector<ll>x(a+1),y(b+1);for(int i=0,v;i<k;i++)cin>>v,x[v]++;for(int i=0,v;i<k;i++)cin>>v,y[v]++;ll bad=0;for(ll v:x)bad+=v*(v-1)/2;for(ll v:y)bad+=v*(v-1)/2;cout<<(MOD?bad:1LL*k*(k-1)/2-bad)<<'\n';}}'''
BLS=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int a,b,k;cin>>a>>b>>k;vector<int>x(k),y(k);for(int&v:x)cin>>v;for(int&v:y)cin>>v;ll ans=0;for(int i=0;i<k;i++)for(int j=0;j<i;j++){int shared=(x[i]==x[j])+(y[i]==y[j]);ans+=shared==(MOD?1:0);}cout<<ans<<'\n';}}'''
register('cf_1475_c',1385,'1475_C. Ball in Berland','https://codeforces.com/problemset/problem/1475/C',ball_gen,ball_val,BLF,BLS,'Given distinct allowed boy-girl dance pairs, count unordered pairs of these edges that share no dancer.','Count unordered pairs of allowed edges that share EXACTLY ONE dancer instead.','1\n1 2 2\n1 1\n1 2\n','k<=35','sum a,b,k individually<=200000',{'fast':'O(a+b+k)','slow':'O(k^2)'},'Because no edge repeats, two different edges cannot share both endpoints. The number sharing one endpoint equals the sum of choose(degree,2) over both vertex classes. Subtract this from choose(k,2) for Raw; keep it for L3. The oracle directly checks both endpoints for every edge pair.',['graphs','counting'])

#1165B.
def training_val(s,c):
 a=I(s);n=a[0];B(n,1,200000);E(a,n+1)
 for x in a[1:]:B(x,1,200000)
 if c=='weak':B(n,1,15)
 return True
def training_gen(seed,c):
 r=random.Random(seed);n=200000 if c=='l2' else (15 if c=='weak' else r.randint(1,12));return L([n,' '.join(str(r.randint(1,200000 if c=='l2' else 20)) for _ in range(n))])
TNF=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;vector<int>a(n);for(int&x:a)cin>>x;sort(a.begin(),a.end());int days=0;for(int x:a)if(x>=days+1+(MOD?1:0))days++;cout<<days<<'\n';}'''
TNS=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;vector<int>a(n),on(n);for(int&x:a)cin>>x;int best=0;while(true){vector<int>chosen;for(int i=0;i<n;i++)if(on[i])chosen.push_back(a[i]);sort(chosen.begin(),chosen.end());bool ok=true;for(int i=0;i<(int)chosen.size();i++)if(chosen[i]<i+1+(MOD?1:0))ok=false;if(ok)best=max(best,(int)chosen.size());int j=0;while(j<n&&on[j])on[j++]=0;if(j==n)break;on[j]=1;}cout<<best<<'\n';}'''
register('cf_1165_b',1475,'1165_B. Polycarp Training','https://codeforces.com/problemset/problem/1165/B',training_gen,training_val,TNF,TNS,'On dayd starting from1, solve exactlyd problems from one previously unused contest containing at leastd problems. Maximize the number of consecutive training days.','The chosen contest must contain STRICTLY MORE THANd problems, so at least one of its problems must remain unsolved on that day.','1\n1\n','n<=15','n<=200000',{'fast':'O(n log n)','slow':'O(2^n n log n)'},'Process capacities in increasing order, using the smallest available contest that meets the next day requirement. An exchange with any later larger qualifying contest preserves feasibility. The oracle chooses every subset and checks its sorted capacities against the necessary and sufficient day requirements.',['sorting','greedy'])

#252C.
def points_val(s,c):
 a=I(s);n,d=a[:2];B(n,1,100000);B(d,1,10**9);E(a,n+2);assert a[2:]==sorted(set(a[2:]))
 for x in a[2:]:B(x,-10**9,10**9)
 if c=='weak':B(n,1,30)
 return True
def points_gen(seed,c):
 r=random.Random(seed);n=100000 if c=='l2' else r.randint(1,30);a=list(range(n)) if c=='l2' else sorted(r.sample(range(-100,101),n));d=10**9 if c=='l2' else r.randint(1,200);return L([f'{n} {d}',' '.join(map(str,a))])
PTF=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;ll d;cin>>n>>d;vector<ll>x(n);for(ll&z:x)cin>>z;ll ans=0;int l=0;for(int r=0;r<n;r++){while(l<r&&(MOD?x[r]-x[l]>=d:x[r]-x[l]>d))l++;ll k=r-l;ans+=k*(k-1)/2;}cout<<ans<<'\n';}'''
PTS=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;ll d;cin>>n>>d;vector<ll>x(n);for(ll&z:x)cin>>z;ll ans=0;for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)for(int k=j+1;k<n;k++)ans+=MOD?x[k]-x[i]<d:x[k]-x[i]<=d;cout<<ans<<'\n';}'''
register('cf_252_c',1497,'252_C. Points on Line','https://codeforces.com/problemset/problem/252/C',points_gen,points_val,PTF,PTS,'Count triples of distinct input points whose farthest-pair distance is at mostd. Coordinates are strictly increasing.','Require farthest-pair distance STRICTLY LESS THANd instead of at mostd.','3 2\n1 2 3\n','n<=30','n<=100000',{'fast':'O(n)','slow':'O(n^3)'},'For a fixed rightmost point, valid other points form a contiguous suffix to its left. Any two of that suffix yield a valid triple, contributing choose(window_size,2). A monotone left pointer locates the suffix. The oracle enumerates all triples and directly checks their extreme distance.',['two-pointers','geometry'])


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
