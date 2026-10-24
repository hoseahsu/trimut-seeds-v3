#!/usr/bin/env python3
"""Append explicitly authored exact-native-bound pressure cases, retaining all prior source cases."""
from pathlib import Path
import argparse,json,resource,sys
R=Path(__file__).resolve().parents[1];sys.path.insert(0,str(R/'tools'));sys.path.insert(0,str(R/'library_work'))
from validate import Sandbox,Programs,write_json,file_hash
from build_native_tests import run,load,dimensions,bound_hits,compile_cpp
from pressure_cases import pressure

def main():
 ap=argparse.ArgumentParser();ap.add_argument('--ids',nargs='*');a=ap.parse_args();box=Sandbox();assert box.available,box.probe;resource.setrlimit(resource.RLIMIT_STACK,(256*1024**2,256*1024**2))
 status=[]
 for x in json.loads((R/'library_work/native_strict_plan.json').read_text()):
  id=x['id'];seed=x['seed_id'];mp=R/'tasks'/seed/'raw_test_manifest.json'
  if a.ids and id not in a.ids and seed not in a.ids:continue
  if not mp.exists():continue
  m=json.loads(mp.read_text())
  if m['native_upper_bound_reached']:continue
  report={'id':id,'seed_id':seed}
  try:
   txt=pressure(id,x['native_params']);assert txt,('no_pressure_generator',id);inp=txt.encode();dim=dimensions(id,inp);hits=bound_hits(x,dim);assert hits,(id,dim)
   out=R/'validation/library_native_domain'/id;package=R/'library_work/prepared_packages'/id
   verifier=compile_cpp(box,package/'verifier.cpp',out/'build/verifier',out/'compile/verifier',[R/'sources/library-checker-problems-master/common'],package)
   name='authored_exact_native_upper_bound';v=run(box,verifier,inp,out/'verify'/name,20);assert v['status']=='OK',(id,'invalid_pressure')
   raw=run(box,R/'validation/library_native_examples'/id/'build/program',inp,out/'raw_reference'/name,x['native_time_seconds']);assert raw['status']=='OK',(id,'raw',raw['status'])
   mod=load(R/x['recipe_module']);cfg=mod.RECIPES[id].copy();cfg['memory_mb']=1024;cfg['max_output_bytes']=256*1024**2;cfg.update(json.loads((R/'library_work/program_overrides.json').read_text()).get(id,{}))
   progs=Programs(box,(R/x['recipe_module']).parent,out/'l3_supplement_programs',cfg);progs.prepare('l3_fast');fast=progs.run('l3_fast',txt,x['native_time_seconds'],out/'l3_fast'/name)
   td=R/'tasks'/seed/'tests/raw';ip=td/(name+'.in');op=td/(name+'.out');ip.write_bytes(inp);op.write_bytes(Path(raw['stdout_path']).read_bytes())
   rec={'name':name,'kind':'authored_exact_native_upper_bound','generator':str(Path(__file__).relative_to(R)),'pressure_generator':str((R/'library_work/pressure_cases.py').relative_to(R)),'pressure_generator_sha256':file_hash(R/'library_work/pressure_cases.py'),'seed':20261022,'not_an_original_official_test':True,'dimensions':dim,'native_upper_bound_hits':hits,'source_verifier':'passed','input_path':str(ip.relative_to(R)),'input_sha256':file_hash(ip),'expected_path':str(op.relative_to(R)),'expected_sha256':file_hash(op),'reference_run':str((out/'raw_reference'/(name+'.run.json')).relative_to(R)),'reference_cpu_seconds':raw['cpu_seconds'],'l3_native_run':{'status':fast['status'],'cpu_seconds':fast['cpu_seconds'],'report':str((out/'l3_fast'/(name+'.run.json')).relative_to(R))}}
   m['records']=[r for r in m['records']if r['name']!=name]+[rec];m['test_count']=len(m['records']);m['native_upper_bound_reached']=True;write_json(mp,m);report.update({'status':'native_upper_bound_added','l3_status':fast['status']})
  except Exception as e:report.update({'status':'blocked','error':repr(e)})
  status.append(report);print(json.dumps(report),flush=True);write_json(R/'library_work/native_supplement_status.json',status)
if __name__=='__main__':main()
