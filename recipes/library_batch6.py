"""Range/contour semantics with source-derived fast programs and literal independent oracles."""
from pathlib import Path
import hashlib
IDS='point_set_range_frequency static_range_sum static_range_sum_with_upper_bound range_affine_point_get range_linear_add_range_min static_range_lis_query vertex_add_range_contour_sum_on_tree vertex_get_range_contour_add_on_tree rooted_tree_topological_order_with_minimum_inversions range_parallel_unionfind'.split()
ROOT=Path(__file__).resolve().parents[1];SRC=ROOT/'sources/library-checker-problems-master';P=998244353
SPEC={
'point_set_range_frequency':('equal → strictly smaller frequency','Keep point assignments; query counts elements strictly smaller than x in [l,r), including0 for empty intervals.','An offline Fenwick tree of compressed Fenwick trees supports point changes and range rank counts in O(log²N). Literal oracle filters every interval.'),
'static_range_sum':('ordinary → alternating range sum','Return a_l-a_(l+1)+a_(l+2)-... for every nonempty [l,r); signs restart with positive at l.','Global signed prefixes and parity of l give the desired sum; oracle evaluates signs relative to the interval start.'),
'static_range_sum_with_upper_bound':('at most → at least threshold','Return count and sum of values at least x in [l,r).','Sort queries and values descending, inserting eligible positions into count/sum Fenwick trees. Oracle directly filters values.'),
'range_affine_point_get':('multiply then add → add then multiply','An update0 l r b c now sets each selected value to b*(a_i+c) modulo998244353; point queries retain their meaning.','Store affine map(b,b*c) instead of(b,c), then compose lazy maps chronologically. Literal oracle explicitly adds c before multiplication.'),
'range_linear_add_range_min':('minimum → maximum range value','Keep linear range additions a_i += b*i+c; each query reports the maximum value in its nonempty range.','Maintain negated array with negated update coefficients in the source lower-hull data structure. Negating its minimum yields the original maximum; this changes the optimized element.'),
'static_range_lis_query':('increasing → decreasing subsequence','Return length of longest strictly decreasing subsequence of the queried interval; empty interval returns0.','For a permutation, mapping p to N-1-p converts decreasing chains into increasing chains while preserving positions. Independent quadratic DP uses the reversed inequality directly.'),
'vertex_add_range_contour_sum_on_tree':('[l,r) → (l,r] distance band','Keep point additions; sum query now selects vertices at integer distance strictly greater than l and at most r.','Because distances are integers, the changed band equals [l+1,r+1). Source centroid structure accepts shifted bounds and clips to actual distances; BFS oracle tests inequalities directly.'),
'vertex_get_range_contour_add_on_tree':('[l,r) → (l,r] update band','Range addition now applies to vertices at distance strictly greater than l and at most r; point queries unchanged.','Use [l+1,r+1) in the source centroid update structure. The oracle computes all tree distances and updates the literal selected vertex set.'),
'rooted_tree_topological_order_with_minimum_inversions':('minimize → maximize weighted ordering objective','Keep ancestor-before-descendant constraints; maximize X=sum_(j<i) c[p_i]*d[p_j]. Return maximum and a valid maximizing permutation.','For any permutation, X(C,D)+X(D,C)=sum_(u<v)(c_u*d_v+c_v*d_u), independent of order. The source minimizes swapped-weight X(D,C), then evaluates original X(C,D) on the chosen witness.'),
'range_parallel_unionfind':('product → squared-difference pair score','Keep range-parallel edge insertion; after each query return sum_(i<j,connected(i,j))(x_i-x_j)^2 modulo998244353.','Merging components adds size(B)*sumSquares(A)+size(A)*sumSquares(B)-2*sum(A)*sum(B). Original range-union acceleration remains, while component statistics and objective change.')}
RECIPES={}
for task,id in enumerate(IDS,1):
 name,spec,proof=SPEC[id]
 RECIPES[id]={'source':'library-checker','source_id':id,'source_url':f'https://judge.yosupo.jp/problem/{id}','raw_fast':f'../assets/library_batch6/{id}_raw.cpp','l3_fast':f'../assets/library_batch6/{id}_l3.cpp','slow_baseline':f'../assets/library_batch6/{id}_slow.cpp','raw_oracle':{'path':'../assets/library_batch6/oracle.py','args':[id,'raw']},'l3_oracle':{'path':'../assets/library_batch6/oracle.py','args':[id,'l3']},'budget_seconds':2.0,'memory_mb':1024,'small_timeout_seconds':30.0,'independent_oracles':True,'independent_oracle_note':'Explicit scans, quadratic subsequence DP, BFS distance tables, exhaustive topological permutations, and graph reachability with direct pair scoring.','mutation_name':name,'mutation_specification':spec,'proof_sketch':proof,'family_id':id,'verification_status':'pending_harness','baseline_policy':'Original public source retained; weak/strong changes only size caps.'}
 if task>=5:
  p=next(SRC.rglob(id+'/sol/correct.cpp'));RECIPES[id]['raw_reference_provenance']={'file':str(p.relative_to(ROOT)),'sha256':hashlib.sha256(p.read_bytes()).hexdigest(),'copied_without_edits':task!=9,'compatibility_change':'Explicit cstdio include for scanf/printf declarations'if task==9 else None,'l3_changes':proof}
for id in ['point_set_range_frequency']:RECIPES[id]['split_group']='static_dynamic_range_frequency'
for id in ['vertex_add_range_contour_sum_on_tree','vertex_get_range_contour_add_on_tree']:RECIPES[id]['split_group']='tree_distance_band_dual_operations'
RECIPES['static_range_lis_query'].update(semantic_collision_group='standard_monotone_subsequences',novel_semantics_claim=False,split_group='standard_monotone_subsequences')
def fmt(head,rows):return ' '.join(map(str,head))+'\n'+''.join(' '.join(map(str,r))+'\n'for r in rows)
def arr(a,qs):return fmt([len(a),len(qs)],[a]+qs)
BOUNDARY={
'point_set_range_frequency':[arr([1,2,2],[(1,0,3,2),(0,0,3),(1,0,2,3),(1,1,1,2)]),arr([],[(1,0,0,0)])],
'static_range_sum':[arr([1,2,3],[(0,3),(1,3),(2,3)])],
'static_range_sum_with_upper_bound':[arr([1,2,3],[(0,3,2),(0,0,2),(0,3,0),(0,3,10**9)])],
'range_affine_point_get':[arr([5],[(0,0,1,2,3),(1,0),(0,0,1,1,0),(1,0)])],
'range_linear_add_range_min':[arr([-3,2,7],[(1,0,3),(0,0,2,-2,5),(1,0,3),(1,1,2)])],
'static_range_lis_query':[arr([0,1,2],[(0,3),(1,1),(0,1)]),arr([2,1,0],[(0,3)])],
'vertex_add_range_contour_sum_on_tree':[fmt([2,3],[(3,7),(0,1),(1,0,0,1),(0,1,-2),(1,0,0,2)])],
'vertex_get_range_contour_add_on_tree':[fmt([2,3],[(3,7),(0,1),(0,0,0,1,5),(1,0),(1,1)])],
'rooted_tree_topological_order_with_minimum_inversions':[fmt([3],[(0,0),(0,1,3),(0,4,2)]),fmt([1],[[],[0],[0]])],
'range_parallel_unionfind':[arr([1,3,5],[(1,0,1),(2,0,1),(0,3,3)])]}
def cases(id,mode,rng):
 if mode=='boundary':
  for j,s in enumerate(BOUNDARY[id]):yield f'boundary_{j}',s
  return
 for trial in range(32 if mode=='small'else 2):
  st=mode=='stress';weak=mode=='weak'
  if id=='rooted_tree_topological_order_with_minimum_inversions':
   n=14 if st else(8 if weak else rng.randint(1,7));par=[0 if st else rng.randrange(v)for v in range(1,n)];c=[rng.randrange(31)for _ in range(n)];d=[rng.randrange(31)for _ in range(n)];s=fmt([n],[par,c,d])
  elif id in ['vertex_add_range_contour_sum_on_tree','vertex_get_range_contour_add_on_tree']:
   n=q=60000 if st else(24 if weak else rng.randint(1,12));a=[rng.randint(-10**9,10**9)for _ in range(n)];rows=[a]+[(v,(v-1)//2 if st else rng.randrange(v))for v in range(1,n)]
   for j in range(q):
    p=rng.randrange(n);l=rng.randrange(n);r=rng.randrange(l+1,n+1);x=rng.randint(-10**9,10**9)
    if id.startswith('vertex_add'):row=(0,p,x)if j%4==0 else(1,p,l,r)
    else:row=(1,p)if j%4==0 else(0,p,l,r,x)
    rows.append(row)
   s=fmt([n,q],rows)
  else:
   sizes={'point_set_range_frequency':200000,'static_range_sum':250000,'static_range_sum_with_upper_bound':120000,'range_affine_point_get':120000,'range_linear_add_range_min':100000,'static_range_lis_query':40000,'range_parallel_unionfind':150000};n=q=sizes[id]if st else(24 if weak else rng.randint(1,15));a=[rng.randrange(10**9+1)for _ in range(n)];qs=[]
   if id=='static_range_lis_query':a=list(range(n));rng.shuffle(a)
   if id=='range_affine_point_get'or id=='range_parallel_unionfind':a=[rng.randrange(P)for _ in range(n)]
   if id=='range_linear_add_range_min':a=[rng.randrange(-10**9+1,10**9)for _ in range(n)]
   for j in range(q):
    l=rng.randrange(n//8+1)if st else rng.randrange(n);r=rng.randrange(7*n//8,n+1)if st else rng.randrange(l+1,n+1)
    if id=='point_set_range_frequency':row=(0,rng.randrange(n),rng.randrange(10**9+1))if j%4==0 else(1,l,r,rng.randrange(10**9+1))
    elif id in ['static_range_sum','static_range_lis_query']:row=(l,r)
    elif id=='static_range_sum_with_upper_bound':row=(l,r,rng.randrange(10**9+1))
    elif id=='range_affine_point_get':row=(1,rng.randrange(n))if j%4==0 else(0,l,r,rng.randrange(1,P),rng.randrange(P))
    elif id=='range_linear_add_range_min':row=(1,l,r)if j%4==0 else(0,l,r,rng.randrange(-99,100),rng.randrange(-9999999,10000000))
    else:
     k=n-1 if st else rng.randrange(n+1);row=(k,0,1)if st else(k,rng.randrange(n-k+1),rng.randrange(n-k+1))
    qs.append(row)
   s=arr(a,qs)
  yield f'{mode}_{trial}',s

def validate_input(id,text,condition):
 try:
  ts=list(map(int,text.split()));i=0
  def val(lo,hi):
   nonlocal i
   v=ts[i];i+=1;assert lo<=v<=hi;return v
  if id=='rooted_tree_topological_order_with_minimum_inversions':
   n=val(1,200000)
   for v in range(1,n):val(0,v-1)
   for _ in range(2):assert sum(val(0,10**9)for _ in range(n))<=10**9
  else:
   n=val(0 if id=='point_set_range_frequency'else 1,200000 if id=='point_set_range_frequency'else 100000 if id in ['range_linear_add_range_min','static_range_lis_query','vertex_add_range_contour_sum_on_tree','vertex_get_range_contour_add_on_tree']else 500000);q=val(0 if id=='point_set_range_frequency'else 1,200000 if id in ['point_set_range_frequency','vertex_add_range_contour_sum_on_tree','vertex_get_range_contour_add_on_tree']else 100000 if id in ['range_linear_add_range_min','static_range_lis_query']else 500000)
   is_tree=id.startswith('vertex_');lo=-10**9 if is_tree else -10**9+1 if id=='range_linear_add_range_min'else 0;hi=P-1 if id in ['range_affine_point_get','range_parallel_unionfind']else n-1 if id=='static_range_lis_query'else 10**9-1 if id=='range_linear_add_range_min'else 10**9;a=[val(lo,hi)for _ in range(n)]
   if id=='static_range_lis_query':assert len(set(a))==n
   if is_tree:
    par=list(range(n))
    def f(v):
     while par[v]!=v:par[v]=par[par[v]];v=par[v]
     return v
    for _ in range(n-1):u,v=f(val(0,n-1)),f(val(0,n-1));assert u!=v;par[u]=v
   for _ in range(q):
    if id=='point_set_range_frequency':
     ty=val(0,1)
     if ty==0:val(0,n-1);val(0,10**9)
     else:l=val(0,n);val(l,n);val(0,10**9)
    elif id in ['static_range_sum','static_range_lis_query','static_range_sum_with_upper_bound']:
     l=val(0,n-1 if id=='static_range_sum'else n);val(l+1 if id=='static_range_sum'else l,n)
     if id=='static_range_sum_with_upper_bound':val(0,10**9)
    elif id=='range_affine_point_get':
     if val(0,1)==1:val(0,n-1)
     else:l=val(0,n-1);val(l+1,n);val(1,P-1);val(0,P-1)
    elif id=='range_linear_add_range_min':
     ty=val(0,1);l=val(0,n-1);val(l+1,n)
     if ty==0:val(-99,99);val(-9999999,9999999)
    elif is_tree:
     ty=val(0,1);val(0,n-1)
     if id.startswith('vertex_add'):
      if ty==0:val(-10**9,10**9)
      else:l=val(0,n-1);val(l+1,n)
     elif ty==0:l=val(0,n-1);val(l+1,n);val(-10**9,10**9)
    else:k=val(0,n);val(0,n-k);val(0,n-k)
  return i==len(ts)
 except(ValueError,IndexError,AssertionError):return False

def check_output(id,text,candidate,oracle,condition):
 if id!='rooted_tree_topological_order_with_minimum_inversions':return candidate.split()==oracle.split()
 try:
  a=list(map(int,text.split()));n=a[0];par=[-1]+a[1:n];c=a[n:2*n];d=a[2*n:3*n];out=list(map(int,candidate.split()));other=list(map(int,oracle.split()));assert len(out)==n+1 and out[0]==other[0];p=out[1:];assert sorted(p)==list(range(n));loc=[0]*n
  for j,v in enumerate(p):loc[v]=j
  assert all(loc[par[v]]<loc[v]for v in range(1,n));s=z=0
  for v in p:z+=s*c[v];s+=d[v]
  return z==out[0]
 except(ValueError,IndexError,AssertionError):return False

def distinguishes(id,text,raw,l3):return not check_output(id,text,raw,l3,'l3')
L2={
'point_set_range_frequency':({'N':24,'Q':24},{'N':200000,'Q':200000},'O(NQ)','O((N+Q)log²N)'),
'static_range_sum':({'N':24,'Q':24},{'N':250000,'Q':250000},'O(NQ)','O(N+Q)'),
'static_range_sum_with_upper_bound':({'N':24,'Q':24},{'N':120000,'Q':120000},'O(NQ)','O((N+Q)log N)'),
'range_affine_point_get':({'N':24,'Q':24},{'N':120000,'Q':120000},'O(NQ)','O((N+Q)log N)'),
'range_linear_add_range_min':({'N':24,'Q':24},{'N':100000,'Q':100000},'O(NQ)','source dynamic lower-hull range structure'),
'static_range_lis_query':({'N':24,'Q':24},{'N':40000,'Q':40000},'O(NQ log N)','source seaweed/Monge preprocessing and wavelet queries'),
'vertex_add_range_contour_sum_on_tree':({'N':24,'Q':24},{'N':60000,'Q':60000},'O(NQ)','O((N+Q)log²N)'),
'vertex_get_range_contour_add_on_tree':({'N':24,'Q':24},{'N':60000,'Q':60000},'O(NQ)','O((N+Q)log²N)'),
'rooted_tree_topological_order_with_minimum_inversions':({'N':8},{'N':14},'O(N!N)','O(N log N)'),
'range_parallel_unionfind':({'N':24,'Q':24},{'N':150000,'Q':150000},'O(NQ alpha(N))','O((N+Q)log N alpha(N))')}
for id,(weak,strong,slow,fast)in L2.items():RECIPES[id]['l2_design']={'weak_caps':weak,'strong_caps':strong,'slow_complexity':slow,'fast_complexity':fast,'fixed_budget_seconds':2.0,'original_source_preserved':True,'preserved':'objective, I/O schema, numeric domains and structural constraints'}
