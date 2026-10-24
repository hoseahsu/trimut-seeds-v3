"""28 distinct public originals with independent executable mutation oracles.
Raw and L3 share weak_bounds; L2 changes declared scale only. Generic validators
also accept source-original examples for fidelity; package validators enforce
version bounds. Public statement/source test bytes remain immutable.
"""
from pathlib import Path
ASSET=Path(__file__).resolve().parents[1]/'assets/cc_b_batch5'
# id,row,title,mutation,specification,proof,original,weak,strong
INFO=[
('cf_846_a',1626,'Curriculum Vitae','nondecreasing → nonincreasing subsequence','Retain as many CV entries as possible with no successful entry immediately after an unsuccessful entry, instead of forbidding the opposite order.','Two states track the best binary monotone subsequence; the oracle enumerates every subsequence.',{'n':100},{'n':12},{'n':200000}),
('atcoder_abc103_b',1648,'String Rotation','rotation → rotation or reflection','Accept when T is any rotation of S or of reversed S, instead of allowing rotations alone.','KMP tests membership in doubled original/reversed strings. The oracle explicitly constructs each transformation.',{'length':100},{'length':12},{'length':200000}),
('atcoder_abc087_c',1649,'Candies','maximum path reward → minimum','Find the minimum candies collected along a right/down path in the same two-row grid.','A path is uniquely determined by its down-step column; prefix/suffix sums evaluate it. The oracle directly sums every path.',{'n':100},{'n':12},{'n':200000}),
('cf_1066_a',1678,'Vova and Train','closed blocked interval → open interval','Lanterns at the standing train endpoints l and r are now visible: only l<p<r is blocked.','Floor division counts multiples in a closed or open interval. The oracle checks each position.',{'L':10**9,'t':10000},{'L':200,'t':2},{'L': 1000000000, 't': 2}),
('cf_1213_b',1685,'Bad Prices','later strictly lower → later no higher','A price is bad when any later price is less than or equal to it instead of strictly less.','A suffix minimum determines the changed comparison. The oracle inspects all later prices.',{'n':150000,'total_n':150000},{'n':20,'t':2},{'n': 150000, 't': 2}),
('cf_1278_a',1688,'Shuffle Hashing','contiguous shuffled password → subsequence','Allow p shuffled to occur as a subsequence of h rather than a contiguous substring. No letter may be added to or removed from p.','Raw uses sliding histograms; L3 checks multiset containment. The oracle enumerates candidate contiguous windows or index combinations.',{'p':100,'h':100,'t':100},{'p':6,'h':12,'t':2},{'p': 10000, 'h': 200000, 't': 2}),
('cf_1321_b',1690,'Journey Planning','increasing beauty difference → decreasing difference','Require c_next-c_prev=b_prev-b_next, rather than b_next-b_prev, retaining the maximum total beauty objective.','Valid paths share key b+i instead of b-i; positive weights allow taking all vertices of a key. The oracle enumerates city subsequences.',{'n':200000},{'n':12},{'n':200000}),
('cf_1547_e',1700,'Air Conditioners','minimum temperature influence → maximum','Each cell receives max_j(t_j+abs(a_j-i)) rather than the minimum of the same influences.','Raw is a two-pass minimum distance transform; L3 is the maximum of two affine envelopes. The oracle evaluates all influences.',{'n':300000,'total_n':300000},{'n':15,'t':2},{'n': 300000, 't': 2}),
('cf_242_e',1704,'XOR on Segment','sum queries → XOR aggregate queries','Type1 returns bitwise XOR over the requested range instead of arithmetic sum. Type2 range XOR updates remain unchanged.','A lazy segment tree stores one counts per bit; a queried bit is selected by odd count in L3. The oracle mutates a plain array.',{'n':100000,'q':50000},{'n':20,'q':30},{'n':100000,'q':50000}),
('cf_5_c',1719,'Longest Regular Bracket Sequence','ordinary regular brackets → reversed interpretation','Treat closing parenthesis as opening and opening parenthesis as closing; report longest regular substring length and its count under that interpretation.','Swapping the interpretation before the stack algorithm is equivalent to changing the prefix-balance sign. The oracle checks every substring independently.',{'length':1000000},{'length':20},{'length':200000}),
('cf_670_d1',1722,'Magic Powder - 1','shared powder budget → per-ingredient budget','Each ingredient separately receives up to k grams of powder; budgets cannot transfer between ingredients. Maximize whole cookies.','Raw feasibility sums deficits, L3 bounds each deficit by k. The independent Raw oracle enumerates all powder allocations.',{'n':1000,'k':1000},{'n':4,'k':6},{'n':1000,'k':10**9}),
('atcoder_agc009_a',1755,'Multiple Array','prefix increment → prefix decrement','Each button decrements its prefix by one instead of incrementing it. Final values may be negative multiples of B; minimize button presses.','Process suffix constraints first and add the least needed modular adjustment. The independent oracle performs BFS over full array states.',{'n':100000,'value':10**9},{'n':4,'a':5,'b':4},{'n':100000,'value':10**9}),
('codechef_sumpair',1779,'SUMPAIR','strict pair difference → inclusive','A disjoint pair is good when its absolute difference is at most D instead of less than D; maximize the sum of selected elements.','Sort and greedily use the largest eligible adjacent pair; positive weights justify exchange to adjacent pairs. The oracle enumerates arbitrary matchings.',{'n':100000,'total_n':500000},{'n':12,'t':2},{'n': 100000, 't': 2}),
('cf_1538_c',1804,'Number of Pairs','closed sum interval → open interval','Count i<j with l<a_i+a_j<r instead of l<=a_i+a_j<=r.','Sorted two-pointer counts of sums below each endpoint implement the interval. The oracle explicitly checks all pairs.',{'n':200000,'total_n':200000},{'n':20,'t':2},{'n': 200000, 't': 2}),
('hackerearth_roy_coin_boxes',1848,'Roy and Coin Boxes','at least X → exactly X coins','Answer the number of boxes with exactly X coins instead of at least X after all interval additions.','A difference array gives box counts, then a histogram answers exact or suffix-count queries. The oracle counts covering intervals independently for every box.',{'n':1000000,'m':1000000,'q':1000000},{'n':20,'m':20,'q':20},{'n':200000,'m':100000,'q':100000}),
('atcoder_abc088_b',1857,'Card Game for Two','maximize own score → minimize own score','Both players optimally minimize their own final score, instead of maximizing it. Alice still moves first; return Alice minus Bob.','With constant total, the minimizing game selects the smallest remaining card first. The independent minimax oracle searches every legal move.',{'n':100},{'n':8},{'n':200000}),
('codenet_p02240',1876,'Connected Components','arbitrary reachable walk → even-length walk','Answer yes only if an even number of edges suffices to walk from s to t; vertices and edges may be revisited and the empty walk is allowed.','Duplicate each vertex by path parity and union across opposite parities. The independent oracle computes transitive closure.',{'n':100000,'m':100000,'q':10000},{'n':10,'m':45,'q':15},{'n':100000,'m':99999,'q':10000}),
('cf_302_a',1915,'Eugeny and Array','zero target sum → one','After rearranging the entire plus/minus-one array, require the queried segment sum to equal one rather than zero.','Length and desired sum determine required positive and negative counts. The independent oracle enumerates all selected index subsets.',{'n':200000,'q':200000},{'n':12,'q':15},{'n':200000,'q':200000}),
('cf_467_c',1922,'George and Job','maximum selected interval sum → minimum','Select exactly k disjoint length-m intervals with minimum total sum instead of maximum.','DP by prefix and interval count considers skipping or taking the final interval. The independent oracle enumerates every combination of interval starts.',{'n':5000},{'n':12},{'n':5000,'k':20}),
('cf_705_c',1932,'Thor','read first t notifications → last t generated','Type3 reads the last t notifications generated so far instead of the first t. They include already read notifications. Types1 and2 remain unchanged.','An ordered set of unread IDs handles either generated-index range; each notification is removed at most once. The oracle maintains individual unread flags.',{'n':300000,'q':300000},{'n':8,'q':30},{'n':100000,'q':300000}),
('cf_911_d',1941,'Inversion Counting','reverse segment → left rotate once','Each query cyclically rotates its segment left by one position instead of reversing it; report inversion parity afterward.','A reversal has choose(length,2) transpositions; a one-step rotation has length-1. The oracle edits the permutation and recounts inversions.',{'n':1500,'q':200000},{'n':12,'q':15},{'n':1500,'q':200000}),
('atcoder_agc047_a',1955,'Integer Product','integer product → even integer product','Count i<j only when A_i*A_j is an even integer rather than any integer. Decimal inputs remain exact.','Scale by10^9 and count factors2,5: product requires at least18 factors each, and L3 requires19 factors2. The oracle uses exact rational multiplication.',{'n':200000},{'n':20},{'n':200000}),
('codenet_p02233',1980,'Fibonacci Number','second base value one → two','Keep f(0)=1 and f(n)=f(n-1)+f(n-2), but set f(1)=2 instead of1.','The changed sequence shifts the original Fibonacci sequence by one. The independent oracle counts one/two-step compositions using binomial coefficients.',{'n':44},{'n':20},{'n':44}),
('codechef_twtclose',1987,'Closing the Tweets','CLOSEALL closes → opens all','The global CLOSEALL command now opens every tweet; CLICK still toggles the requested tweet. Report open count after each command.','An epoch and default bit implement global assignments without touching every tweet; the oracle maintains an explicit set.',{'n':1000,'q':1000},{'n':15,'q':30},{'n':200000,'q':200000}),
('cf_863_b',1939,'Kayaking','minimum instability → maximum','Maximize total tandem instability, retaining exactly two single kayaks and n-1 tandem kayaks.','Minimum uses adjacent sorted pairing with a three-state skip DP; maximum pairs n-1 smallest with n-1 largest. The oracle enumerates all pairings and singles.',{'n':50},{'n':4},{'n':1000}),
('atcoder_abc118_c',1959,'Monsters Battle Royale','minimum final health → maximum','Find the maximum achievable final surviving health instead of the minimum under the same attack process.','The minimum is the gcd. No health increases and the initially largest monster can kill all others, so maximum equals the initial maximum. The oracle enumerates reachable attack states.',{'n':100000,'value':10**9},{'n':3,'value':6},{'n':100000,'value':10**9}),
('hackerearth_xsquare_balanced',1746,'Xsquare And Balanced Strings','minimum balanced pieces → maximum','Split the entire string into the maximum number of nonempty balanced contiguous pieces rather than the minimum. Balanced means every character count is even; return-1 if impossible.','Parity-zero prefixes permit the earliest valid greedy cut; the remainder stays feasible whenever the whole parity is zero. The oracle enumerates every partition.',{'length':100000,'total_length':1000000},{'length':12,'t':2},{'length': 100000, 't': 2}),
('atcoder_abc160_d',1852,'Line++','unit shortcut edge → cost-two shortcut','The extra edge between X and Y has weight2 instead of1; line edges retain weight1. Count unordered vertex pairs by shortest distance k.','Any shortest path uses the shortcut at most once, so evaluate the direct path and two shortcut orientations. The oracle runs Dijkstra from every source.',{'n':2000},{'n':15},{'n':4000}),
]
RECIPES={}
for task,(id,row,title,name,spec,proof,original,weak,strong)in enumerate(INFO,1):
 for role,mut,slow in [('raw',0,0),('l3',1,0),('slow',0,1)]:
  path=ASSET/f'{id}_{role}.cpp';content=f'#define TASK {task}\n#define MUT {mut}\n#define SLOW {slow}\n#include "solver.cpp"\n'
  if not path.exists()or path.read_text()!=content:path.write_text(content)
 RECIPES[id]={'source_id':id,'source':'codecontests','source_row_index':row,'source_name':title,'raw_fast':str(ASSET/f'{id}_raw.cpp'),'l3_fast':str(ASSET/f'{id}_l3.cpp'),'slow_baseline':str(ASSET/f'{id}_slow.cpp'),'raw_oracle':{'path':str(ASSET/'oracle.py'),'args':[str(task),'raw']},'l3_oracle':{'path':str(ASSET/'oracle.py'),'args':[str(task),'l3']},'budget_seconds':.25 if id in('cf_670_d1','codenet_p02233')else 1.,'memory_mb':1024,'small_timeout_seconds':20,'independent_oracles':True,'mutation_name':name,'mutation_specification':spec,'proof_sketch':proof,'original_bounds':original,'weak_bounds':weak,'strong_bounds':strong,'baseline_policy':'Source-original remains separate; standardized Raw and L3 share weak_bounds, while L2 changes declared scale only.','verification_status':'pending_harness','family_id':'cf_670_d'if id=='cf_670_d1'else id}
def seq(a):return str(len(a))+'\n'+' '.join(map(str,a))+'\n'
BOUNDARY={1:['3\n0 0 1\n'],2:['abc\nacb\n'],3:['2\n1 5\n1 1\n'],4:['1\n10 2 2 4\n'],5:['1\n3\n2 2 2\n'],6:['1\nab\nacb\n'],7:['3\n1 2 3\n'],8:['1\n3 2\n1 3\n1 4\n'],9:['2\n1 1\n3\n1 1 2\n2 1 2 1\n1 1 2\n'],10:['((()))\n',')()(\n'],11:['2 2\n1 1\n1 1\n'],12:['2\n1 3\n1 3\n'],13:['1\n2 2\n1 3\n'],14:['1\n3 3 5\n1 2 3\n'],15:['3\n2\n1 3\n1 1\n2\n1\n2\n'],16:['2\n1 3\n'],17:['3 2\n0 1\n1 2\n3\n0 1\n0 2\n1 1\n'],18:['3 2\n1 1 -1\n1 1\n1 2\n'],19:['4 1 2\n1 2 3 4\n'],20:['2 4\n1 1\n1 2\n3 1\n2 1\n'],21:['3\n1 2 3\n1\n1 3\n'],22:['3\n1\n3\n2\n'],23:['1\n'],24:['2 3\nCLICK 1\nCLOSEALL\nCLICK 1\n'],25:['2\n1 2 5 9\n'],26:['2\n2 6\n'],27:['1\naaaa\n'],28:['4 1 4\n']}
def cases(id,mode,rng):
 task=next(i for i,x in enumerate(INFO,1)if x[0]==id)
 if mode=='boundary':yield from((f'boundary_{i}',s)for i,s in enumerate(BOUNDARY[task]));return
 for trial in range(24 if mode=='small'else 1):
  L=mode=='stress';W=mode=='weak'
  if task==1:n=200000 if L else(12 if W else rng.randint(1,12));s=seq([rng.randrange(2)for _ in range(n)])
  elif task==2:
   n=200000 if L else(12 if W else rng.randint(2,12));a='a'*(n-1)+'b'if L else''.join(rng.choice('abc')for _ in range(n));b='a'*(n-1)+'c'if L else''.join(rng.choice('abc')for _ in range(n));s=a+'\n'+b+'\n'
  elif task==3:n=200000 if L else(12 if W else rng.randint(1,12));s=seq([rng.randint(1,100)for _ in range(n)])+' '.join(str(rng.randint(1,100))for _ in range(n))+'\n'
  elif task==4:
   if L:s='1\n1000000000 3 2 999999999\n'
   else:n=rng.randint(1,200);l=rng.randint(1,n);r=rng.randint(l,n);s=f'1\n{n} {rng.randint(1,200)} {l} {r}\n'
  elif task==5:n=150000 if L else(20 if W else rng.randint(1,20));s='1\n'+seq(list(range(1,n+1))if L else[rng.randint(1,20)for _ in range(n)])
  elif task==6:
   p='a'*10000 if L else''.join(rng.choice('abc')for _ in range(rng.randint(1,6)));h='b'*200000 if L else''.join(rng.choice('abc')for _ in range(12 if W else rng.randint(1,12)));s=f'1\n{p}\n{h}\n'
  elif task==7:n=200000 if L else(12 if W else rng.randint(1,12));s=seq([rng.randint(1,400000 if L else 20)for _ in range(n)])
  elif task==8:
   n=300000 if L else(15 if W else rng.randint(1,15));k=n if L else rng.randint(1,n);a=list(range(1,n+1))if L else rng.sample(range(1,n+1),k);s=f'1\n{n} {k}\n'+' '.join(map(str,a))+'\n'+' '.join(str(rng.randint(1,10**9))for _ in range(k))+'\n'
  elif task==9:
   n=100000 if L else(20 if W else rng.randint(1,20));q=50000 if L else 30;s=seq([rng.randint(0,10**6)for _ in range(n)])+str(q)+'\n'
   for i in range(q):
    l=1 if L else rng.randint(1,n);r=n if L else rng.randint(l,n);kind=1+i%2;s+=f'{kind} {l} {r}'+(f' {rng.randint(1,10**6)}'if kind==2 else'')+'\n'
  elif task==10:n=200000 if L else(20 if W else rng.randint(1,20));s=('()'*(n//2)if L else''.join(rng.choice('()')for _ in range(n)))+'\n'
  elif task==11:
   n=1 if L else(4 if W else rng.randint(1,4));k=10**9 if L else rng.randint(1,6);s=f'{n} {k}\n'+' '.join(str(1 if L else rng.randint(1,5))for _ in range(n))+'\n'+' '.join(str(1 if L else rng.randint(1,8))for _ in range(n))+'\n'
  elif task==12:
   n=1 if L else(4 if W else rng.randint(1,4));s=str(n)+'\n'+('1 1000000000\n'if L else''.join(f'{rng.randint(0,5)} {rng.randint(1,4)}\n'for _ in range(n)))
  elif task==13:n=100000 if L else(12 if W else rng.randint(1,12));s=f'1\n{n} {rng.randint(1,10)}\n'+' '.join(str(rng.randint(1,100000 if L else 20))for _ in range(n))+'\n'
  elif task==14:n=200000 if L else(20 if W else rng.randint(1,20));l=rng.randint(1,30);r=rng.randint(l,50);s=f'1\n{n} {l} {r}\n'+' '.join(str(rng.randint(1,10**9 if L else 30))for _ in range(n))+'\n'
  elif task==15:
   n=200000 if L else 20;m=100000 if L else 20;q=100000 if L else 20;s=f'{n}\n{m}\n'
   for _ in range(m):l=1 if L else rng.randint(1,n);r=n if L else rng.randint(l,n);s+=f'{l} {r}\n'
   s+=str(q)+'\n'+'\n'.join(str(rng.randint(1,n))for _ in range(q))+'\n'
  elif task==16:n=200000 if L else(8 if W else rng.randint(1,8));s=seq([rng.randint(1,100)for _ in range(n)])
  elif task==17:
   n=100000 if L else(10 if W else rng.randint(2,10));edges=[(i-1,i)for i in range(1,n)]if L else[(i,j)for i in range(n)for j in range(i+1,n)if rng.randrange(4)==0];q=10000 if L else 15;s=f'{n} {len(edges)}\n'+''.join(f'{a} {b}\n'for a,b in edges)+str(q)+'\n'+''.join(f'{0 if L else rng.randrange(n)} {n-1 if L else rng.randrange(n)}\n'for _ in range(q))
  elif task==18:
   n=200000 if L else(12 if W else rng.randint(1,12));q=200000 if L else 15;s=f'{n} {q}\n'+' '.join(str(rng.choice([-1,1]))for _ in range(n))+'\n'
   for _ in range(q):l=rng.randint(1,n);r=rng.randint(l,n);s+=f'{l} {r}\n'
  elif task==19:
   n=5000 if L else(12 if W else rng.randint(1,12));m=1 if L else rng.randint(1,n);k=20 if L else rng.randint(1,n//m);s=f'{n} {m} {k}\n'+' '.join(str(rng.randint(0,100))for _ in range(n))+'\n'
  elif task==20:
   n=100000 if L else 8;q=300000 if L else 30;created=0;s=f'{n} {q}\n'
   for i in range(q):
    kind=1 if(L and i<150000)or not created else(3 if L else rng.randint(1,3));x=rng.randint(1,n)if kind!=3 else rng.randint(1,created);created+=kind==1;s+=f'{kind} {x}\n'
  elif task==21:
   n=1500 if L else(12 if W else rng.randint(1,12));a=list(range(1,n+1));rng.shuffle(a);q=200000 if L else 15;s=seq(a)+str(q)+'\n'
   for _ in range(q):l=rng.randint(1,n);r=rng.randint(l,n);s+=f'{l} {r}\n'
  elif task==22:
   n=200000 if L else(20 if W else rng.randint(2,20));s=str(n)+'\n'+'\n'.join(rng.choice(['0.000000001','0.2','0.5','1','1.25','2','3','4.8','9999.999999999'])for _ in range(n))+'\n'
  elif task==23:s=str(44 if L else 20 if W else rng.randint(0,20))+'\n'
  elif task==24:
   n=200000 if L else 15;q=200000 if L else 30;s=f'{n} {q}\n'+''.join('CLOSEALL\n'if(L or rng.randrange(3)==0)else f'CLICK {rng.randint(1,n)}\n'for _ in range(q))
  elif task==25:n=1000 if L else(4 if W else rng.randint(2,4));s=str(n)+'\n'+' '.join(str(rng.randint(1,1000))for _ in range(2*n))+'\n'
  elif task==26:s=seq([1]+[1000000000]*99999)if L else seq([rng.randint(1,6)for _ in range(3 if W else rng.randint(2,3))])
  elif task==27:n=100000 if L else(12 if W else rng.randint(1,12));s='1\n'+('a'*n if L else''.join(rng.choice('abc')for _ in range(n)))+'\n'
  else:n=4000 if L else(15 if W else rng.randint(3,15));x=rng.randint(1,n-2);y=rng.randint(x+2,n);s=f'{n} {x} {y}\n'
  yield f'{mode}_{trial:02d}',s

def validate_input(id,text,condition):
 try:
  task=next(i for i,x in enumerate(INFO,1)if x[0]==id);L=condition=='l2';tok=text.split();p=0
  def word():
   nonlocal p
   x=tok[p];p+=1;return x
  def num():return int(word())
  def read(n):return[num()for _ in range(n)]
  def lower(s):return bool(s)and all('a'<=c<='z'for c in s)
  if task==1:n=num();assert 1<=n<=200000;assert all(v in(0,1)for v in read(n))
  elif task==2:a=word();b=word();assert 2<=len(a)<=200000 and len(a)==len(b)and lower(a)and lower(b)
  elif task==3:n=num();assert 1<=n<=200000;assert all(1<=v<=100 for v in read(2*n))
  elif task==4:
   t=num();assert 1<=t<=10000
   for _ in range(t):n,v,l,r=read(4);assert 1<=n<=10**9 and 1<=v<=10**9 and 1<=l<=r<=n
  elif task==5:
   t=num();assert 1<=t<=10000;total=0
   for _ in range(t):n=num();total+=n;assert 1<=n<=150000;assert all(1<=v<=10**6 for v in read(n))
   assert total<=150000
  elif task==6:
   t=num();assert 1<=t<=100
   for _ in range(t):a=word();b=word();assert 1<=len(a)<=10000 and 1<=len(b)<=200000 and lower(a)and lower(b)
  elif task==7:n=num();assert 1<=n<=200000;assert all(1<=v<=400000 for v in read(n))
  elif task==8:
   t=num();assert 1<=t<=10000;total=0
   for _ in range(t):
    n=num();k=num();total+=n;assert 1<=k<=n<=300000;a=read(k);assert len(set(a))==k and all(1<=v<=n for v in a);assert all(1<=v<=10**9 for v in read(k))
   assert total<=300000
  elif task==9:
   n=num();assert 1<=n<=100000;assert all(0<=v<=10**6 for v in read(n));q=num();assert 1<=q<=50000
   for _ in range(q):
    k,l,r=read(3);assert k in(1,2)and 1<=l<=r<=n
    if k==2:assert 1<=num()<=10**6
  elif task==10:s=word();assert 1<=len(s)<=1000000 and set(s)<=set('()')
  elif task==11:
   n=num();k=num();assert 1<=n<=1000 and 1<=k<=10**9;assert all(1<=v<=1000 for v in read(2*n))
  elif task==12:
   n=num();assert 1<=n<=100000
   for _ in range(n):a,b=read(2);assert 0<=a<=10**9 and 1<=b<=10**9
  elif task==13:
   t=num();assert 1<=t<=100000;total=0
   for _ in range(t):n=num();d=num();total+=n;assert 1<=n<=100000 and 1<=d<=100000;assert all(1<=v<=100000 for v in read(n))
   assert total<=500000
  elif task==14:
   t=num();assert 1<=t<=10000;total=0
   for _ in range(t):n,l,r=read(3);total+=n;assert 1<=n<=200000 and 1<=l<=r<=10**9;assert all(1<=v<=10**9 for v in read(n))
   assert total<=200000
  elif task==15:
   n=num();m=num();assert 1<=n<=1000000 and 1<=m<=1000000
   for _ in range(m):l,r=read(2);assert 1<=l<=r<=n
   q=num();assert 1<=q<=1000000;assert all(1<=v<=n for v in read(q))
  elif task==16:n=num();assert 1<=n<=200000;assert all(1<=v<=100 for v in read(n))
  elif task==17:
   n=num();m=num();assert 2<=n<=100000 and 0<=m<=100000
   for _ in range(m):assert all(0<=v<n for v in read(2))
   q=num();assert 1<=q<=10000
   for _ in range(q):assert all(0<=v<n for v in read(2))
  elif task==18:
   n=num();q=num();assert 1<=n<=200000 and 1<=q<=200000;assert all(v in(-1,1)for v in read(n))
   for _ in range(q):l,r=read(2);assert 1<=l<=r<=n
  elif task==19:n,m,k=read(3);assert 1<=m*k<=n<=5000;assert all(0<=v<=10**9 for v in read(n))
  elif task==20:
   n=num();q=num();assert 1<=n<=300000 and 1<=q<=300000;created=0
   for _ in range(q):
    t,x=read(2);assert t in(1,2,3)
    if t==3:assert 1<=x<=created
    else:assert 1<=x<=n
    created+=t==1
  elif task==21:
   n=num();assert 1<=n<=1500;a=read(n);assert set(a)==set(range(1,n+1));q=num();assert 1<=q<=200000
   for _ in range(q):l,r=read(2);assert 1<=l<=r<=n
  elif task==22:
   n=num();assert 2<=n<=200000
   for _ in range(n):
    s=word();assert s.count('.')<=1;parts=s.split('.');assert all(x.isdigit()for x in parts)and(len(parts)==1 or len(parts[1])<=9);x=int(parts[0])*10**9+(int(parts[1].ljust(9,'0'))if len(parts)>1 else 0);assert 0<x<10000*10**9
  elif task==23:assert 0<=num()<=44
  elif task==24:
   n=num();q=num();assert 1<=n<=200000 and 1<=q<=200000
   for _ in range(q):
    s=word();assert s in('CLICK','CLOSEALL')
    if s=='CLICK':assert 1<=num()<=n
  elif task==25:n=num();assert 2<=n<=1000;assert all(1<=v<=1000 for v in read(2*n))
  elif task==26:n=num();assert 2<=n<=100000;assert all(1<=v<=10**9 for v in read(n))
  elif task==27:
   t=num();assert 1<=t<=100000;total=0
   for _ in range(t):s=word();total+=len(s);assert 1<=len(s)<=100000 and lower(s)
   assert total<=1000000
  else:n,x,y=read(3);assert 3<=n<=4000 and 1<=x and x+1<y<=n
  return p==len(tok)
 except(AssertionError,ValueError,IndexError,StopIteration):return False

def check_output(id,input_text,candidate,oracle,condition):return candidate.lower().split()==oracle.lower().split()

# Release validation is stricter than source-fidelity admission.
import importlib.util as _release_import
_release_spec=_release_import.spec_from_file_location("cc_b_release",ASSET.parent/"cc_b_release.py")
_release_module=_release_import.module_from_spec(_release_spec)
_release_spec.loader.exec_module(_release_module)
_release_module.bind(globals(),5)
