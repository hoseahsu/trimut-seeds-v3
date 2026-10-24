#!/usr/bin/env python3
"""Read-only full integrity audit of canonical released assets (hashes and gates)."""
import collections,hashlib,json,sys
from pathlib import Path
B=Path(__file__).resolve().parents[1];sys.path[:0]=[str(B/'recipes'),str(B/'assets')]
import validate
CACHE={}
def sha(p):
 p=Path(p).resolve();stat=p.stat();key=(str(p),stat.st_size,stat.st_mtime_ns)
 if key not in CACHE:
  h=hashlib.sha256()
  with p.open('rb')as f:
   for b in iter(lambda:f.read(4*1024**2),b''):h.update(b)
  CACHE[key]=h.hexdigest()
 return CACHE[key]
def check(path,h):
 p=(B/path).resolve();assert p.is_relative_to(B),'path escapes package';assert p.is_file();assert sha(p)==h,f'hash mismatch: {path}'
def main():
 rows=[json.loads(s)for s in (B/'seeds.jsonl').read_text().splitlines()];prompts=[json.loads(s)for s in(B/'prompts.jsonl').read_text().splitlines()];assert len(rows)==300 and len(prompts)==1200
 assert len({r['source_identity'].lower()for r in rows})==300;assert len({r['conditions']['raw']['statement']['sha256']for r in rows})==300
 loaded={};counts=collections.Counter();result=[]
 for r in rows:
  sid=r['seed_id'];condition=r['conditions'];assert condition['raw']['tests']==condition['l1']['tests'];assert condition['raw']['cpu_budget_seconds']==condition['l1']['cpu_budget_seconds']and condition['raw']['memory_mb']==condition['l1']['memory_mb']
  check(**{'path':r['contract']['path'],'h':r['contract']['sha256']});check(r['l1_certificate']['path'],r['l1_certificate']['sha256']);c=json.loads((B/r['contract']['path']).read_text());assert c.get('strict_l2_l3_validation_complete',c.get('admitted',False))
  for program in c['programs'].values():
   check(program['path'],program.get('sha256',program.get('source_sha256')))
   for field in ('dependency_sha256','local_cpp_header_snapshot_sha256'):
    for path,h in program.get(field,{}).items():check(path,h)
   if program.get('params_path'):check(program['params_path'],program['params_sha256'])
  inputsets={}
  for cond,d in condition.items():
   check(d['statement']['path'],d['statement']['sha256']);check(d['tests']['path'],d['tests']['sha256']);check(d['reference_program']['path'],d['reference_program']['sha256']);m=json.loads((B/d['tests']['path']).read_text());assert len(m['records'])==d['test_count'];counts[cond]+=len(m['records']);inputsets[cond]=[t['input_sha256']for t in m['records']]
   for path,h in d['reference_program'].get('dependency_sha256',{}).items():check(path,h)
   for t in m['records']:
    check(t['input_path'],t['input_sha256']);check(t['expected_path'],t['expected_sha256'])
  assert inputsets['raw']==inputsets['l1']==inputsets['l3'];assert set(inputsets['raw'])<set(inputsets['l2'])
  module=r['checker']['recipe_module']
  if module not in loaded:loaded[module]=validate.load_recipe(B/module)
  assert r['checker']['recipe_id']in loaded[module].RECIPES
  result.append({'seed_id':sid,'passed':True,'checks':['source_unique','four_statement_hashes','l1_certificate_hash','raw_l1_same_frozen_suite_and_budget','raw_l3_same_input_list','l2_contains_raw_and_extra_inputs','all_frozen_io_hashes','current_program_hashes','checker_import']})
 promptmap={(p['seed_id'],p['condition']):p for p in prompts};assert len(promptmap)==1200
 for r in rows:
  for cond,d in r['conditions'].items():
   p=promptmap[(r['seed_id'],cond)];assert hashlib.sha256(p['prompt'].encode()).hexdigest()==d['statement']['sha256']==p['prompt_sha256']
 report={'passed':True,'seed_count':300,'prompt_count':1200,'file_hashes_checked':len(CACHE),'test_occurrences':dict(counts),'checks_scope':'Structural and content-integrity audit; execution evidence is per-seed contracts and reports. This audit does not rerun every solver.','records':result};validate.write_json(B/'validation/release_integrity.json',report);summary=json.loads((B/'release_summary.json').read_text());summary['release_status']='validated_finite_cases_integrity_passed';summary['integrity_audit']={'path':'validation/release_integrity.json','sha256':sha(B/'validation/release_integrity.json')};validate.write_json(B/'release_summary.json',summary);print(json.dumps({k:v for k,v in report.items()if k!='records'},ensure_ascii=False))
if __name__=='__main__':main()
