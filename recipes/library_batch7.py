"""Final ten dynamic-structure/graph originals. Small oracles are literal independent simulations."""
from pathlib import Path
import hashlib,collections
IDS='dynamic_tree_vertex_add_path_sum dynamic_tree_vertex_set_path_composite dynamic_sequence_range_affine_range_sum persistent_range_affine_range_sum range_chmin_chmax_add_range_sum point_set_range_sort_range_composite dynamic_graph_vertex_add_component_sum general_weighted_matching scc connected_components_of_complement_graph'.split()
ROOT=Path(__file__).resolve().parents[1];SRC=ROOT/'sources/library-checker-problems-master';P=998244353
SPEC={
'dynamic_tree_vertex_add_path_sum':('path sum → maximum vertex value','Keep valid edge replacement and nonnegative vertex additions; query maximum vertex value on the unique u-v path.','Top-tree compress aggregates maximum of both clusters and their shared vertex; query includes both endpoints. Independent BFS path oracle evaluates maximum.'),
'dynamic_tree_vertex_set_path_composite':('forward → reverse path composition','Keep edge replacement and function assignment; apply functions from v toward u for a query2 u v x.','The reversible link-cut monoid is queried in reversed path orientation; direct BFS path simulation evaluates the reversed function sequence.'),
'dynamic_sequence_range_affine_range_sum':('sum → second moment','Keep insertion, deletion, reversal and affine updates; query sum of squares of the current interval values modulo998244353.','Implicit treap stores count, sum and sumSquares. Under x→b*x+c the second moment is b²S2+2bcS1+c²count. Split/merge/reversal preserve aggregates.'),
'persistent_range_affine_range_sum':('sum → second moment','Keep persistent affine versions and range copying between versions; query sum of squares in the named version modulo998244353.','Augment the persistent segment monoid from(count,sum)to(count,sum,sumSquares), extending affine action by b²S2+2bcS1+c²count. Version-copy crossover preserves this monoid.'),
'range_chmin_chmax_add_range_sum':('sum → exact second moment','Keep range chmin, chmax and addition with original bound |a_i|<=10^12 after every operation; query exact integer sum of squares.','Segment-tree beats tracks sumSquares in signed128-bit. Changing the extreme group adjusts its count times the difference of squares; addition uses2b*sum+b²count. Maximum output N*10^24<=2*10^29 fits128-bit.'),
'point_set_range_sort_range_composite':('forward → reverse composition','Keep assignments and ascending/descending sorting by unique keys; query applies interval functions from right to left.','Use the opposite composition monoid inside the sortable segment tree; key ordering, inverses and updates are unchanged. Oracle sorts explicit triples then evaluates right-to-left.'),
'dynamic_graph_vertex_add_component_sum':('component sum → maximum vertex value','Keep graph edge insertion/deletion and nonnegative vertex additions; query maximum vertex value in the queried connected component.','Euler-tour forest monoid changes sum to maximum while vertex update remains arithmetic addition. Nonnegative values make0 a valid empty aggregate identity.'),
'general_weighted_matching':('maximum weight → minimum weight among maximum cardinality','First maximize number of matching edges; among those minimize total original weight. Return edge count, original weight sum and a matching.','For N<=500 and w<=10^6, transformed positive weights BIG-w with BIG=500000001 dominate any total-weight difference. Maximum transformed weight therefore gives lexicographic(max cardinality,min cost). Blossom uses64-bit weights and totals; checker verifies both objectives.'),
'scc':('strong → weak directed connectivity','Ignore directions and output weakly connected vertex components. Preserve component-list schema; components may be in any order because distinct weak components have no intercomponent arcs.','Union endpoints of each arc. Independent oracle uses undirected reachability; Raw independent oracle uses mutual directed reachability and topological component ordering.'),
'connected_components_of_complement_graph':('complement adjacency → original adjacency','Output connected components of the supplied simple undirected graph instead of its complement, preserving arbitrary-order component-list schema.','Union only supplied edges; complement structure is used only by Raw. Independent oracle explicitly constructs each target adjacency relation and explores components.')}
RECIPES={}
for task,id in enumerate(IDS,1):
 name,spec,proof=SPEC[id]
 RECIPES[id]={'source':'library-checker','source_id':id,'source_url':f'https://judge.yosupo.jp/problem/{id}','raw_fast':f'../assets/library_batch7/{id}_raw.cpp','l3_fast':f'../assets/library_batch7/{id}_l3.cpp','slow_baseline':f'../assets/library_batch7/{id}_slow.cpp','raw_oracle':{'path':'../assets/library_batch7/oracle.py','args':[id,'raw']},'l3_oracle':{'path':'../assets/library_batch7/oracle.py','args':[id,'l3']},'budget_seconds':2.0,'memory_mb':1024,'small_timeout_seconds':30.0,'independent_oracles':True,'independent_oracle_note':'Literal mutable arrays, copied persistent arrays, BFS paths/components, exact bitmask matching DP and directed reachability, independent of augmented dynamic trees, persistent monoids, beats, blossoms and Kosaraju.','mutation_name':name,'mutation_specification':spec,'proof_sketch':proof,'family_id':id,'verification_status':'pending_harness','baseline_policy':'Public source retained; weak/strong versions explicitly change only size caps.'}
 if task in [1,2,4,5,6,7,8,10]:
  p=next(SRC.rglob(id+'/sol/correct.cpp'));RECIPES[id]['raw_reference_provenance']={'file':str(p.relative_to(ROOT)),'sha256':hashlib.sha256(p.read_bytes()).hexdigest(),'copied_without_edits':True,'l3_changes':proof}
for id in ['dynamic_sequence_range_affine_range_sum','persistent_range_affine_range_sum','range_chmin_chmax_add_range_sum']:RECIPES[id]['split_group']='range_second_moment_mutations'
for id in ['scc','connected_components_of_complement_graph']:RECIPES[id].update(semantic_collision_group='standard_connectivity_relations',novel_semantics_claim=False,split_group='standard_connectivity_relations')
def fmt(head,rows):return ' '.join(map(str,head))+'\n'+''.join(' '.join(map(str,r))+'\n'for r in rows)
def arr(a,qs):return fmt([len(a),len(qs)],[a]+qs)
BOUNDARY={
'dynamic_tree_vertex_add_path_sum':[fmt([3,5],[(1,4,2),(0,1),(1,2),(2,0,2),(1,2,7),(2,1,2),(0,1,2,0,2),(2,1,2)])],
'dynamic_tree_vertex_set_path_composite':[fmt([3,4],[(2,1),(3,4),(1,5),(0,1),(1,2),(2,0,2,7),(0,1,2,0,2),(1,1,5,3),(2,1,2,1)])],
'dynamic_sequence_range_affine_range_sum':[arr([2,3],[(4,0,2),(0,1,4),(3,0,3,0,5),(2,0,3),(1,1),(4,0,2)])],
'persistent_range_affine_range_sum':[arr([2,3],[(2,-1,0,2),(0,-1,0,2,2,1),(1,-1,1,0,1),(2,2,0,2),(2,1,0,2)])],
'range_chmin_chmax_add_range_sum':[arr([-3,4],[(3,0,2),(0,0,2,2),(1,0,2,0),(2,0,2,5),(3,0,2)]),arr([10**12,-10**12],[(3,0,2)])],
'point_set_range_sort_range_composite':[fmt([3,6],[(9,2,1),(3,3,4),(7,1,5),(1,0,3,7),(2,0,3),(1,0,3,7),(3,0,3),(0,1,10,5,3),(1,0,3,2)])],
'dynamic_graph_vertex_add_component_sum':[arr([1,4,2],[(0,0,1),(0,1,2),(3,0),(1,1,2),(2,0,7),(3,1),(3,2)])],
'general_weighted_matching':[fmt([4,3],[(0,1,100),(0,2,1),(1,3,1)]),fmt([3,0],[])],
'scc':[fmt([3,2],[(0,1),(1,2)]),fmt([1,1],[(0,0)])],
'connected_components_of_complement_graph':[fmt([3,2],[(0,1),(1,2)]),fmt([1,0],[])]}
def component(g,start):
 seen={start};todo=[start]
 for u in todo:
  for v in g[u]:
   if v not in seen:seen.add(v);todo.append(v)
 return seen

def cases(id,mode,rng):
 if mode=='boundary':
  for j,s in enumerate(BOUNDARY[id]):yield f'boundary_{j}',s
  return
 for trial in range(32 if mode=='small'else 2):
  st=mode=='stress';weak=mode=='weak'
  if id.startswith('dynamic_tree_'):
   n=q=60000 if st else(20 if weak else rng.randint(2,10));comp=id.endswith('composite');vals=[(rng.randrange(1,P),rng.randrange(P))for _ in range(n)]if comp else[[rng.randrange(10**9+1)for _ in range(n)]];es=[(v,v-1 if st else rng.randrange(v))for v in range(1,n)];g=[set()for _ in range(n)]
   for u,v in es:g[u].add(v);g[v].add(u)
   qs=[]
   for j in range(q):
    ty=2 if st and j%4 else 1 if st else rng.randrange(3)
    if ty==0:
     u,v=rng.choice(es);g[u].remove(v);g[v].remove(u);c=component(g,u);w=rng.choice(sorted(c));x=rng.choice(sorted(set(range(n))-c));g[w].add(x);g[x].add(w);es.remove((u,v));es.append((w,x));qs.append((0,u,v,w,x))
    elif ty==1:qs.append((1,rng.randrange(n),rng.randrange(1,P),rng.randrange(P))if comp else(1,rng.randrange(n),rng.randrange(10**9+1)))
    else:
     u,v=(0,n-1)if st else(rng.randrange(n),rng.randrange(n));qs.append((2,u,v,rng.randrange(P))if comp else(2,u,v))
   # The initial tree must precede the mutations, so reconstruct it independently from recorded cuts in reverse.
   for row in reversed(qs):
    if row[0]==0:_,u,v,w,x=row;es.remove((w,x));es.append((u,v))
   s=fmt([n,q],vals+es+qs)
  elif id=='dynamic_sequence_range_affine_range_sum':
   n=q=60000 if st else(24 if weak else rng.randint(1,12));a=[rng.randrange(P)for _ in range(n)];length=n;qs=[]
   for j in range(q):
    ty=(3 if j%4 else 4)if st else(0 if not length else rng.randrange(5))
    if ty==0:qs.append((0,rng.randrange(length+1),rng.randrange(P)));length+=1
    elif ty==1:qs.append((1,rng.randrange(length)));length-=1
    else:
     l=0 if st else rng.randrange(length);r=length if st else rng.randrange(l+1,length+1);qs.append((ty,l,r,rng.randrange(P),rng.randrange(P))if ty==3 else(ty,l,r))
   s=arr(a,qs)
  elif id=='persistent_range_affine_range_sum':
   n=q=50000 if st else(16 if weak else rng.randint(1,10));a=[rng.randrange(P)for _ in range(n)];vs=[-1];qs=[]
   for j in range(q):
    ty=(0 if j%2==0 else 2)if st else rng.randrange(3);l=0 if st else rng.randrange(n);r=n if st else rng.randrange(l+1,n+1);k=-1 if st and ty==0 else vs[-1]if st else rng.choice(vs)
    if ty==0:qs.append((0,k,l,r,rng.randrange(1,P),rng.randrange(P)));vs.append(j)
    elif ty==1:qs.append((1,k,rng.choice(vs),l,r));vs.append(j)
    else:qs.append((2,k,l,r))
   s=arr(a,qs)
  elif id=='range_chmin_chmax_add_range_sum':
   n=q=160000 if st else(24 if weak else rng.randint(1,14));a=[rng.randrange(-100,101)for _ in range(n)];qs=[]
   for j in range(q):
    l=0 if st else rng.randrange(n);r=n if st else rng.randrange(l+1,n+1);ty=rng.randrange(4);qs.append((ty,l,r)if ty==3 else(ty,l,r,rng.randrange(-100,101)))
   s=arr(a,qs)
  elif id=='point_set_range_sort_range_composite':
   n=q=40000 if st else(24 if weak else rng.randint(1,12));keys=list(range(n));rng.shuffle(keys);vals=[(key,rng.randrange(1,P),rng.randrange(P))for key in keys];qs=[];key=n
   for j in range(q):
    ty=1 if st and j%4 else 0 if st else rng.randrange(4);l=0 if st else rng.randrange(n);r=n if st else rng.randrange(l+1,n+1)
    if ty==0:qs.append((0,rng.randrange(n),key,rng.randrange(1,P),rng.randrange(P)));key+=1
    elif ty==1:qs.append((1,l,r,rng.randrange(P)))
    else:qs.append((ty,l,r))
   s=fmt([n,q],vals+qs)
  elif id=='dynamic_graph_vertex_add_component_sum':
   n=50000 if st else(20 if weak else rng.randint(1,10));q=150000 if st else(40 if weak else 30);a=[rng.randrange(10**9+1)for _ in range(n)];E=set();qs=[]
   for j in range(q):
    if st:
     if j<n-1:row=(0,j,j+1)
     elif j%4:row=(3,rng.randrange(n))
     else:row=(2,rng.randrange(n),rng.randrange(10**9+1))
    else:
     ty=rng.randrange(4)
     if ty==0 and len(E)<n*(n-1)//2:u,v=rng.choice([(u,v)for u in range(n)for v in range(u+1,n)if(u,v)not in E]);E.add((u,v));row=(0,u,v)
     elif ty==1 and E:u,v=rng.choice(sorted(E));E.remove((u,v));row=(1,u,v)
     elif ty==2:row=(2,rng.randrange(n),rng.randrange(10**9+1))
     else:row=(3,rng.randrange(n))
    qs.append(row)
   s=arr(a,qs)
  elif id=='general_weighted_matching':
   n=26 if st else(10 if weak else rng.randint(1,9));es=[(u,v,rng.randrange(1,10**6+1))for u in range(n)for v in range(u+1,n)if st or rng.randrange(2)];s=fmt([n,len(es)],es)
  elif id=='scc':
   n=4000 if st else(30 if weak else rng.randint(1,12));es=[(v,(v+1)%n)for v in range(n)]+[(rng.randrange(n),rng.randrange(n))for _ in range(n)]if st else[(rng.randrange(n),rng.randrange(n))for _ in range(rng.randrange(1,2*n+1))];s=fmt([n,len(es)],es)
  else:
   n=100000 if st else(30 if weak else rng.randint(1,12));es=[(v,v+1)for v in range(n-1)]if st else[(u,v)for u in range(n)for v in range(u+1,n)if rng.randrange(3)==0];s=fmt([n,len(es)],es)
  yield f'{mode}_{trial}',s

class BoundedBlocks:
 def __init__(self,a):
  self.B=1024;self.blocks=[a[i:i+self.B]for i in range(0,len(a),self.B)];self.lazy=[[0,-10**30,10**30]for _ in self.blocks];self.mm=[(min(b),max(b))for b in self.blocks]
 def apply(self,l,r,ty,x):
  for k,b in enumerate(self.blocks):
   left=k*self.B;right=left+len(b)
   if r<=left or right<=l:continue
   add,lo,hi=self.lazy[k];mn,mx=self.mm[k]
   if l<=left and right<=r:
    if ty==0:lo=min(lo,x);hi=min(hi,x);mn=min(mn,x);mx=min(mx,x)
    elif ty==1:lo=max(lo,x);hi=max(hi,x);mn=max(mn,x);mx=max(mx,x)
    else:add+=x;lo+=x;hi+=x;mn+=x;mx+=x
    self.lazy[k]=[add,lo,hi];self.mm[k]=(mn,mx)
   else:
    b[:]=[min(max(v+add,lo),hi)for v in b]
    for j in range(max(l,left)-left,min(r,right)-left):b[j]=min(b[j],x)if ty==0 else max(b[j],x)if ty==1 else b[j]+x
    self.lazy[k]=[0,-10**30,10**30];self.mm[k]=(min(b),max(b))
  return all(-10**12<=mn<=mx<=10**12 for mn,mx in self.mm)

def validate_input(id,text,condition):
 try:
  ts=list(map(int,text.split()));i=0
  def val(lo,hi):
   nonlocal i
   x=ts[i];i+=1;assert lo<=x<=hi;return x
  nmax=500 if id=='general_weighted_matching'else 100000 if id in ['persistent_range_affine_range_sum','point_set_range_sort_range_composite']else 200000 if id.startswith('dynamic_tree_')or id=='range_chmin_chmax_add_range_sum'else 300000 if id=='dynamic_graph_vertex_add_component_sum'else 500000;n=val(1,nmax)
  if id=='general_weighted_matching':
   m=val(0,n*(n-1)//2);E=set()
   for _ in range(m):u,v=val(0,n-1),val(0,n-1);val(1,10**6);e=tuple(sorted((u,v)));assert u!=v and e not in E;E.add(e)
  elif id in ['scc','connected_components_of_complement_graph']:
   m=val(1 if id=='scc'else 0,500000);E=set()
   for _ in range(m):
    u,v=val(0,n-1),val(0,n-1)
    if id!='scc':e=tuple(sorted((u,v)));assert u!=v and e not in E;E.add(e)
  else:
   q=val(1,nmax)
   if id.startswith('dynamic_tree_'):
    comp=id.endswith('composite')
    for _ in range(n):
     val(1 if comp else 0,P-1 if comp else 10**9)
     if comp:val(0,P-1)
    g=[set()for _ in range(n)];par=list(range(n))
    def f(v):
     while par[v]!=v:par[v]=par[par[v]];v=par[v]
     return v
    for _ in range(n-1):u,v=val(0,n-1),val(0,n-1);a,b=f(u),f(v);assert a!=b;par[a]=b;g[u].add(v);g[v].add(u)
    for _ in range(q):
     ty=val(0,2);u=val(0,n-1)
     if ty==0:v,w,x=val(0,n-1),val(0,n-1),val(0,n-1);assert v in g[u];g[u].remove(v);g[v].remove(u);assert x not in component(g,w);g[w].add(x);g[x].add(w)
     elif ty==1:
      val(1 if comp else 0,P-1 if comp else 10**9)
      if comp:val(0,P-1)
     else:
      val(0,n-1)
      if comp:val(0,P-1)
   elif id=='point_set_range_sort_range_composite':
    seen=set()
    for _ in range(n):p=val(0,10**9);assert p not in seen;seen.add(p);val(1,P-1);val(0,P-1)
    for _ in range(q):
     ty=val(0,3)
     if ty==0:val(0,n-1);p=val(0,10**9);assert p not in seen;seen.add(p);val(1,P-1);val(0,P-1)
     else:
      l=val(0,n-1);val(l+1,n)
      if ty==1:val(0,P-1)
   else:
    lo=-10**12 if id=='range_chmin_chmax_add_range_sum'else 0;hi=10**12 if id=='range_chmin_chmax_add_range_sum'else 10**9 if id=='dynamic_graph_vertex_add_component_sum'else P-1;a=[val(lo,hi)for _ in range(n)];length=n;vs={-1};E=set();blocks=BoundedBlocks(a)if id=='range_chmin_chmax_add_range_sum'else None
    for j in range(q):
     if id=='dynamic_sequence_range_affine_range_sum':
      ty=val(0,4)
      if ty==0:val(0,length);val(0,P-1);length+=1
      elif ty==1:val(0,length-1);length-=1
      else:
       l=val(0,length-1);val(l+1,length)
       if ty==3:val(0,P-1);val(0,P-1)
     elif id=='persistent_range_affine_range_sum':
      ty=val(0,2);k=val(-1,j-1);assert k in vs
      if ty==1:s=val(-1,j-1);assert s in vs
      l=val(0,n-1);val(l+1,n)
      if ty==0:val(1,P-1);val(0,P-1)
      if ty in [0,1]:vs.add(j)
     elif id=='range_chmin_chmax_add_range_sum':
      ty=val(0,3);l=val(0,n-1);r=val(l+1,n)
      if ty<3:x=val(-2*10**12,2*10**12);assert blocks.apply(l,r,ty,x)
     else:
      ty=val(0,3);u=val(0,n-1)
      if ty<2:
       v=val(0,n-1);e=tuple(sorted((u,v)));assert u!=v
       if ty==0:assert e not in E;E.add(e)
       else:assert e in E;E.remove(e)
      elif ty==2:val(0,10**9)
  return i==len(ts)
 except(ValueError,IndexError,AssertionError):return False

def check_output(id,text,candidate,oracle,condition):
 if id not in ['general_weighted_matching','scc','connected_components_of_complement_graph']:return candidate.split()==oracle.split()
 try:
  ts=list(map(int,text.split()));n,m=ts[:2];c=list(map(int,candidate.split()));o=list(map(int,oracle.split()))
  if id=='general_weighted_matching':
   k,cost=c[:2];assert k>=0 and len(c)==2+2*k and len(set(c[2:]))==2*k and all(0<=v<n for v in c[2:]);W={tuple(sorted((u,v))):w for u,v,w in zip(ts[2::3],ts[3::3],ts[4::3])};assert sum(W[tuple(sorted((u,v)))]for u,v in zip(c[2::2],c[3::2]))==cost;return cost==o[1]and(condition!='l3'or k==o[0])
  def parse(out):
   cnt=out[0];assert 1<=cnt<=n;labels=[-1]*n;pos=1
   for j in range(cnt):
    k=out[pos];pos+=1;assert 1<=k<=n
    for v in out[pos:pos+k]:assert 0<=v<n and labels[v]<0;labels[v]=j
    pos+=k
   assert pos==len(out)and all(x>=0 for x in labels);return labels
  a,b=parse(c),parse(o);forward={};back={}
  for x,y in zip(a,b):assert forward.setdefault(x,y)==y and back.setdefault(y,x)==x
  if id=='scc'and condition!='l3':assert all(a[u]<=a[v]for u,v in zip(ts[2::2],ts[3::2]))
  return True
 except(ValueError,IndexError,AssertionError,KeyError):return False

def distinguishes(id,text,raw,l3):return not check_output(id,text,raw,l3,'l3')
L2={
'dynamic_tree_vertex_add_path_sum':({'N':20,'Q':20},{'N':60000,'Q':60000},'O(NQ)','amortized O((N+Q)log N)'),
'dynamic_tree_vertex_set_path_composite':({'N':20,'Q':20},{'N':60000,'Q':60000},'O(NQ)','amortized O((N+Q)log N)'),
'dynamic_sequence_range_affine_range_sum':({'N':24,'Q':24},{'N':60000,'Q':60000},'O(NQ)','expected O((N+Q)log(N+Q))'),
'persistent_range_affine_range_sum':({'N':16,'Q':16},{'N':50000,'Q':50000},'O(NQ²) worst-case point-version traversal','O((N+Q)log N) nodes/time per operation logarithmic'),
'range_chmin_chmax_add_range_sum':({'N':24,'Q':24},{'N':160000,'Q':160000},'O(NQ)','segment tree beats amortized bound'),
'point_set_range_sort_range_composite':({'N':24,'Q':24},{'N':40000,'Q':40000},'O(NQ log N)','source sortable segment tree'),
'dynamic_graph_vertex_add_component_sum':({'N':20,'Q':40},{'N':50000,'Q':150000},'O(Q(N+M))','source multilevel dynamic connectivity with Euler-tour trees'),
'general_weighted_matching':({'N':10,'M':45},{'N':26,'M':325},'exhaustive matchings (superexponential)','O(NM log N) blossom'),
'scc':({'N':30,'M':60},{'N':4000,'M':8000},'O(N³)','O(N+M)'),
'connected_components_of_complement_graph':({'N':30,'M':435},{'N':100000,'M':99999},'O(N² alpha(N))','O(N+M)')}
for id,(weak,strong,slow,fast)in L2.items():RECIPES[id]['l2_design']={'weak_caps':weak,'strong_caps':strong,'slow_complexity':slow,'fast_complexity':fast,'fixed_budget_seconds':2.0,'original_source_preserved':True,'preserved':'objective, I/O schema, numeric domains and valid dynamic-operation prerequisites'}
