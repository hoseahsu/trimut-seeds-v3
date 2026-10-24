"""Geometry/string batch; complex Raw references are exact upstream copies."""
from pathlib import Path
import hashlib,bisect,collections
IDS='area_of_union_of_rectangles number_of_subsequences enumerate_palindromes zalgorithm closest_pair furthest_pair all_furthest_neighbors static_convex_hull static_range_mode_query minimum_enclosing_circle'.split()
ROOT=Path(__file__).resolve().parents[1];ASSET=ROOT/'assets/library_batch4';SRC=ROOT/'sources/library-checker-problems-master'
SPEC={
'area_of_union_of_rectangles':('coverage at least1 → at least2','Compute area covered by at least two input rectangle instances; identical rectangles count separately.','Sweep-line segment nodes retain lengths covered at least once and twice; the coverage counter determines whether child first- or second-threshold lengths contribute.'),
'number_of_subsequences':('all nonempty → even nonempty subsequences','Count distinct nonempty subsequences of even length modulo998244353.','Maintain even/odd counts including the empty even subsequence; append swaps parity and subtracts contributions recorded before the previous occurrence of the same value. Remove empty subsequence at the end.','Source English omits nonempty but Japanese explicitly states it, and upstream reference subtracts1; Raw preserves this verified convention.'),
'enumerate_palindromes':('equal mirror letters → complementary mirror letters','Use mirror condition S[l]+S[r]=a+z in character-code arithmetic, i.e. a↔z,b↔y,...; include center comparison. Return maximal length at each original center; no valid odd-length substring exists.','For even-length substrings mirror positions have opposite parity. Complement letters at odd positions and use even Manacher radii; odd-center outputs are0. This changes the equality predicate, not labels in the input.'),
'zalgorithm':('equal prefix → complementary prefix','At offset i, return greatest k such that S[j] is alphabet-complement of S[i+j] for all0<=j<k; preserve output length N.','Compute ordinary Z on S + separator + complement(S), then read the suffix-region entries. Separator prevents a prefix match longer than N.'),
'closest_pair':('Euclidean → Manhattan closest pair','Minimize |x_i-x_j|+|y_i-y_j| over distinct point indices, retaining any-optimal-pair output.','Transform to u=x+y,v=x-y, where Manhattan distance equals max(|Δu|,|Δv|); sorted sweep with current distance window finds the exact closest pair.'),
'furthest_pair':('Euclidean → Manhattan furthest pair','Maximize Manhattan distance over distinct indices.','Maximum Manhattan distance equals the largest range of x+y or x-y; extreme-point candidates achieve it.'),
'all_furthest_neighbors':('Euclidean → Manhattan furthest neighbors','For each input polygon vertex, return any vertex maximizing Manhattan distance; preserve strict-convex CCW input.','For each point, a maximizer is among extrema of x+y and x-y, so four candidates suffice.'),
'static_convex_hull':('extreme vertices → all input boundary points','Output every distinct input point on the convex-hull boundary. For nondegenerate hulls use counterclockwise boundary order; for collinear points use monotone order along the segment; empty input stays empty.','Andrew monotone chain keeps collinear turns instead of deleting them; explicitly handle fully collinear input to avoid duplicates.'),
'static_range_mode_query':('maximum → minimum positive frequency','Return a value with the least positive occurrence count in each nonempty interval and that count. Values absent from the interval are ineligible.','Mo updates maintain buckets of present values by positive frequency; choose the smallest nonempty frequency bucket.'),
'minimum_enclosing_circle':('enclosing circle → axis-aligned enclosing rectangle','Replace the target object with the unique smallest axis-aligned rectangle containing the points; mark points on its boundary in the original0/1 string format, including degenerate rectangles.','The rectangle is [min x,max x]×[min y,max y]; a point is on its boundary iff any coordinate reaches an extremum. Raw exact small oracle enumerates enclosing circles through pairs/triples.')}
RECIPES={}
for task,id in enumerate(IDS,1):
 for kind,mut,slow in [('raw',0,0),('l3',1,0),('slow',0,1)]:
  path=ASSET/f'{id}_{kind}.cpp'
  if kind=='raw'and task>=5:origin=next(SRC.rglob(id+'/sol/correct.cpp'));text=origin.read_text()
  else:text=f'#define TASK {task}\n#define MUTANT {mut}\n#define SLOW {slow}\n#include "solver.cpp"\n'
  if not path.exists()or path.read_text()!=text:path.write_text(text)
 name,spec,proof,*notes=SPEC[id]
 RECIPES[id]={'source':'library-checker','source_id':id,'source_url':f'https://judge.yosupo.jp/problem/{id}','raw_fast':f'../assets/library_batch4/{id}_raw.cpp','l3_fast':f'../assets/library_batch4/{id}_l3.cpp','slow_baseline':f'../assets/library_batch4/{id}_slow.cpp','raw_oracle':{'path':'../assets/library_batch4/oracle.py','args':[id,'raw']},'l3_oracle':{'path':'../assets/library_batch4/oracle.py','args':[id,'l3']},'budget_seconds':2.0,'memory_mb':1024,'small_timeout_seconds':30.0,'independent_oracles':True,'independent_oracle_note':'Literal independent oracles use coordinate-cell enumeration, subsequence sets, direct mirror scans, exhaustive distances/support lines, counters, and Fraction exact circumcircle enumeration.','mutation_name':name,'mutation_specification':spec,'proof_sketch':proof,'source_interpretation_notes':notes,'family_id':id,'verification_status':'pending_harness','baseline_policy':'Original source is retained; weak/strong versions explicitly change only size caps and preserve other constraints.'}
 if task>=5:RECIPES[id]['raw_reference_provenance']={'file':str(origin.relative_to(ROOT)),'sha256':hashlib.sha256(origin.read_bytes()).hexdigest(),'copied_without_edits':True}

def fmt(head,rows):return ' '.join(map(str,head))+'\n'+''.join(' '.join(map(str,row))+'\n'for row in rows)
def points(cases):return str(len(cases))+'\n'+''.join(str(len(a))+'\n'+''.join(f'{x} {y}\n'for x,y in a)for a in cases)
def array(a,qs=None):return fmt([len(a)]if qs is None else[len(a),len(qs)],[a]+([]if qs is None else qs))
BOUNDARY={
'area_of_union_of_rectangles':[fmt([2],[(0,0,2,2),(1,1,3,3)]),fmt([1],[(0,0,10**9,10**9)])],
'number_of_subsequences':[array([1,2]),array([2,2,2]),array([10**9])],
'enumerate_palindromes':['az\n','azbyybza\n','a\n','aaaa\n'],
'zalgorithm':['aza\n','azaz\n','a\n','aaaa\n'],
'closest_pair':[points([[(0,0),(2,2),(100,0),(103,0)],[(0,0),(0,0)],[(10**9,10**9),(-10**9,-10**9)]])],
'furthest_pair':[points([[(0,0),(5,0),(3,3)],[(0,0),(0,0)],[(10**9,10**9),(-10**9,-10**9)]])],
'all_furthest_neighbors':[points([[(0,0),(5,0),(3,3)],[(0,0),(2,0),(2,2),(0,2)]])],
'static_convex_hull':[points([[],[(0,0)],[(0,0),(1,0),(2,0),(0,2),(0,0)],[(0,0),(1,1),(2,2)]])],
'static_range_mode_query':[array([2,2,7],[(0,3),(0,2),(2,3)]),array([0],[])],
'minimum_enclosing_circle':[fmt([5],[(0,0),(4,0),(0,4),(4,4),(2,0)]),fmt([3],[(-10000,0),(0,0),(10000,0)])]}

def cases(id,mode,rng):
 if mode=='boundary':
  for j,s in enumerate(BOUNDARY[id]):yield f'boundary_{j}',s
  return
 for trial in range(32 if mode=='small'else 2):
  st=mode=='stress'
  if id=='area_of_union_of_rectangles':
   n=50000 if st else(32 if mode=='weak'else rng.randint(1,8));lim=10**9 if st else 15;rows=[]
   for _ in range(n):
    l=rng.randrange(lim);r=rng.randrange(l+1,lim+1);d=rng.randrange(lim);u=rng.randrange(d+1,lim+1);rows.append((l,d,r,u))
   s=fmt([n],rows)
  elif id=='number_of_subsequences':
   n=150000 if st else(14 if mode=='weak'else rng.randint(1,12));a=list(range(n))if st else[rng.randrange(7)for _ in range(n)];s=array(a)
  elif id in ['enumerate_palindromes','zalgorithm']:
   n=150000 if st else(64 if mode=='weak'else rng.randint(1,32));s=('a'*n if st else''.join(rng.choice('abzy')for _ in range(n)))+'\n'
  elif id in ['closest_pair','furthest_pair']:
   n=100000 if st else(40 if mode=='weak'else rng.randint(2,12));lim=10**9 if st else 20;a=[(rng.randint(-lim,lim),rng.randint(-lim,lim))for _ in range(n)];s=points([a])
  elif id=='all_furthest_neighbors':
   n=60000 if st else(40 if mode=='weak'else rng.randint(3,12));x0=-(n//2);a=[(x,x*x)for x in range(x0,x0+n)];s=points([a])
  elif id=='static_convex_hull':
   n=60000 if st else(32 if mode=='weak'else rng.randint(0,12));a=[(x,x*x)for x in range(-(n//2),n-n//2)]if st else[(rng.randint(-12,12),rng.randint(-12,12))for _ in range(n)];s=points([a])
  elif id=='static_range_mode_query':
   n=q=40000 if st else(64 if mode=='weak'else rng.randint(1,18));a=[rng.randrange(30 if st else 5)for _ in range(n)];qs=[]
   for _ in range(q):
    l=rng.randrange(n//8+1)if st else rng.randrange(n);r=rng.randrange(max(l+1,7*n//8),n+1)if st else rng.randrange(l+1,n+1);qs.append((l,r))
   s=array(a,qs)
  else:
   n=1500 if st else(8 if mode=='weak'else rng.randint(2,8));vals=rng.sample(range(20001*20001),n);a=[(v//20001-10000,v%20001-10000)for v in vals];s=fmt([n],a)
  yield f'{mode}_{trial}',s

def cross(a,b,c):return(b[0]-a[0])*(c[1]-a[1])-(b[1]-a[1])*(c[0]-a[0])
def hull(a):
 a=sorted(set(a))
 if len(a)<=1:return a
 lo=[];hi=[]
 for p in a:
  while len(lo)>1 and cross(lo[-2],lo[-1],p)<=0:lo.pop()
  lo.append(p)
 for p in reversed(a):
  while len(hi)>1 and cross(hi[-2],hi[-1],p)<=0:hi.pop()
  hi.append(p)
 return lo[:-1]+hi[:-1]
def cycle_equal(a,b):
 if len(a)!=len(b):return False
 if not a:return True
 try:k=b.index(a[0])
 except ValueError:return False
 return a==b[k:]+b[:k]
def parse_points(text,multi=True):
 ts=list(map(int,text.split()));i=0
 if multi:t=ts[0];i=1
 else:t=1
 out=[]
 for _ in range(t):
  n=ts[i];i+=1;a=[tuple(ts[j:j+2])for j in range(i,i+2*n,2)];i+=2*n;out.append(a)
 assert i==len(ts)
 return out

def validate_input(id,text,condition):
 try:
  if id in ['enumerate_palindromes','zalgorithm']:
   ts=text.split();return len(ts)==1 and 1<=len(ts[0])<=500000 and set(ts[0])<=set('abcdefghijklmnopqrstuvwxyz')
  ts=list(map(int,text.split()));i=0
  def val(lo,hi):
   nonlocal i
   v=ts[i];i+=1;assert lo<=v<=hi;return v
  if id=='area_of_union_of_rectangles':
   n=val(1,500000)
   for _ in range(n):l,d,r,u=[val(0,10**9)for _ in range(4)];assert l<r and d<u
  elif id=='number_of_subsequences':
   n=val(1,500000)
   for _ in range(n):val(0,10**9)
  elif id=='static_range_mode_query':
   n,q=val(1,100000),val(0,100000)
   for _ in range(n):val(0,10**9)
   for _ in range(q):l,r=val(0,n-1),val(1,n);assert l<r
  elif id=='minimum_enclosing_circle':
   n=val(2,100000);a=[(val(-10000,10000),val(-10000,10000))for _ in range(n)];assert len(set(a))==n
  else:
   T=val(1,100000);total=0
   for _ in range(T):
    n=val(0 if id=='static_convex_hull'else(3 if id=='all_furthest_neighbors'else 2),500000);total+=n;a=[(val(-10**9,10**9),val(-10**9,10**9))for _ in range(n)]
    if id=='all_furthest_neighbors':assert len(set(a))==n and cycle_equal(a,hull(a))
   assert total<=500000
  return i==len(ts)
 except(ValueError,IndexError,AssertionError):return False

def check_output(id,text,candidate,oracle,condition):
 mut=condition=='l3'
 if id not in ['closest_pair','furthest_pair','all_furthest_neighbors','static_convex_hull','static_range_mode_query']:return candidate.split()==oracle.split()
 try:
  c=list(map(int,candidate.split()));o=list(map(int,oracle.split()))
  if id=='static_range_mode_query':
   ts=list(map(int,text.split()));n,q=ts[:2];a=ts[2:2+n];qs=list(zip(ts[2+n::2],ts[3+n::2]));assert len(c)==len(o)==2*q;pos=collections.defaultdict(list)
   for j,v in enumerate(a):pos[v].append(j)
   for j,(l,r)in enumerate(qs):
    v,f=c[2*j:2*j+2];p=pos[v];assert f==o[2*j+1]and f>0 and bisect.bisect_left(p,r)-bisect.bisect_left(p,l)==f
   return True
  cases=parse_points(text);ci=oi=0
  def d(a,b):return abs(a[0]-b[0])+abs(a[1]-b[1])if mut else(a[0]-b[0])**2+(a[1]-b[1])**2
  for a in cases:
   n=len(a)
   if id in ['closest_pair','furthest_pair']:
    u,v=c[ci:ci+2];x,y=o[oi:oi+2];ci+=2;oi+=2;assert 0<=u<n and 0<=v<n and u!=v and d(a[u],a[v])==d(a[x],a[y])
   elif id=='all_furthest_neighbors':
    cs,os=c[ci:ci+n],o[oi:oi+n];ci+=n;oi+=n;assert len(cs)==len(os)==n
    for j,(u,v)in enumerate(zip(cs,os)):assert 0<=u<n and d(a[j],a[u])==d(a[j],a[v])
   else:
    nc,no=c[ci],o[oi];ci+=1;oi+=1;assert 0<=nc<=n and 0<=no<=n
    cs=[tuple(c[j:j+2])for j in range(ci,ci+nc*2,2)];os=[tuple(o[j:j+2])for j in range(oi,oi+no*2,2)];ci+=2*nc;oi+=2*no;assert len(cs)==len(set(cs))and set(cs)==set(os)
    if len(cs)<=2:continue
    if not any(cross(os[0],os[1],p)for p in os[2:]):assert cs==sorted(cs)or cs==sorted(cs,reverse=True)
    else:assert cycle_equal(cs,os)
  return ci==len(c)and oi==len(o)
 except(ValueError,IndexError,AssertionError):return False

def distinguishes(id,text,raw,l3):return not check_output(id,text,raw,l3,'l3')
L2={
'area_of_union_of_rectangles':({'N':32},{'N':50000},'O(N^2 log N)','O(N log N)'),
'number_of_subsequences':({'N':14},{'N':150000},'O(N^2)','O(N) expected hash-map'),
'enumerate_palindromes':({'N':64},{'N':150000},'O(N^2)','O(N)'),
'zalgorithm':({'N':64},{'N':150000},'O(N^2)','O(N)'),
'closest_pair':({'T':1,'N':40},{'T':1,'N':100000},'O(N^2)','O(N log N)'),
'furthest_pair':({'T':1,'N':40},{'T':1,'N':100000},'O(N^2)','Raw O(N log N), L3 O(N)'),
'all_furthest_neighbors':({'T':1,'N':40},{'T':1,'N':60000},'O(N^2)','Raw O(N log N), L3 O(N)'),
'static_convex_hull':({'T':1,'N':32},{'T':1,'N':60000},'O(Nh)','O(N log N)'),
'static_range_mode_query':({'N':64,'Q':64},{'N':40000,'Q':40000},'O(NQ log N)','Mo O((N+Q)sqrt(N)log N)'),
'minimum_enclosing_circle':({'N':8},{'N':1500},'O(N^4)','Raw expected O(N), L3 O(N)')}
for id,(weak,strong,slow,fast)in L2.items():RECIPES[id]['l2_design']={'weak_caps':weak,'strong_caps':strong,'slow_complexity':slow,'fast_complexity':fast,'fixed_budget_seconds':2.0,'original_source_preserved':True,'preserved':'objective, I/O schema, coordinate/value domain and non-size constraints'}
