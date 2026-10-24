#!/usr/bin/env python3
"""Final-domain revalidation, faithful samples, certified enlarged boundary cases.
Program execution always uses the existing networkless Bubblewrap sandbox.
Cache reuse verifies source, dependency and executable hashes before use.
"""
import json,sys,argparse
from pathlib import Path
BASE=Path(__file__).resolve().parents[1]
sys.path[:0]=[str(BASE/'native')]
import validate,cc_b83,cc_b_extensions,cc_b_samples

def main():
 ap=argparse.ArgumentParser();ap.add_argument('--start',type=int,default=138);ap.add_argument('--end',type=int,default=220);args=ap.parse_args()
 sandbox=validate.Sandbox();assert sandbox.available
 rows={int(x['seed_id'][2:]):x for x in map(json.loads,(BASE/'curation/previous_seed_index.jsonl').read_text().splitlines())}
 for k in range(args.start,args.end+1):
  if k==149:continue
  sid=f'TM{k:03}';seed=rows[k];mainpath=BASE/f'validation/strict_cc_b/{sid}/report.json';previous=json.loads(mainpath.read_text());path=BASE/seed['recipe_module'];module=validate.load_recipe(path);rid=seed['recipe_id'];cfg={**module.RECIPES[rid],'memory_mb':2048,'max_output_bytes':128*1024**2}
  if k==138:
   cfg['raw_fast']={'path':str(BASE/'native/assets/selection_sort.cpp')};cfg['l3_fast']={'path':str(BASE/'native/assets/selection_sort_l3.cpp')}
  if k in (184,203):cfg['raw_fast']={'path':str(BASE/'native/assets'/('cielrcpt_wide.cpp'if k==184 else'cookies_wide.cpp'))}
  out=BASE/f'validation/strict_cc_b_supplement/{sid}';out.mkdir(parents=True,exist_ok=True);programs=validate.Programs(sandbox,path.parent,out,cfg)
  report={'seed_id':sid,'status':'running','admitted':False,'programs':{},'native_contract_sha256':validate.file_hash(BASE/'native/cc_b83.py'),'extension_certificate_sha256':validate.file_hash(BASE/'native/cc_b_extensions.py'),'previous_report':str(mainpath.relative_to(BASE)),'previous_report_sha256':validate.file_hash(mainpath),'previous_failures':previous.get('failures',[]),'cases':[],'failures':[],'scope':'Finite native-domain checks and enlarged-domain boundary certificates; neither universal correctness nor timing separation is implied.'}
  for role in ['raw_fast','l3_fast','raw_oracle','l3_oracle']:
   meta=previous.get('programs',{}).get(role);cached=False
   if meta and Path(meta['source_path'])==programs.resolve(cfg[role]if isinstance(cfg[role],str)else cfg[role]['path'])and Path(meta['source_path']).exists()and validate.file_hash(Path(meta['source_path']))==meta['source_sha256']:
    cached=all(Path(p).exists()and validate.file_hash(Path(p))==h for p,h in meta.get('header_sha256',{}).items())
    if 'binary_sha256'in meta:
     binary=Path(meta['mounts'][1]);cached=cached and binary.exists()and validate.file_hash(binary)==meta['binary_sha256']
   if cached:programs.prepared[role]=meta
   else:meta=programs.prepare(role)
   report['programs'][role]={**meta,'verified_cache_reuse':cached}
  # Reject legacy cases which fail the now complete native grammar, while
  # retaining their identities and evidence instead of silently deleting them.
  ledger=[];witnesses=[]
  for c in previous.get('cases',[]):
   inp=(BASE/c['input_path']).read_text();v=cc_b83.validate(k,inp,c['condition']);item={'name':c['name'],'input_sha256':c['input_sha256'],**v}
   if v['valid']and c.get('raw_oracle_matched')and c.get('l3_oracle_matched'):
    # A different valid witness representation is not a logical difference.
    # Require rejection by the task's semantic checker against the independent
    # mutant oracle, rather than merely comparing output token strings.
    raw_run=c['runs'].get('raw_fast',{});oracle_run=c['runs'].get('l3_oracle',{})
    if raw_run.get('status')=='OK'and oracle_run.get('status')=='OK'and not validate.accepted(module,rid,inp,validate.output(raw_run),validate.output(oracle_run),'l3'):witnesses.append(c['name'])
   ledger.append(item)
  report['legacy_case_domain_recheck']=ledger;report['independently_checked_valid_witnesses']=witnesses
  report['witness_policy']='Raw output rejected by L3 semantic checker against independent L3 oracle; both independent oracle comparisons passed and input is native-valid.'
  if not witnesses:report['failures'].append({'reason':'no_valid_independent_l3_witness'})
  samples=cc_b_samples.extract((BASE/f'tasks/{sid}/raw.txt').read_text())
  cases=[(f'original_statement_sample_{j+1}',x['input'],x['output'],'raw','Officially retained complete Raw sample; formatting fences removed.')for j,x in enumerate(samples)]
  inp,expected,proof=cc_b_extensions.certificate(k);cases.append(('certified_l2_upper',inp,expected,'l2',proof))
  if k in(163,177,201):cases.append(('native_upper_recheck',cc_b83.scale_case(k),None,'raw','Recheck native boundary after source-reference portability/overflow repair or full-domain validation.'))
  for name,inp,expected,condition,reason in cases:
   folder=out/'cases'/name;folder.mkdir(parents=True,exist_ok=True);(folder/'input.txt').write_text(inp)
   v=cc_b83.validate(k,inp,condition);c={'name':name,'condition':condition,'input_path':str((folder/'input.txt').relative_to(BASE)),'input_sha256':validate.sha(inp.encode()),'validity':v,'expected_derivation':reason,'runs':{}}
   if not v['valid']:report['failures'].append({'case':name,'reason':'input_invalid','detail':v});report['cases'].append(c);continue
   if condition=='l2'and not v['outside_original']:report['failures'].append({'case':name,'reason':'not_true_extension'})
   for role in ['raw_fast']+(['l3_fast']if condition=='raw'else[]):
    run=programs.run(role,inp,5,folder/role);c['runs'][role]=run
    if run['status']!='OK':report['failures'].append({'case':name,'role':role,'status':run['status']})
   if name=='native_upper_recheck':
    if k in(163,201):
     cfg['source_corrected']={'path':str(BASE/f'native/assets/source_TM{k:03}_corrected.cpp')}
     if 'source_corrected'not in programs.prepared:report['programs']['source_corrected']=programs.prepare('source_corrected')
     run=programs.run('source_corrected',inp,20,folder/'source_corrected');c['runs']['source_corrected']=run
     if run['status']=='OK':expected=validate.output(run)
     else:report['failures'].append({'case':name,'reason':'corrected_source_unavailable','status':run['status']})
    else:expected='b\n'
   if expected is not None:
    (folder/'expected.txt').write_text(expected);c['expected_path']=str((folder/'expected.txt').relative_to(BASE));c['expected_sha256']=validate.sha(expected.encode());c['raw_expected_matched']=c['runs']['raw_fast']['status']=='OK'and validate.accepted(module,rid,inp,validate.output(c['runs']['raw_fast']),expected,'raw')
    if not c['raw_expected_matched']:report['failures'].append({'case':name,'reason':'expected_mismatch'})
   report['cases'].append(c);validate.write_json(out/'report.json',report)
  report['status']='complete';report['finite_checks_passed']=not report['failures'];report['summary']={'samples':len(samples),'extension_matches':sum(c.get('raw_expected_matched',False)and c['condition']=='l2'for c in report['cases']),'valid_independent_witnesses':len(witnesses),'excluded_legacy_cases':sum(not x['valid']for x in ledger),'failures':len(report['failures'])};validate.write_json(out/'report.json',report);print(json.dumps({'seed_id':sid,'summary':report['summary'],'failures':report['failures']}),flush=True)
if __name__=='__main__':main()
