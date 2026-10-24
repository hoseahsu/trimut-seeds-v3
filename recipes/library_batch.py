"""Ten distinct Library Checker seeds with actual semantic mutations.
No admission claim is made here: the validation harness owns acceptance.
"""
from pathlib import Path
import math
ASSET=Path(__file__).resolve().parents[1]/'assets/library_batch'
IDS=['staticrmq','range_kth_smallest','longest_increasing_subsequence','line_add_get_min','segment_add_get_min','cartesian_tree','minimum_spanning_tree','assignment','static_range_frequency','static_range_inversions_query']
SPECS={
 'staticrmq':('range minimum → range maximum','Replace min(a[l:r]) with max(a[l:r]); retain nonempty half-open ranges.','The idempotent sparse-table aggregate remains associative; replace comparator and identity. A two-value interval distinguishes.'),
 'range_kth_smallest':('k-th smallest → k-th largest','Return the (k+1)-th largest value with duplicate multiplicity retained.','A length-m query seeks ascending rank m-1-k; order statistic exists under unchanged 0<=k<m.'),
 'longest_increasing_subsequence':('strict increasing → nondecreasing','Return optimal length and indices of a longest nondecreasing subsequence.','The tails invariant changes lower_bound to upper_bound; reconstruction retains strictly increasing indices. Duplicate values distinguish.'),
 'line_add_get_min':('lower envelope → upper envelope','Find maximum a*p+b among all inserted lines.','Li Chao invariant depends on two lines crossing at most once and is symmetric under reversed order; comparisons and empty state are reversed, not the returned old answer.'),
 'segment_add_get_min':('segment lower envelope → upper envelope','Find maximum a*p+b over inserted segments with l<=p<r; keep INFINITY as the empty-set token.','Insert each segment into its coordinate interval, then use a maximum Li Chao aggregate; uncovered points still use the explicit empty token.'),
 'cartesian_tree':('minimum Cartesian tree → maximum Cartesian tree','Use the unique largest element as root recursively while preserving inorder positions and root parent=self.','Distinct keys imply a unique max-heap Cartesian tree; reversed stack comparator constructs it in linear time.'),
 'minimum_spanning_tree':('minimum spanning tree → maximum spanning tree','Return maximum total weight among spanning trees and valid original edge indices.','Graphic-matroid greedy selection in descending edge weight yields a maximum spanning tree; independent enumeration checks objective and witness on small graphs.'),
 'assignment':('minimum assignment → maximum assignment','Maximize sum(a[i][p[i]]) over permutations p, preserving witness/output schema.','Negating costs internally reduces a maximum assignment to a minimum assignment; returned witness cost is recomputed on original input, not old-minimum output negation.'),
 'static_range_frequency':('equality count → less-than count','Return number of a[i]<x for l<=i<r, instead of number of a[i]==x.','Each canonical segment stores its sorted multiset; lower_bound counts precisely the new strict predicate. This is not the complement of the old equality output.'),
 'static_range_inversions_query':('strict inversions → weak inversions','Count index pairs l<=i<j<r satisfying a[i]>=a[j], retaining i<j.','Mo updates use inclusive/exclusive Fenwick prefix counts depending on left/right insertion; duplicates produce distinguishing pairs.')}
RECIPES={}
for i,id in enumerate(IDS,1):
 for kind,mut,slow in [('raw',0,0),('l3',1,0),('slow',0,1)]:
  p=ASSET/f'{id}_{kind}.cpp'
  # Separate compile units share an optimized implementation; oracles are independent Python programs.
  content=f'#define TASK {i}\n#define MUTANT {mut}\n#define SLOW {slow}\n#include "solver.cpp"\n'
  if not p.exists() or p.read_text()!=content:p.write_text(content)
 title,spec,proof=SPECS[id]
 RECIPES[id]={
  'source_id':id,'source':'library-checker','source_url':f'https://judge.yosupo.jp/problem/{id}',
  'raw_fast':f'../assets/library_batch/{id}_raw.cpp','l3_fast':f'../assets/library_batch/{id}_l3.cpp',
  'raw_oracle':{'path':'../assets/library_batch/oracle.py','args':[id,'raw']},
  'l3_oracle':{'path':'../assets/library_batch/oracle.py','args':[id,'l3']},
  'slow_baseline':f'../assets/library_batch/{id}_slow.cpp','budget_seconds':2.0,'memory_mb':1024,
  'small_timeout_seconds':20.0,'independent_oracles':True,
  'independent_oracle_note':'Python exhaustive/scanning/DP oracle is algorithmically independent of C++ sparse-table/merge-sort-tree/tails/Li-Chao/stack/Kruskal/Hungarian/Mo implementation.',
  'mutation_name':title,'mutation_specification':spec,'proof_sketch':proof,
  'baseline_policy':'Keep public source-original statement unchanged. The weak/strong scale cohorts are separately labelled and change only N/Q/M caps. Strong cases remain within original constraints.',
  'verification_status':'pending_harness','family_id':id,
 }


L2_DESIGNS={
 'staticrmq':({'N':64,'Q':64},{'N':120000,'Q':120000},'O(NQ)','O(N log N + Q)'),
 'range_kth_smallest':({'N':64,'Q':64},{'N':120000,'Q':120000},'O(Q N log N)','O(N log N + Q log^2 N log |values|)'),
 'longest_increasing_subsequence':({'N':100},{'N':150000},'O(N^2)','O(N log N)'),
 'line_add_get_min':({'N':64,'Q':64},{'N':100000,'Q':100000},'O(Q(N+Q))','O((N+Q) log Q)'),
 'segment_add_get_min':({'N':64,'Q':64},{'N':100000,'Q':100000},'O(Q(N+Q))','O((N+Q) log^2 Q)'),
 'cartesian_tree':({'N':100},{'N':150000},'O(N^2) worst-case on monotone input','O(N)'),
 'minimum_spanning_tree':({'N':6,'M':9},{'N':60000,'M':119999},'O(N^2+M)','O(M log M)'),
 'assignment':({'N':7},{'N':160},'O(N! N)','O(N^3)'),
 'static_range_frequency':({'N':64,'Q':64},{'N':120000,'Q':120000},'O(NQ)','O(N log N + Q log^2 N)'),
 'static_range_inversions_query':({'N':64,'Q':64},{'N':12000,'Q':12000},'O(Q N^2)','O((N+Q) sqrt(N) log N)'),
}
for id,(weak,strong,slow,fast) in L2_DESIGNS.items():
 RECIPES[id]['l2_design']={'weak_caps':weak,'strong_caps':strong,'slow_complexity':slow,'fast_complexity':fast,'fixed_budget_seconds':2.0,'preserved':'mathematical relation, I/O schema, value range, non-size constraints','timing_evidence':'curation/library_batch_timing_pilot.json; final validation report supersedes pilot','original_source_preserved':True}

def _array_input(a,queries):return f'{len(a)} {len(queries)}\n'+ ' '.join(map(str,a))+'\n'+''.join(' '.join(map(str,q))+'\n' for q in queries)
def _one_array(a):return f'{len(a)}\n'+' '.join(map(str,a))+'\n'
def _matrix(a):return str(len(a))+'\n'+''.join(' '.join(map(str,r))+'\n' for r in a)
def _graph(n,e):return f'{n} {len(e)}\n'+''.join(' '.join(map(str,x))+'\n' for x in e)
def _lines(ls,qs):return f'{len(ls)} {len(qs)}\n'+''.join(' '.join(map(str,x))+'\n' for x in ls+qs)

BOUNDARY={
 'staticrmq':[_array_input([0,10**9,4],[(0,3),(1,2),(0,1)]),_array_input([7],[(0,1)])],
 'range_kth_smallest':[_array_input([0,10**9,0,5],[(0,4,0),(0,4,3),(0,4,1),(1,2,0)])],
 'longest_increasing_subsequence':[_one_array([2,2]),_one_array([0,10**9,0,10**9]),_one_array([1])],
 'line_add_get_min':[_lines([(0,2),(0,7)],[(1,0),(0,-10**9,10**18),(1,10**9),(1,-10**9)])],
 'segment_add_get_min':[_lines([(-2,2,0,2),(-1,1,0,7)],[(1,0),(1,2),(1,-2),(0,-10**9,10**9,-10**9,10**18),(1,-10**9),(1,10**9)])],
 'cartesian_tree':[_one_array([0,10**9]),_one_array([5]),_one_array([2,1,3,0])],
 'minimum_spanning_tree':[_graph(3,[(0,1,1),(1,2,2),(0,2,7)]),_graph(1,[]),_graph(2,[(0,0,10**9),(0,1,0),(0,1,10**9)])],
 'assignment':[_matrix([[1,4],[3,0]]),_matrix([[-10**9]]),_matrix([[10**9,-10**9],[-10**9,10**9]])],
 'static_range_frequency':[_array_input([0,2,2,9],[(0,4,2),(0,4,0),(1,1,2),(0,4,10**9)]),_array_input([],[])],
 'static_range_inversions_query':[_array_input([2,2,1],[(0,3),(0,2),(1,2)]),_array_input([0,10**9,0],[(0,3)])],
}

def cases(id,mode,rng):
 if mode=='boundary':
  for i,s in enumerate(BOUNDARY[id]):yield f'boundary_{i:02d}',s
  return
 if mode=='small':
  repetitions=32
 elif mode=='weak':repetitions=2
 elif mode=='stress':repetitions=2
 else:raise ValueError(mode)
 for trial in range(repetitions):
  stress=mode=='stress'
  if id=='assignment':
   n=160 if stress else (7 if mode=='weak' else rng.randint(1,7))
   a=[[rng.randint(-1000,1000) for _ in range(n)]for _ in range(n)]
   text=_matrix(a)
  elif id=='minimum_spanning_tree':
   n=60000 if stress else (6 if mode=='weak' else rng.randint(1,6))
   e=[(i,rng.randrange(i),rng.randint(0,10**9 if stress else 20))for i in range(1,n)]
   extra=n if stress else rng.randint(0,4)
   e +=[(rng.randrange(n),rng.randrange(n),rng.randint(0,10**9 if stress else 20))for _ in range(extra)]
   text=_graph(n,e)
  elif id in ('longest_increasing_subsequence','cartesian_tree'):
   n=150000 if stress else (100 if mode=='weak' else rng.randint(1,30))
   if id=='cartesian_tree':a=list(range(n));a=a if stress else rng.sample(range(10*n),n)
   elif stress:a=[i//2 for i in range(n)]
   else:a=[rng.randrange(8)for _ in range(n)]
   text=_one_array(a)
  elif id in ('line_add_get_min','segment_add_get_min'):
   n=q=100000 if stress else (64 if mode=='weak' else rng.randint(1,16))
   def makeline():
    a,b=rng.randint(-100,100),rng.randint(-10**6,10**6)
    if id=='line_add_get_min':return (a,b)
    if stress:return (-10**9,10**9,a,b)
    l=rng.randint(-20,19);r=rng.randint(l+1,20);return (l,r,a,b)
   ls=[makeline()for _ in range(n)]
   qs=[(1,rng.randint(-10**8,10**8) if stress else rng.randint(-22,22)) if j%3 else (0,)+makeline() for j in range(q)]
   text=_lines(ls,qs)
  else:
   n=q=(12000 if id=='static_range_inversions_query' else 120000) if stress else (64 if mode=='weak' else rng.randint(1,24))
   a=[rng.randrange(10**9 if stress else 7)for _ in range(n)]
   qs=[]
   for j in range(q):
    l=rng.randrange(max(1,n//8)) if stress else rng.randrange(n)
    r=rng.randint(max(l+1,7*n//8),n) if stress else rng.randint(l+1,n)
    if id=='range_kth_smallest':qs.append((l,r,rng.randrange(r-l)))
    elif id=='static_range_frequency':qs.append((l,r,rng.choice(a) if j%2 else rng.randrange(10**9 if stress else 7)))
    else:qs.append((l,r))
   text=_array_input(a,qs)
  yield f'{mode}_{trial:02d}',text

def validate_input(id,input_text,condition):
 try:
  x=list(map(int,input_text.split()));i=0
  def read():
   nonlocal i
   v=x[i];i+=1;return v
  n=read()
  if id in ('longest_increasing_subsequence','cartesian_tree'):
   assert 1<=n<=(1000000 if id=='cartesian_tree' else 500000)
   a=[read()for _ in range(n)];assert all(0<=v<=10**9 for v in a)
   if id=='cartesian_tree':assert len(set(a))==n
  elif id=='assignment':
   assert 1<=n<=500
   for _ in range(n*n):assert abs(read())<=10**9
  elif id=='minimum_spanning_tree':
   m=read();assert 1<=n<=500000 and n-1<=m<=500000
   p=list(range(n))
   def find(a):
    while p[a]!=a:p[a]=p[p[a]];a=p[a]
    return a
   for _ in range(m):
    u,v,w=read(),read(),read();assert 0<=u<n and 0<=v<n and 0<=w<=10**9;p[find(u)]=find(v)
   assert len({find(a)for a in range(n)})==1
  elif id in ('line_add_get_min','segment_add_get_min'):
   q=read();assert 1<=n<=200000 and 1<=q<=200000
   def ln():
    if id=='segment_add_get_min':
     l,r=read(),read();assert -10**9<=l<r<=10**9
    a,b=read(),read();assert abs(a)<=10**9 and abs(b)<=10**18
   for _ in range(n):ln()
   for _ in range(q):
    t=read();assert t in (0,1)
    if t==0:ln()
    else:assert abs(read())<=10**9
  else:
   q=read();cap={'staticrmq':500000,'range_kth_smallest':200000,'static_range_frequency':500000,'static_range_inversions_query':100000}[id]
   lo=0 if id=='static_range_frequency' else 1
   assert lo<=n<=cap and lo<=q<=cap
   for _ in range(n):assert 0<=read()<=10**9
   for _ in range(q):
    l,r=read(),read();assert 0<=l<=r<=n
    if id!='static_range_frequency':assert l<r
    if id=='range_kth_smallest':assert 0<=read()<r-l
    elif id=='static_range_frequency':assert 0<=read()<=10**9
  return i==len(x)
 except (AssertionError,ValueError,IndexError):return False

def check_output(id,input_text,candidate_text,oracle_text,condition):
 try:
  c=list(map(int,candidate_text.split()));o=list(map(int,oracle_text.split()))
 except ValueError:
  return candidate_text.split()==oracle_text.split()
 mut=condition=='l3';x=list(map(int,input_text.split()));n=x[0]
 if id=='longest_increasing_subsequence':
  if not c or not o or c[0]!=o[0] or len(c)!=c[0]+1:return False
  inds=c[1:];a=x[1:]
  return all(0<=i<n for i in inds) and all(inds[j]<inds[j+1] and (a[inds[j]]<=a[inds[j+1]] if mut else a[inds[j]]<a[inds[j+1]])for j in range(len(inds)-1))
 if id=='assignment':
  if not c or not o or len(c)!=n+1 or c[0]!=o[0] or sorted(c[1:])!=list(range(n)):return False
  a=x[1:];return sum(a[i*n+c[i+1]]for i in range(n))==c[0]
 if id=='minimum_spanning_tree':
  if not c or not o or len(c)!=n or c[0]!=o[0] or len(set(c[1:]))!=n-1:return False
  m=x[1];e=[x[j:j+3]for j in range(2,len(x),3)];p=list(range(n))
  def find(a):
   while p[a]!=a:p[a]=p[p[a]];a=p[a]
   return a
  cost=0
  for j in c[1:]:
   if not 0<=j<m:return False
   u,v,w=e[j];u,v=find(u),find(v)
   if u==v:return False
   p[u]=v;cost+=w
  return cost==c[0] and len({find(a)for a in range(n)})==1
 return c==o

def distinguishes(id,input_text,raw_output,l3_output):
 # A different valid witness with the same optimum is not a semantic distinction.
 return not check_output(id,input_text,raw_output,l3_output,'l3')
