"""Fifth independently authored batch; one recipe per exact public source."""
from pathlib import Path
import random
BASE=Path(__file__).resolve().parents[1]/'assets'/'cc_a_batch5'
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

#1199D: welfare floor versus wealth cap.
def welfare_val(s,c):
 a=I(s);n=a[0];B(n,1,200000);p=1
 for x in a[p:p+n]:B(x,0,10**9)
 p+=n;q=a[p];p+=1;B(q,1,200000)
 for _ in range(q):
  t=a[p];p+=1;B(t,1,2)
  if t==1:B(a[p],1,n);p+=1
  B(a[p],0,10**9);p+=1
 E(a,p)
 if c=='weak':B(n,1,30);B(q,1,30)
 return True
def welfare_gen(seed,c):
 r=random.Random(seed);n=200000 if c=='l2' else r.randint(1,30);q=200000 if c=='l2' else r.randint(1,30);ops=[]
 for _ in range(q):
  if c=='l2' or r.randrange(2):ops.append(f'2 {r.randint(0,100)}')
  else:ops.append(f'1 {r.randint(1,n)} {r.randint(0,100)}')
 return L([n,' '.join(str(r.randint(0,100)) for _ in range(n)),q]+ops)
WEF=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;vector<ll>a(n);for(ll&x:a)cin>>x;int q;cin>>q;struct E{int type,p;ll x;};vector<E>e(q);for(auto &v:e){cin>>v.type;if(v.type==1)cin>>v.p,v.p--;cin>>v.x;}vector<bool>done(n);ll cap=MOD?1000000000:0;auto apply=[&](ll x){return MOD?min(x,cap):max(x,cap);};for(int i=q-1;i>=0;i--){E v=e[i];if(v.type==2)cap=MOD?min(cap,v.x):max(cap,v.x);else if(!done[v.p])a[v.p]=apply(v.x),done[v.p]=true;}for(int i=0;i<n;i++)cout<<(done[i]?a[i]:apply(a[i]))<<' ';cout<<'\n';}'''
WES=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;vector<ll>a(n);for(ll&x:a)cin>>x;int q;cin>>q;while(q--){int t,p;ll x;cin>>t;if(t==1){cin>>p>>x;a[p-1]=x;}else{cin>>x;for(ll&v:a)v=MOD?min(v,x):max(v,x);}}for(ll v:a)cout<<v<<' ';cout<<'\n';}'''
register('cf_1199_d',1372,'1199_D. Welfare State','https://codeforces.com/problemset/problem/1199/D',welfare_gen,welfare_val,WEF,WES,'Process point assignments(type1 p x) and nationwide payouts(type2 x), the latter replacing every balance a by max(a,x). Output final balances.','Type2 becomes a wealth CAP: replace every balance a by min(a,x). Point assignments remain unchanged.','2\n1 5\n1\n2 3\n','n,q<=30','n,q<=200000',{'fast':'O(n+q)','slow':'O(nq)'},'Only the last point assignment to a citizen matters; global operations after it combine into one maximum floor or minimum cap. A reverse scan records each citizen once and accumulates the suffix threshold. The oracle executes every event chronologically on the literal array.',['offline-queries','arrays'])

#1416A: min versus max universal window member.
def amazing_val(s,c):
 a=I(s);t=a[0];B(t,1,1000);p=1;total=0
 for _ in range(t):
  n=a[p];p+=1;B(n,1,300000);total+=n;assert p+n<=len(a)
  for x in a[p:p+n]:B(x,1,n)
  p+=n
  if c=='weak':B(n,1,25)
 E(a,p);B(total,1,300000);return True
def amazing_gen(seed,c):
 r=random.Random(seed);n=300000 if c=='l2' else r.randint(1,25);return L([1,n,' '.join(str(r.randint(1,n)) for _ in range(n))])
AMF=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;cin>>n;vector<int>last(n+1),gap(n+1),best(n+1,MOD?-1:n+1);for(int i=1,x;i<=n;i++){cin>>x;gap[x]=max(gap[x],i-last[x]);last[x]=i;}for(int x=1;x<=n;x++){gap[x]=max(gap[x],n+1-last[x]);if(gap[x]<=n)best[gap[x]]=MOD?max(best[gap[x]],x):min(best[gap[x]],x);}for(int k=1;k<=n;k++){if(k>1)best[k]=MOD?max(best[k],best[k-1]):min(best[k],best[k-1]);cout<<(best[k]==n+1?-1:best[k])<<' ';}cout<<'\n';}}'''
AMS=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;cin>>n;vector<int>a(n);for(int&x:a)cin>>x;for(int k=1;k<=n;k++){int best=MOD?-1:n+1;for(int v=1;v<=n;v++){bool all=true;for(int l=0;l+k<=n;l++){bool found=false;for(int i=l;i<l+k;i++)if(a[i]==v)found=true;if(!found)all=false;}if(all)best=MOD?max(best,v):min(best,v);}cout<<(best==n+1?-1:best)<<' ';}cout<<'\n';}}'''
register('cf_1416_a',1487,'1416_A. k-Amazing Numbers','https://codeforces.com/problemset/problem/1416/A',amazing_gen,amazing_val,AMF,AMS,'For every lengthk=1..n, output the MINIMUM value appearing in every contiguous lengthk subarray, or-1 if no such value exists.','Output the MAXIMUM value appearing in every lengthk subarray instead. The absence result remains-1.','1\n2\n1 2\n','n<=25','sum n<=300000',{'fast':'O(n)','slow':'O(n^4)'},'A value appears in every lengthk window iff each gap between consecutive occurrences, including artificial positions0 and n+1, is at mostk. Bucket each value by its largest gap and take prefix minima/maxima. The oracle checks membership in every actual window for every candidate value and length.',['arrays','occurrence-gaps'])

#1506G.
def remaining_val(s,c):
 a=s.split();t=int(a[0]);B(t,1,10000);E(a,t+1);total=0
 for w in a[1:]:B(len(w),1,200000);assert all('a'<=x<='z' for x in w);total+=len(w);assert c!='weak' or len(w)<=15
 B(total,1,200000);return True
def remaining_gen(seed,c):
 r=random.Random(seed);n=200000 if c=='l2' else (15 if c=='weak' else r.randint(1,12));return L([1,''.join(r.choice('abcdef') for _ in range(n))])
REF=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){string s,st;cin>>s;array<int,26>left{};array<bool,26>used{};for(char c:s)left[c-'a']++;for(char c:s){left[c-'a']--;if(used[c-'a'])continue;while(!st.empty()&&left[st.back()-'a']>0&&(MOD?st.back()>c:st.back()<c)){used[st.back()-'a']=false;st.pop_back();}st+=c;used[c-'a']=true;}cout<<st<<'\n';}}'''
RES=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){string s;cin>>s;int n=s.size();set<char>need(s.begin(),s.end());vector<int>on(n);string best;bool have=false;while(true){string t;set<char>seen;bool ok=true;for(int i=0;i<n;i++)if(on[i]){if(!seen.insert(s[i]).second)ok=false;t+=s[i];}if(ok&&seen==need&&(!have||(MOD?t<best:t>best)))have=true,best=t;int j=0;while(j<n&&on[j])on[j++]=0;if(j==n)break;on[j]=1;}cout<<best<<'\n';}}'''
register('cf_1506_g',1491,'1506_G. Maximize the Remaining String','https://codeforces.com/problemset/problem/1506/G',remaining_gen,remaining_val,REF,RES,'Delete only occurrences of currently repeated letters until every remaining character is unique. Output the lexicographically maximum obtainable final string.','Output the lexicographically MINIMUM obtainable final string under the same deletion rules.','1\nabac\n','length<=15','total length<=200000',{'fast':'O(length+alphabet)','slow':'O(length 2^length)'},'Final strings are subsequences containing each original distinct letter exactly once. A stack greedily removes a less-preferred preceding letter only when another occurrence remains, preserving feasibility while improving the earliest differing position. The oracle enumerates all subsequences and explicitly checks exact coverage and uniqueness.',['strings','monotonic-stack'])

#371C: indivisible two-piece purchase packs.
def burger_val(s,c):
 a=s.split();E(a,8);w=a[0];B(len(w),1,100);assert set(w)<=set('BSC');nums=list(map(int,a[1:]))
 for x in nums[:6]:B(x,1,100)
 B(nums[6],1,10**12);assert c!='weak' or nums[6]<=50;return True
def burger_gen(seed,c):
 if c=='l2':return 'B\n1 1 1\n1 1 1\n1000000000000\n'
 r=random.Random(seed);return L([''.join(r.choice('BSC') for _ in range(r.randint(1,8))),' '.join(str(r.randint(1,10)) for _ in range(3)),' '.join(str(r.randint(1,10)) for _ in range(3)),r.randint(1,50)])
BUF=r'''int main(){string s;cin>>s;array<ll,3>need{},have,price;for(char c:s)need[c=='B'?0:c=='S'?1:2]++;for(ll&x:have)cin>>x;for(ll&x:price)cin>>x;ll money;cin>>money;auto ok=[&](ll k){__int128 cost=0;for(int i=0;i<3;i++){ll missing=max(0LL,k*need[i]-have[i]);if(MOD)missing=2*((missing+1)/2);cost+=(__int128)missing*price[i];}return cost<=money;};ll lo=0,hi=money+300;while(lo<hi){ll mid=(lo+hi+1)/2;if(ok(mid))lo=mid;else hi=mid-1;}cout<<lo<<'\n';}'''
BUS=r'''int main(){string s;cin>>s;array<ll,3>need{},have,price;for(char c:s)need[c=='B'?0:c=='S'?1:2]++;for(ll&x:have)cin>>x;for(ll&x:price)cin>>x;ll money;cin>>money;ll count=0;while(true){ll next=count+1;__int128 cost=0;for(int i=0;i<3;i++){ll deficit=max(0LL,next*need[i]-have[i]);ll packs=MOD?(deficit/2+(deficit%2!=0)):deficit;cost+=(__int128)packs*price[i]*(MOD?2:1);}if(cost>money)break;count++;}cout<<count<<'\n';}'''
register('cf_371_c',1502,'371_C. Hamburgers','https://codeforces.com/problemset/problem/371/C',burger_gen,burger_val,BUF,BUS,'Given a B/S/C hamburger recipe, existing ingredient stocks, per-piece prices and budget, buy ingredients to maximize the number of complete hamburgers.','Each ingredient can be bought only in packs of TWO pieces at twice its per-piece price. Existing stocks may be used individually and leftover purchased pieces are allowed.','B\n1 1 1\n1 1 1\n1\n','budget<=50','budget<=10^12',{'fast':'O(recipe_length+log budget)','slow':'O(maximum hamburger count)'},'For a proposed count, independently buy each nonnegative deficit, rounded up to an even quantity for L3. This minimum cost is monotone in the count, so binary search finds the optimum. The oracle increases the target count one by one and checks the literal purchase requirement.',['binary-search','resource-allocation'])

#609C: keep target balance, but transfers are pairs of tasks.
def load_val(s,c):
 a=I(s);n=a[0];B(n,1,100000);E(a,n+1)
 for x in a[1:]:B(x,0,20000)
 if c=='weak':B(n,1,15)
 return True
def load_gen(seed,c):
 r=random.Random(seed);n=100000 if c=='l2' else (15 if c=='weak' else r.randint(1,12));return L([n,' '.join(str(r.randrange(20001 if c=='l2' else 30)) for _ in range(n))])
LDF=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;vector<ll>a(n);ll total=0;for(ll&x:a)cin>>x,total+=x;ll q=total/n,r=total%n,ans=0;if(!MOD){sort(a.begin(),a.end());for(int i=0;i<n;i++)ans+=max(0LL,a[i]-(q+(i>=n-r)));}else{ll highs=0;for(ll x:a){ll target=q+((x%2)!=(q%2));highs+=target==q+1;ans+=max(0LL,x-target)/2;}if(highs!=r)ans=-1;}cout<<ans<<'\n';}'''
LDS=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;vector<ll>a(n);vector<int>high(n);ll total=0;for(ll&x:a)cin>>x,total+=x;ll q=total/n,r=total%n,best=1LL<<60;while(true){ll cnt=accumulate(high.begin(),high.end(),0LL);if(cnt==r){ll cost=0;bool ok=true;for(int i=0;i<n;i++){ll target=q+high[i],diff=a[i]-target;if(MOD&&diff%2)ok=false;if(diff>0)cost+=diff/(MOD?2:1);}if(ok)best=min(best,cost);}int j=0;while(j<n&&high[j])high[j++]=0;if(j==n)break;high[j]=1;}cout<<(best==(1LL<<60)?-1:best)<<'\n';}'''
register('cf_609_c',1512,'609_C. Load Balancing','https://codeforces.com/problemset/problem/609/C',load_gen,load_val,LDF,LDS,'Move one task between arbitrary servers per second. Reach the smallest possible load range, namely0 if total load divides n and1 otherwise, using the fewest seconds.','Each one-second move transfers EXACTLY TWO tasks from one server to another. The required target range remains0 if total divides n and1 otherwise. Print-1 if this target is unreachable.','2\n1 3\n','n<=15','n<=100000',{'fast':'O(n log n) Raw,O(n) L3','slow':'O(n 2^n)'},'Balanced final loads are q=floor(total/n) or q+1, with exactly total%n high servers. Raw exchanges show high targets should be assigned to largest initial loads. L3 preserves each server parity, uniquely fixing its target; if high-count matches, surplus pairs can be moved directly to deficit servers. The oracle enumerates all possible high-target subsets.',['sorting','invariants'])

#985B: remove two switches, not one.
def switch_val(s,c):
 a=s.split();n,m=map(int,a[:2]);B(n,1,2000);B(m,1,2000);E(a,n+2)
 for row in a[2:]:assert len(row)==m and set(row)<=set('01')
 assert all(any(row[j]=='1' for row in a[2:]) for j in range(m))
 if c=='weak':B(n,1,9);B(m,1,9)
 return True
def switch_gen(seed,c):
 r=random.Random(seed)
 if c=='l2':n=m=2000;rows=['0'*i+'1'+'0'*(n-i-1) for i in range(n)]
 else:
  n,m=r.randint(1,9),r.randint(1,9);a=[[r.choice('01') for _ in range(m)] for _ in range(n)]
  for j in range(m):a[r.randrange(n)][j]='1'
  rows=[''.join(row) for row in a]
 return L([f'{n} {m}']+rows)
SWF=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,m;cin>>n>>m;vector<string>a(n);for(string&s:a)cin>>s;vector<bool>essential(n);vector<pair<int,int>>pairs;for(int j=0;j<m;j++){int cnt=0,u=-1,v=-1;for(int i=0;i<n;i++)if(a[i][j]=='1'){cnt++;v=u;u=i;}if(cnt==1)essential[u]=true;if(cnt==2)pairs.push_back({min(u,v),max(u,v)});}ll free=count(essential.begin(),essential.end(),false);bool ok=free>=1;if(MOD){set<pair<int,int>>bad;for(auto e:pairs)if(!essential[e.first]&&!essential[e.second])bad.insert(e);ok=free*(free-1)/2>(ll)bad.size();}cout<<(ok?"YES":"NO")<<'\n';}'''
SWS=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,m;cin>>n>>m;vector<string>a(n);for(string&s:a)cin>>s;bool ok=false;for(int u=0;u<n;u++){int start=MOD?u+1:-1,stop=MOD?n:0;for(int v=start;v<stop;v++){bool all=true;for(int j=0;j<m;j++){bool lit=false;for(int i=0;i<n;i++)if(i!=u&&i!=v&&a[i][j]=='1'){lit=true;break;}if(!lit){all=false;break;}}if(all)ok=true;}if(ok)break;}cout<<(ok?"YES":"NO")<<'\n';}'''
register('cf_985_b',1528,'985_B. Switches and Lamps','https://codeforces.com/problemset/problem/985/B',switch_gen,switch_val,SWF,SWS,'Decide whether exactly one switch can be ignored while activating all remaining switches still lights every lamp. All lamps are covered initially.','Ignore exactly TWO distinct switches instead of one. If fewer than two switches exist, answerNO.','2 1\n1\n1\n','n,m<=9','n,m<=2000',{'fast':'O(nm+m log m)','slow':'O(n^2m) Raw,O(n^3m) L3'},'A sole supporter of any lamp is essential. For two removals, remaining candidate pairs are invalid precisely if they are the two supporters of a lamp with degree2. Deduplicate those forbidden pairs and compare their count with the number of candidate pairs. The oracle recomputes every lamp after each literal removed subset.',['incidence-matrix','counting'])

#ABC120D: construction order instead of destruction order.
def bridges_val(s,c):
 a=I(s);n,m=a[:2];B(n,2,100000);B(m,1,100000);E(a,2+2*m);edges=set();p=list(range(n))
 def find(x):
  while p[x]!=x:p[x]=p[p[x]];x=p[x]
  return x
 for i in range(m):
  u,v=a[2+2*i:4+2*i];B(u,1,n);B(v,u+1,n);assert (u,v) not in edges;edges.add((u,v));p[find(u-1)]=find(v-1)
 assert len({find(i) for i in range(n)})==1
 if c=='weak':B(n,2,18);B(m,1,30)
 return True
def bridges_gen(seed,c):
 r=random.Random(seed);n=100000 if c=='l2' else r.randint(2,18);edges={(i-1,i) for i in range(2,n+1)}
 if c!='l2':
  for _ in range(r.randint(0,12)):
   u,v=sorted(r.sample(range(1,n+1),2));edges.add((u,v))
 edges=list(edges);r.shuffle(edges);return L([f'{n} {len(edges)}']+[f'{u} {v}' for u,v in edges])
BRF=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,m;cin>>n>>m;vector<pair<int,int>>e(m);for(auto &[u,v]:e)cin>>u>>v,--u,--v;vector<int>p(n),sz(n,1);iota(p.begin(),p.end(),0);function<int(int)>find=[&](int x){while(p[x]!=x)x=p[x]=p[p[x]];return x;};ll disconnected=1LL*n*(n-1)/2;auto add=[&](pair<int,int>e){int u=find(e.first),v=find(e.second);if(u==v)return;if(sz[u]<sz[v])swap(u,v);disconnected-=1LL*sz[u]*sz[v];p[v]=u;sz[u]+=sz[v];};vector<ll>ans(m);if(MOD){for(int i=0;i<m;i++){add(e[i]);ans[i]=disconnected;}}else for(int i=m-1;i>=0;i--){ans[i]=disconnected;add(e[i]);}for(ll x:ans)cout<<x<<'\n';}'''
BRS=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,m;cin>>n>>m;vector<pair<int,int>>e(m);for(auto &[u,v]:e)cin>>u>>v,--u,--v;for(int step=0;step<m;step++){vector<vector<int>>g(n);int lo=MOD?0:step+1,hi=MOD?step+1:m;for(int i=lo;i<hi;i++){auto [u,v]=e[i];g[u].push_back(v);g[v].push_back(u);}vector<bool>seen(n);ll conn=0;for(int start=0;start<n;start++)if(!seen[start]){vector<int>q{start};seen[start]=true;for(int h=0;h<(int)q.size();h++)for(int v:g[q[h]])if(!seen[v])seen[v]=true,q.push_back(v);ll k=q.size();conn+=k*(k-1)/2;}cout<<1LL*n*(n-1)/2-conn<<'\n';}}'''
register('atcoder_abc120_d',1543,'p03108 AtCoder Beginner Contest 120 - Decayed Bridges','https://atcoder.jp/contests/abc120/tasks/abc120_d',bridges_gen,bridges_val,BRF,BRS,'Initially all listed bridges exist and the graph is connected. Remove bridges in listed order; after each removal print the number of disconnected unordered island pairs.','Initially NO bridge exists. BUILD bridges in listed order; after each addition print the number of disconnected unordered island pairs.','3 2\n1 2\n2 3\n','N<=18,M<=30','N,M<=100000',{'fast':'O((N+M)alpha(N))','slow':'O(M(N+M))'},'Adding an edge between components of sizesa,b makes exactlya*b pairs connected. Raw removals are handled in reverse with answers recorded before insertion; L3 uses forward insertions with answers recorded after insertion. The oracle rebuilds the graph for each stage and discovers components by BFS.',['graphs','disjoint-set'])

#ABC091B: eligibility requires cards of both colors.
def cards_val(s,c):
 a=s.split();n=int(a[0]);cap=100000 if c=='l2' else 100;B(n,1,cap);assert len(a)>n+1;m=int(a[n+1]);B(m,1,cap);E(a,n+m+2)
 for w in a[1:n+1]+a[n+2:]:B(len(w),1,10);assert all('a'<=x<='z' for x in w)
 if c=='weak':B(n,1,20);B(m,1,20)
 return True
def cards_gen(seed,c):
 r=random.Random(seed)
 if c=='l2':
  n=m=100000
  def word(i):
   s=''
   for _ in range(5):s+=chr(97+i%26);i//=26
   return s
  blue=[word(i) for i in range(n)];red=blue[::-1]
 else:n,m=r.randint(1,20),r.randint(1,20);blue=[r.choice(['a','b','c','ab','ba']) for _ in range(n)];red=[r.choice(['a','b','c','ab','ba']) for _ in range(m)]
 return L([n]+blue+[m]+red)
CAF=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,m;cin>>n;map<string,pair<int,int>>f;for(int i=0;i<n;i++){string s;cin>>s;f[s].first++;}cin>>m;for(int i=0;i<m;i++){string s;cin>>s;f[s].second++;}int best=0;for(auto &[s,v]:f)if(!MOD||(v.first&&v.second))best=max(best,v.first-v.second);cout<<best<<'\n';}'''
CAS=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,m;cin>>n;vector<string>a(n);for(string&s:a)cin>>s;cin>>m;vector<string>b(m);for(string&s:b)cin>>s;int best=0;for(string s:a){int blue=0,red=0;for(string t:a)blue+=s==t;for(string t:b)red+=s==t;if(!MOD||red>0)best=max(best,blue-red);}cout<<best<<'\n';}'''
register('atcoder_abc091_b',1545,'p03408 AtCoder Beginner Contest 091 - Two Colors Card Game','https://atcoder.jp/contests/abc091/tasks/abc091_b',cards_gen,cards_val,CAF,CAS,'Announce any string; earn one per matching blue card and lose one per matching red card. Output the maximum net earning, which is at least0 by announcing an absent string.','Only a string appearing on BOTH a blue card and a red card earns its usual net score; all other announcements earn0. Maximize net earning.','3\na\na\nb\n1\nb\n','N,M<=20','N,M<=100000 (explicit L2 extension from source limit100)',{'fast':'O((N+M)log(N+M))','slow':'O(N(N+M))'},'Group identical strings and evaluate blue_count-red_count, applying the both-colors eligibility predicate for L3. The oracle independently scans both complete card lists for each announced blue-card string. Any strictly positive eligible result must have a blue occurrence.',['strings','frequency-maps'])

#1311B: descending target; bubble simulation remains a real slow solver.
def weird_val(s,c):
 a=I(s);t=a[0];B(t,1,100);p=1
 for _ in range(t):
  n,m=a[p:p+2];p+=2;B(n,2,200000 if c=='l2' else 100);B(m,1,n-1);assert p+n+m<=len(a)
  for x in a[p:p+n]:B(x,1,100)
  pp=a[p+n:p+n+m];assert len(set(pp))==m
  for x in pp:B(x,1,n-1)
  p+=n+m
  if c=='weak':B(n,2,30)
 E(a,p);return True
def weird_gen(seed,c):
 r=random.Random(seed);n=200000 if c=='l2' else r.randint(2,30);m=n-1 if c=='l2' else r.randint(1,n-1);a=[100]*(n//2)+[1]*(n-n//2) if c=='l2' else [r.randint(1,20) for _ in range(n)];p=list(range(1,n)) if c=='l2' else r.sample(range(1,n),m);return L([1,f'{n} {m}',' '.join(map(str,a)),' '.join(map(str,p))])
WYF=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n,m;cin>>n>>m;vector<int>a(n),allowed(n);for(int&x:a)cin>>x;for(int i=0,x;i<m;i++)cin>>x,allowed[x-1]=1;int l=0;while(l<n){int r=l;while(r<n-1&&allowed[r])r++;sort(a.begin()+l,a.begin()+r+1);if(MOD)reverse(a.begin()+l,a.begin()+r+1);l=r+1;}bool ok=true;for(int i=1;i<n;i++)if(MOD?a[i-1]<a[i]:a[i-1]>a[i])ok=false;cout<<(ok?"YES":"NO")<<'\n';}}'''
WYS=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n,m;cin>>n>>m;vector<int>a(n),allowed(n);for(int&x:a)cin>>x;for(int i=0,x;i<m;i++)cin>>x,allowed[x-1]=1;bool changed=true;while(changed){changed=false;for(int i=0;i<n-1;i++)if(allowed[i]&&(MOD?a[i]<a[i+1]:a[i]>a[i+1]))swap(a[i],a[i+1]),changed=true;}bool ok=true;for(int i=1;i<n;i++)if(MOD?a[i-1]<a[i]:a[i-1]>a[i])ok=false;cout<<(ok?"YES":"NO")<<'\n';}}'''
register('cf_1311_b',1586,'1311_B. WeirdSort','https://codeforces.com/problemset/problem/1311/B',weird_gen,weird_val,WYF,WYS,'Given allowed adjacent swap positions, decide whether the array can be made nondecreasing using only such swaps.','Require the final array to be NONINCREASING instead.','1\n3 1\n1 2 3\n1\n','n<=30','n<=200000 (explicit L2 extension from source n<=100)',{'fast':'O(n log n)','slow':'O(n^2)'},'Allowed adjacent edges partition positions into contiguous components. Each component permits arbitrary permutations but no element can leave it, so sorting every component in the target order is necessary and sufficient. The oracle repeatedly executes allowed adjacent inversion swaps until stable and then checks the global order.',['sorting','connected-components'])

#1466B: increase by two rather than one, changing feasible note sets.
def notes_val(s,c):
 a=I(s);t=a[0];B(t,1,10000);p=1;total=0
 for _ in range(t):
  n=a[p];p+=1;B(n,1,100000);total+=n;assert p+n<=len(a);v=a[p:p+n];assert v==sorted(v)
  for x in v:B(x,1,2*n)
  p+=n
  if c=='weak':B(n,1,15)
 E(a,p);B(total,1,100000);return True
def notes_gen(seed,c):
 r=random.Random(seed);n=100000 if c=='l2' else (15 if c=='weak' else r.randint(1,12));return L([1,n,' '.join(map(str,sorted(r.randint(1,2*n) for _ in range(n))))])
NOF=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;cin>>n;vector<bool>used(2*n+4);int ans=0;for(int i=0,x;i<n;i++){cin>>x;if(!used[x])used[x]=true,ans++;else if(!used[x+(MOD?2:1)])used[x+(MOD?2:1)]=true,ans++;}cout<<ans<<'\n';}}'''
NOS=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;cin>>n;vector<int>a(n),on(n);for(int&x:a)cin>>x;int best=0;while(true){set<int>seen;for(int i=0;i<n;i++)seen.insert(a[i]+on[i]*(MOD?2:1));best=max(best,(int)seen.size());int j=0;while(j<n&&on[j])on[j++]=0;if(j==n)break;on[j]=1;}cout<<best<<'\n';}}'''
register('cf_1466_b',1593,'1466_B. Last minute enhancements','https://codeforces.com/problemset/problem/1466/B',notes_gen,notes_val,NOF,NOS,'For each note in a sorted sequence, either keep it or increase it by1. Maximize the number of distinct resulting notes.','A changed note increases by TWO instead of one. Every occurrence is still changed at most once.','1\n4\n1 1 2 2\n','n<=15','sum n<=100000',{'fast':'O(n)','slow':'O(2^n n log n)'},'For stepd=1 or2, separate residues modulo d. Within each chain the available positions for a note are consecutive positions x,x+d. Processing notes in increasing order and taking the first unused option is optimal by exchanging later assignments to the larger option. The oracle independently enumerates every keep/change decision.',['greedy','matching'])

#1227A: a segment must contain each input segment instead of intersecting it.
def math_val(s,c):
 a=I(s);t=a[0];B(t,1,100);p=1;total=0
 for _ in range(t):
  n=a[p];p+=1;B(n,1,100000);total+=n
  for _ in range(n):l,u=a[p:p+2];p+=2;B(l,1,10**9);B(u,l,10**9)
  if c=='weak':B(n,1,15)
 E(a,p);B(total,1,100000);return True
def math_gen(seed,c):
 r=random.Random(seed);n=100000 if c=='l2' else r.randint(1,15);e=[]
 for i in range(n):
  l=i+1 if c=='l2' else r.randint(1,30);u=i+100001 if c=='l2' else r.randint(l,40);e.append(f'{l} {u}')
 return L([1,n]+e)
MAF=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;cin>>n;ll minl=1LL<<60,maxl=0,minr=1LL<<60,maxr=0;while(n--){ll l,r;cin>>l>>r;minl=min(minl,l);maxl=max(maxl,l);minr=min(minr,r);maxr=max(maxr,r);}cout<<(MOD?maxr-minl:max(0LL,maxl-minr))<<'\n';}}'''
MAS=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;cin>>n;vector<pair<ll,ll>>e(n);vector<ll>ends;for(auto &[l,r]:e)cin>>l>>r,ends.push_back(l),ends.push_back(r);sort(ends.begin(),ends.end());ends.erase(unique(ends.begin(),ends.end()),ends.end());ll best=1LL<<60;for(ll a:ends)for(ll b:ends)if(a<=b){bool ok=true;for(auto [l,r]:e)if(MOD?!(a<=l&&r<=b):!(a<=r&&l<=b))ok=false;if(ok)best=min(best,b-a);}cout<<best<<'\n';}}'''
register('cf_1227_a',224,'1227_A. Math Problem','https://codeforces.com/problemset/problem/1227/A',math_gen,math_val,MAF,MAS,'Add a shortest closed segment that intersects every input closed segment, allowing a zero-length point. Output its length.','The added segment must CONTAIN every input segment completely, rather than merely intersect each.','1\n1\n1 5\n','n<=15','sum n<=100000',{'fast':'O(n)','slow':'O(n^3)'},'Intersection requires left endpoint<=minimum right endpoint and right endpoint>=maximum left endpoint, yielding max(0,maxLeft-minRight). Containment requires covering the global minimum left and maximum right. An optimum has endpoints among input endpoints; the oracle enumerates all such endpoint pairs and checks each original constraint.',['intervals','optimization'])

#1334A: every recorded attempt must clear.
def stats_val(s,c):
 a=I(s);t=a[0];B(t,1,500);p=1
 for _ in range(t):
  n=a[p];p+=1;B(n,1,200000 if c=='l2' else 100)
  for x in a[p:p+2*n]:B(x,0,10**9 if c=='l2' else 1000)
  assert p+2*n<=len(a);p+=2*n
  if c=='weak':B(n,1,30)
 E(a,p);return True
def stats_gen(seed,c):
 r=random.Random(seed);n=200000 if c=='l2' else r.randint(1,30);a=[];p=v=0
 for i in range(n):
  dp=r.randint(0,3);dv=r.randint(0,dp);p+=dp;v+=dv;a.append([p,v])
 if c!='l2' and r.randrange(2):a[r.randrange(n)]=[r.randint(0,80),r.randint(0,80)]
 return L([1,n]+[f'{p} {v}' for p,v in a])
SCF=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;cin>>n;ll oldp=0,oldc=0;bool ok=true;while(n--){ll p,c;cin>>p>>c;ll dp=p-oldp,dc=c-oldc;if(dp<0||dc<0||dc>dp||(MOD&&dc!=dp))ok=false;oldp=p;oldc=c;}cout<<(ok?"YES":"NO")<<'\n';}}'''
SCS=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;cin>>n;vector<ll>p(n+1),c(n+1);for(int i=1;i<=n;i++)cin>>p[i]>>c[i];bool ok=true;for(int i=0;i<=n;i++)for(int j=i+1;j<=n;j++){ll plays=p[j]-p[i],clears=c[j]-c[i];if(plays<0||clears<0||clears>plays||(MOD&&plays!=clears))ok=false;}cout<<(ok?"YES":"NO")<<'\n';}}'''
register('cf_1334_a',229,'1334_A. Level Statistics','https://codeforces.com/problemset/problem/1334/A',stats_gen,stats_val,SCF,SCS,'Determine whether chronological(play_count,clear_count) snapshots can come from attempts that each increase plays by1 and either increase clears by1 or leave clears unchanged. Initial counters are zero.','Every attempt is successful: EACH play must also increase clears by1. Check whether the snapshots are consistent with this stricter history.','1\n1\n1 0\n','n<=30','n<=200000,counters<=10^9 (explicit L2 extension from source n<=100,counters<=1000)',{'fast':'O(n)','slow':'O(n^2)'},'Each consecutive difference must satisfy0<=deltaClears<=deltaPlays, or equality for L3. These conditions construct a valid interval history and sum to all nonconsecutive interval constraints. The oracle checks every pair of snapshots, including the initial zero counters, independently.',['prefix-invariants','validation'])

#235A: select two numbers instead of three.
def lcm_val(s,c):
 a=I(s);E(a,1);B(a[0],1,1000000);assert c!='weak' or a[0]<=35;return True
def lcm_gen(seed,c):return str(1000000 if c=='l2' else random.Random(seed).randint(1,35))+'\n'
LCF=r'''int main(){ll n;cin>>n;ll ans;if(MOD)ans=n==1?1:n*(n-1);else if(n<3)ans=n;else if(n%2)ans=n*(n-1)*(n-2);else if(n%3)ans=n*(n-1)*(n-3);else ans=(n-1)*(n-2)*(n-3);cout<<ans<<'\n';}'''
LCS=r'''int main(){ll n;cin>>n;ll best=1;auto lcm=[](ll x,ll y){return x/gcd(x,y)*y;};for(ll a=1;a<=n;a++)for(ll b=1;b<=n;b++){if(MOD)best=max(best,lcm(a,b));else for(ll c=1;c<=n;c++)best=max(best,lcm(lcm(a,b),c));}cout<<best<<'\n';}'''
register('cf_235_a',242,'235_A. LCM Challenge','https://codeforces.com/problemset/problem/235/A',lcm_gen,lcm_val,LCF,LCS,'Choose THREE positive integers at mostn, repetitions allowed, and maximize their least common multiple.','Choose TWO positive integers instead of three; repetitions remain allowed.','5\n','n<=35','n<=1000000',{'fast':'O(1)','slow':'O(n^3 log n) Raw,O(n^2 log n) L3'},'For n>=3 the three-number extremum is n(n-1)(n-2) for oddn, n(n-1)(n-3) for evenn not divisible by3, and(n-1)(n-2)(n-3) otherwise; common factors exclude the larger nearby triples, while lowering any endpoint bounds the product. For two numbers, n,n-1 are coprime and attain the largest possible product of distinct candidates; repetitions yield at mostn. The oracle enumerates all tuples and computes gcd-based LCM directly.',['number-theory','optimization'])

#1512G: choose maximum inverse of divisor sum.
def divisor_val(s,c):
 a=I(s);t=a[0];B(t,1,10000);E(a,t+1)
 for x in a[1:]:B(x,1,10000000);assert c!='weak' or x<=80
 return True
def divisor_gen(seed,c):
 if c=='l2':return '1\n10000000\n'
 r=random.Random(seed);t=r.randint(1,5);return L([t]+[r.randint(1,80) for _ in range(t)])
DVF=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int t;cin>>t;vector<int>q(t);int cap=0;for(int&x:q)cin>>x,cap=max(cap,x);vector<int>sigma(cap+1),ans(cap+1,-1);for(int d=1;d<=cap;d++)for(int v=d;v<=cap;v+=d)sigma[v]+=d;for(int n=1;n<=cap;n++)if(sigma[n]<=cap){int&v=ans[sigma[n]];if(MOD||v==-1)v=n;}for(int x:q)cout<<ans[x]<<'\n';}'''
DVS=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int t;cin>>t;while(t--){int c;cin>>c;int best=-1;for(int n=1;n<=c;n++){ll sum=0;for(int d=1;d<=n;d++)if(n%d==0)sum+=d;if(sum==c){if(MOD||best==-1)best=n;}}cout<<best<<'\n';}}'''
register('cf_1512_g',237,'1512_G. Short Task','https://codeforces.com/problemset/problem/1512/G',divisor_gen,divisor_val,DVF,DVS,'For eachc, find the MINIMUM positive integern whose positive divisors sum toc; output-1 if none exists.','Find the MAXIMUM positive integern with the same divisor sumc.','1\n12\n','c<=80','c<=10000000',{'fast':'O(C log C+t)','slow':'O(sum c^2)'},'Because sigma(n)>=n, only n<=maxQuery must be considered. A multiples sieve accumulates each divisor contribution, then records the first or last index attaining each sum. The oracle instead enumerates each candidate integer and tests every possible divisor individually.',['number-theory','sieve'])
RECIPES['cf_1512_g']['budget_seconds']=2.0
RECIPES['cf_985_b']['budget_seconds']=0.25

def check_output(id,input_text,candidate_text,oracle_text,condition):
 if id in {'cf_985_b','cf_1311_b','cf_1334_a'}:return candidate_text.lower().split()==oracle_text.lower().split()
 return candidate_text.split()==oracle_text.split()


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
