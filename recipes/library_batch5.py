"""Ten tree/graph originals with explicit semantic operators and exact small oracles."""
from pathlib import Path
import hashlib,collections,itertools
IDS='lca jump_on_tree tree_diameter rooted_tree_isomorphism_classification vertex_set_path_composite maximum_independent_set chromatic_number counting_spanning_tree_undirected counting_spanning_tree_directed directedmst'.split()
ROOT=Path(__file__).resolve().parents[1];ASSET=ROOT/'assets/library_batch5';SRC=ROOT/'sources/library-checker-problems-master';P=998244353
SPEC={
'lca':('root0 → rootN-1','Treat supplied parent pairs as undirected edges and answer LCA after rooting the same tree at vertex N-1.','Iterative tree traversal reorients parents before binary lifting; independent oracle compares root-to-vertex BFS paths.'),
'jump_on_tree':('rank from source → rank from target','Return the ith vertex counted from t toward s on the unique path; i beyond path length still returns-1.','Binary lifting selects by distances to the LCA after reversing the path orientation; path traversal oracle constructs the whole target-to-source path.'),
'tree_diameter':('additive path length → bottleneck path length','Maximize the largest edge weight on a simple path; singleton paths have score0. Output this score and a realizing simple path in the original schema.','The best bottleneck equals the maximum edge weight and that edge alone is a valid realizing path. This simplifies the changed task; no claim of equal difficulty is made.'),
'rooted_tree_isomorphism_classification':('unordered → ordered subtree isomorphism','At every vertex order children by increasing original vertex index. Classify rooted subtrees as ordered rooted trees, preserving child sequence in isomorphisms.','Bottom-up interning uses the vector of child class ids without sorting. Raw sorts this vector. Nested-tuple oracle constructs exact ordered/unordered shapes independently.'),
'vertex_set_path_composite':('forward → reverse composition order','For each path query apply vertex functions in order v to u, preserving assignments and arithmetic modulo998244353.','HLD stores forward and reverse compositions; reversing the path combines exactly the opposite noncommutative function sequence. Literal BFS-path oracle directly evaluates functions.'),
'maximum_independent_set':('nonadjacent → pairwise adjacent','Find a maximum clique instead of a maximum independent set, returning its size and vertex indices.','The source branch-and-bound maximum-clique engine receives original adjacency instead of its complement; independent exhaustive subsets test every required edge.'),
'chromatic_number':('chromatic number → clique number','Return the largest number of pairwise adjacent vertices instead of minimum number of colors.','A subset is a clique iff removing one vertex leaves a clique and the removed vertex is adjacent to every remaining vertex. Raw DSATUR searches colorings exactly, independently checked by canonical set partitions.'),
'counting_spanning_tree_undirected':('spanning trees → rooted spanning forests','Count pairs consisting of a spanning forest and one chosen root per component, modulo998244353. Parallel edge instances are distinct choices; self-loops cannot enter a forest.','The matrix-forest theorem gives det(I+L). Each forest contributes the product of its component sizes, which the independent edge-subset oracle computes explicitly.'),
'counting_spanning_tree_directed':('root reaches all → all reach root','Count directed spanning in-arborescences toward r: every vertex can reach r; preserve edge multiplicity and modulus.','Reverse every arc in the directed Laplacian construction and use the same root-deleted determinant. Edge-subset oracle checks underlying tree and original outdegrees.'),
'directedmst':('minimum → maximum arborescence cost','Find a maximum-weight directed spanning arborescence rooted at S, retaining parent witnesses and original nonnegative input weights.','Negating edge costs before the optimization yields a maximum-weight witness; recomputing/sign-correcting its cost returns the original-weight total. This changes optimization choices, not merely the displayed old answer.')}
RECIPES={}
for task,id in enumerate(IDS,1):
 provenance=None
 for kind,mut,slow in [('raw',0,0),('l3',1,0),('slow',0,1)]:
  if task in [6,10]and kind!='slow':
   origin=next(SRC.rglob(id+'/sol/correct.cpp'));text=origin.read_text();patches=[]
   if mut and task==6:
    text=text.replace('VV<int> graph(n, V<int>(n, 1));','VV<int> graph(n, V<int>(n, 0));').replace('graph[a][b] = graph[b][a] = 0;','graph[a][b] = graph[b][a] = 1;');patches=['Initialize absent adjacency to0 instead of1; set supplied undirected edges to1 instead of0.']
   if mut and task==10:
    text=text.replace('g[a].push_back({a, b, c});','g[a].push_back({a, b, -c});').replace('printf("%lld\\n", res.cost);','printf("%lld\\n", -res.cost);');patches=['Negate input weights before arborescence optimization; report selected tree cost in original weights.']
   provenance={'file':str(origin.relative_to(ROOT)),'sha256':hashlib.sha256(origin.read_bytes()).hexdigest(),'raw_copied_without_edits':True,'l3_changes':patches}if mut else provenance
  else:text=f'#define TASK {task}\n#define MUTANT {mut}\n#define SLOW {slow}\n#include "solver.cpp"\n'
  p=ASSET/f'{id}_{kind}.cpp'
  if not p.exists()or p.read_text()!=text:p.write_text(text)
 name,spec,proof=SPEC[id]
 RECIPES[id]={'source':'library-checker','source_id':id,'source_url':f'https://judge.yosupo.jp/problem/{id}','raw_fast':f'../assets/library_batch5/{id}_raw.cpp','l3_fast':f'../assets/library_batch5/{id}_l3.cpp','slow_baseline':f'../assets/library_batch5/{id}_slow.cpp','raw_oracle':{'path':'../assets/library_batch5/oracle.py','args':[id,'raw']},'l3_oracle':{'path':'../assets/library_batch5/oracle.py','args':[id,'l3']},'budget_seconds':2.0,'memory_mb':1024,'small_timeout_seconds':30.0,'independent_oracles':True,'independent_oracle_note':'BFS literal paths, exact nested shapes, exhaustive vertex/edge subsets, canonical partitions, and incoming-edge Cartesian products. Independent from binary lifting/HLD, interning, branch-and-bound, DSATUR, and determinants.','mutation_name':name,'mutation_specification':spec,'proof_sketch':proof,'family_id':id,'verification_status':'pending_harness','baseline_policy':'Retain original source; weak/strong variants change only size bounds.'}
 if provenance:RECIPES[id]['raw_reference_provenance']=provenance
for id in ['maximum_independent_set','chromatic_number']:RECIPES[id].update(semantic_collision_group='standard_clique_independent_coloring',novel_semantics_claim=False,split_group='standard_clique_independent_coloring')
for id in ['counting_spanning_tree_undirected','counting_spanning_tree_directed']:RECIPES[id]['split_group']='matrix_tree_and_forest'

def fmt(head,rows):return ' '.join(map(str,head))+'\n'+''.join(' '.join(map(str,r))+'\n'for r in rows)
def arr(a):return fmt([len(a)+1],[a])
BOUNDARY={
'lca':[fmt([3,3],[[0,1],[0,1],[1,2],[0,2]]),fmt([2,1],[[0],[0,1]])],
'jump_on_tree':[fmt([3,4],[(0,1),(1,2),(0,2,0),(0,2,2),(1,1,1),(2,0,1)])],
'tree_diameter':[fmt([3],[(0,1,4),(1,2,7)]),fmt([1],[])],
'rooted_tree_isomorphism_classification':[arr([0,0,1,1,4,2,6,2]),arr([])],
'vertex_set_path_composite':[fmt([2,3],[(2,1),(3,4),(0,1),(1,0,1,5),(0,1,1,9),(1,0,1,7)])],
'maximum_independent_set':[fmt([3,3],[(0,1),(0,2),(1,2)]),fmt([1,0],[])],
'chromatic_number':[fmt([5,5],[(0,1),(1,2),(2,3),(3,4),(4,0)]),fmt([1,0],[])],
'counting_spanning_tree_undirected':[fmt([2,1],[(0,1)]),fmt([1,2],[(0,0),(0,0)]),fmt([3,3],[(0,1),(0,1),(2,2)])],
'counting_spanning_tree_directed':[fmt([2,1,0],[(0,1)]),fmt([1,2,0],[(0,0),(0,0)]),fmt([2,3,1],[(0,1),(0,1),(1,0)])],
'directedmst':[fmt([3,4,0],[(0,1,1),(0,2,5),(1,2,2),(2,1,9)]),fmt([1,0,0],[])]}
def cases(id,mode,rng):
 if mode=='boundary':
  for j,s in enumerate(BOUNDARY[id]):yield f'boundary_{j}',s
  return
 for trial in range(32 if mode=='small'else 2):
  st=mode=='stress';weak=mode=='weak'
  if id in ['lca','jump_on_tree','vertex_set_path_composite']:
   n=q=100000 if st else(32 if weak else rng.randint(2,12));parents=[v-1 if st else rng.randrange(v)for v in range(1,n)];es=[(v,p)for v,p in enumerate(parents,1)];rows=[parents]if id=='lca'else es
   if id=='vertex_set_path_composite':rows=[(rng.randrange(1,P),rng.randrange(P))for _ in range(n)]+rows
   for _ in range(q):
    a,b=(rng.randrange(n//8+1),rng.randrange(7*n//8,n))if st else sorted(rng.sample(range(n),2))
    if id=='lca':row=(a,b)
    elif id=='jump_on_tree':row=(a,b,rng.randrange(n))
    else:row=(0,rng.randrange(n),rng.randrange(1,P),rng.randrange(P))if rng.randrange(4)==0 else(1,a,b,rng.randrange(P))
    rows.append(row)
   s=fmt([n,q],rows)
  elif id=='tree_diameter':
   n=100000 if st else(32 if weak else rng.randint(1,12));es=[(v,(v-1)//2 if st else rng.randrange(v),rng.randrange(1,10**9+1))for v in range(1,n)];s=fmt([n],es)
  elif id=='rooted_tree_isomorphism_classification':
   n=100000 if st else(32 if weak else rng.randint(1,18));s=arr([v-1 if st else rng.randrange(v)for v in range(1,n)])
  elif id in ['maximum_independent_set','chromatic_number']:
   n=(40 if id=='maximum_independent_set'else 20)if st else(10 if weak else rng.randint(1,9));es=[(a,b)for a in range(n)for b in range(a+1,n)if(st and id=='chromatic_number')or rng.randrange(2)];s=fmt([n,len(es)],es)
  elif id in ['counting_spanning_tree_undirected','counting_spanning_tree_directed']:
   n=120 if st else(6 if weak else rng.randint(1,6));m=600 if st else(10 if weak else rng.randrange(11));es=[(rng.randrange(n),rng.randrange(n))for _ in range(m)];s=fmt([n,m]+([rng.randrange(n)]if id.endswith('_directed')else[]),es)
  else:
   n=36 if st else(7 if weak else rng.randint(1,7));r=0;es=[(0,v,rng.randrange(10**9+1))for v in range(1,n)];seen={(a,b)for a,b,_ in es}
   for v in range(1,n):
    u=(v%n)+1 if st else rng.randrange(n)
    if u<n and u!=v and(u,v)not in seen:es.append((u,v,rng.randrange(10**9+1)));seen.add((u,v))
   s=fmt([n,len(es),r],es)
  yield f'{mode}_{trial}',s

def validate_input(id,text,condition):
 try:
  ts=list(map(int,text.split()));i=0
  def val(lo,hi):
   nonlocal i
   v=ts[i];i+=1;assert lo<=v<=hi;return v
  n=val(2 if id in ['lca','jump_on_tree']else 1,40 if id=='maximum_independent_set'else 20 if id=='chromatic_number'else 500 if id.startswith('counting_')else 200000 if id in ['directedmst','vertex_set_path_composite']else 500000)
  def edges(count,weighted=False,simple=False,tree=False,directed=False):
   seen=set();par=list(range(n));g=[[]for _ in range(n)]
   def f(x):
    while par[x]!=x:par[x]=par[par[x]];x=par[x]
    return x
   for _ in range(count):
    a,b=val(0,n-1),val(0,n-1)
    if weighted:val(1 if id=='tree_diameter'else 0,10**9)
    if simple:assert a!=b and(a,b)not in seen and(directed or(b,a)not in seen)
    seen.add((a,b));g[a].append(b)
    if tree:
     x,y=f(a),f(b);assert x!=y;par[x]=y
   return g
  if id=='lca':
   q=val(1,500000)
   for v in range(1,n):val(0,v-1)
   for _ in range(q):a=val(0,n-2);val(a+1,n-1)
  elif id=='rooted_tree_isomorphism_classification':
   for v in range(1,n):val(0,v-1)
  elif id in ['jump_on_tree','vertex_set_path_composite']:
   q=val(1,200000 if id=='vertex_set_path_composite'else 500000)
   if id=='vertex_set_path_composite':
    for _ in range(n):val(1,P-1);val(0,P-1)
   edges(n-1,tree=True)
   for _ in range(q):
    if id=='jump_on_tree':val(0,n-1);val(0,n-1);val(0,n-1)
    else:
     ty=val(0,1);val(0,n-1);val(0 if ty else 1,n-1 if ty else P-1);val(0,P-1)
  elif id=='tree_diameter':edges(n-1,weighted=True,tree=True)
  elif id in ['maximum_independent_set','chromatic_number']:edges(val(0,n*(n-1)//2),simple=True)
  elif id.startswith('counting_'):
   m=val(0,500000)
   if id.endswith('_directed'):val(0,n-1)
   edges(m)
  else:
   m,r=val(n-1,200000),val(0,n-1);g=edges(m,weighted=True,simple=True,directed=True);seen={r};todo=[r]
   for v in todo:
    for u in g[v]:
     if u not in seen:seen.add(u);todo.append(u)
   assert len(seen)==n
  return i==len(ts)
 except(ValueError,IndexError,AssertionError):return False

def check_output(id,text,candidate,oracle,condition):
 if id not in ['tree_diameter','rooted_tree_isomorphism_classification','maximum_independent_set','directedmst']:return candidate.split()==oracle.split()
 try:
  ts=list(map(int,text.split()));n=ts[0];c=list(map(int,candidate.split()));o=list(map(int,oracle.split()));mut=condition=='l3'
  if id=='rooted_tree_isomorphism_classification':
   assert len(c)==len(o)==n+1 and c[0]==o[0];forward={};backward={}
   for x,y in zip(c[1:],o[1:]):
    assert 0<=x<c[0]and forward.setdefault(x,y)==y and backward.setdefault(y,x)==x
   return len(forward)==c[0]
  if id=='maximum_independent_set':
   assert c[0]==o[0]and len(c)==c[0]+1 and len(set(c[1:]))==c[0]and all(0<=v<n for v in c[1:]);E={frozenset(e)for e in zip(ts[2::2],ts[3::2])};return all((frozenset((u,v))in E)==mut for u,v in itertools.combinations(c[1:],2))
  if id=='tree_diameter':
   assert len(c)==c[1]+2 and 1<=c[1]<=n and c[0]==o[0];p=c[2:];assert len(set(p))==len(p)and all(0<=v<n for v in p);W={frozenset((a,b)):w for a,b,w in zip(ts[1::3],ts[2::3],ts[3::3])};weights=[W[frozenset((a,b))]for a,b in zip(p,p[1:])];return c[0]==(max(weights,default=0)if mut else sum(weights))
  m,r=ts[1:3];assert len(c)==n+1 and c[0]==o[0];par=c[1:];assert par[r]==r and all(0<=v<n for v in par);W={(a,b):w for a,b,w in zip(ts[3::3],ts[4::3],ts[5::3])};assert sum(W[(par[v],v)]for v in range(n)if v!=r)==c[0]
  children=[[]for _ in range(n)]
  for v in range(n):
   if v!=r:children[par[v]].append(v)
  seen={r};q=[r]
  for v in q:
   for u in children[v]:
    if u in seen:return False
    seen.add(u);q.append(u)
  return len(seen)==n
 except(ValueError,IndexError,AssertionError,KeyError):return False

def distinguishes(id,text,raw,l3):return not check_output(id,text,raw,l3,'l3')
L2={
'lca':({'N':32,'Q':32},{'N':100000,'Q':100000},'O(NQ)','O((N+Q)log N)'),
'jump_on_tree':({'N':32,'Q':32},{'N':100000,'Q':100000},'O(NQ)','O((N+Q)log N)'),
'tree_diameter':({'N':32},{'N':100000},'O(N^2)','O(N)'),
'rooted_tree_isomorphism_classification':({'N':32},{'N':100000},'O(N^2)','O(N log N)'),
'vertex_set_path_composite':({'N':32,'Q':32},{'N':100000,'Q':100000},'O(NQ)','O((N+Q)log^2 N)'),
'maximum_independent_set':({'N':10},{'N':40},'O(N2^N)','branch-and-bound with coloring upper bounds'),
'chromatic_number':({'N':10},{'N':20},'labelled color backtracking, up to N! on complete graphs','exact DSATUR branch-and-bound; L3 O(2^N)'),
'counting_spanning_tree_undirected':({'N':6,'M':10},{'N':120,'M':600},'O(binomial(M,N-1)N)','O(N^3+M)'),
'counting_spanning_tree_directed':({'N':6,'M':10},{'N':120,'M':600},'O(binomial(M,N-1)N)','O(N^3+M)'),
'directedmst':({'N':7,'M':12},{'N':36,'M':69},'O(N^2 product(indegree(v)))','heap-based cycle contraction')}
for id,(weak,strong,slow,fast)in L2.items():RECIPES[id]['l2_design']={'weak_caps':weak,'strong_caps':strong,'slow_complexity':slow,'fast_complexity':fast,'fixed_budget_seconds':2.0,'original_source_preserved':True,'preserved':'objective, I/O schema, vertex/weight domain and structural constraints'}
