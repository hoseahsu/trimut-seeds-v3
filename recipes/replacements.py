"""Five public-original replacements. Legacy harness 'weak' mode uses actual native bounds."""
from pathlib import Path
import json,random,math,re
ROOT=Path(__file__).resolve().parents[1]
RECIPES={}
INFO={
 'replacement_abc083_b':('sums','TM070','atcoder:abc083_b',2,256,{'N':10000,'B':36},{'N':1000000000,'B':36},'Change upper digit-sum comparison from <= B to < B; lower comparison stays >= A.'),
 'replacement_cf337_A':('puzzles','TM001','codeforces:337_A',1,256,{'n':50,'m':50,'f':1000},{'n':200000,'m':200000,'f':1000},'Change minimum range of selected puzzle sizes to maximum range.'),
 'replacement_cf43_A':('football','TM017','codeforces:43_A',2,256,{'n':100,'name_length':10},{'n':200000,'name_length':10},'Change argmax goal count to argmin goal count among names occurring in the input.'),
 'replacement_abc145_c':('average','TM025','atcoder:abc145_c',2,1024,{'N':8,'coordinate_abs':1000},{'N':2000,'coordinate_abs':1000},'Change aggregation over all Hamiltonian path lengths from arithmetic mean to minimum.'),
 'replacement_abc087_b':('coins','TM149','atcoder:abc087_b',2,256,{'A':50,'B':50,'C':50,'X':20000},{'A':200000,'B':200000,'C':200000,'X':130000000},'Change total value = X to total value <= X; the empty selection is consequently included.'),
}
for rid,(key,sid,source,budget,memory,native,strong,op) in INFO.items():
 def prog(name,cond):return {'path':'../assets/replacements/'+('sums_'+name if key=='sums' else name)+'.cpp','args':[key,cond]}
 RECIPES[rid]={'key':key,'seed_id':sid,'source_id':source,'source_identity':source,'raw_fast':prog('fast','raw'),'raw_oracle':prog('oracle','raw'),'l3_fast':prog('fast','l3'),'l3_oracle':prog('oracle','l3'),'slow_baseline':prog('oracle','raw'),'budget_seconds':budget,'memory_mb':memory,'small_timeout_seconds':budget,'independent_oracles':True,'baseline_kind':'original_native_domain','spec':{'native_bounds':native,'weak_bounds':native,'strong_bounds':strong,'l3_bounds':'same as original native Raw','l3_relation':op,'l2_changed_fields':[k for k in native if native[k]!=strong[k]],'proof_sketch':{'sums':'Digit-position dynamic programming aggregates counts and value sums by prefix tightness and digit sum. Independent oracle enumerates each integer and sums its decimal-character digits. Strict upper-bound mutation only changes terminal-state acceptance.','puzzles':'After sorting, a minimum-range choice can be a consecutive window; maximum range is global max minus global min since n>=2. Oracle enumerates endpoint values and counts all eligible elements without sorted-window selection.','football':'The unique largest or smallest nonzero multiplicity selects the named team; native no-tie promise ensures uniqueness. Fast histogram and independent repeated recounting agree.','average':'Each undirected pair is adjacent in 2*(N-1)! of N! orders, so the average is 2/N times pair-distance sum. Minimum path uses Held-Karp; independent permutation enumeration checks both.','coins':'For each 500-yen count, feasible 100-yen counts form an interval under equality. Under <=, sum the clipped arithmetic progression of allowed 50-yen counts. Independent exhaustive triple enumeration uses the original predicate directly.'}[key]},'l3_operator':op}

def source_samples(rid):
 key=RECIPES[rid]['key'];src={'puzzles':'cf_337_A','football':'cf_43_A','average':'abc145_c','coins':'abc087_b','sums':'abc083_b'}[key]
 t=json.loads((ROOT/'sources/replacement_official'/src/'source_tests.json').read_text())['public_tests']
 return list(zip(t['input'],t['output']))

def validate_input(rid,s,condition):
 try:
  key=RECIPES[rid]['key'];v=s.split();strong=condition=='l2'
  if key=='football':
   n=int(v[0]);a=v[1:];names=set(a)
   return len(a)==n and 1<=n<=(200000 if strong else 100) and len(names)<=2 and all(re.fullmatch('[A-Z]{1,10}',x) for x in a) and (len(names)==1 or len({a.count(x)for x in names})==2)
  z=list(map(int,v))
  if key=='sums':return len(z)==3 and 1<=z[0]<=(1000000000 if strong else 10000) and 1<=z[1]<=z[2]<=36
  if key=='puzzles':n,m=z[:2];return 2<=n<=m<=(200000 if strong else 50) and len(z)==m+2 and all(4<=x<=1000 for x in z[2:])
  if key=='average':
   n=z[0];p=list(zip(z[1::2],z[2::2]));return 2<=n<=(2000 if strong else 8) and len(z)==1+2*n and len(set(p))==n and all(-1000<=x<=1000 for x in z[1:])
  if key=='coins':
   if len(z)!=4:return False
   A,B,C,X=z;return all(0<=q<=(200000 if strong else 50)for q in (A,B,C)) and A+B+C>=1 and 50<=X<=(130000000 if strong else 20000) and X%50==0
 except (ValueError,IndexError):return False
 return False

def gen(key,rng,mode):
 strong=mode=='stress';native_max=mode=='weak'
 if key=='sums':
  n=1000000000 if strong else 10000 if native_max else rng.randint(1,10000);a=rng.randint(1,36);b=rng.randint(a,36);return f'{n} {a} {b}\n'
 if key=='puzzles':
  m=200000 if strong else 50 if native_max else rng.randint(2,30);n=m//2 if strong else rng.randint(2,m)
  a=[rng.randint(4,1000)for _ in range(m)];return f'{n} {m}\n'+' '.join(map(str,a))+'\n'
 if key=='football':
  n=200000 if strong else 100 if native_max else rng.randint(1,99);k=n//2+1 if strong else rng.randrange(n+1)
  if 2*k==n:k+=1
  a=['NORTH']*k+['SOUTH']*(n-k);rng.shuffle(a);return str(n)+'\n'+'\n'.join(a)+'\n'
 if key=='average':
  n=2000 if strong else 8 if native_max else rng.randint(2,7);p=rng.sample(range(2001*2001),n)
  return str(n)+'\n'+''.join(f'{q//2001-1000} {q%2001-1000}\n'for q in p)
 if key=='coins':
  if strong:return '200000\n200000\n200000\n60000000\n'
  A,B,C=(50,50,50)if native_max else (rng.randint(0,50),rng.randint(0,50),rng.randint(0,50));A+=not(A+B+C)
  X=rng.randint(1,400)*50;return f'{A}\n{B}\n{C}\n{X}\n'

BOUNDARIES={
 'sums':['1 1 1\n','10000 1 36\n','10000 36 36\n','9999 1 1\n'],
 'puzzles':['2 3\n4 5 1000\n','2 2\n4 1000\n','3 5\n7 7 7 7 7\n','2 50\n'+' '.join(str(4+i)for i in range(50))+'\n'],
 'football':['1\nABC\n','3\nA\nB\nB\n','100\n'+'A\n'*100,'100\n'+'A\n'*49+'B\n'*51],
 'average':['3\n0 0\n1 0\n0 1\n','2\n-1000 -1000\n1000 1000\n','8\n'+'\n'.join(f'{i} 0'for i in range(8))+'\n'],
 'coins':['0\n0\n1\n50\n','1\n0\n0\n50\n','0\n1\n0\n150\n','50\n50\n50\n20000\n','0\n50\n50\n50\n']}

def cases(rid,mode,rng):
 key=RECIPES[rid]['key']
 if mode=='boundary':
  for i,(s,o)in enumerate(source_samples(rid)):yield f'public_sample_{i+1}',s
  for i,s in enumerate(BOUNDARIES[key]):yield f'boundary_{i+1}',s
 else:
  for i in range(80 if mode=='small' else 2 if mode=='weak' else 1):yield f'{mode}_{i}',gen(key,rng,mode)

def check_output(rid,inp,candidate,expected,condition):
 if RECIPES[rid]['key']=='average':
  try:
   a=candidate.split();b=expected.split();return len(a)==len(b)==1 and math.isfinite(float(a[0])) and abs(float(a[0])-float(b[0]))<=1e-6
  except ValueError:return False
 return candidate.split()==expected.split()
