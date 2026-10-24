"""Sixth independently authored batch; one recipe per exact public source."""
from pathlib import Path
import random
BASE=Path(__file__).resolve().parents[1]/'assets'/'cc_a_batch6'
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

#967B: strict water target may be infeasible.
def water_val(s,c):
 a=I(s);n,A,b=a[:3];B(n,1,100000);B(A,1,10000);B(b,1,A);E(a,n+3)
 for x in a[3:]:B(x,1,10000)
 if c=='weak':B(n,1,15)
 return True
def water_gen(seed,c):
 r=random.Random(seed);n=100000 if c=='l2' else (15 if c=='weak' else r.randint(1,12));A=r.randint(1,10000);b=r.randint(1,A);return L([f'{n} {A} {b}',' '.join(str(r.randint(1,10000)) for _ in range(n))])
WAF=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;ll A,B;cin>>n>>A>>B;vector<ll>s(n);ll sum=0;for(ll&x:s)cin>>x,sum+=x;ll first=s[0];sort(s.begin()+1,s.end(),greater<ll>());auto enough=[&](){return MOD?first*A>B*sum:first*A>=B*sum;};int k=0;while(!enough()&&k<n-1)sum-=s[++k];cout<<(enough()?k:-1)<<'\n';}'''
WAS=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;ll A,B;cin>>n>>A>>B;vector<ll>s(n);vector<int>off(max(0,n-1));for(ll&x:s)cin>>x;int best=n;while(true){ll sum=s[0];int cnt=0;for(int i=1;i<n;i++)if(off[i-1])cnt++;else sum+=s[i];bool ok=MOD?s[0]*A>B*sum:s[0]*A>=B*sum;if(ok)best=min(best,cnt);int j=0;while(j<n-1&&off[j])off[j++]=0;if(j==n-1)break;off[j]=1;}cout<<(best==n?-1:best)<<'\n';}'''
register('cf_967_b',1213,'967_B. Watering System','https://codeforces.com/problemset/problem/967/B',water_gen,water_val,WAF,WAS,'Block the fewest holes other than the first so its proportional share s1*A/(sum of unblocked sizes) is at leastB liters.','The first hole must receive STRICTLY MORE THANB liters. Output-1 if no legal blocking set can achieve that.','1 5 5\n1\n','n<=15','n<=100000',{'fast':'O(n log n)','slow':'O(n 2^n)'},'For a fixed number of blocked holes, blocking the largest other sizes minimizes the denominator and maximizes the first share. Try descending sizes until the exact cross-multiplied inequality holds. The oracle enumerates all blocking subsets, never blocking the first hole.',['greedy','sorting'])

#ABC085D: throws take two time units.
def katana_val(s,c):
 a=I(s);n,h=a[:2];B(n,1,100000);B(h,1,10**9);E(a,2+2*n)
 for i in range(n):u,v=a[2+2*i:4+2*i];B(u,1,10**9);B(v,u,10**9)
 if c=='weak':B(n,1,15)
 return True
def katana_gen(seed,c):
 r=random.Random(seed);n=100000 if c=='l2' else (15 if c=='weak' else r.randint(1,12));h=10**9 if c=='l2' else r.randint(1,200);e=[]
 for _ in range(n):a=r.randint(1,100);b=r.randint(a,200);e.append(f'{a} {b}')
 return L([f'{n} {h}']+e)
KAF=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;ll h;cin>>n>>h;vector<ll>b(n);ll bestSwing=0;for(int i=0;i<n;i++){ll a;cin>>a>>b[i];bestSwing=max(bestSwing,a);}sort(b.rbegin(),b.rend());ll best=(h+bestSwing-1)/bestSwing,sum=0;for(int k=1;k<=n;k++){sum+=b[k-1];ll rem=max(0LL,h-sum);best=min(best,(MOD?2LL:1LL)*k+(rem+bestSwing-1)/bestSwing);}cout<<best<<'\n';}'''
KAS=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;ll h;cin>>n>>h;vector<ll>a(n),b(n);vector<int>on(n);ll swing=0;for(int i=0;i<n;i++)cin>>a[i]>>b[i],swing=max(swing,a[i]);ll best=1LL<<60;while(true){ll damage=0,cost=0;for(int i=0;i<n;i++)if(on[i])damage+=b[i],cost+=MOD?2:1;ll remain=max(0LL,h-damage);cost+=remain/swing+(remain%swing!=0);best=min(best,cost);int j=0;while(j<n&&on[j])on[j++]=0;if(j==n)break;on[j]=1;}cout<<best<<'\n';}'''
register('atcoder_abc085_d',1231,'p03472 AtCoder Beginner Contest 085 - Katana Thrower','https://atcoder.jp/contests/abc085/tasks/abc085_d',katana_gen,katana_val,KAF,KAS,'Defeat a monster of healthH. Swinging retained katana i dealsa_i and may be repeated; throwing it dealsb_i and permanently removes it. Each attack costs one time unit. Minimize total time.','A THROW takes TWO time units, while a swing still takes one. Minimize total time, with damage and permanent removal unchanged.','1 5\n1 5\n','N<=15','N<=100000,H<=10^9',{'fast':'O(N log N)','slow':'O(N 2^N)'},'All swings can be moved before all throws, so the strongest original swing is available whenever needed. For a fixed numberk of throws, taking thek largest throw damages dominates other subsets, and remaining health is covered by strongest swings. Enumerate prefix sizes. The oracle independently enumerates every thrown subset and combines it with the necessary pre-throw swings.',['greedy','resource-allocation'])

#52B: only southeast-oriented right angles.
def triangle_val(s,c):
 a=s.split();n,m=map(int,a[:2]);B(n,1,1000);B(m,1,1000);E(a,n+2)
 for row in a[2:]:assert len(row)==m and set(row)<=set('.*')
 if c=='weak':B(n,1,6);B(m,1,6)
 return True
def triangle_gen(seed,c):
 r=random.Random(seed);n=m=1000 if c=='l2' else r.randint(1,6);return L([f'{n} {m}']+['*'*m if c=='l2' else ''.join(r.choice('.*') for _ in range(m)) for _ in range(n)])
TGF=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,m;cin>>n>>m;vector<string>a(n);vector<ll>rows(n),cols(m);for(int i=0;i<n;i++){cin>>a[i];for(int j=0;j<m;j++)if(a[i][j]=='*')rows[i]++,cols[j]++;}ll ans=0;if(!MOD){for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(a[i][j]=='*')ans+=(rows[i]-1)*(cols[j]-1);}else{vector<ll>below(m);for(int i=n-1;i>=0;i--){ll right=0;for(int j=m-1;j>=0;j--)if(a[i][j]=='*')ans+=right*below[j],right++;for(int j=0;j<m;j++)below[j]+=a[i][j]=='*';}}cout<<ans<<'\n';}'''
TGS=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,m;cin>>n>>m;vector<string>a(n);for(string&s:a)cin>>s;ll ans=0;for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(a[i][j]=='*')for(int x=0;x<n;x++)if(x!=i&&(!MOD||x>i))for(int y=0;y<m;y++)if(y!=j&&(!MOD||y>j)&&a[x][j]=='*'&&a[i][y]=='*')ans++;cout<<ans<<'\n';}'''
register('cf_52_b',1299,'52_B. Right Triangles','https://codeforces.com/problemset/problem/52/B',triangle_gen,triangle_val,TGF,TGS,'Count right triangles whose vertices are starred grid-cell centers and whose two perpendicular legs are parallel to the grid axes.','Count only triangles whose horizontal leg extends RIGHT and whose vertical leg extends DOWN from their right-angle vertex.','2 2\n.*\n**\n','H,W<=6','H,W<=1000',{'fast':'O(HW)','slow':'O(H^2W^2)'},'A right-angle star independently chooses another star in its row and column. Raw uses full row/column counts minus itself. L3 uses suffix counts strictly to its right and below. The oracle explicitly enumerates the right-angle cell and both other vertex coordinates, checking stars and orientation.',['grids','counting'])

#Exact CodeNet source name retained: no invented AOJ identity.
def tsp_val(s,c):
 a=I(s);n,m=a[:2];B(n,2,15);B(m,0,n*n);E(a,2+3*m);edges=set()
 for i in range(m):
  u,v,w=a[2+3*i:5+3*i];B(u,0,n-1);B(v,0,n-1);B(w,0,1000);assert (u,v) not in edges;edges.add((u,v))
 if c=='weak':B(n,2,8)
 return True
def tsp_gen(seed,c):
 r=random.Random(seed);n=15 if c=='l2' else r.randint(2,8);e=[]
 for i in range(n):
  for j in range(n):
   if i!=j and (c=='l2' or r.randrange(3)):e.append(f'{i} {j} {r.randint(0,30)}')
 return L([f'{n} {len(e)}']+e)
TSF=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,m;cin>>n>>m;const ll INF=1LL<<55;vector<vector<ll>>w(n,vector<ll>(n,-1));while(m--){int u,v;ll d;cin>>u>>v>>d;w[u][v]=d;}ll empty=MOD?-INF:INF;vector<vector<ll>>dp(1<<n,vector<ll>(n,empty));dp[1][0]=0;for(int mask=1;mask<(1<<n);mask++)for(int u=0;u<n;u++)if(dp[mask][u]!=empty)for(int v=1;v<n;v++)if(!(mask>>v&1)&&w[u][v]>=0){ll z=dp[mask][u]+w[u][v];ll &d=dp[mask|1<<v][v];d=MOD?max(d,z):min(d,z);}ll ans=empty;for(int u=1;u<n;u++)if(w[u][0]>=0&&dp.back()[u]!=empty){ll z=dp.back()[u]+w[u][0];ans=MOD?max(ans,z):min(ans,z);}cout<<(ans==empty?-1:ans)<<'\n';}'''
TSS=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n,m;cin>>n>>m;vector<vector<ll>>w(n,vector<ll>(n,-1));while(m--){int u,v;ll d;cin>>u>>v>>d;w[u][v]=d;}vector<int>p(n-1);iota(p.begin(),p.end(),1);ll best=MOD?-1:(1LL<<60);do{int prev=0;ll sum=0;bool ok=true;for(int v:p){if(w[prev][v]<0)ok=false;else sum+=w[prev][v];prev=v;}if(w[prev][0]<0)ok=false;else sum+=w[prev][0];if(ok)best=MOD?max(best,sum):min(best,sum);}while(next_permutation(p.begin(),p.end()));cout<<(best==(1LL<<60)?-1:best)<<'\n';}'''
register('codenet_p02323',1355,'p02323 Traveling Salesman Problem','https://huggingface.co/datasets/deepmind/code_contests',tsp_gen,tsp_val,TSF,TSS,'Find the minimum total weight of a directed Hamiltonian cycle, visiting every vertex exactly once and returning to its start. Output-1 if none exists.','Find the MAXIMUM total weight among directed Hamiltonian cycles instead. All vertices still must be visited exactly once.','3 6\n0 1 1\n1 2 1\n2 0 1\n0 2 3\n2 1 3\n1 0 3\n','V<=8','V<=15',{'fast':'O(2^V V^2)','slow':'O((V-1)!V)'},'Fix vertex0 as the start; every cycle admits this rotation. Subset DP records the best path to each last vertex for every visited set, then adds the return edge. The oracle directly enumerates every permutation of the other vertices and checks all directed edges.',['subset-dp','graphs'])

def square_val(s,c):
 a=I(s);h,w=a[:2];B(h,1,1400);B(w,1,1400);E(a,2+h*w);assert set(a[2:])<={0,1}
 if c=='weak':B(h,1,8);B(w,1,8)
 return True
def square_gen(seed,c):
 r=random.Random(seed);h=w=1400 if c=='l2' else r.randint(1,8);return L([f'{h} {w}']+[' '.join('0' if c=='l2' else str(r.randrange(2)) for _ in range(w)) for _ in range(h)])
SQF=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int h,w;cin>>h>>w;vector<int>prev(w+1),cur(w+1);int best=0;for(int i=0;i<h;i++){fill(cur.begin(),cur.end(),0);for(int j=1,x;j<=w;j++){cin>>x;if(x==(MOD?1:0))cur[j]=1+min({prev[j-1],prev[j],cur[j-1]});best=max(best,cur[j]);}swap(prev,cur);}cout<<best*best<<'\n';}'''
SQS=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int h,w;cin>>h>>w;vector<vector<int>>a(h,vector<int>(w));for(auto&r:a)for(int&x:r)cin>>x;int best=0;for(int i=0;i<h;i++)for(int j=0;j<w;j++)for(int k=1;i+k<=h&&j+k<=w;k++){bool ok=true;for(int x=i;x<i+k;x++)for(int y=j;y<j+k;y++)if(a[x][y]!=(MOD?1:0))ok=false;if(ok)best=max(best,k*k);}cout<<best<<'\n';}'''
register('codenet_p02326',1460,'p02326 Largest Square','https://huggingface.co/datasets/deepmind/code_contests',square_gen,square_val,SQF,SQS,'Find the area of the largest axis-aligned square submatrix consisting entirely of zeros in a binary matrix.','Require the square to consist entirely of ONES instead of zeros.','1 2\n0 0\n','H,W<=8','H,W<=1400',{'fast':'O(HW)','slow':'O(HW min(H,W)^3)'},'For an eligible cell, the largest square ending there has side one plus the minimum of the upper, left, and diagonal neighboring square sizes. Ineligible cells reset the size to zero. The oracle independently tests every square position and side by scanning every contained cell.',['grids','dynamic-programming'])

#Min-max pairing versus max-min pairing.
def pairing_val(s,c):
 a=I(s);t=a[0];B(t,1,100);p=1
 for _ in range(t):
  n=a[p];p+=1;B(n,1,100000);assert p+2*n<=len(a)
  for x in a[p:p+2*n]:B(x,1,100000)
  p+=2*n
  if c=='weak':B(n,1,4)
 E(a,p);return True
def pairing_gen(seed,c):
 r=random.Random(seed);n=100000 if c=='l2' else r.randint(1,4);return L([1,n,' '.join(str(r.randint(1,100000 if c=='l2' else 30)) for _ in range(2*n))])
PAF=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;cin>>n;vector<int>a(2*n);for(int&x:a)cin>>x;sort(a.begin(),a.end());int ans=MOD?INT_MAX:0;for(int i=0;i<n;i++){int sum=a[i]+a[2*n-1-i];ans=MOD?min(ans,sum):max(ans,sum);}cout<<ans<<'\n';}}'''
PAS=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n;cin>>n;vector<int>a(2*n);for(int&x:a)cin>>x;sort(a.begin(),a.end());int best=MOD?0:INT_MAX;do{int value=MOD?INT_MAX:0;for(int i=0;i<2*n;i+=2){int sum=a[i]+a[i+1];value=MOD?min(value,sum):max(value,sum);}best=MOD?max(best,value):min(best,value);}while(next_permutation(a.begin(),a.end()));cout<<best<<'\n';}}'''
register('hackerearth_minimise_maximum_sum',1534,'minimise-maximum-sum','https://www.hackerearth.com/problem/algorithm/minimise-maximum-sum/',pairing_gen,pairing_val,PAF,PAS,'Partition all2N positive input occurrences intoN pairs so that the MAXIMUM pair sum is as small as possible. Output that minimum achievable maximum.','MAXIMIZE the MINIMUM pair sum instead. Every input occurrence must still belong to exactly one pair.','1\n2\n1 2 3 7\n','N<=4','N<=100000',{'fast':'O(N log N)','slow':'O((2N)!N)'},'Pairing sorted extremes is optimal for either bottleneck objective. Exchange the pairs containing the smallest and largest values so they become a pair; the other two become a pair. This does not worsen the maximal pair sum or the minimal pair sum respectively. Repeat inductively. The oracle enumerates all input permutations, pairs adjacent positions, and evaluates the requested bottleneck.',['sorting','pairing'])

#1081C: at most k changes.
def bricks_val(s,c):
 a=I(s);E(a,3);n,m,k=a;B(n,1,2000);B(m,1,2000);B(k,0,n-1)
 if c=='weak':B(n,1,7);B(m,1,3)
 return True
def bricks_gen(seed,c):
 if c=='l2':return '2000 2000 1000\n'
 r=random.Random(seed);n=r.randint(1,7);return f'{n} {r.randint(1,3)} {r.randrange(n)}\n'
BKF=r'''const ll P=998244353;ll pw(ll a,ll n){ll r=1;for(;n;n>>=1,a=a*a%P)if(n&1)r=r*a%P;return r;}int main(){int n,m,k;cin>>n>>m>>k;ll comb=1,power=1,ans=0;for(int j=0;j<=k;j++){ll value=comb*m%P*power%P;if(MOD||j==k)ans=(ans+value)%P;if(j<k){comb=comb*(n-1-j)%P*pw(j+1,P-2)%P;power=power*(m-1)%P;}}cout<<ans<<'\n';}'''
BKS=r'''int main(){int n,m,k;cin>>n>>m>>k;vector<int>a(n);ll ans=0;while(true){int changes=0;for(int i=1;i<n;i++)changes+=a[i]!=a[i-1];if(MOD?changes<=k:changes==k)ans=(ans+1)%998244353;int j=0;while(j<n&&a[j]==m-1)a[j++]=0;if(j==n)break;a[j]++;}cout<<ans<<'\n';}'''
register('cf_1081_c',1575,'1081_C. Colorful Bricks','https://codeforces.com/problemset/problem/1081/C',bricks_gen,bricks_val,BKF,BKS,'Count colorings ofn ordered bricks withm labeled colors having exactlyk adjacent color changes; output modulo998244353.','Count colorings having AT MOSTk adjacent changes instead of exactlyk.','3 2 1\n','n<=7,m<=3','n,m<=2000',{'fast':'O(k log modulus)','slow':'O(n m^n)'},'Choosej changed gaps amongn-1, choose the initial color inm ways, then each changed gap hasm-1 new-color choices: C(n-1,j)*m*(m-1)^j. Keepj=k or sum throughk. The oracle enumerates every color sequence and directly counts neighboring inequalities.',['combinatorics','modular-arithmetic'])

#1490C: zero cubes now allowed.
def cubes_val(s,c):
 a=I(s);t=a[0];B(t,1,100);E(a,t+1)
 for x in a[1:]:B(x,1,10**12);assert c!='weak' or x<=10000
 return True
def cubes_gen(seed,c):
 if c=='l2':return L([100]+[10**12-i*2 for i in range(100)])
 r=random.Random(seed);t=r.randint(1,5);return L([t]+[r.randint(1,10000) for _ in range(t)])
CBF=r'''int main(){int T;cin>>T;while(T--){ll x;cin>>x;ll l=MOD?0:1,r=10000;bool ok=false;while(l<=r){ll sum=l*l*l+r*r*r;if(sum==x){ok=true;break;}if(sum<x)l++;else r--;}cout<<(ok?"YES":"NO")<<'\n';}}'''
CBS=r'''int main(){int T;cin>>T;while(T--){ll x;cin>>x;bool ok=false;ll start=MOD?0:1;for(ll a=start;a*a*a<=x;a++)for(ll b=start;b*b*b<=x;b++)if(a*a*a+b*b*b==x)ok=true;cout<<(ok?"YES":"NO")<<'\n';}}'''
register('cf_1490_c',1594,'1490_C. Sum of Cubes','https://codeforces.com/problemset/problem/1490/C',cubes_gen,cubes_val,CBF,CBS,'Decide whetherx can be written asa^3+b^3 for positive integersa,b.','Allow a and b to be NONNEGATIVE integers, so zero cubes are permitted.','1\n1\n','x<=10000','t<=100,x<=10^12',{'fast':'O(t cube_root(max x))','slow':'O(t cube_root(max x)^2)'},'The cube sequence is increasing. Two pointers on possible bases discard the smaller base when the sum is too small and the larger when too large; starting at0 instead of1 implements the new domain. The oracle explicitly tests every ordered base pair within the cube-root bound.',['number-theory','two-pointers'])

def check_output(id,input_text,candidate_text,oracle_text,condition):
 if id=='cf_1490_c':return candidate_text.lower().split()==oracle_text.lower().split()
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
