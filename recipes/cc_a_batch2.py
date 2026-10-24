"""Second independently authored batch; one recipe per exact public source."""
from pathlib import Path
import random
BASE=Path(__file__).resolve().parents[1]/'assets'/'cc_a_batch2'
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

# 1037B: optimization oracle enumerates unchanged-or-clipped values.
def median_val(s,c):
 a=I(s);n,target=a[:2];B(n,1,199999);assert n%2;B(target,1,10**9);E(a,n+2)
 for x in a[2:]:B(x,1,10**9)
 if c=='weak':B(n,1,13)
 return True
def median_gen(seed,c):
 r=random.Random(seed);n=199999 if c=='l2' else (13 if c=='weak' else r.randrange(1,12,2));target=r.randint(1,30)
 return L([f'{n} {target}',' '.join(str(r.randint(1,30)) for _ in range(n))])
MF=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;ll s;cin>>n>>s;vector<ll>a(n);for(auto&x:a)cin>>x;sort(a.begin(),a.end());ll ans=0;int mid=n/2;if(MOD){for(int i=0;i<=mid;i++)ans+=max(0LL,a[i]-s);}else{for(int i=0;i<mid;i++)ans+=max(0LL,a[i]-s);ans+=llabs(a[mid]-s);for(int i=mid+1;i<n;i++)ans+=max(0LL,s-a[i]);}cout<<ans<<'\n';}'''
MS=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;ll s;cin>>n>>s;vector<ll>a(n);for(auto&x:a)cin>>x;vector<int>on(n);ll best=1LL<<62;while(true){vector<ll>b=a;ll cost=0;for(int i=0;i<n;i++)if(on[i])cost+=llabs(a[i]-s),b[i]=s;sort(b.begin(),b.end());if(MOD?b[n/2]<=s:b[n/2]==s)best=min(best,cost);int j=0;while(j<n&&on[j])on[j++]=0;if(j==n)break;on[j]=1;}cout<<best<<'\n';}'''
register('cf_1037_b',215,'1037_B. Reach Median','https://codeforces.com/problemset/problem/1037/B',median_gen,median_val,MF,MS,'Given odd n, target s and n positive integers, change individual values by unit increments/decrements to make the median exactly s; minimize the operation count.','Require the median to be AT MOST s instead of exactly s.','1 5\n3\n','odd n<=13','odd n<=199999',{'fast':'O(n log n)','slow':'O(2^n n log n)'},'Sorting exposes which elements must cross s. An optimum never changes a value except directly to s: moving partway does not change its side of the threshold and moving farther adds cost. The oracle enumerates every unchanged/clipped choice and checks the median. The upper-bound variant only lowers values needed to ensure at least n//2+1 values<=s.',['order-statistics','optimization'])

# 1269B: restrict returned representative to the canonical residue interval.
def modulo_val(s,c):
 a=I(s);n,m=a[:2];B(n,1,2000);B(m,1,10**9);E(a,2+2*n);x=a[2:2+n];y=a[2+n:]
 for v in x+y:B(v,0,m-1)
 target=sorted(y);assert any(sorted((v+shift)%m for v in x)==target for shift in {(u-x[0])%m for u in y})
 if c=='weak':B(n,1,10);B(m,1,20)
 return True
def modulo_gen(seed,c):
 r=random.Random(seed)
 if c=='l2':return '3 1000000000\n0 0 0\n999999999 999999999 999999999\n'
 n=r.randint(1,10);m=r.randint(1,20);a=[r.randrange(m) for _ in range(n)];shift=r.randrange(m);b=[(x+shift)%m for x in a];r.shuffle(b)
 return L([f'{n} {m}',' '.join(map(str,a)),' '.join(map(str,b))])
MOF=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;ll m;cin>>n>>m;vector<ll>a(n),b(n);for(auto&x:a)cin>>x;for(auto&x:b)cin>>x;sort(b.begin(),b.end());set<ll>sh;for(ll x:b)sh.insert((x-a[0]+m)%m);ll ans=MOD?-1:m;for(ll x:sh){vector<ll>v;for(ll z:a)v.push_back((z+x)%m);sort(v.begin(),v.end());if(v==b)ans=MOD?max(ans,x):min(ans,x);}cout<<ans<<'\n';}'''
MOS=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;ll m;cin>>n>>m;vector<ll>a(n),b(n);for(auto&x:a)cin>>x;for(auto&x:b)cin>>x;ll ans=-1;for(ll shift=0;shift<m;shift++){vector<bool>used(n);bool ok=true;for(ll x:a){ll want=(x+shift)%m;bool found=false;for(int j=0;j<n;j++)if(!used[j]&&b[j]==want){used[j]=true;found=true;break;}if(!found){ok=false;break;}}if(ok){ans=shift;if(!MOD)break;}}cout<<ans<<'\n';}'''
register('cf_1269_b',226,'1269_B. Modulo Equality','https://codeforces.com/problemset/problem/1269/B',modulo_gen,modulo_val,MOF,MOS,'Find the smallest nonnegative offset x making multiset {(a_i+x) mod m} equal multiset B. A solution is guaranteed. The smallest solution is equivalently the smallest valid representative in 0<=x<m.','Return the LARGEST valid normalized residue representative x in [0,m), instead of the smallest. The finite normalized domain is explicit; no unbounded maximum is claimed.','2 4\n0 2\n0 2\n','n<=10,m<=20','n<=2000,m<=10^9',{'fast':'O(n^2 log n)','slow':'O(m n^2)'},'A valid shift must send a[0] to some element of B, leaving at most n candidates. The optimized program checks candidates by sorted multisets; the oracle exhausts all residues and matches occurrences directly using used flags.',['modular-arithmetic','multisets'])

# 1311C: native input guarantee counts<=2e9 checked explicitly.
def combo_parse(s):
 tok=s.split();T=int(tok[0]);B(T,1,10000);p=1;cases=[];sn=sm=0
 for _ in range(T):
  n,m=map(int,tok[p:p+2]);p+=2;B(n,2,200000);B(m,1,200000);w=tok[p];p+=1;assert len(w)==n and w.isascii() and w.islower() and w.isalpha();ps=list(map(int,tok[p:p+m]));p+=m;E(ps,m)
  for x in ps:B(x,1,n-1)
  cases.append((n,m,w,ps));sn+=n;sm+=m
 assert p==len(tok);B(sn,1,200000);B(sm,1,200000);return cases
def combo_val(s,c):
 for n,m,w,ps in combo_parse(s):
  if c=='weak':B(n,2,25);B(m,1,25)
  d=[0]*(n+1)
  for x in ps:d[0]+=1;d[x]-=1
  count=[0]*26;active=1
  for j,x in enumerate(w):active+=d[j];count[ord(x)-97]+=active
  assert max(count)<=2*10**9
 return True
def combo_gen(seed,c):
 r=random.Random(seed);n=m=200000 if c=='l2' else r.randint(2,25);w=('abcdefghijklmnopqrstuvwxyz'*((n+25)//26))[:n] if c=='l2' else ''.join(r.choice('abc') for _ in range(n));ps=[n-1]*m if c=='l2' else [r.randrange(1,n) for _ in range(m)]
 return L([1,f'{n} {m}',w,' '.join(map(str,ps))])
COF=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n,m;string s;cin>>n>>m>>s;vector<ll>d(n+1);while(m--){int p;cin>>p;int l=MOD?n-p:0,rr=MOD?n:p;d[l]++;d[rr]--;}array<ll,26>a{};ll times=1;for(int i=0;i<n;i++){times+=d[i];a[s[i]-'a']+=times;}for(ll x:a)cout<<x<<' ';cout<<'\n';}}'''
COS=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n,m;string s;cin>>n>>m>>s;array<ll,26>a{};for(char c:s)a[c-'a']++;while(m--){int p;cin>>p;for(int j=0;j<p;j++)a[s[MOD?n-1-j:j]-'a']++;}for(ll x:a)cout<<x<<' ';cout<<'\n';}}'''
register('cf_1311_c',228,'1311_C. Perform the Combo','https://codeforces.com/problemset/problem/1311/C',combo_gen,combo_val,COF,COS,'Count button presses per lowercase letter after m failed attempts pressing the first p_i characters of s, followed by one successful full-string attempt.','Each failed attempt presses the LAST p_i characters instead of the first p_i. The successful attempt still presses all of s.','1\n3 1\nabc\n1\n','n,m<=25','sum n,sum m<=200000; original count<=2e9 guarantee retained',{'fast':'O(n+m)','slow':'O(nm)'},'Every attempt adds one to a prefix or suffix interval. A difference array accumulates position multiplicities in linear time. The independent oracle literally visits each pressed character.',['prefix-sums','strings'])

# 1466C: independent exhaustive conflict-cover oracle.
def poetry_val(s,c):
 a=s.split();T=int(a[0]);B(T,1,100000);E(a,T+1);assert sum(map(len,a[1:]))<=100000
 for w in a[1:]:assert w and w.isascii() and w.isalpha() and w.islower();assert c!='weak' or len(w)<=14
 return True
def poetry_gen(seed,c):
 r=random.Random(seed);n=100000 if c=='l2' else (14 if c=='weak' else r.randint(1,11));w='a'*n if c=='l2' else ''.join(r.choice('abc') for _ in range(n));return L([1,w])
POF=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){string s;cin>>s;int ans=0;for(int i=0;i<(int)s.size();i++)if((i&&s[i]==s[i-1])||(!MOD&&i>1&&s[i]==s[i-2])){ans++;s[i]='#';}cout<<ans<<'\n';}}'''
POS=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){string s;cin>>s;int n=s.size(),best=n;vector<int>changed(n);while(true){bool ok=true;int count=0;for(int i=0;i<n;i++){count+=changed[i];if(changed[i])continue;for(int d=1;d<=(MOD?1:2);d++)if(i>=d&&!changed[i-d]&&s[i]==s[i-d])ok=false;}if(ok)best=min(best,count);int j=0;while(j<n&&changed[j])changed[j++]=0;if(j==n)break;changed[j]=1;}cout<<best<<'\n';}}'''
register('cf_1466_c',235,'1466_C. Canine poetry','https://codeforces.com/problemset/problem/1466/C',poetry_gen,poetry_val,POF,POS,'Minimize character replacements needed so a lowercase string has no palindromic substring longer than1.','Forbid only palindromic substrings of length EXACTLY2; longer palindromes are allowed.','1\naba\n','length<=14','total length<=100000',{'fast':'O(length)','slow':'O(length*2^length)'},'Every palindrome of length>=2 contains a central palindrome of length2 or3. Thus raw conflicts are equal original letters distance1 or2; L3 keeps only distance1. Greedily replacing the right endpoint of the first unresolved conflict is optimal for this ordered conflict structure. The oracle independently enumerates replacement-position subsets and tests every original conflict edge; changed positions can always be assigned among26 letters avoiding their at most4 neighbors.',['strings','greedy'])

# 1490D: max/min Cartesian trees; the slow algorithm uses an explicit stack.
def cart_val(s,c):
 a=I(s);T=a[0];B(T,1,100);p=1
 for _ in range(T):
  n=a[p];p+=1;B(n,1,200000 if c=='l2' else 100);v=a[p:p+n];p+=n;assert sorted(v)==list(range(1,n+1));assert c!='weak' or n<=30
 assert p==len(a);return True
def cart_gen(seed,c):
 r=random.Random(seed);n=200000 if c=='l2' else r.randint(1,30);a=list(range(1,n+1))
 if c!='l2':r.shuffle(a)
 return L([1,n,' '.join(map(str,a))])
CAF=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;cin>>n;vector<int>a(n),left(n,-1),right(n,-1),st,dep(n);for(auto&x:a)cin>>x;for(int i=0;i<n;i++){int last=-1;while(!st.empty()&&(MOD?a[st.back()]>a[i]:a[st.back()]<a[i]))last=st.back(),st.pop_back();if(!st.empty())right[st.back()]=i;left[i]=last;st.push_back(i);}int root=st.front();vector<int>walk(1,root);while(!walk.empty()){int v=walk.back();walk.pop_back();for(int u:{left[v],right[v]})if(u!=-1)dep[u]=dep[v]+1,walk.push_back(u);}for(int d:dep)cout<<d<<' ';cout<<'\n';}}'''
CAS=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;cin>>n;vector<int>a(n),dep(n);for(auto&x:a)cin>>x;vector<array<int,3>>st(1,{0,n,0});while(!st.empty()){auto [l,r,d]=st.back();st.pop_back();if(l>=r)continue;int at=l;for(int i=l+1;i<r;i++)if(MOD?a[i]<a[at]:a[i]>a[at])at=i;dep[at]=d;st.push_back({l,at,d+1});st.push_back({at+1,r,d+1});}for(int d:dep)cout<<d<<' ';cout<<'\n';}}'''
register('cf_1490_d',236,'1490_D. Permutation Transformation','https://codeforces.com/problemset/problem/1490/D',cart_gen,cart_val,CAF,CAS,'Recursively make the maximum element of each permutation interval its binary-tree root. Output each original element position depth, with root depth0.','Use the MINIMUM element as each interval root instead of the maximum.','1\n2\n1 2\n','n<=30','n<=200000 (source original n<=100)',{'fast':'O(n)','slow':'O(n^2) worst case'},'The monotone stack builds the unique Cartesian tree satisfying the inorder/permutation relation and heap ordering. A separate iterative traversal computes depths. The oracle literally scans each active interval to find its extremum, then processes the two subintervals; explicit stacks avoid recursion overflow.',['cartesian-tree','monotonic-stack'])

# 609B: preserve the original answer guarantee in generated Raw inputs.
def gift_val(s,c):
 a=I(s);n,m=a[:2];B(n,2,200000);B(m,2,10);E(a,n+2);cnt=[0]*m
 for v in a[2:]:B(v,1,m);cnt[v-1]+=1
 assert all(cnt);different=(n*n-sum(x*x for x in cnt))//2;assert different<=2*10**9
 if c=='weak':B(n,2,30)
 return True
def gift_gen(seed,c):
 r=random.Random(seed)
 if c=='l2':return L(['200000 2',' '.join(['1']*199999+['2'])])
 n=r.randint(2,30);m=r.randint(2,min(n,6));a=list(range(1,m+1))+[r.randint(1,m) for _ in range(n-m)];r.shuffle(a);return L([f'{n} {m}',' '.join(map(str,a))])
GIF=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);ll n;int m;cin>>n>>m;vector<ll>cnt(m+1);for(int i=0,x;i<n;i++)cin>>x,cnt[x]++;ll same=0;for(ll x:cnt)same+=x*(x-1)/2;cout<<(MOD?same:n*(n-1)/2-same)<<'\n';}'''
GIS=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,m;cin>>n>>m;vector<int>a(n);for(auto&x:a)cin>>x;ll ans=0;for(int i=0;i<n;i++)for(int j=0;j<i;j++)ans+=MOD?(a[i]==a[j]):(a[i]!=a[j]);cout<<ans<<'\n';}'''
register('cf_609_b',362,'609_B. The Best Gift','https://codeforces.com/problemset/problem/609/B',gift_gen,gift_val,GIF,GIS,'Count unordered pairs of distinct book occurrences whose genres differ; every genre occurs and the Raw answer is at most2e9.','Count pairs whose genres are the SAME instead of different. Return the exact integer count.','2 2\n1 2\n','n<=30','n<=200000 with original Raw answer<=2e9',{'fast':'O(n+m)','slow':'O(n^2)'},'Per-genre frequency c contributes c choose2 same-genre pairs. Subtract from n choose2 for differing genres. The independent oracle visits every pair and directly tests the predicate.',['frequency','counting'])

# 814C: L3 changes the normalized substring mismatch predicate, not an
# ambiguous global requirement to repaint spare positions elsewhere.
def garland_parse(s):
 a=s.split();n=int(a[0]);w=a[1];q=int(a[2]);B(n,1,1500);B(q,1,200000);E(a,3+2*q);assert len(w)==n and w.isascii() and w.islower() and w.isalpha();qs=[]
 for i in range(q):m=int(a[3+2*i]);ch=a[4+2*i];B(m,1,n);assert len(ch)==1 and 'a'<=ch<='z';qs.append((m,ch))
 return n,w,qs
def garland_val(s,c):
 n,w,qs=garland_parse(s)
 if c=='weak':B(n,1,14);B(len(qs),1,15)
 return True
def garland_gen(seed,c):
 r=random.Random(seed);n=1500 if c=='l2' else r.randint(1,14);q=200000 if c=='l2' else r.randint(1,15);w=('abcdefghijklmnopqrstuvwxyz'*58)[:n] if c=='l2' else ''.join(r.choice('abc') for _ in range(n));qs=[f'{r.randint(1,n)} {r.choice("abcdefghijklmnopqrstuvwxyz" if c=="l2" else "abcd")}' for _ in range(q)]
 return L([n,w,q]+qs)
GAF=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;string s;cin>>n>>s;vector<vector<int>>best(26,vector<int>(n+1));for(int ch=0;ch<26;ch++){for(int l=0;l<n;l++){int mism=0;for(int r=l;r<n;r++){mism+=s[r]-'a'!=ch;best[ch][mism]=max(best[ch][mism],r-l+1);}}if(!MOD)for(int k=1;k<=n;k++)best[ch][k]=max(best[ch][k],best[ch][k-1]);}int q;cin>>q;while(q--){int m;char ch;cin>>m>>ch;cout<<best[ch-'a'][m]<<'\n';}}'''
GAS=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;string s;cin>>n>>s;int q;cin>>q;while(q--){int m;char ch;cin>>m>>ch;int ans=0;for(int l=0;l<n;l++)for(int r=l;r<n;r++){int mism=0;for(int i=l;i<=r;i++)mism+=s[i]!=ch;if(MOD?mism==m:mism<=m)ans=max(ans,r-l+1);}cout<<ans<<'\n';}}'''
register('cf_814_c',371,'814_C. An impassioned circulation of affection','https://codeforces.com/problemset/problem/814/C',garland_gen,garland_val,GAF,GAS,'For each pair(m,c), find the longest substring containing at most m characters different from c; this equals the longest all-c substring obtainable after at most m repaintings.','Change the selected-substring condition to EXACTLY m characters different from c. Only those mismatching characters are repainted to c. Output0 if no such substring exists.','3\naaa\n1\n1 a\n','n<=14,q<=15','n<=1500,q<=200000',{'fast':'O(26 n^2+q)','slow':'O(q n^3)'},'Enumerating all windows once per color gives the maximum length for each exact mismatch count. Prefix maxima convert exact to at-most budgets for Raw. The oracle separately enumerates every window for every query and recounts its characters directly. L3 is specified as a window predicate to eliminate ambiguity about repainting outside the selected window.',['strings','offline-queries'])

# ABC134C: extremum excluding one occurrence.
def except_val(s,c):
 a=I(s);n=a[0];B(n,2,200000);E(a,n+1)
 for x in a[1:]:B(x,1,200000)
 if c=='weak':B(n,2,30)
 return True
def except_gen(seed,c):
 r=random.Random(seed);n=200000 if c=='l2' else r.randint(2,30);return L([n]+[r.randint(1,200000 if c=='l2' else 20) for _ in range(n)])
EXF=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;vector<int>a(n),p(n+1),s(n+1);for(auto&x:a)cin>>x;p[0]=s[n]=MOD?INT_MAX:INT_MIN;for(int i=0;i<n;i++)p[i+1]=MOD?min(p[i],a[i]):max(p[i],a[i]);for(int i=n-1;i>=0;i--)s[i]=MOD?min(s[i+1],a[i]):max(s[i+1],a[i]);for(int i=0;i<n;i++)cout<<(MOD?min(p[i],s[i+1]):max(p[i],s[i+1]))<<'\n';}'''
EXS=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;vector<int>a(n);for(auto&x:a)cin>>x;for(int i=0;i<n;i++){int best=MOD?INT_MAX:INT_MIN;for(int j=0;j<n;j++)if(i!=j)best=MOD?min(best,a[j]):max(best,a[j]);cout<<best<<'\n';}}'''
register('atcoder_abc134_c',392,'p02971 AtCoder Beginner Contest 134 - Exception Handling','https://atcoder.jp/contests/abc134/tasks/abc134_c',except_gen,except_val,EXF,EXS,'For each index i output the maximum of the other N-1 array occurrences.','Output the MINIMUM of the other N-1 occurrences instead.','3\n1\n2\n3\n','N<=30','N<=200000',{'fast':'O(N)','slow':'O(N^2)'},'Prefix and suffix extrema partition all indices except i into two independent ranges. The oracle scans all surviving occurrences from scratch for each excluded index.',['arrays','prefix-sums'])

# ABC120C: cancellation system with a genuine different pair predicate.
def unify_val(s,c):
 a=s.split();E(a,1);w=a[0];B(len(w),1,400000 if c=='l2' else 100000);assert set(w)<=set('01');assert c!='weak' or len(w)<=40;return True
def unify_gen(seed,c):
 r=random.Random(seed);w='0'*200000+'1'*200000 if c=='l2' else ''.join(r.choice('01') for _ in range(r.randint(1,40)));return w+'\n'
UNF=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);string s;cin>>s;if(!MOD){int z=count(s.begin(),s.end(),'0');cout<<2*min(z,(int)s.size()-z)<<'\n';}else{string st;for(char c:s){if(!st.empty()&&st.back()==c)st.pop_back();else st.push_back(c);}cout<<s.size()-st.size()<<'\n';}}'''
UNS=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);string s;cin>>s;int removed=0;while(true){bool found=false;for(int i=0;i+1<(int)s.size();i++)if(MOD?s[i]==s[i+1]:s[i]!=s[i+1]){s.erase(i,2);removed+=2;found=true;break;}if(!found)break;}cout<<removed<<'\n';}'''
register('atcoder_abc120_c',393,'p03107 AtCoder Beginner Contest 120 - Unification','https://atcoder.jp/contests/abc120/tasks/abc120_c',unify_gen,unify_val,UNF,UNS,'Repeatedly remove an adjacent pair of different binary colors; output the maximum removable cube count.','Only adjacent pairs of the SAME color may be removed.','01\n','length<=40','length<=400000 (source original<=100000)',{'fast':'O(length)','slow':'O(length^2)'},'Raw cancels one zero and one one each time and reaches2*min(count0,count1). Under equal-color cancellation, aa->empty is a confluent terminating rewrite system (the only overlap aaa reduces to a either way), so a stack gives the unique irreducible residue. The oracle repeatedly searches from the beginning and erases the leftmost legal pair literally.',['strings','stack'])

# 1003D: bounded and unlimited power-of-two coins.
def coins_val(s,c):
 a=I(s);n,q=a[:2];B(n,1,200000);B(q,1,200000);E(a,2+n+q)
 for x in a[2:2+n]:B(x,1,2*10**9);assert x&(x-1)==0
 for x in a[2+n:]:B(x,1,10**9)
 if c=='weak':B(n,1,14);B(q,1,12)
 return True
def coins_gen(seed,c):
 r=random.Random(seed)
 if c=='l2':return L(['200000 1',' '.join(['1']*200000),200001])
 n=14 if c=='weak' else r.randint(1,11);q=r.randint(1,12);a=[1<<r.randrange(6) for _ in range(n)];return L([f'{n} {q}',' '.join(map(str,a))]+[r.randint(1,60) for _ in range(q)])
CNF=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,q;cin>>n>>q;array<ll,31>cnt{};for(int i=0,x;i<n;i++){cin>>x;cnt[__builtin_ctz((unsigned)x)]++;}while(q--){ll b;cin>>b;ll used=0;for(int k=30;k>=0;k--){ll take=b/(1LL<<k);take=MOD?(cnt[k]?take:0):min(take,cnt[k]);used+=take;b-=take*(1LL<<k);}cout<<(b?-1:used)<<'\n';}}'''
CNS=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,q;cin>>n>>q;vector<ll>a(n);for(auto&x:a)cin>>x;while(q--){int b;cin>>b;ll best=1LL<<60;if(MOD){vector<int>d(b+1,INT_MAX/2);d[0]=0;for(int z=1;z<=b;z++)for(ll v:a)if(v<=z)d[z]=min(d[z],d[z-v]+1);if(d[b]<INT_MAX/2)best=d[b];}else{vector<int>on(n);while(true){ll sum=0,c=0;for(int i=0;i<n;i++)if(on[i])sum+=a[i],c++;if(sum==b)best=min(best,c);int j=0;while(j<n&&on[j])on[j++]=0;if(j==n)break;on[j]=1;}}cout<<(best==(1LL<<60)?-1:best)<<'\n';}}'''
register('cf_1003_d',422,'1003_D. Coins and Queries','https://codeforces.com/problemset/problem/1003/D',coins_gen,coins_val,CNF,CNS,'For each independent positive target, find the minimum number of available power-of-two coins summing exactly to it, or-1. Each input occurrence is usable at most once.','Every denomination present in the input is available in UNLIMITED quantity; absent denominations remain unavailable.','1 1\n2\n4\n','n<=14,q<=12 (oracle targets<=60)','n,q<=200000',{'fast':'O(n+31q)','slow':'O(q n 2^n)'},'For powers of two, exchanging two coins of a smaller size for one available double-size coin never increases the count. Descending greedy therefore minimizes coin count for both bounded and unlimited supply. Raw oracle enumerates every subset; L3 oracle solves minimum-coin shortest paths on integer target sums by dynamic programming.',['greedy','coins'])

# 1110E: unlimited adjacent-difference permutations vs one physical operation.
def magic_val(s,c):
 a=I(s);n=a[0];B(n,2,100000);E(a,1+2*n)
 for x in a[1:]:B(x,0,2*10**9)
 if c=='weak':B(n,2,8)
 return True
def magic_gen(seed,c):
 r=random.Random(seed);n=20000 if c=='l2' else r.randint(2,8);d=list(range(1,n)) if c=='l2' else [r.randint(0,10) for _ in range(n-1)];dd=d[::-1] if c=='l2' else r.sample(d,len(d));a=[0];b=[0]
 for x in d:a.append(a[-1]+x)
 for x in dd:b.append(b[-1]+x)
 if c!='l2' and seed%3==0:b[r.randrange(n)]+=1
 return L([n,' '.join(map(str,a)),' '.join(map(str,b))])
MAF=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;vector<ll>a(n),b(n);for(auto&x:a)cin>>x;for(auto&x:b)cin>>x;bool ok=false;if(MOD){vector<int>mis;for(int i=0;i<n;i++)if(a[i]!=b[i])mis.push_back(i);if(mis.empty())ok=true;else if(mis.size()==1){int i=mis[0];ok=i>0&&i<n-1&&a[i-1]+a[i+1]-a[i]==b[i];}}else if(a[0]==b[0]&&a.back()==b.back()){vector<ll>x,y;for(int i=1;i<n;i++)x.push_back(a[i]-a[i-1]),y.push_back(b[i]-b[i-1]);sort(x.begin(),x.end());sort(y.begin(),y.end());ok=x==y;}cout<<(ok?"Yes":"No")<<'\n';}'''
MAS=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;vector<ll>a(n),b(n);for(auto&x:a)cin>>x;for(auto&x:b)cin>>x;bool ok=false;if(MOD){ok=a==b;for(int i=1;i+1<n;i++){vector<ll>v=a;v[i]=a[i-1]+a[i+1]-a[i];if(v==b)ok=true;}}else if(a[0]==b[0]&&a.back()==b.back()){vector<ll>d;for(int i=1;i<n;i++)d.push_back(a[i]-a[i-1]);sort(d.begin(),d.end());do{ll cur=a[0];bool match=true;for(int i=1;i<n;i++){cur+=d[i-1];if(cur!=b[i]){match=false;break;}}if(match){ok=true;break;}}while(next_permutation(d.begin(),d.end()));}cout<<(ok?"Yes":"No")<<'\n';}'''
register('cf_1110_e',427,'1110_E. Magic Stones','https://codeforces.com/problemset/problem/1110/E',magic_gen,magic_val,MAF,MAS,'Decide whether zero or more operations c_i:=c_(i-1)+c_(i+1)-c_i at internal indices transform C into T.','Allow AT MOST ONE synchronization operation instead of an arbitrary number.','4\n7 2 4 12\n7 15 10 12\n','n<=8','n<=100000 (stress n20000)',{'fast':'O(n log n) Raw; O(n) L3','slow':'O(n*(n-1)!) Raw'},'A synchronization swaps two adjacent first differences while keeping endpoints. Adjacent swaps generate all permutations, so equal endpoint and difference multiset is necessary and sufficient. The independent raw oracle enumerates all difference permutations and reconstructs charges. L3 can differ at only one internal coordinate; its oracle literally tries every possible operation.',['invariants','sorting'])

# 1344A: reversal of displacement direction.
def hotel_val(s,c):
 a=I(s);T=a[0];B(T,1,10000);p=1;total=0
 for _ in range(T):
  n=a[p];p+=1;B(n,1,200000);total+=n;assert p+n<=len(a)
  for x in a[p:p+n]:B(x,-10**9,10**9)
  p+=n
  if c=='weak':B(n,1,30)
 assert p==len(a);B(total,1,200000);return True
def hotel_gen(seed,c):
 r=random.Random(seed);n=200000 if c=='l2' else r.randint(1,30);a=[0]*n if c=='l2' else [r.randint(-30,30) for _ in range(n)];return L([1,n,' '.join(map(str,a))])
HOF=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;cin>>n;vector<bool>seen(n);bool ok=true;for(int i=0;i<n;i++){ll x;cin>>x;ll at=((i+(MOD?-x:x))%n+n)%n;if(seen[at])ok=false;seen[at]=true;}cout<<(ok?"YES":"NO")<<'\n';}}'''
HOS=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;cin>>n;vector<ll>a(n);for(auto&x:a)cin>>x;bool ok=true;for(int i=0;i<n;i++)for(int j=0;j<i;j++){ll di=i+(MOD?-a[i]:a[i]),dj=j+(MOD?-a[j]:a[j]);if((di-dj)%n==0)ok=false;}cout<<(ok?"YES":"NO")<<'\n';}}'''
register('cf_1344_a',438,"1344_A. Hilbert's Hotel",'https://codeforces.com/problemset/problem/1344/A',hotel_gen,hotel_val,HOF,HOS,'For every integer room k move its guest to k+a_(k mod n); decide whether every room receives exactly one guest.','Move each guest to k-a_(k mod n) instead of k+a_(k mod n).','1\n3\n0 1 2\n','n<=30','sum n<=200000',{'fast':'O(n)','slow':'O(n^2)'},'Every residue class maps bijectively to one destination residue class, so the infinite map is bijective exactly when the n destination residues are distinct. The optimized program marks residues; the oracle checks every pair of displacement differences for divisibility by n.',['modular-arithmetic','bijections'])

def check_output(id,input_text,candidate_text,oracle_text,condition):
 if id in {'cf_1110_e','cf_1344_a'}:return candidate_text.lower().split()==oracle_text.lower().split()
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
