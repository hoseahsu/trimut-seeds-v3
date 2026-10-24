from pathlib import Path
import json,math,sys
from collections import Counter
B=Path(__file__).resolve().parents[1];sys.path.insert(0,str(B/'recipes'));import replacements as m
rows=[]
for rec in json.loads((B/'replacements/index.json').read_text())['records']:
 rid=rec['recipe_id'];cfg=m.RECIPES[rid];key=cfg['key'];p=B/rec['validation_report'];report=json.loads(p.read_text())
 for c in report['cases']['stress']:
  inp=Path(c['input_path']);z=inp.read_text().split()
  if key=='puzzles':
   n=int(z[0]);a=list(map(int,z[2:]));cnt=Counter(a);vals=sorted(cnt);best=10**9
   for l,x in enumerate(vals):
    count=0
    for y in vals[l:]:
     count+=cnt[y]
     if count>=n:best=min(best,y-x);break
   expected=str(best)+'\n'
  elif key=='football':
   cnt=Counter(z[1:]);expected=max(cnt,key=cnt.get)+'\n'
  elif key=='average':
   n=int(z[0]);points=list(zip(map(int,z[1::2]),map(int,z[2::2])));s=math.fsum(math.hypot(x-u,y-v)for i,(x,y)in enumerate(points)for u,v in points[:i]);expected=f'{2*s/n:.12f}\n'
  elif key=='coins':
   A,C100,C50,X=map(int,z);target=X//50;ans=0
   for b in range(C100+1):
    rest=target-2*b;lo=max(0,(rest-C50+9)//10);hi=min(A,rest//10);ans+=max(0,hi-lo+1)
   expected=str(ans)+'\n'
  else:
   N,A,U=map(int,z);assert N==10**9;counts=[1]
   for _ in range(9):
    nxt=[0]*(len(counts)+9)
    for i,cnt in enumerate(counts):
     for d in range(10):nxt[i+d]+=cnt
    counts=nxt
   total=sum(counts[s]*s*111111111//9 for s in range(A,U+1));total+=10**9 if A<=1<=U else 0;expected=str(total)+'\n'
  out=inp.parent/'independent_expanded_expected.txt';out.write_text(expected);assert m.check_output(rid,inp.read_text(),Path(c['runs'][0]['stdout_path']).read_text(),expected,'raw'),(rid,expected)
  rows.append({'seed_id':rec['seed_id'],'recipe_id':rid,'input_path':str(inp.relative_to(B)),'expected_path':str(out.relative_to(B)),'matched':True,'method':{'puzzles':'Value-frequency endpoint enumeration','football':'Independent Python multiplicity count','average':'math.fsum/hypot pair expectation under uniform random permutation; independent language and arithmetic implementation','coins':'Eliminate the 500-yen count for each fixed100-yen count; fast uses the opposite elimination','sums':'Unrestricted9-digit generating-function counts; symmetry gives numeric sums; add1e9 endpoint'}[key]})
(B/'replacements/expanded_audit.json').write_text(json.dumps({'records':rows},ensure_ascii=False,indent=2)+'\n');print('independent expanded agreement',len(rows))
