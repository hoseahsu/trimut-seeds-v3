"""Second batch: explicit original-source task contracts and meaningful L3 changes."""
from pathlib import Path
P=998244353
IDS='range_add_range_min set_xor_min point_set_range_composite range_set_range_composite queue_operate_all_composite deque_operate_all_composite point_add_range_sum vertex_add_path_sum vertex_add_subtree_sum range_reverse_range_sum range_affine_range_sum static_range_count_distinct ordered_set predecessor_problem associative_array majority_voting persistent_queue'.split()
SPEC={
'range_add_range_min':('range minimum → maximum','Keep range-add updates; queries return range maximum.','Addition distributes over min and max. A lazy tree can preserve the same update action while changing its aggregate.'),
'set_xor_min':('minimum XOR → maximum XOR','Return max(y XOR x) over current set; retain idempotent insert/delete.','A counted binary trie greedily prefers the opposite query bit for maximization, while preserving live-set membership.'),
'point_set_range_composite':('forward → reverse composition','Apply functions from r-1 down to l instead of l up to r-1; retain point replacements.','Maintain both composition orders; affine functions are associative but not commutative, giving distinguishing witnesses.'),
'range_set_range_composite':('forward → reverse composition','Reverse function application order in query only; retain range replacement by the same function.','A lazy replacement aggregate is the length-fold power of the function; maintain both orders for mixed ranges.'),
'queue_operate_all_composite':('forward → reverse composition','Apply queued functions back-to-front for query; keep enqueue-back/dequeue-front.','An implicit sequence tree tracks both affine composition orders with identity for an empty queue.'),
'deque_operate_all_composite':('forward → reverse composition','Apply functions back-to-front; retain all front/back insertions/deletions.','Both aggregate orders compose associatively in an implicit sequence tree; insertion/removal changes the same sequence.'),
'point_add_range_sum':('sum → maximum','Return maximum current value in the same nonempty range; retain point addition.','Point updates propagate the maximum monoid; nonnegative values fit signed 64-bit even after all additions.'),
'vertex_add_path_sum':('path sum → path maximum','Return maximum value on the same inclusive tree path; retain vertex addition.','Heavy-light intervals partition a path, and max combines their maxima. A singleton path keeps its vertex value.'),
'vertex_add_subtree_sum':('subtree sum → subtree maximum','Return maximum current vertex value in the same rooted subtree; retain vertex addition.','DFS order makes each rooted subtree contiguous; point additions and interval maximum require a segment tree.'),
'range_reverse_range_sum':('sum → nonnegative maximum','Return max({0} union queried values), with empty-range result 0; retain reversals and all empty inputs.','The original permits empty ranges. Explicit neutral 0 is valid for the unchanged nonnegative domain; lazy reversal preserves max while changing later subranges.'),
'range_affine_range_sum':('first moment → second moment','Return sum(a[i]^2) modulo 998244353 on the same range; retain affine updates.','Under a<-b*a+c, S2 becomes b^2*S2+2*b*c*S1+c^2*length; update using old S1, then S1<-b*S1+c*length.'),
'static_range_count_distinct':('distinct values → singleton values','Count distinct values whose frequency in the queried range is exactly one.','For fixed right endpoint, assign +1 at each value last occurrence and -1 at its second-last occurrence; interval sums count exactly singleton values.'),
'ordered_set':('ascending rank → descending rank','Change only type 2 to x-th largest, with one-based x and -1 for invalid rank; other operations unchanged.','A set of size m maps descending rank x to ascending zero-based index m-x; duplicates remain absent.'),
'predecessor_problem':('inclusive successor → strict successor','Change only type 3 from minimum key >=k to minimum key >k; all other operations unchanged.','The ordered-set upper_bound implements the new predicate, retaining -1 when absent.'),
'associative_array':('overwrite → accumulate','Change type 0 from a[k]=v to a[k]+=v, preserving reads and initial zeros.','Per-key accumulation is well-defined. Largest value is at most Q*10^18<=10^24; the mutant uses 128-bit integers and prints full decimal values.'),
'majority_voting':('majority → strict two-thirds majority','Return a value only if 3*frequency>2*range_length; retain -1 and point assignment.','Any >2/3 value is also the unique >1/2 majority candidate. Verify its frequency with dynamic ordered occurrence sets.'),
'persistent_queue':('FIFO deletion → LIFO deletion','Type 1 removes and prints the back element of the selected version instead of the front; retain versioned append.','Versions have unchanged lengths, so original nonempty guarantees remain valid. Tail ancestry represents versioned append and allows exact front/back retrieval.')}
RECIPES={}
ASSET=Path(__file__).resolve().parents[1]/'assets/library_batch2'
for task,id in enumerate(IDS,1):
 for kind,mut,slow in [('raw',0,0),('l3',1,0),('slow',0,1)]:
  path=ASSET/f'{id}_{kind}.cpp';content=f'#define TASK {task}\n#define MUTANT {mut}\n#define SLOW {slow}\n#include "solver.cpp"\n'
  if not path.exists()or path.read_text()!=content:path.write_text(content)
 name,spec,proof=SPEC[id]
 RECIPES[id]={'source':'library-checker','source_id':id,'source_url':f'https://judge.yosupo.jp/problem/{id}','raw_fast':f'../assets/library_batch2/{id}_raw.cpp','l3_fast':f'../assets/library_batch2/{id}_l3.cpp','slow_baseline':f'../assets/library_batch2/{id}_slow.cpp','raw_oracle':{'path':'../assets/library_batch2/oracle.py','args':[id,'raw']},'l3_oracle':{'path':'../assets/library_batch2/oracle.py','args':[id,'l3']},'independent_oracles':True,'independent_oracle_note':'Literal Python state simulation uses direct scanning, counters, BFS paths and full persistent list copies, independently of C++ optimized data structures.','budget_seconds':2.0,'memory_mb':1024,'small_timeout_seconds':20.0,'mutation_name':name,'mutation_specification':spec,'proof_sketch':proof,'family_id':id,'verification_status':'pending_harness','baseline_policy':'Public source is preserved verbatim. Weak and strong conditions are separately named scale cohorts; only size caps differ.'}
L2_DESIGNS={
'range_add_range_min':({'N':64,'Q':64},{'N':120000,'Q':120000},'O(NQ)','O((N+Q) log N)'),
'set_xor_min':({'Q':64},{'Q':240000},'O(Q^2)','O(30 Q)'),
'point_set_range_composite':({'N':64,'Q':64},{'N':120000,'Q':120000},'O(NQ)','O((N+Q) log N)'),
'range_set_range_composite':({'N':64,'Q':64},{'N':120000,'Q':120000},'O(NQ)','O(N+Q log^2 N)'),
'queue_operate_all_composite':({'Q':64},{'Q':120000},'O(Q^2)','O(Q log Q) expected'),
'deque_operate_all_composite':({'Q':64},{'Q':120000},'O(Q^2)','O(Q log Q) expected'),
'point_add_range_sum':({'N':64,'Q':64},{'N':250000,'Q':250000},'O(NQ)','O((N+Q) log N)'),
'vertex_add_path_sum':({'N':64,'Q':64},{'N':120000,'Q':120000},'O(NQ)','O(N+Q log^2 N)'),
'vertex_add_subtree_sum':({'N':64,'Q':64},{'N':120000,'Q':120000},'O(NQ)','O((N+Q) log N)'),
'range_reverse_range_sum':({'N':64,'Q':64},{'N':120000,'Q':120000},'O(NQ)','O((N+Q) log N) expected'),
'range_affine_range_sum':({'N':64,'Q':64},{'N':120000,'Q':120000},'O(NQ)','O((N+Q) log N)'),
'static_range_count_distinct':({'N':64,'Q':64},{'N':120000,'Q':120000},'O(NQ log N)','O((N+Q) log(N+Q))'),
'ordered_set':({'N':64,'Q':64},{'N':120000,'Q':120000},'O((N+Q)Q)','O((N+Q) log(N+Q))'),
'predecessor_problem':({'N':64,'Q':64},{'N':1000000,'Q':120000},'O(NQ)','O(N+Q log N)'),
'associative_array':({'Q':64},{'Q':240000},'O(Q^2)','O(Q log Q)'),
'majority_voting':({'N':64,'Q':64},{'N':120000,'Q':120000},'O(NQ log N)','O((N+Q) log N)'),
'persistent_queue':({'Q':64},{'Q':240000},'O(Q^2)','O(Q log Q)'),
}
for id,(weak,strong,slow,fast) in L2_DESIGNS.items():
 RECIPES[id]['l2_design']={'weak_caps':weak,'strong_caps':strong,'slow_complexity':slow,'fast_complexity':fast,'fixed_budget_seconds':2.0,'preserved':'mathematical relation, I/O schema, value range and non-size constraints','original_source_preserved':True}

def fmt(header,lines):return ' '.join(map(str,header))+'\n'+''.join(' '.join(map(str,row))+'\n'for row in lines)
def arr(a,qs):return fmt([len(a),len(qs)],[a]+qs)
def funcs(a,qs):return fmt([len(a),len(qs)],a+qs)
def seq(qs):return fmt([len(qs)],qs)
BOUNDARY={
'range_add_range_min':[arr([-10**9,10**9],[(1,0,2),(0,0,2,-10**9),(1,0,2)])],
'set_xor_min':[seq([(0,0),(0,(1<<30)-1),(2,0),(0,0),(1,7),(1,0),(2,0)])],
'point_set_range_composite':[funcs([(2,3),(5,7)],[(1,0,2,4),(0,0,1,0),(1,0,2,4)])],
'range_set_range_composite':[funcs([(2,3),(5,7)],[(1,0,2,4),(0,0,1,1,0),(1,0,2,4)])],
'queue_operate_all_composite':[seq([(2,9),(0,2,3),(0,5,7),(2,4),(1,),(2,4)])],
'deque_operate_all_composite':[seq([(4,9),(0,2,3),(1,5,7),(4,4),(2,),(4,4),(3,),(4,7)])],
'point_add_range_sum':[arr([2,7],[(1,0,2),(0,0,10**9),(1,0,2)])],
'vertex_add_path_sum':[fmt([3,4],[[2,7,1],(0,1),(1,2),(1,0,2),(0,1,10**9),(1,0,2),(1,1,1)])],
'vertex_add_subtree_sum':[fmt([3,4],[[2,7,1],[0,1],(1,0),(0,1,10**9),(1,0),(1,2)])],
'range_reverse_range_sum':[arr([2,7,1],[(1,0,3),(0,0,2),(1,0,2),(1,1,1)]),arr([],[(1,0,0),(0,0,0)])],
'range_affine_range_sum':[arr([2,7,P-1],[(1,0,3),(0,0,2,3,5),(1,0,3),(0,1,3,P-1,P-1),(1,0,3)])],
'static_range_count_distinct':[arr([2,2,7],[(0,3),(0,2),(1,1)]),arr([],[])],
'ordered_set':[fmt([2,6],[[2,7],(2,1),(2,2),(2,3),(3,2),(4,2),(5,2)]),fmt([0,2],[[],(2,1),(4,0)])],
'predecessor_problem':['8 5\n00100100\n3 2\n3 5\n4 2\n2 2\n3 7\n'],
'associative_array':[seq([(0,10**18,10**18),(0,10**18,10**18),(1,10**18),(1,0)])],
'majority_voting':[arr([2,2,7],[(1,0,3),(0,2,2),(1,0,3),(1,0,1)])],
'persistent_queue':[seq([(0,-1,2),(0,0,7),(1,1),(1,2),(0,0,5),(1,4),(1,1)])],
}

def cases(id,mode,rng):
 if mode=='boundary':
  for j,s in enumerate(BOUNDARY[id]):yield f'boundary_{j}',s
  return
 count=32 if mode=='small'else 2
 for case in range(count):
  stress=mode=='stress';n=q=(250000 if id=='point_add_range_sum'else 120000) if stress else (64 if mode=='weak'else rng.randint(1,20));vmax=10**9 if stress else 9
  if id=='set_xor_min':
   qs=[];s=set();q=240000 if stress else q
   for j in range(q):
    if stress:t=0 if j<q//2 else 2;x=j if t==0 else rng.randrange(1<<30)
    else:t=rng.randrange(3)if s else 0;x=rng.randrange(12)
    if t==0:s.add(x)
    elif t==1:s.discard(x)
    qs.append((t,x))
   text=seq(qs)
  elif id in ['queue_operate_all_composite','deque_operate_all_composite']:
   qs=[];length=0;isdeque=id.startswith('deque')
   for j in range(q):
    if stress:t=(1 if isdeque else 0)if j<q//2 else (4 if isdeque else 2)
    elif isdeque:t=rng.choice([0,1,4]+([2,3]if length else []))
    else:t=rng.choice([0,2]+([1]if length else []))
    if (isdeque and t in [0,1])or(not isdeque and t==0):qs.append((t,rng.randrange(1,P),rng.randrange(P)));length+=1
    elif (isdeque and t in [2,3])or(not isdeque and t==1):qs.append((t,));length-=1
    else:qs.append((t,rng.randrange(P)))
   text=seq(qs)
  elif id=='associative_array':
   qs=[];q=240000 if stress else q
   for j in range(q):
    if stress:t=0 if j<q//3 else 1;k=j if t==0 else rng.randrange(q//3)
    else:t=rng.randrange(2);k=rng.randrange(9)
    qs.append((0,k,rng.randrange(10**18+1))if t==0 else(1,k))
   text=seq(qs)
  elif id=='persistent_queue':
   qs=[];lens=[0];q=240000 if stress else q
   for j in range(q):
    if stress:t=0 if j<q//2 else 1;k=j-1 if t==0 else q//2-1
    else:k=rng.randrange(-1,j);t=rng.randrange(2)if lens[k+1]else 0
    lens.append(lens[k+1]+(1 if t==0 else -1));qs.append((t,k,rng.randrange(10**9+1))if t==0 else(t,k))
   text=seq(qs)
  elif id=='predecessor_problem':
   if stress:n=1000000;bits='0'*(n-1)+'1';qs=[(3,rng.randrange(10000))for _ in range(q)]
   else:bits=''.join(rng.choice('01')for _ in range(n));qs=[(rng.randrange(5),rng.randrange(n))for _ in range(q)]
   text=f'{n} {q}\n{bits}\n'+''.join(f'{t} {k}\n'for t,k in qs)
  elif id=='ordered_set':
   a=list(range(n))if stress else sorted(rng.sample(range(n*4),n));qs=[]
   for j in range(q):
    t=rng.randrange(2,6)if stress else rng.randrange(6);x=rng.randrange(1 if t==2 else 0,(n if stress else n*4)+1);qs.append((t,x))
   text=fmt([n,q],[a]+qs)
  elif id in ['point_set_range_composite','range_set_range_composite']:
   a=[(rng.randrange(1,P),rng.randrange(P))for _ in range(n)];qs=[]
   for j in range(q):
    l=rng.randrange(n//8+1)if stress else rng.randrange(n);r=rng.randrange(max(l+1,7*n//8),n+1)if stress else rng.randrange(l+1,n+1)
    if j%3==0:qs.append((0,l,rng.randrange(1,P),rng.randrange(P))if id.startswith('point_')else(0,l,r,rng.randrange(1,P),rng.randrange(P)))
    else:qs.append((1,l,r,rng.randrange(P)))
   text=funcs(a,qs)
  else:
   a=[rng.randrange(P if id=='range_affine_range_sum'else vmax+1)for _ in range(n)]
   if id=='majority_voting':a=[rng.randrange(4)for _ in range(n)]
   parents=[i-1 if stress else rng.randrange(i)for i in range(1,n)]
   qs=[]
   for j in range(q):
    l=rng.randrange(n//8+1)if stress else rng.randrange(n);r=rng.randrange(max(l+1,7*n//8),n+1)if stress else rng.randrange(l+1,n+1)
    if id=='static_range_count_distinct':qs.append((l,r));continue
    t=0 if j%3==0 else 1
    if id in ['point_add_range_sum','majority_voting']:qs.append((0,l,rng.randrange(vmax+1))if t==0 else(1,l,r))
    elif id=='vertex_add_path_sum':qs.append((0,l,rng.randrange(vmax+1))if t==0 else(1,l,r-1))
    elif id=='vertex_add_subtree_sum':qs.append((0,l,rng.randrange(vmax+1))if t==0 else(1,l))
    elif id=='range_add_range_min':qs.append((0,l,r,rng.randint(-vmax,vmax))if t==0 else(1,l,r))
    elif id=='range_affine_range_sum':qs.append((0,l,r,rng.randrange(1,P),rng.randrange(P))if t==0 else(1,l,r))
    else:qs.append((t,l,r))
   if id=='vertex_add_path_sum':text=fmt([n,q],[a]+[(parents[i-1],i)for i in range(1,n)]+qs)
   elif id=='vertex_add_subtree_sum':text=fmt([n,q],[a,parents]+qs)
   else:text=arr(a,qs)
  yield f'{mode}_{case:02d}',text

def validate_input(id,text,condition):
 try:
  tokens=text.split();i=0
  def get():
   nonlocal i
   v=int(tokens[i]);i+=1;return v
  def val(lo,hi):
   v=get();assert lo<=v<=hi;return v
  def pair(n,empty=False):
   l,r=get(),get();assert 0<=l<=r<=n and(empty or l<r);return l,r
  seqs={'set_xor_min','queue_operate_all_composite','deque_operate_all_composite','associative_array','persistent_queue'}
  if id in seqs:
   q=val(1,1000000 if id=='associative_array'else 500000);live=set();length=0;lens=[0]
   for j in range(q):
    t=get()
    if id=='set_xor_min':
     assert t in [0,1,2];x=val(0,(1<<30)-1)
     if t==0:live.add(x)
     elif t==1:live.discard(x)
     else:assert live
    elif id=='associative_array':
     assert t in [0,1];val(0,10**18)
     if t==0:val(0,10**18)
    elif id=='persistent_queue':
     assert t in [0,1];k=val(-1,j-1);sz=lens[k+1]
     if t==0:val(0,10**9);sz+=1
     else:assert sz>0;sz-=1
     lens.append(sz)
    else:
     dq=id.startswith('deque');assert 0<=t<=(4 if dq else 2)
     if(t in [0,1]if dq else t==0):val(1,P-1);val(0,P-1);length+=1
     elif(t in [2,3]if dq else t==1):assert length>0;length-=1
     else:val(0,P-1)
  else:
   empty=id in ['range_reverse_range_sum','static_range_count_distinct','ordered_set']
   cap=200000 if id=='range_reverse_range_sum'else(10000000 if id=='predecessor_problem'else 500000)
   n=val(0 if empty else 1,cap);q=val(0 if id in ['range_reverse_range_sum','static_range_count_distinct']else 1,1000000 if id=='predecessor_problem'else cap)
   if id=='predecessor_problem':
    bits=tokens[i];i+=1;assert len(bits)==n and set(bits)<=set('01')
   elif id in ['point_set_range_composite','range_set_range_composite']:
    for _ in range(n):val(1,P-1);val(0,P-1)
   else:
    a=[val(-10**9 if id=='range_add_range_min'else 0,P-1 if id=='range_affine_range_sum'else 10**9)for _ in range(n)]
    if id=='ordered_set':assert a==sorted(set(a))
   if id=='vertex_add_subtree_sum':
    for j in range(1,n):val(0,j-1)
   elif id=='vertex_add_path_sum':
    ds=list(range(n))
    def find(v):
     while ds[v]!=v:ds[v]=ds[ds[v]];v=ds[v]
     return v
    for _ in range(n-1):
     u,v=val(0,n-1),val(0,n-1);u,v=find(u),find(v);assert u!=v;ds[u]=v
   for _ in range(q):
    if id=='static_range_count_distinct':pair(n,True);continue
    t=get()
    if id=='ordered_set':assert 0<=t<=5;val(1 if t==2 else 0,10**9)
    elif id=='predecessor_problem':assert 0<=t<=4;val(0,n-1)
    elif id in ['vertex_add_path_sum','vertex_add_subtree_sum']:
     assert t in [0,1];val(0,n-1)
     if t==0:val(0,10**9)
     elif id=='vertex_add_path_sum':val(0,n-1)
    elif id in ['point_add_range_sum','majority_voting']:
     assert t in [0,1]
     if t==0:val(0,n-1);val(0,10**9)
     else:pair(n)
    elif id=='point_set_range_composite':
     assert t in [0,1]
     if t==0:val(0,n-1);val(1,P-1);val(0,P-1)
     else:pair(n);val(0,P-1)
    elif id=='range_set_range_composite':
     assert t in [0,1];pair(n)
     if t==0:val(1,P-1);val(0,P-1)
     else:val(0,P-1)
    else:
     assert t in [0,1];pair(n,id=='range_reverse_range_sum')
     if t==0 and id=='range_add_range_min':val(-10**9,10**9)
     elif t==0 and id=='range_affine_range_sum':val(1,P-1);val(0,P-1)
  return i==len(tokens)
 except(ValueError,IndexError,AssertionError):return False
