"""Third Library Checker batch. Source-standard semantic collisions are explicit."""
from pathlib import Path
P=998244353
IDS='bitwise_and_convolution bitwise_xor_convolution gcd_convolution lcm_convolution subset_convolution sum_of_floor_of_linear kth_root_integer rectangle_sum point_add_rectangle_sum rectangle_add_point_get number_of_substrings wildcard_pattern_matching lyndon_factorization'.split()
SPEC={
'bitwise_and_convolution':('AND → OR index relation','Use i OR j=k instead of i AND j=k, preserving modular coefficient aggregation.','Subset zeta multiplication and Mobius inversion yield OR convolution.'),
'bitwise_xor_convolution':('XOR → AND index relation','Use i AND j=k instead of i XOR j=k.','Superset zeta multiplication and Mobius inversion recover AND convolution.'),
'gcd_convolution':('GCD → LCM index relation','Use lcm(i,j)=k instead of gcd(i,j)=k, output k=1..N only. Pairs with lcm>N contribute to no output.','Divisor zeta multiplication and inversion enumerate precisely the truncated LCM relation.'),
'lcm_convolution':('LCM → GCD index relation','Use gcd(i,j)=k instead of lcm(i,j)=k, with i,j,k in1..N.','Multiple zeta multiplication and descending inversion recover GCD groups.'),
'subset_convolution':('disjoint union → unrestricted union','Remove the i AND j=0 predicate while retaining i OR j=k.','The new sum is OR convolution. Raw fast uses popcount-ranked zeta convolution; mutant uses unranked zeta convolution.'),
'sum_of_floor_of_linear':('floor → ceiling','Sum ceil((A*i+B)/M), over the unchanged 0<=i<N range.','For integer numerator and positive M, ceil(z/M)=floor((z+M-1)/M); Euclidean floor-sum reduction stays exact.'),
'kth_root_integer':('floor root → ceiling root','Return least integer r with r^K>=A instead of greatest r with r^K<=A.','Compute exact floor root with overflow-safe comparisons; increment iff its exact Kth power differs from A. This changes the extremal integer predicate, not formatting.'),
'rectangle_sum':('open → closed upper x boundary','Use l<=x<=r and d<=y<u for each rectangle query; preserve y boundary and weighted multiplicity.','Integer x coordinates allow prefix threshold r+1; coordinate-compressed2D Fenwick sums implement the changed predicate.'),
'point_add_rectangle_sum':('open → closed upper x boundary','Use l<=x<=r and d<=y<u in rectangle queries; all point insertions unchanged.','Precollect update coordinates, then use Fenwick-of-Fenwick for exact online weighted prefixes with the changed upper x threshold.'),
'rectangle_add_point_get':('open → closed upper x boundary','Each inserted rectangle contains l<=x<=r and d<=y<u; queries remain points.','Four signed corner updates use right-x event at r+1, preserving the y upper event at u and the time ordering of insertions.'),
'number_of_substrings':('all distinct → even-length distinct','Count distinct nonempty substrings of even length only.','Each suffix-automaton state represents one distinct substring of each length in(link.len,state.len]; count even lengths in that interval.'),
'wildcard_pattern_matching':('two-sided → pattern-only wildcard','Asterisk in pattern T matches any single character; asterisk in text S is literal and matches only a pattern asterisk.','Encode text-star as27 while pattern-star stays0. Sum s*t*(s-t)^2 is nonnegative and zero exactly for a match. Two NTT moduli have product exceeding the global bound, preventing modular false zeros.'),
'lyndon_factorization':('alphabet order reversal','Define Lyndon factorization under z<y<...<a, keeping original boundary-index output.','A bijective order-reversing character map converts the requested alphabet to standard order; Duval finds the new factor boundaries.')}
ASSET=Path(__file__).resolve().parents[1]/'assets/library_batch3';RECIPES={}
for task,id in enumerate(IDS,1):
 for kind,mut,slow in [('raw',0,0),('l3',1,0),('slow',0,1)]:
  path=ASSET/f'{id}_{kind}.cpp';text=f'#define TASK {task}\n#define MUTANT {mut}\n#define SLOW {slow}\n#include "solver.cpp"\n'
  if not path.exists()or path.read_text()!=text:path.write_text(text)
 name,spec,proof=SPEC[id]
 RECIPES[id]={'source':'library-checker','source_id':id,'source_url':f'https://judge.yosupo.jp/problem/{id}','raw_fast':f'../assets/library_batch3/{id}_raw.cpp','l3_fast':f'../assets/library_batch3/{id}_l3.cpp','slow_baseline':f'../assets/library_batch3/{id}_slow.cpp','raw_oracle':{'path':'../assets/library_batch3/oracle.py','args':[id,'raw']},'l3_oracle':{'path':'../assets/library_batch3/oracle.py','args':[id,'l3']},'budget_seconds':2.0,'memory_mb':1024,'small_timeout_seconds':20.0,'independent_oracles':True,'independent_oracle_note':'Exact direct enumeration / direct arithmetic / literal geometric filtering / substring set / naive string comparison; separate algorithm from transforms, Fenwick structures, SAM and Duval. Integer square roots use Python math.isqrt independent of C++ binary search.','mutation_name':name,'mutation_specification':spec,'proof_sketch':proof,'family_id':id,'verification_status':'pending_harness','baseline_policy':'Original public statement preserved; explicitly named weak and strong size cohorts, no target-model-result selection.'}
 if task<=5:RECIPES[id]['semantic_collision_group']='standard_set_convolutions'if task in [1,2,5]else'standard_divisor_convolutions';RECIPES[id]['novel_semantics_claim']=False;RECIPES[id]['split_policy']='Keep all members of this collision group in the same split. Do not treat this L3 as evidence of unseen semantics.'

def fmt(h,ls):return ' '.join(map(str,h))+'\n'+''.join(' '.join(map(str,row))+'\n'for row in ls)
def arrays(n,a,b):return fmt([n],[a,b])
BOUNDARY={
'bitwise_and_convolution':[arrays(1,[0,1],[0,1]),arrays(0,[P-1],[P-1])],
'bitwise_xor_convolution':[arrays(1,[0,1],[0,1]),arrays(0,[P-1],[P-1])],
'gcd_convolution':[arrays(3,[0,1,0],[0,0,1]),arrays(1,[P-1],[P-1])],
'lcm_convolution':[arrays(3,[0,1,0],[0,0,1]),arrays(1,[P-1],[P-1])],
'subset_convolution':[arrays(1,[0,1],[0,1]),arrays(0,[P-1],[P-1])],
'sum_of_floor_of_linear':[fmt([4],[(5,3,1,1),(3,1,0,0),(1,10**9,10**9-1,10**9-1),(100,10**9,10**9-1,0)])],
'kth_root_integer':[fmt([9],[(2,2),(4,2),(0,64),(1,64),(2**64-1,1),(2**64-1,2),(2**64-1,64),(10**12-1,3),(10**12,3)])],
'rectangle_sum':[fmt([3,3],[(2,1,7),(1,1,3),(2,2,11),(0,0,2,2),(0,0,1,2),(1,0,10**9,10**9)])],
'point_add_rectangle_sum':[fmt([1,4],[(2,1,7),(1,0,0,2,2),(0,1,1,3),(1,0,0,1,2),(1,0,0,2,2)])],
'rectangle_add_point_get':[fmt([1,4],[(0,0,2,2,7),(1,2,1),(1,2,2),(0,1,1,10**9,10**9,3),(1,10**9,1)])],
'number_of_substrings':['a\n','ababa\n','aaaa\n'],
'wildcard_pattern_matching':['*a\naa\n','a*b*\n*b\n','****\n**\n'],
'lyndon_factorization':['ab\n','ba\n','aaaa\n','ababa\n']}

def cases(id,mode,rng):
 if mode=='boundary':
  for i,s in enumerate(BOUNDARY[id]):yield f'boundary_{i}',s
  return
 reps=32 if mode=='small'else 2
 for trial in range(reps):
  st=mode=='stress'
  if id in IDS[:5]:
   bits=id not in ['gcd_convolution','lcm_convolution']
   if bits:n=17 if st else(5 if mode=='weak'else rng.randrange(0,5));m=1<<n
   else:n=160000 if st else(64 if mode=='weak'else rng.randint(1,20));m=n
   a=[rng.randrange(P)for _ in range(m)];b=[rng.randrange(P)for _ in range(m)];s=arrays(n,a,b)
  elif id=='sum_of_floor_of_linear':
   t=8;rows=[]
   for _ in range(t):
    n=10**9 if st else(500 if mode=='weak'else rng.randint(1,30));m=rng.randrange(1,10**9+1);rows.append((n,m,rng.randrange(m),rng.randrange(m)))
   s=fmt([t],rows)
  elif id=='kth_root_integer':
   t=500000 if st else 8
   rows=[(rng.randrange(10**8,2*10**8),2)for _ in range(t)]if st or mode=='weak'else[(rng.randrange(10000),rng.randrange(1,10))for _ in range(t)]
   s=fmt([t],rows)
  elif id in ['rectangle_sum','point_add_rectangle_sum','rectangle_add_point_get']:
   n=q=80000 if st else(64 if mode=='weak'else rng.randint(1,14));rect=id=='rectangle_add_point_get';lim=10**9 if st else 12
   def rec():
    l=rng.randrange(lim);r=rng.randrange(l+1,lim+1);d=rng.randrange(lim);u=rng.randrange(d+1,lim+1);return(l,d,r,u)
   def point():return(rng.randrange(lim+1),rng.randrange(lim+1),rng.randrange(10**9+1))
   rows=[rec()+(rng.randrange(10**9+1),)if rect else point()for _ in range(n)]
   for j in range(q):
    if id=='rectangle_sum':rows.append(rec())
    elif j%3==0:rows.append((0,)+rec()+(rng.randrange(10**9+1),)if rect else(0,)+point())
    else:rows.append((1,rng.randrange(lim+1),rng.randrange(lim+1))if rect else(1,)+rec())
   s=fmt([n,q],rows)
  elif id=='number_of_substrings':
   n=120000 if st else(64 if mode=='weak'else rng.randint(1,20));s=('a'*n if st else''.join(rng.choice('abcd')for _ in range(n)))+'\n'
  elif id=='lyndon_factorization':
   n=120000 if st else(64 if mode=='weak'else rng.randint(1,20));s=('a'*n if st else''.join(rng.choice('abcd')for _ in range(n)))+'\n'
  else:
   n=240000 if st else(64 if mode=='weak'else rng.randint(1,20));m=n//2 if st else rng.randint(1,n)
   s=('a'*n+'\n'+'a'*m+'\n')if st else(''.join(rng.choice('abc*')for _ in range(n))+'\n'+''.join(rng.choice('abc*')for _ in range(m))+'\n')
  yield f'{mode}_{trial}',s

def validate_input(id,text,condition):
 try:
  ts=text.split();i=0
  def val(lo,hi):
   nonlocal i
   v=int(ts[i]);i+=1;assert lo<=v<=hi;return v
  if id in IDS[:5]:
   bits=id not in ['gcd_convolution','lcm_convolution'];n=val(0 if bits else 1,20 if bits else 1000000);m=1<<n if bits else n
   for _ in range(2*m):val(0,P-1)
  elif id=='sum_of_floor_of_linear':
   t=val(1,100000)
   for _ in range(t):n=val(1,10**9);m=val(1,10**9);val(0,m-1);val(0,m-1)
  elif id=='kth_root_integer':
   t=val(1,500000)
   for _ in range(t):val(0,2**64-1);val(1,64)
  elif id in ['rectangle_sum','point_add_rectangle_sum','rectangle_add_point_get']:
   n=val(1,200000 if id=='rectangle_sum'else 100000);q=val(1,200000 if id=='rectangle_sum'else 100000)
   def rec():
    l,d,r,u=[val(0,10**9)for _ in range(4)];assert l<r and d<u
   def pt():val(0,10**9);val(0,10**9)
   for _ in range(n):
    rec()if id=='rectangle_add_point_get'else pt();val(0,10**9)
   for _ in range(q):
    t=1 if id=='rectangle_sum'else val(0,1)
    if t==0:rec()if id=='rectangle_add_point_get'else pt();val(0,10**9)
    elif id=='rectangle_add_point_get':pt()
    else:rec()
  else:
   alphabet=set('abcdefghijklmnopqrstuvwxyz'+('*'if id=='wildcard_pattern_matching'else''))
   assert len(ts)==(2 if id=='wildcard_pattern_matching'else 1)
   for s in ts:assert 1<=len(s)<=(524288 if id=='wildcard_pattern_matching'else 500000)and set(s)<=alphabet
   if len(ts)==2:assert len(ts[1])<=len(ts[0])
   i=len(ts)
  return i==len(ts)
 except(AssertionError,IndexError,ValueError):return False
L2={}
for id in IDS:
 if id in IDS[:5]:L2[id]=({'N':5 if id not in IDS[2:4] else 64},{'N':17 if id not in IDS[2:4] else 160000},'O(4^N) for bitmask domains; O(N^2 log N) for divisor domains','O(N*2^N), ranked subset O(N^2*2^N), divisor O(N log N)')
 elif id=='sum_of_floor_of_linear':L2[id]=({'N':500,'T':8},{'N':10**9,'T':8},'O(TN)','O(T log M)')
 elif id=='kth_root_integer':L2[id]=({'T':8},{'T':500000},'O(T K A^(1/K))','O(T K log A)')
 elif id in ['rectangle_sum','point_add_rectangle_sum','rectangle_add_point_get']:L2[id]=({'N':64,'Q':64},{'N':80000,'Q':80000},'O(Q(N+Q))','O((N+Q) log^2(N+Q))')
 elif id=='wildcard_pattern_matching':L2[id]=({'S_length':64,'T_length':64},{'S_length':240000,'T_length':120000},'O(|S||T|)','O((|S|+|T|)log(|S|+|T|))')
 else:L2[id]=({'N':64},{'N':120000},'O(N^2 log N) or worse on repetitive strings','O(N)')
for id,(weak,strong,slow,fast) in L2.items():RECIPES[id]['l2_design']={'weak_caps':weak,'strong_caps':strong,'slow_complexity':slow,'fast_complexity':fast,'fixed_budget_seconds':2.0,'original_source_preserved':True,'preserved':'mathematical relation, I/O schema and non-size constraints'}
