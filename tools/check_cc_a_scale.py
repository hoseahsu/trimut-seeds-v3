#!/usr/bin/env python3
from pathlib import Path
import json,sys,argparse
B=Path(__file__).resolve().parents[1];sys.path[:0]=[str(B/'native'),str(B/'recipes')]
import cc_a82 as native,cc_a_scale_expected as ex,validate
ap=argparse.ArgumentParser();ap.add_argument('--start',type=int,default=56);ap.add_argument('--end',type=int,default=137);args=ap.parse_args();rows=[]
old=B/'validation/cc_a_scale_audit.json'
if old.exists()and(args.start!=56 or args.end!=137):rows=[x for x in json.loads(old.read_text())['records']if not args.start<=int(x['seed_id'][2:])<=args.end]
for seed in map(json.loads,(B/'curation/previous_seed_index.jsonl').read_text().splitlines()):
 k=int(seed['seed_id'][2:]);rp=B/'validation/strict_cc_a'/seed['seed_id']/'report.json'
 if not(args.start<=k<=args.end)or k==70 or not rp.exists():continue
 report=json.loads(rp.read_text());row={'seed_id':seed['seed_id'],'cases':[],'passed':True};m=validate.load_recipe(B/seed['recipe_module'])
 for c in report['cases']:
  if c['kind']not in('native_upper','l2_upper'):continue
  expand=c['kind']=='l2_upper';folder=B/'validation/strict_cc_a'/seed['seed_id']/'cases'/c['name'];checks={}
  for mut in([False]if expand else[False,True]):
   role='l3_fast'if mut else'raw_fast';run=c['runs'][role]
   if k==127:
    cfg={'sigma':{'path':str(B/'native/cc_a_sigma_oracle.cpp'),'args':[str(int(mut))]},'memory_mb':1024,'max_output_bytes':1024};prog=validate.Programs(validate.Sandbox(),B/'native',folder/'sigma_independent',cfg);prog.prepare('sigma');oracle=prog.run('sigma',(folder/'input.txt').read_text(),45,folder/('sigma_l3'if mut else'sigma_raw'));expected=validate.output(oracle)if oracle['status']=='OK'else'ORACLE_FAILED';checks[role+'_oracle_execution']=oracle
   else:expected=ex.expected(k,expand,mut)
   path=folder/(role+'_structured_expected.txt');path.write_text(expected);matched=run['status']=='OK'and validate.accepted(m,seed['recipe_id'],(folder/'input.txt').read_text(),validate.output(run),expected,'l3'if mut else'raw')
   checks[role]={'match':matched,'expected_path':str(path.relative_to(B)),'expected_sha256':validate.sha(expected.encode()),'actual_path':str(Path(run['stdout_path']).relative_to(B))};row['passed']&=matched
  row['cases'].append({'name':c['name'],'validity':native.validate(k,(folder/'input.txt').read_text(),'l2'if expand else'raw'),'checks':checks})
 row['complete']=len(row['cases'])==2;row['passed']&=row['complete'];rows.append(row);print(seed['seed_id'],row['passed'],[(c['name'],r)for c in row['cases']for r,v in c['checks'].items()if isinstance(v,dict)and v.get('match')is False],flush=True)
out=B/'validation/cc_a_scale_audit.json';out.write_text(json.dumps({'method':'Independent analytical and recurrence expectations for recorded structured maximum-size inputs. Small random cases independently tested separately.','expected_implementation_sha256':validate.file_hash(B/'native/cc_a_scale_expected.py'),'records':rows},ensure_ascii=False,indent=2)+'\n')
