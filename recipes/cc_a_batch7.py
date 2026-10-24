"""Seventh independently authored batch; one recipe per exact public source."""
from pathlib import Path
import random
BASE=Path(__file__).resolve().parents[1]/'assets'/'cc_a_batch7'
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

#2A: reverse only the historical tie-break among final top scorers.
def winner_val(s,c):
 a=s.split();n=int(a[0]);B(n,1,200000 if c=='l2' else 1000);E(a,1+2*n);tot={}
 for i in range(n):
  name=a[1+2*i];score=int(a[2+2*i]);B(len(name),1,32);assert all('a'<=x<='z' for x in name);B(score,-1000,1000);tot[name]=tot.get(name,0)+score
 assert max(tot.values())>0
 if c=='weak':B(n,1,35)
 return True
def winner_gen(seed,c):
 r=random.Random(seed);n=200000 if c=='l2' else r.randint(1,35)
 if c=='l2':
  def name(i):
   s=''
   for _ in range(5):s+=chr(97+i%26);i//=26
   return s
  events=[f'{name(i)} 1' for i in range(n)]
 else:
  pairs=[(r.choice(['amy','bob','cal','dan']),r.randint(-3,8)) for _ in range(n-1)];pairs.append(('zoe',1));events=[f'{a} {b}' for a,b in pairs]
 return L([n]+events)
WIF=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;vector<pair<string,int>>e(n);map<string,ll>total,cur;for(auto &[s,x]:e)cin>>s>>x,total[s]+=x;ll top=0;for(auto [s,x]:total)top=max(top,x);set<string>reached;string ans;for(auto [s,x]:e){cur[s]+=x;if(total[s]==top&&cur[s]>=top&&!reached.count(s)){reached.insert(s);if(MOD||ans.empty())ans=s;}}cout<<ans<<'\n';}'''
WIS=r'''int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;vector<pair<string,int>>e(n);set<string>names;for(auto &[s,x]:e)cin>>s>>x,names.insert(s);ll bestscore=LLONG_MIN;int besttime=MOD?-1:INT_MAX;string ans;for(string who:names){ll score=0;for(auto [s,x]:e)if(s==who)score+=x;ll running=0;int first=n;for(int i=0;i<n;i++)if(e[i].first==who){running+=e[i].second;if(running>=score&&first==n)first=i;}if(score>bestscore||(score==bestscore&&(MOD?first>besttime:first<besttime)))bestscore=score,besttime=first,ans=who;}cout<<ans<<'\n';}'''
register('cf_2_a',1499,'2_A. Winner','https://codeforces.com/problemset/problem/2/A',winner_gen,winner_val,WIF,WIS,'Compute every named player final score. Among players tied at the final positive maximumM, the winner is the player whose running score first reached at leastM earliest. Output the winner name.','Among the final maximum-score players, choose the player whose FIRST attainment of at leastM happened LATEST instead of earliest.','2\namy 1\nbob 1\n','n<=35','n<=200000 (explicit L2 extension from source n<=1000)',{'fast':'O(n log n)','slow':'O(n * number_of_distinct_players)'},'A first pass computes final totals and maximumM; a second pass computes each eligible player first reaching time. Compare those first times in the requested direction. The oracle independently rescans the entire log for each distinct player to compute its final total and first qualifying time.',['maps','historical-tie-break'])

#1003C: minimum versus exact segment length.
def heat_val(s,c):
 a=I(s);n,k=a[:2];B(n,1,5000);B(k,1,n);E(a,n+2)
 for x in a[2:]:B(x,1,5000)
 if c=='weak':B(n,1,25)
 return True
def heat_gen(seed,c):
 r=random.Random(seed);n=5000 if c=='l2' else r.randint(1,25);k=1 if c=='l2' else r.randint(1,n);return L([f'{n} {k}',' '.join(str(r.randint(1,5000)) for _ in range(n))])
HEF=r'''int main(){int n,k;cin>>n>>k;vector<ll>p(n+1);for(int i=1;i<=n;i++){ll x;cin>>x;p[i]=p[i-1]+x;}double best=0;for(int l=0;l<n;l++)for(int r=l+k;r<=n;r++){if(MOD&&r!=l+k)break;best=max(best,double(p[r]-p[l])/(r-l));}cout<<fixed<<setprecision(10)<<best<<'\n';}'''
HES=r'''int main(){int n,k;cin>>n>>k;vector<int>a(n);for(int&x:a)cin>>x;double best=0;for(int l=0;l<n;l++)for(int r=l;r<n;r++)if(MOD?r-l+1==k:r-l+1>=k){ll sum=0;for(int i=l;i<=r;i++)sum+=a[i];best=max(best,double(sum)/(r-l+1));}cout<<fixed<<setprecision(10)<<best<<'\n';}'''
register('cf_1003_c',1363,'1003_C. Intense Heat','https://codeforces.com/problemset/problem/1003/C',heat_gen,heat_val,HEF,HES,'Output the maximum arithmetic-mean temperature over all contiguous segments of length AT LEASTk. Absolute output error must be less than10^-6.','Only segments of length EXACTLYk are eligible; maximize their mean with the same output tolerance.','3 2\n10 1 10\n','n<=25','n<=5000',{'fast':'O(n^2) Raw,O(n) L3','slow':'O(n^3)'},'Prefix sums give each eligible segment sum in constant time, so enumerate all valid endpoint pairs. Exact-length windows need only one end per start. The independent oracle recomputes each candidate sum by a literal loop over its elements.',['prefix-sums','subarrays'])

def check_output(id,input_text,candidate_text,oracle_text,condition):
 if id=='cf_1003_c':
  try:
   import math
   x=float(candidate_text.strip());y=float(oracle_text.strip());return math.isfinite(x) and math.isfinite(y) and abs(x-y)<1e-6
  except (ValueError,OverflowError):return False
 return candidate_text.split()==oracle_text.split()
def distinguishes(id,input_text,raw_output,l3_output):
 return not check_output(id,input_text,raw_output,l3_output,'l3')


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
