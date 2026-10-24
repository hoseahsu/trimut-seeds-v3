#!/usr/bin/env python3
"""Finite release QA, including selected archived public submissions when runnable."""
from pathlib import Path
import importlib.util,json,subprocess,hashlib,concurrent.futures,os,resource
ROOT=Path(__file__).resolve().parents[2]
MODULES=['codecontests_batch']+[f'cc_a_batch{i}' for i in range(2,8)]
source={}
for p in (ROOT/'sources/codecontests').iterdir():
 q=p/'source_metadata.json'
 if q.is_file():
  d=json.loads(q.read_text());source[(d.get('origin_row_index'),d.get('name'))]=p
jobs=[]
for name in MODULES:
 p=ROOT/'recipes'/(name+'.py');sp=importlib.util.spec_from_file_location(name,p);m=importlib.util.module_from_spec(sp);sp.loader.exec_module(m)
 for pid,cfg in m.RECIPES.items():jobs.append((name,m,pid,cfg))
outdir=ROOT/'assets/codecontests_batch/source_witness_build';outdir.mkdir(exist_ok=True)
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def affinity_and_limits():
 cpus=sorted(os.sched_getaffinity(0));nonzero=[x for x in cpus if x!=0]
 if nonzero:os.sched_setaffinity(0,set(nonzero[:3]))
 resource.setrlimit(resource.RLIMIT_CPU,(30,31))
 resource.setrlimit(resource.RLIMIT_AS,(1024*1024*1024,1024*1024*1024))
 resource.setrlimit(resource.RLIMIT_FSIZE,(32*1024*1024,32*1024*1024))
def sandbox_prefix():
 return ['bwrap','--unshare-all','--die-with-parent','--new-session','--ro-bind','/usr','/usr','--ro-bind','/lib','/lib','--ro-bind','/lib64','/lib64','--proc','/proc','--dev','/dev','--tmpfs','/tmp','--clearenv','--setenv','PATH','/usr/bin:/bin']
def run(cmd,s,timeout=3):
 try:
  v=subprocess.run(cmd,input=s,capture_output=True,text=True,timeout=timeout,preexec_fn=affinity_and_limits)
  return {'status':'ok' if v.returncode==0 else 'runtime_error','returncode':v.returncode,'stdout':v.stdout,'stderr':v.stderr[:500]}
 except subprocess.TimeoutExpired:return {'status':'timeout'}
def check(job):
 name,m,pid,cfg=job;s=cfg['witness'];assert m.validate_version_input(pid,s,'raw') and m.validate_version_input(pid,s,'l3')
 def eq(a,b,c='raw'):
  if hasattr(m,'check_output'):return m.check_output(pid,s,a,b,c)
  return a.split()==b.split()
 values={}
 for k in ['raw_fast','raw_oracle','l3_fast','l3_oracle']:
  exe=ROOT/'assets'/name/'build'/(pid+'_'+k);v=run([str(exe)],s);assert v['status']=='ok',(pid,k,v);values[k]=v['stdout']
 assert eq(values['raw_fast'],values['raw_oracle']) and eq(values['l3_fast'],values['l3_oracle'],'l3')
 assert not eq(values['raw_fast'],values['l3_oracle'],'l3')
 d={'id':pid,'module':name,'weak_raw_input_valid':True,'weak_l3_input_valid':True,'witness_input':s,'witness_outputs':values,'independently_authored_raw_rejected_by_l3':True,'raw_fast_sha256':sha(cfg['raw_fast']),'l3_fast_sha256':sha(cfg['l3_fast']),'original_submission_attempts':[],'original_submission_kill_verified':False,'execution_isolation':'bwrap for archived public submissions; independent authored witness programs run with resource limits; CPU0 excluded'}
 src=source.get((cfg['source_row_index'],cfg['source_name']))
 if src is None:d['original_submission_status']='source archive not found';return d
 for f in sorted(src.glob('source_solution_*.cpp')):
  exe=outdir/(pid+'_'+f.stem);attempt={'source_path':str(f.relative_to(ROOT)),'source_sha256':sha(f)}
  if not exe.exists() or exe.stat().st_mtime<f.stat().st_mtime:
   c=subprocess.run(sandbox_prefix()+['--dir','/work','--ro-bind',str(f.resolve()),'/work/main.cpp','--bind',str(outdir.resolve()),'/out','--chdir','/work','g++','-std=c++17','-O2','/work/main.cpp','-o','/out/'+exe.name],capture_output=True,text=True,timeout=30,preexec_fn=affinity_and_limits)
   if c.returncode:attempt.update(status='compile_error',diagnostic=c.stderr[:500]);d['original_submission_attempts'].append(attempt);continue
  v=run(sandbox_prefix()+['--ro-bind',str(exe.resolve()),'/program','--chdir','/tmp','/program'],s,5);attempt.update(v);attempt['execution_isolation']='bwrap user/mount/network namespaces, restricted read-only runtime mounts, no home mount'
  if v['status']=='ok':
   attempt['matches_raw']=eq(v['stdout'],values['raw_oracle']);attempt['rejected_by_l3']=not eq(v['stdout'],values['l3_oracle'],'l3')
   if attempt['matches_raw'] and attempt['rejected_by_l3']:d['original_submission_kill_verified']=True
  d['original_submission_attempts'].append(attempt)
  if d['original_submission_kill_verified']:break
 d['original_submission_status']='verified' if d['original_submission_kill_verified'] else 'not verified; see attempts'
 return d
results=[]
with concurrent.futures.ThreadPoolExecutor(max_workers=3) as ex:
 for d in ex.map(check,jobs):
  results.append(d);print(d['id'],d['original_submission_status'],flush=True)
  (ROOT/'assets/codecontests_batch/release_witness_qa.json').write_text(json.dumps(results,ensure_ascii=False,indent=2)+'\n')
print('TOTAL',len(results),'ORIGINAL_SUBMISSION_KILLS',sum(d['original_submission_kill_verified'] for d in results),flush=True)
