"""Twenty public originals. Raw/L3 use one weak baseline, L2 changes scale.

Original source constraints are retained independently. Generic validators also
admit source-original tests; released per-version validators must enforce the
metadata bounds. Malformed downloaded examples must be rejected with provenance,
never silently treated as valid evidence.
"""
from pathlib import Path
from collections import Counter
ASSET=Path(__file__).resolve().parents[1]/'assets/cc_b_batch4'
INFO=[
 ('cf_1157_e',846,'Minimum Array','lexicographic minimum → maximum','Reorder b to maximize c_i=(a_i+b_i) mod n lexicographically, instead of minimizing it.','For each fixed prefix, choose the best currently available residue; an ordered multiset handles the wrap threshold. Independent enumeration considers all b permutations.',{'n':200000},{'n':7},{'n':200000}),
 ('cf_1392_b',753,'Omkar and Infinity Clock','maximum reflection anchor → minimum anchor','At each operation use d=min(a), rather than max(a), then simultaneously replace every a_i by d-a_i.','After the first operation the transformation has period two; derive odd/even formulas using the original extrema. The oracle directly simulates all operations.',{'n':200000,'k':10**18},{'n':20,'k':20},{'n':100000,'k':10**18}),
 ('cf_658_b',781,'Bear and Displayed Friends','display strongest friendships → weakest friendships','Display the k online friends with smallest friendship values rather than largest values, retaining all online/query rules.','A bounded ordered set retains the selected extreme k values. The independent oracle sorts all online friends at every query.',{'n':150000,'q':150000},{'n':20,'q':40},{'n':75000,'q':150000}),
 ('cf_747_c',785,'Servers','smallest available IDs → largest available IDs','Allocate the k available servers with largest IDs rather than smallest IDs. Busy intervals and rejection rules are unchanged.','Release events return servers to an ordered available set; select the desired extreme IDs. The oracle stores whole task occupancy intervals and recomputes the available set.',{'n':100,'q':100000},{'n':10,'q':20},{'n':100000,'q':100000}),
 ('cf_90_b',792,'African Crossword','unique in row and column → repeated in both','Keep cells whose letter appears at least twice in its row and at least twice in its column, instead of exactly once in both. Emit retained letters in row-major order; empty output is valid.','Row/column histograms count the two predicates independently. The oracle scans each cell row and column directly.',{'h':100,'w':100},{'h':6,'w':6},{'h':1000,'w':1000}),
 ('atcoder_abc176_c',806,'Step','nondecreasing raised heights → nonincreasing raised heights','Raise heights using nonnegative stools so that final heights are nonincreasing instead of nondecreasing; minimize total stool height.','Prefix maxima solve the original order; suffix maxima solve its reversal. The independent oracle enumerates all bounded feasible final height vectors.',{'n':200000},{'n':6},{'n':200000}),
 ('atcoder_abc147_d',808,'Xor Sum 4','pairwise XOR sum → pairwise AND sum','Sum A_i AND A_j over i<j, instead of XOR, modulo1000000007.','At bit b, AND contributes choose(count_ones,2) pairs rather than count_ones*count_zeros. The oracle directly evaluates each bitwise pair.',{'n':300000},{'n':30},{'n':300000}),
 ('atcoder_abc075_b',813,'Minesweeper','eight neighbors → four orthogonal neighbors','For every empty cell count only horizontally or vertically adjacent bombs, excluding diagonals; preserve bomb cells.','The local stencil changes from Chebyshev distance one to Manhattan distance one. The independent oracle compares each empty cell with the complete bomb list.',{'h':50,'w':50},{'h':6,'w':6},{'h':1000,'w':1000}),
 ('codenet_p00451',819,'Common Sub-String','common substring → common subsequence','Return longest common subsequence length rather than longest common contiguous substring length, independently for each input pair.','The dynamic-programming recurrence allows skipped characters in either string. The oracle enumerates subsequences of the first string and tests membership in the second.',{'length':4000,'datasets':10},{'length':8,'datasets':2},{'length': 4000, 'datasets': 2}),
 ('cf_215_a',658,'Bicycle Chain','maximum integral gear ratio → minimum integral ratio','Count gears with the smallest integral ratio b_j/a_i, rather than largest; only integral gears are eligible.','A divisor-multiple sweep enumerates all eligible pairs without testing every cross-product pair. The oracle explicitly divides every pair.',{'n':50,'m':50,'teeth':10000},{'n':15,'m':15},{'n':10000,'m':10000}),
 ('cf_191_a',657,'Dynasty Puzzles','closed dynasty endpoints → distinct endpoints','Keep chronological selection and matching adjacent name endpoints, but require the first and final letters of the dynasty to differ rather than coincide. Return maximum total length or zero if none.','DP by first/last letter summarizes all previous valid chains. The independent oracle enumerates name subsequences and checks every required adjacency and endpoint.',{'n':500000},{'n':10},{'n':50000}),
 ('codechef_cielrcpt',730,'CIELRCPT','unlimited menu repetitions → at most once per menu','Each of the twelve power-of-two menu prices may be ordered at most once, rather than arbitrarily often. Minimize menu count and return -1 if the exact amount is impossible.','Distinct binary denominations give a unique subset for amounts<=4095 and no subset above that. The independent oracle performs bounded/unbounded coin DP instead of the closed form.',{'p':100000,'t':5},{'p':4096,'t':5},{'p': 100000000, 't': 5}),
 ('cf_1097_b',739,'Petr and a Combination Lock','final angle zero → final angle180','After all signed rotations require final angle180 degrees modulo360 instead of zero.','A residue-set DP propagates both directions and changes only its acceptance state. The oracle enumerates every sign assignment.',{'n':15},{'n':10},{'n':45}),
 ('cf_1031_b',736,'Curiosity Has No Limits','neighbor OR relation → XOR relation','Require a_i=t_i XOR t_(i+1) instead of OR, preserving the AND relation b_i and values0..3. Return any satisfying sequence or NO.','A four-state path DP enforces each adjacent relation and reconstructs a witness. The independent oracle enumerates all4^n sequences.',{'n':100000},{'n':6},{'n':100000}),
 ('cf_1203_a',744,'Circle of Students','either dance direction → clockwise only','Accept only a clockwise increasing round dance; counterclockwise-only orders are no longer valid.','Checking successor values cyclically suffices. The independent oracle constructs every rotation and compares the explicit target ordering.',{'n':200,'q':200},{'n':20,'q':3},{'n': 100000, 'q': 3}),
 ('codenet_p02398',624,'How Many Divisors?','number of divisors → sum of divisors','Output the sum of divisors of c within[a,b] instead of their count.','Divisors pair around sqrt(c); enumerate both members once. The oracle checks divisibility of every integer in the interval.',{'a':10000,'b':10000,'c':10000},{'a':100,'b':200,'c':200},{'a':10**12,'b':10**12,'c':10**12}),
 ('atcoder_abc128_c',705,'Switches','all bulbs on → all bulbs off','Count switch assignments that extinguish all bulbs instead of lighting all bulbs; each bulb parity target is complemented.','The system is linear overF2; Gaussian elimination gives consistency and nullity. The independent oracle enumerates all switch assignments.',{'n':10,'m':10},{'n':8,'m':8},{'n':50,'m':50}),
 ('codechef_prime1',525,'PRIME1','enumerate primes → enumerate composites','Print all composite integers in each interval instead of primes, excluding one from both classes; preserve increasing order and per-case blank separators.','A segmented sieve classifies the interval using primes through sqrt(r). The independent oracle uses direct trial division per integer.',{'r':1000000000,'width':100000,'t':10},{'r':1000,'width':100,'t':2},{'r': 1000000000, 'width': 100000, 't': 2}),
 ('codechef_frgtnlng',523,'Forgotten Languages','occurs in any phrase → occurs in every phrase','Mark a dictionary word YES only when it occurs in every modern phrase, rather than at least one. Multiple occurrences within a phrase count once.','Per-phrase deduplication gives occurrence counts across phrases. The independent oracle checks membership separately for each dictionary-word/phrase pair.',{'n':100,'k':50,'l':50,'t':20},{'n':12,'k':5,'l':8,'t':2},{'n': 100000, 'k': 100000, 'l': 8, 't': 2}),
 ('cf_239_a',659,'Two Bags of Potatoes','total divisible by k → remainder one','List positive x with x+y<=n and(x+y) mod k=1 instead of zero; return-1 if absent, including k=1.','The possible x form an arithmetic progression with the requested residue. The independent oracle scans all admissible positive x.',{'y':10**9,'k':10**9,'n':10**9},{'y':100,'k':100,'n':200},{'y':10**9,'k':10**9,'n':10**9}),
]
RECIPES={}
for task,(id,row,title,name,spec,proof,original,weak,strong)in enumerate(INFO,1):
 for role,mut,slow in [('raw',0,0),('l3',1,0),('slow',0,1)]:
  path=ASSET/f'{id}_{role}.cpp';content=f'#define TASK {task}\n#define MUT {mut}\n#define SLOW {slow}\n#include "solver.cpp"\n'
  if not path.exists()or path.read_text()!=content:path.write_text(content)
 RECIPES[id]={'source_id':id,'source':'codecontests','source_row_index':row,'source_name':title,
  'raw_fast':str(ASSET/f'{id}_raw.cpp'),'l3_fast':str(ASSET/f'{id}_l3.cpp'),'slow_baseline':str(ASSET/f'{id}_slow.cpp'),
  'raw_oracle':{'path':str(ASSET/'oracle.py'),'args':[str(task),'raw']},'l3_oracle':{'path':str(ASSET/'oracle.py'),'args':[str(task),'l3']},
  'budget_seconds':.1 if id in('cf_215_a','codechef_prime1')else .25 if id in('cf_90_b','codechef_cielrcpt')else 1.,'memory_mb':1024,'small_timeout_seconds':20,'independent_oracles':True,
  'mutation_name':name,'mutation_specification':spec,'proof_sketch':proof,'original_bounds':original,'weak_bounds':weak,'strong_bounds':strong,
  'baseline_policy':'Source-original is separate. Standardized Raw and L3 share weak_bounds; L2 changes only declared scale bounds. Source-fidelity validators admit original inputs, while released version validators must enforce their stated bounds.',
  'verification_status':'pending_harness','family_id':id}
def seq(a):return str(len(a))+'\n'+' '.join(map(str,a))+'\n'
BOUNDARY={1:['2\n0 0\n0 1\n'],2:['1\n2 1\n-1 3\n','1\n2 2\n1 3\n'],3:['2 1 4\n1 3\n1 1\n1 2\n2 1\n2 2\n'],4:['3 2\n1 1 1\n2 2 1\n'],5:['2 2\nza\naa\n','1 1\nz\n'],6:['3\n1 5 1\n','2\n1 5\n'],7:['3\n1 2 3\n'],8:['2 2\n#.\n..\n'],9:['ABC\nAC\n'],10:['2\n1 2\n3\n2 4 6\n','2\n2 3\n2\n4 6\n'],11:['3\nab\nba\nac\n','1\na\n'],12:['2\n4096\n10\n'],13:['1\n180\n','2\n90\n90\n'],14:['2\n1\n1\n','2\n0\n1\n'],15:['1\n3\n1 3 2\n','1\n1\n1\n'],16:['1 10 6\n'],17:['2 3\n2 1 2\n1 1\n1 2\n0 0 1\n'],18:['1\n1 10\n'],19:['1\n2 2\naa bb\n2 aa bb\n1 aa\n'],20:['1 3 10\n','1 1 3\n']}
def wordnum(x):
 s=''
 for _ in range(5):s=chr(97+x%26)+s;x//=26
 return s
def cases(id,mode,rng):
 task=next(i for i,x in enumerate(INFO,1)if x[0]==id)
 if mode=='boundary':yield from((f'boundary_{i}',s)for i,s in enumerate(BOUNDARY[task]));return
 for trial in range(24 if mode=='small'else 1):
  large=mode=='stress';weak=mode=='weak'
  if task==1:
   n=200000 if large else(7 if weak else rng.randint(1,7));s=seq([rng.randrange(n)for _ in range(n)])+' '.join(str(rng.randrange(n))for _ in range(n))+'\n'
  elif task==2:
   n=100000 if large else(20 if weak else rng.randint(1,20));k=10**18 if large else rng.randint(1,20);s=f'1\n{n} {k}\n'+' '.join(str(rng.randint(-10**9,10**9))for _ in range(n))+'\n'
  elif task==3:
   n=75000 if large else(20 if weak else rng.randint(1,20));k=min(6,n);values=rng.sample(range(1,10**9),n)
   if large:queries=[(1,i)for i in range(1,n+1)]+[(2,1)]*n
   else:
    queries=[];online=set()
    for _ in range(39 if weak else rng.randint(1,39)):
     if len(online)<n and rng.randrange(2):i=rng.choice([i for i in range(1,n+1)if i not in online]);online.add(i);queries.append((1,i))
     else:queries.append((2,rng.randint(1,n)))
    queries.append((2,1))
   s=f'{n} {k} {len(queries)}\n'+' '.join(map(str,values))+'\n'+''.join(f'{a} {b}\n'for a,b in queries)
  elif task==4:
   n=100000 if large else(10 if weak else rng.randint(1,10));q=100000 if large else(20 if weak else rng.randint(1,20));s=f'{n} {q}\n'+''.join(f'{i+1} {1 if large else rng.randint(1,n)} {1 if large else rng.randint(1,8)}\n'for i in range(q))
  elif task==5:
   h=w=1000 if large else(6 if weak else rng.randint(1,6));a=[['a'if large else rng.choice('abc')for _ in range(w)]for _ in range(h)];a[0][0]='z';s=f'{h} {w}\n'+'\n'.join(''.join(r)for r in a)+'\n'
  elif task==6:
   n=200000 if large else(6 if weak else rng.randint(1,6));s=seq([rng.randint(1,10**9 if large else 5)for _ in range(n)])
  elif task==7:
   n=300000 if large else(30 if weak else rng.randint(2,30));s=seq([rng.randrange(1<<60)for _ in range(n)])
  elif task==8:
   h=w=1000 if large else(6 if weak else rng.randint(1,6));s=f'{h} {w}\n'+'\n'.join(''.join('#'if(i+j)%2 else'.'for j in range(w))if large else''.join(rng.choice('.#')for _ in range(w))for i in range(h))+'\n'
  elif task==9:
   n=4000 if large else(8 if weak else rng.randint(1,8));m=n if large or weak else rng.randint(1,8);s=('A'*n if large else''.join(rng.choice('ABCD')for _ in range(n)))+'\n'+('A'*m if large else''.join(rng.choice('ABCD')for _ in range(m)))+'\n'
  elif task==10:
   n=m=10000 if large else(15 if weak else rng.randint(1,15));a=list(range(1,10001))if large else[1]+sorted(rng.sample(range(2,100),n-1));b=list(range(1,10001))if large else sorted(rng.sample(range(1,150),m));s=seq(a)+seq(b)
  elif task==11:
   n=50000 if large else(10 if weak else rng.randint(1,10));s=str(n)+'\n'+'\n'.join('aa'if large else''.join(rng.choice('abcd')for _ in range(rng.randint(1,5)))for _ in range(n))+'\n'
  elif task==12:s='1\n'+str(100000000 if large else 4096 if weak else rng.randint(1,500))+'\n'
  elif task==13:
   n=45 if large else(10 if weak else rng.randint(1,10));s=seq([1 if large else rng.randint(1,180)for _ in range(n)])
  elif task==14:
   n=100000 if large else(6 if weak else rng.randint(2,6));a=[0]*(n-1)if large else[rng.randrange(4)for _ in range(n-1)];b=([1]+[0]*(n-2))if large else[rng.randrange(4)for _ in range(n-1)];s=str(n)+'\n'+' '.join(map(str,a))+'\n'+' '.join(map(str,b))+'\n'
  elif task==15:
   n=100000 if large else(20 if weak else rng.randint(1,20));a=list(range(1,n+1))
   if large:a=a[1:]+a[:1]
   else:rng.shuffle(a)
   s='1\n'+seq(a)
  elif task==16:
   if large:s='1 1000000000000 1000000000000\n'
   else:a=rng.randint(1,100);b=rng.randint(a,200);s=f'{a} {b} {rng.randint(1,200)}\n'
  elif task==17:
   n=50 if large else(8 if weak else rng.randint(1,8));m=1 if large else rng.randint(1,8);groups=[list(range(1,n+1))]if large else[sorted(rng.sample(range(1,n+1),rng.randint(1,n)))for _ in range(m)];s=f'{n} {m}\n'+''.join(str(len(g))+' '+' '.join(map(str,g))+'\n'for g in groups)+' '.join(str(rng.randrange(2))for _ in range(m))+'\n'
  elif task==18:
   l=999900000 if large else rng.randint(1,900);r=1000000000 if large else l+rng.randint(0,100);s=f'1\n{l} {r}\n'
  elif task==19:
   n=100000 if large else(12 if weak else rng.randint(1,12));k=100000 if large else rng.randint(1,5);dictionary=[wordnum(i)for i in range(n)]if large else[wordnum(rng.randint(0,20))for _ in range(n)];phrases=[['zzzzz']for _ in range(k)]if large else[[wordnum(rng.randint(0,20))for _ in range(rng.randint(1,8))]for _ in range(k)];s=f'1\n{n} {k}\n'+' '.join(dictionary)+'\n'+''.join(str(len(p))+' '+' '.join(p)+'\n'for p in phrases)
  else:s='1 1000000000 1000000000\n'if large else f'{rng.randint(1,100)} {rng.randint(1,100)} {rng.randint(1,200)}\n'
  yield f'{mode}_{trial:02d}',s

def validate_input(id,text,condition):
 try:
  task=next(i for i,x in enumerate(INFO,1)if x[0]==id);large=condition=='l2';tokens=text.split();p=0
  def num():
   nonlocal p
   x=int(tokens[p]);p+=1;return x
  def word():
   nonlocal p
   x=tokens[p];p+=1;return x
  def read(n):return[num()for _ in range(n)]
  if task==1:
   n=num();assert 1<=n<=200000;assert all(0<=x<n for x in read(2*n))
  elif task==2:
   t=num();assert 1<=t<=100;total=0
   for _ in range(t):
    n=num();k=num();total+=n;assert 1<=n<=200000 and 1<=k<=10**18;assert all(abs(x)<=10**9 for x in read(n))
   assert total<=200000
  elif task==3:
   n=num();k=num();q=num();assert 1<=n<=150000 and 1<=q<=150000 and 1<=k<=min(6,n);v=read(n);assert len(set(v))==n and all(1<=x<=10**9 for x in v);online=set();checks=0
   for _ in range(q):
    kind=num();i=num();assert kind in(1,2)and 1<=i<=n
    if kind==1:assert i not in online;online.add(i)
    else:checks+=1
   assert checks
  elif task==4:
   n=num();q=num();assert 1<=n<=(100000 if large else 100)and 1<=q<=100000;last=0
   for _ in range(q):t=num();k=num();d=num();assert last<t<=1000000 and 1<=k<=n and 1<=d<=1000;last=t
  elif task in(5,8):
   h=num();w=num();cap=1000 if large else 100 if task==5 else 50;assert 1<=h<=cap and 1<=w<=cap;a=[word()for _ in range(h)];assert all(len(r)==w for r in a)
   if task==8:assert all(set(r)<={'.','#'}for r in a)
   else:
    assert all(all('a'<=c<='z'for c in r)for r in a);rows=[Counter(r)for r in a];cols=[Counter(a[i][j]for i in range(h))for j in range(w)];assert any(rows[i][a[i][j]]==1 and cols[j][a[i][j]]==1 for i in range(h)for j in range(w))
  elif task in(6,7):
   n=num();assert(1 if task==6 else 2)<=n<=(200000 if task==6 else 300000);assert all((1<=x<=10**9)if task==6 else(0<=x<1<<60)for x in read(n))
  elif task==9:
   assert len(tokens)%2==0 and 2<=len(tokens)<=20
   for s in tokens:assert 1<=len(s)<=4000 and all('A'<=c<='Z'for c in s)
   return True
  elif task==10:
   n=num();a=read(n);m=num();b=read(m);assert 1<=n<=(10000 if large else 50)and 1<=m<=(10000 if large else 50);assert a==sorted(set(a))and b==sorted(set(b));assert all(1<=x<=10000 for x in a+b)
   # Existence follows cheaply from divisor enumeration, not n*m validation.
   aa=set(a);exists=False
   for y in b:
    for d in range(1,int(y**.5)+1):
     if y%d==0 and(d in aa or y//d in aa):exists=True;break
    if exists:break
   assert exists
  elif task==11:
   n=num();assert 1<=n<=500000
   for _ in range(n):s=word();assert 1<=len(s)<=10 and all('a'<=c<='z'for c in s)
  elif task==12:
   t=num();assert 1<=t<=5;assert all(1<=v<=(100000000 if large else 100000)for v in read(t))
  elif task==13:
   n=num();assert 1<=n<=(45 if large else 15);assert all(1<=x<=180 for x in read(n))
  elif task==14:
   n=num();assert 2<=n<=100000;assert all(0<=x<=3 for x in read(2*n-2))
  elif task==15:
   q=num();assert 1<=q<=200
   for _ in range(q):n=num();assert 1<=n<=(100000 if large else 200);assert sorted(read(n))==list(range(1,n+1))
  elif task==16:
   a=num();b=num();c=num();cap=10**12 if large else 10000;assert 1<=a<=b<=cap and 1<=c<=cap
  elif task==17:
   n=num();m=num();assert 1<=n<=(50 if large else 10)and 1<=m<=(50 if large else 10)
   for _ in range(m):k=num();a=read(k);assert 1<=k<=n and len(set(a))==k and all(1<=v<=n for v in a)
   assert all(v in(0,1)for v in read(m))
  elif task==18:
   t=num();assert 1<=t<=10
   for _ in range(t):l=num();r=num();assert 1<=l<=r<=10**9 and r-l<=100000
  elif task==19:
   t=num();assert 1<=t<=20
   for _ in range(t):
    n=num();k=num();assert 1<=n<=(100000 if large else 100)and 1<=k<=(100000 if large else 50)
    for _ in range(n):assert 1<=len(word())<=5
    for _ in range(k):
     size=num();assert 1<=size<=50
     for _ in range(size):assert 1<=len(word())<=5
  else:
   y=num();k=num();n=num();assert 1<=y<=10**9 and 1<=k<=10**9 and 1<=n<=10**9
  return p==len(tokens)
 except(ValueError,IndexError,AssertionError):return False
def check_output(id,input_text,candidate_text,oracle_text,condition):
 if id=='cf_1031_b':
  a=list(map(int,input_text.split()));n=a[0];left=a[1:n];right=a[n:];c=candidate_text.split();o=oracle_text.split()
  if c==['NO']:return o==['NO']
  if len(c)!=n+1 or c[0]!='YES':return False
  try:v=list(map(int,c[1:]))
  except ValueError:return False
  return all(0<=x<=3 for x in v)and all(((v[i]^v[i+1])if condition=='l3'else(v[i]|v[i+1]))==left[i]and(v[i]&v[i+1])==right[i]for i in range(n-1))
 return candidate_text.split()==oracle_text.split()
def distinguishes(id,input_text,raw_output,l3_output):return not check_output(id,input_text,raw_output,l3_output,'l3')

# Release validation is stricter than source-fidelity admission.
import importlib.util as _release_import
_release_spec=_release_import.spec_from_file_location("cc_b_release",ASSET.parent/"cc_b_release.py")
_release_module=_release_import.module_from_spec(_release_spec)
_release_spec.loader.exec_module(_release_module)
_release_module.bind(globals(),4)
