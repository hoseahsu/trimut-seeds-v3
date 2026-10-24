#!/usr/bin/env python3
"""Finite, reproducible native-domain rebuild for the CodeContests batch A (TM056..137).
This does not certify statement mutations or release a seed by itself.
"""
import argparse,json,random,sys
from collections import Counter
from pathlib import Path
BASE=Path(__file__).resolve().parents[1]
sys.path[:0]=[str(BASE/'native'),str(BASE/'recipes'),str(BASE/'assets')]
import validate,cc_a82

def main():
 ap=argparse.ArgumentParser();ap.add_argument('--start',type=int,default=56);ap.add_argument('--end',type=int,default=137);ap.add_argument('--rerun',action='store_true');args=ap.parse_args()
 sandbox=validate.Sandbox();assert sandbox.available
 modules={}
 for seed in map(json.loads,(BASE/'curation/previous_seed_index.jsonl').read_text().splitlines()):
  sid=seed['seed_id'];num=int(sid[2:])
  if not args.start<=num<=args.end or num in (70,):continue
  path=BASE/seed['recipe_module'];m=modules.setdefault(str(path),validate.load_recipe(path));rid=seed['recipe_id'];cfg={**m.RECIPES[rid],'memory_mb':2048,'max_output_bytes':128*1024**2}
  out=BASE/'validation/strict_cc_a'/sid;out.mkdir(parents=True,exist_ok=True);rp=out/'report.json'
  if rp.exists() and not args.rerun:
   old=json.loads(rp.read_text())
   if old.get('status')=='complete':print(sid,'cached',flush=True);continue
  cfg['source_native']={'path':str((BASE/seed['source']['source_reference']).resolve())}
  programs=validate.Programs(sandbox,path.parent,out,cfg)
  report={'seed_id':sid,'status':'running','admitted':False,'native_contract':'native/cc_a82.py','native_contract_sha256':validate.file_hash(BASE/'native/cc_a82.py'),'native_budget_seconds':5.0,'memory_mb':2048,'scope':'Finite program validation only; statement/source/proof audit gates are separate. L2 algorithm separation is not implied.','cases':[],'upstream_ledger':[],'failures':[],'programs':{}}
  for role in ['raw_fast','l3_fast','raw_oracle','l3_oracle','source_native']:
   try:report['programs'][role]=programs.prepare(role)
   except Exception as e:report['failures'].append({'stage':'prepare','role':role,'error':str(e)})
  if report['failures']:
   report['status']='error';validate.write_json(rp,report);print(sid,report['failures'],flush=True);continue
  inputs=[];seen=set();source=json.loads((BASE/seed['source']['source_tests']).read_text())
  for kind,batch in source.items():
   accepted_count=0
   for j,(inp,expected)in enumerate(zip(batch['input'],batch['output'])):
    validity=cc_a82.validate(num,inp);name=f'{kind}_{j:04d}';item={'name':name,'input_sha256':validate.sha(inp.encode()),**validity}
    if validity['valid'] and (kind=='public_tests' or accepted_count<12):
     item['selected']=True;accepted_count+=1
     h=validate.sha(inp.encode())
     if h not in seen:inputs.append((name,inp,expected,'source'));seen.add(h)
    else:item['selected']=False;item['exclusion_reason']='invalid_native_input'if not validity['valid']else'deterministic_first_12_selected_per_nonpublic_partition'
    report['upstream_ledger'].append(item)
  for mode in ['boundary','small']:
   for j,(name,inp)in enumerate(m.cases(rid,mode,random.Random(20261022+num))):
    if j>=24 and mode=='small':break
    validity=cc_a82.validate(num,inp);h=validate.sha(inp.encode())
    if validity['valid'] and h not in seen:inputs.append((mode+'_'+name,inp,None,'small'));seen.add(h)
    elif not validity['valid']:report.setdefault('excluded_legacy_generated',[]).append({'name':name,'input_sha256':h,**validity})
  inputs.append(('native_upper',cc_a82.scale_case(num,False),None,'native_upper'))
  inputs.append(('l2_upper',cc_a82.scale_case(num,True),None,'l2_upper'))
  for name,inp,expected,kind in inputs:
   folder=out/'cases'/name;folder.mkdir(parents=True,exist_ok=True);(folder/'input.txt').write_text(inp)
   cond='l2'if kind=='l2_upper'else'raw';validity=cc_a82.validate(num,inp,cond)
   case={'name':name,'kind':kind,'condition':cond,'input_path':str((folder/'input.txt').relative_to(BASE)),'input_sha256':validate.sha(inp.encode()),'validity':validity,'runs':{}}
   if not validity['valid']:
    report['failures'].append({'case':name,'reason':'generated_input_invalid'});report['cases'].append(case);continue
   for role in ['raw_fast']+([]if kind=='l2_upper'else['l3_fast']):
    run=programs.run(role,inp,5,folder/role);case['runs'][role]=run
    if run['status']!='OK':report['failures'].append({'case':name,'role':role,'status':run['status']})
   if kind=='small':
    for role,fast,condition in [('raw_oracle','raw_fast','raw'),('l3_oracle','l3_fast','l3')]:
     run=programs.run(role,inp,20,folder/role);case['runs'][role]=run
     passed=run['status']=='OK'and case['runs'][fast]['status']=='OK'and validate.accepted(m,rid,inp,validate.output(case['runs'][fast]),validate.output(run),condition)
     case[role+'_matched']=passed
     if not passed:report['failures'].append({'case':name,'reason':role+'_mismatch'})
   if kind=='native_upper':
    run=programs.run('source_native',inp,20,folder/'source_native');case['runs']['source_native']=run
    if run['status']=='OK':expected=validate.output(run)
    else:case['source_reference_scale_result']='unavailable: '+run['status']
   if expected is not None:
    (folder/'raw_expected.txt').write_text(expected);case['raw_expected_path']=str((folder/'raw_expected.txt').relative_to(BASE));case['raw_expected_sha256']=validate.sha(expected.encode())
    passed=case['runs']['raw_fast']['status']=='OK'and validate.accepted(m,rid,inp,validate.output(case['runs']['raw_fast']),expected,'raw')
    case['raw_expected_matched']=passed
    if not passed:report['failures'].append({'case':name,'reason':'raw_expected_mismatch'})
   if kind!='l2_upper' and all(case['runs'][r]['status']=='OK'for r in ['raw_fast','l3_fast']):case['l3_distinguishes_raw']=validate.output(case['runs']['raw_fast']).split()!=validate.output(case['runs']['l3_fast']).split()
   report['cases'].append(case)
   validate.write_json(rp,report)
  report['summary']={'case_count':len(report['cases']),'native_valid_upstream':sum(x['valid']for x in report['upstream_ledger']),'invalid_upstream':sum(not x['valid']for x in report['upstream_ledger']),'independent_l3_small_matches':sum(x.get('l3_oracle_matched',False)for x in report['cases']),'independently_checked_witnesses':sum(x.get('l3_oracle_matched',False)and x.get('l3_distinguishes_raw',False)for x in report['cases']),'failures':len(report['failures'])}
  if not report['summary']['independently_checked_witnesses']:report['failures'].append({'reason':'no_independently_checked_l3_witness'})
  report['status']='complete';validate.write_json(rp,report);print(json.dumps({'seed_id':sid,'summary':report['summary'],'failures':report['failures']},ensure_ascii=False),flush=True)
if __name__=='__main__':main()
