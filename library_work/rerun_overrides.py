#!/usr/bin/env python3
from pathlib import Path
import argparse,json,resource,sys
R=Path(__file__).resolve().parents[1];sys.path.insert(0,str(R/'tools'));sys.path.insert(0,str(R/'library_work'))
from validate import Sandbox,Programs,accepted,file_hash,write_json
from build_native_tests import load

def main():
 ap=argparse.ArgumentParser();ap.add_argument('--ids',nargs='*');args=ap.parse_args();box=Sandbox();assert box.available,box.probe;resource.setrlimit(resource.RLIMIT_STACK,(256*1024**2,256*1024**2));over=json.loads((R/'library_work/program_overrides.json').read_text());rows=[]
 for x in json.loads((R/'library_work/native_strict_plan.json').read_text()):
  id=x['id'];seed=x['seed_id']
  if id not in over or (args.ids and id not in args.ids and seed not in args.ids):continue
  mod=load(R/x['recipe_module']);cfg=mod.RECIPES[id].copy();cfg.update(over[id]);cfg['memory_mb']=1024;cfg['max_output_bytes']=256*1024**2
  out=R/'validation/library_strict_program_repairs'/id;prog=Programs(box,(R/x['recipe_module']).parent,out,cfg)
  for role in('raw_fast','l3_fast'):prog.prepare(role)
  mpath=R/'tasks'/seed/'raw_test_manifest.json';m=json.loads(mpath.read_text());checks=[]
  for c in m['records']:
   inp=(R/c['input_path']).read_text();name=c['name'];run=prog.run('l3_fast',inp,x['native_time_seconds'],out/'native_l3'/name)
   old_report=json.loads((R/c['l3_native_run']['report']).read_text());old=Path(old_report['stdout_path']).read_text();new=Path(run['stdout_path']).read_text();okay=run['status']=='OK'and accepted(mod,id,inp,new,old,'l3')
   independent=None;oracle=R/'validation/library_native_domain'/id/'l3_oracle'/(name+'.stdout')
   if c.get('small_independent_oracles',{}).get('l3_agrees'):
    assert oracle.exists();independent=accepted(mod,id,inp,new,oracle.read_text(),'l3');okay=okay and independent
   assert okay,(id,name,'native_repair_failed')
   c['pre_repair_l3_native_run']=c['l3_native_run'];c['l3_native_run']={'status':run['status'],'cpu_seconds':run['cpu_seconds'],'report':str((out/'native_l3'/(name+'.run.json')).relative_to(R))};c['strict_repair_recheck']={'same_semantic_answer':okay,'independent_small_oracle_agrees':independent};checks.append({'name':name,'condition':'native_l3','passed':okay})
  m['strict_program_override']=over[id];write_json(mpath,m)
  mpath=R/'tasks'/seed/'l2_test_manifest.json';m=json.loads(mpath.read_text())
  for c in m['records']:
   inp=(R/c['input_path']).read_text();expected=(R/c['expected_path']).read_text();name=c['name'];run=prog.run('raw_fast',inp,x['native_time_seconds'],out/'expanded_raw'/name);good=run['status']=='OK'and accepted(mod,id,inp,Path(run['stdout_path']).read_text(),expected,'raw');assert good,(id,name,'l2_repair_failed')
   c['pre_repair_fast_run']=c['fast_run'];c['fast_run']=str((out/'expanded_raw'/(name+'.run.json')).relative_to(R));c['fast_status']=run['status'];c['fast_cpu_seconds']=run['cpu_seconds'];c['fast_answer_agrees_with_source_reference']=good;checks.append({'name':name,'condition':'l2','passed':good})
  m['strict_program_override']=over[id];m['fast_reference_validated']=True;write_json(mpath,m);rows.append({'id':id,'seed_id':seed,'checks':checks,'all_passed':all(c['passed']for c in checks),'reason':over[id]['repair_reason']});print(json.dumps(rows[-1]),flush=True)
 write_json(R/'library_work/program_repairs_status.json',rows)
if __name__=='__main__':main()
