#!/usr/bin/env python3
"""Read-only LC canonical mapping/dependency review and build-cache exclusion audit."""
from pathlib import Path
from collections import Counter
import hashlib,json,re
R=Path(__file__).resolve().parents[1]
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def walk(v,key=''):
 if isinstance(v,dict):
  for k,w in v.items():yield from walk(w,key+'/'+str(k))
 elif isinstance(v,list):
  for k,w in enumerate(v):yield from walk(w,key+'/'+str(k))
 elif isinstance(v,str):yield key,v
def build_file(p):
 try:q=Path(p);q=q if q.is_absolute()else R/q;q=q.resolve().relative_to(R/'validation')
 except ValueError:return False
 return 'build'in q.parts
def quoted_include_closure(path,includes,seen=None):
 seen=set()if seen is None else seen;p=path.resolve()
 if p in seen:return seen,[]
 seen.add(p);missing=[]
 for rel in re.findall(r'^\s*#\s*include\s*"([^"]+)"',p.read_text(errors='replace'),re.M):
  candidates=[p.parent/rel,*[d/rel for d in includes]];dep=next((q.resolve()for q in candidates if q.is_file()),None)
  if dep is None:missing.append({'source':str(p.relative_to(R)),'include':rel});continue
  _,more=quoted_include_closure(dep,includes,seen);missing+=more
 return seen,missing
def main():
 seeds=[json.loads(s)for s in(R/'seeds.jsonl').read_text().splitlines()];lc=[s for s in seeds if s['source_identity'].startswith('library-checker:')];assert len(lc)==80
 rows=[];closure_gaps=[];declared_paths=set();frozen={}
 for s in lc:
  sid=s['seed_id'];c=json.loads((R/s['contract']['path']).read_text());assert sha(R/s['contract']['path'])==s['contract']['sha256'];frozen[s['contract']['path']]=s['contract']['sha256']
  assert s['checker']['recipe_module']==c['output_checker']['module_path'];assert s['checker']['recipe_id']==s['source_identity'].split(':',1)[1];assert sha(R/s['checker']['recipe_module'])==c['output_checker']['module_sha256'];declared_paths.add(s['checker']['recipe_module']);roles={}
  for condition,cfg in s['conditions'].items():
   role={'raw':'raw_source_reference','l1':'raw_source_reference','l2':'l2_fast','l3':'l3_fast'}[condition];p=c['programs'][role];q=cfg['reference_program'];assert q['path']==p['path']and q['sha256']==p['source_sha256'];assert sha(R/q['path'])==q['sha256'];assert q['args']==p.get('args',[]);assert q['include_dirs']==p.get('include_dirs',[]);assert q['compiler_options']==p.get('compiler_options',['-std=c++17','-O2','-pipe']);assert cfg['cpu_budget_seconds']==c['execution']['cpu_budget_seconds'];assert cfg['memory_mb']==c['execution']['experimental_memory_mb'];assert cfg['statement']==c[condition]['statement']
   deps=q['dependency_sha256'];declared_paths.add(q['path']);declared_paths.update(deps)
   for field in('dependency_sha256','local_cpp_header_snapshot_sha256'):
    for dep,h in p.get(field,{}).items():assert deps[dep]==h
   for dep,h in deps.items():assert sha(R/dep)==h
   for folder in q['include_dirs']:
    for dep in(R/folder).rglob('*'):
     if dep.is_file()and'__pycache__'not in dep.parts:assert deps[str(dep.relative_to(R))]==sha(dep)
   if Path(q['path']).suffix in('.cpp','.cc','.cxx'):
    closure,missing=quoted_include_closure(R/q['path'],[R/d for d in q['include_dirs']]);closure_gaps+=missing
    for dep in closure:
     relative=str(dep.relative_to(R))
     if relative!=q['path']and relative not in deps:closure_gaps.append({'seed_id':sid,'condition':condition,'unbound_quoted_include':relative})
   roles[condition]={'program_role':role,'source_sha256':q['sha256'],'dependency_count':len(deps),'cpu_budget_seconds':cfg['cpu_budget_seconds'],'memory_mb':cfg['memory_mb']}
  assert s['conditions']['raw']['tests']==s['conditions']['l1']['tests'];rows.append({'seed_id':sid,'passed':True,'checker_matches_final_contract':True,'conditions':roles})
 all_contracts=list((R/'contracts').glob('*/TM*.json'));bound_hits=[]
 for f in all_contracts:
  for key,value in walk(json.loads(f.read_text())):
   if build_file(value):bound_hits.append({'contract':str(f.relative_to(R)),'key':key,'path':value})
 for s in seeds:
  for key,value in walk(s):
   if build_file(value):bound_hits.append({'seed_id':s['seed_id'],'key':key,'path':value})
 files=[p for p in(R/'validation').rglob('*')if p.is_file()and'build'in p.relative_to(R/'validation').parts];kinds=Counter();other=[]
 for p in files:
  with p.open('rb')as f:magic=f.read(4)
  if magic==b'\x7fELF':kinds['ELF_compiled_program']+=1
  elif p.name=='signature.txt':kinds['compile_cache_signature']+=1
  else:other.append(str(p.relative_to(R)));kinds['other']+=1
 assert not closure_gaps,closure_gaps;assert not bound_hits,bound_hits;assert not other,other
 report_path=R/'preflight/library_runner_smoke_final/report.json';run=json.loads(report_path.read_text());assert run['seed_id']=='TM231'and run['condition']=='l2'and run['passed']and run['selected_test_count']==1
 seed=next(s for s in seeds if s['seed_id']=='TM231');cfg=seed['conditions']['l2'];m=json.loads((R/cfg['tests']['path']).read_text());case=next(q for q in m['records']if q['name']=='expanded_00');assert case['strictly_exceeds_native'];assert case['dimensions']['N']==case['dimensions']['Q']==1000000;assert all(q['native_upper_bound']==500000 for q in case['strictly_exceeds_native']);assert run['source']['source_sha256']==cfg['reference_program']['sha256'];assert run['results'][0]['run']['cpu_affinity']==1
 assert all(sha(R/p)==h for p,h in frozen.items()),'frozen contracts modified during read-only audit'
 result={'schema':'trimut.strict.library.canonical-smoke.v1','reviewer':'library_l3_audit','blind':False,'index':{'path':'seeds.jsonl','sha256':sha(R/'seeds.jsonl')},'judge':{'path':'tools/judge.py','sha256':sha(R/'tools/judge.py')},'library_seed_count':80,'canonical_mapping_checks_passed':80,'all_declared_contract_dependencies_retained':True,'additional_include_tree_binding_verified':True,'quoted_include_dependency_closure_gaps':closure_gaps,'records':rows,'smoke':{'seed_id':'TM231','condition':'l2','case':'expanded_00','dimensions':case['dimensions'],'strictly_exceeds_native':case['strictly_exceeds_native'],'input_sha256':case['input_sha256'],'cpu_affinity':1,'verdict':run['results'][0]['verdict'],'cpu_seconds':run['results'][0]['run']['cpu_seconds'],'cpu_budget_seconds':cfg['cpu_budget_seconds'],'report':{'path':str(report_path.relative_to(R)),'sha256':sha(report_path)},'scope':'One actual expanded-domain case through the final canonical index and dependency-verifying judge; not a rerun of the full frozen suite.'},'compiled_cache_packaging_audit':{'scope':'validation/**/build/** only; no deletion performed','contract_count_scanned':len(all_contracts),'canonical_seed_count_scanned':len(seeds),'files_in_scope':len(files),'total_bytes':sum(p.stat().st_size for p in files),'types':dict(kinds),'bound_file_hits':bound_hits,'unexpected_files':other,'can_omit_from_distribution':True,'keep':['All source programs, source package snapshots, include trees, params.h, checkers, validators, manifests, inputs, expected outputs, JSON evidence and stdout/stderr outside the excluded build-cache directories.'],'note':'Some provenance records retain hashes of historical compiled binaries. These are execution attestations, not source/dependency file bindings; the binaries can be rebuilt. Removing compile caches does not remove those provenance records.'}}
 (R/'preflight/library_runner_smoke.json').write_text(json.dumps(result,indent=2,ensure_ascii=False)+'\n');print(json.dumps({k:v for k,v in result.items()if k not in('records','compiled_cache_packaging_audit')},ensure_ascii=False));print(json.dumps(result['compiled_cache_packaging_audit'],ensure_ascii=False))
if __name__=='__main__':main()
