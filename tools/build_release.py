#!/usr/bin/env python3
"""Build the canonical experiment index. Default is fail-closed at exactly 300.
--preview writes only preflight/seeds.jsonl for integration testing, never a release.
"""
import argparse,collections,hashlib,json,sys,platform
from pathlib import Path
B=Path(__file__).resolve().parents[1]
def sha(p):
 h=hashlib.sha256()
 with Path(p).open('rb')as f:
  for b in iter(lambda:f.read(4*1024**2),b''):h.update(b)
 return h.hexdigest()
def ref(p):
 p=Path(p);p=p if p.is_absolute()else B/p
 return {'path':str(p.relative_to(B)),'sha256':sha(p)}
def checkref(r):
 p=B/r['path'];assert p.is_file(),str(p);assert sha(p)==r['sha256'],f'hash mismatch {r["path"]}'
def write(p,d):p.parent.mkdir(parents=True,exist_ok=True);p.write_text(json.dumps(d,ensure_ascii=False,indent=2)+'\n')
def jsonl(p,rows):p.parent.mkdir(parents=True,exist_ok=True);p.write_text(''.join(json.dumps(r,ensure_ascii=False)+'\n'for r in rows))
def prog(p):
 out={'path':p['path'],'sha256':p.get('sha256',p.get('source_sha256')),'args':p.get('args',[]),'include_dirs':p.get('include_dirs',[]),'compiler_options':p.get('compiler_options',['-std=c++17','-O2','-pipe'])};checkref(out)
 deps={}
 for field in ('dependency_sha256','local_cpp_header_snapshot_sha256'):
  for path,h in p.get(field,{}).items():
   checkref({'path':path,'sha256':h});assert path not in deps or deps[path]==h;deps[path]=h
 # Bind local compilation units and the complete declared include trees as well.
 candidates=[q for q in (B/p['path']).parent.iterdir() if q.is_file() and q.suffix in ('.cpp','.cc','.cxx','.h','.hpp','.tpp','.ipp','.py')]
 for d in out['include_dirs']:candidates.extend(q for q in (B/d).rglob('*') if q.is_file() and '__pycache__' not in q.parts)
 for q in candidates:
  rr=ref(q);assert rr['path']not in deps or deps[rr['path']]==rr['sha256'];deps[rr['path']]=rr['sha256']
 out['dependency_sha256']=dict(sorted(deps.items()));return out

def make_seed(c,contract,old):
 sid=c['seed_id'];folder=B/'tasks'/sid
 for cond in('raw','l1','l2','l3'):checkref(c[cond]['statement'])
 cert=json.loads((folder/'l1_certificate.json').read_text());assert cert['raw_sha256']==c['raw']['statement']['sha256']and cert['l1_sha256']==c['l1']['statement']['sha256'];assert cert['exact_source_reconstruction']and cert['numeric_token_sequence_identical']and cert['mathematical_symbol_sequence_identical_outside_title'];assert cert['raw_ready_for_l1']
 assert c.get('strict_l2_l3_validation_complete',c.get('admitted',False)),sid+' not admitted'
 assert c['l2']['native_upper_bound_strictly_expanded']and c['l2']['fast_program_passed_frozen_expanded_tests']
 assert c['l3']['independent_small_oracle_agreement']and c['l3']['native_domain_runs_passed']and c['l3']['distinguishing_witnesses']and c['l3']['native_constraints_preserved']
 parts={};rows={}
 for cond in('raw','l2','l3'):
  parts[cond]=c[cond]['tests'];checkref(parts[cond]);rows[cond]=json.loads((B/parts[cond]['path']).read_text())['records'];assert rows[cond]
 assert [x['input_sha256']for x in rows['raw']]==[x['input_sha256']for x in rows['l3']],sid+' Raw/L3 input mismatch'
 l1test=c['l1']['tests_must_equal_raw_manifest'];assert l1test==parts['raw']
 # Standard expanded condition retains all native tests and adds every expanded test.
 original={x['input_sha256']for x in rows['raw']};expanded=[r for r in rows['l2']if r['input_sha256']not in original];assert expanded,sid+' no expanded input'
 assert any(r.get('strictly_exceeds_native')or r.get('validity',r.get('native_validity',{})).get('outside_original')or r.get('strictly_outside_original_bound')for r in expanded),sid+' no explicit scale witness'
 rows['l2']=rows['raw']+expanded
 budget=c.get('budget',{});execution=c.get('execution',{});native=json.loads((B/parts['raw']['path']).read_text())
 cpu=budget.get('cpu_seconds',execution.get('cpu_budget_seconds',native.get('cpu_budget_seconds',5)))
 mem=budget.get('memory_mb',execution.get('memory_mb',execution.get('experimental_memory_mb',native.get('memory_mb',native.get('experimental_memory_mb',2048)))))
 conds={}
 for cond in('raw','l2','l3'):
  out=B/'evaluation'/sid/f'{cond}.json';write(out,{'schema':'trimut.experiment-tests.v1','seed_id':sid,'condition':cond,'cpu_budget_seconds':cpu,'memory_mb':mem,'component_manifests':[parts['raw'],parts['l2']]if cond=='l2'else[parts[cond]],'records':rows[cond]})
  p=c['programs'];role='l3_fast'if cond=='l3'else('l2_fast'if cond=='l2'and'l2_fast'in p else('raw_fast'if'raw_fast'in p else'raw_source_reference'))
  conds[cond]={'statement':c[cond]['statement'],'tests':ref(out),'test_count':len(rows[cond]),'reference_program':prog(p[role]),'cpu_budget_seconds':cpu,'memory_mb':mem}
 conds['l1']={**conds['raw'],'statement':c['l1']['statement']};conds={k:conds[k]for k in('raw','l1','l2','l3')}
 checker=c.get('checker',{'recipe_module':old['recipe_module'],'recipe_id':old['recipe_id']});checker={k:checker[k]for k in('recipe_module','recipe_id')}
 if checker['recipe_module']=='recipes/library_release_repairs.py':checker['recipe_module']='recipes/library_batch4.py'
 if checker['recipe_module']=='recipes/library_root_repair.py':checker['recipe_module']='recipes/library_batch3.py'
 source=old['source'];url=c['source_url'];official=url if 'huggingface.co/datasets/'not in url else None
 provenance=json.loads((folder/'raw_provenance.json').read_text());u=provenance.get('official_url','')
 if u and'huggingface.co/datasets/'not in u:official=u
 return {'schema':'trimut.seed.v2','seed_id':sid,'source_identity':c['source_identity'],'title':source.get('title',old.get('title',sid)),'source':{'dataset':source.get('source_dataset'),'dataset_url':source.get('source_repository',url),'original_platform_url':official,'source_problem_id':source.get('source_problem_id'),'source_row_index':source.get('origin_row_index'),'snapshot':provenance.get('source_snapshot',source.get('original_statement')),'raw_provenance':ref(folder/'raw_provenance.json'),'license_note':source.get('license_note','Original publisher and repository notices retained.')},'conditions':conds,'checker':checker,'contract':ref(contract),'l1_certificate':ref(folder/'l1_certificate.json'),'l1_kind':cert['mutation_kind'],'l2_bound_changes':c['l2'].get('bound_changes',{'axis':c['l2'].get('axis'),'native':c['l2'].get('original_upper'),'expanded':c['l2'].get('expanded_upper')}),'l2_expanded_case_count':len(expanded),'l2_algorithm_resource_separation_validated':c['l2']['algorithm_resource_separation_validated'],'l3_operator':c['l3']['operator'],'l3_independent_small_cases':c['l3']['independent_small_cases'],'l3_witness_count':len(c['l3']['distinguishing_witnesses']),'family_split_groups':c['family_split_groups'],'split':'unsplit','status':'validated_finite_cases','human_review':'not_performed','model_evaluation':'not_performed'}

def main():
 ap=argparse.ArgumentParser();ap.add_argument('--preview',action='store_true');args=ap.parse_args();old={x['seed_id']:x for x in map(json.loads,(B/'curation/previous_seed_index.jsonl').read_text().splitlines())}
 for r in json.loads((B/'replacements/index.json').read_text())['records']:old[r['seed_id']]=r
 paths=sorted((B/'contracts').glob('*/TM*.json'));rows=[];errors=[]
 for p in paths:
  try:c=json.loads(p.read_text());rows.append(make_seed(c,p,old[c['seed_id']]))
  except Exception as e:errors.append({'path':str(p.relative_to(B)),'error':repr(e)})
 rows.sort(key=lambda r:r['seed_id']);write(B/'preflight/build_status.json',{'seeds':len(rows),'errors':errors,'preview':args.preview});print(json.dumps({'seeds':len(rows),'errors':errors},ensure_ascii=False))
 if args.preview:jsonl(B/'preflight/seeds.jsonl',rows);return
 assert not errors and len(rows)==300 and len({r['seed_id']for r in rows})==300,'Cannot release incomplete dataset'
 assert len({r['source_identity'].lower()for r in rows})==300
 assert len({r['conditions']['raw']['statement']['sha256']for r in rows})==300
 jsonl(B/'seeds.jsonl',rows)
 prompts=[]
 for r in rows:
  for cond,c in r['conditions'].items():prompts.append({'seed_id':r['seed_id'],'condition':cond,'prompt':(B/c['statement']['path']).read_text(),'prompt_sha256':c['statement']['sha256']})
 jsonl(B/'prompts.jsonl',prompts)
 stats={'schema':'trimut.release.v2','seed_count':300,'distinct_public_original_count':300,'prompt_count':1200,'conditions':['raw','l1','l2','l3'],'raw_l1_identical_test_manifest_count':sum(r['conditions']['raw']['tests']==r['conditions']['l1']['tests']for r in rows),'l1_kinds':dict(collections.Counter(r['l1_kind']for r in rows)),'l2_actual_expansion_count':300,'l2_algorithm_separation_count':sum(r['l2_algorithm_resource_separation_validated']for r in rows),'l3_independent_oracle_and_witness_seed_count':300,'test_occurrences_by_condition':{c:sum(r['conditions'][c]['test_count']for r in rows)for c in ['raw','l1','l2','l3']},'l3_independent_small_case_total':sum(r['l3_independent_small_cases']for r in rows),'l3_distinguishing_witness_total':sum(r['l3_witness_count']for r in rows),'source_datasets':dict(collections.Counter(r['source']['dataset']for r in rows)),'seeds':ref(B/'seeds.jsonl'),'prompts':ref(B/'prompts.jsonl'),'release_status':'built_pending_integrity_audit','limitations':['Finite empirical validation; no universal correctness guarantee.','L2 genuine scale expansion does not generally prove forced algorithm change.','300 different public source identities need not be 300 independent mathematical problem families.','No human blind review or target-model performance result is claimed.']}
 write(B/'release_summary.json',stats)
 lines=['# 300 道种子题索引','','每道公开原题对应四份题面。所有相对路径以本目录为基准；完整机读元数据见 `seeds.jsonl`。','','| ID | 公开原题 | L2 变更 | L3 逻辑变更 |','|---|---|---|---|']
 for r in rows:
  title=r['title'].replace('|','/');bounds=json.dumps(r['l2_bound_changes'],ensure_ascii=False).replace('|','/');op=r['l3_operator'].replace('|','/');lines.append(f'| [{r["seed_id"]}](tasks/{r["seed_id"]}/raw.txt) | {title} | {bounds} | {op} |')
 (B/'INDEX.md').write_text('\n'.join(lines)+'\n')
if __name__=='__main__':main()
