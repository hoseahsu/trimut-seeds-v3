#!/usr/bin/env python3
import argparse,json,sys
from pathlib import Path
BASE=Path(__file__).resolve().parents[1];sys.path[:0]=[str(BASE/'native'),str(BASE/'recipes'),str(BASE/'assets')]
import root55,validate

def main():
 ap=argparse.ArgumentParser();ap.add_argument('--start',type=int,default=1);ap.add_argument('--end',type=int,default=55);args=ap.parse_args();sandbox=validate.Sandbox();assert sandbox.available
 for seed in map(json.loads,(BASE/'curation/previous_seed_index.jsonl').read_text().splitlines()):
  sid=seed['seed_id'];k=int(sid[2:])
  if not args.start<=k<=args.end or k in(1,17,25):continue
  path=BASE/seed['recipe_module'];m=validate.load_recipe(path);cfg={**m.RECIPES[seed['recipe_id']],'memory_mb':2048,'max_output_bytes':128*1024**2}
  for role,mut in [('scale_raw_oracle',0),('scale_l3_oracle',1)]:cfg[role]={'path':str(BASE/'native/root_scale_oracle.py'),'args':[str(k),str(mut)]}
  out=BASE/'validation/root_scale'/sid;rp=out/'report.json';out.mkdir(parents=True,exist_ok=True)
  if rp.exists()and json.loads(rp.read_text()).get('status')=='complete':print(sid,'cached',flush=True);continue
  p=validate.Programs(sandbox,path.parent,out,cfg);report={'seed_id':sid,'status':'running','scope':'Separate Python implementation on original-maximum and strictly expanded inputs; no universal correctness guarantee or algorithm-separation claim.','budget_seconds':5,'oracle_budget_seconds':45,'memory_mb':2048,'programs':{},'cases':[],'failures':[]}
  for r in ['raw_fast','l3_fast','scale_raw_oracle','scale_l3_oracle']:report['programs'][r]=p.prepare(r)
  for kind in ['native','l2']:
   inp=root55.scale_case(k,kind=='l2');folder=out/kind;folder.mkdir(parents=True,exist_ok=True);(folder/'input.txt').write_text(inp);c={'name':kind,'input_path':str((folder/'input.txt').relative_to(BASE)),'input_sha256':validate.sha(inp.encode()),'validity':root55.validate(k,inp,kind),'runs':{},'checks':{}}
   for role in ['raw_fast','scale_raw_oracle']+(['l3_fast','scale_l3_oracle']if kind=='native'else[]):
    c['runs'][role]=p.run(role,inp,45 if role.startswith('scale')else 5,folder/role)
   for fast,oracle,cond in [('raw_fast','scale_raw_oracle','raw')]+([('l3_fast','scale_l3_oracle','l3')]if kind=='native'else[]):
    a,b=c['runs'][fast],c['runs'][oracle];ok=a['status']=='OK'and b['status']=='OK'and validate.accepted(m,seed['recipe_id'],inp,validate.output(a),validate.output(b),cond);c['checks'][fast]=ok
    if not ok:report['failures'].append({'case':kind,'fast':fast,'fast_status':a['status'],'oracle_status':b['status'],'reason':'output_mismatch'if a['status']==b['status']=='OK'else'execution_failure'})
   report['cases'].append(c);validate.write_json(rp,report)
  report['status']='complete';report['passed']=not report['failures'];validate.write_json(rp,report);print(sid,report['passed'],report['failures'],flush=True)
if __name__=='__main__':main()
