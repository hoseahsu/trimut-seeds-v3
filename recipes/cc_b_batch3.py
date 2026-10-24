"""Twenty public-original mutation families. Admission requires recorded tests.

source-original is retained separately. Standardized Raw and L3 share the weak
profile; L2 alone increases the listed scale limits. Validators also accept
source-original inputs for fidelity audits; release validators must enforce the
per-version bounds. No qualification is inferred from these implementation files.
"""
from pathlib import Path
ASSET=Path(__file__).resolve().parents[1]/'assets/cc_b_batch3'
INFO=[
 ('codenet_p02327',519,'Largest Rectangle','all-zero rectangle → all-one rectangle','Find the largest rectangle consisting entirely of ones rather than zeros, retaining area output.','Histogram heights and a monotone stack compute the maximal rectangle of either target bit; an independent oracle enumerates every rectangle and inspects every cell.',{'h':1400,'w':1400},{'h':6,'w':6},{'h':1400,'w':1400}),
 ('cf_1011_a',527,'Stages','minimum weight → maximum weight','Choose exactly k legal stages to maximize their total weight instead of minimizing it; keep the alphabet gap of at least two and -1 when impossible.','Greedy selection from the low/high end is justified by the ordered gap constraint. The oracle enumerates all k-element subsets of stage instances.',{'n':50},{'n':12},{'n':50}),
 ('cf_1121_a',532,'Technogoblet of Fire','strongest per school → weakest per school','The Technogoblet selects the weakest student in each school instead of the strongest; still minimize unique new schools required to select all chosen students.','Each desired student not currently winning requires one additional school; choosing per-school minima realizes the altered election rule. The oracle enumerates sets of students reassigned to unique new schools.',{'n':100},{'n':8},{'n':100000}),
 ('cf_1225_b1',537,'TV Subscriptions (Easy Version)','minimum distinct shows → maximum distinct shows','Among all length-d windows, return the maximum number of different shows instead of the minimum.','Sliding frequencies maintain exact window support size; change only the outer extremum. The oracle constructs each window set independently.',{'total_n':100,'k':100},{'n':24,'total_n':24},{'n':100000,'total_n':100000}),
 ('cf_166_a',552,'Rank List','smaller penalty wins → larger penalty wins','Keep more solved problems as the primary ranking key, but rank larger penalty times before smaller ones on equal solved counts. Return the size of the group sharing kth place.','Sorting by the revised strict weak order preserves groups of equal pairs. The independent oracle counts the number of strictly better and tied teams for every record.',{'n':50},{'n':30},{'n':200000}),
 ('cf_46_c',565,'Hamsters and Tigers','circular blocks → linear blocks','Treat the supplied order as a fixed line instead of a circle and minimize swaps to make each species occupy one contiguous block. The end positions are no longer adjacent.','Circular solutions correspond to every hamster-count window, while linear solutions require hamsters in the prefix or suffix. The independent oracle enumerates all target species strings and computes mismatch/2.',{'n':1000},{'n':12},{'n':100000}),
 ('cf_633_a',572,'Ebony and Ivory','nonnegative shots → positive shots from both guns','Require at least one shot from each gun instead of permitting either gun to fire zero shots; total damage must still equal c.','Subtract a+b and solve the nonnegative linear Diophantine equation using an extended-gcd congruence and an upper bound. The oracle enumerates shot counts independently.',{'a':100,'b':100,'c':10000},{'a':20,'b':20,'c':200},{'a':100,'b':100,'c':1000000000}),
 ('cf_865_d',582,'Buy Low Sell High','nonnegative inventory → nonpositive inventory','Permit only short positions: sell a share to open/increase debt and buy to cover; inventory may never be positive and must end at zero. Keep at most one transaction per day and maximize profit.','Negating prices maps short-only inventory to the long-only optimization solved by the exchange-correcting heap. The oracle enumerates all legal daily buy/sell/idle action sequences.',{'n':300000},{'n':9},{'n':300000}),
 ('atcoder_abc130_e',601,'Common Subsequence','all matching subsequences → odd-length matching subsequences','Count only equal-content subsequence pairs of odd length instead of every length. Index-set multiplicities and modulo 1000000007 are unchanged.','A two-parity DP extends equal-value pairs by toggling subsequence length parity. The independent oracle materializes both subsequence multisets and joins identical tuples.',{'n':2000,'m':2000},{'n':7,'m':7},{'n':1500,'m':1500}),
 ('atcoder_abc105_d',603,'Candy Distribution','sum congruent 0 → sum congruent 1','Count nonempty intervals whose sum leaves remainder one modulo M instead of remainder zero.','For current prefix residue p, count earlier residue p-1 rather than p. The independent oracle sums every interval directly.',{'n':100000},{'n':40},{'n':100000}),
 ('atcoder_abc171_d',702,'Replacing','sum aggregate → bitwise XOR aggregate','After each value-replacement operation report bitwise XOR of all elements instead of their sum. Values, replacements, operation order, and output cardinality remain unchanged.','A value contributes to XOR iff its multiplicity is odd; moving its full multiplicity updates the aggregate exactly. The oracle explicitly replaces the entire array and folds XOR.',{'n':100000,'q':100000},{'n':25,'q':30},{'n':99999,'q':100000}),
 ('atcoder_dp_m',706,'Educational DP - Candies','exactly K distributed → at most K distributed','Permit leftover candies and count allocations with total distributed at most K rather than exactly K, keeping each child bound and modulo 1000000007.','The same prefix-sum bounded-allocation DP gives every exact total; sum final states 0 through K. The independent oracle enumerates every child allocation tuple.',{'n':100,'k':100000},{'n':5,'k':8},{'n':100,'k':100000}),
 ('cf_1152_a',637,'Neko Finds Grapes','odd sum unlocks → even sum unlocks','A key unlocks a chest exactly when their numbers sum to an even number instead of an odd number. Each chest/key can still be used once.','Parity classes form complete bipartite components, so matching size is the sum of class-size minima. The independent oracle searches assignments with a used-key mask.',{'n':100000,'m':100000},{'n':8,'m':8},{'n':100000,'m':100000}),
 ('cf_1165_e',742,'Two Arrays and Sum of Functions','minimum aggregate → maximum aggregate','Reorder b to maximize the full integer sum over all interval functions instead of minimizing it; take the modulus only after optimization.','Each a_i appears in (i+1)(n-i) intervals. The rearrangement inequality pairs both sorted orders for maximum. The independent oracle enumerates b permutations and directly sums all interval functions.',{'n':200000},{'n':6},{'n':200000}),
 ('cf_372_a',769,'Counting Kangaroos is Fun','holder at least twice → strictly more than twice','Permit containment only when the holder is strictly more than twice the held kangaroo size, instead of at least twice. Minimize visible kangaroos with the same matching restrictions.','Sorted two-pointer matching remains exchange-optimal with the strict threshold. The oracle enumerates disjoint compatible pairs by bitmask recursion.',{'n':500000},{'n':12},{'n':500000}),
 ('cf_489_b',774,'BerSU Ball','skill difference at most one → equal skill','Pair a boy and girl only when their skills are equal, rather than allowing difference at most one; maximize disjoint pairs.','Sorted greedy matching applies at tolerance zero. The independent oracle explores all used-girl masks and unmatched-boy choices.',{'n':100,'m':100},{'n':8,'m':8},{'n':100000,'m':100000}),
 ('cf_1000_c',839,'Covered Points Count','closed intervals → right-open intervals','Segment i covers integer x iff l_i<=x<r_i instead of l_i<=x<=r_i. Degenerate intervals cover no points. Retain counts for every positive coverage multiplicity.','A sweep removes each interval at r rather than r+1. The independent oracle enumerates integer coordinates and all membership predicates.',{'n':200000,'coordinate':10**18},{'n':8,'coordinate':30},{'n':100000,'coordinate':10**18}),
 ('cf_1215_b',849,'The Number of Products','product sign → sum sign','Count nonempty intervals with negative and positive sums instead of negative and positive products. Sum-zero intervals contribute to neither count; inputs remain nonzero integers.','Order statistics of earlier prefix sums yield negative/positive interval counts. The independent oracle explicitly computes sum/product on each interval.',{'n':200000},{'n':30},{'n':200000}),
 ('cf_740_b',889,'Alyona and Flowers','maximize contribution → minimize contribution','Choose any subset of suggested intervals to minimize total mood contribution instead of maximizing it. Choosing none remains allowed.','Interval contributions add independently, so select all negative sums instead of positive sums. The independent oracle enumerates every interval subset.',{'n':100,'m':100},{'n':20,'m':10},{'n':100000,'m':100000}),
 ('cf_451_d',668,'Count Good Substrings','palindrome after compression → palindrome before compression','Count even/odd length substrings that are palindromes themselves, instead of palindromes after merging equal-character runs.','Manacher radii count all ordinary palindromes by parity; the original binary compressed-palindrome predicate is equivalent to equal endpoints. The independent oracle constructs every substring, optionally compresses it, and checks reversal equality.',{'n':100000},{'n':40},{'n':100000}),
]
RECIPES={}
for task,(id,row,title,name,spec,proof,original,weak,strong)in enumerate(INFO,1):
 for role,mut,slow in [('raw',0,0),('l3',1,0),('slow',0,1)]:
  path=ASSET/f'{id}_{role}.cpp';content=f'#define TASK {task}\n#define MUT {mut}\n#define SLOW {slow}\n#include "solver.cpp"\n'
  if not path.exists()or path.read_text()!=content:path.write_text(content)
 RECIPES[id]={'source_id':id,'source':'codecontests','source_row_index':row,'source_name':title,
  'raw_fast':str(ASSET/f'{id}_raw.cpp'),'l3_fast':str(ASSET/f'{id}_l3.cpp'),'slow_baseline':str(ASSET/f'{id}_slow.cpp'),
  'raw_oracle':{'path':str(ASSET/'oracle.py'),'args':[str(task),'raw']},'l3_oracle':{'path':str(ASSET/'oracle.py'),'args':[str(task),'l3']},
  'budget_seconds':0.25 if id=='cf_633_a'else 1.0,'memory_mb':1024,'small_timeout_seconds':20,'independent_oracles':True,
  'mutation_name':name,'mutation_specification':spec,'proof_sketch':proof,'original_bounds':original,'weak_bounds':weak,'strong_bounds':strong,
  'baseline_policy':'Source-original is separate. Standardized Raw and L3 share weak_bounds; L2 alone uses strong_bounds. Source-fidelity checks admit original bounds and do not replace version-specific release validators.',
  'verification_status':'pending_harness','family_id':'cf_1225_b'if id=='cf_1225_b1'else id}
def seq(a):return str(len(a))+'\n'+' '.join(map(str,a))+'\n'
BOUNDARY={
 1:['2 3\n0 0 0\n0 1 1\n','1 1\n1\n'],2:['5 3\nxyabd\n','2 2\nab\n'],3:['3 1 1\n1 2 3\n1 1 1\n3\n'],4:['1\n5 3 2\n1 1 2 3 3\n'],5:['3 1\n1 1\n1 1\n1 2\n'],6:['3\nHTH\n','4\nHHTT\n'],7:['6 11 6\n','3 2 7\n','4 6 15\n'],8:['2\n1 10\n','2\n10 1\n'],9:['2 2\n1 1\n1 1\n','1 1\n1\n2\n'],10:['3 3\n1 2 3\n'],11:['3\n1 2 3\n2\n1 2\n2 3\n'],12:['3 4\n1 2 3\n','2 0\n0 0\n'],13:['2 2\n1 1\n1 1\n'],14:['2\n1 3\n4 2\n'],15:['2\n1 2\n'],16:['1\n1\n1\n2\n'],17:['1\n0 0\n','2\n0 3\n3 5\n'],18:['3\n-1 -1 3\n','2\n-1 1\n'],19:['2 2\n-1 3\n1 1\n1 2\n'],20:['aaba\n','a\n','abba\n']}

def cases(id,mode,rng):
 task=next(i for i,x in enumerate(INFO,1)if x[0]==id)
 if mode=='boundary':yield from((f'boundary_{i}',s)for i,s in enumerate(BOUNDARY[task]));return
 for trial in range(24 if mode=='small'else 1):
  large=mode=='stress';weak=mode=='weak'
  if task==1:
   h=w=1400 if large else(6 if weak else rng.randint(1,6));s=f'{h} {w}\n'+''.join(' '.join(str(0 if large else rng.randrange(2))for _ in range(w))+'\n'for _ in range(h))
  elif task==2:
   n=50 if large else(12 if weak else rng.randint(1,12));k=25 if large else rng.randint(1,n);a=('abcdefghijklmnopqrstuvwxyz'*2)[:n]if large else''.join(rng.choice('abcdefghijklmnop')for _ in range(n));s=f'{n} {k}\n{a}\n'
  elif task==3:
   n=100000 if large else(8 if weak else rng.randint(1,8));m=1 if large else rng.randint(1,n);k=n if large else rng.randint(1,n);p=list(range(1,n+1));rng.shuffle(p);schools=list(range(1,m+1))+[rng.randint(1,m)for _ in range(n-m)];rng.shuffle(schools);chosen=rng.sample(range(1,n+1),k);s=f'{n} {m} {k}\n'+'\n'.join(' '.join(map(str,a))for a in[p,schools,chosen])+'\n'
  elif task==4:
   n=100000 if large else(24 if weak else rng.randint(1,24));k=100;d=n//2 if large else rng.randint(1,n);s=f'1\n{n} {k} {d}\n'+' '.join(str(rng.randint(1,k))for _ in range(n))+'\n'
  elif task==5:
   n=200000 if large else(30 if weak else rng.randint(1,30));k=rng.randint(1,n);s=f'{n} {k}\n'+''.join(f'{rng.randint(1,50)} {rng.randint(1,50)}\n'for _ in range(n))
  elif task==6:
   n=100000 if large else(12 if weak else rng.randint(2,12));a='HT'*(n//2)+('H'if n%2 else'')if large else'HT'+''.join(rng.choice('HT')for _ in range(n-2));s=f'{n}\n{a}\n'
  elif task==7:s='2 4 999999999\n'if large else f'{rng.randint(1,20)} {rng.randint(1,20)} {rng.randint(1,200)}\n'
  elif task==8:
   n=300000 if large else(9 if weak else rng.randint(2,9));s=seq([rng.randint(1,1000000)for _ in range(n)])
  elif task==9:
   n=m=1500 if large else(7 if weak else rng.randint(1,7));s=f'{n} {m}\n'+'\n'.join(' '.join(str(1 if large else rng.randint(1,4))for _ in range(size))for size in(n,m))+'\n'
  elif task==10:
   n=100000 if large else(40 if weak else rng.randint(1,30));m=rng.randint(2,30);s=f'{n} {m}\n'+' '.join(str(rng.randint(1,100))for _ in range(n))+'\n'
  elif task==11:
   n=99999 if large else(25 if weak else rng.randint(1,25));q=100000 if large else(30 if weak else rng.randint(1,30));a=[1 if large else rng.randint(1,8)for _ in range(n)];queries=[(1,2)if i%2==0 else(2,1)for i in range(q)]if large else[rng.sample(range(1,9),2)for _ in range(q)];s=seq(a)+str(q)+'\n'+''.join(f'{b} {c}\n'for b,c in queries)
  elif task==12:
   n=100 if large else(5 if weak else rng.randint(1,5));k=100000 if large else rng.randint(0,8);a=[k if large else rng.randint(0,min(k,4))for _ in range(n)];s=f'{n} {k}\n'+' '.join(map(str,a))+'\n'
  elif task==13:
   n=m=100000 if large else(8 if weak else rng.randint(1,8));a=[1 if large else rng.randint(1,15)for _ in range(n)];b=[1 if large else rng.randint(1,15)for _ in range(m)];s=f'{n} {m}\n'+' '.join(map(str,a))+'\n'+' '.join(map(str,b))+'\n'
  elif task==14:
   n=200000 if large else(6 if weak else rng.randint(1,6));s=seq([rng.randint(1,1000000 if large else 10)for _ in range(n)])+' '.join(str(rng.randint(1,1000000 if large else 10))for _ in range(n))+'\n'
  elif task==15:
   n=500000 if large else(12 if weak else rng.randint(1,12));s=seq([1 if large else rng.randint(1,30)for _ in range(n)])
  elif task==16:
   n=m=100000 if large else(8 if weak else rng.randint(1,8));s=seq([100 if large else rng.randint(1,10)for _ in range(n)])+seq([1 if large else rng.randint(1,10)for _ in range(m)])
  elif task==17:
   n=100000 if large else(8 if weak else rng.randint(1,8));a=[]
   for _ in range(n):
    l=0 if large else rng.randint(0,30);r=10**18 if large else rng.randint(l,30);a.append((l,r))
   s=str(n)+'\n'+''.join(f'{l} {r}\n'for l,r in a)
  elif task==18:
   n=200000 if large else(30 if weak else rng.randint(1,20));s=seq([rng.choice([-9,-3,-1,1,2,8])for _ in range(n)])
  elif task==19:
   n=100000 if large else(20 if weak else rng.randint(1,20));m=100000 if large else(10 if weak else rng.randint(1,10));a=[rng.randint(-100,100)for _ in range(n)];queries=[]
   for _ in range(m):
    l=1 if large else rng.randint(1,n);r=n if large else rng.randint(l,n);queries.append((l,r))
   s=f'{n} {m}\n'+' '.join(map(str,a))+'\n'+''.join(f'{l} {r}\n'for l,r in queries)
  else:
   n=100000 if large else(40 if weak else rng.randint(1,30));s=('a'*n if large else''.join(rng.choice('ab')for _ in range(n)))+'\n'
  yield f'{mode}_{trial:02d}',s

def validate_input(id,text,condition):
 try:
  task=next(i for i,x in enumerate(INFO,1)if x[0]==id);large=condition=='l2';tokens=text.split();p=0
  def num():
   nonlocal p
   v=int(tokens[p]);p+=1;return v
  def word():
   nonlocal p
   s=tokens[p];p+=1;return s
  def read(n):return[num()for _ in range(n)]
  if task==1:
   h=num();w=num();assert 1<=h<=1400 and 1<=w<=1400;assert all(v in(0,1)for v in read(h*w))
  elif task==2:
   n=num();k=num();s=word();assert 1<=k<=n<=50 and len(s)==n and all('a'<=c<='z'for c in s)
  elif task==3:
   n=num();m=num();k=num();assert 1<=m<=n<=(100000 if large else 100)and 1<=k<=n;assert sorted(read(n))==list(range(1,n+1));a=read(n);assert set(a)==set(range(1,m+1));c=read(k);assert len(set(c))==k and all(1<=x<=n for x in c)
  elif task==4:
   t=num();assert 1<=t<=100;total=0
   for _ in range(t):
    n=num();k=num();d=num();total+=n;assert 1<=n<=(100000 if large else 100)and 1<=k<=100 and 1<=d<=n;assert all(1<=x<=k for x in read(n))
   assert total<=(100000 if large else 100)
  elif task==5:
   n=num();k=num();assert 1<=k<=n<=(200000 if large else 50);assert all(1<=v<=50 for v in read(2*n))
  elif task==6:
   n=num();s=word();assert 2<=n<=(100000 if large else 1000)and len(s)==n and set(s)=={'H','T'}
  elif task==7:
   a=num();b=num();c=num();assert 1<=a<=100 and 1<=b<=100 and 1<=c<=(1000000000 if large else 10000)
  elif task==8:
   n=num();assert 2<=n<=300000;assert all(1<=x<=1000000 for x in read(n))
  elif task==9:
   n=num();m=num();assert 1<=n<=2000 and 1<=m<=2000;assert all(1<=x<=100000 for x in read(n+m))
  elif task==10:
   n=num();m=num();assert 1<=n<=100000 and 2<=m<=1000000000;assert all(1<=x<=1000000000 for x in read(n))
  elif task==11:
   n=num();assert 1<=n<=100000;assert all(1<=x<=100000 for x in read(n));q=num();assert 1<=q<=100000
   for _ in range(q):b=num();c=num();assert 1<=b<=100000 and 1<=c<=100000 and b!=c
  elif task==12:
   n=num();k=num();assert 1<=n<=100 and 0<=k<=100000;assert all(0<=x<=k for x in read(n))
  elif task==13:
   n=num();m=num();assert 1<=n<=100000 and 1<=m<=100000;assert all(1<=x<=1000000000 for x in read(n+m))
  elif task==14:
   n=num();assert 1<=n<=200000;assert all(1<=x<=1000000 for x in read(2*n))
  elif task==15:
   n=num();assert 1<=n<=500000;assert all(1<=x<=100000 for x in read(n))
  elif task==16:
   n=num();assert 1<=n<=(100000 if large else 100);assert all(1<=x<=100 for x in read(n));m=num();assert 1<=m<=(100000 if large else 100);assert all(1<=x<=100 for x in read(m))
  elif task==17:
   n=num();assert 1<=n<=200000
   for _ in range(n):l=num();r=num();assert 0<=l<=r<=10**18
  elif task==18:
   n=num();assert 1<=n<=200000;assert all(-10**9<=x<=10**9 and x!=0 for x in read(n))
  elif task==19:
   n=num();m=num();assert 1<=n<=(100000 if large else 100)and 1<=m<=(100000 if large else 100);assert all(abs(x)<=100 for x in read(n))
   for _ in range(m):l=num();r=num();assert 1<=l<=r<=n
  else:
   s=word();assert 1<=len(s)<=100000 and set(s)<={'a','b'}
  return p==len(tokens)
 except(ValueError,IndexError,AssertionError):return False

def check_output(id,input_text,candidate_text,oracle_text,condition):
 if id=='cf_633_a':return candidate_text.strip().lower()==oracle_text.strip().lower()and candidate_text.strip().lower()in('yes','no')
 return candidate_text.split()==oracle_text.split()
def distinguishes(id,input_text,raw_output,l3_output):return not check_output(id,input_text,raw_output,l3_output,'l3')

# Release validation is stricter than source-fidelity admission.
import importlib.util as _release_import
_release_spec=_release_import.spec_from_file_location("cc_b_release",ASSET.parent/"cc_b_release.py")
_release_module=_release_import.module_from_spec(_release_spec)
_release_spec.loader.exec_module(_release_module)
_release_module.bind(globals(),3)
