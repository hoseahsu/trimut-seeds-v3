#!/usr/bin/env python3
"""Development verification; formal release status is produced by shared harness."""
import importlib.util,json,subprocess,time,concurrent.futures,pathlib,random
ROOT=pathlib.Path(__file__).resolve().parents[2]
p=ROOT/'recipes'/'cc_a_batch7.py'
spec=importlib.util.spec_from_file_location('r',p);r=importlib.util.module_from_spec(spec);spec.loader.exec_module(r)
assets=pathlib.Path(__file__).parent
bin_dir=assets/'build';bin_dir.mkdir(exist_ok=True)

def build(item):
 pid,kind,src=item;out=bin_dir/(pid+'_'+kind)
 if out.exists() and out.stat().st_mtime>=pathlib.Path(src).stat().st_mtime:return (pid,kind,str(out))
 v=subprocess.run(['g++','-std=c++17','-O2','-pipe',src,'-o',str(out)],capture_output=True,text=True)
 if v.returncode:raise RuntimeError(src+'\n'+v.stderr)
 return (pid,kind,str(out))
programs={}
with concurrent.futures.ThreadPoolExecutor(max_workers=4) as ex:
 for pid,k,out in ex.map(build,[(pid,k,cfg[k]) for pid,cfg in r.RECIPES.items() for k in ['raw_fast','raw_oracle','l3_fast','l3_oracle']]):programs.setdefault(pid,{})[k]=out

def run(pid,k,s,timeout=2):
 st=time.monotonic()
 try:
  v=subprocess.run([programs[pid][k]],input=s,capture_output=True,text=True,timeout=timeout)
  if v.returncode:raise RuntimeError(f'{pid} {k} exited {v.returncode}: {v.stderr}')
  return {'status':'ok','output':v.stdout,'wall_s':time.monotonic()-st}
 except subprocess.TimeoutExpired:return {'status':'timeout','wall_s':time.monotonic()-st}

def equal(a,b):
 if all(x.lower() in {'yes','no'} for x in a.split()+b.split()):return a.lower().split()==b.lower().split()
 
 try:
  import math
  x=float(a.strip());y=float(b.strip());return math.isfinite(x) and math.isfinite(y) and abs(x-y)<1e-6
 except (ValueError,OverflowError):return a.split()==b.split()
source={}
for start in [1200,1300,1400,1500]:
 for entry in json.load(open(f'/tmp/trimut_public_downloads/codecontests_{start:04}.json'))['rows']:source[entry['row_idx']]=entry
report=[]
for pid,cfg in r.RECIPES.items():
 d={'id':pid,'raw_random_cases':0,'l3_random_cases':0,'source_test_cases':0,'sample_repairs':[],'differences':0}
 for mode in ['small','boundary','weak']:
  for name,s in r.cases(pid,mode,random.Random(20261022)):
   assert r.validate_input(pid,s,'weak' if mode=='weak' else 'raw')
   raw=run(pid,'raw_fast',s);oracle=run(pid,'raw_oracle',s)
   assert raw['status']==oracle['status']=='ok',(pid,name,raw,oracle)
   assert equal(raw['output'],oracle['output']),(pid,name,'raw',s,raw,oracle)
   d['raw_random_cases']+=1
   mod=run(pid,'l3_fast',s);oracle=run(pid,'l3_oracle',s)
   assert mod['status']==oracle['status']=='ok',(pid,name,mod,oracle)
   assert equal(mod['output'],oracle['output']),(pid,name,'l3',s,mod,oracle)
   d['l3_random_cases']+=1
   d['differences']+=not equal(raw['output'],mod['output'])
 row=source[cfg['source_row_index']]['row']
 d['source_name']=row['name']
 for split in ['public_tests','private_tests','generated_tests']:
  tests=row[split]
  for i,(s,expect) in enumerate(zip(tests['input'],tests['output'])):
   if i>=15:break
   if s.rstrip().endswith('SAMPLE'):
    s=s.rstrip()[:-6].rstrip()+'\n';d['sample_repairs'].append(f'{split}:{i}: removed trailing non-input SAMPLE marker')
   try:r.validate_input(pid,s,'raw')
   except Exception as e:
    d.setdefault('invalid_source_tests',[]).append({'split':split,'index':i,'error':str(e)})
    continue
   result=run(pid,'raw_fast',s,5)
   assert result['status']=='ok' and equal(result['output'],expect),(pid,split,i,s,result,expect)
   d['source_test_cases']+=1
 witness=cfg['witness'];raw=run(pid,'raw_fast',witness);mod=run(pid,'l3_fast',witness)
 assert not equal(raw['output'],mod['output']),(pid,'invalid witness',raw,mod)
 d['witness']={'input':witness,'raw_output':raw['output'],'l3_output':mod['output']}
 for name,s in r.cases(pid,'stress',random.Random(20261022)):
  assert r.validate_input(pid,s,'l2')
  d['stress_fast']=run(pid,'raw_fast',s,cfg['budget_seconds']);d['stress_fast'].pop('output',None)
  d['stress_slow']=run(pid,'raw_oracle',s,cfg['budget_seconds']);d['stress_slow'].pop('output',None)
 print(json.dumps(d),flush=True);report.append(d)
 (assets/'development_validation.json').write_text(json.dumps(report,indent=2)+'\n')
