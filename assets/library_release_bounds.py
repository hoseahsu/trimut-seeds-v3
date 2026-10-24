"""Portable version-cap validation for the80 Library Checker seeds.
validate_version_input(id,text,condition) uses source-domain validation and caps.
condition: source_original, raw, weak, l3, l2. Raw/weak/L3 use weak_caps;
L2 uses strong_caps. Cases beyond a version's caps are supplemental only.
Original downloaded task.md/info.toml/verifier.cpp remain the source authority.
"""
from pathlib import Path
import importlib.util,functools,json,random
ROOT=Path(__file__).resolve().parents[1]
@functools.lru_cache(None)
def registry():
 out={}
 for j in range(1,8):
  name=f'library_batch{j if j>1 else ""}';spec=importlib.util.spec_from_file_location(name,ROOT/'recipes'/f'{name}.py');m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m)
  for id,c in m.RECIPES.items():out[id]=(m,c)
 return out
Q_ONLY=set('set_xor_min queue_operate_all_composite deque_operate_all_composite associative_array persistent_queue'.split())
STRINGS=set('number_of_substrings lyndon_factorization enumerate_palindromes zalgorithm'.split())
MULTI_POINTS=set('closest_pair furthest_pair all_furthest_neighbors static_convex_hull'.split())
def measure_input(id,text):
 t=text.split()
 if id in STRINGS:return{'N':len(t[0])}
 if id=='wildcard_pattern_matching':return{'S_length':len(t[0]),'T_length':len(t[1])}
 if id in Q_ONLY:return{'Q':int(t[0])}
 if id in MULTI_POINTS:
  T=int(t[0]);pos=1;sizes=[]
  for _ in range(T):n=int(t[pos]);sizes.append(n);pos+=1+2*n
  return{'T':T,'N':max(sizes,default=0),'total_N':sum(sizes)}
 if id=='kth_root_integer':return{'T':int(t[0])}
 if id=='sum_of_floor_of_linear':return{'T':int(t[0]),'N':max(map(int,t[1::4]),default=0)}
 m,c=registry()[id];keys=set(c['l2_design']['weak_caps'])|set(c['l2_design']['strong_caps']);out={'N':int(t[0])}
 for k in keys-{'N'}:
  if k in ['M','Q']:out[k]=int(t[1])
  else:raise ValueError(f'Unimplemented size metric {id}/{k}')
 return out

def validate_version_input(id,text,condition):
 try:
  if condition not in ['source_original','raw','weak','l3','l2']:return False
  m,c=registry()[id]
  if not m.validate_input(id,text,'raw'if condition=='source_original'else condition):return False
  if condition=='source_original':return True
  caps=c['l2_design']['strong_caps'if condition=='l2'else'weak_caps'];sizes=measure_input(id,text)
  return all(0<=sizes[k]<=v for k,v in caps.items())
 except(KeyError,ValueError,IndexError,AssertionError,TypeError):return False

def version_bounds(id):
 m,c=registry()[id];d=c['l2_design'];return{'raw':d['weak_caps'],'weak':d['weak_caps'],'l3':d['weak_caps'],'l2':d['strong_caps'],'source_original':'Original public constraints; no experimental weak/strong cap substitution.','metric_definitions':{'N':'First size token, except string length for string tasks; number of bit positions for bitmask convolutions; maximum points per test case for multi-case geometry; maximum summation length over cases for floor-sum.','Q':'Number of operations/queries; first token for queue/set/map-only inputs, second token otherwise.','M':'Number of supplied graph edges.','T':'Number of test cases.','S_length':'Length of text string S.','T_length':'Length of pattern string T.'}}

def strict_witness_candidates(id):
 """Reuse boundary/small cases; split multi-case geometry into valid T=1 inputs."""
 m,c=registry()[id]
 for mode in ['boundary','small','weak']:
  for name,text in m.cases(id,mode,random.Random(123)):
   texts=[(name,text)]
   if id in MULTI_POINTS:
    t=text.split();pos=1;texts=[]
    for j in range(int(t[0])):
     n=int(t[pos]);rows=[t[k]+' '+t[k+1]for k in range(pos+1,pos+1+2*n,2)];texts.append((f'{name}_case{j}',f'1\n{n}\n'+'\n'.join(rows)+('\n'if rows else'')));pos+=1+2*n
   for name,text in texts:
    if validate_version_input(id,text,'raw')and validate_version_input(id,text,'l3'):yield f'{mode}_{name}',text

def classify_case(id,text):
 versions={v:validate_version_input(id,text,v)for v in ['source_original','raw','weak','l2','l3']}
 return{'valid_versions':versions,'supplemental_outside_weak':versions['source_original']and not versions['raw'],'size_metrics':measure_input(id,text)}
if __name__=='__main__':
 out={id:version_bounds(id)for id in registry()};(ROOT/'assets/library_release_bounds.json').write_text(json.dumps(out,indent=2,ensure_ascii=False)+'\n');print(len(out),'version bounds written')
