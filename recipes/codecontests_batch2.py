"""Fifteen distinct public originals, independently testable mutation recipes.

No run/qualification is claimed by importing this module. Source-original text
must remain separate from the weak and strong constraint cohorts. When the
public upper bound is small, L2 explicitly extends it; source samples are
audited separately from generated tests. Reference bodies are locally authored.
"""
from pathlib import Path
from collections import Counter
import re

ASSET=Path(__file__).resolve().parents[1]/'assets/codecontests_batch2'
INFO=[
 ('codenet_p02260',102,'Selection Sort','selection-sort ascending → descending',
  'Run the specified selection-sort pseudocode with the strict comparison A[j] > A[best] instead of <. Return the descending array and the number of nontrivial swaps. Equal values still select the first suffix occurrence.',
  'A segment tree returns the suffix extreme with smallest-index tie breaking; updating both swapped positions exactly simulates selection sort in O(n log n). The independent oracle directly executes the pseudocode.',
  {'n':100},{'n':64},{'n':200000}),
 ('codechef_walk',109,'WALK','minimum velocity decrease 1 → 2',
  'Between consecutive segments, decrease the velocity by at least 2 instead of at least 1. Retain the no-shopping condition V_i >= W_i, integer velocities, and minimization of the first velocity.',
  'For decay d, every feasible initial velocity satisfies V_0 >= W_i+d*i; their maximum is feasible by decreasing exactly d. The oracle independently searches initial velocities and simulates every segment.',
  {'n':100000,'t':10},{'n':25,'t':2},{'n': 100000, 't': 2}),
 ('cf_1155_a',116,'Reverse a Substring','lexicographically smaller → larger',
  'Reverse exactly one substring with distinct endpoints to obtain a lexicographically larger string instead of a smaller one. Keep YES with any valid 1-based endpoints, or NO if impossible.',
  'A larger result exists exactly when there is an adjacent ascent; reversing that pair suffices. The independent oracle enumerates all substrings and constructs the resulting strings.',
  {'n':300000},{'n':40},{'n':300000}),
 ('cf_339_a',142,'Helpful Maths','nondecreasing → nonincreasing summands',
  'Reorder the same summands 1, 2, and 3 into nonincreasing order, preserving the plus-separated expression format.',
  'The histogram of three possible summands uniquely determines both sorted expressions. The independent oracle uses a comparison sort and the slow baseline uses bubble sort.',
  {'expression_characters':100},{'summands':40},{'summands':200000}),
 ('cf_433_a',146,"Kitahara Haruki's Gift",'equal total weight → equal weight and cardinality',
  'Partition all apples into two groups having both equal total weight and equal number of apples, instead of requiring equal weight alone. Apples remain indivisible and weigh only 100 or 200.',
  'Equal weight and cardinality require equal counts of each weight in both groups. Thus both multiplicities must be even. The independent oracle enumerates all subsets and checks both predicates.',
  {'n':100},{'n':16},{'n':100000}),
 ('cf_500_c',149,'New Year Book Reading','minimum initial-stack cost → maximum',
  'Choose the initial stack order to maximize, instead of minimize, the total weight lifted while following the unchanged move-to-front reading operations.',
  'For each pair of books, the initial-order-dependent cost is determined before the first access to either. First-access order minimizes it; reversed first-access order, with never-read books on top, maximizes it. A Fenwick tree simulates the resulting stack. The oracle enumerates every initial permutation.',
  {'n':500,'m':1000},{'n':6,'m':15},{'n':100000,'m':100000}),
 ('cf_5_a',153,"Chat Server's Outgoing Traffic",'broadcast including sender → excluding sender',
  'On a Send command deliver the message to every current participant except its sender, instead of also delivering it to the sender. Add and Remove commands still create no traffic.',
  'The recipient set is the active set minus the sender. Count recipients in constant time after membership maintenance; the independent oracle accounts for one delivery to each qualifying name.',
  {'commands':100,'line_characters':100},{'commands':100},{'commands':120000}),
 ('cf_670_b',156,'Game of Robots','round order left-to-right → right-to-left',
  'In round r, robot r recites identifiers r,r-1,...,1 instead of 1,2,...,r. Rounds and the queried 1-based position k remain unchanged.',
  'Triangular cumulative lengths determine the containing round. Reversing only the within-round offset gives its identifier. The independent oracle materializes the finite sequence on small inputs.',
  {'n':100000,'k':2000000000},{'n':25,'k':325},{'n':100000,'k':2000000000}),
 ('cf_691_d',157,'Swaps in Permutation','lexicographically maximal → minimal reachable permutation',
  'Use the allowed position swaps to produce the lexicographically smallest reachable permutation instead of the largest.',
  'Edge swaps generate all permutations within each connected component and preserve the component multiset. Sorting component values in the desired order is optimal. The independent oracle explores the entire reachable permutation-state graph for small n.',
  {'n':1000000,'m':1000000},{'n':6,'m':8},{'n':100000,'m':99999}),
 ('cf_977_b',169,'Two-gram','most frequent → least frequent occurring two-gram',
  'Return any occurring two-gram with the minimum positive occurrence count, instead of maximum count. Occurrences may still overlap; absent two-grams are ineligible.',
  'A histogram counts all overlapping windows exactly; taking the minimum over its support realizes the new objective. The independent oracle recounts each distinct candidate by scanning the entire string.',
  {'n':100},{'n':60},{'n':300000}),
 ('hackerearth_the_competitive_class_3',179,'The Competitive Class','rank by strictly greater → strictly smaller marks',
  'Define rank_i = 1 + number of students with strictly smaller marks, instead of strictly greater marks. Equal scores retain equal ranks.',
  'Prefix/suffix frequencies compute the rank predicate without pair enumeration. The independent oracle explicitly compares every ordered student pair.',
  {'n':1000,'score':1000},{'n':60},{'n':100000}),
 ('hackerearth_xenny_range_sums',180,'Xenny and Range Sums','right-to-left subtraction → left-to-right subtraction',
  'For each interval keep its sum, but replace a_R-a_(R-1)-...-a_L with a_L-a_(L+1)-...-a_R. Single-element intervals return that element for both outputs.',
  'The noncommutative fold is twice its starting endpoint minus the interval sum; prefix sums give O(1) queries. The independent oracle executes the specified subtraction sequence.',
  {'n':1000000,'q':100000},{'n':40,'q':40},{'n':100000,'q':100000}),
 ('atcoder_abc154_e',182,'Almost Everywhere Zero','exactly K nonzero digits → at most K',
  'Count positive integers at most N with at most K nonzero decimal digits, instead of exactly K. Zero remains excluded and K remains between 1 and 3.',
  'Digit DP maintains prefix tightness and nonzero count; sum states 1 through K for the new target. The independent oracle enumerates positive integers and inspects their decimal digits.',
  {'decimal_digits':100,'k':3},{'N':5000},{'decimal_digits':100,'k':3}),
 ('atcoder_abc140_b',183,'Buffet','ascending adjacency bonus → descending adjacency bonus',
  'Earn bonus C_i when Dish i is eaten immediately after Dish i+1, instead of Dish i+1 immediately after Dish i. Base satisfaction and the permutation of dishes are unchanged.',
  'A scan of adjacent dishes identifies each directed consecutive-ID pair. The independent oracle locates each of the two dish positions separately and evaluates their ordering.',
  {'n':20},{'n':20},{'n':100000}),
 ('hackerearth_new_world_11',176,'New World','minimize maximum jump → maximize minimum jump',
  'Reach the last stone from the first using exactly K forward jumps while maximizing the minimum jump length, instead of minimizing the maximum jump length. All stone coordinates remain strictly increasing.',
  'For a candidate minimum length, greedily take the earliest eligible interior stones while reserving an eligible final jump; this maximizes the jump count. A path with at least K jumps can drop intermediate stones. Binary search finds the optimum. The independent oracle enumerates all K-1 interior landing-point sets.',
  {'n':100000,'t':10},{'n':16,'t':1},{'n':100000,'t':1}),
]
RECIPES={}
for number,(id,row,title,name,spec,proof,original,weak,strong)in enumerate(INFO,1):
 for role,mut,slow in [('raw',0,0),('l3',1,0),('slow',0,1)]:
  path=ASSET/f'{id}_{role}.cpp';text=f'#define TASK {number}\n#define MUT {mut}\n#define SLOW {slow}\n#include "solver.cpp"\n'
  if not path.exists()or path.read_text()!=text:path.write_text(text)
 RECIPES[id]={'source_id':id,'source':'codecontests','source_row_index':row,'source_name':title,
  'raw_fast':str(ASSET/f'{id}_raw.cpp'),'l3_fast':str(ASSET/f'{id}_l3.cpp'),'slow_baseline':str(ASSET/f'{id}_slow.cpp'),
  'raw_oracle':{'path':str(ASSET/'oracle.py'),'args':[str(number),'raw']},'l3_oracle':{'path':str(ASSET/'oracle.py'),'args':[str(number),'l3']},
  'budget_seconds':0.25 if id in ('codechef_walk','cf_670_b') else 1.0,'memory_mb':1024,'small_timeout_seconds':20,'independent_oracles':True,
  'independent_oracle_note':'The Python oracle is independently expressed from the mathematical specification using exhaustive enumeration/direct simulation, without importing optimized C++.',
  'mutation_name':name,'mutation_specification':spec,'proof_sketch':proof,
  'original_bounds':original,'weak_bounds':weak,'strong_bounds':strong,
  'baseline_policy':'Preserve source-original separately. Standardized Raw and L3 both use weak_bounds; L2 alone replaces weak bounds with strong bounds. Source-original fidelity is audited separately. Generator validators also admit original-source tests, so release package validators must enforce their stated version bounds.',
  'verification_status':'pending_harness','family_id':id}

def _seq(a):return str(len(a))+'\n'+' '.join(map(str,a))+'\n'
def _world(a,k):return '1\n'+f'{len(a)} {k}\n'+' '.join(map(str,a))+'\n'
BOUNDARIES={
 'codenet_p02260':['6\n5 6 4 2 1 3\n','5\n3 3 -1 0 -1\n','1\n0\n'],
 'codechef_walk':['2\n3\n1 1 1\n1\n10\n'],
 'cf_1155_a':['2\nba\n','3\nabc\n','2\naa\n'],
 'cf_339_a':['3+2+1\n','1\n','2+2+2\n'],
 'cf_433_a':['3\n100 200 100\n','1\n100\n','4\n100 100 200 200\n'],
 'cf_500_c':['3 5\n1 2 3\n1 3 2 3 1\n','3 1\n1 5 9\n2\n'],
 'cf_5_a':['+a\na:x\n','+a\n+b\na:hello world\n-b\na:\n'],
 'cf_670_b':['2 2\n1 2\n','1 1\n9\n','3 6\n8 3 5\n'],
 'cf_691_d':['3 2\n1 2 3\n1 2\n2 3\n','1 1\n1\n1 1\n'],
 'cf_977_b':['5\nZZZAA\n','2\nAA\n','4\nABAB\n'],
 'hackerearth_the_competitive_class_3':['4\n62 96 82 55\n','3\n1000 1000 1\n','1\n1\n'],
 'hackerearth_xenny_range_sums':['3 3\n1 2 4\n1 3\n2 2\n1 2\n','1 1\n-1000000\n1 1\n'],
 'atcoder_abc154_e':['25\n2\n','1\n3\n','100\n1\n'],
 'atcoder_abc140_b':['3\n3 1 2\n2 5 4\n3 6\n','2\n1 2\n50 50\n50\n'],
 'hackerearth_new_world_11':[_world([1,3,6,10],2),_world([1,2],1),_world([1,4,8],2)],
}

def cases(id,mode,rng):
 if mode=='boundary':
  yield from((f'boundary_{i}',s)for i,s in enumerate(BOUNDARIES[id]));return
 count=24 if mode=='small'else 1
 for trial in range(count):
  strong=mode=='stress';weak=mode=='weak';task=next(i for i,x in enumerate(INFO,1)if x[0]==id)
  if task==1:
   n=200000 if strong else(64 if weak else rng.randint(1,25));s=_seq([rng.randint(-1000,1000)for _ in range(n)])
  elif task==2:
   n=100000 if strong else(25 if weak else rng.randint(1,20));s='1\n'+_seq([1 if strong else rng.randint(1,20)for _ in range(n)])
  elif task==3:
   n=300000 if strong else(40 if weak else rng.randint(2,20));a='a'*n if strong or weak else''.join(rng.choice('abcd')for _ in range(n));s=f'{n}\n{a}\n'
  elif task==4:
   n=200000 if strong else(40 if weak else rng.randint(1,35));a=[3]*(n//2)+[2]*(n//4)+[1]*(n-n//2-n//4)if strong else[rng.randint(1,3)for _ in range(n)];s='+'.join(map(str,a))+'\n'
  elif task==5:
   n=100000 if strong else(16 if weak else rng.randint(1,14));s=_seq([100 if strong else rng.choice([100,200])for _ in range(n)])
  elif task==6:
   n=100000 if strong else(6 if weak else rng.randint(2,6));m=100000 if strong else(12 if weak else rng.randint(1,15));w=[rng.randint(1,100)for _ in range(n)];b=list(range(1,n+1))if strong else[rng.randint(1,n)for _ in range(m)];s=f'{n} {m}\n'+' '.join(map(str,w))+'\n'+' '.join(map(str,b))+'\n'
  elif task==7:
   if strong:s=''.join(f'+u{i}\n'for i in range(60000))+''.join(f'u{i}:message\n'for i in range(60000))
   elif weak:s=''.join(f'+u{i}\n'for i in range(5))+''.join(f'u{i}:hello\n'for i in range(5))
   else:
    active=[];a=[];counter=0
    for _ in range(rng.randint(2,25)):
     kind=rng.randrange(3)if active else 0
     if kind==0:name=f'u{counter}';counter+=1;active.append(name);a.append('+'+name)
     elif kind==1:name=rng.choice(active);active.remove(name);a.append('-'+name)
     else:a.append(rng.choice(active)+':'+rng.choice(['','a','hello','a b c']))
    s='\n'.join(a)+'\n'
  elif task==8:
   n=100000 if strong else(20 if weak else rng.randint(1,25));k=2000000000 if strong else rng.randint(1,n*(n+1)//2);a=rng.sample(range(1,1000000000),n);s=f'{n} {k}\n'+' '.join(map(str,a))+'\n'
  elif task==9:
   n=100000 if strong else(6 if weak else rng.randint(1,6));a=list(range(1,n+1));rng.shuffle(a);edges=[(i,i+1)for i in range(1,n)]if strong or weak else[(rng.randint(1,n),rng.randint(1,n))for _ in range(rng.randint(1,8))];s=f'{n} {len(edges)}\n'+' '.join(map(str,a))+'\n'+''.join(f'{a} {b}\n'for a,b in edges)
  elif task==10:
   n=300000 if strong else(60 if weak else rng.randint(2,25));a='A'*(n-1)+'B'if strong else''.join(rng.choice('ABCD')for _ in range(n));s=f'{n}\n{a}\n'
  elif task==11:
   n=100000 if strong else(60 if weak else rng.randint(1,25));s=_seq([rng.randint(1,1000)for _ in range(n)])
  elif task==12:
   n=100000 if strong else(40 if weak else rng.randint(1,20));q=100000 if strong else(40 if weak else rng.randint(1,25));a=[rng.randint(-1000000,1000000)for _ in range(n)];queries=[]
   for _ in range(q):
    l=1 if strong else rng.randint(1,n);r=n if strong else rng.randint(l,n);queries.append((l,r))
   s=f'{n} {q}\n'+' '.join(map(str,a))+'\n'+''.join(f'{l} {r}\n'for l,r in queries)
  elif task==13:s=('9'*100 if strong else str(5000 if weak else rng.randint(1,3000)))+'\n'+str(3 if strong else rng.randint(1,3))+'\n'
  elif task==14:
   n=100000 if strong else(20 if weak else rng.randint(2,15));a=list(range(1,n+1));rng.shuffle(a);s=_seq(a)+' '.join(str(rng.randint(1,50))for _ in range(n))+'\n'+' '.join(str(rng.randint(1,50))for _ in range(n-1))+'\n'
  else:
   n=100000 if strong else(16 if weak else rng.randint(2,12));k=n//2 if strong else(5 if weak else rng.randint(1,n-1));a=[];x=0
   for _ in range(n):x+=rng.randint(1,20);a.append(x)
   s=_world(a,k)
  yield f'{mode}_{trial:02d}',s

def validate_input(id,text,condition):
 try:
  task=next(i for i,x in enumerate(INFO,1)if x[0]==id);large=condition=='l2';tokens=text.split();p=0
  def num():
   nonlocal p
   v=int(tokens[p]);p+=1;return v
  def read(n):return[num()for _ in range(n)]
  if task==3 or task==10:
   n=num();a=tokens[p];p+=1;cap=300000 if task==3 or large else 100
   assert 2<=n<=cap and len(a)==n and all(('a'<=c<='z')if task==3 else('A'<=c<='Z')for c in a)
  elif task==4:
   a=text.strip();assert re.fullmatch(r'[123](\+[123])*',a);assert len(a)<=(399999 if large else 100);return True
  elif task==7:
   lines=text.splitlines();assert 1<=len(lines)<=(120000 if large else 100);active=set()
   for line in lines:
    assert len(line)<=100 and line
    if line[0]in'+-':
     name=line[1:];assert re.fullmatch('[A-Za-z0-9]+',name)
     if line[0]=='+':assert name not in active;active.add(name)
     else:assert name in active;active.remove(name)
    else:
     name,message=line.split(':',1);assert name in active and re.fullmatch('[A-Za-z0-9]+',name)
     assert all(c.isascii()and(c.isalnum()or c==' ')for c in message);assert message==message.strip()
   return True
  elif task==1:
   n=num();assert 1<=n<=(200000 if large else 100);read(n)
  elif task==2:
   t=num();assert 1<=t<=10
   for _ in range(t):
    n=num();assert 1<=n<=100000;assert all(1<=v<=1000000 for v in read(n))
  elif task==5:
   n=num();assert 1<=n<=(100000 if large else 100);assert all(v in(100,200)for v in read(n))
  elif task==6:
   n=num();m=num();assert 2<=n<=(100000 if large else 500)and 1<=m<=(100000 if large else 1000);assert all(1<=x<=100 for x in read(n));assert all(1<=x<=n for x in read(m))
  elif task==8:
   n=num();k=num();assert 1<=n<=100000 and 1<=k<=min(2000000000,n*(n+1)//2);a=read(n);assert len(set(a))==n and all(1<=v<=1000000000 for v in a)
  elif task==9:
   n=num();m=num();assert 1<=n<=1000000 and 1<=m<=1000000;assert sorted(read(n))==list(range(1,n+1));assert all(1<=v<=n for v in read(2*m))
  elif task==11:
   n=num();assert 1<=n<=(100000 if large else 1000);assert all(1<=v<=1000 for v in read(n))
  elif task==12:
   n=num();q=num();assert 1<=n<=1000000 and 1<=q<=100000;assert all(abs(v)<=1000000 for v in read(n))
   for _ in range(q):l=num();r=num();assert 1<=l<=r<=n
  elif task==13:
   n=num();k=num();assert 1<=n<10**100 and 1<=k<=3
  elif task==14:
   n=num();assert 2<=n<=(100000 if large else 20);assert sorted(read(n))==list(range(1,n+1));assert all(1<=v<=50 for v in read(2*n-1))
  elif task==15:
   t=num();assert 1<=t<=10
   for _ in range(t):
    n=num();k=num();a=read(n);assert 2<=n<=100000 and 1<=k<n and len(set(a))==n and a==sorted(a)and all(1<=v<=1000000000 for v in a)
  return p==len(tokens)
 except(ValueError,IndexError,AssertionError,StopIteration):return False

def check_output(id,input_text,candidate_text,oracle_text,condition):
 mut=condition=='l3'
 if id=='cf_1155_a':
  n,s=input_text.split();a=candidate_text.split();o=oracle_text.split()
  if a==['NO']:return o==['NO']
  if len(a)!=3 or a[0]!='YES':return False
  try:l,r=map(int,a[1:])
  except ValueError:return False
  if not 1<=l<r<=len(s):return False
  new=s[:l-1]+s[l-1:r][::-1]+s[r:];return(new>s)if mut else(new<s)
 if id=='cf_977_b':
  s=input_text.split()[1];counts=Counter(s[i:i+2]for i in range(len(s)-1));answer=candidate_text.split()
  if len(answer)!=1 or answer[0]not in counts:return False
  return counts[answer[0]]==(min(counts.values())if mut else max(counts.values()))
 return candidate_text.split()==oracle_text.split()

def distinguishes(id,input_text,raw_output,l3_output):return not check_output(id,input_text,raw_output,l3_output,'l3')

# Release validation is stricter than source-fidelity admission.
import importlib.util as _release_import
_release_spec=_release_import.spec_from_file_location("cc_b_release",ASSET.parent/"cc_b_release.py")
_release_module=_release_import.module_from_spec(_release_spec)
_release_spec.loader.exec_module(_release_module)
_release_module.bind(globals(),2)
